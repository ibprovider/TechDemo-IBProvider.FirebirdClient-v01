////////////////////////////////////////////////////////////////////////////////
#ifndef _t_err_records_collection_CC_
#define _t_err_records_collection_CC_

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_err_records_collection

template<class Allocator>
inline t_err_records_collection<Allocator>::t_err_records_collection()
{;}

//------------------------------------------------------------------------
template<class Allocator>
t_err_records_collection<Allocator>::~t_err_records_collection()
{;}

//modificators -----------------------------------------------------------
template<class Allocator>
void t_err_records_collection<Allocator>::clear()
{
 m_records.clear();
}//clear

//t_err_records interface ------------------------------------------------
template<class Allocator>
void t_err_records_collection<Allocator>::add_record(record_type* const record)
{
 assert(record);

 m_records.push_back(record);
}//add_record

//------------------------------------------------------------------------
template<class Allocator>
typename t_err_records_collection<Allocator>::size_type
 t_err_records_collection<Allocator>::get_record_count()const
{
 return m_records.size();
}

//------------------------------------------------------------------------
template<class Allocator>
typename t_err_records_collection<Allocator>::record_ptr
 t_err_records_collection<Allocator>::get_record(size_type i)const
{
 assert_msg(i<m_records.size(),"i="<<i<<"\nsize="<<m_records.size());

 return m_records[i];
}//get_record

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
