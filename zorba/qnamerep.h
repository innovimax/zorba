/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: qnamerep.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#ifndef XQP_QNAMEREP_H
#define XQP_QNAMEREP_H

#include "values/item.h"
#include "context/common.h"
#include <string>

namespace xqp {

class itemstore;

class qnamerep : public atomic_value
{
protected:
	std::string theURI;
	std::string theName;	// prefix:localname

public:
	qnamerep() {}
	qnamerep(
		const std::string& uri,
		const std::string& name);
	qnamerep(
		const std::string& uri,
		const std::string& prefix,
		const std::string& localname);

	~qnamerep() {}

public:
	std::string uri() const;
	std::string prefix() const;
	std::string localname() const;
	qnamekey_t qnamekey() const;

public: 	// XQuery atomic_value
	sequence_type_t type() const { return xs_qname; }
	Iterator_t atomized_value( yy::location &loc) const;
	Iterator_t effective_boolean_value( yy::location &loc) const;
	Iterator_t string_value( yy::location &loc) const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

public:		// output,debugging
	std::ostream& put(std::ostream& os) const;
	std::string describe() const;
	std::string str() const;

};



} /* namespace xqp */
#endif /* XQP_QNAMEREP_H */

