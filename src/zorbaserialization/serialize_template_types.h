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
#pragma once
#ifndef TEMPLATE_SERIALIZATION_OPERATORS
#define TEMPLATE_SERIALIZATION_OPERATORS

#include <list>
#include <vector>
#include <map>
#include <stdio.h>

#include <zorba/diagnostic_list.h>
#include <zorba/internal/unique_ptr.h>

#include "util/string_util.h"
#include "util/stl_util.h"
#include "diagnostics/xquery_diagnostics.h"
#include "zorbatypes/zstring.h"

#include "archiver.h"
#include "class_serializer.h"
#include "serialize_basic_types.h"

namespace zorba
{
namespace serialization
{
/////////////////////////////templates

#define ZORBA_SER_ERROR_DESC_OSS(QNAME,MSG)                     \
  do {                                                          \
    std::ostringstream oss;                                     \
    oss << MSG;                                                 \
    throw XQUERY_EXCEPTION( QNAME, ERROR_PARAMS( oss.str() ) ); \
  } while (0)


/*******************************************************************************

********************************************************************************/
template<class T>
void operator&(Archiver& ar, T& obj)
{
  if (ar.is_serializing_out())
  {
    bool is_ref;
    
    is_ref = ar.add_compound_field(obj.get_class_name_str(),
                                   FIELD_IS_CLASS,
                                   "0",//strtemp, 
                                   (SerializeBaseClass*)&obj, 
                                   ARCHIVE_FIELD_NORMAL);
    if (!is_ref)
    {
      obj.serialize_internal(ar);

      ar.add_end_compound_field();
    }
  }
  else
  {
    char* type;
    std::string value;
    int   id;
    bool  is_simple = false;
    bool  is_class = true;
    enum  ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;
    int   referencing;

    bool  retval = ar.read_next_field(&type, &value, &id,
                                      &is_simple, &is_class, &field_treat,
                                      &referencing);

    if (!retval && ar.get_read_optional_field())
      return;

    ar.check_class_field(retval, type, obj.get_class_name_str(),
                         is_simple, is_class, field_treat, 
                         ARCHIVE_FIELD_NORMAL, 
                         id);

    ar.register_reference(id, field_treat, (SerializeBaseClass*)&obj);

    obj.serialize_internal(ar);

    ar.read_end_current_level();
  }
}


/*******************************************************************************

********************************************************************************/
template<class T>
void operator&(Archiver& ar, T*& obj)
{
  if (ar.is_serializing_out())
  {
    if (obj == NULL)
    {
      ar.add_compound_field("NULL", 
                            FIELD_IS_CLASS,
                            "NULL", 
                            NULL,
                            ARCHIVE_FIELD_NULL);
      return;
    }

    bool is_ref = ar.add_compound_field((ar.is_serialize_base_class() ?
                                         obj->T::get_class_name_str() :
                                         obj->get_class_name_str()), 
                                        FIELD_IS_CLASS,
                                        "0",
                                        (SerializeBaseClass*)obj, 
                                        (ar.is_serialize_base_class() ?
                                         ARCHIVE_FIELD_BASECLASS :
                                         ARCHIVE_FIELD_PTR));
    if (!is_ref)
    {
      if (!ar.is_serialize_base_class())
      {
        obj->serialize_internal(ar);
      }
      else
      {
        obj->T::serialize_internal(ar);
      }

      ar.add_end_compound_field();
    }
  }
  else
  {
    char* type;
    std::string value;
    int   id;
    bool  is_simple = false;
    bool  is_class = true;
    enum  ArchiveFieldKind field_treat = ARCHIVE_FIELD_PTR;
    int   referencing;

    bool  retval = ar.read_next_field(&type, &value, &id,
                                      &is_simple, &is_class, &field_treat,
                                      &referencing);

    if (!retval && ar.get_read_optional_field())
      return;

    ar.check_class_field(retval, "", "",
                         is_simple, is_class, field_treat, (ArchiveFieldKind)-1, id);

    if (field_treat == ARCHIVE_FIELD_NULL)
    {
      assert(!ar.is_serialize_base_class());
      obj = NULL;
      ar.read_end_current_level();
      return;
    }

    if (ar.is_serialize_base_class())
    {
#ifndef NDEBUG
      if (strcmp(type, T::get_class_name_str_static()))
      {
        throw ZORBA_EXCEPTION(zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS(id));
      }
#endif
      if (field_treat != ARCHIVE_FIELD_BASECLASS)
      {
        throw ZORBA_EXCEPTION(zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS(id));
      }
    }
    else
    {
      if (field_treat != ARCHIVE_FIELD_PTR && field_treat != ARCHIVE_FIELD_REFERENCING)
      {
        throw ZORBA_EXCEPTION(zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS(id));
      }
    }

    SerializeBaseClass* new_obj = NULL;

    if (field_treat == ARCHIVE_FIELD_PTR)
    {
      ClassDeserializer* cls_factory;
      cls_factory = ClassSerializer::getInstance()->get_class_factory(type);

      if (cls_factory == NULL)
      {
         throw ZORBA_EXCEPTION(zerr::ZCSE0003_UNRECOGNIZED_CLASS_FIELD, 
         ERROR_PARAMS(type));
      }

      new_obj = cls_factory->create_new(ar);

      obj = dynamic_cast<T*>(new_obj);

      if (!obj)
      {
        delete new_obj;obj=NULL;

        throw ZORBA_EXCEPTION(zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD,
        ERROR_PARAMS(id, type, typeid(T).name()));
      }

      ar.register_reference(id, field_treat, new_obj);
      try
      {
        new_obj->serialize_internal(ar);
      }
      catch(...)
      {
        delete new_obj;obj=NULL;
        throw;
      }
      ar.read_end_current_level();
    }
    else if (field_treat == ARCHIVE_FIELD_BASECLASS)
    {
      obj->T::serialize_internal(ar);
      ar.read_end_current_level();
    }
    else if ((new_obj = (SerializeBaseClass*)ar.get_reference_value(referencing)))// ARCHIVE_FIELD_REFERENCING
    {
      try
      {
        obj = dynamic_cast<T*>(new_obj);
      }
      catch(...)
      {
        throw ZORBA_EXCEPTION(zerr::ZCSE0004_UNRESOLVED_FIELD_REFERENCE,
        ERROR_PARAMS(id));
      }

      if (!obj)
      {
        throw ZORBA_EXCEPTION(zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS(id));
      }
    }
    else
    {
      ar.register_delay_reference((void**)&obj,
                                  FIELD_IS_CLASS,
                                  obj->T::get_class_name_str(),
                                  referencing);
    }
  }
}


/*******************************************************************************

********************************************************************************/
template<class T>
void serialize_baseclass(Archiver& ar, T* obj)
{
  ar.set_serialize_base_class(true);

  ar & obj;
}


/*******************************************************************************

********************************************************************************/
template<class RepType>
void operator&(Archiver& ar, zorba::rstring<RepType>& obj)
{
  bool is_normal_str = true;
  if(ar.is_serializing_out())
  {
    if(obj.size() != strlen(obj.c_str()))
      is_normal_str = false;
  }
  ar.set_is_temp_field(true);
  ar & is_normal_str;
  ar.set_is_temp_field(false);

  if(is_normal_str)
  {
    if(ar.is_serializing_out())
    {
      ar.add_simple_field("rstring", obj.c_str(), &obj, ARCHIVE_FIELD_NORMAL);
    }
    else
    {
      char  *type;
      std::string value;
      int   id;
      bool  is_simple = true;
      bool  is_class = false;
      enum  ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;
      int   referencing;
      bool  retval;
      retval = ar.read_next_field(&type, &value, &id, &is_simple, &is_class, &field_treat, &referencing);
      if(!retval && ar.get_read_optional_field())
        return;
      ar.check_simple_field(retval, type, "rstring", is_simple, field_treat, ARCHIVE_FIELD_NORMAL, id);
      obj = value;
      ar.register_reference(id, field_treat, &obj);
    }
  }
  else
  {
    //for strings which contain '\0' inside
    if(ar.is_serializing_out())
    {
      const char *cstr = obj.c_str();
      zorba::zstring::size_type s = obj.size();

      ar.set_is_temp_field(true);
      ar & s;
      serialize_array(ar, (unsigned char*)cstr, s);
      ar.set_is_temp_field(false);
    }
    else
    {
      std::unique_ptr<unsigned char[]> cstr;
      zorba::zstring::size_type s;

      ar.set_is_temp_field(true);
      ar & s;
      cstr.reset(new unsigned char[s]);
      serialize_array(ar, (unsigned char*)cstr.get(), s);
      obj.assign((const char*)cstr.get(), s);
      ar.set_is_temp_field(false);
    }
  }
}


/*******************************************************************************

********************************************************************************/
template<typename T>
void operator&(Archiver& ar, std::list<T>& obj)
{
  if(ar.is_serializing_out())
  {
    char  strtemp[20];
#ifndef WIN32
    sprintf(strtemp, "%d", (int)obj.size());
#else
    sprintf_s(strtemp, sizeof(strtemp), "%d", (int)obj.size());
#endif
    bool is_ref;
    is_ref = ar.add_compound_field("std::list<T>", !FIELD_IS_CLASS, strtemp, &obj, ARCHIVE_FIELD_NORMAL);
    if(!is_ref)
    {
      typename std::list<T>::iterator  it;
      for(it=obj.begin(); it != obj.end(); it++)
      {
        ar & (*it);
      }
      ar.add_end_compound_field();
    }
  }
  else
  {
    char  *type;
    std::string value;
    int   id;
    bool  is_simple = false;
    bool  is_class = false;
    enum  ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;
    int   referencing;
    bool  retval;
    retval = ar.read_next_field(&type, &value, &id, &is_simple, &is_class, &field_treat, &referencing);
    if(!retval && ar.get_read_optional_field())
      return;
    ar.check_nonclass_field(retval, type, "std::list<T>", is_simple, is_class, field_treat, ARCHIVE_FIELD_NORMAL, id);
    ar.register_reference(id, field_treat, &obj);

    int size;
    sscanf(value.c_str(), "%d", &size);
    obj.resize(size);
    typename std::list<T>::iterator  it;
    for(it=obj.begin(); it != obj.end(); it++)
    {
      ar & (*it);
    }
    ar.read_end_current_level();

  }
}


/*******************************************************************************

********************************************************************************/
template<typename T>
void operator&(Archiver& ar, std::vector<T>& obj)
{
  if(ar.is_serializing_out())
  {
    char  strtemp[20];
#ifndef WIN32
    sprintf(strtemp, "%d", (int)obj.size());
#else
    sprintf_s(strtemp, sizeof(strtemp), "%d", (int)obj.size());
#endif
    bool is_ref;
    is_ref = ar.add_compound_field("std::vector<T>", !FIELD_IS_CLASS, strtemp, &obj, ARCHIVE_FIELD_NORMAL);
    if(!is_ref)
    {
      typename std::vector<T>::iterator  it;
      for(it=obj.begin(); it != obj.end(); it++)
      {
        ar & (*it);
      }
      ar.add_end_compound_field();
    }
  }
  else
  {
    char  *type;
    std::string value;
    int   id;
    bool  is_simple = false;
    bool  is_class = false;
    enum  ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;
    int   referencing;
    bool  retval;
    retval = ar.read_next_field(&type, &value, &id, &is_simple, &is_class, &field_treat, &referencing);
    if(!retval && ar.get_read_optional_field())
      return;
    ar.check_nonclass_field(retval, type, "std::vector<T>", is_simple, is_class, field_treat, ARCHIVE_FIELD_NORMAL, id);
    ar.register_reference(id, field_treat, &obj);

    int size;
    sscanf(value.c_str(), "%d", &size);
    obj.resize(size);
    typename std::vector<T>::iterator  it;
    for(it=obj.begin(); it != obj.end(); it++)
    {
      ar & (*it);
    }
    ar.read_end_current_level();

  }
}


/*******************************************************************************

********************************************************************************/
template<typename T>
void operator&(Archiver& ar, std::vector<T>*& obj)
{
  if(ar.is_serializing_out())
  {
    if(obj == NULL)
    {
      ar.add_compound_field("NULL", 
                            !FIELD_IS_CLASS, "NULL", 
                            NULL,//(SerializeBaseClass*)obj, 
                            ARCHIVE_FIELD_NULL);
      return;
    }
    char  strtemp[20];
#ifndef WIN32
    sprintf(strtemp, "%d", (int)obj->size());
#else
    sprintf_s(strtemp, sizeof(strtemp), "%d", (int)obj->size());
#endif
    bool is_ref;
    is_ref = ar.add_compound_field("std::vector<T>*", !FIELD_IS_CLASS, strtemp, obj, ar.is_serialize_base_class() ? ARCHIVE_FIELD_BASECLASS : ARCHIVE_FIELD_PTR);
    if(ar.is_serialize_base_class())                                     
      ar.set_serialize_base_class(false);                                
    if(!is_ref)
    {
      typename std::vector<T>::iterator  it;
      for(it=obj->begin(); it != obj->end(); it++)
      {
        ar & (*it);
      }
      ar.add_end_compound_field();
    }
  }
  else
  {
    char  *type;
    std::string value;
    int   id;
    bool  is_simple = false;
    bool  is_class = false;
    enum  ArchiveFieldKind field_treat = ARCHIVE_FIELD_PTR;
    int   referencing;
    bool  retval;
    retval = ar.read_next_field(&type, &value, &id, &is_simple, &is_class, &field_treat, &referencing);
    if(!retval && ar.get_read_optional_field())
      return;
    ar.check_nonclass_field(retval, type, "std::vector<T>*", is_simple, is_class, field_treat, (ArchiveFieldKind)-1, id);
    if(field_treat == ARCHIVE_FIELD_NULL)
    {
      obj = NULL;
      ar.read_end_current_level();
      return;
    }
    if(ar.is_serialize_base_class())                                     
      ar.set_serialize_base_class(false);                                
    void *new_obj;
    if(field_treat == ARCHIVE_FIELD_PTR)
    {
      obj = new std::vector<T>;
      ar.register_reference(id, field_treat, obj);

      int size;
      sscanf(value.c_str(), "%d", &size);
      obj->resize(size);
      typename std::vector<T>::iterator  it;
      for(it=obj->begin(); it != obj->end(); it++)
      {
        ar & (*it);
      }
      ar.read_end_current_level();
    }
    else if(field_treat == ARCHIVE_FIELD_BASECLASS)
    {
      int size;
      sscanf(value.c_str(), "%d", &size);
      obj->resize(size);
      typename std::vector<T>::iterator  it;
      for(it=obj->begin(); it != obj->end(); it++)
      {
        ar & (*it);
      }
      ar.read_end_current_level();
    }
    else if((new_obj = ar.get_reference_value(referencing)))// ARCHIVE_FIELD_REFERENCING
    {
      obj = (std::vector<T>*)new_obj;
      if(!obj)
      {
        throw ZORBA_EXCEPTION(
          zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS( id )
        );
      }
    }
    else
      ar.register_delay_reference((void**)&obj, !FIELD_IS_CLASS, "std::vector<T>*", referencing);
  }
}


/*******************************************************************************

********************************************************************************/
template<typename T>
void operator&(Archiver& ar, std::vector<T*>& obj)
{
  if(ar.is_serializing_out())
  {
    char  strtemp[20];
#ifndef WIN32
    sprintf(strtemp, "%d", (int)obj.size());
#else
    sprintf_s(strtemp, sizeof(strtemp), "%d", (int)obj.size());
#endif
    bool is_ref;
    is_ref = ar.add_compound_field("std::vector<T*>", !FIELD_IS_CLASS, strtemp, &obj, ARCHIVE_FIELD_NORMAL);
    if(!is_ref)
    {
      typename std::vector<T*>::iterator  it;
      for(it=obj.begin(); it != obj.end(); it++)
      {
        ar & (*it);
      }
      ar.add_end_compound_field();
    }
  }
  else
  {
    char  *type;
    std::string value;
    int   id;
    bool  is_simple = false;
    bool  is_class = false;
    enum  ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;
    int   referencing;
    bool  retval;
    retval = ar.read_next_field(&type, &value, &id, &is_simple, &is_class, &field_treat, &referencing);
    if(!retval && ar.get_read_optional_field())
      return;
    ar.check_nonclass_field(retval, type, "std::vector<T*>", is_simple, is_class, field_treat, ARCHIVE_FIELD_NORMAL, id);
    ar.register_reference(id, field_treat, &obj);

    int size;
    sscanf(value.c_str(), "%d", &size);
    obj.resize(size);
    typename std::vector<T*>::iterator  it;
    for(it=obj.begin(); it != obj.end(); it++)
    {
      ar & (*it);
    }
    ar.read_end_current_level();

  }
}


/*******************************************************************************

********************************************************************************/
template<typename T1, typename T2>
void operator&(Archiver& ar, std::pair<T1, T2>& obj)
{
  if(ar.is_serializing_out())
  {
    bool is_ref;
    is_ref = ar.add_compound_field("std::pair<T1, T2>", !FIELD_IS_CLASS, "", &obj, ARCHIVE_FIELD_NORMAL);
    if(!is_ref)
    {
      ar & obj.first;
      ar & obj.second;
      ar.add_end_compound_field();
    }
  }
  else
  {
    char  *type;
    std::string value;
    int   id;
    bool  is_simple = false;
    bool  is_class = false;
    enum  ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;
    int   referencing;
    bool  retval;
    retval = ar.read_next_field(&type, &value, &id, &is_simple, &is_class, &field_treat, &referencing);
    if(!retval && ar.get_read_optional_field())
      return;
    ar.check_nonclass_field(retval, type, "std::pair<T1, T2>", is_simple, is_class, field_treat, ARCHIVE_FIELD_NORMAL, id);
    ar.register_reference(id, field_treat, &obj);

    ar & obj.first;
    ar & obj.second;
    ar.read_end_current_level();

  }
}


/*******************************************************************************

********************************************************************************/
template<typename T1, typename T2>
void operator&(Archiver& ar, std::pair<T1, T2>*& obj)
{
  if(ar.is_serializing_out())
  {
    if(obj == NULL)
    {
      ar.add_compound_field("NULL", 
                            !FIELD_IS_CLASS, "NULL", 
                            NULL,//(SerializeBaseClass*)obj, 
                            ARCHIVE_FIELD_NULL);
      return;
    }
    bool is_ref;
    is_ref = ar.add_compound_field("std::pair<T1, T2>", !FIELD_IS_CLASS, "", &obj, ar.is_serialize_base_class() ? ARCHIVE_FIELD_BASECLASS : ARCHIVE_FIELD_PTR);
    if(ar.is_serialize_base_class())                                     
      ar.set_serialize_base_class(false);                                
    if(!is_ref)
    {
      ar & obj->first;
      ar & obj->second;
      ar.add_end_compound_field();
    }
  }
  else
  {
    char  *type;
    std::string value;
    int   id;
    bool  is_simple = false;
    bool  is_class = false;
    enum  ArchiveFieldKind field_treat = ARCHIVE_FIELD_PTR;
    int   referencing;
    bool  retval;
    retval = ar.read_next_field(&type, &value, &id, &is_simple, &is_class, &field_treat, &referencing);
    if(!retval && ar.get_read_optional_field())
      return;
    ar.check_nonclass_field(retval, type, "std::pair<T1, T2>", is_simple, is_class, field_treat, (ArchiveFieldKind)-1, id);
    if(field_treat == ARCHIVE_FIELD_NULL)
    {
      obj = NULL;
      ar.read_end_current_level();
      return;
    }
    if(ar.is_serialize_base_class())                                     
      ar.set_serialize_base_class(false);                                

    void *new_obj;
    if(field_treat == ARCHIVE_FIELD_PTR)
    {
      obj = new std::pair<T1, T2>;
      ar.register_reference(id, field_treat, &obj);

      ar & obj->first;
      ar & obj->second;
      ar.read_end_current_level();
    }
    else if(field_treat == ARCHIVE_FIELD_BASECLASS)
    {
      ar & obj->first;
      ar & obj->second;
      ar.read_end_current_level();
    }
    else if((new_obj = ar.get_reference_value(referencing)))// ARCHIVE_FIELD_REFERENCING
    {
      obj = (std::pair<T1, T2>*)new_obj;
      if(!obj)
      {
        throw ZORBA_EXCEPTION(
          zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS( id )
        );
      }
    }
    else
      ar.register_delay_reference((void**)&obj, !FIELD_IS_CLASS, "std::pair<T1, T2>", referencing);
  }
}


/*******************************************************************************

********************************************************************************/
template<typename T1, typename T2>
void operator&(Archiver& ar, std::map<T1, T2>*& obj)
{
  if(ar.is_serializing_out())
  {
    if(obj == NULL)
    {
      ar.add_compound_field("NULL", 
                            !FIELD_IS_CLASS, "NULL", 
                            NULL,//(SerializeBaseClass*)obj, 
                            ARCHIVE_FIELD_NULL);
      return;
    }
    bool is_ref;
    is_ref = ar.add_compound_field("std::map<T1, T2>", !FIELD_IS_CLASS, "", obj, ar.is_serialize_base_class() ? ARCHIVE_FIELD_BASECLASS : ARCHIVE_FIELD_PTR);
    if(ar.is_serialize_base_class())                                     
      ar.set_serialize_base_class(false);                                
    if(!is_ref)
    {
      ar.set_is_temp_field_one_level(true);
      int s = (int)obj->size();
      ar & s;
      typename std::map<T1, T2>::iterator  it;
      for(it=obj->begin(); it != obj->end(); it++)
      {
        ar.dont_allow_delay();
        T1  t1 = (*it).first;
        ar & t1;
        ar.dont_allow_delay();
        ar & (*it).second;
      }
      ar.set_is_temp_field_one_level(false);
      ar.add_end_compound_field();
    }
  }
  else
  {
    char  *type;
    std::string value;
    int   id;
    bool  is_simple = false;
    bool  is_class = false;
    enum  ArchiveFieldKind field_treat = ARCHIVE_FIELD_PTR;
    int   referencing;
    bool  retval;
    retval = ar.read_next_field(&type, &value, &id, &is_simple, &is_class, &field_treat, &referencing);
    if(!retval && ar.get_read_optional_field())
      return;
    ar.check_nonclass_field(retval, type, "std::map<T1, T2>", is_simple, is_class, field_treat, (ArchiveFieldKind)-1, id);
    if(field_treat == ARCHIVE_FIELD_NULL)
    {
      obj = NULL;
      ar.read_end_current_level();
      return;
    }
    if(ar.is_serialize_base_class())                                     
      ar.set_serialize_base_class(false);                                
    void *new_obj;
    if(field_treat == ARCHIVE_FIELD_PTR)
    {
      obj = new std::map<T1, T2>;
      ar.register_reference(id, field_treat, obj);

      ar.set_is_temp_field_one_level(true);
      int s;
      ar & s;
      typename std::map<T1, T2>::iterator  it;
      std::pair<T1, T2>   p;
      for(int i=0;i<s;i++)
      {
        ar & p.first;
        ar & p.second;
        obj->insert(p);
      }
      ar.set_is_temp_field_one_level(false);
      ar.read_end_current_level();
    }
    else if(field_treat == ARCHIVE_FIELD_BASECLASS)
    {
      ar.set_is_temp_field_one_level(true);
      int s;
      ar & s;
      typename std::map<T1, T2>::iterator  it;
      std::pair<T1, T2>   p;
      for(int i=0;i<s;i++)
      {
        ar & p.first;
        ar & p.second;
        obj->insert(p);
      }
      ar.set_is_temp_field_one_level(false);
      ar.read_end_current_level();
    }
    else if((new_obj = ar.get_reference_value(referencing)))// ARCHIVE_FIELD_REFERENCING
    {
      obj = (std::map<T1, T2>*)new_obj;
      if(!obj)
      {
        throw ZORBA_EXCEPTION(
          zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS( id )
        );
      }
    }
    else
      ar.register_delay_reference((void**)&obj, !FIELD_IS_CLASS, "std::map<T1, T2>", referencing);
  }
}

void operator&(Archiver &ar, short &obj);


/*******************************************************************************

********************************************************************************/
template<typename T1, typename T2, class Tcomp>
void operator&(Archiver& ar, std::map<T1, T2, Tcomp>& obj)
{
  if(ar.is_serializing_out())
  {
    bool is_ref;
    is_ref = ar.add_compound_field("std::map<T1, T2>", !FIELD_IS_CLASS, "", &obj, ARCHIVE_FIELD_NORMAL);
    if(!is_ref)
    {
      ar.set_is_temp_field_one_level(true);
      int s = (int)obj.size();
      ar & s;
      typename std::map<T1, T2, Tcomp>::iterator  it;
      for(it=obj.begin(); it != obj.end(); it++)
      {
        T1  t1 = (*it).first;
        ar.dont_allow_delay();
        ar & t1;
        ar.dont_allow_delay();
        ar & (*it).second;
      }
      ar.set_is_temp_field_one_level(false);
      ar.add_end_compound_field();
    }
  }
  else
  {
    char  *type;
    std::string value;
    int   id;
    bool  is_simple = false;
    bool  is_class = false;
    enum  ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;
    int   referencing;
    bool  retval;
    retval = ar.read_next_field(&type, &value, &id, &is_simple, &is_class, &field_treat, &referencing);
    if(!retval && ar.get_read_optional_field())
      return;
    ar.check_nonclass_field(retval, type, "std::map<T1, T2>", is_simple, is_class, field_treat, ARCHIVE_FIELD_NORMAL, id);

    ar.register_reference(id, field_treat, &obj);

    ar.set_is_temp_field_one_level(true);
    int s;
    ar & s;
    //typename std::map<T1, T2>::iterator  it;
    std::pair<T1, T2>   p;
    for(int i=0;i<s;i++)
    {
      ar & p.first;
      ar & p.second;
      obj.insert(p);
    }
    ar.set_is_temp_field_one_level(false);
    ar.read_end_current_level();
  }
}


/*******************************************************************************

********************************************************************************/
template<class T>
void read_optional_field(Archiver& ar, T& obj)
{
  ar.set_read_optional_field(true);
  ar & obj;
  ar.set_read_optional_field(false);
}

} // namespace serialization
} // namespace zorba

#endif /* TEMPLATE_SERIALIZATION_OPERATORS */
/* vim:set et sw=2 ts=2: */