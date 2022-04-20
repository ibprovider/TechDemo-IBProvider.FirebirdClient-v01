////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_sqlncli
//! \file    ibp_sqlncli.h
//! \brief   Конструкции SQLNCLI, поддерживаемые IBProvider'ом.
//! \author  Kovalenko Dmitry.
//! \date    25.12.2012.
#ifndef _ibp_sqlncli_H_
#define _ibp_sqlncli_H_

namespace lcpi{namespace ibp{namespace sqlncli{
////////////////////////////////////////////////////////////////////////////////
//PropIds for DBPROPSET_SQLSERVERROWSET

const DBPROPID SSPROP_ISSAsynchStatus       =24;

////////////////////////////////////////////////////////////////////////////////
//DBPROPSET GUIDs

extern const GUID DBPROPSET_SQLSERVERROWSET;

////////////////////////////////////////////////////////////////////////////////
//struct ISSAsynchStatus

//"1FF1F743-8BB0-4C00-ACC4-C10E43B08FC1"
extern const IID IID_ISSAsynchStatus;

struct ISSAsynchStatus:public IDBAsynchStatus
{
 public:
  virtual HRESULT STDMETHODCALLTYPE WaitForAsynchCompletion
                                           (/*[in]*/DWORD dwMillisecTimeOut)=0;
};//struct ISSAsynchStatus

////////////////////////////////////////////////////////////////////////////////
//struct tagSSErrorInfo

typedef struct tagSSErrorInfo
{
 LPOLESTR pwszMessage;
 LPOLESTR pwszServer;
 LPOLESTR pwszProcedure;
 LONG     lNative;
 BYTE     bState;
 BYTE     bClass;
 WORD     wLineNumber;
} SSERRORINFO;

////////////////////////////////////////////////////////////////////////////////
//struct ISQLServerErrorInfo

//"5CF4CA12-EF21-11d0-97E7-00C04FC2AD98"
extern const IID IID_ISQLServerErrorInfo;

struct ISQLServerErrorInfo:public IUnknown
{
 public:
  virtual HRESULT STDMETHODCALLTYPE GetErrorInfo
                                           (/*[out]*/ SSERRORINFO** ppErrorInfo,
                                            /*[out]*/ OLECHAR**     ppStringsBuffer)=0;
};//struct ISQLServerErrorInfo

////////////////////////////////////////////////////////////////////////////////
}/*nms sqlncli*/}/*nms ibp*/}/*nms lcpi*/
#endif
