////////////////////////////////////////////////////////////////////////////////
//Classes for work with VERSIONINFO resource
//                                                  Kovalenko Dmitry. 10.09.2007
#ifndef _win32_resource_versioninfo_H_
#define _win32_resource_versioninfo_H_

#include <win32lib/win32_memory_allocator.h>

#include <structure/error/t_err_exception_with_params.h>
#include <structure/error/t_err_record_with_params.h>
#include <structure/t_value_with_null.h>
#include <structure/t_message_entry.h>

namespace win32lib{
////////////////////////////////////////////////////////////////////////////////
//containings

class t_ver_info_element;
class t_ver_info_element__VS_VERSION_INFO;
class t_ver_info_element__String;
class t_ver_info_element__StringTable;
class t_ver_info_element__StringFileInfo;
class t_ver_info_element__Var;
class t_ver_info_element__VarFileInfo;

////////////////////////////////////////////////////////////////////////////////
//typedefs

typedef structure::t_smart_object_ptr<t_ver_info_element> t_ver_info_element_ptr;

////////////////////////////////////////////////////////////////////////////////

t_ver_info_element_ptr load_ver_info_element(const void* pvBlock,size_t cbBlock);

////////////////////////////////////////////////////////////////////////////////
//error sources

enum t_ver_info_src_id
{
 ver_info_src__load_ver_info_element               =1,

 ver_info_src__ver_info_element__VS_VERSION_INFO   =2,

 ver_info_src__ver_info_element__StringFileInfo    =3,

 ver_info_src__ver_info_element__StringTable       =4,

 ver_info_src__ver_info_element__String            =5,

 ver_info_src__ver_info_element__VarFileInfo       =6,

 ver_info_src__ver_info_element__Var               =7,
};//enum t_ver_info_src_id

////////////////////////////////////////////////////////////////////////////////
//error messages

enum t_ver_info_err_code
{
 //get size, min size
 ver_info_mce__bad_block_size_2                    =1,

 //cant detect key of version info block
 ver_info_mce__cant_detect_key_of_ver_info_block_0 =2,

 //element length, max length
 ver_info_mce__large_element_length_2              =3,

 //element length, max length
 ver_info_mce__small_element_length_2              =4,

 //element key
 ver_info_mce__unk_element_key_1                   =5,

 //structure name, value length, min value_length
 ver_info_mce__bad_size_of_structured_value_3      =6,

 ver_info_mce__VS_FIXEDFILEINFO_is_not_defined_0   =7,

 //key, entry size, value offset, value size
 ver_info_mce__bad_value_size_4                    =8,

 //key, entry_size, value offset
 //ver_info_mce__bad_value_offset_3                  =9,

 //key
 ver_info_mce__cant_process_string_value_1         =10,

 //key, length
 ver_info_mce__bad_var_array_length_2              =11,

 //Key, Type ID
 ver_info_mce__unknown_type_id_2                   =12,

 //Path
 ver_info_mce__bad_query_path_1                    =13,

 //Path
 ver_info_mce__query_path_not_exists_1             =14,
};//enum t_ver_info_err_code

////////////////////////////////////////////////////////////////////////////////
//class t_ver_info_error_traits

class t_ver_info_error_traits
{
 public: //typedefs ------------------------------------------------------
  typedef t_ver_info_src_id                                  source_id_type;
  typedef t_ver_info_err_code                                msg_id_type;
  typedef unsigned int                                       help_file_id_type;

 public:
  typedef structure::t_message_entry<source_id_type,const wchar_t*> src_entry_type;
  typedef structure::t_message_entry<msg_id_type,const wchar_t*>    msg_entry_type;

  typedef structure::t_err_record::lcid_type                 lcid_type;
  typedef structure::t_err_record::string_type               string_type;
  typedef structure::t_err_record::system_id_type            system_id_type;
  typedef structure::t_err_record::subsystem_id_type         subsystem_id_type;

 public:
  struct record_data_ext_type{};

 public:
  static system_id_type get_def_system_id()
   {return structure::t_err_record::system_user;}

  static subsystem_id_type get_def_subsystem_id()
   {return 0;}

 public:
  static bool get_msg(lcid_type,msg_id_type,string_type&);

  static void get_unknown_msg(lcid_type,string_type&);

  static const char* get_critical_error_msg(lcid_type);

  static bool get_source_name(lcid_type,source_id_type,string_type&);

  static bool get_help_file(lcid_type,help_file_id_type,string_type&);

 private:
  static const src_entry_type sm_sources[];

