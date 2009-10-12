/*
 * Copyright 2006-2008 The FLWOR Foundation.
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
 
#include "zorbaerrors/error_manager.h"
#include "zorbaerrors/Assert.h"

#include "system/globalenv.h"

#include "context/namespace_context.h"

#include "runtime/accessors/AccessorsImpl.h"
#include "runtime/visitors/planiter_visitor.h"

#include "store/api/item.h"
#include "store/api/iterator.h"
#include "store/api/item_factory.h"

namespace zorba {

SERIALIZABLE_CLASS_VERSIONS(FnDataIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnDataIterator)

SERIALIZABLE_CLASS_VERSIONS(FnRootIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnRootIterator)

SERIALIZABLE_CLASS_VERSIONS(FnNodeNameIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnNodeNameIterator)

SERIALIZABLE_CLASS_VERSIONS(FnNilledIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnNilledIterator)

SERIALIZABLE_CLASS_VERSIONS(FnBaseUriIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnBaseUriIterator)

SERIALIZABLE_CLASS_VERSIONS(FnDocumentUriIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnDocumentUriIterator)

SERIALIZABLE_CLASS_VERSIONS(FnStringIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnStringIterator)


/*******************************************************************************
  2.1 fn:node-name
********************************************************************************/
bool FnNodeNameIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t inNode;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(inNode, theChildren[0].getp(), planState))
  {
    if( inNode->getNodeKind() == store::StoreConsts::elementNode ||
        inNode->getNodeKind() == store::StoreConsts::attributeNode) 
    {
      result = inNode->getNodeName();
      STACK_PUSH(true, state);
    }
    else if(inNode->getNodeKind() == store::StoreConsts::piNode) 
    {
      GENV_ITEMFACTORY->createQName(result, xqp_string().getStore(),
                                    xqp_string().getStore(),
                                    inNode->getTarget());
      STACK_PUSH(true, state);
    }
  }
  STACK_END (state);
}


NARY_ACCEPT(FnNodeNameIterator);


/*******************************************************************************
  2.2 fn:nilled
********************************************************************************/
bool FnNilledIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t inNode;
  
  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(inNode, theChildren[0].getp(), planState))
  {
    if (inNode->isNode()) {
      result = inNode->getNilled();
      STACK_PUSH(result != NULL, state);
    } else
      ZORBA_ERROR_LOC_DESC(XPTY0004, loc,
                           "The argument of the fn:nilled function is not a node");
  }
  
  STACK_END (state);
}


NARY_ACCEPT(FnNilledIterator);


/*******************************************************************************
  2.3 fn:string
********************************************************************************/
bool FnStringIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t inVal;
  xqpStringStore_t strval;

  FnStringIteratorState* state;
  DEFAULT_STACK_INIT(FnStringIteratorState, state, planState);

  while(consumeNext(inVal, theChildren[0], planState)) 
  {
    state->hasOutput = true;
    strval = inVal->getStringValue();
    GENV_ITEMFACTORY->createString(result, strval);
    STACK_PUSH(true, state);
  }

  if (!state->hasOutput && theEmptyStringOnNULL) 
  {
    state->hasOutput = true;
    strval = new xqpStringStore("");
    GENV_ITEMFACTORY->createString(result, strval);
    STACK_PUSH(true, state);
  }

  STACK_END (state);
}


NARY_ACCEPT(FnStringIterator);


/*******************************************************************************
  2.4 fn:data
********************************************************************************/
void FnDataIteratorState::init(PlanState& planState) 
{ 
  PlanIteratorState::init( planState );
  theTypedValueIter = NULL;
}


void FnDataIteratorState::reset(PlanState& planState) 
{
  PlanIteratorState::reset( planState );
  theTypedValueIter = NULL;
}


bool
FnDataIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIter_t iter;
  store::Item_t itemNode;

  FnDataIteratorState* state;
  DEFAULT_STACK_INIT(FnDataIteratorState, state, planState);
  
  while (true) 
  {
    if (!consumeNext(result, theChild, planState))
      break;

    if (result->isAtomic())
    {
      STACK_PUSH(true, state);
    }
    else
    {
      assert(result->isNode());

      itemNode.transfer(result);
      itemNode->getTypedValue(result, state->theTypedValueIter);

      if (state->theTypedValueIter == NULL)
      {
        if (result == NULL)
          continue;

        STACK_PUSH(true, state );
      }
      else
      {
        state->theTypedValueIter->open();
      
        while (true) 
        {
          if (!state->theTypedValueIter->next(result))
            break;

          assert(!result->isNode());
          STACK_PUSH(true, state );
        }
      }
    }
  }

  state->theTypedValueIter = 0; // TODO remove???
  STACK_END (state);
}


UNARY_ACCEPT(FnDataIterator);


/*******************************************************************************
  2.5 fn:base-uri
********************************************************************************/
bool FnBaseUriIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t inNode;
  xqpStringStore_t baseuri;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(inNode, theChildren[0].getp(), planState))
  {
    baseuri = inNode->getBaseURI();
    if (baseuri != NULL) {
      GENV_ITEMFACTORY->createAnyURI(result, baseuri);
      STACK_PUSH(true, state);
    }
  }
  
  STACK_END (state);
}


NARY_ACCEPT(FnBaseUriIterator);


/*******************************************************************************
  2.6 fn:document-uri
********************************************************************************/
bool FnDocumentUriIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  xqpStringStore_t docuri;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(result, theChildren[0].getp(), planState))
  {
    docuri = result->getDocumentURI();
    if (docuri != NULL) {
      STACK_PUSH(GENV_ITEMFACTORY->createAnyURI(result, docuri), state);
    }
  }
  
  STACK_END (state);
}


NARY_ACCEPT(FnDocumentUriIterator);


/*******************************************************************************
  14.9 fn:root
********************************************************************************/
bool FnRootIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t contextNode;
  store::Item_t parentNode;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(result, theChildren[0].getp(), planState))
    return false;

  parentNode = result->getParent();

  while (parentNode != NULL)
  {
    result = parentNode;
    parentNode = parentNode->getParent();
  }

  STACK_PUSH(true, state);
  STACK_END (state);
}


NARY_ACCEPT(FnRootIterator);


} /* namespace zorba */
/* vim:set ts=2 sw=2: */
