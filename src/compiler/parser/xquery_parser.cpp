/* A Bison parser, made by GNU Bison 2.5.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

// Take the name prefix into account.
#define yylex   zorbalex

/* First part of user declarations.  */

/* Line 293 of lalr1.cc  */
#line 1 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"

#define XQUERY_PARSER

/* Line 293 of lalr1.cc  */
#line 59 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"


#include "common/common.h"

#ifdef WIN32
#pragma warning(disable: 4786)
#endif

#include "compiler/api/compilercb.h"
#include "compiler/parser/parse_constants.h"
#include "compiler/parser/parser_helpers.h"
#include "compiler/parser/xquery_driver.h"
#include "compiler/parsetree/parsenodes.h"
#include "store/api/update_consts.h"
#include "zorbatypes/decimal.h"
#include "zorbatypes/integer.h"

#define SYMTAB( n ) driver.symtab.get( (off_t)n )
#define SYMTAB_PUT( s ) driver.symtab.put( s )
#define LOC( p ) driver.createQueryLoc( p )

#define ERROR_IF_QNAME_NOT_NCNAME(qname, location)                \
  do {                                                            \
    if ( ! static_cast<QName*>(qname)->is_ncname()) {             \
      error((location), "A NCName is expected, found a QName");   \
      YYERROR;                                                    \
  }                                                               \
  } while (0);          


#define YYDEBUG 1

using namespace std;
using namespace zorba;


/* Line 293 of lalr1.cc  */
#line 102 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"


#ifdef XQUERY_PARSER
#include "compiler/parser/xquery_scanner.h"
#else
#include "compiler/parser/jsoniq_scanner.h"
#endif

#undef yylex
#ifdef XQUERY_PARSER
#define yylex driver.getXqueryLexer()->lex
#else
#define yylex driver.getJsoniqLexer()->lex
#endif



/* Line 293 of lalr1.cc  */
#line 102 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 299 of lalr1.cc  */
#line 785 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"

template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 299 of lalr1.cc  */
#line 839 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"

namespace {
bool convert_postfix_to_target_and_selector(
    exprnode* aPostfixExpr,
    rchandle<exprnode>* aTargetExpr,
    rchandle<exprnode>* aSelectorExpr,
    string* anError,
    bool allowArray = true)
{
  rchandle<DynamicFunctionInvocation> lDynamicFunctionInvocation =
      dynamic_cast<DynamicFunctionInvocation*>(aPostfixExpr);
  rchandle<FilterExpr> lFilterExpr = dynamic_cast<FilterExpr*>(aPostfixExpr);
  rchandle<JSONObjectLookup> lObjectLookup = dynamic_cast<JSONObjectLookup*>(aPostfixExpr);
  if (lDynamicFunctionInvocation != NULL) {
    if (lDynamicFunctionInvocation->getArgList()->size() != 1)
    {
      *anError = "An object or array lookup with exactly one argument is expected. Zero or more than one argument were found.";
      return false;
    }
    *aTargetExpr = lDynamicFunctionInvocation->getPrimaryExpr(),
    *aSelectorExpr = lDynamicFunctionInvocation->getArgList()->operator[](0);
    return true;
  }
  else
  {
    *anError = "An object or array lookup is expected.";
    return false;
  }
};
}


/* Line 299 of lalr1.cc  */
#line 154 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                               \
 do                                                                    \
   if (N)                                                              \
     {                                                                 \
       (Current).begin = YYRHSLOC (Rhs, 1).begin;                      \
       (Current).end   = YYRHSLOC (Rhs, N).end;                        \
     }                                                                 \
   else                                                                \
     {                                                                 \
       (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;        \
     }                                                                 \
 while (false)
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace zorba {

/* Line 382 of lalr1.cc  */
#line 240 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  xquery_parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              /* Fall through.  */
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  xquery_parser::xquery_parser (xquery_driver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {
  }

  xquery_parser::~xquery_parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  xquery_parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  xquery_parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  xquery_parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
        case 111: /* "\"'DECIMAL'\"" */

/* Line 480 of lalr1.cc  */
#line 784 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 345 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 125: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 783 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 354 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 150: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 782 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 363 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 372 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 381 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 390 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 399 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 408 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 417 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 426 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 435 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 444 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 453 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 462 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 471 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 480 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 489 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 498 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 507 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 516 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 525 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 534 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 543 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 552 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 561 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 570 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 579 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 588 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 597 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 606 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 615 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 624 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 633 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 642 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 651 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 660 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 669 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 794 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 678 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 794 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 687 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 794 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 696 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 705 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 714 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 723 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 732 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 741 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 750 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 759 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 768 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 777 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 786 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 795 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 804 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 813 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 822 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 831 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 840 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 858 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 867 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 894 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 903 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 912 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 939 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 948 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 957 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 966 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 975 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 984 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 993 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "VoidStatement" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1002 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1011 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1020 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1029 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1038 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1047 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1056 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1065 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1074 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1083 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1092 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1101 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1110 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1119 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1128 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1137 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1146 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1155 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1164 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1173 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1182 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1191 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1200 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1209 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1218 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1227 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1236 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1245 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1254 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1263 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1272 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1281 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1290 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1299 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1308 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1317 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1326 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1335 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1344 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1353 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1362 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1371 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1380 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1389 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1398 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1407 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1416 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "SequenceTypeList" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1425 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1434 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1443 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1452 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1461 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1470 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "StringConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1479 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1488 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1497 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1506 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1515 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1524 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1533 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1542 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1551 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1560 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1569 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1578 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1587 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1596 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1605 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "SimpleMapExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1614 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1623 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1632 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1641 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1650 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1659 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1668 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1677 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1686 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1695 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1704 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 793 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1713 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 793 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1722 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 793 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1731 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 793 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1740 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 793 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1749 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 793 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1758 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1767 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1776 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "PostfixExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1785 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1794 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1803 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1812 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1821 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1830 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1839 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1848 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1857 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1866 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1875 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1884 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 794 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1893 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1902 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1911 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1920 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1929 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1938 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1947 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1956 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1965 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1974 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 794 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1983 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 794 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1992 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2001 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 794 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2010 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2019 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2028 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2037 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2046 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2055 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2064 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2073 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2082 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2091 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2100 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2109 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2118 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "CompNamespaceConstructor" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2127 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2136 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2145 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2154 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2163 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2172 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "GeneralizedAtomicType" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2181 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "SimpleType" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2190 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2199 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 794 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2208 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2217 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "NamespaceTest" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2226 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2235 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2244 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2253 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2262 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2271 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2280 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2289 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2298 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2307 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2316 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2325 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2334 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2343 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2352 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2361 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2370 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2379 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2388 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2397 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2406 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2415 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2424 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 590: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2433 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 591: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2442 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2451 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2460 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2469 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2478 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2487 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2496 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2505 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2514 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2523 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2532 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2541 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2550 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2559 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 610: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2568 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 613: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2577 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 614: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2586 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 615: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2595 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 616: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2604 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 617: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2613 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 618: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2622 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 619: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2631 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 620: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2640 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 621: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2649 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 622: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2658 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 623: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2667 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 624: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2676 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 628: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2685 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 631: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2694 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 632: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2703 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 636: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2712 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 637: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2721 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 638: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2730 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 639: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2739 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 640: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2748 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 641: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2757 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 642: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2766 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 643: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2775 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 644: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2784 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 645: /* "JSONArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2793 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 646: /* "JSONSimpleObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2802 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 647: /* "JSONAccumulatorObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2811 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 648: /* "JSONObjectConstructor" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2820 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 649: /* "JSONPairList" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2829 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 650: /* "JSONInsertExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2838 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 651: /* "JSONAppendExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2847 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 652: /* "JSONDeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2856 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 653: /* "JSONRenameExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2865 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 654: /* "JSONReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2874 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 657: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2883 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 658: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2892 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;
      case 659: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2901 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	break;

	default:
	  break;
      }
  }

  void
  xquery_parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  xquery_parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  xquery_parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  xquery_parser::debug_level_type
  xquery_parser::debug_level () const
  {
    return yydebug_;
  }

  void
  xquery_parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  inline bool
  xquery_parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  xquery_parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  xquery_parser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    semantic_type yylval;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[3];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    
/* Line 565 of lalr1.cc  */
#line 129 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 565 of lalr1.cc  */
#line 2998 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"

    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval, &yylloc);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yy_table_value_is_error_ (yyn))
	  goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 3:

/* Line 690 of lalr1.cc  */
#line 875 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 879 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 883 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 889 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL;
      }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 897 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 903 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 909 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 937 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 943 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);
      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 949 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));
      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 955 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));
      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 963 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 968 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement");
      YYERROR;
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 976 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration");
      YYERROR;
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 984 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr);
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration");
      YYERROR;
    }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 992 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr);
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement");
      YYERROR;
    }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 1001 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 1006 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 1012 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 1018 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 1027 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(6) - (3)].expr), (yylocation_stack_[(6) - (3)]));
      (yyval.node) = new ModuleDecl( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 1035 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 1042 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 1048 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration");
      YYERROR;
    }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 1074 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 1079 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 1085 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 1091 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 1097 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 1102 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 1108 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 1113 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 1119 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 1124 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 1130 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, true);
    }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 1135 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, false);
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 1140 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, true);
    }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 1145 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, false);
    }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 1155 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node);
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\"");
      YYERROR;
    }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 1163 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 1168 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 1176 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 1184 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 1193 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 1200 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 1208 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 1214 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 1220 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 1226 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(6) - (4)].expr), (yylocation_stack_[(6) - (4)]));
      (yyval.node) = new ModuleImport(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 1233 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 1241 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(8) - (4)].expr), (yylocation_stack_[(8) - (4)]));
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(8) - (4)].expr)),
                            SYMTAB((yysemantic_stack_[(8) - (6)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
    }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 1252 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(5) - (3)].expr), (yylocation_stack_[(5) - (3)]));
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 1259 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 1266 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 1274 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 1281 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 1287 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration");
      YYERROR;
    }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 1306 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 1312 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1319 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1326 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1334 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1341 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1342 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1343 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1344 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinity"; }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1345 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1346 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1347 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1348 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1349 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1350 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1354 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
      if (static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr))->get_localname() == "enable")
      {
        zstring opt = SYMTAB((yysemantic_stack_[(4) - (4)].sval));
        if (opt.find(":") != zstring::npos)
          opt = opt.substr(opt.find(":")+1);
        if (opt == "common-language")
          driver.enableCommonLanguage();
      }
    }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1368 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1374 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1380 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1387 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1393 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1400 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1405 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1411 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1417 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      std::unique_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (2)].varnametype)));
      (yyval.node) = new GlobalVarDecl(LOC((yyloc)),
                             nt->theName,
                             nt->theType,
                             (yysemantic_stack_[(4) - (4)].expr),
                             nt->get_annotations(),
                             false);
      static_cast<GlobalVarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 1429 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      std::unique_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(3) - (2)].varnametype)));
      (yyval.node) = new GlobalVarDecl(LOC((yyloc)),
                             nt->theName,
                             nt->theType,
                             NULL,
                             nt->get_annotations(),
                             true);
      static_cast<GlobalVarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
    }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 1441 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      std::unique_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(5) - (2)].varnametype)));
      (yyval.node) = new GlobalVarDecl(LOC((yyloc)),
                             nt->theName,
                             nt->theType,
                             (yysemantic_stack_[(5) - (5)].expr),
                             nt->get_annotations(),
                             true);
      static_cast<GlobalVarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 1454 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1459 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1467 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1475 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1484 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1489 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1496 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1501 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1508 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1513 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1521 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1526 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1533 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1539 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));
      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1552 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      exprnode* body = (yysemantic_stack_[(4) - (4)].expr);
      if (body == NULL)
        body = new BlockBody(LOC((yylocation_stack_[(4) - (4)])));
      (yyval.node) = new FunctionDecl(LOC((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->theParams,
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->theReturnType,
                            body,
                            false,
                            false);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1566 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                            (yysemantic_stack_[(4) - (3)].fnsig)->theParams.getp(),
                            (yysemantic_stack_[(4) - (3)].fnsig)->theReturnType.getp(),
                            NULL,
                            false,
                            true);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1579 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      exprnode* body = (yysemantic_stack_[(5) - (5)].expr);
      if (body == NULL)
        body = new BlockBody(LOC((yylocation_stack_[(5) - (5)])));
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theParams.getp(),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theReturnType.getp(),
                            (yysemantic_stack_[(5) - (5)].expr),
                            true,
                            false);
      delete (yysemantic_stack_[(5) - (4)].fnsig);
    }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1594 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theParams.getp(),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theReturnType.getp(),
                            NULL,
                            true,
                            true);
      delete (yysemantic_stack_[(5) - (4)].fnsig);
    }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1607 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1612 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1617 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceTypeAST*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1622 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceTypeAST*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1628 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1635 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1643 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1648 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1656 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL);
      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
    }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1664 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              static_cast<SequenceTypeAST*>((yysemantic_stack_[(5) - (5)].node)));
      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1672 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)),
                               0);
      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1680 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)),
                               static_cast<SequenceTypeAST*>((yysemantic_stack_[(6) - (6)].node)));
      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
    }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1690 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceTypeAST(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1694 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceTypeAST(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1700 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceTypeAST(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 1704 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceTypeAST(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1711 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
                             (yysemantic_stack_[(8) - (6)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                             NULL);
      static_cast<AST_IndexDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(8) - (1)].sval)) );
    }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 1720 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(9) - (4)].expr)),
                             (yysemantic_stack_[(9) - (7)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(9) - (9)].node)),
                             static_cast<AnnotationListParsenode*>((yysemantic_stack_[(9) - (2)].node)));
      static_cast<AST_IndexDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(9) - (1)].sval)) );
    }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 1731 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 1737 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 1744 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1749 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceTypeAST*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 1756 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1763 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceTypeAST*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1773 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 1783 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 1793 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollForeachNode(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 1804 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICForeignKey( LOC((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(22) - (4)].expr)),
                            static_cast<QName*>((yysemantic_stack_[(22) - (9)].expr)),
                            static_cast<QName*>((yysemantic_stack_[(22) - (12)].expr)),
                            (yysemantic_stack_[(22) - (14)].expr),
                            static_cast<QName*>((yysemantic_stack_[(22) - (17)].expr)),
                            static_cast<QName*>((yysemantic_stack_[(22) - (20)].expr)),
                            (yysemantic_stack_[(22) - (22)].expr));
    }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 1817 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      if ((yysemantic_stack_[(1) - (1)].expr) == NULL)
      {
        error((yylocation_stack_[(1) - (1)]), "syntax error, unexpected end of file, the query body should not be empty");
        YYERROR;
      }
      if (dynamic_cast<BlockBody*>((yysemantic_stack_[(1) - (1)].expr)) != NULL)
      {
        BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(1) - (1)].expr));
        blk->setTopLevel(true);
      }
      (yyval.expr) = new QueryBody(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 1833 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 1837 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 1841 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 1847 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 1851 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 1855 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 1861 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 1866 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));
      blk->add((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 1874 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 1881 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));
      blk->add((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 1888 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(4) - (1)].expr);
      (yyval.expr) = (yysemantic_stack_[(4) - (2)].expr);
      (yyval.expr) = (yysemantic_stack_[(4) - (4)].expr);
      error((yylocation_stack_[(4) - (3)]), "syntax error, unexpected statement (missing semicolon \";\" between statements?)");
      delete (yysemantic_stack_[(4) - (1)].expr);
      delete (yysemantic_stack_[(4) - (2)].expr);
      delete (yysemantic_stack_[(4) - (4)].expr);
      YYERROR;
    }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 1916 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1921 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      driver.addCommonLanguageWarning((yylocation_stack_[(2) - (1)]), ZED(ZWST0009_EMPTY_BLOCK));
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1928 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* block = dynamic_cast<BlockBody*>((yysemantic_stack_[(3) - (2)].expr));
      if ((yysemantic_stack_[(3) - (2)].expr) == NULL)
      {
        (yyval.expr) = new BlockBody(LOC((yyloc)));
      }
      else if (block == NULL)
      {
        BlockBody* blk = new BlockBody(LOC((yyloc)));
        blk->add((yysemantic_stack_[(3) - (2)].expr));
        (yyval.expr) = blk;
      }
      else
      {
        (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
      }
    }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1948 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1954 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1960 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1967 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1974 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1983 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)),
                                          NULL,
                                          NULL,
                                          NULL);
      (yyval.node) = vd;
    }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1992 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                                          dynamic_cast<SequenceTypeAST*>((yysemantic_stack_[(3) - (3)].node)),
                                          NULL,
                                          NULL);
      (yyval.node) = vd;
    }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 2001 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                          NULL,
                                          (yysemantic_stack_[(4) - (4)].expr),
                                          NULL);
      (yyval.node) = vd;
    }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 2010 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                          dynamic_cast<SequenceTypeAST*>((yysemantic_stack_[(5) - (3)].node)),
                                          (yysemantic_stack_[(5) - (5)].expr),
                                          NULL);
      (yyval.node) = vd;
    }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 2021 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 2027 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 2033 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 2039 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* bb = dynamic_cast<BlockBody *>((yysemantic_stack_[(5) - (5)].expr));
      if (bb == NULL)
      {
        bb = new BlockBody((yysemantic_stack_[(5) - (5)].expr)->get_location());
        bb->add((yysemantic_stack_[(5) - (5)].expr));
      }
      (yyval.expr) = new WhileExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), bb);
    }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 2051 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 2056 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 2062 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      ReturnExpr* re = dynamic_cast<ReturnExpr*>((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = new FLWORExpr(LOC((yyloc)),
                         dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node)),
                         re->get_return_val(),
                         re->get_location(),
                         driver.theCompilerCB->theConfig.force_gflwor);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 2074 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      exprnode* retExpr = (yysemantic_stack_[(2) - (2)].expr);
      if (dynamic_cast<VarDeclStmt*>(retExpr) != NULL)
      {
        BlockBody* blk = new BlockBody(LOC((yyloc)));
        blk->add(retExpr);
        retExpr = blk;
      }
      (yyval.expr) = new ReturnExpr(LOC((yyloc)), retExpr);
    }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 2087 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      exprnode* thenExpr = (yysemantic_stack_[(8) - (6)].expr);
      exprnode* elseExpr = (yysemantic_stack_[(8) - (8)].expr);
      if (dynamic_cast<VarDeclStmt*>(thenExpr) != NULL)
      {
        BlockBody* blk = new BlockBody(LOC((yyloc)));
        blk->add(thenExpr);
        thenExpr = blk;
      }
      if (dynamic_cast<VarDeclStmt*>(elseExpr) != NULL)
      {
        BlockBody* blk = new BlockBody(LOC((yyloc)));
        blk->add(elseExpr);
        elseExpr = blk;
      }
      (yyval.expr) = new IfExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), thenExpr, elseExpr);
    }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 2107 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 2113 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 2120 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 2129 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 2136 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 2142 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 2147 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      Expr* expr = dynamic_cast<Expr*>((yysemantic_stack_[(3) - (1)].expr));
      if ( !expr )
      {
        expr = new Expr( LOC((yyloc)) );
        expr->push_back( (yysemantic_stack_[(3) - (1)].expr) );
      }
      expr->push_back( (yysemantic_stack_[(3) - (3)].expr) );
      (yyval.expr) = expr;
    }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 2159 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (1)].expr);
      (yyval.expr) = (yysemantic_stack_[(3) - (3)].expr);
      if (dynamic_cast<PathExpr*>((yysemantic_stack_[(3) - (1)].expr)) == NULL)
        error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected expression (missing comma \",\" between expressions?)");
      delete (yysemantic_stack_[(3) - (1)].expr);
      delete (yysemantic_stack_[(3) - (3)].expr);
      YYERROR;
    }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 2193 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      ReturnExpr *re = dynamic_cast<ReturnExpr*>((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = new FLWORExpr(LOC((yyloc)),
                         dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node)),
                         re->get_return_val(),
                         re->get_location(),
                         driver.theCompilerCB->theConfig.force_gflwor);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 2205 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 2211 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
    }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2216 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 2221 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2227 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 2232 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 2237 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 2243 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)),
                            (yysemantic_stack_[(4) - (4)].expr),
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 243:

/* Line 690 of lalr1.cc  */
#line 2252 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            NULL,
                            (yysemantic_stack_[(3) - (3)].expr),
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 244:

/* Line 690 of lalr1.cc  */
#line 2262 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(5) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(5) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (4)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 245:

/* Line 690 of lalr1.cc  */
#line 2272 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 246:

/* Line 690 of lalr1.cc  */
#line 2283 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2301 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 2308 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2316 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2320 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected qualified name \""
          + static_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node))->operator[](0)->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (3)].node);
      YYERROR;
    }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 2328 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL;
      error((yylocation_stack_[(2) - (2)]), "");
      YYERROR;
    }
    break;

  case 260:

/* Line 690 of lalr1.cc  */
#line 2336 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
    }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 2341 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 262:

/* Line 690 of lalr1.cc  */
#line 2348 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 263:

/* Line 690 of lalr1.cc  */
#line 2355 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
      error((yylocation_stack_[(3) - (3)]), "syntax error, unexpected QName \""
          + static_cast<VarInDecl*>((yysemantic_stack_[(3) - (3)].node))->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (1)].node);
      YYERROR;
    }
    break;

  case 264:

/* Line 690 of lalr1.cc  */
#line 2365 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)),
                         NULL,
                         NULL,
                         NULL,
                         (yysemantic_stack_[(3) - (3)].expr),
                         false);
    }
    break;

  case 265:

/* Line 690 of lalr1.cc  */
#line 2375 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         NULL,
                         NULL,
                         NULL,
                         (yysemantic_stack_[(5) - (5)].expr),
                         true);
    }
    break;

  case 266:

/* Line 690 of lalr1.cc  */
#line 2385 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(4) - (2)].node)),
                         NULL,
                         NULL,
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 267:

/* Line 690 of lalr1.cc  */
#line 2395 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)),
                         dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(6) - (2)].node)),
                         NULL,
                         NULL,
                         (yysemantic_stack_[(6) - (6)].expr),
                         true);
    }
    break;

  case 268:

/* Line 690 of lalr1.cc  */
#line 2405 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)),
                         NULL,
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 269:

/* Line 690 of lalr1.cc  */
#line 2415 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (4)].node)),
                         NULL,
                         (yysemantic_stack_[(6) - (6)].expr),
                         true);
    }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 2425 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(5) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
                         NULL,
                         (yysemantic_stack_[(5) - (5)].expr),
                         false);
    }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 2435 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(7) - (1)].expr)),
                         dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(7) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(7) - (5)].node)),
                         NULL,
                         (yysemantic_stack_[(7) - (7)].expr),
                         true);
    }
    break;

  case 272:

/* Line 690 of lalr1.cc  */
#line 2445 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 2454 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(5) - (2)].node)),
                         NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         false);
    }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 2464 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC ((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (2)].node)),
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         false);
    }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2474 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC ((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)),
                         dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(6) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (3)].node)),
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                         (yysemantic_stack_[(6) - (6)].expr),
                         false);
    }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2486 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2492 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2498 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2504 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2510 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 2518 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2526 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 2534 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2542 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 2552 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 2558 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 2568 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 2572 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 2579 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 2583 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 2591 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 2595 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 2599 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 2605 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 2611 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 2617 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 2623 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 2631 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 2635 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         static_cast<SequenceTypeAST*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         NULL);
    }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 2643 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                         static_cast<SequenceTypeAST*>((yysemantic_stack_[(6) - (3)].node)),
                         (yysemantic_stack_[(6) - (5)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 2651 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         NULL,
                         (yysemantic_stack_[(5) - (4)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 2659 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      VarRef* varRef = dynamic_cast<VarRef*>((yysemantic_stack_[(1) - (1)].expr));
      if (varRef != NULL)
        (yyval.node) = new GroupSpec(LOC((yyloc)), varRef, NULL, NULL, NULL);
      else
        (yyval.node) = new GroupSpec(LOC((yyloc)), NULL, NULL, (yysemantic_stack_[(1) - (1)].expr), NULL);
    }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 2667 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      VarRef* varRef = dynamic_cast<VarRef*>((yysemantic_stack_[(2) - (1)].expr));
      if (varRef != NULL)
        (yyval.node) = new GroupSpec(LOC((yyloc)), varRef, NULL, NULL, static_cast<GroupCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
      else
        (yyval.node) = new GroupSpec(LOC((yyloc)), NULL, NULL, (yysemantic_stack_[(2) - (1)].expr), static_cast<GroupCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 2677 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 2683 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 2689 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 2697 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 2703 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 2711 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 2715 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 2723 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 2729 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 2735 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 2741 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 2750 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 2759 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 2768 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 2779 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 2783 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 2789 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 2795 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 2803 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 2809 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 2818 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 2829 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;
    }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 2835 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 2843 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 2847 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 2856 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 2862 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 2868 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 2876 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 2882 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 2888 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 2896 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 2902 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 2908 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 2916 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 341:

/* Line 690 of lalr1.cc  */
#line 2922 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 2929 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 343:

/* Line 690 of lalr1.cc  */
#line 2939 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 2946 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 2956 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 2962 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 2970 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 2976 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 2985 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 2991 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = static_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 2999 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 3005 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 3014 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      SequenceTypeList* seqList = new SequenceTypeList(LOC((yyloc)));
      seqList->push_back(static_cast<SequenceTypeAST*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = seqList;
    }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 3020 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      SequenceTypeList* seqList = static_cast<SequenceTypeList*>((yysemantic_stack_[(3) - (1)].node));
      seqList->push_back(static_cast<SequenceTypeAST*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 3028 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 3034 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 3038 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 3044 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 3049 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 360:

/* Line 690 of lalr1.cc  */
#line 3055 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 3059 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 3068 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 363:

/* Line 690 of lalr1.cc  */
#line 3074 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 364:

/* Line 690 of lalr1.cc  */
#line 3083 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 365:

/* Line 690 of lalr1.cc  */
#line 3092 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            driver.getXqueryLexer()->interpretAsLessThan();
        }
    break;

  case 366:

/* Line 690 of lalr1.cc  */
#line 3096 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 367:

/* Line 690 of lalr1.cc  */
#line 3105 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 368:

/* Line 690 of lalr1.cc  */
#line 3114 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 3123 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 3134 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 3138 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 3149 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 3153 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 3158 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 3162 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 376:

/* Line 690 of lalr1.cc  */
#line 3168 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 3172 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 3178 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 3182 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 3186 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 3192 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 3196 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 3202 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 3208 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 3214 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 3222 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 3226 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 3230 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 3236 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 3240 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 3246 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 3254 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 3258 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceTypeAST*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 3266 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 3270 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceTypeAST*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 3278 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 3282 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 3290 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 3294 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 3302 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(1) - (1)].node)), false);
    }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 3306 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(2) - (1)].node)), true);
    }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 3312 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 3316 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 3322 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 3326 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 3330 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 3334 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 3347 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
        (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
      }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 3352 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
        (yyval.expr) = new SimpleMapExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
      }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 3358 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 3362 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 3366 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 3370 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 3374 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 3378 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 3384 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 3388 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 3392 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 3398 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 3402 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 3406 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 3410 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 3419 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 3427 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 3433 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 3441 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 3445 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 3449 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 432:

/* Line 690 of lalr1.cc  */
#line 3455 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 3459 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;
      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);
      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 3467 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;
      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);
      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 3475 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      if (rpe != NULL &&
         ( (dynamic_cast<ContextItemExpr*>(rpe->get_step_expr()) != NULL &&
             dynamic_cast<ContextItemExpr*>(rpe->get_step_expr())->is_placeholder() &&
             dynamic_cast<AxisStep*>(rpe->get_relpath_expr()) != NULL)
           ||
             dynamic_cast<AxisStep*>(rpe->get_step_expr()) != NULL))
      {
        driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_AXIS_STEP));
      }
      if ((yyval.expr) == NULL)
        (yyval.expr) = (rpe ?
              new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)) :
              (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 3495 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 3501 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      AxisStep* as = dynamic_cast<AxisStep*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (as ?
            new RelativePathExpr(LOC((yyloc)),
                                 ParseConstants::st_slash,
                                 new ContextItemExpr( LOC((yyloc)), true ), (yysemantic_stack_[(1) - (1)].expr), true)
            :
            (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 3511 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 3515 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 3525 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 443:

/* Line 690 of lalr1.cc  */
#line 3531 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 3539 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 3545 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 3555 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 3561 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 3569 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 3573 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 3577 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 3581 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 3585 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 3591 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 3597 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 3603 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 3607 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 3613 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 3617 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 3626 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 3630 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 3634 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 3640 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 3644 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 3656 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 3660 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 3666 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 3670 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 3674 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 3678 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 3684 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 3688 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 3692 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), false);
     }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 3696 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)), false);
     }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 3702 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      PredicateList* pl = new PredicateList( LOC((yyloc)) );
      pl->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.node) = pl;
    }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 3708 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      if (PredicateList* pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)))
        pl->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 3716 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 3738 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 3742 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 3748 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 3755 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 3762 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 3771 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 3777 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 3781 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 3787 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_CONTEXT_ITEM_EXPR));
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 3794 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 3800 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 3806 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FunctionCall(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL);
    }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 3810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      ArgList* argList = dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node));
      if (argList->has_placeholder())
      {
        LiteralFunctionItem* lfi =
        new LiteralFunctionItem(LOC((yyloc)),
                                dynamic_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                                new Integer(argList->size()));
        (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), lfi, argList, true);
      }
      else
      {
        (yyval.expr) = new FunctionCall(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)), argList);
      }
    }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 3828 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      ArgList* al = new ArgList(LOC((yyloc)));
      al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = al;
    }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 3834 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      if (ArgList* al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)))
        al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 3840 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
      (yyval.node) = al;
    }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 3846 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 3854 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 3858 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 3864 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 3870 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 3889 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                  NULL,
                                  NULL,
                                  NULL);
    }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 3897 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      if (static_cast<QName*>((yysemantic_stack_[(8) - (2)].expr))->get_qname() != static_cast<QName*>((yysemantic_stack_[(8) - (6)].expr))->get_qname())
      {
        error((yylocation_stack_[(8) - (5)]), "syntax error, end tag </" +
                  static_cast<QName*>((yysemantic_stack_[(8) - (6)].expr))->get_qname().str() +
                  "> does not match start tag <" +
                  static_cast<QName*>((yysemantic_stack_[(8) - (2)].expr))->get_qname().str() + ">");
        YYERROR;
      }
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(8) - (2)].expr)),
                                  static_cast<QName*>((yysemantic_stack_[(8) - (6)].expr)),
                                  NULL,
                                  NULL);
    }
    break;

  case 521:

/* Line 690 of lalr1.cc  */
#line 3913 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                  NULL,
                                  dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)),
                                  NULL);
    }
    break;

  case 522:

/* Line 690 of lalr1.cc  */
#line 3921 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      if (static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr))->get_qname() != static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr))->get_qname())
      {
        error((yylocation_stack_[(9) - (5)]), "syntax error, end tag </" +
                  static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr))->get_qname().str() +
                  "> does not match start tag <" +
                  static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr))->get_qname().str() + ">");
        YYERROR;
      }
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
                                  static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
                                  dynamic_cast<DirAttributeList*>((yysemantic_stack_[(9) - (3)].node)),
                                  NULL);
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 3939 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      if (static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr))->get_qname() != static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr))->get_qname())
      {
        error((yylocation_stack_[(9) - (5)]), "syntax error, end tag </" +
                  static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr))->get_qname().str() +
                  "> does not match start tag <" +
                  static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr))->get_qname().str() + ">");
        YYERROR;
      }
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
                                  static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
                                  NULL,
                                  dynamic_cast<DirElemContentList*>((yysemantic_stack_[(9) - (5)].node)));
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 3957 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      if (static_cast<QName*>((yysemantic_stack_[(10) - (2)].expr))->get_qname() != static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr))->get_qname())
      {
        error((yylocation_stack_[(10) - (5)]), "syntax error, end tag </" +
                  static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr))->get_qname().str() +
                  "> does not match start tag <" +
                  static_cast<QName*>((yysemantic_stack_[(10) - (2)].expr))->get_qname().str() + ">");
        YYERROR;
      }
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(10) - (2)].expr)),
                                  static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                                  dynamic_cast<DirAttributeList*>((yysemantic_stack_[(10) - (3)].node)),
                                  dynamic_cast<DirElemContentList*>((yysemantic_stack_[(10) - (6)].node)));
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 3975 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
      decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.node) = decl;
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 3981 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( decl )
        decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 3990 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
      dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = dal;
    }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 3996 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
      if ( dal )
        dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 4005 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttr(LOC((yyloc)),
                       static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                       dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 4015 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttributeValue(LOC((yyloc)),
                                 dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 4020 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                  dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 4026 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 4030 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 4036 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = qacl;
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 4042 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qacl;
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 4048 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList* qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 4055 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 4063 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 4067 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 4073 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = aacl;
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 4079 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = aacl;
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 4085 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if (aacl)
        aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 4092 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( aacl )
        aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 4101 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 4105 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 4111 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 4115 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 4121 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 4125 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 4129 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 4134 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
    }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 4141 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 4145 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_lbrace);
    }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 4149 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_rbrace);
    }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 4153 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 4159 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 4164 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 4170 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)) );
    }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 4176 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 4183 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 4189 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 4194 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 4199 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 4204 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 4209 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 4214 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 4222 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 4228 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 4232 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 4238 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
    }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 4242 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 4248 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 4254 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 4260 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 4264 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 4270 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 4274 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 4280 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 4286 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceTypeAST( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 4290 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceTypeAST(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 4294 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceTypeAST( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 4300 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 4306 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 4312 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 4320 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            GeneralizedAtomicType* gat = static_cast<GeneralizedAtomicType*>((yysemantic_stack_[(1) - (1)].node));
            QName* q = gat->get_qname();
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 4326 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 4330 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 4334 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 4338 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 4342 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 4346 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 4352 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 4358 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 4366 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GeneralizedAtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 4372 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SimpleType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 4378 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 600:

/* Line 690 of lalr1.cc  */
#line 4382 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 601:

/* Line 690 of lalr1.cc  */
#line 4386 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 602:

/* Line 690 of lalr1.cc  */
#line 4390 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 603:

/* Line 690 of lalr1.cc  */
#line 4394 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 604:

/* Line 690 of lalr1.cc  */
#line 4398 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 605:

/* Line 690 of lalr1.cc  */
#line 4402 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 606:

/* Line 690 of lalr1.cc  */
#line 4406 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 607:

/* Line 690 of lalr1.cc  */
#line 4410 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 608:

/* Line 690 of lalr1.cc  */
#line 4414 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 609:

/* Line 690 of lalr1.cc  */
#line 4420 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyKindTest( LOC((yyloc)) );
    }
    break;

  case 610:

/* Line 690 of lalr1.cc  */
#line 4426 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 611:

/* Line 690 of lalr1.cc  */
#line 4432 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)));
    }
    break;

  case 612:

/* Line 690 of lalr1.cc  */
#line 4436 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 613:

/* Line 690 of lalr1.cc  */
#line 4440 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 614:

/* Line 690 of lalr1.cc  */
#line 4446 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceTest(LOC((yyloc)));
    }
    break;

  case 615:

