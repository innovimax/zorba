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
#ifndef ZORBA_STORE_SIMPLE_TEMP_SEQ_H
#define ZORBA_STORE_SIMPLE_TEMP_SEQ_H

#include <vector>

#include "store/api/iterator.h"
#include "store/api/temp_seq.h"

namespace zorba { namespace simplestore {

/**
 * 
 */
typedef rchandle<class SimpleTempSeq> SimpleTempSeq_t;


/*******************************************************************************
  Very simple implementation of Temp Sequence. It eagerly saves the items
  returned by an iterator into a vector.
********************************************************************************/
class SimpleTempSeq : public store::TempSeq
{
  friend class SimpleTempSeqIter;

private:
  std::vector<store::Item*> theItems; // ref-counting is done manually

private:
  void clear();

public:
  SimpleTempSeq() { }

  SimpleTempSeq(store::Item_t& item) 
  {
    theItems.push_back(NULL);
    theItems[0] = item.release();
  }

  SimpleTempSeq(std::vector<store::Item_t>& items);

  SimpleTempSeq(const store::Iterator_t& iter)
  {
    init(iter);
  }

  virtual ~SimpleTempSeq();

  void init(const store::Iterator_t& iter);

  void append(const store::Iterator_t& iter);

  void purge();

  void purgeUpTo(xs_integer upTo);

  bool empty();
  
  xs_integer getSize() const;

  void getItem(xs_integer position, store::Item_t& res);

  bool containsItem(xs_integer position);

  store::Iterator_t getIterator() const;

  store::Iterator_t getIterator(
      xs_integer startPos,
      xs_integer endPos,
      bool streaming = false) const;
};


/*******************************************************************************

********************************************************************************/
class SimpleTempSeqIter : public store::TempSeqIterator
{
 private:
  enum BorderType
  {
    none,
    startEnd
  };

  SimpleTempSeq_t                      theTempSeq;
  BorderType                           theBorderType;

  std::vector<store::Item*>::iterator  theIte;
  std::vector<store::Item*>::iterator  theBegin;
  std::vector<store::Item*>::iterator  theEnd;

 public:
  SimpleTempSeqIter() {}

  SimpleTempSeqIter(const SimpleTempSeq* seq);

  SimpleTempSeqIter(const SimpleTempSeq* seq, xs_integer startPos, xs_integer endPos);

  ~SimpleTempSeqIter() {}

  void init(const store::TempSeq_t& seq);

  void init(const store::TempSeq_t& seq, xs_integer startPos, xs_integer endPos);

  store::Item* next();

  void open();
  bool next(store::Item_t& result);
  void reset();
  void close();
 };


} // namespace store
} // namespace zorba

#endif /* ZORBA_STORE_SIIMPLE_TEMP_SEQ_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
