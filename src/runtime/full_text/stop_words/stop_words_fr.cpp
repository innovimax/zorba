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

#include "utf8_chars.h"

namespace zorba {

//
// These words come from http://snowball.tartarus.org/.
//
extern char const *const stop_words_fr[] = {
  agrave,
  "ai",
  "aie",
  "aient",
  "aies",
  "ait",
  "as",
  "au",
  "aura",
  "aurai",
  "auraient",
  "aurais",
  "aurait",
  "auras",
  "aurez",
  "auriez",
  "aurions",
  "aurons",
  "auront",
  "aux",
  "avaient",
  "avais",
  "avait",
  "avec",
  "avez",
  "aviez",
  "avions",
  "avons",
  "ayant",
  "ayez",
  "ayons",
  "c",
  "ce",
  "ceci",
  "cel" agrave,
  "ces",
  "cet",
  "cette",
  "d",
  "dans",
  "de",
  "des",
  "du",
  "elle",
  "en",
  "es",
  "est",
  "et",
  eacute "taient",
  eacute "tais",
  eacute "tait",
  eacute "tant",
  eacute "t" eacute,
  eacute "t" eacute "e",
  eacute "t" eacute "es",
  eacute "t" eacute "s",
  ecirc "tes",
  eacute "tiez",
  eacute "tions",
  "eu",
  "eue",
  "eues",
  "e" ucirc "mes",
  "eurent",
  "eus",
  "eusse",
  "eussent",
  "eusses",
  "eussiez",
  "eussions",
  "eut",
  "e" ucirc "t",
  "e" ucirc "tes",
  "eux",
  "f" ucirc "mes",
  "furent",
  "fus",
  "fusse",
  "fussent",
  "fusses",
  "fussiez",
  "fussions",
  "fut",
  "f" ucirc "t",
  "f" ucirc "tes",
  "ici",
  "il",
  "ils",
  "j",
  "je",
  "l",
  "la",
  "le",
  "les",
  "leur",
  "leurs",
  "lui",
  "m",
  "ma",
  "mais",
  "me",
  "m" ecirc "me",
  "mes",
  "moi",
  "mon",
  "n",
  "ne",
  "nos",
  "notre",
  "nous",
  "on",
  "ont",
  "ou",
  "par",
  "pas",
  "pour",
  "qu",
  "que",
  "quel",
  "quelle",
  "quelles",
  "quels",
  "qui",
  "s",
  "sa",
  "sans",
  "se",
  "sera",
  "serai",
  "seraient",
  "serais",
  "serait",
  "seras",
  "serez",
  "seriez",
  "serions",
  "serons",
  "seront",
  "ses",
  "soi",
  "soient",
  "sois",
  "soit",
  "sommes",
  "son",
  "sont",
  "soyez",
  "soyons",
  "suis",
  "sur",
  "t",
  "ta",
  "te",
  "tes",
  "toi",
  "ton",
  "tu",
  "un",
  "une",
  "vos",
  "votre",
  "vous",
  "y",

  0
};

} // namespace zorba
/* vim:set et sw=2 ts=2: */
