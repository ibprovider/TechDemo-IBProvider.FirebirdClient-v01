////////////////////////////////////////////////////////////////////////////////
//LCPI OLEDB Provider for InterBase/Firebird SDK.
//                                                 Kovalenko Dmitry. 25.01.2019
#ifndef _lcpi_sdk__ibprovider__v05_H_
#define _lcpi_sdk__ibprovider__v05_H_

#include <unknwn.h>

namespace lcpi{namespace sdk{namespace ibprovider{namespace v05{
////////////////////////////////////////////////////////////////////////////////
//containings

struct IBP_ISequentialStream_WideChar;
struct IBP_ISequentialStream_MultiByteChar;

struct IBP_IErrorExtendedParameter;
struct IBP_IText;
struct IBP_IClone;

////////////////////////////////////////////////////////////////////////////////
//interface IBP_ISequentialStream_WideChar

//769A128F-04BF-11D8-AE8B-00A0C907DB93
extern const IID IID_IBP_ISequentialStream_WideChar;

struct IBP_ISequentialStream_WideChar:IUnknown
{
 //Parameters:
 // [OUT]  pchars
 //  Points to the buffer into which the stream is read.
 //
 // [IN]   cch
 //  Specifies the number of chars of data to attempt to read from the stream object.
 //
 // [OUT]  pcchRead
 //  Pointer to a location where this method writes the actual number of chars
 //  read from the stream object. You can set this pointer to NULL to indicate
 //  that you are not interested in this value. In this case, this method does
 //  not provide the actual number of chars read.
 //
 //Return code:
 // S_OK 
 //  Data was successfully read from the stream object.
 //
 // S_FALSE 
 //  The data could not be read from the stream object.
 //
 // E_FAIL
 //  The error occurred.
 virtual HRESULT STDMETHODCALLTYPE Read(WCHAR*  pchars,
                                        SIZE_T  cch,
                                        SIZE_T* pcchRead)=0;

 virtual HRESULT STDMETHODCALLTYPE Write(const WCHAR* pchars,
                                         SIZE_T       cch,
                                         SIZE_T*      pcchWritten)=0;
};//struct IBP_ISequentialStream_WideChar

////////////////////////////////////////////////////////////////////////////////
//interface IBP_ISequentialStream_MultiByteChar

//769A1290-04BF-11D8-AE8B-00A0C907DB93
extern const IID IID_IBP_ISequentialStream_MultiByteChar;

struct IBP_ISequentialStream_MultiByteChar:IUnknown
{
 //Parameters:
 // [OUT]  pchars
 //  Points to the buffer into which the stream is read.
 //
 // [IN]   cch
 //  Specifies the number of chars of data to attempt to read from the stream object.
 //
 // [OUT]  pcchRead
 //  Pointer to a location where this method writes the actual number of chars
 //  read from the stream object. You can set this pointer to NULL to indicate
 //  that you are not interested in this value. In this case, this method does
 //  not provide the actual number of chars read.
 //
 //Return code:
 // S_OK 
 //  Data was successfully read from the stream object.
 //
 // S_FALSE 
 //  The data could not be read from the stream object.
 //
 // E_FAIL
 //  The error occurred.
 virtual HRESULT STDMETHODCALLTYPE Read(CHAR*   pchars,
                                        SIZE_T  cch,
                                        SIZE_T* pcchRead)=0;

 virtual HRESULT STDMETHODCALLTYPE Write(const CHAR* pchars,
                                         SIZE_T      cch,
                                         SIZE_T*     pcchWritten)=0;
};//struct IBP_ISequentialStream_MultiByteChar

////////////////////////////////////////////////////////////////////////////////
//interface IBP_IErrorExtendedParameter

//D8552162-22C7-462C-96B4-9514355A030B
extern const IID IID_IBP_IErrorExtendedParameter;

/// <summary>
///  Interface for get an error description
/// </summary>
//! \todo
//!  Rename this interface to IBP_IErrorInfo
struct IBP_IErrorExtendedParameter:public IUnknown
{
 /// <summary>
 ///  Get an error description
 /// </summary>
 //! \param[in]  lcid
 //! \param[out] pbstrSource
 //!  Can be NULL
 //! \param[out] pbstrDescription
 //!  Can be NULL
 virtual HRESULT __stdcall GetErrorDescription(LCID  lcid,
                                               BSTR* pbstrSource,
                                               BSTR* pbstrDescription)=0;
};//struct IBP_IErrorExtendedParameter

////////////////////////////////////////////////////////////////////////////////
//interface IBP_IText

//769A128D-04BF-11D8-AE8B-00A0C907DB93
extern const IID IID_IBP_IText;

/// <summary>
///  Interface for get a text
/// </summary>
struct IBP_IText:public IUnknown
{
 /// <summary>
 ///  Get text
 /// </summary>
 //! \param[in]  lcid
 //! \param[out] pbstrText
 //!  Not NULL
 virtual HRESULT __stdcall GetText(LCID  lcid,
                                   BSTR* pbstrText)=0;
};//struct IBP_IText

////////////////////////////////////////////////////////////////////////////////
//interface IBP_IClone

//769A1291-04BF-11D8-AE8B-00A0C907DB93
extern const IID IID_IBP_IClone;

/// <summary>
///  Interface for create object clone
/// </summary>
struct IBP_IClone:public IUnknown
{
 /// <summary>
 ///  Clone of object
 /// </summary>
 //! \param[in] pUnkOuter
 //!  A pointer to the controlling IUnknown interface if the new command
 //!  is being created as part of an aggregate. It is a null pointer if
 //!  the command is not part of an aggregate. 
 //! \param[out] pNewObject
 //!  Not null.
 virtual HRESULT __stdcall Clone(IUnknown*  pUnkOuter,
                                 IUnknown** pNewObject)=0;
};//struct IBP_IClone

////////////////////////////////////////////////////////////////////////////////
}/*nms v05*/}/*nms ibprovider*/}/*nms sdk*/}/*nms lcpi*/
#endif
