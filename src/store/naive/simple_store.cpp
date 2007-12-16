/*
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf (david.graf@28msec.com), Markos Zaharioudakis
 *
 */

#include <iostream>

#include "util/rchandle.h"

#include "errors/Error.h"
#include "store/naive/simple_store.h"
#include "store/naive/simple_temp_seq.h"
#include "store/naive/simple_collection.h"
#include "store/naive/qname_pool.h"
#include "store/naive/simple_loader.h"
#include "store/naive/store_defs.h"
#include "store/naive/node_items.h"
#include "store/naive/basic_item_factory.h"

namespace xqp
{

typedef rchandle<TempSeq> TempSeq_t;

const float SimpleStore::DEFAULT_HASH_LOAD_FACTOR = 0.6;

const xqp_ulong SimpleStore::DEFAULT_COLLECTION_MAP_SIZE = 32;

const char* SimpleStore::XS_URI = "http://www.w3.org/2001/XMLSchema";

unsigned long SimpleStore::theUriCounter = 0;

unsigned long SimpleStore::theTreeCounter = 1;


/*******************************************************************************

********************************************************************************/
SimpleStore::SimpleStore()
  :
  theIsInitialized(false),
  theNamespacePool(new StringPool(StringPool::DEFAULT_POOL_SIZE)),
  theQNamePool(new QNamePool(QNamePool::MAX_CACHE_SIZE)),
  theItemFactory(new BasicItemFactory(theNamespacePool, theQNamePool)),
  theCollections(DEFAULT_COLLECTION_MAP_SIZE, DEFAULT_HASH_LOAD_FACTOR),
  theXmlLoader(NULL)
{
}


/*******************************************************************************

********************************************************************************/
void SimpleStore::init()
{
  if (!theIsInitialized)
  {
    theIsInitialized = true;

    theNamespacePool->insert("", theEmptyNs);
    theNamespacePool->insert(XS_URI, theXmlSchemaNs);
    theAnyType = theItemFactory->createQName(XS_URI, "xs", "anyType");
    theUntypedAtomicType = theItemFactory->createQName(XS_URI, "xs", "untypedAtomic");
    theQNameType = theItemFactory->createQName(XS_URI, "xs", "QName");
  }
}


/*******************************************************************************

********************************************************************************/
SimpleStore::~SimpleStore()
{
  theCollections.clear();

  if (theItemFactory != NULL)
  {
    delete theItemFactory;
    theItemFactory = NULL;
  }

  if (theQNamePool != NULL)
  {
    theAnyType = NULL;
    theUntypedAtomicType = NULL;
    theQNameType = NULL;

    delete theQNamePool;
    theQNamePool = NULL;
  }

  if (theNamespacePool != NULL)
  {
    theEmptyNs = NULL;
    theXmlSchemaNs = NULL;

    delete theNamespacePool;
    theNamespacePool = NULL;
  }
}


/*******************************************************************************

********************************************************************************/
XmlLoader& SimpleStore::getXmlLoader()
{
  if (theXmlLoader == NULL)
    theXmlLoader = new XmlLoader();

  return *theXmlLoader;
}


/*******************************************************************************
  Possibility to change the Garbage Collection strategy of the store.

  @param garbageCollectionStrategy
********************************************************************************/
void SimpleStore::setGarbageCollectionStrategy(const xqp_string& strategy)
{

}


/*******************************************************************************
  Create an internal URI and return an rchandle to it. 
********************************************************************************/
Item_t SimpleStore::createUri()
{
  std::ostringstream uristream;
  uristream << "zorba://internalURI-" << SimpleStore::theUriCounter++;

  return theItemFactory->createAnyURI(uristream.str().c_str()).get_ptr();
}


/*******************************************************************************
  Create a collection with a given URI and return an rchandle to the new
  collection object. If a collection with the given URI exists already, return
  NULL and register an error.

  Note: The collection URI is given as an xqp_string.
********************************************************************************/
Collection_t SimpleStore::createCollection(const xqp_string& uri)
{
  if (theCollections.find(uri))
  {
    ZORBA_ERROR_ALERT_OSS(error_messages::API0005_COLLECTION_ALREADY_EXISTS,
                          error_messages::USER_ERROR,
                          NULL,
                          true,
                          uri, "");
    return NULL;
  }

  Item_t uriItem = theItemFactory->createAnyURI(uri);

  Collection_t collection(new SimpleCollection(uriItem));

  theCollections.insert(uri, collection);

  return collection;
}


/*******************************************************************************
  Create a collection with a given URI and return an rchandle to the new
  collection object. If a collection with the given URI exists already, return
  NULL and register an error.

  Note: The collection URI is given as an Item.
********************************************************************************/
Collection_t SimpleStore::createCollection(Item_t uri)
{
  if (theCollections.find(uri->getStringValue()))
  {
    ZORBA_ERROR_ALERT_OSS(error_messages::API0005_COLLECTION_ALREADY_EXISTS,
                          error_messages::USER_ERROR,
                          NULL,
                          true,
                          uri->getStringValue(), "");
    return NULL;
  }

  Collection_t collection(new SimpleCollection(uri));

  theCollections.insert(uri->getStringValue(), collection);

  return collection;
}


/*******************************************************************************
  Create a collection in the store. The collection will be assigned an internal
  URI by the store.
********************************************************************************/
Collection_t SimpleStore::createCollection()
{
  Item_t uri = createUri();

  return createCollection(uri);
}


/*******************************************************************************
  Return an rchandle to the Collection object corresponding to the given URI,
  or NULL if there is no collection with that URI.
********************************************************************************/
Collection_t SimpleStore::getCollection(Item_t uri)
{
  Collection_t collection;  // initialized to NULL
  bool found = theCollections.get(uri->getStringValue(), collection);
  return collection;
}


/*******************************************************************************
  Deletes the collection with the given URI. If there is no collection with
  that URI, this method is a NOOP.
********************************************************************************/
void SimpleStore::deleteCollection(Item_t uri)
{
  theCollections.remove(uri->getStringValue());
}


/*******************************************************************************
  Compare two nodes, based on their node id. Return -1 if node1 < node2, 0, if
  node1 == node2, or 1 if node1 > node2.
********************************************************************************/
int32_t SimpleStore::compare(Item_t node1, Item_t node2) const
{
  if (!node1->isNode() || !node2->isNode())
  {
    ZORBA_ERROR_ALERT(error_messages::XQP0014_SYSTEM_SHOULD_NEVER_BE_REACHED,
                      error_messages::SYSTEM_ERROR,
                      NULL,
                      false);
  }

  if (node1 == node2)
    return 0;
  else if (BASE_NODE(node1)->getId() < BASE_NODE(node2)->getId())
    return -1;
  else
    return 1;
}


/*******************************************************************************
  Sorts the items of the passed iterator

  @param iterator to sort
  @param ascendent true for ascendent and false for descendant
  @param duplicate duplicate elemination should be applied
  @return iterator which produces the sorted items
********************************************************************************/
Iterator_t SimpleStore::sortNodes(
    Iterator_t input,
    bool ascendent,
    bool duplicateElemination)
{
  return  new StoreNodeSortIterator(input, ascendent, duplicateElemination);
}


/*******************************************************************************
  Create an iterator that eliminates the duplicate nodes in the set of items
  which is produced by the passed iterator
********************************************************************************/
Iterator_t SimpleStore::distinctNodes(Iterator_t input)
{
  return new StoreNodeDistinctIterator(input);
}


/*******************************************************************************
  Computes the URI for the given node.
********************************************************************************/
Item_t SimpleStore::getReference(Item_t node)
{
  return rchandle<Item>(NULL);
}


/*******************************************************************************
  Returns a fixed reference of an item, dependent on a requester (defines branch)
  and a timetravel (defines version)

  @param Item 
  @param requester
  @param timetravel
  @throws NotSupportedException Throws an exception if the store does not
          support branching or versioning
********************************************************************************/
Item_t SimpleStore::getFixedReference(
    Item_t,
    Requester requester,
    Timetravel timetravel)
{
  return rchandle<Item> ( NULL );
}


/*******************************************************************************
  Returns Item which is identified by a reference

  @param uri Has to be an xs:URI item
  @returns referenced item if it exists, otherwise NULL
********************************************************************************/
Item_t SimpleStore::getNodeByReference(Item_t)
{
  return rchandle<Item> ( NULL );
}


/*******************************************************************************
  Returns Item wich is identified by a referenced, dependent on a requester
  (defines branch) and a timetravel (defines version)

  @param Item_t Has to be an xs:URI item (no correctness check is applied!!!)
  @param requester
  @param timetravel
  @returns referenced item if it exists, otherwise NULL
  @throws NotSupportedException Throws an exception if the store does not
          support branching or versioning
  @throws IllegalReferenceException Throws an exception if the reference is fixed.
********************************************************************************/
Item_t SimpleStore::getNodeByReference(
    Item_t,
    Requester requester,
    Timetravel timetravel)
{
  return rchandle<Item> ( NULL );
}


/*******************************************************************************
  Applies a pending update list on this store

  @param pendingUpdateList
********************************************************************************/
void SimpleStore::apply(PUL_t pendingUpdateList)
{

}


/*******************************************************************************
  Applies the pending update list on the specified branch. Potentially, 
  creates a new branch if no branch for that requester exists yet.

  @param pendingUpdateList
  @param requester
  @throws NotSupportedException Throws an exception if the store does not
          support branching
********************************************************************************/
void SimpleStore::apply(PUL_t pendingUpdateList, Requester requester)
{

}


/*******************************************************************************
  Creates a new TempSeq. The instance can be used, e.g. for variable bindings

  @param iterator The source for the XMDInstance
  @param lazy			Hint for the store. If possible a XMDInstance should be
                  evaluated lazily. For XQueryP it might be necassary to set
                  this to false.
********************************************************************************/
TempSeq_t SimpleStore::createTempSeq(Iterator_t iterator, bool lazy)
{
  TempSeq_t tempSeq = new SimpleTempSeq(iterator, lazy);
  return tempSeq;
}


/*******************************************************************************
  Creates an empty TempSeq.
********************************************************************************/
TempSeq_t SimpleStore::createTempSeq()
{
  TempSeq_t tempSeq = new SimpleTempSeq();
  return tempSeq;
}


} /* namespace xqp */
