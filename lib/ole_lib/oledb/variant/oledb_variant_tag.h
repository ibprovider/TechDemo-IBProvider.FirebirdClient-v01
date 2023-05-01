////////////////////////////////////////////////////////////////////////////////
//Declaration of OLEDB VARIANT structure
//                                                Dmitry Kovalenko. 06.03.2006.
#ifndef _oledb_variant_tag_
#define _oledb_variant_tag_

#if(COMP_CONF_SUPPORT_PRAGMA_ONCE)
# pragma once
#endif

#include <ole_lib/oledb/oledb_data_types.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////

#if ( _MSC_VER >= 800 )
#if _MSC_VER >= 1200
#pragma warning(push)
#endif
#pragma warning(disable:4201)    /* Nameless struct/union */
#endif

////////////////////////////////////////////////////////////////////////////////
//struct tagDBVARIANT

struct tagDBVARIANT
{
 private:
  typedef tagDBVARIANT                                self_type;

 public: //typedefs ------------------------------------------------------
  typedef DBLENGTH                                    length_type;
  typedef DBSTATUS                                    status_type;
  typedef DBCOUNTITEM                                 count_item_type;
  typedef size_t                                      size_type;

 public: //typedefs ------------------------------------------------------
  typedef t_oledb_value__I1                           value_i1_type;
  typedef t_oledb_value__I2                           value_i2_type;
  typedef t_oledb_value__I4                           value_i4_type;
  typedef t_oledb_value__I8                           value_i8_type;
  typedef t_oledb_value__I8_s                         value_i8_type_s;

  typedef t_oledb_value__UI1                          value_ui1_type;
  typedef t_oledb_value__UI2                          value_ui2_type;
  typedef t_oledb_value__UI4                          value_ui4_type;
  typedef t_oledb_value__UI8                          value_ui8_type;
  typedef t_oledb_value__UI8_s                        value_ui8_type_s;

  typedef t_oledb_value__R4                           value_r4_type;
  typedef t_oledb_value__R8                           value_r8_type;

  typedef t_oledb_value__LONG                         value_long_type;
  typedef t_oledb_value__ULONG                        value_ulong_type;

  typedef t_oledb_value__CY                           value_cy_type;
  typedef t_oledb_value__DECIMAL                      value_decimal_type;
  typedef t_oledb_value__NUMERIC                      value_numeric_type;

  typedef t_oledb_value__DATE                         value_date_type;
  typedef t_oledb_value__DBDATE                       value_dbdate_type;
  typedef t_oledb_value__DBTIME                       value_dbtime_type;
  typedef t_oledb_value__DBTIME2                      value_dbtime2_type;
  typedef t_oledb_value__DBTIMESTAMP                  value_dbstamp_type;
  typedef t_oledb_value__DBTIMESTAMPOFFSET            value_dbstampoffset_type;
  typedef t_oledb_value__FILETIME                     value_filetime_type;

  typedef t_oledb_value__SCODE                        value_scode_type;

  typedef t_oledb_value__GUID                         value_guid_type;

  struct tagUnkVal
  {
   LPUNKNOWN   ptr;
   IID         iid;
  };//struct tagUnkVal

  struct tagDispVal
  {
   LPDISPATCH  ptr;
  };//struct tagDispVal

  struct tagStrVal
  {
   //pointer to DBTYPE_STR. include a terminated '\0'
   t_oledb_value__CHAR*  ptr;

   //length (char count, without terminated symbol)
   size_type  len;

   //если strVal==NULL, то длина игнорируется
   size_type      length()const
    {return this->ptr?this->len:0;}

   size_type      byte_count()const
    {return this->length()*sizeof(*this->ptr);}
  };//struct tagStrVal

  //DBTYPE_WSTR (все по аналогии с DBTYPE_STR)
  struct tagWStrVal
  {
   t_oledb_value__WCHAR*  ptr;

   //length (char count, without terminated symbol)
   size_type  len;

   size_type      length()const
    {return this->ptr?this->len:0;}

   size_type      byte_count()const
    {return this->length()*sizeof(*this->ptr);}
  };//struct tagWStrVal

  //DBBYTE_BYTES
  struct tagBytesVal
  {
   //pointer - должен находится первым, чтобы накладываться на др. указатели
   void*          ptr     ;
   size_type      len     ;//length

   size_type      length()const
    {return this->ptr?this->len:0;}

   size_type      byte_count()const
    {return this->length();}