  static const msg_entry_type sm_msgs[];
};//class t_ver_info_error_traits

typedef structure::t_err_record_with_params
         <t_ver_info_error_traits>                t_ver_info_error_record;

typedef structure::t_err_exception_with_params
         <t_ver_info_error_record>                t_ver_info_error;

////////////////////////////////////////////////////////////////////////////////
//class t_ver_info_element

class t_ver_info_element
 :public structure::t_basic_smart_interface_impl__dynamic
          <structure::t_smart_interface,
           TWin32MemoryAllocator>
{
 private:
  typedef t_ver_info_element                         self_type;

  t_ver_info_element(const self_type&);
  self_type& operator = (const self_type&);

 protected:
  virtual ~t_ver_info_element();

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type>   self_ptr;

  typedef structure::t_str_parameter<wchar_t>        str_arg_type;

  typedef size_t                                     size_type;

  typedef t_ver_info_src_id                          src_id_type;

  struct tag_entry
  {
   WORD  wLength;
   WORD  wValueLength;
   WORD  wType;
   WCHAR szKey[1];

   const void* end()const
   {
    assert(sizeof(*this)<=wLength);

    return reinterpret_cast<const char*>(this)+this->wLength;
   }
  };//struct tag_entry

 public:
  explicit t_ver_info_element(src_id_type src_id);

  //selectors ------------------------------------------------------------
  src_id_type src_id()const;

  const std::wstring& key()const;

  //interface ------------------------------------------------------------
  virtual size_type child_count()const=0;

  virtual t_ver_info_element* child(size_type i)const=0;

  /// <summary>
  ///  Compare keys values
  /// </summary>
  virtual bool eq_key(const wchar_t* pwszKey,size_t cchKey);

  //query services -------------------------------------------------------
  /// <summary>
  ///  Query version info element.
  /// </summary>
  //! \param[in] path
  //!  Query string. Structure of query equal of ::VerQueryValue
  //! \param[in] must_exists
  //!  true, if query element must exists.
  //! \return
  //!  SmartPointer of finded element or null, if element is not found
  //!
  //! Samples of query string
  //! - "\"
  //! - "\VarFileInfo\Translation"
  //! - "\StringFileInfo\lang-charset\string-name"
  //!
  //! All spaces uses in search!
  self_ptr query(str_arg_type path,bool must_exists)const;

 protected:
  virtual const void* internal__load(const tag_entry& entry);

 private:
  const t_ver_info_src_id  m_src_id;

  std::wstring             m_key;
};//class t_ver_info_element

////////////////////////////////////////////////////////////////////////////////
//class t_ver_info_element__VS_VERSION_INFO

class t_ver_info_element__VS_VERSION_INFO LCPI_CPP_CFG__CLASS__FINAL
 :public t_ver_info_element
{
 private:
  typedef t_ver_info_element__VS_VERSION_INFO        self_type;
  typedef t_ver_info_element                         inherited;

  t_ver_info_element__VS_VERSION_INFO(const self_type&);
  self_type& operator = (const self_type&);

  t_ver_info_element__VS_VERSION_INFO();

  virtual ~t_ver_info_element__VS_VERSION_INFO();

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type>   self_ptr;

 public:
  static self_ptr create(const tag_entry& entry);

  //selectors ------------------------------------------------------------
  const VS_FIXEDFILEINFO* fixed_info(bool must_exists=true)const;

  //interface ------------------------------------------------------------
  virtual size_type child_count()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual t_ver_info_element* child(size_type i)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  virtual const void* internal__load(const tag_entry& entry) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  typedef TWin32MemoryAllocator                           allocator_type;

  typedef structure::t_value_with_null<VS_FIXEDFILEINFO>  ffi_type;

  typedef structure::t_stl_vector
            <t_ver_info_element::self_ptr,
             allocator_type>                              childs_type;

 private:
  ffi_type     m_ffi;
  childs_type  m_childs;
};//class t_ver_info_element__VS_VERSION_INFO

////////////////////////////////////////////////////////////////////////////////
//class t_ver_info_element__String

class t_ver_info_element__String LCPI_CPP_CFG__CLASS__FINAL
 :public t_ver_info_element
{
 private:
  typedef t_ver_info_element__String               self_type;
  typedef t_ver_info_element                       inherited;

  t_ver_info_element__String(const self_type&);
  self_type& operator = (const self_type&);

  t_ver_info_element__String();

  virtual ~t_ver_info_element__String();

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type> self_ptr;

  typedef std::pair<self_ptr,const void*>          create_result_type;

 public:
  static create_result_type create(const void* pvBlock,size_t cbBlock);

  //selectors ------------------------------------------------------------
  const std::wstring& value()const;

  //interface ------------------------------------------------------------
  virtual size_type child_count()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual t_ver_info_element* child(size_type i)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  virtual const void* internal__load(const tag_entry& entry) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  std::wstring m_value;
};//class t_ver_info_element__String

////////////////////////////////////////////////////////////////////////////////
//class t_ver_info_element__StringTable

class t_ver_info_element__StringTable LCPI_CPP_CFG__CLASS__FINAL
 :public t_ver_info_element
{
 private:
  typedef t_ver_info_element__StringTable          self_type;
  typedef t_ver_info_element                       inherited;

  t_ver_info_element__StringTable(const self_type&);
  self_type& operator = (const self_type&);

  t_ver_info_element__StringTable();

  virtual ~t_ver_info_element__StringTable();

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type> self_ptr;

  typedef std::pair<self_ptr,const void*>          create_result_type;

 public:
  static create_result_type create(const void* pvBlock,size_t cbBlock);

  //interface ------------------------------------------------------------
  virtual size_type child_count()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual t_ver_info_element__String* child(size_type i)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  virtual const void* internal__load(const tag_entry& entry) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  typedef TWin32MemoryAllocator                           allocator_type;

  typedef structure::t_stl_vector
            <t_ver_info_element__String::self_ptr,
             allocator_type>                              childs_type;

 private:
  childs_type m_childs;
};//class t_ver_info_element__StringTable

////////////////////////////////////////////////////////////////////////////////
//class t_ver_info_element__StringFileInfo

class t_ver_info_element__StringFileInfo LCPI_CPP_CFG__CLASS__FINAL
 :public t_ver_info_element
{
 private:
  typedef t_ver_info_element__StringFileInfo        self_type;
  typedef t_ver_info_element                        inherited;

  t_ver_info_element__StringFileInfo(const self_type&);
  self_type& operator = (self_type&);

  t_ver_info_element__StringFileInfo();

  virtual ~t_ver_info_element__StringFileInfo();

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type>  self_ptr;

 public:
  static self_ptr create(const tag_entry& entry);

  //interface ------------------------------------------------------------
  virtual size_type child_count()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual t_ver_info_element__StringTable* child(size_type i)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  virtual const void* internal__load(const tag_entry& entry) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  typedef TWin32MemoryAllocator                           allocator_type;

  typedef structure::t_stl_vector
            <t_ver_info_element__StringTable::self_ptr,
             allocator_type>                              childs_type;

 private:
  childs_type m_childs;
};//t_ver_info_element__StringFileInfo

////////////////////////////////////////////////////////////////////////////////
//class t_ver_info_element__Var

class t_ver_info_element__Var LCPI_CPP_CFG__CLASS__FINAL
 :public t_ver_info_element
{
 private:
  typedef t_ver_info_element__Var                      self_type;
  typedef t_ver_info_element                           inherited;

  t_ver_info_element__Var(const self_type&);
  self_type& operator = (const self_type&);

  t_ver_info_element__Var();

  virtual ~t_ver_info_element__Var();

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type>     self_ptr;

  typedef std::pair<self_ptr,const void*>              create_result_type;

 public:
  static create_result_type create(const void* pvBlock,size_t cbBlock);

  //selectors ------------------------------------------------------------
  size_type id_count()const;

  DWORD     id(size_type i)const;

  std::wstring id_as_str(size_type i)const;

  //interface ------------------------------------------------------------
  virtual size_type child_count()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual t_ver_info_element* child(size_type i)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  virtual const void* internal__load(const tag_entry& entry) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  typedef TWin32MemoryAllocator                           allocator_type;

  typedef structure::t_stl_vector
           <DWORD,
            allocator_type>                               ids_type;

 private:
  ids_type m_ids;
};//class t_ver_info_element__Var

////////////////////////////////////////////////////////////////////////////////
//class t_ver_info_element__VarFileInfo

class t_ver_info_element__VarFileInfo LCPI_CPP_CFG__CLASS__FINAL
 :public t_ver_info_element
{
 private:
  typedef t_ver_info_element__VarFileInfo              self_type;
  typedef t_ver_info_element                           inherited;

  t_ver_info_element__VarFileInfo(const self_type&);
  self_type& operator = (const self_type&);

  t_ver_info_element__VarFileInfo();

  virtual ~t_ver_info_element__VarFileInfo();

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type>     self_ptr;

 public:
  static self_ptr create(const tag_entry& entry);

  //interface ------------------------------------------------------------
  virtual size_type child_count()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual t_ver_info_element__Var* child(size_type i)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  virtual const void* internal__load(const tag_entry& entry) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  typedef TWin32MemoryAllocator                           allocator_type;

  typedef structure::t_stl_vector
           <t_ver_info_element__Var::self_ptr,
            allocator_type>                               childs_type;

 private:
  childs_type m_childs;
};//class t_ver_info_element__VarFileInfo

////////////////////////////////////////////////////////////////////////////////
}//namespace win32lib
#endif
