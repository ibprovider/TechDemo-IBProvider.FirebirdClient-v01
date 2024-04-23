////////////////////////////////////////////////////////////////////////////////
//LCPI instrumental C++ library.
//                                                 Dmitry Kovalenko. 28.01.2005.
#ifndef _lcpi_lib_structure__t_str_cvt_traits__unicode_or_ascii_H_
#define _lcpi_lib_structure__t_str_cvt_traits__unicode_or_ascii_H_

#include <structure/t_const_str_box.h>

#include <algorithm>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_str_cvt_traits__unicode_or_ascii

class t_str_cvt_traits__unicode_or_ascii LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=t_str_cvt_traits__unicode_or_ascii;

 public:
  template<class TDest,class TSrc>
  static void tstr_to_tstr(TDest* const pDest,TSrc&& src)
  {
   self_type::helper__tstr_to_tstr(pDest,std::forward<TSrc>(src));
  }//tstr_to_tstr

 public:
  template<class TDest,class TSrc>
  static bool try__tstr_to_tstr(TDest* const pDest,TSrc&& src)
  {
   return self_type::helper__try__tstr_to_tstr(pDest,std::forward<TSrc>(src));
  }//try__tstr_to_tstr

 private:
  using str_box_type=structure::t_const_str_box;

  using wstr_box_type=structure::t_const_wstr_box;
 
 private:
  static void helper__tstr_to_tstr(std::wstring* const result,std::wstring&& source)
  {
   LCPI__assert(result!=nullptr);

   (*result)=LCPI_STL_MOVE_VALUE(source);
  }//helper__tstr_to_tstr

  //----------------------------------------------------------------------
  static void helper__tstr_to_tstr(std::wstring* const result,const wchar_t* const source)
  {
   LCPI__assert(result!=nullptr);

   if(source==nullptr)
    (*result).clear();
   else
    (*result)=source;
  }//helper__tstr_to_tstr

  //----------------------------------------------------------------------
  static void helper__tstr_to_tstr(std::wstring* const result,wstr_box_type const source)
  {
   LCPI__assert(result!=nullptr);

   result->assign(source.begin(),source.end());
  }//helper__tstr_to_tstr

  //----------------------------------------------------------------------
  static void helper__tstr_to_tstr(std::wstring* const result,str_box_type const source)
  {
   self_type::helper__check_ascii(source);

   result->assign(source.begin(),source.end());
  }//helper__tstr_to_tstr

  //----------------------------------------------------------------------
  static void helper__tstr_to_tstr(std::string* const result,std::string&& source)
  {
   self_type::helper__check_ascii(source);

   (*result)=LCPI_STL_MOVE_VALUE(source);
  }//helper__tstr_to_tstr

  //----------------------------------------------------------------------
  static void helper__tstr_to_tstr(std::string* const result,const char* const source)
  {
   LCPI__assert(result!=nullptr);

   if(source==nullptr)
   {
    (*result).clear();
   }
   else
   {
    self_type::helper__check_ascii(source);

    (*result)=source;
   }//else
  }//helper__tstr_to_tstr

  //----------------------------------------------------------------------
  static void helper__tstr_to_tstr(std::string* const result,str_box_type const source)
  {
   LCPI__assert(result!=nullptr);

   self_type::helper__check_ascii(source);

   result->assign(source.begin(),source.end());
  }//helper__tstr_to_tstr

  //----------------------------------------------------------------------
  static void helper__tstr_to_tstr(std::string* const result,wstr_box_type const source)
  {
   LCPI__assert(result!=nullptr);

   self_type::helper__check_ascii(source);

   result->resize(source.size());

   auto x=result->begin();

   for(auto ch:source)
   {
    (*x)=static_cast<std::string::value_type>(ch);

    ++x;
   }//for ch
  }//helper__tstr_to_tstr

 private:
  static bool helper__try__tstr_to_tstr(std::wstring* const result,std::wstring&& source)
  {
   LCPI__assert(result!=nullptr);

   (*result)=LCPI_STL_MOVE_VALUE(source);

   return true;
  }//helper__try__tstr_to_tstr

  //----------------------------------------------------------------------
  static bool helper__try__tstr_to_tstr(std::wstring* const result,const wchar_t* const source)
  {
   LCPI__assert(result!=nullptr);

   if(source==nullptr)
    (*result).clear();
   else
    (*result)=source;

   return true;
  }//helper__try__tstr_to_tstr

  //----------------------------------------------------------------------
  static bool helper__try__tstr_to_tstr(std::wstring* const result,wstr_box_type const source)
  {
   LCPI__assert(result!=nullptr);

   result->assign(source.begin(),source.end());

   return true;
  }//helper__try__tstr_to_tstr

  //----------------------------------------------------------------------
  static bool helper__try__tstr_to_tstr(std::wstring* const result,str_box_type const source)
  {
   self_type::helper__check_ascii(source);

   result->assign(source.begin(),source.end());

   return true;
  }//helper__try__tstr_to_tstr

  //----------------------------------------------------------------------
  static bool helper__try__tstr_to_tstr(std::string* const result,std::string&& source)
  {
   self_type::helper__check_ascii(source);

   (*result)=LCPI_STL_MOVE_VALUE(source);

   return true;
  }//helper__try__tstr_to_tstr

  //----------------------------------------------------------------------
  static bool helper__try__tstr_to_tstr(std::string* const result,const char* const source)
  {
   LCPI__assert(result!=nullptr);

   if(source==nullptr)
   {
    (*result).clear();
   }
   else
   if(self_type::helper__is_ascii(source))
   {
    (*result)=source;
   }
   else
   {
    return false;
   }//else

   return true;
  }//helper__try__tstr_to_tstr

  //----------------------------------------------------------------------
  static bool helper__try__tstr_to_tstr(std::string* const result,str_box_type const source)
  {
   LCPI__assert(result!=nullptr);

   if(!self_type::helper__is_ascii(source))
    return false;

   result->assign(source.begin(),source.end());

   return true;
  }//helper__try__tstr_to_tstr

  //----------------------------------------------------------------------
  static bool helper__try__tstr_to_tstr(std::string* const result,wstr_box_type const source)
  {
   LCPI__assert(result!=nullptr);

   if(!self_type::helper__is_ascii(source))
    return false;

   result->resize(source.size());

   auto x=result->begin();

   for(auto ch:source)
   {
    (*x)=static_cast<std::string::value_type>(ch);

    ++x;
   }//for ch

   return true;
  }//helper__try__tstr_to_tstr

 private: //--------------------------------------------------------------
  static void helper__check_ascii(str_box_type const str)
  {
   if(!self_type::helper__is_ascii(str))
    self_type::helper__throw_error("Multibyte source contains non ASCII symbols.");
  }//helper__check_ascii

  //----------------------------------------------------------------------
  static void helper__check_ascii(wstr_box_type const str)
  {
   if(!self_type::helper__is_ascii(str))
    self_type::helper__throw_error("Unicode source contains non ASCII symbols.");
  }//helper__check_ascii

  //----------------------------------------------------------------------
  static bool helper__is_ascii(str_box_type const str)
  {
   using ch_type=str_box_type::value_type;
   using unsigned_ch_t=std::make_unsigned<ch_type>::type;

   const auto x=std::find_if_not(str.begin(),str.end(),[](char ch){return unsigned_ch_t(ch)<=127;});

   if(x!=str.end())
    return false;

   return true;
  }//helper__is_ascii

  //----------------------------------------------------------------------
  static bool helper__is_ascii(wstr_box_type const str)
  {
   using ch_type=wstr_box_type::value_type;
   using unsigned_ch_t=std::make_unsigned<ch_type>::type;

   const auto x=std::find_if_not(str.begin(),str.end(),[](wchar_t ch){return unsigned_ch_t(ch)<=127;});

   if(x!=str.end())
    return false;

   return true;
  }//helper__is_ascii

  //----------------------------------------------------------------------
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void helper__throw_error(const char* const msg)
  {
   LCPI__assert(msg);

   throw std::runtime_error(std::string("[BUG CHECK][t_str_cvt_traits__unicode_or_ascii] ").append(msg));
  }//helper__throw_error
};//class t_str_cvt_traits__unicode_or_ascii

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
