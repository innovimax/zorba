/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: Assert.h,v 1.2 2006/10/13 06:53:29 Paul Pedersen Exp $
 *
 *  Copyright 2005-2006 FLWOR Foundation.
 *
 */


#ifndef XQP_ASSERT_H
#define XQP_ASSERT_H

#include <string>

namespace xqp {

#ifndef NDEBUG

void ZorbaAssert(const char *where, const char *what);

#define __Assert_aux3( line ) #line
#define __Assert_aux2( line ) __Assert_aux3( line )
#define __Assert_aux1( cond, line ) if (! (cond)) ZorbaAssert (__FILE__ ":" __Assert_aux2 (line), #cond)
#define ZORBA_ASSERT( cond ) __Assert_aux1 (cond, __LINE__)
#define Assert( cond ) ZORBA_ASSERT (cond)

#else //#ifndef NDEBUG

#define Assert( cond )			cond
#define ZORBA_ASSERT( cond ) 

#endif //#ifndef NDEBUG

}	/* namespace xqp */
#endif	/* XQP_ASSERT_H */

