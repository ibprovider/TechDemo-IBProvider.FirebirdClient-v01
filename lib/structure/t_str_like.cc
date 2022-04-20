////////////////////////////////////////////////////////////////////////////////
#ifndef _t_str_like_CC_
#define _t_str_like_CC_

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//template t_str_like

template<typename Iterator1,typename Iterator2>
t_str_like<Iterator1,Iterator2>::t_str_like(char_type any_sym,char_type any_seq)
 :m_any_sym(any_sym),
  m_any_seq(any_seq)
{;}

//------------------------------------------------------------------------
template<typename Iterator1,typename Iterator2>
bool t_str_like<Iterator1,Iterator2>::run(iterator1_type i_str,
                                          iterator1_type e_str,
                                          iterator2_type i_templ,
                                          iterator2_type e_templ)const
{
 restart_point_type_N restart_point;

 for(;;)
 {
  if(run_impl(i_str,e_str,i_templ,e_templ,restart_point))
   return true;

  if(restart_point.null())
   return false;

  assert(restart_point.value().i_str!=e_str);
  assert(restart_point.value().i_templ!=restart_point.value().e_templ);

  ++restart_point.value().i_str;

  i_str=std::search(restart_point.value().i_str,
                    e_str,
                    restart_point.value().i_templ,
                    restart_point.value().e_templ);

  if(i_str==e_str)
   return false;

  i_str+=(restart_point.value().e_templ-restart_point.value().i_templ);

  i_templ=restart_point.value().e_templ;
 }//while true
}//run

//------------------------------------------------------------------------
template<typename Iterator1,typename Iterator2>
bool t_str_like<Iterator1,Iterator2>::run_impl(iterator1_type        i_str,
                                               iterator1_type        e_str,
                                               iterator2_type        i_templ,
                                               iterator2_type        e_templ,
                                               restart_point_type_N& restart_point)const
{
 while(i_templ!=e_templ)
 {
  if((*i_templ)==m_any_seq)
  {
   ++i_templ;

   for(;i_templ!=e_templ && (*i_templ)==m_any_seq;++i_templ);

   if(i_templ==e_templ)
    return true;

   const iterator2_type i_start(i_templ);

   for(;i_templ!=e_templ;++i_templ)
   {
    if((*i_templ)==m_any_seq || (*i_templ)==m_any_sym)
     break;
   }//for

   assert(i_start!=i_templ);

   i_str=std::search(i_str,e_str,i_start,i_templ);

   if(i_str!=e_str)
   {
    restart_point_type tmp_point;

    tmp_point.i_templ =i_start;
    tmp_point.e_templ =i_templ;
    tmp_point.i_str   =i_str;

    restart_point=tmp_point;

    i_str+=(i_templ-i_start);

    continue;
   }
  }//if '%'

  if(i_str==e_str)
   return false;

  if((*i_templ)!=m_any_sym && (*i_str)!=(*i_templ))
   return false;

  ++i_str;
  ++i_templ;
 }//while

 return i_templ==e_templ && i_str==e_str;
}//run_impl

////////////////////////////////////////////////////////////////////////////////
//helper utilities

template<typename charT>
bool is_like_str(charT                                any_sym,
                 charT                                any_seq,
                 const __STL_DEF_BASIC_STRING(charT)& str,
                 const __STL_DEF_BASIC_STRING(charT)& templ)
{
 typedef __STL_DEF_BASIC_STRING(charT)::const_iterator iterator_type;

 typedef t_str_like<iterator_type,iterator_type> like_op_type;

 like_op_type like_op(any_sym,any_seq);

 return like_op.run(str.begin(),
                    str.end(),
                    templ.begin(),
                    templ.end());
}//is_like_str

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif