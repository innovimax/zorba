# Copyright 2006-2012 The FLWOR Foundation.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

PROJECT(ZorbaUtilCurlModule)

IF (ZORBA_SUPPRESS_CURL)
  MESSAGE(STATUS "ZORBA_SUPPRESS_CURL is true - not searching for cURL library")
ELSE (ZORBA_SUPPRESS_CURL)
  MESSAGE(STATUS "Looking for cURL")
  FIND_PACKAGE(CURL)

  IF (CURL_FOUND)
    MESSAGE(STATUS "Found cURL library -- " ${CURL_LIBRARIES})
    INCLUDE_DIRECTORIES(BEFORE SYSTEM "${CURL_INCLUDE_DIR}")
    SET(requiredlibs ${requiredlibs} "${CURL_LIBRARIES}")

    SET(ZORBA_PROJECT_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/include")
    INCLUDE_DIRECTORIES("${CMAKE_CURRENT_SOURCE_DIR}/include")
    INSTALL(FILES include/util/curl_streambuf.h DESTINATION include/util)

    ADD_SUBDIRECTORY("src")

    IF (WIN32) # Copy certificates for windows only
      IF (MSVC_IDE)
        SET(CACERT_DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/../../bin/${CMAKE_BUILD_TYPE}/cacert.pem")
      ELSE (MSVC_IDE)
        SET(CACERT_DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/../../bin/cacert.pem")
      ENDIF (MSVC_IDE)
      CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/cacert.pem" ${CACERT_DESTINATION} COPYONLY)
      INSTALL(FILES ${CACERT_DESTINATION} DESTINATION bin)
    ENDIF (WIN32)

  ELSE (CURL_FOUND)
    MESSAGE(STATUS "The cURL library was not found")
  ENDIF (CURL_FOUND)
ENDIF (ZORBA_SUPPRESS_CURL)
SET(ZORBA_HAVE_CURL ${CURL_FOUND} CACHE BOOL "Whether Zorba found cURL" FORCE)

# vim:set et sw=2 ts=2:
