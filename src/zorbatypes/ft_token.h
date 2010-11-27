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

#ifndef ZORBA_FT_TOKEN_H
#define ZORBA_FT_TOKEN_H

#include <iostream>
#include <vector>

#include "zorbatypes/zstring.h"
#include "zorbautils/locale.h"

namespace zorba {

class ft_wildcard;

namespace store {
  class Item;
}

///////////////////////////////////////////////////////////////////////////////

/**
 * An %FTToken is a full-text token from either an XML document or a query.
 */
class FTToken {
public:

  /**
   * The integral type used for token, paragraph, and sentence numbers.
   */
  typedef unsigned int_t;

  /**
   * The string type used for the token string.
   */
  typedef zstring string_t;

  /**
   * Constructs an %FTToken for a token from an XML document.
   *
   * @param utf8_s    The token string encoded in UTF-8.  It need not be
   *                  null-terminated.
   * @param len       The number of chars in the token string.
   * @param pos_no    The position number.  Position numbers start at 0.
   * @param sent_no   The sentence number.  Sentence numbers start at 1.
   * @param para_no   The paragraph number.  Paragraph numbers start at 1.
   * @param item      The Item this token came from.
   * @param lang      The language of the token string.
   */
  FTToken( char const *utf8_s, int len,
           int_t pos_no, int_t sent_no, int_t para_no, store::Item const *item,
           locale::iso639_1::type lang = locale::iso639_1::unknown );

  /**
   * Constructs an %FTToken for a token from a query.
   *
   * @param utf8_s    The token string encoded in UTF-8.  It need not be
   *                  null-terminated.
   * @param len       The number of chars in the token string.
   * @param pos_no    The position number.  Position numbers start at 0.
   * @param sent_no   The sentence number.  Sentence numbers start at 1.
   * @param lang      The language of the token string.
   */
  FTToken( char const *utf8_s, int len, int_t pos_no, int_t sent_no,
           locale::iso639_1::type lang = locale::iso639_1::unknown );

  /**
   * Constructs an %FTToken for a token from a query.
   *
   * @param utf8_s    The token string encoded in UTF-8.
   * @param pos_no    The position number.  Position numbers start at 0.
   * @param sent_no   The sentence number.  Sentence numbers start at 1.
   * @param lang      The language of the token string.
   */
  FTToken( string_t const &utf8_s, int_t pos_no, int_t sent_no,
           locale::iso639_1::type lang = locale::iso639_1::unknown );

  /**
   * Copy constructor.
   *
   * @param from The %FTToken to copy from.
   */
  FTToken( FTToken const &from ) {
    copy( from );
  }

  /**
   * Destroys and %FTToken.
   */
  ~FTToken() {
    free();
  }

  /**
   * Assignment operator.
   *
   * @param from The %FTToken to copy from.
   * @return Returns \c *this.
   */
  FTToken& operator=( FTToken const &from );

  /**
   * Gets the Item this token came from.
   *
   * @return Returns said Item or \c NULL for query tokens.
   */
  store::Item const* item() const {
    return is_query_token() ? NULL : dt_.item_;
  }

  /**
   * Gets the langauge of the token.
   */
  locale::iso639_1::type lang() const {
    return lang_;
  }

  /**
   * Gets the paragraph number within the source XML document.  Paragraph
   * numbers start at 1.  For query tokens, this is always 0.
   *
   * @return Returns said paragraph number.
   */
  int_t para() const {
    return is_query_token() ? 0 : para_;
  }

  /**
   * Gets the token position within either the source XML document or query.
   * Token positions start at 0.
   *
   * @return Retuns said token position.
   */
  int_t pos() const {
    return pos_;
  }

  /**
   * Gets the sentence number within the source XML document.  Sentence numbers
   * start at 1.
   *
   * @return Returns said sentence number.
   */
  int_t sent() const {
    return sent_;
  }

  /**
   * The "bit-wise or" of these is used to select the token's value modified in
   * one-or-more ways.  Note that some combinations are nonsensical, e.g.,
   * <code>lower | upper</code> and will fail an assertion.
   */
  enum Selectors {
    original  = 0x00, ///< the original token
    ascii     = 0x01, ///< diacritics stripped
    lower     = 0x02, ///< lower-case
    upper     = 0x04, ///< upper-case
    stem      = 0x08, ///< stemmed
  };

  /**
   * Gets the token's value modified in one-or-more ways.
   *
   * @param selector  The "bit-wise or" of Selectors.
   * @param alt_lang  The language to use only if the token doesn't already
   *                  have a language.
   * @return Returns said value.
   */
  zstring const&
  value( int selector = original,
         locale::iso639_1::type alt_lang = locale::iso639_1::unknown ) const {
    if ( selector == original )         // optimize this case
      return value_;
    return valueImpl( selector, alt_lang );
  }

  /**
   * Gets an ft_wildcard TODO
   *
   * @param selector The "bit-wise or" of Selectors.
   * @return Returns said ft_wildcard.
   */
  ft_wildcard const& wildcard( int selector = original ) const;

private:
  typedef std::vector<string_t> mod_values_t;

  /**
   * The smallest possible type to store a Selectors value.
   */
  typedef char selector_t;

  static int_t const QueryTokenMagicValue = static_cast<int_t>( ~0 );

  string_t value_;                      ///< original value
  locale::iso639_1::type lang_;         ///< language (if any)
  int_t pos_;                           ///< position number
  int_t sent_;                          ///< sentence number

  /**
   * The token's paragraph number.  If this is QueryTokenMagicValue, it means
   * this token is a query token.  (Query tokens don't have paragraph numbers.)
   * A separate \c bool isn't used because that would take more space.
   */
  int_t para_;

  /**
   * Data only for document tokens.
   */
  struct dt_data {
    store::Item const *item_;           ///< the Item this token came from
  };

  /**
   * Data only for query tokens.
   */
  struct qt_data {

    /**
     * The selector that was used at the time the ft_wildcard was created.
     */
    mutable selector_t selector_;

    mutable ft_wildcard *wildcard_;
  };

  /**
   * Union of document/query token data.
   */
  union {
    dt_data dt_;
    qt_data qt_;
  };

  /**
   * A cache of the various modified token values.  A pointer to a vector is
   * used rather than a vector in order to use less space for the majority of
   * tokens that will never need this.
   */
  mutable mod_values_t *mod_values_;

  inline bool is_query_token() const {
    return para_ == QueryTokenMagicValue;
  }

  static void fix_selector( int *selector );

  void copy( FTToken const& );
  void free();
  void init( int_t, int_t, int_t, store::Item const*, locale::iso639_1::type );

  string_t const&
  valueImpl( int, locale::iso639_1::type = locale::iso639_1::unknown ) const;
};

///////////////////////////////////////////////////////////////////////////////

/**
 * Inserts a text representation of an %FTToken into an ostream.
 *
 * @param o The ostream to insert into.
 * @param t The %FTToken to insert.
 * @return Returns the given ostream.
 */
std::ostream& operator<<( std::ostream &o, FTToken const &t );

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif  /* ZORBA_FT_TOKEN_H */
/* vim:set et sw=2 ts=2: */
