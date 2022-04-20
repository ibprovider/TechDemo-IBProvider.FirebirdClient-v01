////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++.
//                                                Kovalenko Dmitry. 19.12.2018.
#ifndef _lcpi_oledb_wms_H_
#define _lcpi_oledb_wms_H_

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////

#define MAKE_OLEDB_WMS(wText) oledb_lib::tagOLEDB_WMS(wText L"\0")

////////////////////////////////////////////////////////////////////////////////
//class tagOLEDB_WMS

class tagOLEDB_WMS
{
 public:

  //
  // Attention: use MAKE_OLEDB_WMS instead direct call!
  //
  explicit tagOLEDB_WMS(const wchar_t* const v)
   :m_value(v)
  {
  }

  //interface ------------------------------------------------------------
  operator const wchar_t* () const
  {
   return m_value;
  }

  const wchar_t* ptr() const
  {
   return m_value;
  }//ptr

 private:
  const wchar_t* m_value;
};//class tagOLEDB_WMS

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
#endif
