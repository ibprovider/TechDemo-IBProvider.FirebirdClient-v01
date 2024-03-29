///////////////////////////////////////////////////////////////////////////////
//LCPI C++ Infrastructure. Core.
//                                               Dmitry Kovalenko. 17.07.2019.
#ifndef _lcpi_infrastructure_core_structure__t_lcid_H_
#define _lcpi_infrastructure_core_structure__t_lcid_H_

#include <lcpi/infrastructure/core/structure/t_explicit.h>

#include <cstdint>

namespace lcpi{namespace infrastructure{namespace core{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_lcid

class LCPI_INFRASTRUCTURE_CORE__CFG__CLASS_STG t_lcid final
{
 private:
  using self_type=t_lcid;

 public: //typedefs
  enum enum_kind
  {
   kind__number      =0,
   kind__name        =1,
  };

 public:
  using char_type=char;

  using kind_type=enum_kind;

  using number_type=std::uint32_t;

  using name_ptr=const char_type*;

 public: //---------------------------------------------------------------
  t_lcid();

  t_lcid(number_type num);

  t_lcid(t_explicit<name_ptr> name);

  //selectors ------------------------------------------------------------
  kind_type      get_kind()const;

  number_type    get_number()const;

  name_ptr       get_name()const;

 private:
  kind_type       m_kind;

  union
  {
   number_type    m_number;
   name_ptr       m_name;
  };
};//class t_lcid

////////////////////////////////////////////////////////////////////////////////
//class t_lcid

inline t_lcid::t_lcid()
 :m_kind(self_type::kind__number)
{
 m_number=0;
}

//------------------------------------------------------------------------
inline t_lcid::t_lcid(number_type num)
 :m_kind(self_type::kind__number)
{
 m_number=num;
}

//------------------------------------------------------------------------
inline t_lcid::t_lcid(t_explicit<name_ptr> name)
 :m_kind(self_type::kind__name)
{
 m_name=name.value;
}

//------------------------------------------------------------------------
inline t_lcid::kind_type t_lcid::get_kind()const
{
 return m_kind;
}

//------------------------------------------------------------------------
inline t_lcid::number_type t_lcid::get_number()const
{
 return (m_kind==self_type::kind__number)?m_number:0;
}

//------------------------------------------------------------------------
inline t_lcid::name_ptr t_lcid::get_name()const
{
 return (m_kind==self_type::kind__name)?m_name:"";
}

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms core*/}/*nms infrastructure*/}/*nms lcpi*/
#endif