/* Line 690 of lalr1.cc  */
#line 4451 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new TextTest(LOC((yyloc)));
    }
    break;

  case 616:

/* Line 690 of lalr1.cc  */
#line 4457 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CommentTest(LOC((yyloc)));
    }
    break;

  case 617:

/* Line 690 of lalr1.cc  */
#line 4463 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 618:

/* Line 690 of lalr1.cc  */
#line 4467 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(4) - (3)].expr), (yylocation_stack_[(4) - (3)]));
            (yyval.node) = new PITest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 619:

/* Line 690 of lalr1.cc  */
#line 4472 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 620:

/* Line 690 of lalr1.cc  */
#line 4478 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 621:

/* Line 690 of lalr1.cc  */
#line 4482 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 622:

/* Line 690 of lalr1.cc  */
#line 4488 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 623:

/* Line 690 of lalr1.cc  */
#line 4494 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 624:

/* Line 690 of lalr1.cc  */
#line 4498 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 625:

/* Line 690 of lalr1.cc  */
#line 4506 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 626:

/* Line 690 of lalr1.cc  */
#line 4512 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 627:

/* Line 690 of lalr1.cc  */
#line 4516 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 628:

/* Line 690 of lalr1.cc  */
#line 4522 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 629:

/* Line 690 of lalr1.cc  */
#line 4531 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 630:

/* Line 690 of lalr1.cc  */
#line 4540 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 631:

/* Line 690 of lalr1.cc  */
#line 4546 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 632:

/* Line 690 of lalr1.cc  */
#line 4552 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 633:

/* Line 690 of lalr1.cc  */
#line 4560 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 634:

/* Line 690 of lalr1.cc  */
#line 4566 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 635:

/* Line 690 of lalr1.cc  */
#line 4572 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 636:

/* Line 690 of lalr1.cc  */
#line 4578 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 637:

/* Line 690 of lalr1.cc  */
#line 4584 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 638:

/* Line 690 of lalr1.cc  */
#line 4588 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 639:

/* Line 690 of lalr1.cc  */
#line 4594 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 640:

/* Line 690 of lalr1.cc  */
#line 4600 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 641:

/* Line 690 of lalr1.cc  */
#line 4604 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 642:

/* Line 690 of lalr1.cc  */
#line 4612 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 643:

/* Line 690 of lalr1.cc  */
#line 4618 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 644:

/* Line 690 of lalr1.cc  */
#line 4624 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 645:

/* Line 690 of lalr1.cc  */
#line 4630 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 646:

/* Line 690 of lalr1.cc  */
#line 4638 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 647:

/* Line 690 of lalr1.cc  */
#line 4642 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 648:

/* Line 690 of lalr1.cc  */
#line 4648 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 649:

/* Line 690 of lalr1.cc  */
#line 4654 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 650:

/* Line 690 of lalr1.cc  */
#line 4658 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 651:

/* Line 690 of lalr1.cc  */
#line 4664 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 652:

/* Line 690 of lalr1.cc  */
#line 4668 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 653:

/* Line 690 of lalr1.cc  */
#line 4674 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 654:

/* Line 690 of lalr1.cc  */
#line 4680 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 655:

/* Line 690 of lalr1.cc  */
#line 4687 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 656:

/* Line 690 of lalr1.cc  */
#line 4695 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 657:

/* Line 690 of lalr1.cc  */
#line 4700 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 658:

/* Line 690 of lalr1.cc  */
#line 4706 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 659:

/* Line 690 of lalr1.cc  */
#line 4712 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 660:

/* Line 690 of lalr1.cc  */
#line 4720 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 661:

/* Line 690 of lalr1.cc  */
#line 4726 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 662:

/* Line 690 of lalr1.cc  */
#line 4733 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 663:

/* Line 690 of lalr1.cc  */
#line 4739 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 664:

/* Line 690 of lalr1.cc  */
#line 4748 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 665:

/* Line 690 of lalr1.cc  */
#line 4754 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 666:

/* Line 690 of lalr1.cc  */
#line 4760 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 667:

/* Line 690 of lalr1.cc  */
#line 4766 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 668:

/* Line 690 of lalr1.cc  */
#line 4775 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 669:

/* Line 690 of lalr1.cc  */
#line 4782 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 670:

/* Line 690 of lalr1.cc  */
#line 4788 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 671:

/* Line 690 of lalr1.cc  */
#line 4794 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 672:

/* Line 690 of lalr1.cc  */
#line 4803 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 673:

/* Line 690 of lalr1.cc  */
#line 4810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 674:

/* Line 690 of lalr1.cc  */
#line 4814 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 675:

/* Line 690 of lalr1.cc  */
#line 4820 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 676:

/* Line 690 of lalr1.cc  */
#line 4825 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 677:

/* Line 690 of lalr1.cc  */
#line 4832 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 678:

/* Line 690 of lalr1.cc  */
#line 4836 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 679:

/* Line 690 of lalr1.cc  */
#line 4842 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 680:

/* Line 690 of lalr1.cc  */
#line 4846 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 681:

/* Line 690 of lalr1.cc  */
#line 4852 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 682:

/* Line 690 of lalr1.cc  */
#line 4856 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 683:

/* Line 690 of lalr1.cc  */
#line 4862 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 684:

/* Line 690 of lalr1.cc  */
#line 4866 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 685:

/* Line 690 of lalr1.cc  */
#line 4874 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 686:

/* Line 690 of lalr1.cc  */
#line 4884 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 687:

/* Line 690 of lalr1.cc  */
#line 4888 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 688:

/* Line 690 of lalr1.cc  */
#line 4893 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 689:

/* Line 690 of lalr1.cc  */
#line 4897 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 690:

/* Line 690 of lalr1.cc  */
#line 4903 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 691:

/* Line 690 of lalr1.cc  */
#line 4909 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 692:

/* Line 690 of lalr1.cc  */
#line 4917 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 693:

/* Line 690 of lalr1.cc  */
#line 4921 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 694:

/* Line 690 of lalr1.cc  */
#line 4926 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 695:

/* Line 690 of lalr1.cc  */
#line 4930 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 696:

/* Line 690 of lalr1.cc  */
#line 4936 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 697:

/* Line 690 of lalr1.cc  */
#line 4945 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 698:

/* Line 690 of lalr1.cc  */
#line 4949 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 699:

/* Line 690 of lalr1.cc  */
#line 4955 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 700:

/* Line 690 of lalr1.cc  */
#line 4965 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 701:

/* Line 690 of lalr1.cc  */
#line 4971 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 702:

/* Line 690 of lalr1.cc  */
#line 4978 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 703:

/* Line 690 of lalr1.cc  */
#line 4982 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 704:

/* Line 690 of lalr1.cc  */
#line 4988 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 705:

/* Line 690 of lalr1.cc  */
#line 4992 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 706:

/* Line 690 of lalr1.cc  */
#line 4996 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 707:

/* Line 690 of lalr1.cc  */
#line 5001 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 708:

/* Line 690 of lalr1.cc  */
#line 5005 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 709:

/* Line 690 of lalr1.cc  */
#line 5010 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 710:

/* Line 690 of lalr1.cc  */
#line 5014 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 711:

/* Line 690 of lalr1.cc  */
#line 5020 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 712:

/* Line 690 of lalr1.cc  */
#line 5024 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 713:

/* Line 690 of lalr1.cc  */
#line 5028 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 714:

/* Line 690 of lalr1.cc  */
#line 5032 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 715:

/* Line 690 of lalr1.cc  */
#line 5036 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 716:

/* Line 690 of lalr1.cc  */
#line 5042 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 717:

/* Line 690 of lalr1.cc  */
#line 5048 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 718:

/* Line 690 of lalr1.cc  */
#line 5058 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 719:

/* Line 690 of lalr1.cc  */
#line 5068 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 720:

/* Line 690 of lalr1.cc  */
#line 5072 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 721:

/* Line 690 of lalr1.cc  */
#line 5076 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 722:

/* Line 690 of lalr1.cc  */
#line 5082 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 723:

/* Line 690 of lalr1.cc  */
#line 5088 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 724:

/* Line 690 of lalr1.cc  */
#line 5096 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 725:

/* Line 690 of lalr1.cc  */
#line 5100 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 726:

/* Line 690 of lalr1.cc  */
#line 5104 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 727:

/* Line 690 of lalr1.cc  */
#line 5108 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 728:

/* Line 690 of lalr1.cc  */
#line 5112 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 729:

/* Line 690 of lalr1.cc  */
#line 5116 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 730:

/* Line 690 of lalr1.cc  */
#line 5120 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 731:

/* Line 690 of lalr1.cc  */
#line 5124 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 732:

/* Line 690 of lalr1.cc  */
#line 5130 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 733:

/* Line 690 of lalr1.cc  */
#line 5134 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 734:

/* Line 690 of lalr1.cc  */
#line 5138 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 735:

/* Line 690 of lalr1.cc  */
#line 5142 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 736:

/* Line 690 of lalr1.cc  */
#line 5148 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 737:

/* Line 690 of lalr1.cc  */
#line 5154 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 738:

/* Line 690 of lalr1.cc  */
#line 5162 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 739:

/* Line 690 of lalr1.cc  */
#line 5170 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 740:

/* Line 690 of lalr1.cc  */
#line 5174 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 741:

/* Line 690 of lalr1.cc  */
#line 5180 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            FTThesaurusOption::thesaurus_id_list_t *til = NULL;
            if ( (yysemantic_stack_[(2) - (2)].node) ) {
                til = new FTThesaurusOption::thesaurus_id_list_t;
                til->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(2) - (2)].node)) );
            }
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), til, !til );
            delete til;
        }
    break;

  case 742:

/* Line 690 of lalr1.cc  */
#line 5190 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            FTThesaurusOption::thesaurus_id_list_t *til = (yysemantic_stack_[(5) - (4)].thesaurus_id_list);
            if ( (yysemantic_stack_[(5) - (3)].node) ) {
                if ( !til )
                    til = new FTThesaurusOption::thesaurus_id_list_t;
                til->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(5) - (3)].node)) );
            }
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), til, !(yysemantic_stack_[(5) - (3)].node) );
            delete til;
        }
    break;

  case 743:

/* Line 690 of lalr1.cc  */
#line 5201 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 744:

/* Line 690 of lalr1.cc  */
#line 5207 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 745:

/* Line 690 of lalr1.cc  */
#line 5211 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 746:

/* Line 690 of lalr1.cc  */
#line 5216 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 747:

/* Line 690 of lalr1.cc  */
#line 5220 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 748:

/* Line 690 of lalr1.cc  */
#line 5226 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 749:

/* Line 690 of lalr1.cc  */
#line 5231 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 750:

/* Line 690 of lalr1.cc  */
#line 5238 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 751:

/* Line 690 of lalr1.cc  */
#line 5245 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 752:

/* Line 690 of lalr1.cc  */
#line 5249 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 753:

/* Line 690 of lalr1.cc  */
#line 5255 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 754:

/* Line 690 of lalr1.cc  */
#line 5259 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 755:

/* Line 690 of lalr1.cc  */
#line 5265 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 756:

/* Line 690 of lalr1.cc  */
#line 5274 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 757:

/* Line 690 of lalr1.cc  */
#line 5281 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 758:

/* Line 690 of lalr1.cc  */
#line 5289 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 759:

/* Line 690 of lalr1.cc  */
#line 5293 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 760:

/* Line 690 of lalr1.cc  */
#line 5299 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 761:

/* Line 690 of lalr1.cc  */
#line 5305 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 762:

/* Line 690 of lalr1.cc  */
#line 5312 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 763:

/* Line 690 of lalr1.cc  */
#line 5316 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 764:

/* Line 690 of lalr1.cc  */
#line 5322 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 765:

/* Line 690 of lalr1.cc  */
#line 5327 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 766:

/* Line 690 of lalr1.cc  */
#line 5337 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 767:

/* Line 690 of lalr1.cc  */
#line 5345 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 768:

/* Line 690 of lalr1.cc  */
#line 5355 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 769:

/* Line 690 of lalr1.cc  */
#line 5361 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 770:

/* Line 690 of lalr1.cc  */
#line 5365 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 771:

/* Line 690 of lalr1.cc  */
#line 5371 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 772:

/* Line 690 of lalr1.cc  */
#line 5375 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 773:

/* Line 690 of lalr1.cc  */
#line 5379 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 774:

/* Line 690 of lalr1.cc  */
#line 5385 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 775:

/* Line 690 of lalr1.cc  */
#line 5391 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 776:

/* Line 690 of lalr1.cc  */
#line 5395 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 777:

/* Line 690 of lalr1.cc  */
#line 5399 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 778:

/* Line 690 of lalr1.cc  */
#line 5403 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 779:

/* Line 690 of lalr1.cc  */
#line 5409 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 780:

/* Line 690 of lalr1.cc  */
#line 5417 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 781:

/* Line 690 of lalr1.cc  */
#line 5427 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 782:

/* Line 690 of lalr1.cc  */
#line 5431 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 783:

/* Line 690 of lalr1.cc  */
#line 5437 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 784:

/* Line 690 of lalr1.cc  */
#line 5443 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 785:

/* Line 690 of lalr1.cc  */
#line 5447 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 786:

/* Line 690 of lalr1.cc  */
#line 5453 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 787:

/* Line 690 of lalr1.cc  */
#line 5457 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 788:

/* Line 690 of lalr1.cc  */
#line 5463 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 789:

/* Line 690 of lalr1.cc  */
#line 5467 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 790:

/* Line 690 of lalr1.cc  */
#line 5473 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 791:

/* Line 690 of lalr1.cc  */
#line 5480 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 792:

/* Line 690 of lalr1.cc  */
#line 5486 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 793:

/* Line 690 of lalr1.cc  */
#line 5495 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 794:

/* Line 690 of lalr1.cc  */
#line 5501 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (3)].node));
          (yyval.expr) = new JSONObjectInsertExpr(
              LOC((yyloc)),
              new JSONDirectObjectConstructor(
                  LOC((yyloc)),
                  jpl),
              (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 795:

/* Line 690 of lalr1.cc  */
#line 5511 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 796:

/* Line 690 of lalr1.cc  */
#line 5517 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 797:

/* Line 690 of lalr1.cc  */
#line 5523 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
          rchandle<exprnode> lTargetExpr;
          rchandle<exprnode> lSelectorExpr;
          string lError;
          if (!convert_postfix_to_target_and_selector((yysemantic_stack_[(3) - (3)].expr), &lTargetExpr, &lSelectorExpr, &lError))
          {
            error((yylocation_stack_[(3) - (2)]), lError);
            YYERROR;
          }
          (yyval.expr) = new JSONDeleteExpr(
              LOC((yyloc)),
              lTargetExpr,
              lSelectorExpr);
        }
    break;

  case 798:

/* Line 690 of lalr1.cc  */
#line 5540 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
          rchandle<exprnode> lTargetExpr;
          rchandle<exprnode> lSelectorExpr;
          string lError;
          if (!convert_postfix_to_target_and_selector(
              (yysemantic_stack_[(5) - (3)].expr),
              &lTargetExpr,
              &lSelectorExpr,
              &lError,
              false))
          {
            error((yylocation_stack_[(5) - (3)]), lError);
            delete (yysemantic_stack_[(5) - (5)].expr);
            YYERROR;
          }
          (yyval.expr) = new JSONRenameExpr(
                LOC((yyloc)),
                lTargetExpr,
                lSelectorExpr,
                (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 799:

/* Line 690 of lalr1.cc  */
#line 5564 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
          rchandle<exprnode> lTargetExpr;
          rchandle<exprnode> lSelectorExpr;
          string lError;
          if (!convert_postfix_to_target_and_selector((yysemantic_stack_[(7) - (5)].expr), &lTargetExpr, &lSelectorExpr, &lError))
          {
            error((yylocation_stack_[(7) - (5)]), lError);
            delete (yysemantic_stack_[(7) - (7)].expr);
            YYERROR;
          }
          (yyval.expr) = new JSONReplaceExpr(
                LOC((yyloc)),
                lTargetExpr,
                lSelectorExpr,
                (yysemantic_stack_[(7) - (7)].expr));
        }
    break;

  case 800:

/* Line 690 of lalr1.cc  */
#line 5583 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 801:

/* Line 690 of lalr1.cc  */
#line 5587 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 802:

/* Line 690 of lalr1.cc  */
#line 5591 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 805:

/* Line 690 of lalr1.cc  */
#line 5600 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 806:

/* Line 690 of lalr1.cc  */
#line 5601 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 807:

/* Line 690 of lalr1.cc  */
#line 5602 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 808:

/* Line 690 of lalr1.cc  */
#line 5603 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 809:

/* Line 690 of lalr1.cc  */
#line 5604 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace-node"))); }
    break;

  case 810:

/* Line 690 of lalr1.cc  */
#line 5605 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 811:

/* Line 690 of lalr1.cc  */
#line 5606 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 812:

/* Line 690 of lalr1.cc  */
#line 5607 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 813:

/* Line 690 of lalr1.cc  */
#line 5608 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 814:

/* Line 690 of lalr1.cc  */
#line 5609 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 815:

/* Line 690 of lalr1.cc  */
#line 5610 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 816:

/* Line 690 of lalr1.cc  */
#line 5611 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 817:

/* Line 690 of lalr1.cc  */
#line 5612 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 818:

/* Line 690 of lalr1.cc  */
#line 5613 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 819:

/* Line 690 of lalr1.cc  */
#line 5614 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 820:

/* Line 690 of lalr1.cc  */
#line 5615 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 821:

/* Line 690 of lalr1.cc  */
#line 5616 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 822:

/* Line 690 of lalr1.cc  */
#line 5617 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 823:

/* Line 690 of lalr1.cc  */
#line 5618 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 824:

/* Line 690 of lalr1.cc  */
#line 5619 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 825:

/* Line 690 of lalr1.cc  */
#line 5620 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json-item"))); }
    break;

  case 826:

/* Line 690 of lalr1.cc  */
#line 5621 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 828:

/* Line 690 of lalr1.cc  */
#line 5625 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 829:

/* Line 690 of lalr1.cc  */
#line 5626 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 830:

/* Line 690 of lalr1.cc  */
#line 5627 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 831:

/* Line 690 of lalr1.cc  */
#line 5628 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 832:

/* Line 690 of lalr1.cc  */
#line 5629 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 833:

/* Line 690 of lalr1.cc  */
#line 5630 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 834:

/* Line 690 of lalr1.cc  */
#line 5631 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 835:

/* Line 690 of lalr1.cc  */
#line 5632 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 836:

/* Line 690 of lalr1.cc  */
#line 5633 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 837:

/* Line 690 of lalr1.cc  */
#line 5634 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 838:

/* Line 690 of lalr1.cc  */
#line 5635 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 839:

/* Line 690 of lalr1.cc  */
#line 5636 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 840:

/* Line 690 of lalr1.cc  */
#line 5637 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 841:

/* Line 690 of lalr1.cc  */
#line 5638 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 842:

/* Line 690 of lalr1.cc  */
#line 5639 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 843:

/* Line 690 of lalr1.cc  */
#line 5640 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 844:

/* Line 690 of lalr1.cc  */
#line 5641 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 845:

/* Line 690 of lalr1.cc  */
#line 5642 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 846:

/* Line 690 of lalr1.cc  */
#line 5643 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 847:

/* Line 690 of lalr1.cc  */
#line 5644 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 848:

/* Line 690 of lalr1.cc  */
#line 5645 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 849:

/* Line 690 of lalr1.cc  */
#line 5646 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 850:

/* Line 690 of lalr1.cc  */
#line 5647 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 851:

/* Line 690 of lalr1.cc  */
#line 5648 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 852:

/* Line 690 of lalr1.cc  */
#line 5649 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 853:

/* Line 690 of lalr1.cc  */
#line 5650 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 854:

/* Line 690 of lalr1.cc  */
#line 5651 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 855:

/* Line 690 of lalr1.cc  */
#line 5652 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 856:

/* Line 690 of lalr1.cc  */
#line 5653 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 857:

/* Line 690 of lalr1.cc  */
#line 5654 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 858:

/* Line 690 of lalr1.cc  */
#line 5655 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 859:

/* Line 690 of lalr1.cc  */
#line 5656 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 860:

/* Line 690 of lalr1.cc  */
#line 5657 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 861:

/* Line 690 of lalr1.cc  */
#line 5658 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 862:

/* Line 690 of lalr1.cc  */
#line 5659 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 863:

/* Line 690 of lalr1.cc  */
#line 5660 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 864:

/* Line 690 of lalr1.cc  */
#line 5661 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 865:

/* Line 690 of lalr1.cc  */
#line 5662 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 866:

/* Line 690 of lalr1.cc  */
#line 5663 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 867:

/* Line 690 of lalr1.cc  */
#line 5664 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 868:

/* Line 690 of lalr1.cc  */
#line 5665 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 869:

/* Line 690 of lalr1.cc  */
#line 5666 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 870:

/* Line 690 of lalr1.cc  */
#line 5667 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 871:

/* Line 690 of lalr1.cc  */
#line 5668 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 872:

/* Line 690 of lalr1.cc  */
#line 5669 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 873:

/* Line 690 of lalr1.cc  */
#line 5670 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 874:

/* Line 690 of lalr1.cc  */
#line 5671 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 875:

/* Line 690 of lalr1.cc  */
#line 5672 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 876:

/* Line 690 of lalr1.cc  */
#line 5673 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 877:

/* Line 690 of lalr1.cc  */
#line 5674 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 878:

/* Line 690 of lalr1.cc  */
#line 5675 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 879:

/* Line 690 of lalr1.cc  */
#line 5676 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 880:

/* Line 690 of lalr1.cc  */
#line 5677 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 881:

/* Line 690 of lalr1.cc  */
#line 5678 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 882:

/* Line 690 of lalr1.cc  */
#line 5679 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 883:

/* Line 690 of lalr1.cc  */
#line 5680 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 884:

/* Line 690 of lalr1.cc  */
#line 5681 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 885:

/* Line 690 of lalr1.cc  */
#line 5682 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 886:

/* Line 690 of lalr1.cc  */
#line 5683 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 887:

/* Line 690 of lalr1.cc  */
#line 5684 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 888:

/* Line 690 of lalr1.cc  */
#line 5685 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 889:

/* Line 690 of lalr1.cc  */
#line 5686 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 890:

/* Line 690 of lalr1.cc  */
#line 5687 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 891:

/* Line 690 of lalr1.cc  */
#line 5688 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 892:

/* Line 690 of lalr1.cc  */
#line 5689 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 893:

/* Line 690 of lalr1.cc  */
#line 5690 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 894:

/* Line 690 of lalr1.cc  */
#line 5691 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 895:

/* Line 690 of lalr1.cc  */
#line 5692 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 896:

/* Line 690 of lalr1.cc  */
#line 5693 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 897:

/* Line 690 of lalr1.cc  */
#line 5694 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 898:

/* Line 690 of lalr1.cc  */
#line 5695 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 899:

/* Line 690 of lalr1.cc  */
#line 5696 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 900:

/* Line 690 of lalr1.cc  */
#line 5697 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 901:

/* Line 690 of lalr1.cc  */
#line 5698 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 902:

/* Line 690 of lalr1.cc  */
#line 5699 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 903:

/* Line 690 of lalr1.cc  */
#line 5700 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 904:

/* Line 690 of lalr1.cc  */
#line 5701 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 905:

/* Line 690 of lalr1.cc  */
#line 5702 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 906:

/* Line 690 of lalr1.cc  */
#line 5703 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 907:

/* Line 690 of lalr1.cc  */
#line 5704 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 908:

/* Line 690 of lalr1.cc  */
#line 5705 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 909:

/* Line 690 of lalr1.cc  */
#line 5706 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 910:

/* Line 690 of lalr1.cc  */
#line 5707 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 911:

/* Line 690 of lalr1.cc  */
#line 5708 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 912:

/* Line 690 of lalr1.cc  */
#line 5709 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 913:

/* Line 690 of lalr1.cc  */
#line 5710 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 914:

/* Line 690 of lalr1.cc  */
#line 5711 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 915:

/* Line 690 of lalr1.cc  */
#line 5712 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 916:

/* Line 690 of lalr1.cc  */
#line 5713 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 917:

/* Line 690 of lalr1.cc  */
#line 5714 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 918:

/* Line 690 of lalr1.cc  */
#line 5715 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 919:

/* Line 690 of lalr1.cc  */
#line 5716 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 920:

/* Line 690 of lalr1.cc  */
#line 5717 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 921:

/* Line 690 of lalr1.cc  */
#line 5718 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 922:

/* Line 690 of lalr1.cc  */
#line 5719 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 923:

/* Line 690 of lalr1.cc  */
#line 5720 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 924:

/* Line 690 of lalr1.cc  */
#line 5721 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 925:

/* Line 690 of lalr1.cc  */
#line 5722 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 926:

/* Line 690 of lalr1.cc  */
#line 5723 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 927:

/* Line 690 of lalr1.cc  */
#line 5724 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 928:

/* Line 690 of lalr1.cc  */
#line 5725 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 929:

/* Line 690 of lalr1.cc  */
#line 5726 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 930:

/* Line 690 of lalr1.cc  */
#line 5727 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 931:

/* Line 690 of lalr1.cc  */
#line 5728 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 932:

/* Line 690 of lalr1.cc  */
#line 5729 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 933:

/* Line 690 of lalr1.cc  */
#line 5730 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 934:

/* Line 690 of lalr1.cc  */
#line 5731 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 935:

/* Line 690 of lalr1.cc  */
#line 5732 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 936:

/* Line 690 of lalr1.cc  */
#line 5733 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 937:

/* Line 690 of lalr1.cc  */
#line 5734 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 938:

/* Line 690 of lalr1.cc  */
#line 5735 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 939:

/* Line 690 of lalr1.cc  */
#line 5736 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 940:

/* Line 690 of lalr1.cc  */
#line 5737 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 941:

/* Line 690 of lalr1.cc  */
#line 5738 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 942:

/* Line 690 of lalr1.cc  */
#line 5739 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 943:

/* Line 690 of lalr1.cc  */
#line 5740 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 944:

/* Line 690 of lalr1.cc  */
#line 5741 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 945:

/* Line 690 of lalr1.cc  */
#line 5742 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 946:

/* Line 690 of lalr1.cc  */
#line 5743 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 947:

/* Line 690 of lalr1.cc  */
#line 5744 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 948:

/* Line 690 of lalr1.cc  */
#line 5745 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 949:

/* Line 690 of lalr1.cc  */
#line 5746 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 950:

/* Line 690 of lalr1.cc  */
#line 5747 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 951:

/* Line 690 of lalr1.cc  */
#line 5748 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 952:

/* Line 690 of lalr1.cc  */
#line 5749 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 953:

/* Line 690 of lalr1.cc  */
#line 5750 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 954:

/* Line 690 of lalr1.cc  */
#line 5751 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 955:

/* Line 690 of lalr1.cc  */
#line 5752 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 956:

/* Line 690 of lalr1.cc  */
#line 5753 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 957:

/* Line 690 of lalr1.cc  */
#line 5754 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 958:

/* Line 690 of lalr1.cc  */
#line 5755 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 959:

/* Line 690 of lalr1.cc  */
#line 5756 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 960:

/* Line 690 of lalr1.cc  */
#line 5757 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 961:

/* Line 690 of lalr1.cc  */
#line 5758 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 962:

/* Line 690 of lalr1.cc  */
#line 5759 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 963:

/* Line 690 of lalr1.cc  */
#line 5760 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 964:

/* Line 690 of lalr1.cc  */
#line 5761 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 965:

/* Line 690 of lalr1.cc  */
#line 5762 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 966:

/* Line 690 of lalr1.cc  */
#line 5763 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 967:

/* Line 690 of lalr1.cc  */
#line 5764 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 968:

/* Line 690 of lalr1.cc  */
#line 5765 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 969:

/* Line 690 of lalr1.cc  */
#line 5766 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 970:

/* Line 690 of lalr1.cc  */
#line 5767 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 971:

/* Line 690 of lalr1.cc  */
#line 5768 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 972:

/* Line 690 of lalr1.cc  */
#line 5769 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 973:

/* Line 690 of lalr1.cc  */
#line 5770 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 974:

/* Line 690 of lalr1.cc  */
#line 5771 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 975:

/* Line 690 of lalr1.cc  */
#line 5772 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 976:

/* Line 690 of lalr1.cc  */
#line 5773 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 977:

/* Line 690 of lalr1.cc  */
#line 5774 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 978:

/* Line 690 of lalr1.cc  */
#line 5775 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 979:

/* Line 690 of lalr1.cc  */
#line 5776 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 980:

/* Line 690 of lalr1.cc  */
#line 5777 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 981:

/* Line 690 of lalr1.cc  */
#line 5778 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 982:

/* Line 690 of lalr1.cc  */
#line 5779 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 983:

/* Line 690 of lalr1.cc  */
#line 5780 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 984:

/* Line 690 of lalr1.cc  */
#line 5781 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 985:

/* Line 690 of lalr1.cc  */
#line 5782 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 986:

/* Line 690 of lalr1.cc  */
#line 5783 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 987:

/* Line 690 of lalr1.cc  */
#line 5784 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 988:

/* Line 690 of lalr1.cc  */
#line 5785 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 989:

/* Line 690 of lalr1.cc  */
#line 5786 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 990:

/* Line 690 of lalr1.cc  */
#line 5787 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 991:

/* Line 690 of lalr1.cc  */
#line 5788 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 992:

/* Line 690 of lalr1.cc  */
#line 5789 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 993:

/* Line 690 of lalr1.cc  */
#line 5790 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 994:

/* Line 690 of lalr1.cc  */
#line 5791 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 995:

/* Line 690 of lalr1.cc  */
#line 5792 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 996:

/* Line 690 of lalr1.cc  */
#line 5793 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 997:

/* Line 690 of lalr1.cc  */
#line 5794 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 998:

/* Line 690 of lalr1.cc  */
#line 5795 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 999:

/* Line 690 of lalr1.cc  */
#line 5796 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 1000:

/* Line 690 of lalr1.cc  */
#line 5797 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 1001:

/* Line 690 of lalr1.cc  */
#line 5798 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 1002:

/* Line 690 of lalr1.cc  */
#line 5799 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 1003:

/* Line 690 of lalr1.cc  */
#line 5800 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 1004:

/* Line 690 of lalr1.cc  */
#line 5801 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 1005:

/* Line 690 of lalr1.cc  */
#line 5802 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 1006:

/* Line 690 of lalr1.cc  */
#line 5803 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 1007:

/* Line 690 of lalr1.cc  */
#line 5804 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 1008:

/* Line 690 of lalr1.cc  */
#line 5805 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 1009:

/* Line 690 of lalr1.cc  */
#line 5806 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 1010:

/* Line 690 of lalr1.cc  */
#line 5807 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 1011:

/* Line 690 of lalr1.cc  */
#line 5808 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 1012:

/* Line 690 of lalr1.cc  */
#line 5809 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 1013:

/* Line 690 of lalr1.cc  */
#line 5810 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 1014:

/* Line 690 of lalr1.cc  */
#line 5811 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 1015:

/* Line 690 of lalr1.cc  */
#line 5812 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 1016:

/* Line 690 of lalr1.cc  */
#line 5813 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 1017:

/* Line 690 of lalr1.cc  */
#line 5814 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 1018:

/* Line 690 of lalr1.cc  */
#line 5815 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 1019:

/* Line 690 of lalr1.cc  */
#line 5816 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 1020:

/* Line 690 of lalr1.cc  */
#line 5817 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 1021:

/* Line 690 of lalr1.cc  */
#line 5818 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 1022:

/* Line 690 of lalr1.cc  */
#line 5819 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 1023:

/* Line 690 of lalr1.cc  */
#line 5820 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1024:

/* Line 690 of lalr1.cc  */
#line 5821 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1025:

/* Line 690 of lalr1.cc  */
#line 5822 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1026:

/* Line 690 of lalr1.cc  */
#line 5823 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1027:

/* Line 690 of lalr1.cc  */
#line 5824 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1028:

/* Line 690 of lalr1.cc  */
#line 5827 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 690 of lalr1.cc  */
#line 12118 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"
	default:
          break;
      }
    /* User semantic actions sometimes alter yychar, and that requires
       that yytoken be updated with the new translation.  We take the
       approach of translating immediately before every use of yytoken.
       One alternative is translating here after every semantic action,
       but that translation would be missed if the semantic action
       invokes YYABORT, YYACCEPT, or YYERROR immediately after altering
       yychar.  In the case of YYABORT or YYACCEPT, an incorrect
       destructor might then be invoked immediately.  In the case of
       YYERROR, subsequent parser actions might lead to an incorrect
       destructor call or verbose syntax error message before the
       lookahead is translated.  */
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* Make sure we have latest lookahead translation.  See comments at
       user semantic actions for why this is necessary.  */
    yytoken = yytranslate_ (yychar);

    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	if (yychar == yyempty_)
	  yytoken = yyempty_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[1] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
	  }
      }

    /* Else will try to reuse lookahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[1] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (!yy_pact_value_is_default_ (yyn))
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[1] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[2] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      {
        /* Make sure we have latest lookahead translation.  See comments
           at user semantic actions for why this is necessary.  */
        yytoken = yytranslate_ (yychar);
        yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval,
                     &yylloc);
      }

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  xquery_parser::yysyntax_error_ (int yystate, int yytoken)
  {
    std::string yyres;
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yytoken) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yychar.
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (yytoken != yyempty_)
      {
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            /* Stay within bounds of both yycheck and yytname.  */
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = 0;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const short int xquery_parser::yypact_ninf_ = -1425;
  const short int
  xquery_parser::yypact_[] =
  {
      4693, -1425, -1425, -1425, -1425,  6247,  6247,  6247,  6247, -1425,
   -1425,   197,   260, -1425,  1422,    58, -1425, -1425, -1425,   806,
   -1425, -1425, -1425,   292,   360,   810,  4411,   529,   644,   850,
   -1425,    78, -1425,   691, -1425, -1425, -1425, -1425, -1425,   814,
   -1425,   695,   737, -1425, -1425, -1425, -1425,   372, -1425,   815,
   -1425,   780,   832, -1425,   427, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,   533,
     660, -1425, -1425, -1425, -1425,   690, 12447, -1425, -1425, -1425,
     853, -1425, -1425, -1425,   863, -1425,   869,   871, -1425, -1425,
   16318, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,   879,
   -1425, -1425,   877,   887, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425,  5317,  8727,  9037, 16318, -1425, -1425,   860, -1425, -1425,
   -1425, -1425,   865, -1425, -1425,   899, 16318, -1425, 13358,   901,
     902, -1425, -1425, -1425,   903, -1425, -1425, 11827, -1425, -1425,
   -1425, -1425, -1425, -1425,   876, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425,    77,   811, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425,   -72,   875,   -51, -1425,  -101,   390, -1425,
   -1425, -1425, -1425, -1425, -1425,   915, -1425,   792,   794,   795,
   -1425, -1425,   882,   889, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425,  9347,  9657, -1425,
     727, -1425, -1425, -1425, -1425, -1425,  5005,  6557,  1044, -1425,
    6867, -1425, -1425,   332,    76, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,    95,
   -1425, -1425, -1425, -1425, -1425, -1425,   482, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425,  6247, -1425, -1425, -1425, -1425,
     351, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
     180, -1425,   866, -1425, -1425, -1425,   675, -1425,   532, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425,   890,   966, -1425,   950,
     813,   960,   713,   588,   632,    36, -1425,  1013,   864,   963,
     964, 10277, -1425,   878, -1425, -1425,   528, -1425, -1425, 12137,
   -1425,   755, -1425,   911, 12447, -1425,   911, 12447, -1425, -1425,
   -1425,   801, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,   912,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425,   785, -1425, -1425,
   -1425, -1425, -1425,   884, -1425,  6247,   888,   891,   894,  6247,
     548,   548,  1043,   717,   747,   480, 16906, 16318,   609,  1032,
   16318,   927,   962,   640, 16318,   763,   836, 16318, 16318,   786,
     507,    82, -1425, -1425, -1425, 16318,  6247,   897,  6247,   140,
   10587, 13654, 16318,   -19,   933, 10587,  1087,   182,   135, 16318,
     974,   953,   989, -1425,   913, 10587, 13950, 16318, 16318, 16318,
    6247,   916, 10587, 10587, 16318,  6247,   944,   945, -1425, -1425,
   -1425, 10587, 14246,   947, -1425,   952, -1425, -1425, -1425, -1425,
     954, -1425,   955, -1425, -1425, -1425, -1425, -1425,   957, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, 16318, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425,   958, 16318, -1425, -1425, -1425,   923,  5627,   988,   303,
     961,   967,   969, 16318,  6247, -1425,   968,   234, -1425,   675,
   -1425,   131,  1084, 10587, 10587, -1425,   112, -1425, -1425,  1103,
   -1425, -1425, -1425, -1425, 10587,   909, -1425,  1097, 10587, 10587,
   16618, 10587, 10587, 10587, 10587, 16618, 10587,   904, 16318,   938,
     940, 10587, 10587,  5317,   892, -1425,    67, -1425,    54, 10587,
    6557, -1425, -1425, -1425, -1425, -1425,  1422,   850,   102,   104,
    1131,  7177,  3149,  7487,  3470,   863, -1425, -1425,   204,   863,
   -1425, 10587,  4090, -1425,  1017,   757,    78,   970,   971,   972,
   -1425, 10587, -1425, -1425,  6247, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425,   855,   856, 16318,  1024, 10897, 10897, 10897, -1425,
   10897, 10897, -1425, 10897, -1425, 10897, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, 10897, 10897,  1073, 10897, 10897, 10897, 10897,
   10897, 10897, 10897, 10897, 10897, 10897, 10897, 10897,   920,  1050,
    1051,  1052, -1425, -1425, -1425, 11517,  6247, -1425, -1425, 11827,
   11827, 10587,   911, -1425, -1425,   911, -1425,  8107,   911,   976,
    1002,  8417, -1425, -1425, -1425, -1425,   369, -1425,   381, -1425,
   -1425, -1425, -1425, -1425, -1425,  1053,  1056,   529,  1129, -1425,
   -1425, 16906,   965,   694, 16318,  1004,  1005,   965,  1043,  1039,
    1035, -1425, -1425, -1425,   188,   924,  1074,   883, 16318,  1029,
   10587,  1055, 16318, 16318, -1425,  1042,   994, -1425,   997,   952,
     737, -1425,   998,  1000,   215, -1425,   419,   443,  1076, -1425,
      46, 16318,  1093,   478, -1425,  6247, -1425,   150, -1425, 16318,
    1092,  1145, 16318,  1043,  1094,   697, 16318, 10587,    78, -1425,
     334,  1006, -1425,  1007,  1009,  1010,   250, -1425,   621,  1008,
   -1425,   151,   162,  1045, -1425,  1014,  6247,  6247,   335, -1425,
     493,   505,   702, 10587,   263, -1425, -1425, 10587, 10587, -1425,
   10587, 10587, 10587, -1425, 10587, -1425, 10587, -1425, 16318,  1084,
   -1425,   458,   339,   374, -1425, -1425, -1425,   386, -1425,   479,
   -1425, -1425,  1046,  1047,  1048,  1049,  1054,   801,   785,   230,
     287,   274,    13,  1109,   517,   973,  -100,    27, -1425,  1062,
   -1425, -1425,  1016,   169,  5627,   432, 12757,   892, -1425, -1425,
   -1425,   978, -1425,   332,   825,  1174,   166, -1425, -1425,   117,
   -1425, -1425, -1425,   125, -1425,    65, -1425, -1425, -1425, -1425,
   -1425,  3780, -1425, -1425, -1425, 16318,  1057, 10587, 11207, -1425,
   -1425, -1425, -1425, -1425,  1076, 16318,    63,   966, -1425, -1425,
   -1425, -1425, -1425, 10897, -1425, -1425, -1425,    71, -1425,   588,
     588,    10,   632,   632,   632,   632,    36,    36, -1425, -1425,
   15430, 15430, 16318, 16318, -1425,  1028, -1425, -1425,   237, -1425,
   -1425, -1425, -1425,   544, -1425, -1425, -1425,   549,   548, -1425,
   -1425,   602,   606,   543, -1425,   529, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425,   965, -1425,  1080, 15726,
    1071, 10587, -1425, -1425, -1425,  1120,  1043,  1043,   965, -1425,
     867,  1043,   696, 16318,   676,   678,  1186, -1425, -1425,   931,
      52, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425,   188,    44,   991,   646, 10587, -1425, 16318,  1125,
     922,  1043, -1425, -1425, -1425, -1425,  1068, 16318, -1425, 16318,
   -1425, 16022,  1095, 15430,  1105, 10587,   -20,  1077,    59,  1120,
   15430,  1107,  1133,  1058,  1031,  1098,  1043,  1069,  1099,  1136,
    1043, 10587,    80, -1425, -1425, -1425,  1081, -1425, -1425, -1425,
   -1425,  1115, 10587, 10587,  1088, -1425,  1137,  1138,  6247, -1425,
    1059,  1060,  1086, 16318, -1425, 16318, -1425, 10587,  1102,  1061,
   10587, -1425,  1124,   192,   221,   223,  1212, -1425,   474, -1425,
     107,  1096, -1425, -1425,  1222, -1425,   756, 10587, 10587, 10587,
     759, 10587, 10587, 10587, 10587, 10587, 10587, 10587, 10587, 10587,
   16618,  1135, 10587, 10587, -1425,  7797,   129,  1011, -1425,   499,
   -1425, 10587,   136,   189,    65,  7487,  3470,  7487,  1175, -1425,
   -1425, 10587,   797,  1149, -1425, 16318,  1151,  1152, -1425,   682,
    1012, -1425, -1425,   731,    63, -1425, 10587,    71,   738,   589,
   -1425,   977,   293,  1001,  1003, -1425, -1425,   836, -1425,  1015,
     638,  1111,  1112, 15726,  1113,  1114,  1117,  1118,  1121, -1425,
      14, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425,  1119, -1425, -1425, -1425, -1425,  9967, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425,   700, -1425,  1249,   643,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,   995,
   -1425, -1425,  1250, -1425, -1425, -1425, -1425, -1425,   642,  1255,
   -1425,   784, -1425, -1425, -1425,   947,   360,   691,   954,   695,
     955,   957, -1425,  1114,  1117,  1118, -1425,    14,    14, 11517,
     999,   983, -1425,  1120,    44,  1063,  1104,  6247,  1106,  1110,
    1147,  1122,  1126, 16318, -1425,   382, -1425, 16318, -1425, 10587,
    1148, 10587,  1170, 10587,    86,  1153, -1425, -1425, -1425, 15430,
   -1425,  6247,  1043,  1191, -1425, -1425, -1425,  1043,  1191, -1425,
   10587,  1159,  6247, 16318, -1425, -1425, 10587, 10587,   449, -1425,
     343,   796, -1425, 14542,   819, -1425,   820, -1425,  1128, -1425,
   -1425,  6247,  1127,  1130, -1425, 10587, -1425, -1425, 10587,  1108,
    1137,  1203, -1425,  1172, -1425,   575, -1425, -1425,  1301, -1425,
   -1425,  6247, 16318, -1425,   599, -1425, -1425, -1425,  6247,  1132,
    1083,  1100, -1425, -1425, -1425,  1116,  1134, -1425, -1425, -1425,
    1223, -1425, -1425, -1425, -1425,  1089,   338, 16318,  1139, -1425,
    1164,  1178,  1179,  1177, -1425,   866,   675, 12757,  1011, -1425,
    5937, 12757, -1425, -1425,  1174,   348, -1425, -1425, -1425,  1149,
   -1425,  1043, -1425,   873, -1425,   688,  1225, -1425, 10587,   722,
    1043, -1425, 11207, 10587,  1181, -1425,  1218,  1219, 10587, 16318,
     847,  1262, -1425, -1425, -1425,   434,  1154, -1425,    71,  1123,
   -1425, -1425,   -53, -1425,   641,   340,  1144,    71,   641, 10897,
   -1425,   307, -1425, -1425, -1425, -1425, -1425, -1425,    71,  1194,
    1065,   924,   340, -1425, -1425,  1066,  1264, -1425, -1425, -1425,
   13053,  1157,  1158,  1161,  1166,  1168,  1173,  1176, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425,  1327,    17,  1329,    17,  1101,  1256, -1425, -1425,  1195,
   16318,  1140, -1425, -1425, 11517, -1425,  1184, -1425, -1425, -1425,
   -1425, -1425, -1425, 10587,  1226, -1425, -1425, 10587, -1425,   662,
   -1425, 10587,  1229, 10587, -1425,  1243,  1244,  1282,  1043,  1191,
   -1425, 10587,  1196, -1425, -1425, -1425,  1139, -1425,   343, 10587,
    6247,  1139,   343, -1425, 16318,   -26, -1425, 14838,    29, -1425,
   15134,  1139, -1425, -1425,  1197, -1425, -1425, -1425, -1425, 10587,
     834,  1212, 16318,   626, -1425,  1198,  1212, 16318, -1425,  1200,
   -1425, 10587, 10587, 10587, 10587,  1072, 10587, 10587, -1425, 10587,
   10587, 10587, 10587,  7797,   586, -1425, -1425, -1425, -1425, -1425,
    1225, -1425, -1425, -1425, 10587,  1242, -1425, -1425, -1425, 10587,
   16318, 16318, -1425,   739, -1425, 10587, -1425, -1425, -1425,  1205,
   10897, -1425, -1425, -1425, -1425, -1425,    62, 10897, 10897,   584,
   -1425,  1001, -1425,   407, -1425,  1003,    71,  1233, -1425, -1425,
    1142, -1425, -1425, -1425, -1425,  1300,  1209, -1425,   550, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425,   520,   520, -1425,
      17, -1425, -1425,   555, -1425,  1370,   340,  1304,  1215, 11517,
     -25,  1141,  1234, -1425, -1425, 10587, -1425, 10587,  1257, -1425,
   10587, -1425,  7797, 10587,  1043, -1425, -1425, -1425, 10587, 10587,
   -1425, -1425, -1425,  7797,  7797,  1308, 15430,  6247, 16318,   -26,
   16318, 10587, 16318,   -26,  7797, -1425,    31,   298,  1212, 16318,
   -1425,  1210,  1212, -1425, -1425, -1425, -1425, -1425, 10587, -1425,
   -1425, -1425,   231,   239,   249, 10587, -1425, -1425,  1151, 10587,
   -1425, -1425,  1354, -1425, -1425, -1425,   632, 10897, 10897,    10,
     724, -1425, -1425, -1425, -1425, -1425, -1425, 10587, -1425, 15430,
   -1425, 15430,  1314, -1425, -1425, -1425,  1383, -1425, -1425, -1425,
    1150,  1309, -1425, -1425,  1310, -1425,   783, 16318,  1297,  1199,
   16318, 11517, -1425, -1425, 10587, -1425, -1425, -1425,  1191, -1425,
   -1425, 15430, -1425, -1425, -1425,  1324, 10587,  1139, -1425,  1325,
    7797, -1425, 16318,   448,   540, -1425,  1228,  1212, -1425,  1230,
   -1425,  1231,  1137,  1138,   459, -1425,  1151,  1307,    10,    10,
   10897,   463, -1425, -1425, 15430, -1425, -1425,  1304, 11517, -1425,
    1225,  1156, 16318,  1312,  1207,  1310, -1425,   -26, 15430,  6247,
   15430,  1139, -1425, -1425,  1340,   620, -1425, -1425, -1425, -1425,
    1240,   578, -1425, -1425, -1425,  1238, -1425,  7797,   835, -1425,
   -1425, 16318,    10, -1425, -1425, -1425, -1425, -1425, 10587,  1160,
   16318,  1318,  6247,   -26, -1425, -1425,   -26, 10587, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425,  1319, -1425, -1425,  1146,  1162,
   16318, -1425, -1425, 10587,  7797, 16318,  1169, 10587,  1183,  1139,
   11517, -1425, 11517,  7797, -1425,  1241,  1155, 16318,  1216,  1326,
   16318,  1187, 11517, -1425
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       165,   469,   470,   805,   471,   168,   168,   168,     0,   828,
    1028,   120,   122,   636,   921,   930,   870,   833,   831,   807,
     922,   925,   877,   837,   808,   810,     0,   931,   812,   928,
     899,   879,   853,   809,   874,   875,   926,   923,   873,   814,
     929,   815,   816,   970,   982,   969,   871,   890,   884,   817,
     872,   819,   818,   971,   908,   909,   876,   850,   992,   993,
     994,   995,   996,   997,   998,   999,  1000,  1001,  1002,  1016,
    1023,   898,   894,   885,   864,   806,     0,   893,   901,   910,
    1017,   889,   495,   865,   866,   924,  1018,  1024,   886,   903,
       0,   501,   458,   497,   896,   830,   887,   888,   917,   891,
     907,   916,  1022,  1025,   836,   878,   919,   496,   906,   912,
     811,     0,     0,     0,     0,   405,   904,   915,   920,   918,
     897,   883,   972,   881,   882,  1019,     0,   404,     0,  1020,
    1026,   913,   867,   892,  1021,   212,   436,     0,   468,   914,
     895,   902,   911,   905,   973,   858,   863,   862,   861,   860,
     859,   820,   880,     0,   829,   927,   851,   963,   962,   964,
     835,   834,   854,   961,   813,   958,   966,   960,   959,   857,
     900,   956,   968,   967,   955,   855,   965,   977,   978,   975,
     976,   974,   821,   979,   980,   981,   947,   946,   933,   849,
     842,   940,   936,   852,   848,   948,   869,   838,   839,   832,
     841,   945,   944,   941,   937,   953,   954,   952,   943,   939,
     932,   840,   951,   950,   844,   846,   845,   938,   942,   934,
     847,   935,   843,   949,  1003,  1004,  1005,  1006,  1007,  1008,
     984,   985,   983,   989,   990,   991,   986,   987,   988,   856,
    1009,  1010,  1011,  1012,  1013,  1014,  1015,     0,     0,   822,
     957,  1027,   824,   823,   825,   826,   165,   165,     0,     2,
     165,     9,    11,    23,     0,    28,    31,    36,    37,    38,
      39,    40,    41,    42,    32,    58,    59,    33,    34,     0,
      76,    79,    80,    35,    81,    82,     0,   118,    83,    84,
      85,    86,    18,   162,   163,   164,   171,   174,   488,   175,
       0,   176,   177,   178,   179,   180,   181,   182,   185,   186,
       0,   213,   221,   216,   249,   255,     0,   247,     0,   248,
     223,   217,   184,   218,   183,   219,   222,   356,   358,   360,
     370,   372,   376,   378,   381,   386,   389,   392,   394,   396,
     398,     0,   402,   409,   408,   410,     0,   427,   411,   432,
     435,   437,   440,   442,     0,   447,   444,     0,   455,   465,
     467,   441,   472,   479,   493,   480,   481,   482,   485,   486,
     483,   487,   510,   511,   484,   514,   516,   517,   518,   515,
     563,   564,   565,   566,   567,   568,   569,   464,   608,     0,
     599,   607,   606,   605,   604,   601,   603,   600,   602,   494,
      43,   224,   225,   227,   226,   228,   220,   490,   491,   492,
     489,   230,   233,   229,   231,   232,   466,   804,   827,   921,
     930,   928,   829,     0,   166,   167,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   126,   128,   129,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   278,   279,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   460,   463,
     450,     0,     0,   807,   837,   810,   868,   931,   812,   879,
     814,   890,   817,   819,   818,   908,  1016,  1023,   806,  1017,
     866,  1018,  1024,   891,  1022,  1025,   915,   972,  1019,  1020,
    1026,  1021,   973,   961,   958,   960,   959,   855,   977,   978,
     975,   821,   979,   957,   456,   804,   448,     0,   193,   449,
     452,   807,   808,   810,   809,   814,   815,   816,   817,   806,
     813,   498,     0,   454,   453,   188,     0,     0,   213,     0,
     812,   819,   818,     0,   168,   784,   979,     0,   221,     0,
     499,     0,   530,     0,     0,   459,     0,   430,   431,     0,
     462,   461,   451,   434,     0,     0,   559,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   786,     0,   788,     0,     0,
     165,     3,     4,     1,    10,    12,     0,     0,     0,     0,
       6,   165,     0,   165,     0,     0,   119,   172,     0,     0,
     191,     0,     0,   200,     0,     0,     0,     0,     0,     0,
     236,     0,   205,   234,     0,   254,   250,   256,   251,   253,
     252,   259,     0,     0,     0,     0,     0,     0,     0,   421,
       0,     0,   419,     0,   365,     0,   420,   413,   418,   417,
     416,   415,   414,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   407,   406,   403,     0,   168,   428,   433,     0,
       0,     0,   443,   476,   446,   445,   457,     0,   473,     0,
       0,     0,   571,   573,   577,   579,     0,   124,     0,   803,
      47,    44,    45,    48,    49,     0,     0,     0,     0,    50,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   643,   644,   645,     0,   103,   142,     0,     0,   112,
       0,     0,     0,     0,   127,     0,     0,   616,     0,     0,
       0,   611,     0,     0,     0,   626,     0,     0,   258,   261,
       0,     0,   134,     0,   138,   168,   513,     0,    60,     0,
      69,     0,     0,     0,    61,     0,     0,     0,     0,   614,
       0,     0,   617,     0,     0,     0,     0,   327,     0,     0,
     615,     0,     0,     0,   634,     0,     0,     0,     0,   620,
       0,     0,   195,     0,     0,   189,   187,     0,     0,   790,
       0,     0,     0,   498,     0,   785,     0,   500,   531,   530,
     527,     0,     0,     0,   561,   560,   429,     0,   558,     0,
     656,   657,     0,     0,     0,     0,     0,   797,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   662,     0,
     203,   204,     0,     0,     0,     0,     0,   208,   209,   787,
     789,     0,     5,    24,     0,    25,     0,     7,    29,     0,
      15,     8,    30,     0,    19,   921,    77,    16,    78,    20,
     194,     0,   192,   214,   215,     0,     0,     0,     0,   296,
     206,   235,   237,   238,   257,     0,     0,   357,   359,   363,
     369,   368,   367,     0,   364,   361,   362,     0,   373,   380,
     379,   377,   383,   384,   385,   382,   387,   388,   391,   390,
       0,     0,     0,     0,   412,     0,   438,   439,     0,   477,
     506,   474,   508,     0,   609,   512,   504,     0,     0,   121,
     123,     0,     0,     0,   102,     0,    92,    94,    95,    96,
      97,    99,   100,   101,    93,    98,    88,    89,     0,     0,
     108,     0,   104,   106,   107,   114,     0,     0,    87,    46,
       0,     0,     0,     0,     0,     0,     0,   734,   739,     0,
       0,   735,   769,   722,   724,   725,   726,   728,   730,   729,
     727,   731,     0,     0,     0,     0,     0,   111,     0,   144,
       0,     0,   576,   570,   612,   613,     0,     0,   630,     0,
     627,     0,     0,     0,     0,     0,     0,     0,     0,   140,
       0,     0,   135,     0,     0,     0,     0,     0,     0,    62,
       0,     0,     0,   277,   283,   280,     0,   619,   618,   625,
     633,     0,     0,     0,     0,   575,     0,     0,     0,   422,
       0,     0,     0,     0,   623,     0,   621,     0,   196,     0,
       0,   791,     0,     0,     0,     0,   530,   528,     0,   519,
       0,     0,   502,   503,     0,    13,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   201,     0,     0,     0,   670,     0,
     210,     0,     0,     0,     0,   165,     0,   165,     0,   173,
     246,     0,   311,   307,   309,     0,   304,   297,   298,     0,
       0,   239,   240,     0,   245,   366,     0,     0,     0,     0,
     700,   374,   673,   677,   679,   681,   683,   686,   693,   694,
     702,   931,   811,     0,   820,   824,   823,   825,   826,   393,
     582,   588,   589,   592,   637,   638,   593,   594,   597,   395,
     397,   400,   598,   399,   426,   478,     0,   475,   505,   125,
      56,    57,    54,    55,   131,   130,     0,    90,     0,     0,
     109,   110,   115,    74,    75,    52,    53,    73,   740,     0,
     743,   770,     0,   733,   732,   737,   736,   768,     0,     0,
     745,     0,   741,   744,   723,     0,     0,     0,     0,     0,
       0,     0,   610,     0,     0,     0,   143,   146,   148,     0,
       0,     0,   113,   116,     0,     0,     0,   168,     0,     0,
     634,     0,     0,     0,   263,     0,   581,     0,   264,     0,
       0,     0,     0,     0,     0,     0,   141,   136,   139,     0,
     190,     0,     0,    71,    65,    68,    67,     0,    63,   281,
       0,     0,   168,     0,   325,   329,     0,     0,     0,   332,
       0,     0,   338,     0,     0,   345,     0,   349,     0,   424,
     423,   168,     0,     0,   197,     0,   199,   326,     0,     0,
       0,     0,   531,     0,   521,     0,   554,   551,     0,   555,
     556,     0,     0,   550,     0,   525,   553,   552,     0,     0,
       0,     0,   649,   650,   646,     0,     0,   654,   655,   651,
     793,   794,   660,   798,   658,     0,     0,     0,     0,   664,
     812,   819,   818,   979,   202,     0,     0,     0,   665,   666,
       0,     0,   211,   796,    26,     0,    17,    21,    22,   308,
     320,     0,   321,     0,   312,   313,   314,   315,     0,   498,
       0,   305,     0,     0,     0,   241,     0,     0,     0,     0,
     290,     0,   287,   292,   244,     0,     0,   684,   697,     0,
     371,   375,     0,   716,     0,     0,     0,     0,     0,     0,
     672,   674,   675,   711,   712,   713,   715,   714,     0,     0,
     688,   687,     0,   691,   695,   709,   707,   706,   699,   703,
       0,     0,     0,     0,     0,     0,     0,     0,   585,   587,
     586,   583,   401,   507,   509,   133,   132,    91,   105,   757,
     738,     0,   762,     0,   762,   751,   746,   147,   149,     0,
       0,     0,   117,   145,     0,    27,     0,   631,   632,   635,
     628,   629,   262,     0,     0,   276,   268,     0,   272,     0,
     266,     0,     0,     0,   137,     0,     0,    70,     0,    64,
     282,     0,     0,   328,   330,   335,     0,   333,     0,     0,
       0,     0,     0,   339,     0,     0,   353,     0,     0,   346,
       0,     0,   350,   425,     0,   624,   622,   198,   792,     0,
       0,   530,     0,     0,   562,     0,   530,     0,   526,     0,
      14,     0,     0,     0,     0,     0,     0,     0,   663,     0,
       0,     0,     0,     0,     0,   667,   671,   324,   322,   323,
     316,   317,   318,   310,     0,     0,   306,   299,   285,     0,
       0,     0,   243,   288,   291,     0,   701,   692,   698,     0,
       0,   771,   772,   782,   781,   780,     0,     0,     0,     0,
     773,   678,   779,     0,   676,   680,     0,     0,   685,   689,
       0,   710,   705,   708,   704,     0,     0,   595,     0,   590,
     642,   584,   802,   801,   800,   591,   758,     0,     0,   756,
     763,   764,   760,     0,   755,     0,   753,     0,     0,     0,
       0,     0,     0,   572,   265,     0,   274,     0,     0,   270,
       0,   273,     0,     0,     0,    66,   284,   578,     0,     0,
     336,   340,   334,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   574,     0,     0,   530,     0,
     557,     0,   530,   580,   647,   648,   652,   653,     0,   659,
     799,   661,     0,     0,     0,     0,   668,   319,   300,     0,
     286,   294,   295,   289,   242,   696,   783,     0,     0,   775,
       0,   721,   720,   719,   718,   717,   682,     0,   774,     0,
     639,     0,     0,   767,   766,   765,     0,   759,   752,   750,
       0,   747,   748,   742,   150,   152,   154,     0,     0,     0,
       0,     0,   269,   267,     0,   275,   207,   355,    72,   331,
     337,     0,   354,   351,   347,     0,     0,     0,   341,     0,
       0,   343,     0,   540,   534,   529,     0,   530,   520,     0,
     795,     0,     0,     0,     0,   303,   301,     0,   777,   776,
       0,     0,   640,   596,     0,   761,   754,     0,     0,   156,
     155,     0,     0,     0,     0,   151,   271,     0,     0,     0,
       0,     0,   548,   542,     0,   541,   543,   549,   546,   536,
       0,   535,   537,   547,   522,     0,   523,     0,     0,   669,
     302,     0,   778,   690,   641,   749,   153,   157,     0,     0,
       0,     0,     0,     0,   344,   342,     0,     0,   533,   544,
     545,   532,   538,   539,   524,     0,   293,   158,     0,     0,
       0,   352,   348,     0,     0,     0,     0,     0,     0,     0,
       0,   160,     0,     0,   159,     0,     0,     0,     0,     0,
       0,     0,     0,   161
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1425, -1425,  -188,  -176, -1425,  1204,  1214, -1425,  1180,  -552,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
    -992, -1425, -1425, -1425, -1425,  -219,  -578, -1425,   707,   -40,
   -1425, -1425, -1425, -1425, -1425,   257,   477, -1425, -1425,    11,
    -173,  1023, -1425,  1019, -1425, -1425,  -641, -1425,   424, -1425,
     224, -1425,  -254,  -282, -1425,  -563, -1425,     4,    12,    28,
    -223,  -181, -1425,  -880, -1425, -1425,  -240, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425,   611, -1425,   -59,
    1357,     0, -1425, -1425,  -315, -1425, -1425,   347, -1425, -1425,
    -301, -1425,    16, -1425, -1425,   828,  -934,  -742,  -718, -1425,
   -1425,   704, -1425, -1425,   -70,   105, -1425, -1425, -1425,   122,
   -1068, -1425,   363,   127, -1425, -1425,   133, -1299, -1425,   948,
     226, -1425, -1425,   218, -1014, -1425, -1425,   220, -1425, -1425,
   -1260, -1255, -1425,   217, -1422, -1425, -1425,   848,   851, -1425,
    -527,   829, -1425, -1425,  -665,   328,  -643,   323,   329, -1425,
   -1425, -1425,   576, -1425, -1425,  1182, -1425, -1425, -1425, -1425,
   -1425,  -886,  -319,  -682, -1425,   -66, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425,   -13,  -819, -1425,  -539,  -195,   275, -1425,
    -427, -1425, -1425, -1425, -1425, -1425, -1425, -1425,   799, -1425,
   -1425, -1425, -1425, -1001, -1425,   206, -1425,   684,  -797, -1425,
   -1425, -1425, -1425, -1425,  -266,  -259, -1212,  -919, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,  -755,
    -832,  -210,  -825, -1425, -1425, -1425,  -759, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425,  1067,  1070,  -192,   498,
     330, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425,   183, -1425, -1425,   171, -1425,   174, -1072, -1425,
   -1425, -1425,   128,   114,   -52,   389, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,   130,
   -1425, -1425, -1425,   -45,   383,   530, -1425, -1425, -1425, -1425,
   -1425,   326, -1425, -1425, -1424, -1425, -1425, -1425,  -577, -1425,
      94, -1425,   -61, -1425, -1425, -1425, -1425, -1322, -1425,   142,
   -1425, -1425, -1425, -1425, -1425,   949, -1425, -1425, -1425, -1425,
   -1425,  -929,  -383,   914,   -64, -1425
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   258,   632,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
    1263,   783,   276,   277,   278,   279,   280,   281,   966,   967,
     968,   282,   283,   284,   972,   973,   974,   285,   450,   286,
     287,   716,   288,   452,   453,   454,   464,   773,   774,   289,
    1226,   290,  1704,  1705,   291,   292,   293,   556,   294,   295,
     296,   297,   298,   776,   299,   300,   538,   301,   302,   303,
     304,   305,   306,   642,   307,   308,   867,   868,   309,   310,
     311,   568,   313,   643,  1641,   655,  1133,  1134,   314,   645,
     315,   647,   569,   317,   318,   768,   769,  1380,   471,   319,
     472,   473,   906,  1381,  1382,  1383,   648,   649,  1127,  1128,
    1371,   650,  1123,  1124,  1364,  1365,  1366,  1367,   320,   796,
     797,   321,  1278,  1279,  1488,   322,  1281,  1282,   323,   324,
    1284,  1285,  1286,  1287,  1495,   325,   326,   327,   328,   913,
     329,   330,  1390,   331,   332,   333,   334,   335,   336,   337,
     338,   339,  1170,   340,   341,   342,   343,   673,   674,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   708,   703,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   943,   371,
     372,   373,   374,   375,   376,  1314,   829,   830,   831,  1735,
    1780,  1781,  1774,  1775,  1782,  1776,  1315,  1316,   377,   378,
    1317,   379,   380,   381,   382,   383,   384,   385,   386,  1028,
    1496,  1431,  1160,  1588,  1161,  1171,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   803,  1239,
     399,  1163,  1164,  1165,  1166,   400,   401,   402,   403,   404,
     405,   857,   858,   406,  1348,  1349,  1666,  1109,  1141,  1400,
    1401,  1142,  1143,  1144,  1145,  1146,  1410,  1578,  1579,  1147,
    1413,  1148,  1559,  1149,  1150,  1418,  1419,  1584,  1582,  1402,
    1403,  1404,  1405,  1684,   745,   993,   994,   995,   996,   997,
     998,  1212,  1608,  1701,  1213,  1606,  1699,   999,  1444,  1603,
    1599,  1600,  1601,  1000,  1001,  1406,  1414,  1569,  1407,  1565,
    1391,   407,   408,   409,   410,   559,   411,   412,   413,   414,
     415,  1167,  1264,   416,   417,   418
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int xquery_parser::yytable_ninf_ = -869;
  const short int
  xquery_parser::yytable_[] =
  {
       312,   644,   604,   717,   717,   312,   312,   312,   312,   423,
     426,   427,   535,   934,   921,   646,   316,   424,   424,   424,
     428,   316,   316,   316,   316,   451,   535,   697,  1026,  1499,
    1042,  1139,  1078,   425,   425,   425,   429,   922,   923,   924,
     925,  1510,  1280,  1054,   619,   886,   888,  1108,  1268,   720,
     535,   847,  1027,   567,   571,   620,   854,  1068,   880,   884,
     887,   889,   535,   534,   535,  1386,  1541,  1542,   620,   878,
     882,   583,   627,  1185,  1228,  1639,   622,   620,  1643,  1313,
     611,   612,  1022,  1215,   780,   784,   953,  1244,  1216,   759,
    1580,   624,    11,    12,  1707,  1252,   620,  1217,  1159,  1169,
     771,    13,  1518,   620,  1218,   620,  1219,   760,   585,    11,
      12,   312,   436,   626,  1677,  1220,  1306,  1307,   620,  1130,
     834,   818,   437,   424,   594,  1099,   620,   316,  1249,   436,
     620,   909,   620,   910,   911,  1101,   912,   620,   914,   557,
     439,  1023,  1221,  1024,  1189,   440,   915,   916,  1640,  1209,
    1732,   620,   620,   588,  1597,   589,  1024,   439,   702,  1428,
     640,   705,   631,   620,  1561,   719,  1210,   881,   772,   677,
     620,  1162,  1162,   686,   591,   631,   592,   441,   442,  1118,
    -169,   620,    82,  1702,  1636,   759,   678,   687,   606,   608,
    1429,  1246,  1678,   620,  1025,   751,    93,   469,  1257,  1114,
    1708,  1562,   627,   760,  -170,   620,   627,  1253,  1430,  1211,
    1162,  1308,   719,   595,  1100,   640,   620,   640,  1598,   455,
    1192,   107,   620,  1270,   620,  1136,   432,   433,  1137,   434,
     435,  1309,   620,  1310,  1471,   620,   628,   631,   620,   631,
     620,  1667,   590,   982,  1227,   983,  1095,   438,   128,   781,
     620,  1139,  1139,   470,   826,  1499,   312,   312,   631,   631,
     312,  1311,  1102,   593,  1162,   114,   621,  1492,   646,  1222,
     631,  1162,   316,   316,  1256,  1479,   316,   631,   626,  1303,
    1131,   126,  1709,   698,  1700,   623,  1254,   835,   631,   984,
     535,   586,   873,   535,   875,   312,   782,   886,   888,  1767,
     631,  1518,  1312,  1355,  1313,  1228,  1436,  1115,  1250,  1462,
    1255,   316,   631,  1313,  1186,  1117,  1558,  1132,   827,   470,
     153,   878,   882,   631,  1271,  1086,  1354,   761,  1422,   631,
    1138,   631,   470,  1795,   627,   620,   620,  1034,  1056,   631,
     620,   704,   631,   779,   706,   631,  1803,   631,  1806,  1057,
     444,   470,   447,   470,   430,   979,  1105,   631,  1051,   470,
     448,  1223,  1224,  1225,  -169,   616,   628,   870,   449,   752,
     628,  1051,   727,   535,  1374,   620,   535,   753,   869,  1299,
     535,   617,  1090,   535,   535,   890,  1135,   620,  -170,   892,
    1392,   535,  1733,   735,  1162,   736,   817,   535,   535,  1016,
    1039,   764,   879,   883,  1392,   535,   777,  1759,  1300,   445,
    1301,   818,   535,   535,   535,   535,   790,   431,  1741,   825,
     535,   900,  1175,   801,   802,   312,  1742,  1474,   535,   312,
     874,   876,   808,   620,   872,   620,  1743,  1566,  1052,   985,
     891,   316,   631,   631,  1489,   316,   458,   631,  1087,  1088,
     446,  1070,   986,  1772,   987,   738,   312,  1306,   312,   629,
     620,  1797,  1393,  1089,   620,   988,   989,   990,   756,   991,
     758,   992,   316,   535,   316,  1227,  1393,   948,  1452,  1024,
     312,  1734,   631,  1788,   429,   312,   429,   819,   535,   948,
    1140,   479,   799,   701,   631,   707,   316,   805,   628,   535,
    1162,   316,  1139,  1464,   484,  1091,  1092,  1094,   429,    11,
      12,  1139,  1313,   429,   832,   833,   739,   459,  1046,  1062,
    1093,  1179,  1139,  1081,  1162,   837,   848,  1017,  1108,   640,
    1463,   848,  1536,  1499,   535,   651,  1472,   886,   888,   886,
     631,   630,   631,   863,   865,  1394,  1395,  1449,  1396,  1306,
    1277,  1019,  1356,  1357,  1358,  1397,   949,   312,  1082,  1394,
    1395,  1336,  1396,  1486,   312,  1398,   677,   631,   950,  1778,
    1083,   631,  1309,   316,  1310,  1527,   424,  1399,    13,  1398,
     316,   485,  1773,   678,  1306,  1307,  1031,  1306,  1587,  1079,
     535,  1399,   425,  1193,  1194,   625,  1567,  1568,  1197,   652,
    1745,  1063,  1311,   312,   653,  1304,  1018,  1778,  1306,  1307,
     312,  1084,  1097,  1065,  1545,   596,  1107,  1441,  1556,   316,
     597,   312,   312,   312,   312,  1772,   316,   451,  1236,  1306,
    1020,   864,  1718,   936,   937,  1306,  1307,   316,   316,   316,
     316,   627,   938,  1789,   312,   749,   725,  1793,   486,   487,
     750,   654,  1176,  1350,  1112,  1080,   488,  1176,  1691,    82,
     316,  1162,   726,  1696,  1309,  1032,  1310,   955,  1119,  1085,
     535,  1305,   701,    93,   707,  1779,  1681,  1443,  1790,  1308,
    1064,  1184,   696,  1682,   535,   735,   463,   736,   535,   535,
    1139,  1116,  1066,  1683,  1311,   876,   312,   775,   107,  1309,
     935,  1310,  1309,  1308,  1310,   128,   680,   535,   424,  1351,
    1140,  1140,   316,  1812,  1647,   535,  1023,   634,   535,  1651,
     737,   635,   535,  1309,   425,  1310,   636,  1618,  1492,  1311,
    1308,  1177,  1311,   114,  1573,   681,  1178,  1692,  1162,  1441,
    1665,  1162,  1697,  1388,  1309,   637,  1310,   738,   682,   126,
    1309,  1180,  1310,  1311,  1809,  1182,  1442,   114,   462,  1024,
    -260,  1073,  1074,  1075,   535,   865,   128,  1181,    13,  1053,
    1512,  1183,  1612,   126,  1311,   312,   886,  1023,   729,  1033,
    1311,   970,   683,   489,   114,  1376,   971,   424,   153,   969,
    1377,   316,  1023,  1376,  1517,  1361,  1351,  1023,  1377,  1443,
     126,   465,   535,   425,  1722,  1106,   312,   312,   739,  1378,
    1617,   730,   153,   490,  1777,  1783,  1363,  1023,  1060,  1061,
     697,  1649,   316,   316,  -260,  1238,   881,  1241,  1024,  -260,
    1373,   535,   970,   684,   429,   429,  1024,   971,  1435,   153,
    1041,   535,   685,   638,   491,  1067,   639,   492,   474,    82,
    1379,  1736,   477,  1681,   775,  1739,  1777,  1752,  1113,  1753,
    1682,   640,  1783,    93,   312,  1544,   535,   535,   535,   535,
    1683,  1292,   677,  1293,   617,   466,  -260,  1162,  1023,  1477,
     316,  1209,  1344,   677,   467,  1415,  1416,   641,   107,   678,
    1361,   312,  1136,  1360,   478,  1137,   451,  1277,  1210,   721,
     678,  1376,  1679,  1680,  1361,   535,  1377,   316,  1417,  1563,
    1491,   468,   679,   722,  1362,   128,  1564,  1676,   891,   535,
    1497,  1500,  1794,  1750,   876,  1363,  1187,  1706,  1352,   723,
    1162,   710,  1162,  1498,  1501,  1497,  1497,   482,  1187,  1203,
    1785,  1205,   711,   724,   535,  1230,   699,   700,  1646,  1815,
    1204,  1760,  1206,   535,  1231,   535,   701,   535,   707,   535,
     456,  1140,  1162,   457,   460,  1490,   535,   461,   475,   480,
    1140,   476,   481,  1198,  1199,  1200,   536,   939,  1537,  1201,
     939,  1140,   537,   939,   741,   742,   743,  1546,  1320,   483,
    1321,  1325,   539,  1326,   540,  1162,  1195,  1196,   552,   535,
     553,   535,  1538,  1539,   551,   919,   920,   926,   927,  1162,
     554,  1162,  1748,  1749,   573,   928,   929,  1447,  1448,   574,
    1693,  1694,   575,  1529,   580,   581,   582,   587,   572,  1706,
     584,  1533,  -610,   599,   598,   600,   848,   601,  1475,   602,
     576,   609,   579,   603,   613,   646,   956,   957,   958,   959,
     960,   961,   962,   963,   964,   965,   633,   656,   312,   657,
     676,   535,   675,   688,   689,   690,   701,   691,   712,   709,
    1288,   695,   713,   719,   316,   714,  1706,  1385,   715,   731,
     733,   734,   744,   658,   757,  1792,   429,   775,   778,   535,
     748,   659,   660,   786,   661,  1625,   787,   788,   806,   807,
     789,   813,   662,   800,   457,  1345,   663,   815,   664,   461,
     817,   476,   481,   665,   492,   312,   312,   312,   820,   828,
     836,  1346,   824,   838,   821,   451,   822,   839,   860,   666,
     861,   316,   316,   316,   877,   856,   895,   866,   896,   902,
     903,   897,   898,   905,   917,   931,   932,   933,  1834,  1140,
    1835,   930,   945,   667,   668,   669,   670,   671,   672,   954,
    1843,   951,   604,   944,   952,   976,   977,   980,   981,  1003,
    1002,  1628,  1006,  1629,  1008,  1011,  1633,  1634,  1012,   535,
    1637,  1013,  1004,   535,  1021,  1014,  1644,  1015,  1030,  1036,
    1037,  1040,  1055,  1047,  1048,   535,  1049,  1050,  1059,  1058,
     456,   460,   475,   480,  1096,  1103,  1104,  1114,   491,   535,
    1098,  1111,  1174,  1188,   971,  1023,  1207,  1208,  1229,   535,
    1234,  1235,  1237,  1245,  1247,  1251,   771,  1121,  1259,  1261,
    1265,  1262,  1266,  1267,  1273,  1272,  1276,   312,  1277,  1283,
    1291,  1456,  1260,  1289,  1290,  1295,  1298,  1302,   535,   424,
    1318,  1296,  1319,   316,  1337,   737,  1347,  1368,  1370,  1408,
    1372,   312,  1389,  1409,  1432,   425,  1375,  1631,  1420,  1421,
    1423,  1424,   312,   535,  1425,  1426,  1482,   316,  1427,    13,
    1440,  1439,  1412,   535,   424,  1445,  1450,   535,   316,  1451,
    1454,   312,  1459,  1457,  1455,  1504,  1467,  1458,  1469,  1478,
     425,  1473,  1481,   424,  1497,  1511,  1509,   316,  1514,  1460,
     900,   312,  1503,  1461,  1505,   535,  1521,  1506,   312,   425,
    1525,  1530,  1520,  1515,  1726,   640,  1526,   316,  1730,  1549,
    1519,  1350,  1361,  1522,   316,  1531,  1532,  1550,  1551,   429,
    1555,  1557,  1576,  1583,  1589,  1590,   429,  1577,  1591,  1523,
    1345,   728,  1581,  1592,   732,  1593,   535,  1596,   740,  1602,
    1594,   746,   747,  1595,  1607,  1609,  1346,  1524,  1613,   755,
    1622,  1623,  1605,  1560,  1615,   767,   770,  1620,   864,  1624,
    1627,  1645,  1650,   785,  1653,  1669,   535,  1687,  1658,  1675,
     793,   794,   795,   798,  1570,  1689,  1690,  1611,   804,  1716,
    1698,  1209,  1703,  1721,  1711,  1714,   811,  1738,  1747,  1754,
    1720,  1631,  1769,  1755,  1723,  1756,  1762,  1757,  1758,  1768,
    1770,  1731,  1688,  1811,  1763,  1784,  1791,  1786,  1710,  1787,
     535,  1800,  1801,   535,  1808,  1814,   535,  1820,  1825,  1826,
    1836,  1839,  1837,   618,   978,  1840,  1438,  1190,   535,    11,
      12,   812,  1802,   535,   718,  1258,  1807,  1765,  1453,   432,
     433,  1798,   434,   435,   614,  1818,   798,  1827,   558,   436,
     754,  1662,  1663,  1664,   615,  1830,  1796,   823,  1110,   437,
     438,  1384,   904,  1673,  1359,  1554,   535,   535,  1823,  1832,
     312,  1824,  1045,  1842,  1547,  1543,  1487,   439,  1540,  1483,
     814,  1493,   440,  1502,   907,   918,   316,  1723,   908,  1173,
     947,  1513,   859,  1077,  1833,  1813,  1810,  1242,  1437,  1535,
    1528,  1534,  1575,   694,  1686,  1571,   762,  1387,  1685,   763,
    1411,  1574,  1214,  1345,   441,   442,   443,  1446,  1604,  1695,
    1572,     0,   852,     0,     0,     0,  1804,     0,     0,  1346,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1475,     0,     0,     0,   770,     0,
       0,     0,   535,     0,   535,     0,   535,     0,   535,  1821,
       0,     0,     0,   444,     0,   535,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1821,     0,     0,     0,     0,  1744,     0,     0,     0,
    1804,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1345,     0,     0,   535,     0,   535,  1751,     0,
       0,     0,     0,  1345,  1345,     0,     0,   312,  1346,     0,
       0,     0,   445,   535,  1345,     0,   535,     0,   975,  1346,
    1346,     0,     0,   316,     0,     0,     0,   535,     0,     0,
    1346,     0,  1005,     0,     0,     0,  1009,  1010,   535,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   446,     0,  1029,     0,     0,     0,     0,
     535,     0,     0,  1035,     0,     0,  1038,     0,   535,     0,
    1043,     0,     0,     0,   535,     0,   535,     0,     0,   447,
       0,     0,     0,     0,     0,     0,     0,   448,     0,     0,
       0,     0,     0,     0,     0,   449,     0,   535,     0,     0,
    1345,     0,     0,     0,     0,     0,   535,     0,     0,     0,
       0,     0,  1076,     0,     0,     0,  1346,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   535,     0,     0,     0,
       0,   535,     0,     0,     0,     0,     0,     0,     0,   312,
       0,     0,     0,   535,     0,     0,   535,     0,     0,     0,
       0,     0,     0,     0,     0,   316,     0,  1345,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   312,  1346,     0,     0,     0,     0,     0,  1120,
       0,     0,     0,     0,     0,     0,     0,     0,   316,  1129,
       0,     0,     0,     0,  1345,     0,     0,     0,     0,     0,
       0,     0,     0,  1345,     0,     0,     0,     0,     0,     0,
    1346,     0,     0,     0,  1168,  1168,  1172,  1172,     0,  1346,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1168,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1202,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   558,  1233,     0,     0,     0,     0,     0,     0,     0,
       0,  1240,     0,  1240,     0,   770,     0,  1168,     0,     0,
       0,     0,     0,     0,  1168,   840,   841,     0,   849,   850,
     851,   853,     0,   855,     0,     0,     0,     0,   862,     0,
       0,     0,     0,     0,     0,     0,   871,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   804,     0,   804,
       0,     0,     0,     0,     0,     0,     0,     0,   893,   894,
       0,     0,     0,     0,     0,     0,     0,     0,   899,     0,
       0,   901,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1369,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   942,     0,     0,  1168,   942,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1007,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1044,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   770,     0,     0,
       0,  1465,     0,     0,     0,     0,     0,     0,     0,     0,
    1069,     0,     0,  1168,  1071,  1072,     0,     0,     0,     0,
       0,     0,     0,   901,     0,     0,     0,   798,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1168,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1516,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   894,     0,
       0,   859,     0,     0,  1122,  1126,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1553,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1191,     0,
       0,     0,     0,     0,  1168,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1232,  1610,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1248,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1269,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1635,  1274,
    1275,  1168,     0,     0,  1168,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1294,     0,  1648,  1297,     0,     0,
       0,  1652,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1322,  1323,  1324,     0,  1327,  1328,
    1329,  1330,  1331,  1332,  1333,  1334,  1335,     0,     0,  1338,
    1339,     0,     0,     0,  1671,  1672,     0,     0,  1353,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1434,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1168,     0,  1725,     0,  1727,     0,  1729,     0,     0,     0,
       0,     0,     0,  1737,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1168,     0,  1168,  1466,     0,  1468,     0,
    1470,     0,     0,     0,     0,     0,     0,     0,  1476,     0,
       0,  1761,     0,     0,  1764,     0,     0,  1480,     0,     0,
       0,     0,     0,  1484,  1485,  1168,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1771,     0,     0,     0,
       0,     0,  1507,     0,     0,  1508,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1168,     0,
       0,     0,     0,     0,     0,     0,  1799,     0,     0,     0,
       0,     0,  1168,     0,  1168,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1816,     0,     0,     0,     0,
       0,     0,     0,     0,  1819,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1122,     0,     0,     0,  1126,
    1548,     0,     0,     0,  1828,  1552,     0,     0,     0,  1829,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1838,     0,     0,  1841,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1614,     0,     0,     0,  1616,     0,     0,     0,  1619,     0,
    1621,     0,     0,     0,     0,     0,     0,     0,  1626,     0,
       0,     0,     0,     0,     0,     0,  1630,  1632,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1476,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1654,  1655,
    1656,  1657,     0,  1659,  1660,     0,  1661,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1668,     0,     0,     0,     0,  1670,     0,     0,     0,
       0,     0,  1674,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1712,     0,  1713,     0,     0,  1715,     0,     0,
    1717,     0,     0,     0,     0,  1719,  1632,     0,     0,     0,
       0,     0,     0,     0,  1724,     0,     0,     0,  1728,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1740,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1746,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1766,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1724,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1805,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -165,
     881,     0,     0,     0,     0,  1817,     0,     0,     0,  1822,
       1,     2,     0,     0,  1805,     3,     0,     0,     0,     4,
       5,     6,     7,     8,     9,    10,    11,    12,     0,    13,
    1822,     0,    14,   420,  1831,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     0,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,     0,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,    72,    73,    74,    75,    76,     0,
      77,    78,    79,     0,     0,    80,    81,     0,     0,     0,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,     0,     0,     0,    93,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,    99,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   111,   112,     0,   113,   114,   115,   116,
     117,     0,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   125,     0,   126,     0,   127,   128,     0,     0,   129,
     130,   131,     0,     0,     0,   132,     0,   133,   134,   135,
     136,   137,     0,   138,     0,   139,     0,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,     0,     0,
     151,   152,   153,     0,   422,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,     0,   197,   198,
     199,     0,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
       0,   248,     0,   249,   250,   251,   252,   253,   254,   255,
    -165,   881,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
      13,     0,     0,   885,   420,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,   421,
      30,    31,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,     0,     0,     0,    93,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,    99,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   112,     0,   113,   114,   115,
     116,   117,     0,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,     0,   126,     0,   127,   128,     0,     0,
     129,   130,   131,     0,     0,     0,   132,     0,   133,   134,
     135,   136,   137,     0,   138,     0,   139,     0,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,     0,
       0,   151,   152,   153,     0,   422,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   881,   248,     0,   249,   250,   251,   252,   253,   254,
     255,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
      13,     0,     0,   419,   420,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,   421,
      30,    31,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,     0,     0,     0,    93,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,    99,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   112,     0,   113,   114,   115,
     116,   117,     0,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,     0,   126,     0,   127,   128,     0,     0,
     129,   130,   131,     0,     0,     0,   132,     0,   133,   134,
     135,   136,   137,     0,   138,     0,   139,     0,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,     0,
       0,   151,   152,   153,     0,   422,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   881,   248,     0,   249,   250,   251,   252,   253,   254,
     255,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   419,   420,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,   560,   421,
      30,    31,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,    50,   561,   562,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,   510,    85,    86,    87,    88,    89,   563,
      91,    92,     0,     0,     0,    93,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,    99,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   564,   112,     0,   113,   114,   115,
     116,   117,     0,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,     0,   126,     0,   127,   128,     0,     0,
     129,   130,   131,     0,     0,     0,   132,     0,   133,   134,
       0,   136,   137,     0,   138,     0,   139,     0,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,     0,
       0,   151,   152,   153,     0,   422,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   528,   529,
     530,   180,   181,   531,   566,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,     0,   248,     0,   249,   250,   251,   252,   253,   254,
     255,  -868,   462,     0,  -260,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -868,     0,     0,     0,  -868,     0,     0,
       0,  -868,  -868,     0,     0,     0,     0,  -868,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -260,     0,
       0,  -868,     0,  -260,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -868,     0,  -868,  -868,  -868,     0,
       0,  -868,  -868,  -868,  -868,     0,     0,     0,  -868,  -868,
       0,     0,     0,     0,     0,  -868,     0,     0,  -868,  -868,
    -260,     0,     0,  -868,     0,     0,     0,     0,  -868,  -868,
       0,     0,     0,     0,  -868,     0,     0,     0,  -868,     0,
       0,     0,  -868,  -868,     0,  -868,     0,  -868,  -868,     0,
       0,     0,  -868,  -868,     0,     0,  -868,  -868,  -868,  -868,
    -868,  -868,     0,     0,  -868,     0,     0,     0,  -868,  -868,
       0,     0,  -868,     0,     0,     0,     0,  -868,     0,     0,
    -868,     0,     0,     0,     0,  -868,  -868,  -868,  -868,  -868,
       0,  -868,  -868,  -868,  -868,  -868,     0,     0,     0,     0,
    -868,  -868,  -868,     0,  -868,  -868,  -868,  -868,  -868,  -868,
       0,  -868,     0,  -868,     0,     0,     0,     0,  -868,  -868,
    -868,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -868,     0,  -868,     0,  -868,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -868,     0,     0,     0,     0,  -868,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     2,     0,     0,     0,     3,
       0,     0,     0,     4,     5,     6,     7,     8,     9,    10,
      11,    12,  -868,    13,  -868,     0,    14,    15,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,     0,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,     0,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,    72,    73,
      74,    75,    76,     0,    77,    78,    79,     0,     0,    80,
      81,     0,     0,     0,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,     0,     0,     0,    93,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,    99,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,   110,   111,   112,     0,
     113,   114,   115,   116,   117,     0,     0,     0,   118,   119,
     120,   121,   122,   123,   124,   125,     0,   126,     0,   127,
     128,     0,     0,   129,   130,   131,     0,     0,     0,   132,
       0,   133,   134,   135,   136,   137,     0,   138,     0,   139,
       0,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,     0,     0,   151,   152,   153,     0,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,     0,   197,   198,   199,     0,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,     0,   248,     0,   249,   250,   251,
     252,   253,   254,   255,   256,   257,     1,     2,     0,     0,
       0,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     0,    13,     0,     0,    14,    15,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       0,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     0,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,    74,    75,    76,     0,    77,    78,    79,     0,
       0,    80,    81,     0,     0,     0,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,     0,   113,   114,   115,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   127,   128,     0,     0,   129,   130,   131,     0,     0,
       0,   132,     0,   133,   134,   135,   136,   137,     0,   138,
       0,   139,     0,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,     0,     0,   151,   152,   153,     0,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,     0,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,     0,   248,     0,   249,
     250,   251,   252,   253,   254,   255,     0,   610,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,   421,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   111,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,   555,     0,   132,     0,   133,   134,   135,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   250,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,   421,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   111,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,   816,     0,   132,     0,   133,   134,   135,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   250,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,  1340,   421,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
    1341,  1342,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   111,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,   555,     0,   132,     0,   133,   134,   135,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,  1343,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   250,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,   421,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   111,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,   135,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   250,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,    13,     0,     0,
      14,    15,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   111,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,   135,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   250,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,    13,     0,     0,
      14,    15,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   111,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,   135,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   250,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,    13,     0,     0,
      14,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   111,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,   135,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   250,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,    13,     0,     0,
     885,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,   421,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   111,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,   135,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   250,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,  1340,   421,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
    1341,  1342,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   111,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,   135,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,  1343,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   250,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,   560,   421,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
     561,   562,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     510,    85,    86,    87,    88,    89,   563,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,   940,     0,   104,   105,   106,   107,   108,   109,
     110,   564,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,   941,   133,   134,     0,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   528,   529,   530,   180,   181,
     531,   566,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   250,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,   560,   421,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
     561,   562,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     510,    85,    86,    87,    88,    89,   563,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,   940,     0,   104,   105,   106,   107,   108,   109,
     110,   564,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,   946,   133,   134,     0,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   528,   529,   530,   180,   181,
     531,   566,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   250,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,   560,   421,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
     561,   562,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     510,    85,    86,    87,    88,    89,   563,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   564,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,   565,   132,     0,   133,   134,     0,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   528,   529,   530,   180,   181,
     531,   566,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   250,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,   560,   421,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
     561,   562,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     510,    85,    86,    87,    88,    89,   563,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   564,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,   570,   133,   134,     0,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   528,   529,   530,   180,   181,
     531,   566,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   250,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,   560,   421,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
     561,   562,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     510,    85,    86,    87,    88,    89,   563,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   564,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,     0,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   528,   529,   530,   180,   181,
     531,   566,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   605,   248,
       0,   249,   250,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,   560,   421,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
     561,   562,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     510,    85,    86,    87,    88,    89,   563,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   564,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,     0,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   528,   529,   530,   180,   181,
     531,   566,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
     607,   249,   250,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,   560,   421,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
     561,   562,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     510,    85,    86,    87,    88,    89,   563,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,  1433,     0,   104,   105,   106,   107,   108,   109,
     110,   564,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,     0,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   528,   529,   530,   180,   181,
     531,   566,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   250,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   496,    27,   498,   421,    30,   499,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,   501,     0,    48,    49,    50,
     503,   504,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     510,    85,    86,    87,    88,    89,   563,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   513,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   564,   112,     0,   113,   114,   692,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   693,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,     0,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   523,   164,   524,   166,   525,   526,   169,   170,   171,
     172,   173,   174,   527,   176,   528,   529,   530,   180,   181,
     531,   532,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   533,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,   560,   421,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
     561,   562,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     510,    85,    86,    87,    88,    89,   563,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   564,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,     0,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   528,   529,   530,   180,   181,
     531,   566,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   250,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   496,    27,   498,   421,    30,   499,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,   501,     0,    48,    49,    50,
     503,   504,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     510,    85,    86,    87,    88,    89,   563,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   513,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   564,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,     0,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   523,   164,   524,   166,   525,   526,   169,   170,   171,
     172,   173,   174,   527,   176,   528,   529,   530,   180,   181,
     531,   532,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   533,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,   560,   421,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
     561,   562,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     510,    85,    86,    87,    88,    89,  1125,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   564,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,     0,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   528,   529,   530,   180,   181,
     531,   566,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   250,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   496,    27,   498,   421,    30,   499,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,   501,     0,    48,    49,    50,
     503,   504,    53,   505,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     510,    85,    86,    87,    88,    89,   563,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   513,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   564,   112,     0,   113,   114,     0,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,     0,     0,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,     0,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   523,   164,   524,   166,   525,   526,   169,   170,   171,
     172,   173,   174,   527,   176,   528,   529,   530,   180,   181,
     531,   532,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   533,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   496,    27,   498,   421,    30,   499,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,   501,     0,    48,    49,    50,
     503,   504,    53,   505,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     510,    85,    86,    87,    88,    89,   563,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   513,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   564,   112,     0,   113,   114,     0,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,     0,     0,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,     0,     0,     0,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   523,   164,   524,   166,   525,   526,   169,   170,   171,
     172,   173,   174,   527,   176,   528,   529,   530,   180,   181,
     531,   532,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   533,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   496,    27,   498,   421,    30,   499,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,   501,     0,    48,    49,    50,
     503,   504,    53,   505,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     510,    85,    86,    87,    88,    89,   563,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   513,     0,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,     0,   109,
     110,   564,   112,     0,   113,   114,     0,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,     0,     0,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,     0,     0,     0,
       0,   138,     0,   139,     0,   140,     0,   142,     0,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   523,   164,   524,   166,   525,   526,   169,   170,   171,
     172,   173,   174,   527,   176,   528,   529,   530,   180,   181,
     531,   532,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   533,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     0,     0,
       0,     0,     9,    10,     0,     0,     0,     0,     0,     0,
     419,   420,     0,    16,    17,    18,   493,    20,    21,    22,
     494,    24,   495,   496,   497,   498,   421,    30,   499,    32,
      33,    34,     0,    35,    36,    37,    38,   500,    40,    41,
      42,    43,    44,    45,    46,   501,     0,    48,   502,    50,
     503,   504,    53,   505,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,   506,   507,
      71,     0,    72,    73,    74,   508,     0,     0,    77,    78,
      79,     0,     0,   509,    81,     0,     0,     0,     0,    83,
     510,    85,   511,   512,    88,    89,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   513,   100,   101,   514,   515,     0,     0,
       0,     0,     0,     0,   104,   105,   106,     0,   108,   109,
     110,     0,     0,     0,     0,     0,     0,   116,   516,     0,
       0,     0,   118,   119,   120,   121,   517,   123,   124,   518,
       0,     0,     0,     0,     0,     0,     0,   519,   520,   131,
       0,     0,     0,   132,     0,   133,   521,     0,     0,     0,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   522,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
       0,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   523,   164,   524,   166,   525,   526,   169,   170,   171,
     172,   173,   174,   527,   176,   528,   529,   530,   180,   181,
     531,   532,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,     0,     0,     0,
       0,   249,   533,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     0,     0,
       0,     0,     9,    10,     0,     0,     0,     0,     0,     0,
     419,   420,     0,    16,    17,    18,   541,    20,    21,    22,
     494,   542,   543,   496,   497,   498,   421,    30,   499,    32,
     544,    34,     0,    35,    36,    37,    38,   545,    40,   546,
     547,    43,    44,    45,    46,   501,     0,    48,   548,    50,
     503,   504,    53,   505,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,   506,   507,
      71,     0,    72,    73,    74,   549,     0,     0,    77,    78,
      79,     0,     0,   509,    81,     0,     0,     0,     0,    83,
     510,    85,   511,   512,    88,    89,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   513,   100,   101,   514,   515,     0,     0,
       0,     0,     0,     0,   104,   105,   106,     0,   108,   109,
     110,     0,     0,     0,     0,     0,     0,   116,   516,     0,
       0,     0,   118,   119,   120,   121,   517,   123,   124,   518,
       0,     0,     0,     0,     0,     0,     0,   519,   520,   131,
       0,     0,     0,   132,     0,   133,   521,     0,     0,     0,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   522,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
       0,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   523,   550,   524,   166,   525,   526,   169,   170,   171,
     172,   173,   174,   527,   176,   528,   529,   530,   180,   181,
     531,   532,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,     0,     0,     3,
       0,   249,   533,   251,   252,   253,   254,   255,     9,    10,
       0,     0,     0,     0,     0,     0,   419,   420,     0,    16,
      17,    18,   493,    20,    21,    22,   494,    24,   495,   496,
    1151,   498,   421,    30,   499,    32,    33,    34,     0,    35,
      36,    37,    38,   500,    40,    41,    42,    43,    44,    45,
      46,   501,     0,    48,   502,    50,   503,   504,    53,   505,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,   506,   507,    71,     0,    72,    73,
      74,   508,     0,     0,    77,    78,    79,     0,     0,   509,
      81,     0,     0,     0,     0,    83,   510,    85,   511,   512,
      88,    89,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,   513,
     100,   101,   514,   515,     0,     0,     0,     0,     0,     0,
     104,   105,   106,     0,   108,   109,  1152,     0,     0,     0,
    1153,     0,     0,   116,   516,     0,     0,     0,   118,   119,
     120,   121,   517,   123,   124,   518,     0,     0,     0,     0,
       0,     0,     0,   519,   520,   131,     0,     0,     0,   132,
    1585,   133,   521,     0,     0,     0,     0,  1586,     0,   139,
       0,   140,   141,   142,   143,   522,   145,   146,   147,   148,
     149,   150,     0,     0,  1154,   152,     0,     0,   422,   155,
     156,   157,   158,   159,   160,   161,   162,   523,   164,   524,
     166,   525,   526,   169,   170,   171,   172,   173,   174,   527,
     176,   528,   529,   530,   180,   181,   531,   532,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,     0,   197,   198,   199,     0,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,     0,     0,     0,     0,   249,   533,   251,
    1155,  1156,  1157,  1158,     3,     0,   577,   578,     0,     0,
       0,     0,     0,     9,    10,     0,     0,     0,     0,     0,
       0,   419,   420,     0,    16,    17,    18,   541,    20,    21,
      22,   494,   542,   543,   496,   497,   498,   421,    30,   499,
      32,   544,    34,     0,    35,    36,    37,    38,   545,    40,
     546,   547,    43,    44,    45,    46,   501,     0,    48,   548,
      50,   503,   504,    53,   505,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,   506,
     507,    71,     0,    72,    73,    74,   549,     0,     0,    77,
      78,    79,     0,     0,   509,    81,     0,     0,     0,     0,
      83,   510,    85,   511,   512,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   513,   100,   101,   514,   515,     0,
       0,     0,     0,     0,     0,   104,   105,   106,     0,   108,
     109,   110,     0,     0,     0,     0,     0,     0,   116,   516,
       0,     0,     0,   118,   119,   120,   121,   517,   123,   124,
     518,     0,     0,     0,     0,     0,     0,     0,   519,   520,
     131,     0,     0,     0,   132,     0,   133,   521,     0,     0,
       0,     0,     0,     0,   139,     0,   140,   141,   142,   143,
     522,   145,   146,   147,   148,   149,   150,     0,     0,   151,
     152,     0,     0,   422,   155,   156,   157,   158,   159,   160,
     161,   162,   523,   550,   524,   166,   525,   526,   169,   170,
     171,   172,   173,   174,   527,   176,   528,   529,   530,   180,
     181,   531,   532,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,     0,   197,   198,   199,
       0,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,     0,     0,
       3,     0,   249,   533,   251,   252,   253,   254,   255,     9,
      10,     0,     0,     0,     0,     0,     0,   419,   420,     0,
      16,    17,    18,   541,    20,    21,    22,   494,   542,   543,
     496,   497,   498,   421,    30,   499,    32,   544,    34,     0,
      35,    36,    37,    38,   545,    40,   546,   547,    43,    44,
      45,    46,   501,     0,    48,   548,    50,   503,   504,    53,
     505,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,   506,   507,    71,     0,    72,
      73,    74,   549,     0,     0,    77,    78,    79,     0,     0,
     509,    81,     0,     0,     0,     0,    83,   510,    85,   511,
     512,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
     513,   100,   101,   514,   515,     0,     0,     0,     0,     0,
       0,   104,   105,   106,     0,   108,   109,   110,     0,     0,
       0,     0,     0,     0,   116,   516,     0,     0,     0,   118,
     119,   120,   121,   517,   123,   124,   518,     0,     0,     0,
       0,     0,     0,     0,   519,   520,   131,     0,     0,     0,
     132,   765,   133,   521,     0,     0,     0,     0,   766,     0,
     139,     0,   140,   141,   142,   143,   522,   145,   146,   147,
     148,   149,   150,     0,     0,   151,   152,     0,     0,   422,
     155,   156,   157,   158,   159,   160,   161,   162,   523,   550,
     524,   166,   525,   526,   169,   170,   171,   172,   173,   174,
     527,   176,   528,   529,   530,   180,   181,   531,   532,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,     0,   197,   198,   199,     0,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,     0,     0,     3,     0,   249,   533,
     251,   252,   253,   254,   255,     9,    10,     0,     0,     0,
     791,     0,     0,   419,   420,     0,    16,    17,    18,   541,
      20,    21,    22,   494,   542,   543,   496,   497,   498,   421,
      30,   499,    32,   544,    34,     0,    35,    36,    37,    38,
     545,    40,   546,   547,    43,    44,    45,    46,   501,     0,
      48,   548,    50,   503,   504,    53,   505,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,   506,   507,    71,     0,    72,    73,    74,   549,     0,
       0,    77,    78,    79,     0,     0,   509,    81,     0,     0,
       0,     0,    83,   510,    85,   511,   512,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,   513,   100,   101,   514,
     515,     0,     0,     0,     0,     0,     0,   104,   105,   106,
       0,   108,   109,   110,     0,     0,     0,     0,     0,     0,
     116,   516,     0,     0,     0,   118,   119,   120,   121,   517,
     123,   124,   518,     0,     0,     0,     0,     0,     0,     0,
     519,   520,   131,     0,     0,     0,   132,   792,   133,   521,
       0,     0,     0,     0,     0,     0,   139,     0,   140,   141,
     142,   143,   522,   145,   146,   147,   148,   149,   150,     0,
       0,   151,   152,     0,     0,   422,   155,   156,   157,   158,
     159,   160,   161,   162,   523,   550,   524,   166,   525,   526,
     169,   170,   171,   172,   173,   174,   527,   176,   528,   529,
     530,   180,   181,   531,   532,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
       0,     0,     3,     0,   249,   533,   251,   252,   253,   254,
     255,     9,    10,     0,     0,     0,     0,     0,     0,   419,
     420,     0,    16,    17,    18,   541,    20,    21,    22,   494,
     542,   543,   496,   497,   498,   421,    30,   499,    32,   544,
      34,     0,    35,    36,    37,    38,   545,    40,   546,   547,
      43,    44,    45,    46,   501,     0,    48,   548,    50,   503,
     504,    53,   505,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,   506,   507,    71,
       0,    72,    73,    74,   549,     0,     0,    77,    78,    79,
       0,     0,   509,    81,     0,     0,     0,     0,    83,   510,
      85,   511,   512,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,   513,   100,   101,   514,   515,     0,     0,     0,
       0,     0,     0,   104,   105,   106,     0,   108,   109,   110,
       0,     0,     0,     0,     0,     0,   116,   516,     0,     0,
       0,   118,   119,   120,   121,   517,   123,   124,   518,     0,
       0,     0,     0,     0,     0,     0,   519,   520,   131,     0,
       0,     0,   132,   809,   133,   521,     0,     0,     0,     0,
     810,     0,   139,     0,   140,   141,   142,   143,   522,   145,
     146,   147,   148,   149,   150,     0,     0,   151,   152,     0,
       0,   422,   155,   156,   157,   158,   159,   160,   161,   162,
     523,   550,   524,   166,   525,   526,   169,   170,   171,   172,
     173,   174,   527,   176,   528,   529,   530,   180,   181,   531,
     532,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,     0,   197,   198,   199,     0,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,     0,     0,     3,     0,
     249,   533,   251,   252,   253,   254,   255,     9,    10,     0,
       0,     0,     0,     0,     0,   419,   420,     0,    16,    17,
      18,   493,    20,    21,    22,   494,    24,   495,   496,  1151,
     498,   421,    30,   499,    32,    33,    34,     0,    35,    36,
      37,    38,   500,    40,    41,    42,    43,    44,    45,    46,
     501,     0,    48,   502,    50,   503,   504,    53,   505,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,   506,   507,    71,     0,    72,    73,    74,
     508,     0,     0,    77,    78,    79,     0,     0,   509,    81,
       0,     0,     0,     0,    83,   510,    85,   511,   512,    88,
      89,  1494,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,   513,   100,
     101,   514,   515,     0,     0,     0,     0,     0,     0,   104,
     105,   106,     0,   108,   109,  1152,     0,     0,     0,  1153,
       0,     0,   116,   516,     0,     0,     0,   118,   119,   120,
     121,   517,   123,   124,   518,     0,     0,     0,     0,     0,
       0,     0,   519,   520,   131,     0,     0,     0,   132,     0,
     133,   521,     0,     0,     0,     0,     0,     0,   139,     0,
     140,   141,   142,   143,   522,   145,   146,   147,   148,   149,
     150,     0,     0,  1154,   152,     0,     0,   422,   155,   156,
     157,   158,   159,   160,   161,   162,   523,   164,   524,   166,
     525,   526,   169,   170,   171,   172,   173,   174,   527,   176,
     528,   529,   530,   180,   181,   531,   532,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
       0,   197,   198,   199,     0,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,     0,     0,     3,     0,   249,   533,   251,  1155,
    1156,  1157,  1158,     9,    10,     0,     0,     0,     0,     0,
       0,   419,   420,     0,    16,    17,    18,   493,    20,    21,
      22,   494,    24,   495,   496,  1151,   498,   421,    30,   499,
      32,    33,    34,     0,    35,    36,    37,    38,   500,    40,
      41,    42,    43,    44,    45,    46,   501,     0,    48,   502,
      50,   503,   504,    53,   505,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,   506,
     507,    71,     0,    72,    73,    74,   508,     0,     0,    77,
      78,    79,     0,     0,   509,    81,     0,     0,     0,     0,
      83,   510,    85,   511,   512,    88,    89,  1638,     0,     0,
       0,     0,     0,     0,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   513,   100,   101,   514,   515,     0,
       0,     0,     0,     0,     0,   104,   105,   106,     0,   108,
     109,  1152,     0,     0,     0,  1153,     0,     0,   116,   516,
       0,     0,     0,   118,   119,   120,   121,   517,   123,   124,
     518,     0,     0,     0,     0,     0,     0,     0,   519,   520,
     131,     0,     0,     0,   132,     0,   133,   521,     0,     0,
       0,     0,     0,     0,   139,     0,   140,   141,   142,   143,
     522,   145,   146,   147,   148,   149,   150,     0,     0,  1154,
     152,     0,     0,   422,   155,   156,   157,   158,   159,   160,
     161,   162,   523,   164,   524,   166,   525,   526,   169,   170,
     171,   172,   173,   174,   527,   176,   528,   529,   530,   180,
     181,   531,   532,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,     0,   197,   198,   199,
       0,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,     0,     0,
       3,     0,   249,   533,   251,  1155,  1156,  1157,  1158,     9,
      10,     0,     0,     0,     0,     0,     0,   419,   420,     0,
      16,    17,    18,   493,    20,    21,    22,   494,    24,   495,
     496,  1151,   498,   421,    30,   499,    32,    33,    34,     0,
      35,    36,    37,    38,   500,    40,    41,    42,    43,    44,
      45,    46,   501,     0,    48,   502,    50,   503,   504,    53,
     505,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,   506,   507,    71,     0,    72,
      73,    74,   508,     0,     0,    77,    78,    79,     0,     0,
     509,    81,     0,     0,     0,     0,    83,   510,    85,   511,
     512,    88,    89,  1642,     0,     0,     0,     0,     0,     0,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
     513,   100,   101,   514,   515,     0,     0,     0,     0,     0,
       0,   104,   105,   106,     0,   108,   109,  1152,     0,     0,
       0,  1153,     0,     0,   116,   516,     0,     0,     0,   118,
     119,   120,   121,   517,   123,   124,   518,     0,     0,     0,
       0,     0,     0,     0,   519,   520,   131,     0,     0,     0,
     132,     0,   133,   521,     0,     0,     0,     0,     0,     0,
     139,     0,   140,   141,   142,   143,   522,   145,   146,   147,
     148,   149,   150,     0,     0,  1154,   152,     0,     0,   422,
     155,   156,   157,   158,   159,   160,   161,   162,   523,   164,
     524,   166,   525,   526,   169,   170,   171,   172,   173,   174,
     527,   176,   528,   529,   530,   180,   181,   531,   532,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,     0,   197,   198,   199,     0,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,     0,     0,     3,     0,   249,   533,
     251,  1155,  1156,  1157,  1158,     9,    10,     0,     0,     0,
       0,     0,     0,   419,   420,     0,    16,    17,    18,   493,
      20,    21,    22,   494,    24,   495,   496,  1151,   498,   421,
      30,   499,    32,    33,    34,     0,    35,    36,    37,    38,
     500,    40,    41,    42,    43,    44,    45,    46,   501,     0,
      48,   502,    50,   503,   504,    53,   505,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,   506,   507,    71,     0,    72,    73,    74,   508,     0,
       0,    77,    78,    79,     0,     0,   509,    81,     0,     0,
       0,     0,    83,   510,    85,   511,   512,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,   513,   100,   101,   514,
     515,     0,     0,     0,     0,     0,     0,   104,   105,   106,
       0,   108,   109,  1152,     0,     0,     0,  1153,     0,     0,
     116,   516,     0,     0,     0,   118,   119,   120,   121,   517,
     123,   124,   518,     0,     0,     0,     0,     0,     0,     0,
     519,   520,   131,     0,     0,     0,   132,     0,   133,   521,
       0,     0,     0,     0,     0,     0,   139,     0,   140,   141,
     142,   143,   522,   145,   146,   147,   148,   149,   150,     0,
       0,  1154,   152,     0,     0,   422,   155,   156,   157,   158,
     159,   160,   161,   162,   523,   164,   524,   166,   525,   526,
     169,   170,   171,   172,   173,   174,   527,   176,   528,   529,
     530,   180,   181,   531,   532,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
       0,     0,     3,     0,   249,   533,   251,  1155,  1156,  1157,
    1158,     9,    10,     0,     0,     0,     0,     0,     0,   419,
     420,     0,    16,    17,    18,   493,    20,    21,    22,   494,
      24,   495,   496,  1151,   498,   421,    30,   499,    32,    33,
      34,     0,    35,    36,    37,    38,   500,    40,    41,    42,
      43,    44,    45,    46,   501,     0,    48,   502,    50,   503,
     504,    53,   505,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,   506,   507,    71,
       0,    72,    73,    74,   508,     0,     0,    77,    78,    79,
       0,     0,   509,    81,     0,     0,     0,     0,    83,   510,
      85,   511,   512,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,   513,   100,   101,   514,   515,     0,     0,     0,
       0,     0,     0,   104,   105,   106,     0,   108,   109,  1152,
       0,     0,     0,  1153,     0,     0,   116,   516,     0,     0,
       0,   118,   119,   120,   121,   517,   123,   124,   518,     0,
       0,     0,     0,     0,     0,     0,   519,   520,   131,     0,
       0,     0,   132,     0,   133,   521,     0,     0,     0,     0,
       0,     0,   139,     0,   140,   141,   142,   143,   522,   145,
     146,   147,   148,   149,   150,     0,     0,   151,   152,     0,
       0,   422,   155,   156,   157,   158,   159,   160,   161,   162,
     523,   164,   524,   166,   525,   526,   169,   170,   171,   172,
     173,   174,   527,   176,   528,   529,   530,   180,   181,   531,
     532,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,     0,   197,   198,   199,     0,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,     0,     0,     3,     0,
     249,   533,   251,  1155,  1156,  1157,  1158,     9,    10,     0,
       0,     0,     0,     0,     0,   419,   420,     0,    16,    17,
      18,   541,    20,    21,    22,   494,   542,   543,   496,   497,
     498,   421,    30,   499,    32,   544,    34,     0,    35,    36,
      37,    38,   545,    40,   546,   547,    43,    44,    45,    46,
     501,     0,    48,   548,    50,   503,   504,    53,   505,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,   506,   507,    71,     0,    72,    73,    74,
     549,     0,     0,    77,    78,    79,     0,     0,   509,    81,
       0,     0,     0,     0,    83,   510,    85,   511,   512,    88,
      89,  1243,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,   513,   100,
     101,   514,   515,     0,     0,     0,     0,     0,     0,   104,
     105,   106,     0,   108,   109,   110,     0,     0,     0,     0,
       0,     0,   116,   516,     0,     0,     0,   118,   119,   120,
     121,   517,   123,   124,   518,     0,     0,     0,     0,     0,
       0,     0,   519,   520,   131,     0,     0,     0,   132,     0,
     133,   521,     0,     0,     0,     0,     0,     0,   139,     0,
     140,   141,   142,   143,   522,   145,   146,   147,   148,   149,
     150,     0,     0,   151,   152,     0,     0,   422,   155,   156,
     157,   158,   159,   160,   161,   162,   523,   550,   524,   166,
     525,   526,   169,   170,   171,   172,   173,   174,   527,   176,
     528,   529,   530,   180,   181,   531,   532,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
       0,   197,   198,   199,     0,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,     0,     0,     3,     0,   249,   533,   251,   252,
     253,   254,   255,     9,    10,     0,     0,     0,     0,     0,
       0,   419,   420,     0,    16,    17,    18,   541,    20,    21,
      22,   494,   542,   543,   496,   497,   498,   421,    30,   499,
      32,   544,    34,     0,    35,    36,    37,    38,   545,    40,
     546,   547,    43,    44,    45,    46,   501,     0,    48,   548,
      50,   503,   504,    53,   505,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,   506,
     507,    71,     0,    72,    73,    74,   549,     0,     0,    77,
      78,    79,     0,     0,   509,    81,     0,     0,     0,     0,
      83,   510,    85,   511,   512,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   513,   100,   101,   514,   515,     0,
       0,     0,     0,     0,     0,   104,   105,   106,     0,   108,
     109,   110,     0,     0,     0,     0,     0,     0,   116,   516,
       0,     0,     0,   118,   119,   120,   121,   517,   123,   124,
     518,     0,     0,     0,     0,     0,     0,     0,   519,   520,
     131,     0,     0,     0,   132,     0,   133,   521,     0,     0,
       0,     0,     0,     0,   139,     0,   140,   141,   142,   143,
     522,   145,   146,   147,   148,   149,   150,     0,     0,   151,
     152,     0,     0,   422,   155,   156,   157,   158,   159,   160,
     161,   162,   523,   550,   524,   166,   525,   526,   169,   170,
     171,   172,   173,   174,   527,   176,   528,   529,   530,   180,
     181,   531,   532,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,     0,   197,   198,   199,
       0,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,     0,     0,
       0,     0,   249,   533,   251,   252,   253,   254,   255,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    13,     0,
       0,   419,   420,     0,    16,    17,    18,   842,    20,    21,
      22,    23,     0,   843,   496,    27,     0,   421,    30,   499,
      32,     0,    34,     0,    35,    36,    37,    38,   844,    40,
       0,     0,    43,    44,    45,    46,   501,     0,    48,   845,
      50,     0,     0,    53,   505,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,   506,
     507,    71,     0,    72,    73,    74,   846,     0,     0,    77,
      78,    79,     0,     0,   509,    81,     0,     0,     0,    82,
      83,   510,    85,   511,   512,    88,    89,   563,    91,     0,
       0,     0,     0,    93,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   513,   100,   101,   514,   515,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,     0,   564,   112,     0,   113,   114,     0,   116,   117,
       0,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     518,     0,   126,     0,     0,     0,     0,     0,   519,   520,
     131,     0,     0,     0,   132,     0,   133,   521,     0,     0,
       0,     0,     0,     0,   139,     0,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,     0,     0,     0,
     152,   153,     0,   422,   155,   156,   157,   158,   159,   160,
     161,   162,   523,     0,   524,   166,   525,   526,   169,   170,
     171,   172,   173,   174,   527,   176,   528,   529,   530,   180,
     181,     0,   532,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,     0,   197,   198,   199,
       0,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,     0,
     248,     9,    10,   533,   251,     0,     0,     0,     0,   419,
     420,     0,    16,    17,    18,     0,    20,    21,    22,   494,
       0,     0,   496,   497,     0,   421,    30,   499,    32,     0,
      34,     0,    35,    36,    37,    38,     0,    40,     0,     0,
      43,    44,    45,    46,   501,     0,    48,     0,    50,     0,
       0,    53,   505,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,   506,   507,    71,
       0,    72,    73,    74,     0,     0,     0,    77,    78,    79,
       0,     0,   509,    81,     0,     0,     0,     0,    83,   510,
      85,   511,   512,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,   513,   100,   101,   514,   515,     0,     0,     0,
       0,     0,     0,   104,   105,   106,     0,   108,   109,     0,
       0,     0,     0,     0,     0,     0,   116,   516,     0,     0,
       0,   118,   119,   120,   121,   517,   123,   124,   518,     0,
       0,     0,     0,     0,     0,     0,   519,   520,   131,     0,
       0,     0,   132,     0,   133,   521,     0,     0,     0,     0,
       0,     0,   139,     0,   140,   141,   142,   143,   522,   145,
     146,   147,   148,   149,   150,     0,     0,     0,   152,     0,
       0,   422,   155,   156,   157,   158,   159,   160,   161,   162,
     523,     0,   524,   166,   525,   526,   169,   170,   171,   172,
     173,   174,   527,   176,   528,   529,   530,   180,   181,     0,
     532,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,     0,   197,   198,   199,     0,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,     0,     0,     0,     0,
       0,   533,   251
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,   316,   183,   430,   431,     5,     6,     7,     8,     5,
       6,     7,    76,   695,   679,   316,     0,     5,     6,     7,
       8,     5,     6,     7,     8,    14,    90,   346,   770,  1284,
     785,   917,   829,     5,     6,     7,     8,   680,   681,   682,
     683,  1301,  1056,   798,   263,   623,   624,   866,  1040,   432,
     114,   590,   770,   112,   113,     1,   595,   812,   621,   622,
     623,   624,   126,    76,   128,  1137,  1365,  1366,     1,   621,
     622,   137,   295,   953,  1003,  1497,   264,     1,  1500,  1080,
     256,   257,    36,    39,   467,   468,   727,  1021,    44,    45,
    1412,   279,    27,    28,   119,    36,     1,    53,   930,   931,
     119,    30,  1314,     1,    60,     1,    62,    63,    31,    27,
      28,   111,    47,   286,    52,    71,     9,    10,     1,    56,
       8,   108,    57,   111,   225,   225,     1,   111,   148,    47,
       1,   658,     1,   660,   661,   108,   663,     1,   665,   111,
      75,    95,    98,    97,   969,    80,   673,   674,   119,    97,
     119,     1,     1,   225,   137,   227,    97,    75,   353,   145,
     186,   356,   108,     1,   217,    30,   114,     1,   187,   159,
       1,   930,   931,   137,   225,   108,   227,   112,   113,   114,
       0,     1,   111,  1607,   210,    45,   176,   151,   247,   248,
     176,  1023,   130,     1,   148,   113,   125,   119,  1030,    33,
     225,   254,   425,    63,     0,     1,   429,   148,   194,   157,
     969,   104,    30,   314,   314,   186,     1,   186,   201,   161,
     975,   150,     1,   143,     1,   154,    37,    38,   157,    40,
      41,   124,     1,   126,   148,     1,   295,   108,     1,   108,
       1,  1540,   314,    55,  1003,    57,   233,    58,   177,   114,
       1,  1137,  1138,   273,   569,  1510,   256,   257,   108,   108,
     260,   154,   235,   314,  1023,   158,   190,  1281,   569,   225,
     108,  1030,   256,   257,  1029,  1267,   260,   108,   451,  1076,
     217,   174,   307,   349,  1606,   190,  1028,   175,   108,   101,
     354,   214,   190,   357,   190,   295,   161,   875,   876,  1721,
     108,  1513,   195,   114,  1305,  1234,  1186,   190,  1026,  1243,
    1028,   295,   108,  1314,   955,   190,  1388,   254,   187,   273,
     213,   873,   874,   108,  1042,    95,   190,   187,  1153,   108,
     259,   108,   273,  1757,   557,     1,     1,   187,   187,   108,
       1,   354,   108,   161,   357,   108,  1768,   108,  1770,   187,
     161,   273,   287,   273,   157,   738,   187,   108,   108,   273,
     295,   317,   318,   319,   184,    33,   425,   313,   303,   287,
     429,   108,   436,   437,  1129,     1,   440,   295,   311,   187,
     444,    49,    95,   447,   448,   625,   913,     1,   184,   629,
      97,   455,    94,    45,  1153,    47,   122,   461,   462,   184,
     783,   460,   621,   622,    97,   469,   465,  1706,   187,   220,
     187,   108,   476,   477,   478,   479,   475,   157,   187,   185,
     484,   644,   185,   482,   483,   425,   187,  1259,   492,   429,
     618,   619,   491,     1,   610,     1,   187,    97,   188,   251,
     628,   425,   108,   108,   101,   429,   154,   108,   218,   219,
     261,   188,   264,     5,   266,   107,   456,     9,   458,   108,
       1,  1760,   169,   233,     1,   277,   278,   279,   456,   281,
     458,   283,   456,   537,   458,  1234,   169,   108,  1233,    97,
     480,   183,   108,  1743,   456,   485,   458,   184,   552,   108,
     917,   119,   480,   155,   108,   157,   480,   485,   557,   563,
    1259,   485,  1388,  1245,    77,   218,   219,   233,   480,    27,
      28,  1397,  1513,   485,   573,   574,   168,   157,   184,   184,
     233,   948,  1408,   184,  1283,   584,   590,   108,  1347,   186,
     148,   595,  1351,  1788,   598,     3,  1254,  1115,  1116,  1117,
     108,   190,   108,   602,   603,   252,   253,  1229,   255,     9,
     101,   108,  1115,  1116,  1117,   262,   187,   557,   184,   252,
     253,  1100,   255,   114,   564,   272,   159,   108,   187,    29,
     184,   108,   124,   557,   126,   237,   564,   284,    30,   272,
     564,   154,   134,   176,     9,    10,   108,     9,  1420,   131,
     654,   284,   564,   976,   977,   113,   256,   257,   981,    67,
    1668,   108,   154,   603,    72,   131,   187,    29,     9,    10,
     610,   132,    95,   108,  1369,   225,   184,    97,   184,   603,
     230,   621,   622,   623,   624,     5,   610,   616,  1011,     9,
     187,   603,  1624,   699,   700,     9,    10,   621,   622,   623,
     624,   864,   701,   184,   644,   138,   166,   184,   221,   222,
     143,   119,   108,   154,   873,   197,   123,   108,   108,   111,
     644,  1420,   182,   108,   124,   187,   126,   731,   891,   190,
     734,   197,   155,   125,   157,   135,   269,   157,  1746,   104,
     187,   138,   154,   276,   748,    45,   157,    47,   752,   753,
    1576,   879,   187,   286,   154,   883,   696,   154,   150,   124,
     696,   126,   124,   104,   126,   177,   118,   771,   696,   210,
    1137,  1138,   696,   135,  1511,   779,    95,    42,   782,  1516,
      80,    46,   786,   124,   696,   126,    51,  1469,  1742,   154,
     104,   187,   154,   158,  1399,   147,   187,   187,  1497,    97,
     154,  1500,   187,   154,   124,    70,   126,   107,   160,   174,
     124,   149,   126,   154,   134,   149,   114,   158,     1,    97,
       3,   820,   821,   822,   828,   824,   177,   165,    30,   148,
     195,   165,  1454,   174,   154,   775,  1354,    95,   169,   775,
     154,   138,   194,   123,   158,    54,   143,   775,   213,    95,
      59,   775,    95,    54,   195,   107,   210,    95,    59,   157,
     174,   157,   866,   775,  1636,   864,   806,   807,   168,    78,
     148,   202,   213,   123,  1733,  1734,   128,    95,   806,   807,
    1139,   195,   806,   807,    67,  1017,     1,  1019,    97,    72,
     148,   895,   138,   201,   806,   807,    97,   143,   138,   213,
     143,   905,   210,   168,   154,   143,   171,   157,   157,   111,
     119,  1648,   157,   269,   154,  1652,  1775,  1689,    33,  1691,
     276,   186,  1781,   125,   864,   143,   930,   931,   932,   933,
     286,  1063,   159,  1065,    49,    25,   119,  1636,    95,  1262,
     864,    97,  1105,   159,    34,   247,   248,   212,   150,   176,
     107,   891,   154,    96,   157,   157,   885,   101,   114,   182,
     176,    54,  1567,  1568,   107,   969,    59,   891,   270,   268,
     114,    61,   199,   196,   117,   177,   275,  1560,  1106,   983,
     101,   101,  1754,   199,  1112,   128,   966,  1609,  1109,   182,
    1689,   146,  1691,   114,   114,   101,   101,   157,   978,   263,
    1737,   263,   157,   196,  1008,   299,   191,   192,   114,   114,
     274,  1706,   274,  1017,   308,  1019,   155,  1021,   157,  1023,
     154,  1388,  1721,   157,   154,  1280,  1030,   157,   154,   154,
    1397,   157,   157,   277,   278,   279,   123,   702,  1361,   283,
     705,  1408,   119,   708,   221,   222,   223,  1370,   232,   157,
     234,   232,   123,   234,   123,  1754,   129,   130,   119,  1063,
     123,  1065,   129,   130,    90,   677,   678,   684,   685,  1768,
     123,  1770,  1677,  1678,   154,   686,   687,  1227,  1228,   154,
    1597,  1598,   123,  1338,   123,   123,   123,   216,   114,  1711,
     154,  1346,   157,   241,   119,   241,  1100,   242,  1261,   157,
     126,   314,   128,   154,     0,  1346,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,   190,   167,  1058,    93,
     100,  1125,   249,    50,   200,   102,   155,   103,   184,   157,
    1058,   193,   184,    30,  1058,   184,  1758,  1136,   184,    47,
     153,   119,   246,   133,   187,  1750,  1058,   154,     1,  1153,
     304,   141,   142,   119,   144,  1478,   143,   108,   154,   154,
     187,   143,   152,   187,   157,  1105,   156,   184,   158,   157,
     122,   157,   157,   163,   157,  1115,  1116,  1117,   157,    35,
      17,  1105,   154,   214,   157,  1114,   157,    30,   190,   179,
     190,  1115,  1116,  1117,     3,   231,   119,   245,   168,   284,
     284,   170,   170,   119,    71,    95,    95,    95,  1830,  1576,
    1832,   231,   150,   203,   204,   205,   206,   207,   208,    30,
    1842,   108,  1343,   187,   108,   161,   161,   128,   133,    95,
     246,  1486,   143,  1488,   119,   133,  1491,  1492,   184,  1243,
    1495,   184,   299,  1247,   108,   187,  1501,   187,    95,    97,
      45,    97,   184,   187,   187,  1259,   187,   187,   184,   154,
     154,   154,   154,   154,    95,   143,   190,    33,   154,  1273,
     237,   233,   184,   133,   143,    95,    30,   286,   227,  1283,
      95,   299,   154,   128,   119,   148,   119,   170,    95,   198,
     161,   133,   133,    97,   119,   154,   148,  1237,   101,   101,
     154,  1237,   184,   184,   184,   143,   122,    35,  1312,  1237,
     154,   190,    30,  1237,   119,    80,   245,   108,   107,   258,
     108,  1261,   285,   260,   145,  1237,   254,  1490,   157,   157,
     157,   157,  1272,  1337,   157,   157,  1272,  1261,   157,    30,
      30,   286,   267,  1347,  1272,    30,   287,  1351,  1272,   306,
     227,  1291,   145,   187,   190,  1291,   148,   187,   128,   108,
    1272,   148,   143,  1291,   101,   133,   198,  1291,     7,   187,
    1533,  1311,   184,   187,   187,  1379,   233,   187,  1318,  1291,
      97,   157,   190,  1311,  1639,   186,   237,  1311,  1643,   148,
    1318,   154,   107,   233,  1318,   157,   157,   119,   119,  1311,
      78,   187,   148,    79,   187,   187,  1318,   282,   187,   233,
    1350,   437,   286,   187,   440,   187,  1420,    30,   444,    30,
     187,   447,   448,   187,   108,   170,  1350,   233,   184,   455,
     127,   127,   271,   250,   148,   461,   462,   148,  1350,    97,
     184,   184,   184,   469,   184,   143,  1450,   154,   316,   184,
     476,   477,   478,   479,   250,    95,   187,   257,   484,  1622,
      30,    97,   187,    95,   170,   148,   492,   197,    54,    95,
    1633,  1634,  1727,    30,  1637,   265,   119,   108,   108,    95,
      95,  1644,   280,   183,   225,   197,   119,   197,   287,   198,
    1494,   119,   225,  1497,    94,   197,  1500,   119,   119,   293,
     199,   225,   287,   263,   737,   119,  1189,   970,  1512,    27,
      28,   537,  1767,  1517,   431,  1031,  1771,  1711,  1234,    37,
      38,   305,    40,    41,   260,   305,   552,   305,   111,    47,
     451,  1530,  1531,  1532,   260,   306,  1758,   563,   867,    57,
      58,  1134,   654,  1553,  1121,  1380,  1550,  1551,  1803,   306,
    1490,  1806,   788,   306,  1372,  1368,  1278,    75,  1365,  1273,
     552,  1281,    80,  1286,   656,   676,  1490,  1730,   657,   933,
     711,  1305,   598,   829,  1829,  1781,  1775,  1019,  1188,  1348,
    1337,  1347,  1408,   341,  1576,  1397,   459,  1138,  1573,   459,
    1147,  1401,  1002,  1533,   112,   113,   114,  1211,  1444,  1600,
    1398,    -1,   593,    -1,    -1,    -1,  1769,    -1,    -1,  1533,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1787,    -1,    -1,    -1,   654,    -1,
      -1,    -1,  1636,    -1,  1638,    -1,  1640,    -1,  1642,  1802,
      -1,    -1,    -1,   161,    -1,  1649,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1824,    -1,    -1,    -1,    -1,  1665,    -1,    -1,    -1,
    1833,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1622,    -1,    -1,  1689,    -1,  1691,  1687,    -1,
      -1,    -1,    -1,  1633,  1634,    -1,    -1,  1637,  1622,    -1,
      -1,    -1,   220,  1707,  1644,    -1,  1710,    -1,   734,  1633,
    1634,    -1,    -1,  1637,    -1,    -1,    -1,  1721,    -1,    -1,
    1644,    -1,   748,    -1,    -1,    -1,   752,   753,  1732,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   261,    -1,   771,    -1,    -1,    -1,    -1,
    1754,    -1,    -1,   779,    -1,    -1,   782,    -1,  1762,    -1,
     786,    -1,    -1,    -1,  1768,    -1,  1770,    -1,    -1,   287,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   295,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   303,    -1,  1791,    -1,    -1,
    1730,    -1,    -1,    -1,    -1,    -1,  1800,    -1,    -1,    -1,
      -1,    -1,   828,    -1,    -1,    -1,  1730,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1820,    -1,    -1,    -1,
      -1,  1825,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1769,
      -1,    -1,    -1,  1837,    -1,    -1,  1840,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1769,    -1,  1787,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1802,  1787,    -1,    -1,    -1,    -1,    -1,   895,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1802,   905,
      -1,    -1,    -1,    -1,  1824,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1833,    -1,    -1,    -1,    -1,    -1,    -1,
    1824,    -1,    -1,    -1,   930,   931,   932,   933,    -1,  1833,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   969,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   983,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   564,  1008,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1017,    -1,  1019,    -1,  1021,    -1,  1023,    -1,    -1,
      -1,    -1,    -1,    -1,  1030,   588,   589,    -1,   591,   592,
     593,   594,    -1,   596,    -1,    -1,    -1,    -1,   601,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   609,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1063,    -1,  1065,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   631,   632,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   641,    -1,
      -1,   644,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1125,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   707,    -1,    -1,  1153,   711,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   750,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   787,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1243,    -1,    -1,
      -1,  1247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     813,    -1,    -1,  1259,   817,   818,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   826,    -1,    -1,    -1,  1273,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1283,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1312,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   891,    -1,
      -1,  1337,    -1,    -1,   897,   898,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1379,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   971,    -1,
      -1,    -1,    -1,    -1,  1420,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1006,  1450,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1025,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1041,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1494,  1052,
    1053,  1497,    -1,    -1,  1500,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1067,    -1,  1512,  1070,    -1,    -1,
      -1,  1517,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1087,  1088,  1089,    -1,  1091,  1092,
    1093,  1094,  1095,  1096,  1097,  1098,  1099,    -1,    -1,  1102,
    1103,    -1,    -1,    -1,  1550,  1551,    -1,    -1,  1111,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1121,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1176,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1636,    -1,  1638,    -1,  1640,    -1,  1642,    -1,    -1,    -1,
      -1,    -1,    -1,  1649,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1689,    -1,  1691,  1249,    -1,  1251,    -1,
    1253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1261,    -1,
      -1,  1707,    -1,    -1,  1710,    -1,    -1,  1270,    -1,    -1,
      -1,    -1,    -1,  1276,  1277,  1721,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1732,    -1,    -1,    -1,
      -1,    -1,  1295,    -1,    -1,  1298,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1754,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1762,    -1,    -1,    -1,
      -1,    -1,  1768,    -1,  1770,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1791,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1800,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1368,    -1,    -1,    -1,  1372,
    1373,    -1,    -1,    -1,  1820,  1378,    -1,    -1,    -1,  1825,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1837,    -1,    -1,  1840,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1463,    -1,    -1,    -1,  1467,    -1,    -1,    -1,  1471,    -1,
    1473,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1481,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1489,  1490,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1509,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1521,  1522,
    1523,  1524,    -1,  1526,  1527,    -1,  1529,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1544,    -1,    -1,    -1,    -1,  1549,    -1,    -1,    -1,
      -1,    -1,  1555,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1615,    -1,  1617,    -1,    -1,  1620,    -1,    -1,
    1623,    -1,    -1,    -1,    -1,  1628,  1629,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1637,    -1,    -1,    -1,  1641,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1658,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1669,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1714,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1726,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1769,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,
       1,    -1,    -1,    -1,    -1,  1798,    -1,    -1,    -1,  1802,
      11,    12,    -1,    -1,  1807,    16,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
    1823,    -1,    33,    34,  1827,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    95,    96,    97,    98,    99,    -1,
     101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,
      -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,   140,
      -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,   157,   158,   159,   160,
     161,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,   190,
     191,   192,    -1,   194,    -1,   196,    -1,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,    -1,    -1,
     211,   212,   213,    -1,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,   259,   260,
     261,    -1,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
      -1,   312,    -1,   314,   315,   316,   317,   318,   319,   320,
       0,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      30,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    99,
      -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,    -1,    -1,    -1,   125,    -1,   127,   128,   129,
     130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,
     140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,
     150,   151,   152,   153,   154,   155,    -1,   157,   158,   159,
     160,   161,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,
     190,   191,   192,    -1,   194,    -1,   196,    -1,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,    -1,
      -1,   211,   212,   213,    -1,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,    -1,   259,
     260,   261,    -1,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,     1,   312,    -1,   314,   315,   316,   317,   318,   319,
     320,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      30,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    99,
      -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,    -1,    -1,    -1,   125,    -1,   127,   128,   129,
     130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,
     140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,
     150,   151,   152,   153,   154,   155,    -1,   157,   158,   159,
     160,   161,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,
     190,   191,   192,    -1,   194,    -1,   196,    -1,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,    -1,
      -1,   211,   212,   213,    -1,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,    -1,   259,
     260,   261,    -1,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,     1,   312,    -1,   314,   315,   316,   317,   318,   319,
     320,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    99,
      -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,    -1,    -1,    -1,   125,    -1,   127,   128,   129,
     130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,
     140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,
     150,   151,   152,   153,   154,   155,    -1,   157,   158,   159,
     160,   161,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,
      -1,   191,   192,    -1,   194,    -1,   196,    -1,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,    -1,
      -1,   211,   212,   213,    -1,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,    -1,   259,
     260,   261,    -1,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,    -1,   312,    -1,   314,   315,   316,   317,   318,   319,
     320,     0,     1,    -1,     3,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    50,    51,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    -1,    95,    96,    97,    -1,
      -1,   100,   101,   102,   103,    -1,    -1,    -1,   107,   108,
      -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,   117,   118,
     119,    -1,    -1,   122,    -1,    -1,    -1,    -1,   127,   128,
      -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,   137,    -1,
      -1,    -1,   141,   142,    -1,   144,    -1,   146,   147,    -1,
      -1,    -1,   151,   152,    -1,    -1,   155,   156,   157,   158,
     159,   160,    -1,    -1,   163,    -1,    -1,    -1,   167,   168,
      -1,    -1,   171,    -1,    -1,    -1,    -1,   176,    -1,    -1,
     179,    -1,    -1,    -1,    -1,   184,   185,   186,   187,   188,
      -1,   190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,
     199,   200,   201,    -1,   203,   204,   205,   206,   207,   208,
      -1,   210,    -1,   212,    -1,    -1,    -1,    -1,   217,   218,
     219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   233,    -1,   235,    -1,   237,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    11,    12,    -1,    -1,    -1,    16,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    28,   311,    30,   313,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    95,    96,
      97,    98,    99,    -1,   101,   102,   103,    -1,    -1,   106,
     107,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,    -1,    -1,    -1,   125,    -1,
     127,   128,   129,   130,    -1,   132,    -1,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,
     147,   148,   149,   150,   151,   152,   153,   154,   155,    -1,
     157,   158,   159,   160,   161,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,   174,    -1,   176,
     177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
      -1,   188,   189,   190,   191,   192,    -1,   194,    -1,   196,
      -1,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,    -1,    -1,   211,   212,   213,    -1,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,    -1,   259,   260,   261,    -1,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,    -1,   312,    -1,   314,   315,   316,
     317,   318,   319,   320,   321,   322,    11,    12,    -1,    -1,
      -1,    16,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    30,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    -1,
      95,    96,    97,    98,    99,    -1,   101,   102,   103,    -1,
      -1,   106,   107,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
     125,    -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,   157,   158,   159,   160,   161,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,    -1,   188,   189,   190,   191,   192,    -1,   194,
      -1,   196,    -1,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,    -1,   211,   212,   213,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    -1,   312,    -1,   314,
     315,   316,   317,   318,   319,   320,    -1,   322,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,   157,   158,   159,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,   182,
      -1,   184,    -1,   186,    -1,   188,   189,   190,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,   157,   158,   159,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,   182,
      -1,   184,    -1,   186,    -1,   188,   189,   190,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,   157,   158,   159,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,   182,
      -1,   184,    -1,   186,    -1,   188,   189,   190,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,   157,   158,   159,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,   190,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,   157,   158,   159,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,   190,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,   157,   158,   159,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,   190,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,   157,   158,   159,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,   190,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,   157,   158,   159,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,   190,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,   157,   158,   159,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,   190,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,   145,    -1,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,   157,   158,   159,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,   187,   188,   189,    -1,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,   145,    -1,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,   157,   158,   159,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,   187,   188,   189,    -1,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,   157,   158,   159,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,   182,
      -1,    -1,   185,   186,    -1,   188,   189,    -1,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,   157,   158,   159,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,   187,   188,   189,    -1,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,   157,   158,   159,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,   157,   158,   159,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
     313,   314,   315,   316,   317,   318,   319,   320,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,   145,    -1,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,   157,   158,   159,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,   157,   158,   159,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,   157,   158,   159,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,   157,   158,   159,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,   157,   158,   159,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,   157,   158,    -1,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,   157,   158,    -1,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,    -1,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,    -1,   152,
     153,   154,   155,    -1,   157,   158,    -1,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,
      -1,   194,    -1,   196,    -1,   198,    -1,   200,    -1,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    -1,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,   112,
     113,   114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,    -1,   151,   152,
     153,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
      -1,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,    -1,    -1,    -1,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    -1,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,   112,
     113,   114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,    -1,   151,   152,
     153,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
      -1,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,    -1,    -1,    16,
      -1,   314,   315,   316,   317,   318,   319,   320,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    95,    96,
      97,    98,    -1,    -1,   101,   102,   103,    -1,    -1,   106,
     107,    -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,
     117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     127,   128,   129,   130,    -1,   132,    -1,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,
     147,   148,   149,    -1,   151,   152,   153,    -1,    -1,    -1,
     157,    -1,    -1,   160,   161,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
     187,   188,   189,    -1,    -1,    -1,    -1,   194,    -1,   196,
      -1,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,    -1,    -1,   211,   212,    -1,    -1,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,    -1,   259,   260,   261,    -1,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,    -1,    -1,    -1,    -1,   314,   315,   316,
     317,   318,   319,   320,    16,    -1,    18,    19,    -1,    -1,
      -1,    -1,    -1,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    97,    98,    -1,    -1,   101,
     102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,    -1,   151,
     152,   153,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,
      -1,    -1,    -1,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,    -1,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,    -1,    -1,
      16,    -1,   314,   315,   316,   317,   318,   319,   320,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    95,
      96,    97,    98,    -1,    -1,   101,   102,   103,    -1,    -1,
     106,   107,    -1,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,    -1,
     136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,
      -1,   147,   148,   149,    -1,   151,   152,   153,    -1,    -1,
      -1,    -1,    -1,    -1,   160,   161,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,   187,   188,   189,    -1,    -1,    -1,    -1,   194,    -1,
     196,    -1,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    -1,    -1,   211,   212,    -1,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,    -1,    -1,    16,    -1,   314,   315,
     316,   317,   318,   319,   320,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    -1,
      -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,   129,
     130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,
     140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,
      -1,   151,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,
     160,   161,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,   187,   188,   189,
      -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,    -1,
      -1,   211,   212,    -1,    -1,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,    -1,   259,
     260,   261,    -1,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
      -1,    -1,    16,    -1,   314,   315,   316,   317,   318,   319,
     320,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    95,    96,    97,    98,    -1,    -1,   101,   102,   103,
      -1,    -1,   106,   107,    -1,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   127,   128,   129,   130,    -1,   132,    -1,
      -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,
      -1,    -1,    -1,   147,   148,   149,    -1,   151,   152,   153,
      -1,    -1,    -1,    -1,    -1,    -1,   160,   161,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,
      -1,    -1,   186,   187,   188,   189,    -1,    -1,    -1,    -1,
     194,    -1,   196,    -1,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,    -1,    -1,   211,   212,    -1,
      -1,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,    -1,    -1,    16,    -1,
     314,   315,   316,   317,   318,   319,   320,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    96,    97,
      98,    -1,    -1,   101,   102,   103,    -1,    -1,   106,   107,
      -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,
     128,   129,   130,    -1,   132,    -1,    -1,    -1,   136,   137,
     138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,
     148,   149,    -1,   151,   152,   153,    -1,    -1,    -1,   157,
      -1,    -1,   160,   161,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,
     188,   189,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,    -1,    -1,   211,   212,    -1,    -1,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
      -1,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,    -1,    -1,    16,    -1,   314,   315,   316,   317,
     318,   319,   320,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    97,    98,    -1,    -1,   101,
     102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,   118,   119,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,    -1,   151,
     152,   153,    -1,    -1,    -1,   157,    -1,    -1,   160,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,
      -1,    -1,    -1,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,    -1,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,    -1,    -1,
      16,    -1,   314,   315,   316,   317,   318,   319,   320,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    95,
      96,    97,    98,    -1,    -1,   101,   102,   103,    -1,    -1,
     106,   107,    -1,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,   119,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,    -1,
     136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,
      -1,   147,   148,   149,    -1,   151,   152,   153,    -1,    -1,
      -1,   157,    -1,    -1,   160,   161,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,    -1,
     196,    -1,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    -1,    -1,   211,   212,    -1,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,    -1,    -1,    16,    -1,   314,   315,
     316,   317,   318,   319,   320,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    -1,
      -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,   129,
     130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,
     140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,
      -1,   151,   152,   153,    -1,    -1,    -1,   157,    -1,    -1,
     160,   161,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,
      -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,    -1,
      -1,   211,   212,    -1,    -1,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,    -1,   259,
     260,   261,    -1,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
      -1,    -1,    16,    -1,   314,   315,   316,   317,   318,   319,
     320,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    95,    96,    97,    98,    -1,    -1,   101,   102,   103,
      -1,    -1,   106,   107,    -1,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   127,   128,   129,   130,    -1,   132,    -1,
      -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,
      -1,    -1,    -1,   147,   148,   149,    -1,   151,   152,   153,
      -1,    -1,    -1,   157,    -1,    -1,   160,   161,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,
      -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,    -1,
      -1,    -1,   196,    -1,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,    -1,    -1,   211,   212,    -1,
      -1,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,    -1,    -1,    16,    -1,
     314,   315,   316,   317,   318,   319,   320,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    96,    97,
      98,    -1,    -1,   101,   102,   103,    -1,    -1,   106,   107,
      -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,
     128,   129,   130,    -1,   132,    -1,    -1,    -1,   136,   137,
     138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,
     148,   149,    -1,   151,   152,   153,    -1,    -1,    -1,    -1,
      -1,    -1,   160,   161,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,
     188,   189,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,    -1,    -1,   211,   212,    -1,    -1,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
      -1,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,    -1,    -1,    16,    -1,   314,   315,   316,   317,
     318,   319,   320,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    97,    98,    -1,    -1,   101,
     102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,    -1,   151,
     152,   153,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,
      -1,    -1,    -1,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,    -1,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,    -1,    -1,
      -1,    -1,   314,   315,   316,   317,   318,   319,   320,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    45,    46,    47,    -1,    49,    50,    51,
      52,    -1,    54,    -1,    56,    57,    58,    59,    60,    61,
      -1,    -1,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    -1,    -1,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    97,    98,    -1,    -1,   101,
     102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,
     152,    -1,   154,   155,    -1,   157,   158,    -1,   160,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,
      -1,    -1,    -1,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,    -1,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,    -1,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    25,    26,   315,   316,    -1,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    -1,    40,    41,    42,    43,
      -1,    -1,    46,    47,    -1,    49,    50,    51,    52,    -1,
      54,    -1,    56,    57,    58,    59,    -1,    61,    -1,    -1,
      64,    65,    66,    67,    68,    -1,    70,    -1,    72,    -1,
      -1,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    95,    96,    97,    -1,    -1,    -1,   101,   102,   103,
      -1,    -1,   106,   107,    -1,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   127,   128,   129,   130,    -1,   132,    -1,
      -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,
      -1,    -1,    -1,   147,   148,   149,    -1,   151,   152,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   160,   161,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,
      -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,    -1,
      -1,    -1,   196,    -1,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,    -1,    -1,    -1,   212,    -1,
      -1,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,    -1,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,    -1,    -1,    -1,    -1,
      -1,   315,   316
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,    11,    12,    16,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    30,    33,    34,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    95,    96,    97,    98,    99,   101,   102,   103,
     106,   107,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   125,   127,   128,   129,   130,   132,   136,
     137,   138,   139,   140,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   157,   158,   159,   160,   161,   165,   166,
     167,   168,   169,   170,   171,   172,   174,   176,   177,   180,
     181,   182,   186,   188,   189,   190,   191,   192,   194,   196,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   211,   212,   213,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   259,   260,   261,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   312,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   335,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   356,   357,   358,   359,
     360,   361,   365,   366,   367,   371,   373,   374,   376,   383,
     385,   388,   389,   390,   392,   393,   394,   395,   396,   398,
     399,   401,   402,   403,   404,   405,   406,   408,   409,   412,
     413,   414,   415,   416,   422,   424,   426,   427,   428,   433,
     452,   455,   459,   462,   463,   469,   470,   471,   472,   474,
     475,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     487,   488,   489,   490,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,   505,   506,   507,   508,
     509,   510,   513,   514,   515,   516,   517,   518,   519,   520,
     521,   523,   524,   525,   526,   527,   528,   542,   543,   545,
     546,   547,   548,   549,   550,   551,   552,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   574,
     579,   580,   581,   582,   583,   584,   587,   645,   646,   647,
     648,   650,   651,   652,   653,   654,   657,   658,   659,    33,
      34,    49,   215,   391,   392,   393,   391,   391,   392,   393,
     157,   157,    37,    38,    40,    41,    47,    57,    58,    75,
      80,   112,   113,   114,   161,   220,   261,   287,   295,   303,
     372,   373,   377,   378,   379,   161,   154,   157,   154,   157,
     154,   157,     1,   157,   380,   157,    25,    34,    61,   119,
     273,   432,   434,   435,   157,   154,   157,   157,   157,   119,
     154,   157,   157,   157,    77,   154,   221,   222,   123,   123,
     123,   154,   157,    39,    43,    45,    46,    47,    48,    51,
      60,    68,    71,    73,    74,    76,    91,    92,    98,   106,
     113,   115,   116,   136,   139,   140,   161,   169,   172,   180,
     181,   189,   202,   224,   226,   228,   229,   236,   238,   239,
     240,   243,   244,   315,   507,   658,   123,   119,   400,   123,
     123,    39,    44,    45,    53,    60,    62,    63,    71,    98,
     225,   657,   119,   123,   123,   184,   391,   393,   414,   649,
      48,    73,    74,   119,   154,   185,   244,   413,   415,   426,
     187,   413,   657,   154,   154,   123,   657,    18,    19,   657,
     123,   123,   123,   499,   154,    31,   214,   216,   225,   227,
     314,   225,   227,   314,   225,   314,   225,   230,   119,   241,
     241,   242,   157,   154,   395,   311,   413,   313,   413,   314,
     322,   337,   337,     0,   339,   340,    33,    49,   342,   359,
       1,   190,   336,   190,   336,   113,   374,   394,   413,   108,
     190,   108,   336,   190,    42,    46,    51,    70,   168,   171,
     186,   212,   407,   417,   418,   423,   424,   425,   440,   441,
     445,     3,    67,    72,   119,   419,   167,    93,   133,   141,
     142,   144,   152,   156,   158,   163,   179,   203,   204,   205,
     206,   207,   208,   491,   492,   249,   100,   159,   176,   199,
     118,   147,   160,   194,   201,   210,   137,   151,    50,   200,
     102,   103,   159,   176,   489,   193,   154,   496,   499,   191,
     192,   155,   511,   512,   507,   511,   507,   157,   511,   157,
     146,   157,   184,   184,   184,   184,   375,   514,   375,    30,
     656,   182,   196,   182,   196,   166,   182,   658,   657,   169,
     202,    47,   657,   153,   119,    45,    47,    80,   107,   168,
     657,   221,   222,   223,   246,   618,   657,   657,   304,   138,
     143,   113,   287,   295,   377,   657,   392,   187,   392,    45,
      63,   187,   570,   571,   413,   187,   194,   657,   429,   430,
     657,   119,   187,   381,   382,   154,   397,   413,     1,   161,
     656,   114,   161,   355,   656,   657,   119,   143,   108,   187,
     413,    30,   187,   657,   657,   657,   453,   454,   657,   392,
     187,   413,   413,   572,   657,   392,   154,   154,   413,   187,
     194,   657,   657,   143,   453,   184,   184,   122,   108,   184,
     157,   157,   157,   657,   154,   185,   418,   187,    35,   530,
     531,   532,   413,   413,     8,   175,    17,   413,   214,    30,
     414,   414,    39,    45,    60,    71,    98,   510,   658,   414,
     414,   414,   649,   414,   510,   414,   231,   585,   586,   657,
     190,   190,   414,   413,   393,   413,   245,   410,   411,   311,
     313,   414,   337,   190,   336,   190,   336,     3,   343,   359,
     389,     1,   343,   359,   389,    33,   360,   389,   360,   389,
     400,   336,   400,   414,   414,   119,   168,   170,   170,   414,
     394,   414,   284,   284,   429,   119,   436,   471,   472,   474,
     474,   474,   474,   473,   474,   474,   474,    71,   475,   479,
     479,   478,   480,   480,   480,   480,   481,   481,   482,   482,
     231,    95,    95,    95,   497,   391,   499,   499,   413,   512,
     145,   187,   414,   522,   187,   150,   187,   522,   108,   187,
     187,   108,   108,   380,    30,   658,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,   362,   363,   364,    95,
     138,   143,   368,   369,   370,   657,   161,   161,   362,   656,
     128,   133,    55,    57,   101,   251,   264,   266,   277,   278,
     279,   281,   283,   619,   620,   621,   622,   623,   624,   631,
     637,   638,   246,    95,   299,   657,   143,   414,   119,   657,
     657,   133,   184,   184,   187,   187,   184,   108,   187,   108,
     187,   108,    36,    95,    97,   148,   431,   432,   553,   657,
      95,   108,   187,   391,   187,   657,    97,    45,   657,   656,
      97,   143,   553,   657,   414,   435,   184,   187,   187,   187,
     187,   108,   188,   148,   553,   184,   187,   187,   154,   184,
     392,   392,   184,   108,   187,   108,   187,   143,   553,   414,
     188,   414,   414,   413,   413,   413,   657,   531,   532,   131,
     197,   184,   184,   184,   132,   190,    95,   218,   219,   233,
      95,   218,   219,   233,   233,   233,    95,    95,   237,   225,
     314,   108,   235,   143,   190,   187,   413,   184,   508,   591,
     411,   233,   359,    33,    33,   190,   336,   190,   114,   394,
     657,   170,   414,   446,   447,   119,   414,   442,   443,   657,
      56,   217,   254,   420,   421,   474,   154,   157,   259,   495,
     514,   592,   595,   596,   597,   598,   599,   603,   605,   607,
     608,    47,   153,   157,   211,   317,   318,   319,   320,   554,
     556,   558,   560,   575,   576,   577,   578,   655,   657,   554,
     486,   559,   657,   486,   184,   185,   108,   187,   187,   514,
     149,   165,   149,   165,   138,   397,   380,   363,   133,   556,
     370,   414,   553,   656,   656,   129,   130,   656,   277,   278,
     279,   283,   657,   263,   274,   263,   274,    30,   286,    97,
     114,   157,   625,   628,   619,    39,    44,    53,    60,    62,
      71,    98,   225,   317,   318,   319,   384,   560,   655,   227,
     299,   308,   414,   657,    95,   299,   656,   154,   572,   573,
     657,   572,   573,   119,   430,   128,   554,   119,   414,   148,
     432,   148,    36,   148,   431,   432,   553,   554,   382,    95,
     184,   198,   133,   354,   656,   161,   133,    97,   354,   414,
     143,   432,   154,   119,   414,   414,   148,   101,   456,   457,
     458,   460,   461,   101,   464,   465,   466,   467,   392,   184,
     184,   154,   572,   572,   414,   143,   190,   414,   122,   187,
     187,   187,    35,   532,   131,   197,     9,    10,   104,   124,
     126,   154,   195,   527,   529,   540,   541,   544,   154,    30,
     232,   234,   414,   414,   414,   232,   234,   414,   414,   414,
     414,   414,   414,   414,   414,   414,   510,   119,   414,   414,
      48,    73,    74,   244,   394,   415,   426,   245,   588,   589,
     154,   210,   395,   414,   190,   114,   389,   389,   389,   446,
      96,   107,   117,   128,   448,   449,   450,   451,   108,   657,
     107,   444,   108,   148,   553,   254,    54,    59,    78,   119,
     431,   437,   438,   439,   421,   413,   592,   599,   154,   285,
     476,   644,    97,   169,   252,   253,   255,   262,   272,   284,
     593,   594,   613,   614,   615,   616,   639,   642,   258,   260,
     600,   618,   267,   604,   640,   247,   248,   270,   609,   610,
     157,   157,   556,   157,   157,   157,   157,   157,   145,   176,
     194,   555,   145,   145,   414,   138,   397,   574,   369,   286,
      30,    97,   114,   157,   632,    30,   625,   555,   555,   497,
     287,   306,   553,   384,   227,   190,   391,   187,   187,   145,
     187,   187,   430,   148,   431,   657,   414,   148,   414,   128,
     414,   148,   432,   148,   554,   394,   414,   656,   108,   354,
     414,   143,   391,   454,   414,   414,   114,   457,   458,   101,
     418,   114,   458,   461,   119,   468,   554,   101,   114,   465,
     101,   114,   467,   184,   391,   187,   187,   414,   414,   198,
     464,   133,   195,   529,     7,   392,   657,   195,   540,   392,
     190,   233,   233,   233,   233,    97,   237,   237,   586,   418,
     157,   157,   157,   418,   591,   589,   508,   656,   129,   130,
     450,   451,   451,   447,   143,   553,   656,   443,   414,   148,
     119,   119,   414,   657,   439,    78,   184,   187,   592,   606,
     250,   217,   254,   268,   275,   643,    97,   256,   257,   641,
     250,   596,   643,   478,   613,   597,   148,   282,   601,   602,
     641,   286,   612,    79,   611,   187,   194,   554,   557,   187,
     187,   187,   187,   187,   187,   187,    30,   137,   201,   634,
     635,   636,    30,   633,   634,   271,   629,   108,   626,   170,
     657,   257,   497,   184,   414,   148,   414,   148,   431,   414,
     148,   414,   127,   127,    97,   656,   414,   184,   418,   418,
     414,   394,   414,   418,   418,   657,   210,   418,   119,   468,
     119,   418,   119,   468,   418,   184,   114,   532,   657,   195,
     184,   532,   657,   184,   414,   414,   414,   414,   316,   414,
     414,   414,   413,   413,   413,   154,   590,   451,   414,   143,
     414,   657,   657,   438,   414,   184,   480,    52,   130,   478,
     478,   269,   276,   286,   617,   617,   598,   154,   280,    95,
     187,   108,   187,   632,   632,   636,   108,   187,    30,   630,
     641,   627,   628,   187,   386,   387,   497,   119,   225,   307,
     287,   170,   414,   414,   148,   414,   394,   414,   354,   414,
     394,    95,   554,   394,   414,   657,   418,   657,   414,   657,
     418,   394,   119,    94,   183,   533,   532,   657,   197,   532,
     414,   187,   187,   187,   413,   444,   414,    54,   478,   478,
     199,   413,   554,   554,    95,    30,   265,   108,   108,   451,
     553,   657,   119,   225,   657,   386,   414,   468,    95,   418,
      95,   657,     5,   134,   536,   537,   539,   541,    29,   135,
     534,   535,   538,   541,   197,   532,   197,   198,   464,   184,
     444,   119,   478,   184,   554,   628,   387,   451,   305,   657,
     119,   225,   418,   468,   394,   414,   468,   418,    94,   134,
     539,   183,   135,   538,   197,   114,   657,   414,   305,   657,
     119,   394,   414,   418,   418,   119,   293,   305,   657,   657,
     306,   414,   306,   418,   497,   497,   199,   287,   657,   225,
     119,   657,   306,   497
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  xquery_parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   334,   335,   335,   335,   335,   336,   336,   336,   337,
     337,   337,   337,   338,   338,   339,   339,   339,   339,   339,
     339,   339,   339,   340,   340,   340,   340,   341,   342,   342,
     342,   343,   343,   343,   343,   343,   344,   344,   344,   344,
     344,   344,   344,   344,   345,   345,   346,   347,   348,   348,
     349,   349,   350,   350,   351,   351,   351,   351,   352,   352,
     352,   353,   353,   353,   353,   354,   354,   355,   355,   356,
     356,   356,   356,   357,   358,   358,   359,   359,   359,   360,
     360,   360,   360,   360,   360,   360,   360,   361,   361,   362,
     362,   363,   364,   364,   364,   364,   364,   364,   364,   364,
     364,   364,   365,   366,   367,   368,   368,   369,   369,   369,
     370,   371,   371,   371,   372,   372,   372,   372,   373,   373,
     374,   374,   374,   374,   375,   375,   376,   376,   377,   377,
     378,   378,   379,   379,   380,   380,   380,   380,   381,   381,
     382,   382,   383,   383,   383,   383,   384,   384,   384,   384,
     385,   385,   386,   386,   387,   387,   387,   387,   388,   388,
     388,   388,   389,   390,   390,   390,   391,   391,   391,   392,
     392,   393,   393,   393,   394,   394,   394,   394,   394,   394,
     394,   394,   394,   394,   394,   394,   394,   395,   395,   396,
     397,   398,   399,   399,   399,   400,   400,   400,   400,   401,
     402,   403,   404,   405,   405,   406,   407,   408,   409,   410,
     410,   411,   412,   413,   413,   413,   414,   414,   414,   414,
     414,   414,   415,   415,   415,   415,   415,   415,   415,   415,
     415,   415,   415,   415,   416,   417,   418,   419,   419,   420,
     420,   420,   421,   421,   422,   422,   423,   424,   424,   424,
     425,   425,   425,   425,   425,   426,   426,   427,   427,   427,
     428,   429,   429,   429,   430,   430,   430,   430,   430,   430,
     430,   430,   430,   430,   430,   430,   431,   432,   433,   434,
     434,   435,   435,   435,   435,   436,   436,   437,   437,   437,
     438,   438,   438,   439,   439,   439,   440,   441,   442,   442,
     443,   443,   443,   443,   443,   443,   444,   445,   445,   446,
     446,   447,   447,   448,   448,   448,   448,   448,   448,   448,
     449,   449,   450,   450,   451,   452,   452,   453,   453,   454,
     454,   455,   456,   456,   457,   458,   458,   459,   460,   460,
     461,   462,   462,   463,   463,   464,   464,   465,   465,   466,
     466,   467,   467,   468,   468,   469,   470,   470,   471,   471,
     472,   472,   472,   472,   472,   473,   472,   472,   472,   472,
     474,   474,   475,   475,   476,   476,   477,   477,   478,   478,
     478,   479,   479,   479,   479,   479,   480,   480,   480,   481,
     481,   481,   482,   482,   483,   483,   484,   484,   485,   485,
     486,   486,   487,   487,   488,   488,   488,   488,   489,   489,
     489,   490,   490,   491,   491,   491,   491,   491,   491,   492,
     492,   492,   493,   493,   493,   493,   494,   495,   495,   496,
     496,   496,   497,   497,   497,   497,   498,   499,   499,   499,
     500,   500,   501,   501,   501,   501,   502,   502,   503,   503,
     503,   503,   503,   503,   503,   504,   504,   505,   505,   506,
     506,   506,   506,   506,   507,   507,   508,   508,   509,   509,
     509,   509,   510,   510,   510,   510,   511,   511,   512,   513,
     513,   513,   513,   513,   513,   513,   513,   513,   513,   513,
     513,   513,   513,   514,   514,   515,   515,   515,   516,   517,
     517,   518,   519,   520,   521,   521,   522,   522,   522,   522,
     523,   523,   524,   525,   526,   526,   527,   527,   527,   528,
     528,   528,   528,   528,   528,   529,   529,   530,   530,   531,
     532,   532,   533,   533,   534,   534,   535,   535,   535,   535,
     536,   536,   537,   537,   537,   537,   538,   538,   539,   539,
     540,   540,   540,   540,   541,   541,   541,   541,   542,   542,
     543,   543,   544,   545,   545,   545,   545,   545,   545,   545,
     546,   547,   547,   548,   548,   549,   550,   551,   551,   552,
     552,   553,   554,   554,   554,   555,   555,   555,   556,   556,
     556,   556,   556,   556,   556,   557,   557,   558,   559,   560,
     560,   560,   560,   560,   560,   560,   560,   560,   560,   561,
     562,   563,   563,   563,   564,   565,   566,   567,   567,   567,
     568,   568,   568,   568,   568,   569,   570,   570,   570,   570,
     570,   570,   570,   571,   572,   573,   574,   575,   575,   576,
     577,   577,   578,   579,   579,   579,   580,   580,   580,   580,
     580,   580,   580,   580,   580,   580,   581,   581,   582,   582,
     583,   584,   585,   585,   586,   587,   588,   588,   589,   590,
     591,   591,   592,   593,   593,   594,   594,   595,   595,   596,
     596,   597,   597,   598,   598,   599,   600,   600,   601,   601,
     602,   603,   603,   603,   604,   604,   605,   606,   606,   607,
     608,   608,   609,   609,   610,   610,   610,   611,   611,   612,
     612,   613,   613,   613,   613,   613,   614,   615,   616,   617,
     617,   617,   618,   618,   619,   619,   619,   619,   619,   619,
     619,   619,   620,   620,   620,   620,   621,   621,   622,   623,
     623,   624,   624,   624,   625,   625,   626,   626,   627,   627,
     628,   629,   629,   630,   630,   631,   631,   631,   632,   632,
     633,   633,   634,   634,   635,   635,   636,   636,   637,   638,
     638,   639,   639,   639,   640,   641,   641,   641,   641,   642,
     642,   643,   643,   644,   645,   645,   646,   646,   647,   647,
     648,   649,   649,   650,   650,   650,   651,   652,   653,   654,
     655,   655,   655,   656,   657,   657,   657,   657,   657,   657,
     657,   657,   657,   657,   657,   657,   657,   657,   657,   657,
     657,   657,   657,   657,   657,   657,   657,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   659
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  xquery_parser::yyr2_[] =
  {
         0,     2,     1,     2,     2,     3,     1,     2,     2,     1,
       2,     1,     2,     4,     6,     3,     3,     5,     1,     3,
       3,     5,     5,     1,     3,     3,     5,     6,     1,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     4,     3,     3,     3,
       3,     3,     5,     5,     5,     5,     5,     5,     1,     1,
       3,     3,     4,     5,     6,     1,     3,     3,     3,     3,
       6,     5,     8,     5,     5,     5,     1,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     1,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     3,     4,     3,     1,     1,     1,     2,
       2,     4,     3,     5,     3,     4,     4,     5,     1,     2,
       1,     4,     1,     4,     1,     3,     2,     3,     1,     1,
       4,     4,     5,     5,     2,     3,     4,     5,     1,     3,
       2,     3,     3,     5,     4,     6,     1,     2,     1,     2,
       8,     9,     1,     3,     1,     2,     2,     3,    11,    14,
      13,    22,     1,     1,     1,     0,     1,     1,     0,     1,
       2,     1,     2,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     2,     3,
       3,     2,     3,     2,     3,     2,     3,     4,     5,     5,
       2,     4,     5,     3,     3,     2,     2,     8,     3,     1,
       2,     3,     1,     1,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     2,     2,     1,
       1,     2,     4,     3,     5,     4,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     3,     2,
       1,     1,     4,     3,     3,     5,     4,     6,     4,     6,
       5,     7,     4,     5,     5,     6,     3,     3,     2,     1,
       3,     4,     5,     3,     6,     4,     5,     1,     2,     3,
       1,     2,     1,     6,     3,     3,     2,     3,     1,     3,
       4,     5,     6,     5,     1,     2,     2,     3,     4,     1,
       3,     1,     2,     1,     1,     1,     2,     2,     2,     3,
       1,     1,     2,     2,     2,     5,     5,     1,     4,     3,
       4,     8,     1,     2,     3,     2,     3,     8,     1,     2,
       3,     8,    10,     8,    10,     1,     2,     4,     7,     1,
       2,     4,     7,     1,     3,     8,     1,     3,     1,     3,
       1,     3,     3,     3,     3,     0,     4,     3,     3,     3,
       1,     5,     1,     3,     0,     1,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     4,     1,     4,     1,     4,     1,     4,
       1,     2,     1,     2,     1,     1,     2,     2,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     5,     5,     6,     4,     1,     2,     3,
       2,     2,     1,     2,     2,     1,     1,     1,     3,     3,
       1,     1,     1,     2,     1,     2,     2,     1,     2,     2,
       2,     2,     2,     2,     2,     1,     2,     2,     1,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     4,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       3,     1,     4,     4,     3,     4,     1,     3,     1,     3,
       1,     1,     3,     3,     1,     1,     1,     1,     1,     4,
       8,     5,     9,     9,    10,     1,     2,     1,     2,     6,
       0,     1,     3,     3,     0,     1,     1,     1,     2,     2,
       0,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     2,
       3,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       4,     3,     7,     3,     7,     4,     4,     3,     7,     3,
       7,     2,     1,     2,     3,     1,     1,     1,     1,     1,
       3,     3,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     3,     4,     4,     3,     3,     3,     3,     4,     4,
       3,     4,     6,     4,     6,     4,     3,     4,     6,     6,
       4,     6,     6,     4,     1,     2,     1,     1,     1,     4,
       5,     6,     3,     3,     3,     3,     5,     7,     7,     5,
       5,     5,     7,     7,     5,     5,     3,     3,     5,     7,
       5,     7,     1,     4,     3,     5,     1,     2,     3,     3,
       1,     3,     2,     0,     1,     1,     2,     1,     3,     1,
       3,     1,     4,     1,     2,     3,     0,     1,     0,     1,
       4,     2,     3,     1,     0,     1,     4,     0,     1,     2,
       1,     3,     0,     1,     2,     2,     1,     0,     1,     0,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     1,
       1,     1,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     1,     2,     2,     3,     1,
       2,     2,     5,     2,     1,     1,     0,     2,     1,     3,
       4,     0,     2,     0,     2,     4,     4,     3,     2,     3,
       1,     3,     0,     1,     1,     2,     2,     2,     2,     1,
       2,     2,     2,     2,     3,     2,     3,     3,     4,     2,
       2,     1,     1,     3,     2,     3,     2,     3,     2,     3,
       3,     3,     5,     5,     5,     8,     5,     3,     5,     7,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const xquery_parser::yytname_[] =
  {
    "\"'end of file'\"", "error", "$undefined", "\"'unrecognized'\"",
  "\"'error'\"", "\"'apos attribute content'\"", "\"'char literal'\"",
  "\"'char literal]]>'\"", "\"'char literal and pi end'\"",
  "\"'&#charref;'\"", "\"'element content'\"", "\"'pref:*'\"",
  "\"'ns:*'\"", "\"'&entity;'\"", "\"'comment literal'\"",
  "\"'pi <NCName {>'\"", "\"'NCName_sval'\"", "\"'pragma literal'\"",
  "\"'QName #)'\"", "\"'EQName #)'\"", "\"'*:QName'\"",
  "\"'element QName {'\"", "\"'attribute QName {'\"",
  "\"'processing-instruction NCName {'\"", "\"'namespace NCName {'\"",
  "\"'QName'\"", "\"'EQName'\"", "\"'%QName'\"", "\"'%EQName'\"",
  "\"'quote attribute content'\"", "\"'STRING'\"", "\"'XML comment'\"",
  "\"'URI'\"", "\"'declare'\"", "\"'module'\"", "\"'<blank>'\"",
  "\"'allowing'\"", "\"'base-uri'\"", "\"'boundary-space'\"",
  "\"'comment'\"", "\"'construction'\"", "\"'copy-namespaces'\"",
  "\"'count'\"", "\"'document'\"", "\"'document-node'\"", "\"'element'\"",
  "\"'for'\"", "\"'function'\"", "\"'if'\"", "\"'import'\"",
  "\"'instance'\"", "\"'let'\"", "\"'most'\"", "\"'namespace-node'\"",
  "\"'next'\"", "\"'no'\"", "\"'only'\"", "\"'option'\"", "\"'ordering'\"",
  "\"'previous'\"", "\"'processing-instruction'\"", "\"'schema'\"",
  "\"'schema-attribute'\"", "\"'schema-element'\"", "\"'sequential'\"",
  "\"'set'\"", "\"'simple'\"", "\"'sliding'\"", "\"'some'\"",
  "\"'space'\"", "\"'stable'\"", "\"'text'\"", "\"'tumbling'\"",
  "\"'switch'\"", "\"'typeswitch'\"", "\"'updating'\"", "\"'validate'\"",
  "\"'type'\"", "\"'when'\"", "\"'word'\"", "\"'decimal-format'\"",
  "\"'decimal-separator'\"", "\"'grouping-separator'\"", "\"'infinity'\"",
  "\"'minus-sign'\"", "\"'NaN'\"", "\"'percent'\"", "\"'per-mille'\"",
  "\"'zero-digit'\"", "\"'digit'\"", "\"'pattern-separator'\"",
  "\"'ancestor'\"", "\"'ancestor-or-self'\"", "\"'and'\"", "\"'''\"",
  "\"'as'\"", "\"'ascending'\"", "\"'at'\"", "\"'attribute'\"", "\"'@'\"",
  "\"'||'\"", "\"'case'\"", "\"'castable'\"", "\"'cast'\"",
  "\"'CDATA[['\"", "\"']]'\"", "\"'child'\"", "\"'collation'\"", "\"','\"",
  "\"'(:'\"", "\"':)'\"", "\"'DECIMAL'\"", "\"'context'\"",
  "\"'variable'\"", "\"'default'\"", "\"'descendant'\"",
  "\"'descendant-or-self'\"", "\"'descending'\"", "\"'div'\"", "\"'$'\"",
  "\"'.'\"", "\"'..'\"", "\"':'\"", "\"'::'\"", "\"'{{'\"", "\"'DOUBLE'\"",
  "\"'<double {>'\"", "\"'else'\"", "\"'empty'\"", "\"'greatest'\"",
  "\"'least'\"", "\"'/>'\"", "\"'encoding'\"", "\"'='\"", "\"''''\"",
  "\"'\\\"\\\"'\"", "\"'every'\"", "\"'except'\"", "\"'external'\"",
  "\"'following'\"", "\"'following-sibling'\"", "\"'follows'\"",
  "\"'>='\"", "\"':='\"", "\"'>'\"", "\"'?'\"", "\"'#'\"", "\"'idiv'\"",
  "\"'in'\"", "\"'inherit'\"", "\"'INTEGER'\"", "\"'intersect'\"",
  "\"'is'\"", "\"'item'\"", "\"'{'\"", "\"'['\"", "\"'<='\"", "\"'('\"",
  "\"'<'\"", "\"'-'\"", "\"'mod'\"", "\"'namespace'\"", "\"'nan'\"",
  "\"'!='\"", "\"'nodecomp'\"", "\"'<no inherit>'\"",
  "\"'<no preserve>'\"", "\"'or'\"", "\"'order'\"", "\"'ordered'\"",
  "\"'by'\"", "\"'group'\"", "\"'parent'\"", "\"'%'\"", "\"'<?'\"",
  "\"'?>'\"", "\"'+'\"", "\"'(#'\"", "\"'#)'\"", "\"'<<'\"",
  "\"'preceding'\"", "\"'preceding-sibling'\"", "\"'preserve'\"",
  "\"'\\\"'\"", "\"'}'\"", "\"']'\"", "\"'return'\"", "\"')'\"",
  "\"'satisfies'\"", "\"'self'\"", "\"';'\"", "\"'/'\"", "\"'//'\"",
  "\"'!'\"", "\"'*'\"", "\"'</ (start tag end)'\"", "\"'strip'\"",
  "\"'> (tag end)'\"", "\"'then'\"", "\"'to'\"", "\"'treat'\"",
  "\"'union'\"", "\"'unordered'\"", "\"'eq'\"", "\"'ge'\"", "\"'gt'\"",
  "\"'le'\"", "\"'lt'\"", "\"'ne'\"", "\"'VALUECOMP'\"", "\"'|'\"",
  "\"'empty-sequence'\"", "\"'where'\"", "\"'<!--'\"", "\"'-->'\"",
  "\"'xquery'\"", "\"'version'\"", "\"'start'\"", "\"'after'\"",
  "\"'before'\"", "\"'revalidation'\"", "\"'strict'\"", "\"'lax'\"",
  "\"'skip'\"", "\"'delete'\"", "\"'node'\"", "\"'insert'\"",
  "\"'nodes'\"", "\"'rename'\"", "\"'replace'\"", "\"'value'\"",
  "\"'of'\"", "\"'first'\"", "\"'into'\"", "\"'last'\"", "\"'modify'\"",
  "\"'copy'\"", "\"'with'\"", "\"'break'\"", "\"'continue'\"",
  "\"'exit'\"", "\"'loop'\"", "\"'returning'\"", "\"'while'\"",
  "\"'try'\"", "\"'catch'\"", "\"'using'\"", "\"'all'\"", "\"'any'\"",
  "\"'contains'\"", "\"'content'\"", "\"'diacritics'\"", "\"'different'\"",
  "\"'distance'\"", "\"'end'\"", "\"'entire'\"", "\"'exactly'\"",
  "\"'from'\"", "\"'ftand'\"", "\"'ftnot'\"", "\"'not'\"",
  "\"'ft-option'\"", "\"'ftor'\"", "\"'insensitive'\"", "\"'language'\"",
  "\"'levels'\"", "\"'lowercase'\"", "\"'occurs'\"", "\"'paragraph'\"",
  "\"'paragraphs'\"", "\"'phrase'\"", "\"'relationship'\"", "\"'same'\"",
  "\"'score'\"", "\"'sensitive'\"", "\"'sentence'\"", "\"'sentences'\"",
  "\"'stemming'\"", "\"'stop'\"", "\"'thesaurus'\"", "\"'times'\"",
  "\"'uppercase'\"", "\"'weight'\"", "\"'wildcards'\"", "\"'window'\"",
  "\"'without'\"", "\"'words'\"", "\"'collection'\"", "\"'const'\"",
  "\"'append-only'\"", "\"'queue'\"", "\"'mutable'\"", "\"'read-only'\"",
  "\"'unique'\"", "\"'non'\"", "\"'index'\"", "\"'manually'\"",
  "\"'automatically'\"", "\"'maintained'\"", "\"'on'\"", "\"'range'\"",
  "\"'equality'\"", "\"'general'\"", "\"'integrity'\"", "\"'constraint'\"",
  "\"'check'\"", "\"'key'\"", "\"'foreach'\"", "\"'foreign'\"",
  "\"'keys'\"", "\"'{|'\"", "\"'|}'\"", "\"'{['\"", "\"']}'\"",
  "\"'json'\"", "\"'append'\"", "\"'position'\"", "\"'object'\"",
  "\"'array'\"", "\"'json-item'\"", "\"'structured-item'\"",
  "\"'BOM_UTF8'\"", "\"'#!/shebang\"", "RANGE_REDUCE",
  "SEQUENCE_TYPE_REDUCE", "ADDITIVE_REDUCE", "UNION_REDUCE",
  "INTERSECT_EXCEPT_REDUCE", "QVARINDECLLIST_REDUCE", "UNARY_PREC",
  "STEP_REDUCE", "SIMPLEMAPEXPR_REDUCE", "MULTIPLICATIVE_REDUCE", "SELECT",
  "$accept", "Module", "ERROR", "ModuleWithoutBOM", "VersionDecl",
  "MainModule", "LibraryModule", "ModuleDecl", "SIND_DeclList",
  "SIND_Decl", "Setter", "BoundarySpaceDecl", "DefaultCollationDecl",
  "BaseURIDecl", "ConstructionDecl", "OrderingModeDecl", "EmptyOrderDecl",
  "CopyNamespacesDecl", "Import", "SchemaImport", "URILiteralList",
  "SchemaPrefix", "ModuleImport", "NamespaceDecl", "DefaultNamespaceDecl",
  "VFO_DeclList", "VFO_Decl", "DecimalFormatDecl",
  "DecimalFormatParamList", "DecimalFormatParam", "DecimalFormatParamName",
  "OptionDecl", "FTOptionDecl", "CtxItemDecl", "CtxItemDecl2",
  "CtxItemDecl3", "CtxItemDecl4", "VarDecl", "VarNameAndType",
  "AnnotationList", "Annotation", "AnnotationLiteralList", "FunctionDecl",
  "FunctionDecl2", "FunctionDeclSimple", "FunctionDeclUpdating",
  "FunctionSig", "ParamList", "Param", "CollectionDecl",
  "CollectionTypeDecl", "IndexDecl", "IndexKeyList", "IndexKeySpec",
  "IntegrityConstraintDecl", "QueryBody", "StatementsAndOptionalExprTop",
  "StatementsAndOptionalExpr", "StatementsAndExpr", "Statements",
  "Statement", "BlockStatement", "BlockExpr",
  "EnclosedStatementsAndOptionalExpr", "VarDeclStatement",
  "BlockVarDeclList", "BlockVarDecl", "AssignStatement", "ApplyStatement",
  "ExitStatement", "WhileStatement", "FlowCtlStatement", "FLWORStatement",
  "ReturnStatement", "IfStatement", "TryStatement", "CatchListStatement",
  "CatchStatement", "VoidStatement", "Expr", "ExprSingle", "ExprSimple",
  "FLWORExpr", "ReturnExpr", "ReturnOrSelect", "WindowType",
  "FLWORWinCondType", "FLWORWinCond", "WindowClause", "CountClause",
  "ForLetWinClause", "FLWORClause", "FLWORClauseList", "ForClause",
  "ForOrFrom", "VarInDeclList", "VarInDecl", "PositionalVar", "FTScoreVar",
  "LetClause", "VarGetsDeclList", "VarGetsDecl", "WindowVarDecl",
  "WindowVars", "WindowVars3", "WindowVars2", "WhereClause",
  "GroupByClause", "GroupSpecList", "GroupSpec", "GroupCollationSpec",
  "OrderByClause", "OrderSpecList", "OrderSpec", "OrderModifier",
  "OrderDirSpec", "OrderEmptySpec", "OrderCollationSpec", "QuantifiedExpr",
  "QVarInDeclList", "QVarInDecl", "SwitchExpr", "SwitchCaseClauseList",
  "SwitchCaseClause", "SwitchCaseOperandList", "SwitchStatement",
  "SwitchCaseStatementList", "SwitchCaseStatement", "TypeswitchExpr",
  "TypeswitchStatement", "CaseClauseList", "CaseClause",
  "CaseStatementList", "CaseStatement", "SequenceTypeList", "IfExpr",
  "OrExpr", "AndExpr", "ComparisonExpr", "$@1", "FTContainsExpr",
  "StringConcatExpr", "opt_FTIgnoreOption", "RangeExpr", "AdditiveExpr",
  "MultiplicativeExpr", "UnionExpr", "IntersectExceptExpr",
  "InstanceofExpr", "TreatExpr", "CastableExpr", "CastExpr", "SingleType",
  "UnaryExpr", "SignList", "ValueExpr", "SimpleMapExpr", "ValueComp",
  "NodeComp", "ValidateExpr", "ExtensionExpr", "Pragma_list", "Pragma",
  "PathExpr", "LeadingSlash", "RelativePathExpr", "StepExpr", "AxisStep",
  "ForwardStep", "ForwardAxis", "AbbrevForwardStep", "ReverseStep",
  "ReverseAxis", "NodeTest", "NameTest", "Wildcard", "PostfixExpr",
  "PredicateList", "Predicate", "PrimaryExpr", "Literal", "NumericLiteral",
  "VarRef", "ParenthesizedExpr", "ContextItemExpr", "OrderedExpr",
  "UnorderedExpr", "FunctionCall", "ArgList", "FunctionItemExpr",
  "LiteralFunctionItem", "InlineFunction", "Constructor",
  "DirectConstructor", "DirElemConstructor", "DirElemContentList",
  "DirAttributeList", "DirAttr", "OptionalBlank", "DirAttributeValue",
  "opt_QuoteAttrContentList", "QuoteAttrContentList",
  "opt_AposAttrContentList", "AposAttrContentList",
  "QuoteAttrValueContent", "AposAttrValueContent", "DirElemContent",
  "CommonContent", "DirCommentConstructor", "DirPIConstructor",
  "CDataSection", "ComputedConstructor", "CompDocConstructor",
  "CompElemConstructor", "CompAttrConstructor", "CompTextConstructor",
  "CompCommentConstructor", "CompPIConstructor",
  "CompNamespaceConstructor", "TypeDeclaration", "SequenceType",
  "OccurrenceIndicator", "ItemType", "TypeList", "GeneralizedAtomicType",
  "SimpleType", "KindTest", "AnyKindTest", "NODE_KIND_TEST",
  "DocumentTest", "NamespaceTest", "TextTest", "CommentTest", "PITest",
  "AttributeTest", "SchemaAttributeTest", "ElementTest",
  "SchemaElementTest", "TypeName", "TypeName_WITH_HOOK", "StringLiteral",
  "FunctionTest", "AnyFunctionTest", "TypedFunctionTest",
  "ParenthesizedItemType", "RevalidationDecl", "InsertExpr", "DeleteExpr",
  "ReplaceExpr", "RenameExpr", "TransformExpr", "VarNameList",
  "VarNameDecl", "TryExpr", "CatchListExpr", "CatchExpr", "BracedExpr",
  "NameTestList", "FTSelection", "opt_FTPosFilter_list",
  "FTPosFilter_list", "FTOr", "FTAnd", "FTMildNot", "FTUnaryNot",
  "FTPrimaryWithOptions", "opt_FTMatchOptions", "opt_FTWeight", "FTWeight",
  "FTPrimary", "opt_FTTimes", "FTExtensionSelection", "opt_FTSelection",
  "FTWords", "FTWordsValue", "opt_FTAnyallOption", "FTAnyallOption",
  "opt_word", "opt_words", "FTPosFilter", "FTOrder", "FTWindow",
  "FTDistance", "FTUnit", "FTMatchOptions", "FTMatchOption",
  "FTCaseOption", "FTDiacriticsOption", "FTExtensionOption",
  "FTStemOption", "FTThesaurusOption", "FTThesaurusID_or_default",
  "opt_FTThesaurus_list", "FTThesaurus_list", "FTThesaurusID",
  "opt_relationship", "opt_levels", "FTStopWordOption", "FTStopWords",
  "STRING_LITERAL_list", "opt_FTStopWordsInclExcl_list",
  "FTStopWordsInclExcl_list", "FTStopWordsInclExcl", "FTLanguageOption",
  "FTWildCardOption", "FTContent", "FTTimes", "FTRange", "FTScope",
  "FTBigUnit", "FTIgnoreOption", "JSONArrayConstructor",
  "JSONSimpleObjectUnion", "JSONAccumulatorObjectUnion",
  "JSONObjectConstructor", "JSONPairList", "JSONInsertExpr",
  "JSONAppendExpr", "JSONDeleteExpr", "JSONRenameExpr", "JSONReplaceExpr",
  "JSONTest", "URI_LITERAL", "QNAME", "FUNCTION_NAME", "EQNAME", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const xquery_parser::rhs_number_type
  xquery_parser::yyrhs_[] =
  {
       335,     0,    -1,   337,    -1,   321,   337,    -1,   322,   337,
      -1,   321,   322,   337,    -1,     1,    -1,     1,     3,    -1,
     336,     1,    -1,   339,    -1,   338,   339,    -1,   340,    -1,
     338,   340,    -1,   215,   216,    30,   190,    -1,   215,   216,
      30,   132,    30,   190,    -1,   342,   190,   389,    -1,   359,
     190,   389,    -1,   342,   190,   359,   190,   389,    -1,   389,
      -1,   342,   336,   389,    -1,   359,   336,   389,    -1,   342,
     190,   359,   336,   389,    -1,   342,   336,   359,   190,   389,
      -1,   341,    -1,   341,   342,   190,    -1,   341,   359,   190,
      -1,   341,   342,   190,   359,   190,    -1,    34,   161,   657,
     133,   656,   190,    -1,   343,    -1,   342,   190,   343,    -1,
     342,   336,   343,    -1,   344,    -1,   352,    -1,   357,    -1,
     358,    -1,   366,    -1,   345,    -1,   346,    -1,   347,    -1,
     348,    -1,   349,    -1,   350,    -1,   351,    -1,   579,    -1,
      33,    38,   182,    -1,    33,    38,   196,    -1,    33,   114,
     107,   656,    -1,    33,    37,   656,    -1,    33,    40,   182,
      -1,    33,    40,   196,    -1,    33,    58,   169,    -1,    33,
      58,   202,    -1,    33,   114,   168,   128,   129,    -1,    33,
     114,   168,   128,   130,    -1,    33,    41,   182,   108,   149,
      -1,    33,    41,   182,   108,   165,    -1,    33,    41,   166,
     108,   149,    -1,    33,    41,   166,   108,   165,    -1,   353,
      -1,   356,    -1,    49,    25,     1,    -1,    49,    61,   656,
      -1,    49,    61,   355,   656,    -1,    49,    61,   656,    97,
     354,    -1,    49,    61,   355,   656,    97,   354,    -1,   656,
      -1,   354,   108,   656,    -1,   161,   657,   133,    -1,   114,
      45,   161,    -1,    49,    34,   656,    -1,    49,    34,   161,
     657,   133,   656,    -1,    49,    34,   656,    97,   354,    -1,
      49,    34,   161,   657,   133,   656,    97,   354,    -1,    33,
     161,   657,   133,   656,    -1,    33,   114,    45,   161,   656,
      -1,    33,   114,    47,   161,   656,    -1,   360,    -1,   359,
     190,   360,    -1,   359,   336,   360,    -1,   361,    -1,   365,
      -1,   367,    -1,   371,    -1,   376,    -1,   383,    -1,   385,
      -1,   388,    -1,    33,   114,    80,   362,    -1,    33,    80,
     657,   362,    -1,   363,    -1,   362,   363,    -1,   364,   133,
     574,    -1,    81,    -1,    89,    -1,    82,    -1,    83,    -1,
      84,    -1,    85,    -1,    90,    -1,    86,    -1,    87,    -1,
      88,    -1,    33,    57,   657,    30,    -1,    33,   261,   618,
      -1,    33,   112,   153,   368,    -1,    95,   556,   369,    -1,
     369,    -1,   370,    -1,   138,    -1,   138,   370,    -1,   143,
     414,    -1,    33,   372,   143,   414,    -1,    33,   372,   138,
      -1,    33,   372,   138,   143,   414,    -1,   113,   119,   657,
      -1,   113,   119,   657,   553,    -1,   373,   113,   119,   657,
      -1,   373,   113,   119,   657,   553,    -1,   374,    -1,   373,
     374,    -1,    27,    -1,    27,   157,   375,   187,    -1,    28,
      -1,    28,   157,   375,   187,    -1,   514,    -1,   375,   108,
     514,    -1,    33,   377,    -1,    33,   373,   377,    -1,   378,
      -1,   379,    -1,    47,   658,   380,   397,    -1,    47,   658,
     380,   138,    -1,    75,    47,   658,   380,   397,    -1,    75,
      47,   658,   380,   138,    -1,   157,   187,    -1,   157,   381,
     187,    -1,   157,   187,    95,   554,    -1,   157,   381,   187,
      95,   554,    -1,   382,    -1,   381,   108,   382,    -1,   119,
     657,    -1,   119,   657,   553,    -1,    33,   287,   657,    -1,
      33,   287,   657,    95,   384,    -1,    33,   373,   287,   657,
      -1,    33,   373,   287,   657,    95,   384,    -1,   560,    -1,
     560,   555,    -1,   655,    -1,   655,   555,    -1,    33,   295,
     657,   299,   227,   497,   170,   386,    -1,    33,   373,   295,
     657,   299,   227,   497,   170,   386,    -1,   387,    -1,   386,
     108,   387,    -1,   497,    -1,   497,   553,    -1,   497,   451,
      -1,   497,   553,   451,    -1,    33,   303,   304,   657,   299,
     287,   657,   119,   657,   305,   414,    -1,    33,   303,   304,
     657,   299,   287,   657,   225,   119,   657,   305,   293,   306,
     497,    -1,    33,   303,   304,   657,   299,   287,   657,   307,
     225,   119,   657,   305,   414,    -1,    33,   303,   304,   657,
     308,   306,   257,   287,   657,   225,   119,   657,   306,   497,
     199,   287,   657,   225,   119,   657,   306,   497,    -1,   390,
      -1,   392,    -1,   393,    -1,    -1,   392,    -1,   393,    -1,
      -1,   413,    -1,   393,   413,    -1,   394,    -1,   393,   394,
      -1,   393,   413,   336,   394,    -1,   395,    -1,   398,    -1,
     401,    -1,   402,    -1,   403,    -1,   404,    -1,   405,    -1,
     406,    -1,   408,    -1,   463,    -1,   459,    -1,   409,    -1,
     412,    -1,   154,   393,   184,    -1,   154,   184,    -1,   154,
     391,   184,    -1,   154,   391,   184,    -1,   399,   190,    -1,
     399,   108,   400,    -1,   113,   400,    -1,   373,   113,   400,
      -1,   119,   657,    -1,   119,   657,   553,    -1,   119,   657,
     143,   414,    -1,   119,   657,   553,   143,   414,    -1,   119,
     657,   143,   414,   190,    -1,   415,   190,    -1,   240,   242,
     414,   190,    -1,   243,   157,   413,   187,   394,    -1,   238,
     241,   190,    -1,   239,   241,   190,    -1,   426,   407,    -1,
     418,   394,    -1,    48,   157,   413,   187,   198,   394,   127,
     394,    -1,   244,   395,   410,    -1,   411,    -1,   410,   411,
      -1,   245,   591,   395,    -1,   190,    -1,   414,    -1,   413,
     108,   414,    -1,   413,   336,   414,    -1,   416,    -1,   455,
      -1,   462,    -1,   469,    -1,   587,    -1,   415,    -1,   470,
      -1,   452,    -1,   580,    -1,   581,    -1,   583,    -1,   582,
      -1,   584,    -1,   652,    -1,   650,    -1,   653,    -1,   654,
      -1,   651,    -1,   426,   417,    -1,   418,   414,    -1,   186,
      -1,    67,   284,    -1,    72,   284,    -1,   217,    -1,   254,
      -1,    56,   254,    -1,   420,   437,    78,   414,    -1,   420,
      78,   414,    -1,   428,   419,   436,   421,   421,    -1,   428,
     419,   436,   421,    -1,    42,   119,   657,    -1,   427,    -1,
     433,    -1,   422,    -1,   424,    -1,   440,    -1,   445,    -1,
     441,    -1,   423,    -1,   424,    -1,   426,   425,    -1,   428,
     119,   429,    -1,    46,     1,   429,    -1,   428,     3,    -1,
      46,    -1,   430,    -1,   429,   108,   119,   430,    -1,   429,
     108,   430,    -1,   657,   148,   414,    -1,   657,    36,   128,
     148,   414,    -1,   657,   553,   148,   414,    -1,   657,   553,
      36,   128,   148,   414,    -1,   657,   431,   148,   414,    -1,
     657,    36,   128,   431,   148,   414,    -1,   657,   553,   431,
     148,   414,    -1,   657,   553,    36,   128,   431,   148,   414,
      -1,   657,   432,   148,   414,    -1,   657,   553,   432,   148,
     414,    -1,   657,   431,   432,   148,   414,    -1,   657,   553,
     431,   432,   148,   414,    -1,    97,   119,   657,    -1,   273,
     119,   657,    -1,    51,   434,    -1,   435,    -1,   434,   108,
     435,    -1,   119,   657,   143,   414,    -1,   119,   657,   553,
     143,   414,    -1,   432,   143,   414,    -1,   119,   657,   553,
     432,   143,   414,    -1,   119,   657,   148,   414,    -1,   119,
     657,   553,   148,   414,    -1,   438,    -1,   119,   657,    -1,
     119,   657,   438,    -1,   431,    -1,   431,   439,    -1,   439,
      -1,    59,   119,   657,    54,   119,   657,    -1,    54,   119,
     657,    -1,    59,   119,   657,    -1,   212,   414,    -1,   171,
     170,   442,    -1,   443,    -1,   442,   108,   443,    -1,   119,
     657,   143,   414,    -1,   119,   657,   553,   143,   414,    -1,
     119,   657,   553,   143,   414,   444,    -1,   119,   657,   143,
     414,   444,    -1,   414,    -1,   414,   444,    -1,   107,   656,
      -1,   168,   170,   446,    -1,    70,   168,   170,   446,    -1,
     447,    -1,   446,   108,   447,    -1,   414,    -1,   414,   448,
      -1,   449,    -1,   450,    -1,   451,    -1,   449,   450,    -1,
     449,   451,    -1,   450,   451,    -1,   449,   450,   451,    -1,
      96,    -1,   117,    -1,   128,   129,    -1,   128,   130,    -1,
     107,   656,    -1,    68,   119,   453,   188,   414,    -1,   136,
     119,   453,   188,   414,    -1,   454,    -1,   453,   108,   119,
     454,    -1,   657,   148,   414,    -1,   657,   553,   148,   414,
      -1,    73,   157,   413,   187,   456,   114,   418,   414,    -1,
     457,    -1,   456,   457,    -1,   458,   418,   414,    -1,   101,
     414,    -1,   458,   101,   414,    -1,    73,   157,   413,   187,
     460,   114,   418,   394,    -1,   461,    -1,   460,   461,    -1,
     458,   418,   394,    -1,    74,   157,   413,   187,   464,   114,
     418,   414,    -1,    74,   157,   413,   187,   464,   114,   119,
     657,   418,   414,    -1,    74,   157,   413,   187,   466,   114,
     418,   394,    -1,    74,   157,   413,   187,   464,   114,   119,
     657,   418,   394,    -1,   465,    -1,   464,   465,    -1,   101,
     468,   418,   414,    -1,   101,   119,   657,    95,   468,   418,
     414,    -1,   467,    -1,   466,   467,    -1,   101,   468,   418,
     394,    -1,   101,   119,   657,    95,   468,   418,   394,    -1,
     554,    -1,   468,   210,   554,    -1,    48,   157,   413,   187,
     198,   414,   127,   414,    -1,   471,    -1,   470,   167,   471,
      -1,   472,    -1,   471,    93,   472,    -1,   474,    -1,   474,
     491,   474,    -1,   474,   492,   474,    -1,   474,   133,   474,
      -1,   474,   163,   474,    -1,    -1,   474,   158,   473,   474,
      -1,   474,   156,   474,    -1,   474,   144,   474,    -1,   474,
     142,   474,    -1,   475,    -1,   475,   249,    71,   592,   476,
      -1,   477,    -1,   477,   100,   475,    -1,    -1,   644,    -1,
     478,    -1,   478,   199,   478,    -1,   479,    -1,   478,   176,
     479,    -1,   478,   159,   479,    -1,   480,    -1,   479,   194,
     480,    -1,   479,   118,   480,    -1,   479,   147,   480,    -1,
     479,   160,   480,    -1,   481,    -1,   480,   201,   481,    -1,
     480,   210,   481,    -1,   482,    -1,   481,   151,   482,    -1,
     481,   137,   482,    -1,   483,    -1,   483,    50,   231,   554,
      -1,   484,    -1,   484,   200,    95,   554,    -1,   485,    -1,
     485,   102,    95,   486,    -1,   487,    -1,   487,   103,    95,
     486,    -1,   559,    -1,   559,   145,    -1,   489,    -1,   488,
     489,    -1,   176,    -1,   159,    -1,   488,   176,    -1,   488,
     159,    -1,   493,    -1,   490,    -1,   494,    -1,   497,    -1,
     490,   193,   497,    -1,   203,    -1,   208,    -1,   207,    -1,
     206,    -1,   205,    -1,   204,    -1,   152,    -1,   179,    -1,
     141,    -1,    76,   154,   392,   184,    -1,    76,   222,   154,
     392,   184,    -1,    76,   221,   154,   392,   184,    -1,    76,
      77,   572,   154,   392,   184,    -1,   495,   154,   391,   184,
      -1,   496,    -1,   495,   496,    -1,   177,   657,    17,    -1,
     177,    18,    -1,   177,    19,    -1,   498,    -1,   498,   499,
      -1,   192,   499,    -1,   499,    -1,   191,    -1,   500,    -1,
     500,   191,   499,    -1,   500,   192,   499,    -1,   501,    -1,
     510,    -1,   502,    -1,   502,   511,    -1,   505,    -1,   505,
     511,    -1,   503,   507,    -1,   504,    -1,   106,   123,    -1,
     115,   123,    -1,    98,   123,    -1,   189,   123,    -1,   116,
     123,    -1,   140,   123,    -1,   139,   123,    -1,   507,    -1,
      99,   507,    -1,   506,   507,    -1,   121,    -1,   172,   123,
      -1,    91,   123,    -1,   181,   123,    -1,   180,   123,    -1,
      92,   123,    -1,   560,    -1,   508,    -1,   657,    -1,   509,
      -1,   194,    -1,    11,    -1,    12,    -1,    20,    -1,   513,
      -1,   510,   511,    -1,   510,   157,   187,    -1,   510,   157,
     522,   187,    -1,   512,    -1,   511,   512,    -1,   155,   413,
     185,    -1,   514,    -1,   516,    -1,   517,    -1,   518,    -1,
     521,    -1,   526,    -1,   519,    -1,   520,    -1,   523,    -1,
     396,    -1,   648,    -1,   645,    -1,   646,    -1,   647,    -1,
     515,    -1,   574,    -1,   111,    -1,   150,    -1,   125,    -1,
     119,   657,    -1,   157,   187,    -1,   157,   413,   187,    -1,
     120,    -1,   169,   154,   413,   184,    -1,   202,   154,   413,
     184,    -1,   658,   157,   187,    -1,   658,   157,   522,   187,
      -1,   145,    -1,   522,   108,   145,    -1,   414,    -1,   522,
     108,   414,    -1,   524,    -1,   525,    -1,   658,   146,   150,
      -1,    47,   380,   397,    -1,   527,    -1,   545,    -1,   528,
      -1,   542,    -1,   543,    -1,   158,   657,   532,   131,    -1,
     158,   657,   532,   197,   195,   657,   532,   197,    -1,   158,
     657,   530,   532,   131,    -1,   158,   657,   530,   532,   197,
     195,   657,   532,   197,    -1,   158,   657,   532,   197,   529,
     195,   657,   532,   197,    -1,   158,   657,   530,   532,   197,
     529,   195,   657,   532,   197,    -1,   540,    -1,   529,   540,
      -1,   531,    -1,   530,   531,    -1,    35,   657,   532,   133,
     532,   533,    -1,    -1,    35,    -1,   183,   534,   183,    -1,
      94,   536,    94,    -1,    -1,   535,    -1,   135,    -1,   538,
      -1,   535,   135,    -1,   535,   538,    -1,    -1,   537,    -1,
     134,    -1,   539,    -1,   537,   134,    -1,   537,   539,    -1,
      29,    -1,   541,    -1,     5,    -1,   541,    -1,   527,    -1,
      10,    -1,   544,    -1,   541,    -1,     9,    -1,   124,    -1,
     126,    -1,   154,   392,   184,    -1,   213,    31,   214,    -1,
     213,   214,    -1,   174,   657,   175,    -1,   174,   657,     8,
      -1,   104,     7,    -1,   546,    -1,   547,    -1,   548,    -1,
     549,    -1,   550,    -1,   551,    -1,   552,    -1,    43,   154,
     392,   184,    -1,    21,   391,   184,    -1,    45,   154,   413,
     184,   154,   391,   184,    -1,    22,   391,   184,    -1,    98,
     154,   413,   184,   154,   391,   184,    -1,    71,   154,   392,
     184,    -1,    39,   154,   392,   184,    -1,    23,   391,   184,
      -1,    60,   154,   413,   184,   154,   391,   184,    -1,    24,
     392,   184,    -1,   161,   154,   413,   184,   154,   392,   184,
      -1,    95,   554,    -1,   556,    -1,   556,   555,    -1,   211,
     157,   187,    -1,   145,    -1,   194,    -1,   176,    -1,   558,
      -1,   560,    -1,   153,   157,   187,    -1,   320,   157,   187,
      -1,   575,    -1,   578,    -1,   655,    -1,   554,    -1,   557,
     108,   554,    -1,   657,    -1,   657,    -1,   563,    -1,   570,
      -1,   568,    -1,   571,    -1,   569,    -1,   567,    -1,   566,
      -1,   565,    -1,   564,    -1,   561,    -1,   562,   157,   187,
      -1,   225,    -1,    44,   157,   187,    -1,    44,   157,   570,
     187,    -1,    44,   157,   571,   187,    -1,    53,   157,   187,
      -1,    71,   157,   187,    -1,    39,   157,   187,    -1,    60,
     157,   187,    -1,    60,   157,   657,   187,    -1,    60,   157,
      30,   187,    -1,    98,   157,   187,    -1,    98,   157,   657,
     187,    -1,    98,   157,   657,   108,   572,   187,    -1,    98,
     157,   194,   187,    -1,    98,   157,   194,   108,   572,   187,
      -1,    62,   157,   657,   187,    -1,    45,   157,   187,    -1,
      45,   157,   657,   187,    -1,    45,   157,   657,   108,   572,
     187,    -1,    45,   157,   657,   108,   573,   187,    -1,    45,
     157,   194,   187,    -1,    45,   157,   194,   108,   572,   187,
      -1,    45,   157,   194,   108,   573,   187,    -1,    63,   157,
     657,   187,    -1,   657,    -1,   657,   145,    -1,    30,    -1,
     576,    -1,   577,    -1,    47,   157,   194,   187,    -1,    47,
     157,   187,    95,   554,    -1,    47,   157,   557,   187,    95,
     554,    -1,   157,   556,   187,    -1,    33,   220,   221,    -1,
      33,   220,   222,    -1,    33,   220,   223,    -1,   226,   225,
     414,   233,   414,    -1,   226,   225,   414,    95,   232,   233,
     414,    -1,   226,   225,   414,    95,   234,   233,   414,    -1,
     226,   225,   414,   218,   414,    -1,   226,   225,   414,   219,
     414,    -1,   226,   227,   414,   233,   414,    -1,   226,   227,
     414,    95,   232,   233,   414,    -1,   226,   227,   414,    95,
     234,   233,   414,    -1,   226,   227,   414,   218,   414,    -1,
     226,   227,   414,   219,   414,    -1,   224,   225,   414,    -1,
     224,   227,   414,    -1,   229,   225,   414,   237,   414,    -1,
     229,   230,   231,   225,   414,   237,   414,    -1,   228,   225,
     414,    95,   414,    -1,   236,   119,   585,   235,   414,   418,
     414,    -1,   586,    -1,   585,   108,   119,   586,    -1,   657,
     143,   414,    -1,   244,   154,   413,   184,   588,    -1,   589,
      -1,   588,   589,    -1,   245,   591,   590,    -1,   154,   413,
     184,    -1,   508,    -1,   591,   210,   508,    -1,   595,   593,
      -1,    -1,   594,    -1,   613,    -1,   594,   613,    -1,   596,
      -1,   595,   262,   596,    -1,   597,    -1,   596,   258,   597,
      -1,   598,    -1,   597,   260,   148,   598,    -1,   599,    -1,
     259,   599,    -1,   603,   600,   601,    -1,    -1,   618,    -1,
      -1,   602,    -1,   282,   154,   413,   184,    -1,   607,   604,
      -1,   157,   592,   187,    -1,   605,    -1,    -1,   640,    -1,
     495,   154,   606,   184,    -1,    -1,   592,    -1,   608,   609,
      -1,   514,    -1,   154,   413,   184,    -1,    -1,   610,    -1,
     248,   611,    -1,   247,   612,    -1,   270,    -1,    -1,    79,
      -1,    -1,   286,    -1,   614,    -1,   615,    -1,   616,    -1,
     642,    -1,   639,    -1,   169,    -1,   284,   478,   617,    -1,
     253,   641,   617,    -1,   286,    -1,   276,    -1,   269,    -1,
     246,   619,    -1,   618,   246,   619,    -1,   620,    -1,   621,
      -1,   622,    -1,   637,    -1,   623,    -1,   631,    -1,   624,
      -1,   638,    -1,   101,   274,    -1,   101,   263,    -1,   266,
      -1,   281,    -1,   251,   274,    -1,   251,   263,    -1,    57,
     657,    30,    -1,   277,    -1,    55,   277,    -1,   279,   625,
      -1,   279,   157,   625,   626,   187,    -1,    55,   279,    -1,
     628,    -1,   114,    -1,    -1,   108,   627,    -1,   628,    -1,
     627,   108,   628,    -1,    97,    30,   629,   630,    -1,    -1,
     271,    30,    -1,    -1,   641,   265,    -1,   278,   286,   632,
     634,    -1,   278,   286,   114,   634,    -1,    55,   278,   286,
      -1,    97,    30,    -1,   157,   633,   187,    -1,    30,    -1,
     633,   108,    30,    -1,    -1,   635,    -1,   636,    -1,   635,
     636,    -1,   201,   632,    -1,   137,   632,    -1,   264,    30,
      -1,   283,    -1,    55,   283,    -1,    97,   217,    -1,    97,
     254,    -1,   255,   250,    -1,   267,   641,   280,    -1,   256,
     478,    -1,    97,   130,   478,    -1,    97,    52,   478,    -1,
     257,   478,   199,   478,    -1,   272,   643,    -1,   252,   643,
      -1,   275,    -1,   268,    -1,   285,   250,   480,    -1,   155,
     185,    -1,   155,   413,   185,    -1,   310,   311,    -1,   310,
     413,   311,    -1,   312,   313,    -1,   312,   413,   313,    -1,
     154,   649,   184,    -1,   414,   122,   414,    -1,   649,   108,
     414,   122,   414,    -1,   226,   314,   414,   233,   414,    -1,
     226,   314,   649,   233,   414,    -1,   226,   314,   414,   233,
     414,    97,   316,   414,    -1,   315,   314,   414,   233,   414,
      -1,   224,   314,   510,    -1,   228,   314,   510,    95,   414,
      -1,   229,   230,   231,   314,   510,   237,   414,    -1,   319,
     157,   187,    -1,   318,   157,   187,    -1,   317,   157,   187,
      -1,    30,    -1,   658,    -1,    16,    -1,    98,    -1,    39,
      -1,    44,    -1,    53,    -1,    45,    -1,   153,    -1,    48,
      -1,   225,    -1,    60,    -1,    62,    -1,    63,    -1,    71,
      -1,    74,    -1,    73,    -1,   211,    -1,   243,    -1,   314,
      -1,   318,    -1,   317,    -1,   319,    -1,   320,    -1,   659,
      -1,    25,    -1,   215,    -1,   128,    -1,    38,    -1,   261,
      -1,    37,    -1,   222,    -1,   221,    -1,   147,    -1,    43,
      -1,   259,    -1,   260,    -1,   274,    -1,   263,    -1,   251,
      -1,   285,    -1,   277,    -1,   279,    -1,   278,    -1,   283,
      -1,   255,    -1,   250,    -1,    79,    -1,   217,    -1,   254,
      -1,    52,    -1,   223,    -1,   236,    -1,   302,    -1,   230,
      -1,   203,    -1,   208,    -1,   207,    -1,   206,    -1,   205,
      -1,   204,    -1,    97,    -1,   112,    -1,   113,    -1,   186,
      -1,    46,    -1,   257,    -1,    36,    -1,    67,    -1,    72,
      -1,    59,    -1,    54,    -1,    56,    -1,    78,    -1,    42,
      -1,   148,    -1,    51,    -1,   212,    -1,   170,    -1,   171,
      -1,   168,    -1,    70,    -1,    96,    -1,   117,    -1,   129,
      -1,   130,    -1,   107,    -1,    68,    -1,   136,    -1,   188,
      -1,   101,    -1,    95,    -1,   198,    -1,   127,    -1,   167,
      -1,    93,    -1,    50,    -1,   231,    -1,   102,    -1,   199,
      -1,   118,    -1,   160,    -1,   201,    -1,   151,    -1,   137,
      -1,    76,    -1,    77,    -1,   103,    -1,   200,    -1,   152,
      -1,   182,    -1,   196,    -1,   161,    -1,   138,    -1,   132,
      -1,   166,    -1,   149,    -1,   165,    -1,    33,    -1,    40,
      -1,    58,    -1,   114,    -1,    41,    -1,    57,    -1,   216,
      -1,    49,    -1,    61,    -1,    34,    -1,    47,    -1,   273,
      -1,   249,    -1,   282,    -1,   284,    -1,   253,    -1,   267,
      -1,   280,    -1,   272,    -1,   252,    -1,   266,    -1,   281,
      -1,   271,    -1,   265,    -1,   264,    -1,   248,    -1,   247,
      -1,   256,    -1,   286,    -1,   276,    -1,   275,    -1,   270,
      -1,   268,    -1,   269,    -1,   235,    -1,   232,    -1,   315,
      -1,   226,    -1,   229,    -1,   228,    -1,   224,    -1,   219,
      -1,   218,    -1,   220,    -1,   237,    -1,   227,    -1,   234,
      -1,   233,    -1,    66,    -1,    64,    -1,    75,    -1,   169,
      -1,   202,    -1,   242,    -1,   240,    -1,   241,    -1,   238,
      -1,   239,    -1,   244,    -1,   245,    -1,   246,    -1,    65,
      -1,   295,    -1,   293,    -1,   294,    -1,   299,    -1,   300,
      -1,   301,    -1,   296,    -1,   297,    -1,   298,    -1,    80,
      -1,    81,    -1,    82,    -1,    83,    -1,    84,    -1,    85,
      -1,    86,    -1,    87,    -1,    88,    -1,    89,    -1,    90,
      -1,   287,    -1,   288,    -1,   289,    -1,   290,    -1,   291,
      -1,   292,    -1,   303,    -1,   304,    -1,   305,    -1,   306,
      -1,   307,    -1,   308,    -1,   309,    -1,    91,    -1,   106,
      -1,   115,    -1,   172,    -1,   180,    -1,   189,    -1,   139,
      -1,    92,    -1,   116,    -1,   140,    -1,   181,    -1,   316,
      -1,    26,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  xquery_parser::yyprhs_[] =
  {
         0,     0,     3,     5,     8,    11,    15,    17,    20,    23,
      25,    28,    30,    33,    38,    45,    49,    53,    59,    61,
      65,    69,    75,    81,    83,    87,    91,    97,   104,   106,
     110,   114,   116,   118,   120,   122,   124,   126,   128,   130,
     132,   134,   136,   138,   140,   144,   148,   153,   157,   161,
     165,   169,   173,   179,   185,   191,   197,   203,   209,   211,
     213,   217,   221,   226,   232,   239,   241,   245,   249,   253,
     257,   264,   270,   279,   285,   291,   297,   299,   303,   307,
     309,   311,   313,   315,   317,   319,   321,   323,   328,   333,
     335,   338,   342,   344,   346,   348,   350,   352,   354,   356,
     358,   360,   362,   367,   371,   376,   380,   382,   384,   386,
     389,   392,   397,   401,   407,   411,   416,   421,   427,   429,
     432,   434,   439,   441,   446,   448,   452,   455,   459,   461,
     463,   468,   473,   479,   485,   488,   492,   497,   503,   505,
     509,   512,   516,   520,   526,   531,   538,   540,   543,   545,
     548,   557,   567,   569,   573,   575,   578,   581,   585,   597,
     612,   626,   649,   651,   653,   655,   656,   658,   660,   661,
     663,   666,   668,   671,   676,   678,   680,   682,   684,   686,
     688,   690,   692,   694,   696,   698,   700,   702,   706,   709,
     713,   717,   720,   724,   727,   731,   734,   738,   743,   749,
     755,   758,   763,   769,   773,   777,   780,   783,   792,   796,
     798,   801,   805,   807,   809,   813,   817,   819,   821,   823,
     825,   827,   829,   831,   833,   835,   837,   839,   841,   843,
     845,   847,   849,   851,   853,   856,   859,   861,   864,   867,
     869,   871,   874,   879,   883,   889,   894,   898,   900,   902,
     904,   906,   908,   910,   912,   914,   916,   919,   923,   927,
     930,   932,   934,   939,   943,   947,   953,   958,   965,   970,
     977,   983,   991,   996,  1002,  1008,  1015,  1019,  1023,  1026,
    1028,  1032,  1037,  1043,  1047,  1054,  1059,  1065,  1067,  1070,
    1074,  1076,  1079,  1081,  1088,  1092,  1096,  1099,  1103,  1105,
    1109,  1114,  1120,  1127,  1133,  1135,  1138,  1141,  1145,  1150,
    1152,  1156,  1158,  1161,  1163,  1165,  1167,  1170,  1173,  1176,
    1180,  1182,  1184,  1187,  1190,  1193,  1199,  1205,  1207,  1212,
    1216,  1221,  1230,  1232,  1235,  1239,  1242,  1246,  1255,  1257,
    1260,  1264,  1273,  1284,  1293,  1304,  1306,  1309,  1314,  1322,
    1324,  1327,  1332,  1340,  1342,  1346,  1355,  1357,  1361,  1363,
    1367,  1369,  1373,  1377,  1381,  1385,  1386,  1391,  1395,  1399,
    1403,  1405,  1411,  1413,  1417,  1418,  1420,  1422,  1426,  1428,
    1432,  1436,  1438,  1442,  1446,  1450,  1454,  1456,  1460,  1464,
    1466,  1470,  1474,  1476,  1481,  1483,  1488,  1490,  1495,  1497,
    1502,  1504,  1507,  1509,  1512,  1514,  1516,  1519,  1522,  1524,
    1526,  1528,  1530,  1534,  1536,  1538,  1540,  1542,  1544,  1546,
    1548,  1550,  1552,  1557,  1563,  1569,  1576,  1581,  1583,  1586,
    1590,  1593,  1596,  1598,  1601,  1604,  1606,  1608,  1610,  1614,
    1618,  1620,  1622,  1624,  1627,  1629,  1632,  1635,  1637,  1640,
    1643,  1646,  1649,  1652,  1655,  1658,  1660,  1663,  1666,  1668,
    1671,  1674,  1677,  1680,  1683,  1685,  1687,  1689,  1691,  1693,
    1695,  1697,  1699,  1701,  1704,  1708,  1713,  1715,  1718,  1722,
    1724,  1726,  1728,  1730,  1732,  1734,  1736,  1738,  1740,  1742,
    1744,  1746,  1748,  1750,  1752,  1754,  1756,  1758,  1760,  1763,
    1766,  1770,  1772,  1777,  1782,  1786,  1791,  1793,  1797,  1799,
    1803,  1805,  1807,  1811,  1815,  1817,  1819,  1821,  1823,  1825,
    1830,  1839,  1845,  1855,  1865,  1876,  1878,  1881,  1883,  1886,
    1893,  1894,  1896,  1900,  1904,  1905,  1907,  1909,  1911,  1914,
    1917,  1918,  1920,  1922,  1924,  1927,  1930,  1932,  1934,  1936,
    1938,  1940,  1942,  1944,  1946,  1948,  1950,  1952,  1956,  1960,
    1963,  1967,  1971,  1974,  1976,  1978,  1980,  1982,  1984,  1986,
    1988,  1993,  1997,  2005,  2009,  2017,  2022,  2027,  2031,  2039,
    2043,  2051,  2054,  2056,  2059,  2063,  2065,  2067,  2069,  2071,
    2073,  2077,  2081,  2083,  2085,  2087,  2089,  2093,  2095,  2097,
    2099,  2101,  2103,  2105,  2107,  2109,  2111,  2113,  2115,  2117,
    2121,  2123,  2127,  2132,  2137,  2141,  2145,  2149,  2153,  2158,
    2163,  2167,  2172,  2179,  2184,  2191,  2196,  2200,  2205,  2212,
    2219,  2224,  2231,  2238,  2243,  2245,  2248,  2250,  2252,  2254,
    2259,  2265,  2272,  2276,  2280,  2284,  2288,  2294,  2302,  2310,
    2316,  2322,  2328,  2336,  2344,  2350,  2356,  2360,  2364,  2370,
    2378,  2384,  2392,  2394,  2399,  2403,  2409,  2411,  2414,  2418,
    2422,  2424,  2428,  2431,  2432,  2434,  2436,  2439,  2441,  2445,
    2447,  2451,  2453,  2458,  2460,  2463,  2467,  2468,  2470,  2471,
    2473,  2478,  2481,  2485,  2487,  2488,  2490,  2495,  2496,  2498,
    2501,  2503,  2507,  2508,  2510,  2513,  2516,  2518,  2519,  2521,
    2522,  2524,  2526,  2528,  2530,  2532,  2534,  2536,  2540,  2544,
    2546,  2548,  2550,  2553,  2557,  2559,  2561,  2563,  2565,  2567,
    2569,  2571,  2573,  2576,  2579,  2581,  2583,  2586,  2589,  2593,
    2595,  2598,  2601,  2607,  2610,  2612,  2614,  2615,  2618,  2620,
    2624,  2629,  2630,  2633,  2634,  2637,  2642,  2647,  2651,  2654,
    2658,  2660,  2664,  2665,  2667,  2669,  2672,  2675,  2678,  2681,
    2683,  2686,  2689,  2692,  2695,  2699,  2702,  2706,  2710,  2715,
    2718,  2721,  2723,  2725,  2729,  2732,  2736,  2739,  2743,  2746,
    2750,  2754,  2758,  2764,  2770,  2776,  2785,  2791,  2795,  2801,
    2809,  2813,  2817,  2821,  2823,  2825,  2827,  2829,  2831,  2833,
    2835,  2837,  2839,  2841,  2843,  2845,  2847,  2849,  2851,  2853,
    2855,  2857,  2859,  2861,  2863,  2865,  2867,  2869,  2871,  2873,
    2875,  2877,  2879,  2881,  2883,  2885,  2887,  2889,  2891,  2893,
    2895,  2897,  2899,  2901,  2903,  2905,  2907,  2909,  2911,  2913,
    2915,  2917,  2919,  2921,  2923,  2925,  2927,  2929,  2931,  2933,
    2935,  2937,  2939,  2941,  2943,  2945,  2947,  2949,  2951,  2953,
    2955,  2957,  2959,  2961,  2963,  2965,  2967,  2969,  2971,  2973,
    2975,  2977,  2979,  2981,  2983,  2985,  2987,  2989,  2991,  2993,
    2995,  2997,  2999,  3001,  3003,  3005,  3007,  3009,  3011,  3013,
    3015,  3017,  3019,  3021,  3023,  3025,  3027,  3029,  3031,  3033,
    3035,  3037,  3039,  3041,  3043,  3045,  3047,  3049,  3051,  3053,
    3055,  3057,  3059,  3061,  3063,  3065,  3067,  3069,  3071,  3073,
    3075,  3077,  3079,  3081,  3083,  3085,  3087,  3089,  3091,  3093,
    3095,  3097,  3099,  3101,  3103,  3105,  3107,  3109,  3111,  3113,
    3115,  3117,  3119,  3121,  3123,  3125,  3127,  3129,  3131,  3133,
    3135,  3137,  3139,  3141,  3143,  3145,  3147,  3149,  3151,  3153,
    3155,  3157,  3159,  3161,  3163,  3165,  3167,  3169,  3171,  3173,
    3175,  3177,  3179,  3181,  3183,  3185,  3187,  3189,  3191,  3193,
    3195,  3197,  3199,  3201,  3203,  3205,  3207,  3209,  3211,  3213,
    3215,  3217,  3219,  3221,  3223,  3225,  3227,  3229,  3231,  3233,
    3235,  3237,  3239,  3241,  3243,  3245,  3247,  3249,  3251,  3253,
    3255,  3257,  3259,  3261,  3263,  3265,  3267,  3269,  3271
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   873,   873,   874,   878,   882,   888,   892,   896,   902,
     908,   916,   922,   931,   936,   942,   948,   954,   962,   967,
     975,   983,   991,  1000,  1005,  1011,  1017,  1026,  1034,  1041,
    1047,  1056,  1057,  1058,  1059,  1060,  1063,  1064,  1065,  1066,
    1067,  1068,  1069,  1070,  1073,  1078,  1084,  1090,  1096,  1101,
    1107,  1112,  1118,  1123,  1129,  1134,  1139,  1144,  1150,  1152,
    1154,  1162,  1167,  1175,  1183,  1192,  1199,  1207,  1213,  1219,
    1225,  1232,  1240,  1251,  1258,  1265,  1273,  1280,  1286,  1295,
    1296,  1297,  1298,  1299,  1300,  1301,  1302,  1305,  1311,  1318,
    1325,  1333,  1341,  1342,  1343,  1344,  1345,  1346,  1347,  1348,
    1349,  1350,  1353,  1367,  1373,  1379,  1386,  1392,  1399,  1404,
    1410,  1416,  1428,  1440,  1453,  1458,  1466,  1474,  1483,  1488,
    1495,  1500,  1507,  1512,  1520,  1525,  1532,  1538,  1547,  1548,
    1551,  1565,  1578,  1593,  1606,  1611,  1616,  1621,  1627,  1634,
    1642,  1647,  1655,  1663,  1671,  1679,  1689,  1693,  1699,  1703,
    1710,  1719,  1730,  1736,  1743,  1748,  1755,  1762,  1771,  1781,
    1791,  1801,  1816,  1832,  1836,  1841,  1846,  1850,  1855,  1860,
    1865,  1873,  1880,  1887,  1900,  1901,  1902,  1903,  1904,  1905,
    1906,  1907,  1908,  1909,  1910,  1911,  1912,  1915,  1920,  1927,
    1947,  1953,  1959,  1966,  1973,  1982,  1991,  2000,  2009,  2020,
    2026,  2032,  2038,  2050,  2055,  2061,  2073,  2086,  2106,  2112,
    2119,  2128,  2135,  2141,  2146,  2158,  2170,  2171,  2172,  2173,
    2174,  2175,  2178,  2179,  2180,  2181,  2182,  2183,  2184,  2185,
    2186,  2187,  2188,  2189,  2192,  2204,  2210,  2215,  2220,  2226,
    2231,  2236,  2242,  2251,  2261,  2271,  2282,  2288,  2289,  2290,
    2293,  2294,  2295,  2296,  2297,  2300,  2307,  2315,  2319,  2327,
    2335,  2340,  2347,  2354,  2364,  2374,  2384,  2394,  2404,  2414,
    2424,  2434,  2444,  2453,  2463,  2473,  2485,  2491,  2497,  2503,
    2509,  2517,  2525,  2533,  2541,  2551,  2557,  2566,  2567,  2571,
    2578,  2582,  2587,  2590,  2594,  2598,  2604,  2610,  2616,  2622,
    2630,  2634,  2642,  2650,  2658,  2666,  2676,  2682,  2688,  2696,
    2702,  2710,  2714,  2722,  2728,  2734,  2740,  2749,  2758,  2767,
    2778,  2782,  2788,  2794,  2802,  2808,  2817,  2828,  2834,  2842,
    2846,  2855,  2861,  2867,  2875,  2881,  2887,  2895,  2901,  2907,
    2915,  2921,  2928,  2938,  2945,  2955,  2961,  2969,  2975,  2984,
    2990,  2998,  3004,  3013,  3019,  3027,  3033,  3037,  3043,  3048,
    3054,  3058,  3067,  3073,  3082,  3092,  3091,  3104,  3113,  3122,
    3133,  3137,  3148,  3152,  3158,  3161,  3167,  3171,  3177,  3181,
    3185,  3191,  3195,  3201,  3207,  3213,  3221,  3225,  3229,  3235,
    3239,  3245,  3253,  3257,  3265,  3269,  3277,  3281,  3289,  3293,
    3301,  3305,  3311,  3315,  3321,  3325,  3329,  3333,  3341,  3342,
    3343,  3346,  3351,  3357,  3361,  3365,  3369,  3373,  3377,  3383,
    3387,  3391,  3397,  3401,  3405,  3409,  3418,  3426,  3432,  3440,
    3444,  3448,  3454,  3458,  3466,  3474,  3494,  3500,  3510,  3514,
    3520,  3521,  3524,  3530,  3538,  3544,  3554,  3560,  3568,  3572,
    3576,  3580,  3584,  3590,  3596,  3602,  3606,  3612,  3616,  3625,
    3629,  3633,  3639,  3643,  3651,  3652,  3655,  3659,  3665,  3669,
    3673,  3677,  3683,  3687,  3691,  3695,  3701,  3707,  3715,  3721,
    3722,  3723,  3724,  3725,  3726,  3727,  3728,  3729,  3730,  3731,
    3732,  3733,  3734,  3737,  3741,  3747,  3754,  3761,  3770,  3776,
    3780,  3786,  3793,  3799,  3805,  3809,  3827,  3833,  3839,  3845,
    3853,  3857,  3863,  3869,  3879,  3880,  3883,  3884,  3885,  3888,
    3896,  3912,  3920,  3936,  3954,  3974,  3980,  3989,  3995,  4004,
    4011,  4012,  4014,  4019,  4026,  4029,  4035,  4041,  4047,  4054,
    4063,  4066,  4072,  4078,  4084,  4091,  4100,  4104,  4110,  4114,
    4120,  4124,  4128,  4133,  4140,  4144,  4148,  4152,  4158,  4163,
    4169,  4175,  4182,  4188,  4193,  4198,  4203,  4208,  4213,  4218,
    4221,  4227,  4231,  4237,  4241,  4247,  4253,  4259,  4263,  4269,
    4273,  4279,  4285,  4289,  4293,  4299,  4305,  4311,  4319,  4325,
    4329,  4333,  4337,  4341,  4345,  4351,  4357,  4365,  4371,  4377,
    4381,  4385,  4389,  4393,  4397,  4401,  4405,  4409,  4413,  4419,
    4425,  4431,  4435,  4439,  4445,  4450,  4456,  4462,  4466,  4471,
    4477,  4481,  4487,  4493,  4497,  4505,  4511,  4515,  4521,  4530,
    4539,  4545,  4551,  4559,  4565,  4571,  4577,  4583,  4587,  4593,
    4599,  4603,  4611,  4617,  4623,  4629,  4637,  4641,  4647,  4653,
    4657,  4663,  4667,  4673,  4679,  4686,  4694,  4699,  4705,  4711,
    4719,  4725,  4732,  4738,  4747,  4753,  4759,  4765,  4774,  4781,
    4787,  4793,  4802,  4809,  4813,  4819,  4824,  4831,  4835,  4841,
    4845,  4851,  4855,  4861,  4865,  4873,  4884,  4887,  4893,  4896,
    4902,  4908,  4916,  4920,  4926,  4929,  4935,  4945,  4948,  4954,
    4964,  4970,  4978,  4981,  4987,  4991,  4995,  5001,  5004,  5010,
    5013,  5019,  5023,  5027,  5031,  5035,  5041,  5047,  5057,  5067,
    5071,  5075,  5081,  5087,  5095,  5099,  5103,  5107,  5111,  5115,
    5119,  5123,  5129,  5133,  5137,  5141,  5147,  5153,  5161,  5169,
    5173,  5179,  5189,  5200,  5206,  5210,  5216,  5219,  5225,  5230,
    5237,  5245,  5248,  5254,  5258,  5264,  5273,  5280,  5288,  5292,
    5298,  5304,  5312,  5315,  5321,  5326,  5336,  5344,  5354,  5360,
    5364,  5370,  5374,  5378,  5384,  5390,  5394,  5398,  5402,  5408,
    5416,  5426,  5430,  5436,  5442,  5446,  5452,  5456,  5462,  5466,
    5472,  5479,  5485,  5494,  5500,  5510,  5516,  5522,  5539,  5563,
    5582,  5586,  5590,  5596,  5599,  5600,  5601,  5602,  5603,  5604,
    5605,  5606,  5607,  5608,  5609,  5610,  5611,  5612,  5613,  5614,
    5615,  5616,  5617,  5618,  5619,  5620,  5621,  5624,  5625,  5626,
    5627,  5628,  5629,  5630,  5631,  5632,  5633,  5634,  5635,  5636,
    5637,  5638,  5639,  5640,  5641,  5642,  5643,  5644,  5645,  5646,
    5647,  5648,  5649,  5650,  5651,  5652,  5653,  5654,  5655,  5656,
    5657,  5658,  5659,  5660,  5661,  5662,  5663,  5664,  5665,  5666,
    5667,  5668,  5669,  5670,  5671,  5672,  5673,  5674,  5675,  5676,
    5677,  5678,  5679,  5680,  5681,  5682,  5683,  5684,  5685,  5686,
    5687,  5688,  5689,  5690,  5691,  5692,  5693,  5694,  5695,  5696,
    5697,  5698,  5699,  5700,  5701,  5702,  5703,  5704,  5705,  5706,
    5707,  5708,  5709,  5710,  5711,  5712,  5713,  5714,  5715,  5716,
    5717,  5718,  5719,  5720,  5721,  5722,  5723,  5724,  5725,  5726,
    5727,  5728,  5729,  5730,  5731,  5732,  5733,  5734,  5735,  5736,
    5737,  5738,  5739,  5740,  5741,  5742,  5743,  5744,  5745,  5746,
    5747,  5748,  5749,  5750,  5751,  5752,  5753,  5754,  5755,  5756,
    5757,  5758,  5759,  5760,  5761,  5762,  5763,  5764,  5765,  5766,
    5767,  5768,  5769,  5770,  5771,  5772,  5773,  5774,  5775,  5776,
    5777,  5778,  5779,  5780,  5781,  5782,  5783,  5784,  5785,  5786,
    5787,  5788,  5789,  5790,  5791,  5792,  5793,  5794,  5795,  5796,
    5797,  5798,  5799,  5800,  5801,  5802,  5803,  5804,  5805,  5806,
    5807,  5808,  5809,  5810,  5811,  5812,  5813,  5814,  5815,  5816,
    5817,  5818,  5819,  5820,  5821,  5822,  5823,  5824,  5827
  };

  // Print the state stack on the debug stream.
  void
  xquery_parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  xquery_parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  xquery_parser::token_number_type
  xquery_parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 17222;
  const int xquery_parser::yynnts_ = 326;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 613;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 334;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 588;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


} // zorba

/* Line 1136 of lalr1.cc  */
#line 17622 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 5829 "/home/markos/zorba/repo/type-api/build-nocc-g/src/compiler/parser/xquery_parser.y"

namespace zorba {
static bool contains(const zstring& msg, const char* str1, const char* str2)
{
  zstring::size_type pos = msg.find(str1);
  if (pos == zstring::npos)
    return false;
  if (zstring(str2).size() == 0)
    return true;
  pos = msg.find(str2, pos);
  if (pos == zstring::npos)
    return false;
  return true;
}
void xquery_parser::error(zorba::xquery_parser::location_type const& loc, string const& msg)
{
  if (driver.parserError != NULL)
  {
    driver.set_expr(new ParseErrorNode(driver.parserError->loc, driver.parserError->err_code, driver.parserError->msg));
  }
  else
  {
    ParseErrorNode* prevErr = dynamic_cast<ParseErrorNode*>(driver.get_expr());
    if (prevErr != NULL)
    {
      if ((msg.find("(missing comma \",\" between expressions?)") != string::npos &&
            ! contains(prevErr->msg, "expecting", ","))
          ||
          (msg.find("missing semicolon \";\" after") != string::npos &&
            ! contains(prevErr->msg, "expecting", ";")))
        return;
    }
    string message = msg;
    int pos;
    std::string unexpected_qname = "unexpected \"'QName'\"";
    if ((pos = message.find(unexpected_qname)) != -1)
      message = message.substr(0, pos) + "unexpected qualified name \"" + driver.symtab.get_last_qname() + "\"" + message.substr(pos+unexpected_qname.length());
    while ((pos = message.find("\"'")) != -1 || (pos = message.find("'\"")) != -1)
      message.replace(pos, 2, "\"");
    driver.set_expr(new ParseErrorNode(driver.createQueryLoc(loc), err::XPST0003, message));
  }
}
}

