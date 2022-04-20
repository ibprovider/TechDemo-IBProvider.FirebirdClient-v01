////////////////////////////////////////////////////////////////////////////////
//DBVARIANT implementation. IUnknown utilities
//                                          Kovalenko Dmitry. 03.05.2008

////////////////////////////////////////////////////////////////////////////////

HRESULT DBVARIANT_CVT_UTILS::StorageObjectToSimpleType_v2
                                            (ISequentialStream* const pSS,
                                             void*                    buffer,
                                             size_type                buffer_size)
{
 assert(pSS);
 assert(buffer_size!=0 && buffer!=NULL);

 CHECK_WRITE_PTR(buffer,buffer_size);

 for(ULONG cbBuffer;buffer_size!=0;)
 {
  if(!structure::can_numeric_cast(&cbBuffer,buffer_size))
   cbBuffer=structure::get_numeric_limits(cbBuffer).max_value();
  else
   structure::static_numeric_cast(&cbBuffer,buffer_size);

  assert(cbBuffer!=0);
  assert(cbBuffer<=buffer_size);

  ULONG cbActual=0;

  const HRESULT read_hr=pSS->Read(buffer,cbBuffer,&cbActual);

  if(FAILED(read_hr))
   return read_hr;

  //paranoia
  //if(read_hr!=S_OK && read_hr!=S_FALSE)
  // return E_UNEXPECTED;

  if(cbActual>cbBuffer)
   return E_UNEXPECTED; // after such must will be :crash:

  if(cbActual==0)
   break;

  buffer=reinterpret_cast<char*>(buffer)+cbActual;

  buffer_size-=cbActual;

  if(read_hr==S_FALSE)
   break;
 }//for

 if(buffer_size!=0)
  return DB_E_CANTCONVERTVALUE;

 {//Verification: no more data
  char test_buf[16];

  ULONG cbActual=0;

  const HRESULT read_hr=pSS->Read(test_buf,sizeof(test_buf),&cbActual);

  if(FAILED(read_hr))
   return read_hr;

  //paranoia
  //if(read_hr!=S_OK && read_hr!=S_FALSE)
  // return E_UNEXPECTED;

  if(cbActual>sizeof(test_buf))
   return E_UNEXPECTED; // after such must will be :crash:

  if(cbActual!=0)
   return DB_E_CANTCONVERTVALUE;
 }//local

 return S_OK;
}//StorageObjectToSimpleType_v2

////////////////////////////////////////////////////////////////////////////////
