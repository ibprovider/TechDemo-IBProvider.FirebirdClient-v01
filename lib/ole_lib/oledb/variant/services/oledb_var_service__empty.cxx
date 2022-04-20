////////////////////////////////////////////////////////////////////////////////
//DBTYPE_EMPTY Service
//                                                  Kovalenko Dmitry 04.11.2008

////////////////////////////////////////////////////////////////////////////////
//EMPTY

DEFINE_OLEDB_TYPE_SERVICE_OBJ(EMPTY)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_SERVICE_GET_CONVERTOR(EMPTY)

//------------------------------------------------------------------------
t_oledb_type_service_EMPTY::length_type
 t_oledb_type_service_EMPTY::get_align()const
{
 assert(this->get_type()==DBTYPE_EMPTY);

 return 1;
}//EMPTY::get_align

//------------------------------------------------------------------------
void t_oledb_type_service_EMPTY::internal__get_size__ok
                                           (const DBVARIANT&  DEBUG_CODE(dbvar),
                                            length_type&      cbSize,
                                            length_type&      cbMemSize,
                                            length_type&      cbMinSize)const
{
 assert(this->get_type()==DBTYPE_EMPTY);
 assert(dbvar.wType==get_type());
 assert(dbvar.TestDataStatus__IsOK());

 cbMinSize =
 cbSize    =
 cbMemSize =0;
}//EMPTY::internal__get_size__ok

//------------------------------------------------------------------------
t_oledb_type_service_EMPTY::length_type
 t_oledb_type_service_EMPTY::internal__get_length__ok(const DBVARIANT&  DEBUG_CODE(dbvar))const
{
 assert(this->get_type()==DBTYPE_EMPTY);
 assert(dbvar.wType==this->get_type());
 assert(dbvar.TestDataStatus__IsOK());

 return 0;
}//EMPTY::internal__get_length__ok

//------------------------------------------------------------------------
t_oledb_type_service_EMPTY::length_type
 t_oledb_type_service_EMPTY::get_binary_length(length_type)const
{
 assert(this->get_type()==DBTYPE_EMPTY);

 return 0;
}//get_binary_length

//------------------------------------------------------------------------
HRESULT t_oledb_type_service_EMPTY::internal__get_data__ok
                                           (const DBVARIANT&  DEBUG_CODE(dbvar),
                                            const DBBINDING&  /*Binding*/,
                                            length_type const /*cbMemSize*/,
                                            status_type&      Binding_Status,
                                            length_type&      Binding_Length,
                                            void*       const /*pBuffer*/)const
{
 assert(this->get_type()==DBTYPE_EMPTY);
 assert(dbvar.wType==this->get_type());
 assert(dbvar.TestDataStatus__IsOK());

 //-----------------------------------------
 Binding_Status=DBSTATUS_S_DEFAULT;
 Binding_Length=0;

 return S_OK;
}//EMPTY::internal__get_data__ok

//------------------------------------------------------------------------
HRESULT t_oledb_type_service_EMPTY::get_element(DBVARIANT*   const DEBUG_CODE(dest),
                                                REFIID             /*ElementIID*/,
                                                length_type  const DEBUG_CODE(cbElement),
                                                const void*  const DEBUG_CODE(pElement))const
{
 assert(dest);

 CHECK_READ_PTR(pElement,cbElement);

 return DB_E_NOTSUPPORTED;
}//EMPTY::get_element

//------------------------------------------------------------------------
HRESULT t_oledb_type_service_EMPTY::set_element(LPCCONVCONTEXT      /*pConvCtx*/,
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
}//EMPTY::set_element

//------------------------------------------------------------------------
std::wstring t_oledb_type_service_EMPTY::get_print_wstr(const DBVARIANT& dbvar)const
{
 assert(dbvar.wType==this->get_type());

 //-------
 std::wstring result(L"EMPTY[");

 result+=structure::tstr_to_wstr(oledb_lib::GetDBStatusName__short(dbvar.GetDataStatus()));

 result+=L"]";

 //-------
 return result;
}//EMPTY::get_print_wstr                                                   //!!!

////////////////////////////////////////////////////////////////////////////////
