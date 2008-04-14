#ifndef ZORBA_ITERATOR_H
#define ZORBA_ITERATOR_H

#include "common/shared_types.h"

namespace zorba { namespace store {

  /**
   * General iterator interface. Used to program iterators which return a
   * sequence of items, wrapped into a rchandle object for garbage collection
   */
  class Iterator : virtual public SimpleRCObject
  {
    public:
      virtual ~Iterator() {}

      Iterator() {}

      Iterator(const Iterator&) 
        : SimpleRCObject() {}

      virtual void
      open() = 0;

      virtual store::Item_t
      next() = 0;

      virtual void
      reset() = 0;

      virtual void
      close() = 0;

  };
} /* namespace store */
} /* namespace zorba */
#endif
