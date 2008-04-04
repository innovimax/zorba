#ifndef XQP_XQUERY_IMPL_H
#define XQP_XQUERY_IMPL_H

#include <iostream>
#include <zorba/xquery.h>

#include <zorba/api_shared_types.h>
#include "zorbatypes/xqpstring.h"
#include "common/shared_types.h" 
#include "compiler/api/compilercb.h"


namespace zorba {

	class XQueryImpl : public XQuery 
	{
  public:
    virtual ~XQueryImpl();

    void
    registerErrorHandler(ErrorHandler*);

    void
    resetErrorHandler();

    bool
    isUpdateQuery() const;

    void
    serialize(std::ostream&, const XQuery::SerializerOptions_t& = XQuery::SerializerOptions());

    void 
    applyUpdates(std::ostream& os);

    ResultIterator_t
    iterator();

    DynamicContext_t
    getDynamicContext();

    const StaticContext_t
    getStaticContext() const;

    void
    compile(const String&);

    void 
    compile(const String&, const XQuery::CompilerHints_t& aHints);
      
    void 
    compile(std::istream&, const XQuery::CompilerHints_t& aHints);
      
    void 
    compile(const String&, const StaticContext_t&, const XQuery::CompilerHints_t& aHints);
      
    void 
    compile(std::istream&, const StaticContext_t&, const XQuery::CompilerHints_t& aHints);

    void
    setFileName( const String& );

    void
    close();

    XQuery_t
    clone() const;

		// only allow ZorbaImpl to create us
		friend class ZorbaImpl;

  protected:
    
    XQueryImpl();
      
    void
    doCompile(std::istream&, const XQuery::CompilerHints_t& aHints);

    CompilerCB::config_t
    getCompilerConfig(const XQuery::CompilerHints_t&);

    void
    setSerializationParameters(serializer*, const XQuery::SerializerOptions&);

    PlanWrapper_t
    generateWrapper();

    // check whether the query has already been closed
    // if so, fire an error
    void
    checkClosed() const;

    // check whether the query has been compiled (successfully)
    // if not, fire an error
    void
    checkCompiled() const;

    // static stuff
    xqpString              theFileName; // the filename of the query

    CompilerCB*            theCompilerCB;
    PlanIterator*          thePlan; 

    // static context is either generated by ourselves or given by the user 
    // (hence, the boolean flag in order to capture ownership).
    static_context       * theStaticContext;

    // dynamic stuff
    // one dynamic context that always belongs to a query
    dynamic_context      * theDynamicContext;

    // utility stuff
    bool                   theUserErrorHandler; // who has ownership of the error handler
    ErrorHandler         * theErrorHandler; // provided by user or default one throwing exceptions 
    error::ErrorManager  * theErrorManager; // see note in the constructor

    bool                   theIsClosed; // remember whether the query has been closed

	}; /* class XQueryImpl */


  std::ostream& operator<< (std::ostream& os, const XQuery_t& aQuery);


} /* namespace zorba */
#endif
