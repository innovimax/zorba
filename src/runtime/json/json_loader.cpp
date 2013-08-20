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

#include "stdafx.h"
#include <zorba/config.h>

// Zorba
#include <store/api/item.h>
#include <store/api/store.h>
#include <store/api/iterator.h>
#include <zorba/store_consts.h>

#include "context/static_context.h"
#include "diagnostics/xquery_diagnostics.h"
#include "store/api/item_factory.h"
#include "system/globalenv.h"
#include "zorbatypes/decimal.h"
#include "zorbatypes/float.h"
#include "zorbatypes/integer.h"
#include "zorbatypes/zstring.h"

// local
#include "common.h"
#include "json_loader.h"

using namespace std;

namespace zorba {
namespace json {


///////////////////////////////////////////////////////////////////////////////

loader::stack_element::stack_element( type t )
  :
  type_( t ), dataguide_( nullptr )
{
  switch ( type_ ) {
    case array_type:
      array_ = new json_array_type;
      break;
    case object_type:
      object_ = new json_object_type;
      break;
    default:
      key_ = nullptr;
      break;
  }
}

/**
 * Destroys a %stack_element.  We have this as an ordinary member function
 * rather than a destructor so that popping the stack and destroying an element
 * are distinct operations and can be called independently which comes in
 * handy.
 */
void loader::stack_element::destroy() {
  switch ( type_ ) {
    case array_type:
      delete array_;
      break;
    case object_type:
      delete object_;
      break;
    case key_type:
      key_->removeReference();
      break;
    default:
      break;
  }
}

///////////////////////////////////////////////////////////////////////////////

loader::loader( istream &is, bool allow_multiple, bool strip_top_level_array, const store::Item *aDataguide) :
  parser_( is, allow_multiple ),
  strip_top_level_array_( strip_top_level_array ),
  stripped_top_level_array_( false ),
  dataguide_(aDataguide),
  skip_next_level_(0)
{
  if (aDataguide)
  {
    zstring s = "*";
    GENV_ITEMFACTORY->createString( dataguide_star_, s );
  }
}

loader::~loader() {
  clear_stack();
}


///////////////////////////////////////////////////////////////////////////////
// Dataguide manipulation
///////////////////////////////////////////////////////////////////////////////
bool loader::contains(const store::Item* dataguide, store::Item_t const& a_key)
{
  if (dataguide == nullptr || (dataguide->isAtomic() && dataguide_star_->equals(dataguide)))
    return true;

  assert(dataguide->isObject());

  store::Iterator_t it = dataguide->getObjectKeys();
  it->open();

  store::Item_t key;
  while (it->next(key))
    if (key->equals(a_key))
      return true;

  return false;
}


void loader::add_value( store::Item_t const &value ) {
  stack_element top( stack_.top() );
  switch ( top.type_ ) {
    case stack_element::array_type:
      top.array_->push_back( value );
      break;
    case stack_element::object_type:
      //
      // value must be a string that's the name of the object's next key/value
      // pair.
      //
      if (!value->isAtomic() || contains(top.dataguide_, value))
      {        
        push( stack_element::key_type ).key_ = value.getp();
        value->addReference();

        if (top.dataguide_ && top.dataguide_->equals(dataguide_star_))
          stack_.top().dataguide_ = dataguide_star_;
        else if (value->isAtomic() && top.dataguide_)
          stack_.top().dataguide_ = top.dataguide_->getObjectValue(value);
      }
      else
      {
        skip_next_level_ = 1;
      }
      break;
    case stack_element::key_type: {
      //
      // Otherwise, the top of the stack must be a string which means that the
      // second-to-top must be an object awaiting a value associated with this
      // name.
      //
      stack_.pop();
      stack_element &top2 = stack_.top();
      assert( top2.type_ == stack_element::object_type );
      top2.object_->keys_.push_back( top.key_ );
      top2.object_->values_.push_back( value );
      top.destroy();      
      break;
    }
    default:
      assert( false );
  }
}

void loader::clear() {
  parser_.clear();
  clear_stack();
  stripped_top_level_array_ = false;
  dataguide_ = nullptr;
  skip_next_level_ = 0;
}

void loader::clear_stack() {
  while ( !stack_.empty() ) {
    stack_.top().destroy();
    stack_.pop();
  }
}

bool loader::next( store::Item_t *result ) {
  store::Item_t item;
  zstring s;
  json::token t;
  const store::Item* top_dg;

  try {
    while ( parser_.next( &t ) ) {
      switch( t.get_type() ) {
        case '[':
          if (skip_next_level_)
          {
            skip_next_level_++;
            continue;
          }
          if ( strip_top_level_array_ && !stripped_top_level_array_ )
            stripped_top_level_array_ = true;
          else
            push( stack_element::array_type );
          continue;
        case '{':
          if (skip_next_level_)
          {
            skip_next_level_++;
            continue;
          }
          top_dg = ( stack_.size() > 0 ? stack_.top().dataguide_ : nullptr );
          push( stack_element::object_type );
          stack_.top().dataguide_ = (stack_.size() == 1 ? dataguide_ : top_dg);
          continue;
        case ']':
          if (skip_next_level_)
          {
            if (skip_next_level_-- > 1)
              continue;
          }
          if ( stack_.empty() && strip_top_level_array_ ) {
            stripped_top_level_array_ = false;
            continue;
          }
        case '}': {
          if (skip_next_level_)
          {
            if (skip_next_level_-- > 1)
              continue;
          }
          stack_element top( stack_.top() );
          stack_.pop();
          switch ( top.type_ ) {
            case stack_element::array_type:
              GENV_ITEMFACTORY->createJSONArray( item, *top.array_ );
              break;
            case stack_element::object_type:
              GENV_ITEMFACTORY->createJSONObject(
                item, top.object_->keys_, top.object_->values_
              );
              break;
            default:
              assert( false );
          } // switch
          top.destroy();
          break;
        }
        case ':':
          continue;
        case ',':
          if (skip_next_level_ == 1)
            skip_next_level_ = 0;
          continue;
        case token::number:
          if (skip_next_level_)
            continue;
          switch ( t.get_numeric_type() ) {
            case token::integer:
              GENV_ITEMFACTORY->createInteger(
                item, xs_integer( t.get_value() )
              );
              break;
            case token::decimal:
              GENV_ITEMFACTORY->createDecimal(
                item, xs_decimal( t.get_value() )
              );
              break;
            case token::floating_point:
              GENV_ITEMFACTORY->createDouble(
                item, xs_double( t.get_value() )
              );
              break;
            default:
              assert( false );
          }
          break;
        case token::string:
          if (skip_next_level_)
            continue;
          s = t.get_value();
          GENV_ITEMFACTORY->createString( item, s );
          break;
        case 'F':
        case 'T':
          if (skip_next_level_)
            continue;
          GENV_ITEMFACTORY->createBoolean( item, t.get_type() == 'T' );
          break;
        case token::json_null:
          if (skip_next_level_)
            continue;
          GENV_ITEMFACTORY->createJSONNull( item );
          break;
        default:
          assert( false );
      } // switch

      if ( stack_.empty() ) {
        *result = item;
        return true;
      }
      add_value( item );
    } // while
    return false;
  } // try
  catch ( json::illegal_character const &e ) {
    XQueryException xe(
      XQUERY_EXCEPTION(
        jerr::JNDY0021,
        ERROR_PARAMS(
          ZED( JNDY0021_IllegalCharacter_2 ),
          ascii::printable_char( e.get_char() )
        ),
        ERROR_LOC( e.get_loc() )
      )
    );
    set_data( &xe, e );
    throw xe;
  }
  catch ( json::illegal_codepoint const &e ) {
    XQueryException xe(
      XQUERY_EXCEPTION(
        jerr::JNDY0021,
        ERROR_PARAMS(
          ZED( JNDY0021_IllegalCodepoint_2 ),
          e.get_codepoint()
        ),
        ERROR_LOC( e.get_loc() )
      )
    );
    set_data( &xe, e );
    throw xe;
  }
  catch ( json::illegal_escape const &e ) {
    XQueryException xe(
      XQUERY_EXCEPTION(
        jerr::JNDY0021,
        ERROR_PARAMS(
          ZED( JNDY0021_IllegalEscape_2 ),
          ascii::printable_char( e.get_escape() )
        ),
        ERROR_LOC( e.get_loc() )
      )
    );
    set_data( &xe, e );
    throw xe;
  }
  catch ( json::illegal_literal const &e ) {
    XQueryException xe(
      XQUERY_EXCEPTION(
        jerr::JNDY0021,
        ERROR_PARAMS( ZED( JNDY0021_IllegalLiteral ) ),
        ERROR_LOC( e.get_loc() )
      )
    );
    set_data( &xe, e );
    throw xe;
  }
  catch ( json::illegal_number const &e ) {
    XQueryException xe(
      XQUERY_EXCEPTION(
        jerr::JNDY0021,
        ERROR_PARAMS( ZED( JNDY0021_IllegalNumber ) ),
        ERROR_LOC( e.get_loc() )
      )
    );
    set_data( &xe, e );
    throw xe;
  }
  catch ( json::unexpected_token const &e ) {
    XQueryException xe(
      XQUERY_EXCEPTION(
        jerr::JNDY0021,
        ERROR_PARAMS(
          ZED( JNDY0021_UnexpectedToken_2 ),
          e.get_token()
        ),
        ERROR_LOC( e.get_loc() )
      )
    );
    set_data( &xe, e );
    throw xe;
  }
  catch ( json::unterminated_string const &e ) {
    XQueryException xe(
      XQUERY_EXCEPTION(
        jerr::JNDY0021,
        ERROR_PARAMS( ZED( JNDY0021_UnterminatedString ) ),
        ERROR_LOC( e.get_loc() )
      )
    );
    set_data( &xe, e );
    throw xe;
  }
}

///////////////////////////////////////////////////////////////////////////////

} // namespace json
} // namespace zorba

/* vim:set et sw=2 ts=2: */
