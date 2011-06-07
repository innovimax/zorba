/* -*- mode:c++ -*-
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

#ifndef ZORBA_TESTURIRESOLVER_H
#define ZORBA_TESTURIRESOLVER_H

#include <zorba/uri_resolvers.h>
#include <zorba/serialization_callback.h>

#include <map>
#include <vector>

namespace zorba 
{

/******************************************************************************

*******************************************************************************/
class TestDocumentURIResolverResult : public DocumentURIResolverResult
{
  protected:
    friend class TestDocumentURIResolver;
    Item theDocument;

  public:
    virtual ~TestDocumentURIResolverResult();
    virtual Item getDocument() const;
};


/******************************************************************************

*******************************************************************************/
class TestDocumentURIResolver : public DocumentURIResolver
{
  public:
    TestDocumentURIResolver(String aBaseFile);
    virtual ~TestDocumentURIResolver();

  virtual std::auto_ptr<DocumentURIResolverResult>
  resolve(const Item& aURI,
          StaticContext* aStaticContext,
          XmlDataManager* aXmlDataManager,
          bool validateUri,
          bool replaceDoc = false);
  private:
    String theBaseFile;
};



/******************************************************************************

*******************************************************************************/
class TestSchemaURIMapper : public URIMapper 
{
private:
  std::string                map_file;
  std::map< String, String > uri_map;
  bool                       theVerbose;

public:
  TestSchemaURIMapper(const char* file, bool verbose = true);

  virtual ~TestSchemaURIMapper();

  virtual void mapURI(const String aURI, Resource::EntityType aEntityType,
    std::vector<String>& oUris) throw ();

private:
  void initialize ();
};


/******************************************************************************

*******************************************************************************/
class TestModuleURIMapper : public URIMapper
{
  typedef std::multimap<std::string, std::string> UriMap;

private:
  std::string    theMapFile;
  std::string    theTest;
  bool           theVerbose;

  UriMap         theUriMap;

public :
  TestModuleURIMapper(
        const char* file,
        const std::string& test,
        bool verbose = true);

  TestModuleURIMapper(
        const char* file,
        bool verbose = true);

  virtual ~TestModuleURIMapper();

  void setTest(const std::string& test) { theTest = test; }

  virtual URIMapper::Kind mapperKind() throw() { return URIMapper::COMPONENT; }

  virtual void mapURI(const String aURI, Resource::EntityType aEntityType,
    std::vector<String>& oUris) throw ();

private:
  void initialize();
};


/******************************************************************************

*******************************************************************************/
class TestCollectionURIMapper : public URIMapper
{
  typedef std::map<std::string, std::vector<std::string> > UriMap;

private:
  std::string  theMapFileName;
  std::string  theRbktSrcFile;
  UriMap       theMap;

  virtual void
  initialize();

  static void
  trim(std::string& str);

public:
  TestCollectionURIMapper(
      const char * file,
      const std::string& aRbktSrcFile );

  virtual ~TestCollectionURIMapper();

  virtual URIMapper::Kind
  mapperKind() throw() { return URIMapper::CANDIDATE; }

  virtual void
  mapURI(
      const String aURI,
      Resource::EntityType aEntityType,
      std::vector<String>& oUris) throw ();
};


class TestSerializationCallback : public zorba::SerializationCallback
{
  std::vector<URIMapper*> theUriMappers;
  public:
    TestSerializationCallback(const std::vector<URIMapper*>& my_uri_mappers)
    {
      theUriMappers = my_uri_mappers;
    }
                              
    virtual ~TestSerializationCallback() {}

  virtual URIMapper*
    getURIMapper(size_t  i ) const {return theUriMappers[i];}


};

#ifndef ZORBA_NO_FULL_TEXT
/******************************************************************************

*******************************************************************************/
class TestFullTextURIResolverResult: public FullTextURIResolverResult
{
  public:
    virtual String getResolvedFullText() const { return theFullText; }
  
  protected:
    friend class TestFullTextURIResolver;
    String theFullText;
};

class TestFullTextURIResolver: public FullTextURIResolver
{
  public:
    virtual ~TestFullTextURIResolver();
  
    virtual std::auto_ptr<FullTextURIResolverResult>
    resolve(
      const Item& aURI,
      StaticContext* aStaticContext);
  
    public:
      void
      add_mapping(const std::string& aURI, const std::string& aValue);
  
  protected:
    typedef std::map<std::string, std::string> Mapping_t;
    typedef Mapping_t::const_iterator          MappingIter_t;
    Mapping_t theMappings;
};
#endif


} // namespace zorba

#endif /* ZORBA_TESTURIRESOLVER_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
