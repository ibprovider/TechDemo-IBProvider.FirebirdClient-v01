////////////////////////////////////////////////////////////////////////////////
//Test FrameWork. SET01.
//                                                Kovalenko Dmitry. 07.12.2017.
#ifndef _test_fw_set01__tracer_utils_H_
#define _test_fw_set01__tracer_utils_H_

#include <structure/test_obj/t_tso_lib.h>

namespace structure{namespace test_fw{namespace set01{
////////////////////////////////////////////////////////////////////////////////
//class TestFW__TracerAutoSend

template<class TTracer>
class TestFW__Basic_TracerAutoSend
{
 private:
  typedef TestFW__Basic_TracerAutoSend<TTracer>       self_type;

  TestFW__Basic_TracerAutoSend(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef TTracer                                     tracer_type;

 public:
  explicit TestFW__Basic_TracerAutoSend(tracer_type& tracer)
   :m_tracer(tracer)
  {;}

 ~TestFW__Basic_TracerAutoSend()
  {
   m_tracer.send();
  }

 private:
  tracer_type& m_tracer;
};//class TestFW__Basic_TracerAutoSend

////////////////////////////////////////////////////////////////////////////////
//class TestFW__Basic_TraceDataOrNA

template<class TData>
class TestFW__Basic_TraceDataOrNA
{
 private:
  typedef TestFW__Basic_TraceDataOrNA<TData>         self_type;

  self_type& operator = (const self_type&);

 public:
  TestFW__Basic_TraceDataOrNA(bool ok,const TData& data)
   :m_data(data)
   ,m_ok  (ok)
  {;}

  TestFW__Basic_TraceDataOrNA(const self_type& x)
   :m_data (x.m_data)
   ,m_ok   (x.m_ok)
  {;}

  //selectors ------------------------------
  const TData& data()const
  {
   return m_data;
  }

  bool ok()const
  {
   return m_ok;
  }

 private:
  TData m_data;
  bool  m_ok;
};//class TestFW__Basic_TraceDataOrNA

////////////////////////////////////////////////////////////////////////////////

template<class Allocator,class TData>
structure::tso_obj::t_basic_tracer<Allocator>&
 operator << (structure::tso_obj::t_basic_tracer<Allocator>& tracer,
              const TestFW__Basic_TraceDataOrNA<TData>&      x)
{
 if(x.ok())
  return tracer<<x.data();

 return tracer<<L"n/a";
}//operator <<

////////////////////////////////////////////////////////////////////////////////

template<class TData>
TestFW__Basic_TraceDataOrNA<TData>
 TestFW_TraceDataOrNA(bool ok,const TData& data)
{
 return TestFW__Basic_TraceDataOrNA<TData>(ok,data);
}//TestFW_TraceDataOrNA

////////////////////////////////////////////////////////////////////////////////
//class tag_tracer_data__ptr

class tag_tracer_data__ptr
{
 public:
  const void* m_ptr;

  explicit tag_tracer_data__ptr(const void* const ptr)
   :m_ptr(ptr)
  {
  }
};//class tag_tracer_data__ptr

//------------------------------------------------------------------------
template<class Allocator>
structure::tso_obj::t_basic_tracer<Allocator>&
 operator << (structure::tso_obj::t_basic_tracer<Allocator>& tracer,
              const tag_tracer_data__ptr&                    d)
{
 if(!d.m_ptr)
  return tracer<<L"NULL";

 return tracer<<L"NOT NULL";
}//operator <<

//------------------------------------------------------------------------
inline tag_tracer_data__ptr trace_ptr(const void* ptr)
{
 return tag_tracer_data__ptr(ptr);
}//trace_ptr

////////////////////////////////////////////////////////////////////////////////
//class tag_tracer_data__pvalue

template<typename T>
class tag_tracer_data__pvalue
{
 public:
  const T* m_ptr;

