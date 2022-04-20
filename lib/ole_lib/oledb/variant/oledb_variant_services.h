////////////////////////////////////////////////////////////////////////////////
//Services for each OLEDB DataType
//                                             Kovalenko Dmitry. Long long time ago.
#ifndef _oledb_variant_services_H_
#define _oledb_variant_services_H_

#include <ole_lib/oledb/variant/oledb_variant.h>

namespace oledb_lib{namespace oledb_lib_utils{
////////////////////////////////////////////////////////////////////////////////
//helper macros

#define DECLARE_OLEDB_TYPE_SERVICE(dbtype,type)                                 \
struct t_oledb_type_service_##dbtype:public DBVARIANT::TTypeService             \
{                                                                               \
 private:                                                                       \
  typedef t_oledb_type_service_##dbtype                self_type;               \
  typedef DBVARIANT::TTypeService                      inherited;               \
                                                                                \
  t_oledb_type_service_##dbtype(const self_type&);                              \
  self_type& operator = (const self_type&);                                     \
                                                                                \
 public:                                                                        \
  typedef type                                         value_type;              \
                                                                                \
 public:                                                                        \
  t_oledb_type_service_##dbtype()                                               \
   :inherited(oledb_lib::oledb_typeid__##dbtype)                                \
  {;}                                                                           \
                                                                                \
  virtual length_type                                                           \
   get_binary_length(length_type DataLength)const COMP_W000004_OVERRIDE_FINAL;  \
                                                                                \
  virtual length_type                                                           \
   get_align()const COMP_W000004_OVERRIDE_FINAL;                                \
                                                                                \
  virtual HRESULT                                                               \
   get_element(DBVARIANT*   dest,                                               \
               REFIID       ElementIID,                                         \
               length_type  cbElement,                                          \
               const void*  pElement)const COMP_W000004_OVERRIDE_FINAL;         \
                                                                                \
  virtual HRESULT                                                               \
   set_element(LPCCONVCONTEXT   pConvCtx,                                       \
               const DBVARIANT& source,                                         \
               REFIID           ElementIID,                                     \
               length_type      cbElement,                                      \
               void*            pElement,                                       \
               status_type*     pBinding_Status)const COMP_W000004_OVERRIDE_FINAL; \
                                                                                \
  virtual DBVARIANT::LPCTYPECONVERTER                                           \
   get_convertor(DBTYPE TargetType)const COMP_W000004_OVERRIDE_FINAL;           \
                                                                                \
  virtual std::wstring                                                          \
   get_print_wstr(const DBVARIANT& dbvar)const COMP_W000004_OVERRIDE_FINAL;     \
                                                                                \
 private:                                                                       \
  virtual length_type                                                           \
   internal__get_length__ok                                                     \
    (const DBVARIANT& dbvar)const COMP_W000004_OVERRIDE_FINAL;                  \
                                                                                \
  virtual void                                                                  \
   internal__get_size__ok                                                       \
    (const DBVARIANT&  dbvar,                                                   \
     length_type&      cbSize,                                                  \
     length_type&      cbMemSize,                                               \
     length_type&      cbMinSize)const COMP_W000004_OVERRIDE_FINAL;             \
                                                                                \
  virtual HRESULT                                                               \
   internal__get_data__ok                                                       \
    (const DBVARIANT& dbvar,                                                    \
     const DBBINDING& Binding,                                                  \
     length_type      cbMemSize,                                                \
     status_type&     Binding_Status,                                           \
     length_type&     Binding_Length,                                           \
     void*            pBuffer)const COMP_W000004_OVERRIDE_FINAL;                \
};                                                                              \
                                                                                \
extern t_oledb_type_service_##dbtype g_service_##dbtype;

////////////////////////////////////////////////////////////////////////////////
//declarations

DECLARE_OLEDB_TYPE_SERVICE(EMPTY       ,void                              )
DECLARE_OLEDB_TYPE_SERVICE(NULL        ,void                              )
DECLARE_OLEDB_TYPE_SERVICE(UI1         ,t_oledb_value__UI1                )
DECLARE_OLEDB_TYPE_SERVICE(UI2         ,t_oledb_value__UI2                )
DECLARE_OLEDB_TYPE_SERVICE(UI4         ,t_oledb_value__UI4                )
DECLARE_OLEDB_TYPE_SERVICE(UI8         ,t_oledb_value__UI8_s              )
DECLARE_OLEDB_TYPE_SERVICE(I1          ,t_oledb_value__I1                 )
DECLARE_OLEDB_TYPE_SERVICE(I2          ,t_oledb_value__I2                 )
DECLARE_OLEDB_TYPE_SERVICE(I4          ,t_oledb_value__I4                 )
DECLARE_OLEDB_TYPE_SERVICE(I8          ,t_oledb_value__I8_s               )
DECLARE_OLEDB_TYPE_SERVICE(CY          ,t_oledb_value__CY                 )
DECLARE_OLEDB_TYPE_SERVICE(R4          ,t_oledb_value__R4                 )
DECLARE_OLEDB_TYPE_SERVICE(R8          ,t_oledb_value__R8                 )
DECLARE_OLEDB_TYPE_SERVICE(NUMERIC     ,t_oledb_value__NUMERIC            )
DECLARE_OLEDB_TYPE_SERVICE(DECIMAL     ,t_oledb_value__DECIMAL            )
DECLARE_OLEDB_TYPE_SERVICE(BOOL        ,VARIANT_BOOL                      )
DECLARE_OLEDB_TYPE_SERVICE(ERROR       ,t_oledb_value__SCODE              )
DECLARE_OLEDB_TYPE_SERVICE(VARIANT     ,VARIANT                           )
DECLARE_OLEDB_TYPE_SERVICE(DATE        ,t_oledb_value__DATE               )
DECLARE_OLEDB_TYPE_SERVICE(DBDATE      ,t_oledb_value__DBDATE             )
DECLARE_OLEDB_TYPE_SERVICE(DBTIME      ,t_oledb_value__DBTIME             )
DECLARE_OLEDB_TYPE_SERVICE(DBTIME2     ,t_oledb_value__DBTIME2            )
DECLARE_OLEDB_TYPE_SERVICE(DBTIMESTAMP ,t_oledb_value__DBTIMESTAMP        )
DECLARE_OLEDB_TYPE_SERVICE(BSTR        ,BSTR                              )
DECLARE_OLEDB_TYPE_SERVICE(STR         ,t_oledb_value__CHAR               )
DECLARE_OLEDB_TYPE_SERVICE(WSTR        ,t_oledb_value__WCHAR              )
DECLARE_OLEDB_TYPE_SERVICE(BYTES       ,BYTE                              )
DECLARE_OLEDB_TYPE_SERVICE(FILETIME    ,t_oledb_value__FILETIME           )
DECLARE_OLEDB_TYPE_SERVICE(GUID        ,t_oledb_value__GUID               )
DECLARE_OLEDB_TYPE_SERVICE(IUNKNOWN    ,IUnknown*                         )
DECLARE_OLEDB_TYPE_SERVICE(IDISPATCH   ,IDispatch*                        )

////////////////////////////////////////////////////////////////////////////////
//ARRAY data types - one service class for ARRAY data types

struct t_oledb_type_service_ARRAY:public DBVARIANT::TTypeService
{
 private:
  typedef t_oledb_type_service_ARRAY           self_type;
  typedef DBVARIANT::TTypeService              inherited;