   unsigned char* bytes()
    {return this->len?reinterpret_cast<unsigned char*>(this->ptr):NULL;}

   const unsigned char* bytes()const
    {return this->len?reinterpret_cast<const unsigned char*>(this->ptr):NULL;}
  };//struct tagBytesVal

  struct tagArrayVal
  {
   LPSAFEARRAY  ptr;
   IID          element_iid;
  };//tagArrayVal

 public:
  DBSTATUS  dwDataStatus;
  DBTYPE    wType;

  union
  {
   //main rules: &valI1 - access for all direct fields
   //            strVal - access to all pointed fields

   //For new dbtype need refresh:
   //
   // - <oledb_variant_service.h>(cpp)
   //     - service for single value and array
   //
   // - <oledb_variant_dbtype.inc>
   //     - array g_DBTypes
   //
   // - <oledb_variant_adotype.inc>
   //     - array g_ADOTypes
   //
   // - <oledb_variant_assign.cc>
   //     - basic_dbvariant::Clear
   //     - basic_dbvariant::SetVariant
   //
   // - <oledb_variant_assign_utils.h>(cc)
   //     - sm_copy_funcs
   //     - sm_assign_as_funcs
   //
   // - <oledb_variant_set_utils.h>(cc)
   //     - sm_set_data_funcs
   //
   // - <oledb_variant.cpp>
   //     - DBVARIANT::CanConvert

   //depended functions:
   //Clear
   //operator = (const dbvariant_type&)
   //SetArrayElement

   union
   {
    value_i1_type             valI1;           //           DBTYPE_I1
    value_ui1_type            valUI1;          //           DBTYPE_UI1
    value_i2_type             valI2;           //           DBTYPE_I2
    value_ui2_type            valUI2;          //           DBTYPE_UI2
    value_i4_type             valI4;           //           DBTYPE_I4
    value_ui4_type            valUI4;          //           DBTYPE_UI4
    value_r4_type             valR4;           //           DBTYPE_R4
    value_r8_type             valR8;           //           DBTYPE_R8
    value_i8_type_s           valI8;           //           DBTYPE_I8
    value_ui8_type_s          valUI8;          //           DBTYPE_UI8

    value_long_type           longVal;         //           LONG equal to I4
    value_ulong_type          ulongVal;        //           ULONG equal to UI4

    value_cy_type             valCY;           //           DBTYPE_CY
    value_numeric_type        dbnumVal;        //           DBTYPE_NUMERIC
    value_decimal_type        decVal;          //           DBTYPE_DECIMAL

    VARIANT_BOOL              boolVal;         //           DBTYPE_BOOL
    value_scode_type          scodeVal;        //           DBTYPE_ERROR
    BSTR                      bstrVal;         //BSTR       DBTYPE_BSTR

    value_date_type           dateVal;         //           DBTYPE_DATE
    value_dbdate_type         dbdateVal;       //           DBTYPE_DBDATE
    value_dbtime_type         dbtimeVal;       //           DBTYPE_DBTIME
    value_dbtime2_type        dbtime2Val;      //           oledb_typeid__DBTIME2
    value_dbstamp_type        dbstampVal;      //           DBTYPE_DBTIMESTAMP
    value_dbstampoffset_type  dbstampoffsetVal;//           DBTYPE_DBTIMESTAMPOFFSET
    value_filetime_type       filetimeVal;     //           DBTYPE_FILETIME

    value_guid_type           guidVal;         //           DBTYPE_GUID

    VARIANT                   varVal;          //           DBTYPE_VARIANT

    tagUnkVal                 unkVal;          //Release    DBTYPE_IUNKNOWN
    tagDispVal                dispVal;         //Release    DBTYPE_IDISPATCH

    tagArrayVal               arrayVal2;       //pointer    DBTYPE_ARRAY|DBTYPE_XXX
   };

   struct
   {
    union
    {
     tagStrVal                strVal;          //pointer    DBTYPE_STR

     tagWStrVal               wstrVal;         //pointer    DBTYPE_WSTR

     tagBytesVal              bytesVal;        //pointer    DBBYTE_BYTES
    };//union

    size_type                 reserveMemSize;
   };//struct
  };//union
};//struct tagDBVARIANT

////////////////////////////////////////////////////////////////////////////////

#if ( _MSC_VER >= 800 )
#if _MSC_VER >= 1200
#pragma warning(pop)
#else
#pragma warning(default:4201) /* Nameless struct/union */
#endif
#endif

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
#endif