  explicit tag_tracer_data__pvalue(const T* const ptr)
   :m_ptr(ptr)
  {
  }
};//class tag_tracer_data__pvalue

//------------------------------------------------------------------------
template<class Allocator,typename T>
structure::tso_obj::t_basic_tracer<Allocator>&
 operator << (structure::tso_obj::t_basic_tracer<Allocator>& tracer,
              const tag_tracer_data__pvalue<T>&              d)
{
 if(!d.m_ptr)
  return tracer<<L"NULL";

 return tracer<<*d.m_ptr;
}//operator <<

//------------------------------------------------------------------------
template<typename T>
inline tag_tracer_data__pvalue<T> trace_pvalue(const T* const ptr)
{
 return tag_tracer_data__pvalue<T>(ptr);
}//trace_pvalue

////////////////////////////////////////////////////////////////////////////////
//class tag_tracer_data__pptr

template<typename T>
class tag_tracer_data__pptr
{
 public:
  const T* const* m_pptr;

  explicit tag_tracer_data__pptr(const T* const* pptr)
   :m_pptr(pptr)
  {
  }
};//class tag_tracer_data__pptr

//------------------------------------------------------------------------
template<class Allocator,typename T>
structure::tso_obj::t_basic_tracer<Allocator>&
 operator << (structure::tso_obj::t_basic_tracer<Allocator>& tracer,
              const tag_tracer_data__pptr<T>&                d)
{
 if(!d.m_pptr)
  return tracer<<L"NULL";

 if(!*d.m_pptr)
  return tracer<<L"(NULL)";

 return tracer<<L"(NOT NULL)";
}//operator <<

//------------------------------------------------------------------------
template<typename T>
inline tag_tracer_data__pptr<T> trace_pptr(const T* const* const pptr)
{
 return tag_tracer_data__pptr<T>(pptr);
}//trace_pptr

////////////////////////////////////////////////////////////////////////////////
//class tag_tracer_data__psz

template<typename charT>
class tag_tracer_data__psz
{
 public:
  const charT* m_psz;

  explicit tag_tracer_data__psz(const charT* const psz)
   :m_psz(psz)
  {
  }
};//class tag_tracer_data__psz

//------------------------------------------------------------------------
template<class Allocator,typename charT>
structure::tso_obj::t_basic_tracer<Allocator>&
 operator << (structure::tso_obj::t_basic_tracer<Allocator>& tracer,
              const tag_tracer_data__psz<charT>&             d)
{
 if(!d.m_psz)
  return tracer<<L"NULL";

 return tracer<<L"\""<<(d.m_psz)<<"\"";
}//operator <<

//------------------------------------------------------------------------
inline tag_tracer_data__psz<wchar_t> trace_pwsz(const wchar_t* const pwsz)
{
 return tag_tracer_data__psz<wchar_t>(pwsz);
}//trace_pwsz

////////////////////////////////////////////////////////////////////////////////
//class tag_tracer_data__ppsz

template<typename charT>
class tag_tracer_data__ppsz
{
 public:
  const charT* const* m_ppsz;

  explicit tag_tracer_data__ppsz(const charT* const* ppsz)
   :m_ppsz(ppsz)
  {
  }
};//class tag_tracer_data__ppsz

//------------------------------------------------------------------------
template<class Allocator,typename charT>
structure::tso_obj::t_basic_tracer<Allocator>&
 operator << (structure::tso_obj::t_basic_tracer<Allocator>& tracer,
              const tag_tracer_data__ppsz<charT>&            d)
{
 if(!d.m_ppsz)
  return tracer<<L"NULL";

 if(!*d.m_ppsz)
  return tracer<<L"(NULL)";

 return tracer<<L"("<<(*d.m_ppsz)<<")";
}//operator <<

//------------------------------------------------------------------------
inline tag_tracer_data__ppsz<wchar_t> trace_ppwsz(const wchar_t* const* const ppwsz)
{
 return tag_tracer_data__ppsz<wchar_t>(ppwsz);
}//trace_ppwsz

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms test_fw*/}/*nms structure*/
////////////////////////////////////////////////////////////////////////////////
#endif
