/** -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: context.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "context.h"

#include "../util/xqp_exception.h"
#include "../values/values.h"

#include <stdlib.h>
#include <sstream>
#include <string>



using namespace std;
namespace xqp {


/*...........................................
	:  default constructor                    :
	:.........................................:
*/

//XXX: seriously missing: context constructor from XML config file.

context::context()
:
	parent_h(NULL),
	namespaces(),
	in_scope_schema_types(),
	in_scope_elem_decls(),
	in_scope_attr_decls(),
	in_scope_vars(),
	collations(),
	//statically_known_collection_types(32,0.6),
	signature_map(256,0.6),
	statically_known_documents(256,0.6),
	statically_known_collections(64,0.6),
	context_item_h(NULL),
	context_position(0),
	context_size(0),
	var_values(1024,0.6),
	function_implementations(1024,0.6),
	timezone(-8),
	available_documents(1024,0.6),
	available_collections(1024,0.6),
	default_collection("defcol"),
	nodeid_counter("data/nodeid",1),
	string_store_h(new fxcharheap(1<<16)),
	node_store_h(new nodestore("data/store"))
{
}

context::~context()
{
}

/*...........................................
	:  strings                                :
	:.........................................:
*/

off_t context::put_string(
	string const& s)
{
	return string_store_h->put(s.c_str());
}

string context::get_string(
	off_t sref)
throw (xqp_exception)
{
	return string_store_h->get(sref);
}


/*...........................................
	:  nodeids                                :
	:.........................................:
*/

nodeid context::next_nodeid()
{
	return nodeid(++nodeid_counter[0]);
}

nodeid context::context_nodeid()
{
	return ctx_nodeid;
}

nodeid context::context_docid()
{
	return ctx_docid;
}


/*...........................................
	:  variables                              :
	:.........................................:
*/

var_binding::var_binding()
:
  name_h(NULL),
	value_h(NULL),
  type(item_type())
{
}

var_binding::var_binding(
	var_binding &  v)
:
  name_h(v.name_h),
	value_h(v.value_h),
  type(v.type)
{
}

var_binding::var_binding(
	var_binding const&  v)
:
  name_h(v.name_h),
  value_h(v.value_h),
  type(v.type)
{
}

var_binding::var_binding(
	rchandle<QName> _name_h,
	rchandle<item_iterator> _value_h,
	item_type const& _type)
:
	name_h(_name_h),
	value_h(_value_h),
	type(_type)
{
}

void context::push_var(
	rchandle<var_binding> vb_h)
{
	varstackref_t s_p;
	string varname = vb_h->get_qname()->describe(this);
	if (!var_values.get(varname, s_p)) {
		s_p = new stack<varref_t>;
		var_values.put(varname, s_p);
	}
	s_p->push(vb_h);
}

rchandle<item_iterator> context::get_var_value(
	rchandle<QName> vqn_h) const
throw (xqp_exception)
{
	varstackref_t s_p;
	string varname = vqn_h->string_value(this);
	if (!var_values.get(varname, s_p)) {
  	throw bad_arg(__FUNCTION__,"variable not found");
	}
	else {
		varref_t v_h = s_p->top();
		return v_h->get_value();
	}
}


/*...........................................
	:  functions                              :
	:.........................................:
*/

string context::get_function_type(
  QName const& fqname, 
  uint32_t arity) const 
throw (xqp_exception)
{
  ostringstream oss;
  fqname.put(oss,this) << '[' << arity << ']';
  string sig_h;
  if (!signature_map.get(oss.str(),sig_h)) {
    throw xqp_exception(__FUNCTION__,
      "no signature for: "+fqname.get_prefix()+':'+fqname.get_name());
  }
  return sig_h;
}
	
function_impl const* context::get_function(
	signature const& sig) const
throw (xqp_exception)
{
	return NULL;
}


/*...........................................
	:  context document                       :
	:.........................................:
*/

item_type context::get_document_type(
	string const& doc_uri) const
throw (xqp_exception)
{
  item_type t;
  if (!statically_known_documents.get(doc_uri,t)) {
    throw xqp_exception(__FUNCTION__,
      "no static document type for: "+doc_uri);
  }
  return t;
}
	
rchandle<item_iterator> context::get_document(
	string const& doc_uri) const
throw (xqp_exception)
{
  return new item_iterator(const_cast<context*>(this));
}


/*...........................................
	:  context collection                     :
	:.........................................:
*/

item_type context::get_collection_type(
	string const& col_uri) const
throw (xqp_exception)
{
  item_type t;
  if (!statically_known_collections.get(col_uri,t)) {
    throw xqp_exception(__FUNCTION__,
      "no static collection type for: "+col_uri);
  }
  return t;
}
	
rchandle<item_iterator> context::get_collection(
	string const& col_uri) const
throw (xqp_exception)
{
  return new item_iterator(const_cast<context*>(this));
}

rchandle<item_iterator> context::get_default_collection() const
throw (xqp_exception)
{
  return new item_iterator(const_cast<context*>(this));
}


/*...........................................
	:  node store                             :
	:.........................................:
*/

rchandle<node> context::get_node(nodeid id)
{
	rchandle<node> n_h;
	node_store_h->get(this, id, n_h);
	return n_h;
}

rchandle<node> context::get_node(nodeid id) const
{
	rchandle<node> n_h;
	node_store_h->get(const_cast<context*>(this), id, n_h);
	return n_h;
}

rchandle<nodestore> context::get_nodestore()
{
	return node_store_h;
}


}	/* namespace xqp */
