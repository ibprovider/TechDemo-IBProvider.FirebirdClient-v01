////////////////////////////////////////////////////////////////////////////////
//IBProvider - OLE DB Provider for Firebird/InterBase.
//                                                 Kovalenko Dmitry. 29.10.2022.
#include <_pch_.h>
#pragma hdrstop

//#include "source_lib/ole_lib/ibp--ole_lib__base_unknown2.h"

namespace ole_lib{
////////////////////////////////////////////////////////////////////////////////
//class TBaseUnknown2__SERVER_LINK_DATA_REAL

class TBaseUnknown2__SERVER_LINK_DATA_REAL LCPI_CPP_CFG__CLASS__FINAL
 :public IBP_DEF_INTERFACE_IMPL_DYNAMIC(TBaseUnknown2__SERVER_LINK_DATA)
{
 private:
  typedef TBaseUnknown2__SERVER_LINK_DATA_REAL                  self_type;

  TBaseUnknown2__SERVER_LINK_DATA_REAL(const self_type&);
  self_type& operator = (const self_type&);

 private:
  TBaseUnknown2__SERVER_LINK_DATA_REAL();

  virtual ~TBaseUnknown2__SERVER_LINK_DATA_REAL();

 public:
  static self_ptr Create();

  //interface ------------------------------------------------------------
  virtual bool IsReal()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual void IncrementComponentCount() LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual void DecrementComponentCount() LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;
};//class TBaseUnknown2__SERVER_LINK_DATA_REAL

////////////////////////////////////////////////////////////////////////////////
//class TBaseUnknown2__SERVER_LINK_DATA_REAL

TBaseUnknown2__SERVER_LINK_DATA_REAL::TBaseUnknown2__SERVER_LINK_DATA_REAL()
{
 _Module.IncrementModuleLockCount();
}//TBaseUnknown2__SERVER_LINK_DATA_REAL

//------------------------------------------------------------------------
TBaseUnknown2__SERVER_LINK_DATA_REAL::~TBaseUnknown2__SERVER_LINK_DATA_REAL()
{
 _Module.DecrementModuleLockCount();
}//~TBaseUnknown2__SERVER_LINK_DATA_REAL

//------------------------------------------------------------------------
TBaseUnknown2__SERVER_LINK_DATA_REAL::self_ptr TBaseUnknown2__SERVER_LINK_DATA_REAL::Create()
{
 return lcpi::lib::structure::not_null_ptr(new self_type());
}//Create

//interface --------------------------------------------------------------
bool TBaseUnknown2__SERVER_LINK_DATA_REAL::IsReal()const
{
 return true;
}//IsReal

//------------------------------------------------------------------------
void TBaseUnknown2__SERVER_LINK_DATA_REAL::IncrementComponentCount()
{
 _Module.IncrementComponentCount2();
}//IncrementComponentCount

//------------------------------------------------------------------------
void TBaseUnknown2__SERVER_LINK_DATA_REAL::DecrementComponentCount()
{
 _Module.DecrementComponentCount2();
}//DecrementComponentCount

////////////////////////////////////////////////////////////////////////////////
//class TBaseUnknown2__SERVER_LINK_DATA_DUMMY

class TBaseUnknown2__SERVER_LINK_DATA_DUMMY LCPI_CPP_CFG__CLASS__FINAL
 :public IBP_DEF_INTERFACE_IMPL_STATIC(TBaseUnknown2__SERVER_LINK_DATA)
{
 private:
  typedef TBaseUnknown2__SERVER_LINK_DATA_DUMMY                  self_type;

  TBaseUnknown2__SERVER_LINK_DATA_DUMMY(const self_type&);
  self_type& operator = (const self_type&);

 private:
  TBaseUnknown2__SERVER_LINK_DATA_DUMMY();

  virtual ~TBaseUnknown2__SERVER_LINK_DATA_DUMMY();

 public:
  static self_ptr Create();

  //interface ------------------------------------------------------------
  virtual bool IsReal()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual void IncrementComponentCount() LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual void DecrementComponentCount() LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  static self_type sm_Instance;
};//class TBaseUnknown2__SERVER_LINK_DATA_DUMMY

////////////////////////////////////////////////////////////////////////////////
//class TBaseUnknown2__SERVER_LINK_DATA_DUMMY

TBaseUnknown2__SERVER_LINK_DATA_DUMMY
 TBaseUnknown2__SERVER_LINK_DATA_DUMMY::sm_Instance;

//------------------------------------------------------------------------
TBaseUnknown2__SERVER_LINK_DATA_DUMMY::TBaseUnknown2__SERVER_LINK_DATA_DUMMY()
{
}//TBaseUnknown2__SERVER_LINK_DATA_DUMMY

//------------------------------------------------------------------------
TBaseUnknown2__SERVER_LINK_DATA_DUMMY::~TBaseUnknown2__SERVER_LINK_DATA_DUMMY()
{
}//~TBaseUnknown2__SERVER_LINK_DATA_DUMMY

//------------------------------------------------------------------------
TBaseUnknown2__SERVER_LINK_DATA_DUMMY::self_ptr TBaseUnknown2__SERVER_LINK_DATA_DUMMY::Create()
{
 return lcpi::lib::structure::not_null_ptr(&sm_Instance);
}//Create

//interface --------------------------------------------------------------
bool TBaseUnknown2__SERVER_LINK_DATA_DUMMY::IsReal()const
{
 return false;
}//IsReal

//------------------------------------------------------------------------
void TBaseUnknown2__SERVER_LINK_DATA_DUMMY::IncrementComponentCount()
{
 // Ignoring
}//IncrementComponentCount

//------------------------------------------------------------------------
void TBaseUnknown2__SERVER_LINK_DATA_DUMMY::DecrementComponentCount()
{
 // Ignoring
}//DecrementComponentCount

////////////////////////////////////////////////////////////////////////////////
//class TBaseUnknown2__SERVER_LINK

TBaseUnknown2__SERVER_LINK::TBaseUnknown2__SERVER_LINK(const self_type& x)
 :m_spData(x.m_spData.not_null_ptr())
{
 assert(m_spData);
}//TBaseUnknown2__SERVER_LINK - copy

//------------------------------------------------------------------------
TBaseUnknown2__SERVER_LINK::TBaseUnknown2__SERVER_LINK(TBaseUnknown2__SERVER_LINK_DATA* const pData)
 :m_spData(::lcpi::lib::structure::not_null_ptr(pData))
{
 assert(m_spData);
}//TBaseUnknown2__SERVER_LINK - init

//------------------------------------------------------------------------
TBaseUnknown2__SERVER_LINK::~TBaseUnknown2__SERVER_LINK()
{
}//~TBaseUnknown2__SERVER_LINK

//------------------------------------------------------------------------
TBaseUnknown2__SERVER_LINK TBaseUnknown2__SERVER_LINK::Create_REAL()
{
 return self_type(TBaseUnknown2__SERVER_LINK_DATA_REAL::Create());
}//Create_REAL

//------------------------------------------------------------------------
TBaseUnknown2__SERVER_LINK TBaseUnknown2__SERVER_LINK::Create_DUMMY()
{
 return self_type(TBaseUnknown2__SERVER_LINK_DATA_DUMMY::Create());
}//Create_DUMMY

//------------------------------------------------------------------------
TBaseUnknown2__SERVER_LINK_DATA* TBaseUnknown2__SERVER_LINK::GetData()const
{
 assert(m_spData);

 return m_spData;
}//GetData

////////////////////////////////////////////////////////////////////////////////
//class TBaseUnknown2

TBaseUnknown2::~TBaseUnknown2()
{
 assert(m_COM_SERVER_LINK.GetData());

 m_COM_SERVER_LINK.GetData()->DecrementComponentCount();
}//~TBaseUnknown2

//------------------------------------------------------------------------
const TBaseUnknown2__SERVER_LINK& TBaseUnknown2::GetComServerLink()const
{
 return m_COM_SERVER_LINK;
}//GetComServerLink

////////////////////////////////////////////////////////////////////////////////
}//namespace ole_lib
