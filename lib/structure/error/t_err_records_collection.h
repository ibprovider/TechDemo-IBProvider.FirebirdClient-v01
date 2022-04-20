////////////////////////////////////////////////////////////////////////////////
//Implementation of t_err_records
//                                               Dmitry Kovalenko. 21.08.2004.
#ifndef _t_err_records_collection_H_
#define _t_err_records_collection_H_

#if(COMP_CONF_SUPPORT_PRAGMA_ONCE)
# pragma once
#endif

#include <structure/t_smart_vector.h>
#include <structure/error/t_err_records.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//containings

template<class Allocator>
class t_err_records_collection;

////////////////////////////////////////////////////////////////////////////////
//class t_err_records_collection

template<class Allocator>
class t_err_records_collection:public t_err_records_r
                              ,public t_err_records_w
{
 private:
  typedef t_err_records_collection<Allocator>              self_type;

  t_err_records_collection(const self_type& x);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef Allocator                                        allocator_type;

  typedef size_t                                           size_type;
  typedef t_err_record                                     record_type;
  typedef record_type::self_ptr                            record_ptr;

 private:
  typedef t_smart_vector<record_type,allocator_type>       record_vector_type;

 public:
  typedef typename record_vector_type::const_reference     const_reference;
  typedef typename record_vector_type::const_iterator      const_iterator;

 public:
  t_err_records_collection();

  virtual ~t_err_records_collection();

  //modificators ---------------------------------------------------------
  void clear();

  //selectors ------------------------------------------------------------
  size_type          size()   const       {return m_records.size();}
  bool               empty()  const       {return m_records.empty();}

  const_reference    front()  const       {return m_records.front();}
  const_reference    back()   const       {return m_records.back();}

  const_iterator     begin()  const       {return m_records.begin();}
  const_iterator     end()    const       {return m_records.end();}

  //t_err_records interface ----------------------------------------------
  virtual void        add_record(record_type* record) COMP_W000004_OVERRIDE_FINAL;

  virtual size_type   get_record_count()const COMP_W000004_OVERRIDE_FINAL;

  virtual record_ptr  get_record(size_type i)const COMP_W000004_OVERRIDE_FINAL;

 private:
  record_vector_type m_records;
};//class t_err_records_collection

////////////////////////////////////////////////////////////////////////////////
}//namespace structure

////////////////////////////////////////////////////////////////////////////////
#include <structure/error/t_err_records_collection.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
