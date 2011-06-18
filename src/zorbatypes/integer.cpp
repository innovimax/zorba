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

#include <cerrno>
#include <cstdlib>

#include "util/ascii_util.h"
#include "util/cxx_util.h"
#include "util/string_util.h"
#include "zorbaserialization/zorba_class_serializer.h"

#include "integer.h"
#include "decimal.h"
#include "floatimpl.h"
#include "numconversions.h"

namespace zorba {

SERIALIZABLE_CLASS_VERSIONS(Integer)
END_SERIALIZABLE_CLASS_VERSIONS(Integer)

///////////////////////////////////////////////////////////////////////////////

void Integer::parse( char const *s ) {
#ifdef ZORBA_WITH_BIG_INTEGER
  Decimal::parse( s, &value_, Decimal::parse_integer );
#else
  char *end;
  value_ = std::strtoll( s, &end, 10 );
  if ( errno == ERANGE )
    throw std::range_error(
      BUILD_STRING( '"', s, "\": number too big/small" )
    );
  if ( end == s )
    throw std::invalid_argument( BUILD_STRING( '"', s, "\": no digits" ) );
  for ( ; *end; ++end )                 // remaining characters, if any, ...
    if ( !ascii::is_space( *end ) )     // ... may only be whitespace
      throw std::invalid_argument(
        BUILD_STRING( '"', *end, "\": invalid character" )
      );
#endif /* ZORBA_WITH_BIG_INTEGER */
}

void Integer::serialize( serialization::Archiver &ar ) {
  ar & value_;
}

////////// constructors ///////////////////////////////////////////////////////

#ifdef ZORBA_WITH_BIG_INTEGER
Integer::Integer( long long n ) {
  zstring const temp( NumConversions::longToStr( n ) );
  value_ = temp.c_str();
}

Integer::Integer( unsigned long n ) {
  zstring const temp( NumConversions::ulongToStr( n ) );
  value_ = temp.c_str();
}

Integer::Integer( unsigned long long n ) {
  zstring const temp( NumConversions::longToStr( n ) );
  value_ = temp.c_str();
}
#endif /* ZORBA_WITH_BIG_INTEGER */

Integer::Integer( Decimal const &d ) {
  value_ = ftoi( d.value_ );
}

Integer::Integer( Double const &d ) {
  if ( !d.isFinite() )
    throw std::invalid_argument( "not finite" );
  value_ = ftoi( d.theFloating );
}

Integer::Integer( Float const &f ) {
  if ( !f.isFinite() )
    throw std::invalid_argument( "not finite" );
  value_ = ftoi( f.theFloating );
}

////////// assignment operators ///////////////////////////////////////////////

#ifdef ZORBA_WITH_BIG_INTEGER
Integer& Integer::operator=( long long n ) {
  zstring const temp( NumConversions::longToStr( n ) );
  value_ = temp.c_str();
  return *this;
}

Integer& Integer::operator=( unsigned long n ) {
  zstring const temp( NumConversions::ulongToStr( n ) );
  value_ = temp.c_str();
  return *this;
}

Integer& Integer::operator=( unsigned long long n ) {
  zstring const temp( NumConversions::longToStr( n ) );
  value_ = temp.c_str();
  return *this;
}
#endif /* ZORBA_WITH_BIG_INTEGER */

Integer& Integer::operator=( Decimal const &d ) {
  value_ = ftoi( d.value_ );
  return *this;
}

Integer& Integer::operator=( Double const &d ) {
  if ( !d.isFinite() )
    throw std::invalid_argument( "not finite" );
  value_ = ftoi( d.theFloating );
  return *this;
}

Integer& Integer::operator=( Float const &f ) {
  if ( !f.isFinite() )
    throw std::invalid_argument( "not finite" );
  value_ = ftoi( f.theFloating );
  return *this;
}

////////// arithmetic operators ///////////////////////////////////////////////

Decimal operator+( Integer const &i, Decimal const &d ) {
  return i.itod() + d.value_;
}

Decimal operator-( Integer const &i, Decimal const &d ) {
  return i.itod() - d.value_;
}

Decimal operator*( Integer const &i, Decimal const &d ) {
  return i.itod() * d.value_;
}

Decimal operator/( Integer const &i, Decimal const &d ) {
  return i.itod() / d.value_;
}

Decimal operator%( Integer const &i, Decimal const &d ) {
  return i.itod() % d.value_;
}

////////// relational operators ///////////////////////////////////////////////

bool operator==( Integer const &i, Decimal const &d ) {
  return d.is_integer() && i.itod() == d.value_;
}

bool operator!=( Integer const &i, Decimal const &d ) {
  return i.itod() != d.value_;
}

bool operator<( Integer const &i, Decimal const &d ) {
  return i.itod() < d.value_;
}

bool operator<=( Integer const &i, Decimal const &d ) {
  return i.itod() <= d.value_;
}

bool operator>( Integer const &i, Decimal const &d ) {
  return i.itod() > d.value_;
}

bool operator>=( Integer const &i, Decimal const &d ) {
  return i.itod() >= d.value_;
}

////////// math functions /////////////////////////////////////////////////////

Double Integer::pow( Integer const &power ) const {
#ifdef ZORBA_WITH_BIG_INTEGER
  value_type const result( value_.pow( power.value_, 15 ) );
  char buf[300];
  result.toFixPtString( buf, 15 );
  xs_double double_result;
  xs_double::parseString( buf, double_result );
  return double_result;
#else
  return Double( ::pow( value_, power.value_ ) );
#endif /* ZORBA_WITH_BIG_INTEGER */
}

Integer Integer::round( Integer const &precision ) const {
  return Integer( Decimal::round( itod(), precision.itod() ) );
}

Integer Integer::roundHalfToEven( Integer const &precision ) const {
  return Integer( Decimal::roundHalfToEven( itod(), precision.itod() ) );
}

////////// miscellaneous //////////////////////////////////////////////////////

#ifndef ZORBA_WITH_BIG_INTEGER
Integer::value_type Integer::ftoi( MAPM const &d ) {
  MAPM const temp( d.sign() >= 0 ? d.floor() : d.ceil() );
  char *const buf = new char[ temp.exponent() + 3 ];
  temp.toIntegerString( buf );
  value_type const result( std::strtoll( buf, nullptr, 10 ) );
  delete[] buf;
  return result;
}

MAPM Integer::itod() const {
  if ( is_xs_long() )
    return static_cast<long>( value_ );
  return NumConversions::longToStr( value_ ).c_str();
}
#endif /* ZORBA_WITH_BIG_INTEGER */

#ifdef ZORBA_WITH_BIG_INTEGER
uint32_t Integer::hash() const {
  return Decimal::hash( value_ );
}
#endif /* ZORBA_WITH_BIG_INTEGER */

Integer const& Integer::one() {
  static Integer const i(1);
  return i;
}

zstring Integer::toString() const {
#ifdef ZORBA_WITH_BIG_INTEGER
  char *const buf = new char[ value_.exponent() + 3 ];
  value_.toIntegerString( buf );
  zstring const s( buf );
  delete[] buf;
  return s;
#else
  char buf[ 128 ];
  sprintf( buf, "%lld", value_ );
  return buf;
#endif /* ZORBA_WITH_BIG_INTEGER */
}

Integer const& Integer::zero() {
  static Integer const i(0);
  return i;
}

std::ostream& operator<<( std::ostream &os, Integer const &i ) {
  return os << i.toString();
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
