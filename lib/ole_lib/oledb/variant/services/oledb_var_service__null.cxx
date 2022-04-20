////////////////////////////////////////////////////////////////////////////////
//DBTYPE_NULL Service
//                                                  Kovalenko Dmitry 04.11.2008

////////////////////////////////////////////////////////////////////////////////
//NULL

DEFINE_OLEDB_TYPE_SERVICE_OBJ(NULL)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_SERVICE_GET_CONVERTOR(NULL)

//------------------------------------------------------------------------
t_oledb_type_service_NULL::length_type
 t_oledb_type_service_NULL::get_align()const
{
 assert(this->get_type()==DBTYPE_NULL);

 return 1;
}//NULL::get_align

//------------------------------------------------------------------------
void t_oledb_type_service_NULL::internal__get_size__ok
                                           (const DBVARIANT&  DEBUG_CODE(dbvar),
                                            length_type&      cbSize,
                                            length_type&      cbMemSize,
                                            length_type&      cbMinSize)const
{
 assert(this->get_type()==DBTYPE_NULL);
 assert(dbvar.wType==this->get_type());
 assert(dbvar.TestDataStatus__IsOK());

 cbMinSize =
 cbSize    =
 cbMemSize =0;
}//NULL::internal__get_size__ok

//------------------------------------------------------------------------
t_oledb_type_service_NULL::length_type
 t_oledb_type_service_NULL::internal__get_length__ok(const DBVARIANT&  DEBUG_CODE(dbvar))const
{
 assert(this->get_type()==DBTYPE_NULL);
 assert(dbvar.wType==this->get_type());
 assert(dbvar.TestDataStatus__IsOK());

 return 0;
}//NULL::internal__get_length__ok

//------------------------------------------------------------------------
t_oledb_type_service_NULL::length_type
 t_oledb_type_service_NULL::get_binary_length(length_type)const
{
 assert(this->get_type()==DBTYPE_NULL);

 return 0;
}//NULL::get_binary_length

//------------------------------------------------------------------------
HRESULT t_oledb_type_service_NULL::internal__get_data__ok
                                           (const DBVARIANT&  DEBUG_CODE(dbvar),
                                            const DBBINDING&  /*Binding*/,
                                            length_type const /*cbMemSize*/,
                                            status_type&      Binding_Status,
                                            length_type&      Binding_Length,
                                            void*       const /*pBuffer*/)const
{
 assert(this->get_type()==DBTYPE_NULL);
 assert(dbvar.wType==this->get_type());
 assert(dbvar.TestDataStatus__IsOK());

 //-----------------------------------------
 Binding_Status=DBSTATUS_S_ISNULL;
 Binding_Length=0;

 return S_OK;
}//NULL::internal__get_data__ok

//------------------------------------------------------------------------
HRESULT t_oledb_type_service_NULL::get_element(DBVARIANT*   const DEBUG_CODE(dest),
                                               REFIID             /*ElementIID*/,
                                               length_type  const DEBUG_CODE(cbElement),
                                               const void*  const DEBUG_CODE(pElement))const
{
 assert(dest);

 CHECK_READ_PTR(pElement,cbElement);

 return DB_E_NOTSUPPORTED;
}//NULL::get_element

//------------------------------------------------------------------------
HRESULT t_oledb_type_service_NULL::set_element(LPCCONVCONTEXT      /*pConvCtx*/,
                                               const DBVARIANT&    /*source*/,
                                               REFIID              /*ElementIID*/,
                                               length_type   const DEBUG_CODE(cbElement),
                                               void*         const DEBUG_CODE(pElement),
                                               status_type*  const pBinding_Status)const
{
 assert(pBinding_Status);

 CHECK_WRITE_PTR(pElement,cbElement);

 (*pBinding_Status)=DBSTATUS_E_CANTCONVERTVALUE;

 return DB_E_NOTSUPPORTED;
}//NULL::set_element

//------------------------------------------------------------------------
std::wstring t_oledb_type_service_NULL::get_print_wstr(const DBVARIANT& dbvar)const
{
 assert(dbvar.wType==this->get_type());

 //-------
 std::wstring result(L"DBNULL[");

 result+=structure::tstr_to_wstr(oledb_lib::GetDBStatusName__short(dbvar.GetDataStatus()));

 result+=L"]";

 //-------
 return result;
}//NULL::get_print_wstr                                                   //!!!

////////////////////////////////////////////////////////////////////////////////
