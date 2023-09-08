////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/test_state2_storage.h"
#include "source/test_state2.h"

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class TTSO_TestState2_Storage

TTSO_TestState2_Storage::TTSO_TestState2_Storage()
 :m_count(0)
{;}

//------------------------------------------------------------------------
TTSO_TestState2_Storage::~TTSO_TestState2_Storage()
{;}

//interface --------------------------------------------------------------
TTSO_TestState2_Storage::count_type TTSO_TestState2_Storage::get_count()const
{
 const lock_guard_type __lock(m_guard);

 return m_count;
}//get_count

//------------------------------------------------------------------------
void TTSO_TestState2_Storage::append(const item_type& item)
{
 const lock_guard_type __lock(m_guard);

 if(m_count==structure::get_numeric_limits(m_count).max_value())
 {
  throw std::runtime_error("[BUG CHECK][TTSO_TestState2_Storage::append][1] item count overflow");
 }

 typedef file_type::position_type file_position_type;

 const file_position_type c_file_capacity
  =structure::t_numeric_limits<file_position_type>::max_value()/sizeof(item_type);

 if(c_file_capacity<m_count)
 {
  throw std::runtime_error("[BUG CHECK][TTSO_TestState2_Storage::append][2] file is full");
 }

 //-----------------------------------------
 file_position_type pos=m_count;

 pos*=sizeof(item_type);

 file_type::size_type Writed=0;

 assert(sizeof(item)==sizeof(item_type));

 m_file.write(pos,sizeof(item_type),&item,Writed); //throw

 if(Writed!=sizeof(item_type))
 {
  structure::str_formatter
   fmsg("[BUG CHECK][TTSO_TestState2_Storage::append][3]\n"
        "item size: %1. writed: %2.");

  fmsg<<sizeof(item_type)<<Writed;

  throw std::runtime_error(fmsg);
 }//if

 ++m_count;
}//append

//------------------------------------------------------------------------
void TTSO_TestState2_Storage::read(count_type const index,item_type* const item)const
{
 assert(index<m_count);
 assert(item!=NULL);

 const lock_guard_type __lock(m_guard);

 //-----------------------------------------
 typedef file_type::position_type file_position_type;

 file_position_type pos=index;

 pos*=sizeof(item_type);

 file_type::size_type Readed=0;

 assert(sizeof(*item)==sizeof(item_type));

 m_file.read(pos,sizeof(item_type),item,Readed); //throw

 if(Readed!=sizeof(item_type))
 {
  structure::str_formatter
   fmsg("[BUG CHECK][TTSO_TestState2_Storage::read][3]\n"
        "item size: %1. writed: %2. item index: %3.");

  fmsg<<sizeof(item_type)<<Readed<<index;

  throw std::runtime_error(fmsg);
 }//if
}//read

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
