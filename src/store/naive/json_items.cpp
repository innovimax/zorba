/*
 * Copyright 2006-2011 The FLWOR Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "json_items.h"
#include "simple_item_factory.h"
#include "simple_store.h"
#include "item_iterator.h"

#include "store/api/copymode.h"

#include "diagnostics/assert.h"
#include "diagnostics/util_macros.h"

namespace zorba
{

namespace simplestore
{

namespace json
{

/******************************************************************************

*******************************************************************************/
store::Item* JSONNull::getType() const
{
  return GET_STORE().JDM_NULL_QNAME;
}


/******************************************************************************

*******************************************************************************/
bool JSONNull::equals(
    const store::Item* other,
    long /* timezone */,
    const XQPCollator* /* collation */) const
{
  return other->getTypeCode() == store::JDM_NULL;
}


/******************************************************************************

*******************************************************************************/
uint32_t JSONNull::hash(long /* tmz */, const XQPCollator* /* collation */) const
{
  const void* tmp = this; // there is only one instance in the store
  return hashfun::h32(&tmp, sizeof(void*), FNV_32_INIT);
}


/******************************************************************************

*******************************************************************************/
void JSONNull::getTypedValue(store::Item_t& val, store::Iterator_t& iter) const
{
  iter = NULL;
  val = this;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Object                                                                     //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/******************************************************************************

*******************************************************************************/
store::Item* JSONObject::getType() const
{
  return GET_STORE().JDM_OBJECT_QNAME;
}


/******************************************************************************

*******************************************************************************/
void setJSONRoot(const store::Item_t& aJSONItem, const JSONItem* aRoot)
{
  if (aJSONItem->isJSONObject())
  {
    assert(dynamic_cast<SimpleJSONObject*>(aJSONItem.getp()));
    SimpleJSONObject* lObject =
      static_cast<SimpleJSONObject*>(aJSONItem.getp());

    // Only attach or detach allowed - no direct reattach.
    assert(aRoot == NULL || lObject->theRoot == NULL);
    lObject->setRoot(aRoot);
  }
  else if (aJSONItem->isJSONArray())
  {
    assert(dynamic_cast<SimpleJSONArray*>(aJSONItem.getp()));
    SimpleJSONArray* lArray =
      static_cast<SimpleJSONArray*>(aJSONItem.getp());

    // Only attach or detach allowed - no direct reattach.
    assert(aRoot == NULL || lArray->theRoot == NULL);
    lArray->setRoot(aRoot);
  } 
  else
  {
    assert(false);
  }
}


/******************************************************************************

*******************************************************************************/
SimpleJSONObject::~SimpleJSONObject()
{
#ifndef NDEBUG
  assertInvariant();
#endif
  for (Pairs::iterator lIter = thePairs.begin();
       lIter != thePairs.end();
       ++lIter)
  {
    store::Item* lName = lIter->first;
    store::Item* lChild = lIter->second;
    if (lChild != NULL && lChild->isJSONItem())
    {
      if (getCollection() != NULL && lChild->isJSONItem())
      {
        setJSONRoot(lChild, NULL);
      }
    }
    lName->removeReference();
    lChild->removeReference();
  }
  theKeys.clear();
  thePairs.clear();
  theFrees.clear();
#ifndef NDEBUG
  assertInvariant();
#endif
}


/******************************************************************************

*******************************************************************************/
store::Item* SimpleJSONObject::copy(
    store::Item* parent,
    const store::CopyMode& copymode) const
{
#ifndef NDEBUG
  assertInvariant();
#endif
  SimpleJSONObject* lNewObject = const_cast<SimpleJSONObject*>(this);
 
 if (copymode.theDoCopy)
  {
    lNewObject = new SimpleJSONObject();

    for (Keys::iterator lIter = theKeys.begin();
         lIter != theKeys.end();
         ++lIter)
    {
      zstring lName = lIter.getKey();
      csize lPosition = lIter.getValue();
      store::Item_t lKey = thePairs[lPosition].first;
      store::Item_t lValue = thePairs[lPosition].second;

      if (lValue->isJSONObject() ||
           lValue->isJSONArray() ||
           lValue->isNode())
      {
        store::Item_t lCopiedValue = lValue->copy(NULL, copymode);
        lNewObject->add(lKey, lCopiedValue, false);
      }
      else
      {
        lNewObject->add(lKey, lValue, false);
      }
    }
  }

  if (parent)
  {
    assert(parent->isJSONArray());
    assert(dynamic_cast<JSONArray*>(parent));
    JSONArray* a = static_cast<JSONArray*>(parent);

    a->push_back(lNewObject);
  }
  
  return lNewObject;
}


/*******************************************************************************

********************************************************************************/
void SimpleJSONObject::setCollection(SimpleCollection* collection, xs_integer /*pos*/)
{
#ifndef NDEBUG
  assertInvariant();
#endif
  // Ensures one either detaches or attaches.
  ZORBA_ASSERT(collection == NULL || theCollection == NULL);

  theCollection = collection;
  
  if (theCollection != NULL)
  {
    // Attach
    setRoot(this);
  }
  else 
  {
    // Detach
    setRoot(NULL);
  }
  
#ifndef NDEBUG
  assertInvariant();
#endif
}


/******************************************************************************

*******************************************************************************/
bool SimpleJSONObject::add(
    const store::Item_t& aName,
    const store::Item_t& aValue,
    bool accumulate)
{
#ifndef NDEBUG
  assertInvariant();
#endif
  zstring lName = aName->getStringValue();

  if (!theKeys.exists(lName))
  {
    store::Item* lValue = aValue.getp();

    if (getCollection() != NULL && aValue->isJSONItem())
    {
      setJSONRoot(aValue, theRoot);
    }
    
    csize lPosition;
//    if (theFrees.empty())
//    {
      lPosition = thePairs.size();
//    } else {
//      lPosition = theFrees.back();
//      theFrees.pop_back();
//    }
    theKeys.insert(lName, lPosition);
    aName->addReference();
    lValue->addReference();
    if (lPosition == thePairs.size())
    {
      thePairs.push_back(std::make_pair(aName.getp(), lValue));
    } else { 
      thePairs[lPosition] = std::make_pair(aName.getp(), lValue);
    }

#ifndef NDEBUG
    assertInvariant();
#endif
    return true;
  }
  else if (accumulate)
  {
    csize lPosition;
    theKeys.get(lName, lPosition);
    assert(thePairs[lPosition].first->getStringValue() == lName);
    store::Item* lValue = thePairs[lPosition].second;

    if (lValue->isJSONArray())
    {
      static_cast<SimpleJSONArray*>(lValue)->push_back(aValue);
    }
    else
    {
      SimpleJSONArray_t array = new SimpleJSONArray();
      array->push_back(lValue);
      array->push_back(aValue);

      if (getCollection() != NULL)
      {
        setJSONRoot(array, theRoot);
      }

      lValue->removeReference();
      array->addReference();
      thePairs[lPosition].second = array;
    }
#ifndef NDEBUG
    assertInvariant();
#endif
    return true;
  }

#ifndef NDEBUG
  assertInvariant();
#endif
  return false;
}


/******************************************************************************

*******************************************************************************/
store::Item_t SimpleJSONObject::remove(const store::Item_t& aName)
{
#ifndef NDEBUG
  assertInvariant();
#endif
  zstring lName = aName->getStringValue();

  if (theKeys.exists(lName))
  {
#ifndef NDEBUG
    assertInvariant();
#endif
    return 0;
  }
  
  csize lPosition;
  theKeys.get(lName, lPosition);
  assert(thePairs[lPosition].first->getStringValue() == lName);
  store::Item_t lRes = thePairs[lPosition].second;

  if (getCollection() != NULL && lRes->isJSONItem())
  {
    setJSONRoot(lRes, NULL);
  }

  theKeys.erase(lName);
  thePairs[lPosition].first->removeReference();
  thePairs[lPosition].first = NULL;
  lRes->removeReference();
  thePairs[lPosition].second = NULL;
  theFrees.push_back(lPosition);

#ifndef NDEBUG
  assertInvariant();
#endif
  return lRes;
}


/******************************************************************************

*******************************************************************************/
store::Item_t SimpleJSONObject::setValue(
    const store::Item_t& aName,
    const store::Item_t& aValue)
{
#ifndef NDEBUG
  assertInvariant();
#endif
  zstring lName = aName->getStringValue();

  if (!theKeys.exists(lName))
  {
#ifndef NDEBUG
    assertInvariant();
#endif
    return NULL;
  }

  csize lPosition;
  theKeys.get(lName, lPosition);
  assert(thePairs[lPosition].first->getStringValue() == lName);
  store::Item_t lRes = thePairs[lPosition].second;

  if (getCollection() != NULL && lRes->isJSONItem())
  {
    setJSONRoot(lRes, NULL);
  }

  if (getCollection() != NULL && aValue->isJSONItem())
  {
    setJSONRoot(aValue, theRoot);
  }

  lRes->removeReference();
  aValue->addReference();
  thePairs[lPosition].second = aValue.getp();

#ifndef NDEBUG
  assertInvariant();
#endif
  return lRes;
}

/******************************************************************************

*******************************************************************************/
bool SimpleJSONObject::rename(
    const store::Item_t& aName,
    const store::Item_t& aNewName)
{
#ifndef NDEBUG
  assertInvariant();
#endif
  zstring lName = aName->getStringValue();
  zstring lNewName = aNewName->getStringValue();

  if (theKeys.exists(lNewName))
  {
#ifndef NDEBUG
    assertInvariant();
#endif
    return false;
  }
  
  if (!theKeys.exists(lName)) 
  {
#ifndef NDEBUG
    assertInvariant();
#endif
    return false;
  }

  csize lPosition;
  theKeys.get(lName, lPosition);
  assert(thePairs[lPosition].first->getStringValue() == lName);
  
  thePairs[lPosition].first->removeReference();
  aNewName->addReference();
  thePairs[lPosition].first = aNewName.getp();
  theKeys.erase(lName);
  theKeys.insert(lNewName, lPosition);

#ifndef NDEBUG
  assertInvariant();
#endif
  return true;
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONObject::setRoot(const JSONItem* aRoot)
{
  theRoot = aRoot;

  for (Pairs::iterator lIter = thePairs.begin();
       lIter != thePairs.end();
       ++lIter)
  {
    store::Item* lValue = lIter->second;
    if (lValue->isJSONObject())
    {
      assert(dynamic_cast<SimpleJSONObject*>(lValue));
      SimpleJSONObject* lObject = static_cast<SimpleJSONObject*>(lValue);

      lObject->setRoot(aRoot);
    }
    else if (lValue->isJSONArray())
    {
      assert(dynamic_cast<SimpleJSONArray*>(lValue));
      SimpleJSONArray* lArray = static_cast<SimpleJSONArray*>(lValue);
      
      lArray->setRoot(aRoot);
    }
  }
}


/******************************************************************************

*******************************************************************************/
zstring SimpleJSONObject::getStringValue() const
{
#ifndef NDEBUG
  assertInvariant();
#endif
  throw ZORBA_EXCEPTION(jerr::JNTY0003, ERROR_PARAMS("object"));
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONObject::getStringValue2(zstring& val) const
{
#ifndef NDEBUG
  assertInvariant();
#endif
  val = getStringValue();
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONObject::appendStringValue(zstring& buf) const
{
#ifndef NDEBUG
  assertInvariant();
#endif
  buf = getStringValue();
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONObject::getTypedValue(store::Item_t& val, store::Iterator_t& iter) const
{
#ifndef NDEBUG
  assertInvariant();
#endif
  throw ZORBA_EXCEPTION(jerr::JNTY0004, ERROR_PARAMS("object"));
}


/******************************************************************************

*******************************************************************************/
store::Item_t SimpleJSONObject::getObjectValue(const zstring& aKey) const
{
#ifndef NDEBUG
  assertInvariant();
#endif
  store::Item_t lName;
  zstring aNonConstName = aKey;
  GET_FACTORY().createString(lName, aNonConstName);

  if (!const_cast<Keys&>(theKeys).exists(aKey))
  {
    return NULL;
  }

  csize lPosition;
  theKeys.get(aKey, lPosition);
  assert(thePairs[lPosition].first->getStringValue() == aKey);
  return thePairs[lPosition].second;
}


/******************************************************************************

*******************************************************************************/
store::Iterator_t SimpleJSONObject::getObjectKeys() const
{
#ifndef NDEBUG
  assertInvariant();
#endif
  return new KeyIterator(const_cast<SimpleJSONObject*>(this));
}


/******************************************************************************

*******************************************************************************/
const store::Collection* SimpleJSONObject::getCollection() const
{
  if (theRoot == this)
  {
    return theCollection;
  }
  else if (theRoot != NULL)
  {
    return theRoot->getCollection();
  }
  else
  {
    return NULL;
  }
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONObject::assertInvariant() const
{
  // Note: only root objects may point to a collection, so if theCollection ==
  // NULL, it doesn't mean that the object does not belong to a collection.
  assert(theCollection == NULL || theRoot == this);

  if (theRoot != NULL)
  {
    const store::Collection* lCollection = getCollection();
    assert(lCollection != NULL);

    const SimpleJSONObject* lObject =
        dynamic_cast<const SimpleJSONObject*>(theRoot);
    const SimpleJSONArray* lArray =
        dynamic_cast<const SimpleJSONArray*>(theRoot);

    assert(lObject != NULL || lArray != NULL);

    if (lObject != NULL) 
    {
      assert(lObject->isThisRootOfAllDescendants(theRoot));
      assert(lObject->isThisJSONItemInDescendance(this));
    }
    else
    {
      assert(lArray->isThisRootOfAllDescendants(theRoot));
      assert(lArray->isThisJSONItemInDescendance(this));
    }
  }

  assert(theKeys.size() + theFrees.size() == thePairs.size());

  for(Keys::iterator lIter = theKeys.begin();
      lIter != theKeys.end();
      ++lIter)
  {
    csize lPosition = lIter.getValue();
    assert(lPosition < thePairs.size());
    assert(thePairs[lPosition].first != NULL);
    assert(thePairs[lPosition].first->isAtomic());
    assert(thePairs[lPosition].second != NULL);
  }

  for(FreeList::const_iterator lIter = theFrees.begin();
      lIter != theFrees.end();
      ++lIter)
  {
    csize lPosition = *lIter;
    assert(lPosition < thePairs.size());
    assert(thePairs[lPosition].first == NULL);
    assert(thePairs[lPosition].second == NULL);
  }
}


/******************************************************************************

*******************************************************************************/
bool SimpleJSONObject::isThisRootOfAllDescendants(const store::Item* aRoot) const
{
  if (theRoot != aRoot)
  {
    return false;
  }

  for (Pairs::const_iterator lIter = thePairs.begin();
       lIter != thePairs.end();
       ++lIter)
  {
    store::Item* lValue = lIter->second;
    const SimpleJSONObject* lObject =
      dynamic_cast<const SimpleJSONObject*>(lValue);
    const SimpleJSONArray* lArray =
      dynamic_cast<const SimpleJSONArray*>(lValue);
 
   if (lObject != NULL && (!lObject->isThisRootOfAllDescendants(aRoot)))
    {
      return false;
    }
    else if (lArray != NULL && (!lArray->isThisRootOfAllDescendants(aRoot)))
    {
      return false;
    }
  }
  return true;
}


/******************************************************************************

*******************************************************************************/
bool SimpleJSONObject::isThisJSONItemInDescendance(const store::Item* anItem) const
{
  if (this == anItem)
  {
    return true;
  }

  for (Pairs::const_iterator lIter = thePairs.begin();
       lIter != thePairs.end();
       ++lIter)
  {
    store::Item* lValue = lIter->second;
    const SimpleJSONObject* lObject =
      dynamic_cast<const SimpleJSONObject*>(lValue);
    const SimpleJSONArray* lArray =
      dynamic_cast<const SimpleJSONArray*>(lValue);
 
    if (lObject != NULL && lObject->isThisJSONItemInDescendance(anItem))
    {
      return true;
    }
    else if (lArray != NULL && lArray->isThisJSONItemInDescendance(anItem))
    {
      return true;
    }
  }
  return false;
}


/******************************************************************************

*******************************************************************************/
SimpleJSONObject::KeyIterator::~KeyIterator() 
{
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONObject::KeyIterator::open()
{
  theIter = theObject->thePairs.begin();
}


/******************************************************************************

*******************************************************************************/
bool SimpleJSONObject::KeyIterator::next(store::Item_t& res)
{
  while (theIter != theObject->thePairs.end() && theIter->first == NULL)
  {
    ++theIter;
  }
  if (theIter != theObject->thePairs.end())
  {
    res = theIter->first;
    return true;
  } else {
    return false;
  }
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONObject::KeyIterator::reset()
{
  open();
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONObject::KeyIterator::close()
{
  theIter = theObject->thePairs.end();
}



/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Array                                                                      //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/******************************************************************************

*******************************************************************************/
store::Item* JSONArray::getType() const
{
  return GET_STORE().JDM_ARRAY_QNAME;
}


/******************************************************************************

*******************************************************************************/
SimpleJSONArray::~SimpleJSONArray()
{
#ifndef NDEBUG
  assertInvariant();
#endif
  for (Members::const_iterator lIter = theContent.begin();
       lIter != theContent.end();
       ++lIter)
  {
    if (getCollection() != NULL && (*lIter)->isJSONItem())
    {
      setJSONRoot(*lIter, NULL);
    }
    (*lIter)->removeReference();
  }
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::push_back(const store::Item_t& aValue)
{
#ifndef NDEBUG
  assertInvariant();
#endif

  if (getCollection() != NULL && aValue->isJSONItem())
  {
    setJSONRoot(aValue, theRoot);
  }

  aValue->addReference();
  theContent.push_back(aValue.getp());

#ifndef NDEBUG
  assertInvariant();
#endif
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::push_back(const std::vector<store::Item_t>& members)
{
#ifndef NDEBUG
  assertInvariant();
#endif
  theContent.reserve(theContent.size() + members.size());
  add(theContent.size(), members);
#ifndef NDEBUG
  assertInvariant();
#endif
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::push_front(const std::vector<store::Item_t>& members)
{
#ifndef NDEBUG
  assertInvariant();
#endif
  theContent.reserve(theContent.size() + members.size());
  add(0, members);
#ifndef NDEBUG
  assertInvariant();
#endif
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::insert_before(
    const xs_integer& pos,
    const store::Item_t& member)
{
#ifndef NDEBUG
  assertInvariant();
#endif

  if (getCollection() != NULL && member->isJSONItem())
  {
    setJSONRoot(member, theRoot);
  }

  member->addReference();
  theContent.insert(theContent.begin() + (cast(pos) - 1), member.getp());

#ifndef NDEBUG
  assertInvariant();
#endif
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::insert_before(
    const xs_integer& aPos,
    const std::vector<store::Item_t>& members)
{
#ifndef NDEBUG
  assertInvariant();
#endif
  // need to reserve at the beginning because reserve invalidates
  // existing iterators
  theContent.reserve(theContent.size() + members.size());

  add(cast(aPos) - 1, members);

#ifndef NDEBUG
  assertInvariant();
#endif
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::insert_after(
    const xs_integer& aPos,
    const std::vector<store::Item_t>& members)
{
#ifndef NDEBUG
  assertInvariant();
#endif
  // need to reserve at the beginning because reserve invalidates
  // existing iterators
  theContent.reserve(theContent.size() + members.size());

  add(cast(aPos), members);
#ifndef NDEBUG
  assertInvariant();
#endif
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::add(
    uint64_t aTargetPos,
    const std::vector<store::Item_t>& aNewMembers)
{
#ifndef NDEBUG
  assertInvariant();
#endif
  for (size_t i = 0; i < aNewMembers.size(); ++i)
  {
    store::Item* lItem = aNewMembers[i].getp();

    if (getCollection() != NULL && lItem->isJSONItem())
    {
      setJSONRoot(lItem, theRoot);
    }

    lItem->addReference();
    theContent.insert(theContent.begin() + aTargetPos + i, lItem);
  }

#ifndef NDEBUG
  assertInvariant();
#endif
}


/******************************************************************************

*******************************************************************************/
store::Item_t SimpleJSONArray::remove(const xs_integer& aPos)
{
#ifndef NDEBUG
  assertInvariant();
#endif
  store::Item_t lItem = getArrayValue(aPos);

  if (getCollection() != NULL && lItem->isJSONItem())
  {
    setJSONRoot(lItem, NULL);
  }

  lItem->removeReference();
  uint64_t lPosStartingZero = cast(aPos) - 1;
  theContent.erase(theContent.begin() + lPosStartingZero);

#ifndef NDEBUG
  assertInvariant();
#endif
  return lItem;
}


/******************************************************************************

*******************************************************************************/
store::Item_t SimpleJSONArray::replace(
    const xs_integer& aPos,
    const store::Item_t& value)
{
#ifndef NDEBUG
  assertInvariant();
#endif
  store::Item_t lItem = getArrayValue(aPos);

  if (getCollection() != NULL && lItem->isJSONItem())
  {
    setJSONRoot(lItem, NULL);
  }

  uint64_t pos = cast(aPos) - 1;

  if (getCollection() != NULL && value->isJSONItem())
  {
    setJSONRoot(value, theRoot);
  }

  theContent[pos]->removeReference();
  value->addReference();
  theContent[pos] = value.getp();
  
#ifndef NDEBUG
  assertInvariant();
#endif
  return lItem;
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::setRoot(const JSONItem* aRoot)
{
  theRoot = aRoot;

  for (Members::const_iterator lIter = theContent.begin();
       lIter != theContent.end();
       ++lIter)
  {
    if ((*lIter)->isJSONObject())
    {
      assert(dynamic_cast<SimpleJSONObject*>(*lIter));
      SimpleJSONObject* lObject = static_cast<SimpleJSONObject*>(*lIter);

      lObject->setRoot(aRoot);
    }
    else if ((*lIter)->isJSONArray())
    {
      assert(dynamic_cast<SimpleJSONArray*>(*lIter));
      SimpleJSONArray* lArray = static_cast<SimpleJSONArray*>(*lIter);
      
      lArray->setRoot(aRoot);
    }
  }
}


/******************************************************************************

*******************************************************************************/
uint64_t SimpleJSONArray::cast(const xs_integer& i)
{
  try 
  {
    return to_xs_unsignedLong(i);
  }
  catch (std::range_error& e)
  {
    throw ZORBA_EXCEPTION(zerr::ZSTR0060_RANGE_EXCEPTION,
    ERROR_PARAMS(BUILD_STRING("access out of bounds " << e.what() << ")")));
  }
}


/******************************************************************************

*******************************************************************************/
store::Item_t SimpleJSONArray::getArrayValue(const xs_integer& aPosition) const
{
#ifndef NDEBUG
  assertInvariant();
#endif
  uint64_t lPos = cast(aPosition);

  if (lPos == 0 || lPos > theContent.size())
  {
    return 0;
  }
  else
  {
    return theContent[lPos-1];
  }
}


/******************************************************************************

*******************************************************************************/
store::Iterator_t SimpleJSONArray::getArrayValues() const
{
#ifndef NDEBUG
  assertInvariant();
#endif
  return new ValuesIterator(const_cast<SimpleJSONArray*>(this));
}


/******************************************************************************

*******************************************************************************/
xs_integer SimpleJSONArray::getArraySize() const
{
#ifndef NDEBUG
  assertInvariant();
#endif
  store::Item_t lRes;
  xs_integer lSize(theContent.size());
  return lSize;
}


/******************************************************************************

*******************************************************************************/
store::Item* SimpleJSONArray::copy(
    store::Item* parent,
    const store::CopyMode& copymode) const
{
#ifndef NDEBUG
  assertInvariant();
#endif
  SimpleJSONArray* lNewArray = const_cast<SimpleJSONArray*>(this);
  if (copymode.theDoCopy)
  {
    lNewArray = new SimpleJSONArray();
    lNewArray->theContent.reserve(theContent.size());

    for (Members::const_iterator lIter = theContent.begin();
         lIter != theContent.end();
         ++lIter)
    {
      store::Item_t lValue = *lIter;
      if (lValue->isJSONObject() ||
          lValue->isJSONArray() ||
          lValue->isNode())
      {
        lValue = lValue->copy(NULL, copymode);
      }
      lNewArray->push_back(lValue);
    }
  }

  if (parent)
  {
    assert(parent->isJSONArray());
    JSONArray* a = static_cast<JSONArray*>(parent);
    a->push_back(lNewArray);
  }

  return lNewArray;
}


/******************************************************************************

*******************************************************************************/
zstring SimpleJSONArray::getStringValue() const
{
#ifndef NDEBUG
  assertInvariant();
#endif
  throw ZORBA_EXCEPTION(jerr::JNTY0003, ERROR_PARAMS("array"));
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::getStringValue2(zstring& val) const
{
#ifndef NDEBUG
  assertInvariant();
#endif
  val = getStringValue();
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::appendStringValue(zstring& buf) const
{
#ifndef NDEBUG
  assertInvariant();
#endif
  buf = getStringValue();
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::getTypedValue(store::Item_t& val, store::Iterator_t& iter) const
{
#ifndef NDEBUG
  assertInvariant();
#endif
  throw ZORBA_EXCEPTION(jerr::JNTY0004, ERROR_PARAMS("array"));
}


/*******************************************************************************

********************************************************************************/
void SimpleJSONArray::setCollection(SimpleCollection* collection, xs_integer /*pos*/)
{
#ifndef NDEBUG
  assertInvariant();
#endif
  // Ensures one either detaches or attaches.
  ZORBA_ASSERT(collection == NULL || theCollection == NULL);

  theCollection = collection;
  
  if (theCollection != NULL)
  {
    // Attach
    setRoot(this);
  }
  else
  {
    // Detach
    setRoot(NULL);
  }
  
#ifndef NDEBUG
  assertInvariant();
#endif
}

/******************************************************************************

*******************************************************************************/
const store::Collection* SimpleJSONArray::getCollection() const
{
  if (theRoot == this)
  {
    return theCollection;
  }
  else if (theRoot != NULL)
  {
    return theRoot->getCollection();
  }
  else
  {
    return NULL;
  }
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::assertInvariant() const
{
  assert(theCollection == NULL || theRoot == this);
  if (theRoot != NULL)
  {
    const store::Collection* lCollection = getCollection();
    assert(lCollection != NULL);
    const SimpleJSONObject* lObject = dynamic_cast<const SimpleJSONObject*>(theRoot);
    const SimpleJSONArray* lArray = dynamic_cast<const SimpleJSONArray*>(theRoot);
    assert(lObject != NULL || lArray != NULL);
    if (lObject != NULL) {
      assert(lObject->isThisRootOfAllDescendants(theRoot));
      assert(lObject->isThisJSONItemInDescendance(this));
    } else {
      assert(lArray->isThisRootOfAllDescendants(theRoot));
      assert(lArray->isThisJSONItemInDescendance(this));
    }
  }
}


/******************************************************************************

*******************************************************************************/
bool SimpleJSONArray::isThisRootOfAllDescendants(const store::Item* aRoot) const
{
  if(theRoot != aRoot)
  {
    return false;
  }
  for (Members::const_iterator lIter = theContent.begin();
       lIter != theContent.end();
       ++lIter)
  {
    const SimpleJSONObject* lObject =
        dynamic_cast<const SimpleJSONObject*>(*lIter);
    const SimpleJSONArray* lArray =
        dynamic_cast<const SimpleJSONArray*>(*lIter);
    if (lObject != NULL && (!lObject->isThisRootOfAllDescendants(aRoot)))
    {
      return false;
    }
    else if (lArray != NULL && (!lArray->isThisRootOfAllDescendants(aRoot)))
    {
      return false;
    }
  }
  return true;
}


/******************************************************************************

*******************************************************************************/
bool SimpleJSONArray::isThisJSONItemInDescendance(const store::Item* anItem) const
{
  if(this == anItem)
  {
    return true;
  }
  for (Members::const_iterator lIter = theContent.begin();
       lIter != theContent.end();
       ++lIter)
  {
    const SimpleJSONObject* lObject =
        dynamic_cast<const SimpleJSONObject*>(*lIter);
    const SimpleJSONArray* lArray =
        dynamic_cast<const SimpleJSONArray*>(*lIter);
    if (lObject != NULL && lObject->isThisJSONItemInDescendance(anItem))
    {
      return true;
    }
    else if (lArray != NULL && lArray->isThisJSONItemInDescendance(anItem))
    {
      return true;
    }
  }
  return false;
}


/******************************************************************************

*******************************************************************************/
SimpleJSONArray::ValuesIterator::~ValuesIterator() 
{
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::ValuesIterator::open()
{
  theIter = theArray->theContent.begin();
}


/******************************************************************************

*******************************************************************************/
bool SimpleJSONArray::ValuesIterator::next(store::Item_t& res)
{
  if (theIter != theArray->theContent.end())
  {
    res = *theIter;
    ++theIter;
    return true;
  }
  else
  {
    return false;
  }
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::ValuesIterator::reset()
{
  open();
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::ValuesIterator::close()
{
  theIter = theArray->theContent.end();
}




} // namespace json
} // namespace simplestore
} // namespace zorba

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