 public:
  typedef LPSAFEARRAY                          value_type;

 public:
  t_oledb_type_service_ARRAY(DBTYPE const wElementType)
   :inherited(DBTYPE(DBTYPE_ARRAY|wElementType))
  {;}

  virtual length_type get_align()const COMP_W000004_OVERRIDE_FINAL;

  virtual HRESULT get_element(DBVARIANT*   dest,
                              REFIID       ElementIID, 
                              length_type  cbElement,
                              const void*  pElement)const COMP_W000004_OVERRIDE_FINAL;

  virtual HRESULT set_element(LPCCONVCONTEXT   pConvCtx,
                              const DBVARIANT& source,
                              REFIID           ElementIID,
                              length_type      cbElement,
                              void*            pElement,
                              status_type*     pBinding_Status)const COMP_W000004_OVERRIDE_FINAL;

  virtual std::wstring get_print_wstr(const DBVARIANT& dbvar)const COMP_W000004_OVERRIDE_FINAL;

 private:
  virtual void
   internal__get_size__ok
    (const DBVARIANT&  dbvar,
     length_type&      cbSize,
     length_type&      cbMemSize,
     length_type&      cbMinSize)const COMP_W000004_OVERRIDE_FINAL;

  virtual HRESULT
   internal__get_data__ok
    (const DBVARIANT& dbvar,
     const DBBINDING& Binding,
     length_type      cbMemSize,
     status_type&     Binding_Status,
     length_type&     Binding_Length,
     void*            pBuffer)const COMP_W000004_OVERRIDE_FINAL;
};//t_oledb_type_service_ARRAY

////////////////////////////////////////////////////////////////////////////////
//Специализация сервиса массивов под конкретный тип элемента

#define DECLARE_OLEDB_ARRAY_TYPE_SERVICE(dbtype,type)                           \
class t_oledb_type_service_ARRAY_##dbtype:public t_oledb_type_service_ARRAY     \
{                                                                               \
 private:                                                                       \
  typedef t_oledb_type_service_ARRAY_##dbtype   self_type;                      \
  typedef t_oledb_type_service_ARRAY            inherited;                      \
                                                                                \
  t_oledb_type_service_ARRAY_##dbtype(const self_type&);                        \
  self_type& operator = (const self_type&);                                     \
                                                                                \
 public:                                                                        \
  typedef type                                  element_type;                   \
                                                                                \
  typedef DBVARIANT::LPCTYPECONVERTER           LPCTYPECONVERTER;               \
                                                                                \
  enum                                                                          \
  {                                                                             \
   element_dbtype=oledb_lib::oledb_typeid__##dbtype                             \
  };                                                                            \
                                                                                \
 public:                                                                        \
  t_oledb_type_service_ARRAY_##dbtype()                                         \
   :inherited(oledb_typeid__##dbtype)                                           \
  {;}                                                                           \
                                                                                \
  virtual length_type                                                           \
   get_binary_length(length_type DataLength)const COMP_W000004_OVERRIDE_FINAL;  \
                                                                                \
  virtual LPCTYPECONVERTER                                                      \
   get_convertor(DBTYPE TargetType)const COMP_W000004_OVERRIDE_FINAL;           \
                                                                                \
 private:                                                                       \
  virtual length_type                                                           \
   internal__get_length__ok                                                     \
    (const DBVARIANT& dbvar)const COMP_W000004_OVERRIDE_FINAL;                  \
};                                                                              \
                                                                                \
extern const t_oledb_type_service_ARRAY_##dbtype g_service_ARRAY_##dbtype;

////////////////////////////////////////////////////////////////////////////////
//declarations of array data type service objects

DECLARE_OLEDB_ARRAY_TYPE_SERVICE(EMPTY       ,void                        )
DECLARE_OLEDB_ARRAY_TYPE_SERVICE(NULL        ,void                        )
DECLARE_OLEDB_ARRAY_TYPE_SERVICE(UI1         ,t_oledb_value__UI1          )
DECLARE_OLEDB_ARRAY_TYPE_SERVICE(UI2         ,t_oledb_value__UI2          )
DECLARE_OLEDB_ARRAY_TYPE_SERVICE(UI4         ,t_oledb_value__UI4          )
DECLARE_OLEDB_ARRAY_TYPE_SERVICE(UI8         ,t_oledb_value__UI8_s        )
DECLARE_OLEDB_ARRAY_TYPE_SERVICE(I1          ,t_oledb_value__I1           )
DECLARE_OLEDB_ARRAY_TYPE_SERVICE(I2          ,t_oledb_value__I2           )
DECLARE_OLEDB_ARRAY_TYPE_SERVICE(I4          ,t_oledb_value__I4           )
DECLARE_OLEDB_ARRAY_TYPE_SERVICE(I8          ,t_oledb_value__I8_s         )
DECLARE_OLEDB_ARRAY_TYPE_SERVICE(CY          ,t_oledb_value__CY           )
DECLARE_OLEDB_ARRAY_TYPE_SERVICE(R4          ,t_oledb_value__R4           )
DECLARE_OLEDB_ARRAY_TYPE_SERVICE(R8          ,t_oledb_value__R8           )
DECLARE_OLEDB_ARRAY_TYPE_SERVICE(NUMERIC     ,t_oledb_value__NUMERIC      )
DECLARE_OLEDB_ARRAY_TYPE_SERVICE(DECIMAL     ,t_oledb_value__DECIMAL      )
DECLARE_OLEDB_ARRAY_TYPE_SERVICE(BOOL        ,VARIANT_BOOL                )
DECLARE_OLEDB_ARRAY_TYPE_SERVICE(ERROR       ,t_oledb_value__SCODE        )
DECLARE_OLEDB_ARRAY_TYPE_SERVICE(VARIANT     ,VARIANT                     )
DECLARE_OLEDB_ARRAY_TYPE_SERVICE(DATE        ,t_oledb_value__DATE         )
DECLARE_OLEDB_ARRAY_TYPE_SERVICE(DBDATE      ,t_oledb_value__DBDATE       )
DECLARE_OLEDB_ARRAY_TYPE_SERVICE(DBTIME      ,t_oledb_value__DBTIME       )
DECLARE_OLEDB_ARRAY_TYPE_SERVICE(DBTIME2     ,t_oledb_value__DBTIME2      )
DECLARE_OLEDB_ARRAY_TYPE_SERVICE(DBTIMESTAMP ,t_oledb_value__DBTIMESTAMP  )
DECLARE_OLEDB_ARRAY_TYPE_SERVICE(BSTR        ,BSTR                        )
DECLARE_OLEDB_ARRAY_TYPE_SERVICE(STR         ,t_oledb_value__CHAR         )
DECLARE_OLEDB_ARRAY_TYPE_SERVICE(WSTR        ,t_oledb_value__WCHAR        )
DECLARE_OLEDB_ARRAY_TYPE_SERVICE(BYTES       ,BYTE                        )
DECLARE_OLEDB_ARRAY_TYPE_SERVICE(FILETIME    ,t_oledb_value__FILETIME     )
DECLARE_OLEDB_ARRAY_TYPE_SERVICE(GUID        ,t_oledb_value__GUID         )
DECLARE_OLEDB_ARRAY_TYPE_SERVICE(IUNKNOWN    ,IUnknown*                   )
DECLARE_OLEDB_ARRAY_TYPE_SERVICE(IDISPATCH   ,IDispatch*                  )

////////////////////////////////////////////////////////////////////////////////
#undef DECLARE_OLEDB_ARRAY_TYPE_SERVICE
#undef DECLARE_OLEDB_TYPE_SERVICE
////////////////////////////////////////////////////////////////////////////////
}/*nms oledb_lib_utils*/}//nms oledb_lib
#endif
