////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests.h"

#include"source/tests/units/RemoteFB__ErrorUtils/TestsFor__RemoteFB__ErrorUtils__01.h"

#include "source/tests/isc/portable_format_to_integer/ISC_Test__portable_format_to_integer__signed_long.h"
#include "source/tests/isc/portable_format_to_integer/ISC_Test__portable_format_to_integer__unsigned_long.h"
#include "source/tests/fb_v25/FB25_Test_009__BlrPrinter.h"
#include "source/tests/fb_v25/FB25_Test_010__CheckBlrPrinter.h"
#include "source/tests/inet/PortFactory/INET_PortFactory_Test_001__Analyze_v2.h"
#include "source/tests/inet/PortFactory/INET_PortFactory_Test_002__Analyze_v3.h"
#include "source/tests/inet/PortFactory/INET_PortFactory_Test_003__Analyze_v3__inet4.h"
#include "source/tests/inet/PortFactory/INET_PortFactory_Test_004__Analyze_v3__inet6.h"

#include "source/tests/api/helpers/xsqlda/v01/RemoteFB__API_HLP__XSQLDA_v01_Utilities/TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA.h"
#include "source/tests/api/helpers/xsqlda/v01/RemoteFB__API_HLP__XSQLDA_v01_Utilities/TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR.h"
#include "source/tests/api/helpers/xsqlda/v01/RemoteFB__API_HLP__XSQLDA_v01_Utilities/TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_DATA.h"
#include "source/tests/api/helpers/xsqlda/v01/RemoteFB__API_HLP__XSQLDA_v01_Utilities/TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_DATA_DESCRS.h"
#include "source/tests/api/helpers/xsqlda/v01/RemoteFB__API_HLP__XSQLDA_v01_Utilities/TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA_MSG_DATA.h"
#include "source/tests/api/helpers/xsqlda/v01/RemoteFB__API_HLP__XSQLDA_v01_Utilities/TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE.h"
#include "source/tests/api/helpers/xsqlda/v01/RemoteFB__API_HLP__XSQLDA_v01_Utilities/TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Alloc_XSQLDA_MSG_NULLS.h"
#include "source/tests/api/helpers/xsqlda/v01/RemoteFB__API_HLP__XSQLDA_v01_Utilities/TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_NULLS__001.h"
#include "source/tests/api/helpers/xsqlda/v01/RemoteFB__API_HLP__XSQLDA_v01_Utilities/TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_NULLS__002.h"

#include "source/tests/api/helpers/RemoteFB__API_HLP__ArraySlice_V01__Utilities/TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL.h"

#include "source/tests/api/p13/RemoteFB__P13__ProcessAuthResponse/TestsFor__RemoteFB__P13__ProcessAuthResponse.h"
#include "source/tests/api/p13/RemoteFB__P13__AddServerKeys/TestsFor__RemoteFB__P13__AddServerKeys.h"

#include "source/tests/inet/Socket/INET_Socket_Test_002__unspec.h"
#include "source/tests/inet/Socket/INET_Socket_Test_003__inet4.h"
#include "source/tests/inet/Socket/INET_Socket_Test_004__inet6.h"
#include "source/tests/inet/INET_Test_002__RemotePort.h"

#include "source/tests/mix/RemoteFB__ClientConnectBlock_v2/TestsFor__RemoteFB__ClientConnectBlock_v2__RegAuthPluginFactory.h"

#include "source/tests/protocol/set01/TestsFor__PSET01__001_Mix.h"
#include "source/tests/protocol/set01/TestsFor__PSET01__002__unk_auth.h"

#include "source/tests/protocol/set02/TestsFor__PSET02__001_Mix.h"

#include "source/tests/protocol/v10/TestsFor__P10__001_Mix.h"

#include "source/tests/protocol/v13/Legacy_Auth/TestsFor__P13_Legacy_Auth_003__connect_db.h"
#include "source/tests/protocol/v13/Legacy_Auth/TestsFor__P13_Legacy_Auth_004__create_db.h"

#include "source/tests/protocol/v13/Srp/TestsFor__P13_Srp_001__connect_db.h"
#include "source/tests/protocol/v13/Srp/TestsFor__P13_Srp_002__create_db.h"

#include "source/tests/protocol/v13/Win_Sspi/TestsFor__P13_Win_Sspi_003__connect_db.h"
#include "source/tests/protocol/v13/Win_Sspi/TestsFor__P13_Win_Sspi_004__create_db.h"

#include "source/tests/protocol/v13/Compression/TestsFor__P13_Compression_01__zlib1_dll.h"

#include "source/tests/work/WORK_Test_003__Connector.h"
#include "source/tests/work/WORK_Test_004__StartTransaction__v1.h"
#include "source/tests/work/WORK_Test_004__StartTransaction__v2_lazy_send.h"
#include "source/tests/work/WORK_Test_005__Rollback.h"
#include "source/tests/work/WORK_Test_005__Rollback__v2_lazy_send.h"
#include "source/tests/work/WORK_Test_006__Commit.h"
#include "source/tests/work/WORK_Test_006__Commit__v2_lazy_send.h"
#include "source/tests/work/WORK_Test_007__RollbackRetaining.h"
#include "source/tests/work/WORK_Test_007__RollbackRetaining__v2_lazy_send.h"
#include "source/tests/work/WORK_Test_008__CommitRetaining.h"
#include "source/tests/work/WORK_Test_008__CommitRetaining__v2_lazy_send.h"
#include "source/tests/work/WORK_Test_009__PrepareTransaction.h"
#include "source/tests/work/WORK_Test_010__DetachDatabase.h"
#include "source/tests/work/WORK_Test_011__CreateDatabase.h"
#include "source/tests/work/WORK_Test_012__DropDatabase.h"
#include "source/tests/work/WORK_Test_013__StmtAllocate__v1_no_lazy.h"
#include "source/tests/work/WORK_Test_013__StmtAllocate__v2_lazy_send.h"
#include "source/tests/work/WORK_Test_014__StmtDrop__v1_no_lazy.h"
#include "source/tests/work/WORK_Test_014__StmtDrop__v2_lazy_send.h"
#include "source/tests/work/WORK_Test_015__StmtPrepare__v1_no_lazy.h"
#include "source/tests/work/WORK_Test_015__StmtPrepare__v2_lazy_send.h"
#include "source/tests/work/WORK_Test_016__GetColumns.h"
#include "source/tests/work/WORK_Test_017__GetStatementInfo.h"
#include "source/tests/work/WORK_Test_017__GetStatementInfo__select.h"
#include "source/tests/work/WORK_Test_017__GetStatementInfo__bind.h"
#include "source/tests/work/WORK_Test_018__GetParameters.h"
#include "source/tests/work/WORK_Test_019__StmtExecute__v1_no_lazy.h"
#include "source/tests/work/WORK_Test_019__StmtExecute__v2_lazy_send.h"
#include "source/tests/work/WORK_Test_019__StmtExecute__v3.h"
#include "source/tests/work/WORK_Test_020__StmtFetch__v1_no_lazy.h"
#include "source/tests/work/WORK_Test_020__StmtFetch__v2_lazy_send.h"
#include "source/tests/work/WORK_Test_021__StmtClose__v1_no_lazy.h"
#include "source/tests/work/WORK_Test_021__StmtClose__v2_lazy_send.h"
#include "source/tests/work/WORK_Test_022__OpenBlob__v1_no_lazy.h"
#include "source/tests/work/WORK_Test_022__OpenBlob__v2_lazy_send.h"
#include "source/tests/work/WORK_Test_023__CloseBlob__v1_no_lazy.h"
#include "source/tests/work/WORK_Test_023__CloseBlob__v2_lazy_send.h"
#include "source/tests/work/WORK_Test_024__GetBlobInfo.h"
#include "source/tests/work/WORK_Test_025__ReadBlob.h"
#include "source/tests/work/WORK_Test_026__CreateBlob__v0.h"
#include "source/tests/work/WORK_Test_026__CreateBlob__v1_no_lazy.h"
#include "source/tests/work/WORK_Test_026__CreateBlob__v2_lazy_send.h"
#include "source/tests/work/WORK_Test_027__WriteBlob.h"
#include "source/tests/work/WORK_Test_028__FlushBlob.h"
#include "source/tests/work/WORK_Test_029__CancelBlob__v1_no_lazy.h"
#include "source/tests/work/WORK_Test_029__CancelBlob__v2_lazy_send.h"
#include "source/tests/work/WORK_Test_030__PutArraySlice.h"
#include "source/tests/work/WORK_Test_031__GetArraySlice.h"
#include "source/tests/work/WORK_Test_032__ExecuteImmediate.h"
#include "source/tests/work/WORK_Test_033__GetDatabaseInfo.h"

#include "source/tests/work/WORK_Test_M01__WorkWithCursor.h"

#include "source/tests/work/Params/OUT/WORK_Params_OUT_001__short.h"
#include "source/tests/work/Params/OUT/WORK_Params_OUT_002__long.h"
#include "source/tests/work/Params/OUT/WORK_Params_OUT_003__int64.h"
#include "source/tests/work/Params/OUT/WORK_Params_OUT_004__float.h"
#include "source/tests/work/Params/OUT/WORK_Params_OUT_005__double.h"
#include "source/tests/work/Params/OUT/WORK_Params_OUT_006__type_time.h"
#include "source/tests/work/Params/OUT/WORK_Params_OUT_007__type_date.h"
#include "source/tests/work/Params/OUT/WORK_Params_OUT_008__timestamp.h"
#include "source/tests/work/Params/OUT/WORK_Params_OUT_009__char.h"
#include "source/tests/work/Params/OUT/WORK_Params_OUT_010__varchar.h"
#include "source/tests/work/Params/OUT/WORK_Params_OUT_011__blob.h"
#include "source/tests/work/Params/OUT/WORK_Params_OUT_012__array.h"
#include "source/tests/work/Params/OUT/WORK_Params_OUT_013__boolean.h"

#include "source/tests/work/Params/IN/WORK_Params_IN_013__boolean.h"

#include "source/tests/work/Params/IN2/WORK_Params_IN2_001__short.h"
#include "source/tests/work/Params/IN2/WORK_Params_IN2_002__long.h"
#include "source/tests/work/Params/IN2/WORK_Params_IN2_003__int64.h"
#include "source/tests/work/Params/IN2/WORK_Params_IN2_004__float.h"
#include "source/tests/work/Params/IN2/WORK_Params_IN2_005__double.h"
#include "source/tests/work/Params/IN2/WORK_Params_IN2_006__type_time.h"
#include "source/tests/work/Params/IN2/WORK_Params_IN2_007__type_date.h"
#include "source/tests/work/Params/IN2/WORK_Params_IN2_008__timestamp.h"
#include "source/tests/work/Params/IN2/WORK_Params_IN2_009__char.h"
#include "source/tests/work/Params/IN2/WORK_Params_IN2_010__varchar.h"
#include "source/tests/work/Params/IN2/WORK_Params_IN2_011__blob.h"
#include "source/tests/work/Params/IN2/WORK_Params_IN2_012__array.h"
#include "source/tests/work/Params/IN2/WORK_Params_IN2_013__boolean.h"

#include "source/tests/work/Params/WORK_Params__001__nulls.h"

#include "source/tests/work/StmtFetch/WORK_StmtFetch_Test_01__Failed.h"
#include "source/tests/work/StmtFetch/WORK_StmtFetch_Test_03__MARS.h"
#include "source/tests/work/StmtFetch/WORK_StmtFetch_Test_04__MARS_Failed.h"
#include "source/tests/work/StmtFetch/WORK_StmtFetch_Test_05__drop_stmt__v1_no_lazy.h"
#include "source/tests/work/StmtFetch/WORK_StmtFetch_Test_05__drop_stmt__v2_lazy_send.h"
#include "source/tests/work/StmtFetch/WORK_StmtFetch_Test_06__close_stmt.h"
#include "source/tests/work/StmtFetch/WORK_StmtFetch_Test_07__commit.h"
#include "source/tests/work/StmtFetch/WORK_StmtFetch_Test_08__rollback.h"
#include "source/tests/work/StmtFetch/WORK_StmtFetch_Test_09__commit_retaining.h"
#include "source/tests/work/StmtFetch/WORK_StmtFetch_Test_10__rollback_retaining.h"
#include "source/tests/work/StmtFetch/WORK_StmtFetch_Test_11__sql_commit.h"
#include "source/tests/work/StmtFetch/WORK_StmtFetch_Test_12__sql_rollback.h"
#include "source/tests/work/StmtFetch/WORK_StmtFetch_Test_13__sql_commit_retaining.h"
#include "source/tests/work/StmtFetch/WORK_StmtFetch_Test_14__sql_rollback_retaining.h"

#include "source/tests/work/Fields/smallint/WORK_Fields__smallint_001.h"
#include "source/tests/work/Fields/smallint/WORK_Fields__smallint_002__check_align.h"
#include "source/tests/work/Fields/integer/WORK_Fields__integer_001.h"
#include "source/tests/work/Fields/integer/WORK_Fields__integer_002__check_align.h"
#include "source/tests/work/Fields/bigint/WORK_Fields__bigint_001.h"
#include "source/tests/work/Fields/bigint/WORK_Fields__bigint_002__check_align.h"
#include "source/tests/work/Fields/float/WORK_Fields__float_001.h"
#include "source/tests/work/Fields/double/WORK_Fields__double_001.h"
#include "source/tests/work/Fields/numeric/WORK_Fields__numeric_001__N03_01.h"
#include "source/tests/work/Fields/numeric/WORK_Fields__numeric_001__N07_02.h"
#include "source/tests/work/Fields/numeric/WORK_Fields__numeric_001__N15_05.h"
#include "source/tests/work/Fields/decimal/WORK_Fields__decimal_001__D03_01.h"
#include "source/tests/work/Fields/decimal/WORK_Fields__decimal_001__D07_02.h"
#include "source/tests/work/Fields/decimal/WORK_Fields__decimal_001__D15_05.h"
#include "source/tests/work/Fields/time/WORK_Fields__time_001.h"
#include "source/tests/work/Fields/date/WORK_Fields__date_001.h"
#include "source/tests/work/Fields/timestamp/WORK_Fields__timestamp_001.h"
#include "source/tests/work/Fields/char/WORK_Fields__char_001__sz7.h"
#include "source/tests/work/Fields/varchar/WORK_Fields__varchar_001__sz7.h"
#include "source/tests/work/Fields/boolean/WORK_Fields__boolean_001.h"

#include "source/tests/work/Fields/WORK_Fields__001__nulls.h"
#include "source/tests/work/Fields/WORK_Fields__002__nulls.h"

#include "source/tests/work/Blob/WORK_Blob_Test_01__WriteAndReadBinData__v1_no_lazy.h"
#include "source/tests/work/Blob/WORK_Blob_Test_01__WriteAndReadBinData__v2_lazy_send.h"

#include "source/tests/work/Array/Write/WORK_Array_Write_Test_001__smallint.h"
#include "source/tests/work/Array/Write/WORK_Array_Write_Test_002__integer.h"
#include "source/tests/work/Array/Write/WORK_Array_Write_Test_003__bigint.h"
#include "source/tests/work/Array/Write/WORK_Array_Write_Test_004__float.h"
#include "source/tests/work/Array/Write/WORK_Array_Write_Test_005__double.h"
#include "source/tests/work/Array/Write/WORK_Array_Write_Test_006__date.h"
#include "source/tests/work/Array/Write/WORK_Array_Write_Test_007__time.h"
#include "source/tests/work/Array/Write/WORK_Array_Write_Test_008__timestamp.h"
#include "source/tests/work/Array/Write/WORK_Array_Write_Test_009__char.h"
#include "source/tests/work/Array/Write/WORK_Array_Write_Test_010__boolean.h"

#include "source/tests/work/Array/Read/WORK_Array_Read_Test_001__smallint.h"
#include "source/tests/work/Array/Read/WORK_Array_Read_Test_002__integer.h"
#include "source/tests/work/Array/Read/WORK_Array_Read_Test_003__bigint.h"
#include "source/tests/work/Array/Read/WORK_Array_Read_Test_004__float.h"
#include "source/tests/work/Array/Read/WORK_Array_Read_Test_005__double.h"
#include "source/tests/work/Array/Read/WORK_Array_Read_Test_006__date.h"
#include "source/tests/work/Array/Read/WORK_Array_Read_Test_007__time.h"
#include "source/tests/work/Array/Read/WORK_Array_Read_Test_008__timestamp.h"
#include "source/tests/work/Array/Read/WORK_Array_Read_Test_009__char.h"
#include "source/tests/work/Array/Read/WORK_Array_Read_Test_010__boolean.h"

#include "source/tests/work/Cancel/WORK_Cancel_Test_01__StmtExecute.h"
#include "source/tests/work/Cancel/WORK_Cancel_Test_02__StmtFetch.h"
#include "source/tests/work/Cancel/WORK_Cancel_Test_03__ExecuteImmediate.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////

#define DEF_CREATOR_DESCR(func) \
 {func}

////////////////////////////////////////////////////////////////////////////////
//Tests

const TTestCreatorDescr g_Tests[]=
{
 DEF_CREATOR_DESCR(TestsFor__RemoteFB__ErrorUtils__01::create),

 DEF_CREATOR_DESCR(ISC_Test__portable_format_to_integer__signed_long::create),

 DEF_CREATOR_DESCR(ISC_Test__portable_format_to_integer__unsigned_long::create),

 DEF_CREATOR_DESCR(FB25_Test_009__BlrPrinter::create),

 DEF_CREATOR_DESCR(FB25_Test_010__CheckBlrPrinter::create),

 DEF_CREATOR_DESCR(INET_PortFactory_Test_001__Analyze_v2::create),

 DEF_CREATOR_DESCR(INET_PortFactory_Test_002__Analyze_v3::create),

 DEF_CREATOR_DESCR(INET_PortFactory_Test_003__Analyze_v3__inet4::create),

 DEF_CREATOR_DESCR(INET_PortFactory_Test_004__Analyze_v3__inet6::create),

 DEF_CREATOR_DESCR(TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::create),

 DEF_CREATOR_DESCR(TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::create),

 DEF_CREATOR_DESCR(TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_DATA::create),

 DEF_CREATOR_DESCR(TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_DATA_DESCRS::create),

 DEF_CREATOR_DESCR(TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA_MSG_DATA::create),

 DEF_CREATOR_DESCR(TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::create),

 DEF_CREATOR_DESCR(TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Alloc_XSQLDA_MSG_NULLS::create),

 DEF_CREATOR_DESCR(TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_NULLS__001::create),

 DEF_CREATOR_DESCR(TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_NULLS__002::create),

 DEF_CREATOR_DESCR(TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::create),

 DEF_CREATOR_DESCR(TestsFor__RemoteFB__P13__ProcessAuthResponse::create),

 DEF_CREATOR_DESCR(TestsFor__RemoteFB__P13__AddServerKeys::create),

 DEF_CREATOR_DESCR(INET_Socket_Test_002__unspec::create),

 DEF_CREATOR_DESCR(INET_Socket_Test_003__inet4::create),

 DEF_CREATOR_DESCR(INET_Socket_Test_004__inet6::create),

 DEF_CREATOR_DESCR(INET_Test_002__RemotePort::create),

 DEF_CREATOR_DESCR(TestsFor__RemoteFB__ClientConnectBlock_v2__RegAuthPluginFactory::create),

 DEF_CREATOR_DESCR(TestsFor__PSET01__001_Mix::create),

 DEF_CREATOR_DESCR(TestsFor__PSET01__002__unk_auth::create),

 DEF_CREATOR_DESCR(TestsFor__PSET02__001_Mix::create),

 DEF_CREATOR_DESCR(TestsFor__P10__001_Mix::create),

 DEF_CREATOR_DESCR(TestsFor__P13_Legacy_Auth_003__connect_db::create),

 DEF_CREATOR_DESCR(TestsFor__P13_Legacy_Auth_004__create_db::create),

 DEF_CREATOR_DESCR(TestsFor__P13_Srp_001__connect_db::create),

 DEF_CREATOR_DESCR(TestsFor__P13_Srp_002__create_db::create),

 DEF_CREATOR_DESCR(TestsFor__P13_Win_Sspi_003__connect_db::create),

 DEF_CREATOR_DESCR(TestsFor__P13_Win_Sspi_004__create_db::create),

 DEF_CREATOR_DESCR(TestsFor__P13_Compression_01__zlib1_dll::create),

 DEF_CREATOR_DESCR(WORK_Test_003__Connector::create),

 DEF_CREATOR_DESCR(WORK_Test_004__StartTransaction__v1::create),

 DEF_CREATOR_DESCR(WORK_Test_004__StartTransaction__v2_lazy_send::create),

 DEF_CREATOR_DESCR(WORK_Test_005__Rollback::create),

 DEF_CREATOR_DESCR(WORK_Test_005__Rollback__v2_lazy_send::create),

 DEF_CREATOR_DESCR(WORK_Test_006__Commit::create),

 DEF_CREATOR_DESCR(WORK_Test_006__Commit__v2_lazy_send::create),

 DEF_CREATOR_DESCR(WORK_Test_007__RollbackRetaining::create),

 DEF_CREATOR_DESCR(WORK_Test_007__RollbackRetaining__v2_lazy_send::create),

 DEF_CREATOR_DESCR(WORK_Test_008__CommitRetaining::create),

 DEF_CREATOR_DESCR(WORK_Test_008__CommitRetaining__v2_lazy_send::create),

 DEF_CREATOR_DESCR(WORK_Test_009__PrepareTransaction::create),

 DEF_CREATOR_DESCR(WORK_Test_010__DetachDatabase::create),

 DEF_CREATOR_DESCR(WORK_Test_011__CreateDatabase::create),

 DEF_CREATOR_DESCR(WORK_Test_012__DropDatabase::create),

 DEF_CREATOR_DESCR(WORK_Test_013__StmtAllocate__v1_no_lazy::create),

 DEF_CREATOR_DESCR(WORK_Test_013__StmtAllocate__v2_lazy_send::create),

 DEF_CREATOR_DESCR(WORK_Test_014__StmtDrop__v1_no_lazy::create),

 DEF_CREATOR_DESCR(WORK_Test_014__StmtDrop__v2_lazy_send::create),

 DEF_CREATOR_DESCR(WORK_Test_015__StmtPrepare__v1_no_lazy::create),

 DEF_CREATOR_DESCR(WORK_Test_015__StmtPrepare__v2_lazy_send::create),

 DEF_CREATOR_DESCR(WORK_Test_016__GetColumns::create),

 DEF_CREATOR_DESCR(WORK_Test_017__GetStatementInfo::create),

 DEF_CREATOR_DESCR(WORK_Test_017__GetStatementInfo__select::create),

 DEF_CREATOR_DESCR(WORK_Test_017__GetStatementInfo__bind::create),

 DEF_CREATOR_DESCR(WORK_Test_018__GetParameters::create),

 DEF_CREATOR_DESCR(WORK_Test_019__StmtExecute__v1_no_lazy::create),

 DEF_CREATOR_DESCR(WORK_Test_019__StmtExecute__v2_lazy_send::create),

 DEF_CREATOR_DESCR(WORK_Test_019__StmtExecute__v3::create),

 DEF_CREATOR_DESCR(WORK_Test_020__StmtFetch__v1_no_lazy::create),

 DEF_CREATOR_DESCR(WORK_Test_020__StmtFetch__v2_lazy_send::create),

 DEF_CREATOR_DESCR(WORK_Test_021__StmtClose__v1_no_lazy::create),

 DEF_CREATOR_DESCR(WORK_Test_021__StmtClose__v2_lazy_send::create),

 DEF_CREATOR_DESCR(WORK_Test_022__OpenBlob__v1_no_lazy::create),

 DEF_CREATOR_DESCR(WORK_Test_022__OpenBlob__v2_lazy_send::create),

 DEF_CREATOR_DESCR(WORK_Test_023__CloseBlob__v1_no_lazy::create),

 DEF_CREATOR_DESCR(WORK_Test_023__CloseBlob__v2_lazy_send::create),

 DEF_CREATOR_DESCR(WORK_Test_024__GetBlobInfo::create),

 DEF_CREATOR_DESCR(WORK_Test_025__ReadBlob::create),

 DEF_CREATOR_DESCR(WORK_Test_026__CreateBlob__v0::create),

 DEF_CREATOR_DESCR(WORK_Test_026__CreateBlob__v1_no_lazy::create),

 DEF_CREATOR_DESCR(WORK_Test_026__CreateBlob__v2_lazy_send::create),

 DEF_CREATOR_DESCR(WORK_Test_027__WriteBlob::create),

 DEF_CREATOR_DESCR(WORK_Test_028__FlushBlob::create),

 DEF_CREATOR_DESCR(WORK_Test_029__CancelBlob__v1_no_lazy::create),

 DEF_CREATOR_DESCR(WORK_Test_029__CancelBlob__v2_lazy_send::create),

 DEF_CREATOR_DESCR(WORK_Test_030__PutArraySlice::create),

 DEF_CREATOR_DESCR(WORK_Test_031__GetArraySlice::create),

 DEF_CREATOR_DESCR(WORK_Test_032__ExecuteImmediate::create),

 DEF_CREATOR_DESCR(WORK_Test_033__GetDatabaseInfo::create),

 DEF_CREATOR_DESCR(WORK_Test_M01__WorkWithCursor::create),

 DEF_CREATOR_DESCR(WORK_Params_OUT_001__short::create),

 DEF_CREATOR_DESCR(WORK_Params_OUT_002__long::create),

 DEF_CREATOR_DESCR(WORK_Params_OUT_003__int64::create),

 DEF_CREATOR_DESCR(WORK_Params_OUT_004__float::create),

 DEF_CREATOR_DESCR(WORK_Params_OUT_005__double::create),

 DEF_CREATOR_DESCR(WORK_Params_OUT_006__type_time::create),

 DEF_CREATOR_DESCR(WORK_Params_OUT_007__type_date::create),

 DEF_CREATOR_DESCR(WORK_Params_OUT_008__timestamp::create),

 DEF_CREATOR_DESCR(WORK_Params_OUT_009__char::create),

 DEF_CREATOR_DESCR(WORK_Params_OUT_010__varchar::create),

 DEF_CREATOR_DESCR(WORK_Params_OUT_011__blob::create),

 DEF_CREATOR_DESCR(WORK_Params_OUT_012__array::create),

 DEF_CREATOR_DESCR(WORK_Params_OUT_013__boolean::create),

 //-----------------------------------------
 DEF_CREATOR_DESCR(WORK_Params_IN_013__boolean::create),

 //-----------------------------------------
 DEF_CREATOR_DESCR(WORK_Params_IN2_001__short::create),

 DEF_CREATOR_DESCR(WORK_Params_IN2_002__long::create),

 DEF_CREATOR_DESCR(WORK_Params_IN2_003__int64::create),

 DEF_CREATOR_DESCR(WORK_Params_IN2_004__float::create),

 DEF_CREATOR_DESCR(WORK_Params_IN2_005__double::create),

 DEF_CREATOR_DESCR(WORK_Params_IN2_006__type_time::create),

 DEF_CREATOR_DESCR(WORK_Params_IN2_007__type_date::create),

 DEF_CREATOR_DESCR(WORK_Params_IN2_008__timestamp::create),

 DEF_CREATOR_DESCR(WORK_Params_IN2_009__char::create),

 DEF_CREATOR_DESCR(WORK_Params_IN2_010__varchar::create),

 DEF_CREATOR_DESCR(WORK_Params_IN2_011__blob::create),

 DEF_CREATOR_DESCR(WORK_Params_IN2_012__array::create),

 DEF_CREATOR_DESCR(WORK_Params_IN2_013__boolean::create),

 //-----------------------------------------
 DEF_CREATOR_DESCR(WORK_Params__001__nulls::create),

 //-----------------------------------------
 DEF_CREATOR_DESCR(WORK_StmtFetch_Test_01__Failed::create),

 DEF_CREATOR_DESCR(WORK_StmtFetch_Test_03__MARS::create),

 DEF_CREATOR_DESCR(WORK_StmtFetch_Test_04__MARS_Failed::create),

 DEF_CREATOR_DESCR(WORK_StmtFetch_Test_05__drop_stmt__v1_no_lazy::create),

 DEF_CREATOR_DESCR(WORK_StmtFetch_Test_05__drop_stmt__v2_lazy_send::create),

 DEF_CREATOR_DESCR(WORK_StmtFetch_Test_06__close_stmt::create),

 DEF_CREATOR_DESCR(WORK_StmtFetch_Test_07__commit::create),

 DEF_CREATOR_DESCR(WORK_StmtFetch_Test_08__rollback::create),

 DEF_CREATOR_DESCR(WORK_StmtFetch_Test_09__commit_retaining::create),

 DEF_CREATOR_DESCR(WORK_StmtFetch_Test_10__rollback_retaining::create),

 DEF_CREATOR_DESCR(WORK_StmtFetch_Test_11__sql_commit::create),

 DEF_CREATOR_DESCR(WORK_StmtFetch_Test_12__sql_rollback::create),

 DEF_CREATOR_DESCR(WORK_StmtFetch_Test_13__sql_commit_retaining::create),

 DEF_CREATOR_DESCR(WORK_StmtFetch_Test_14__sql_rollback_retaining::create),

 //-----------------------------------------
 DEF_CREATOR_DESCR(WORK_Fields__smallint_001::create),
 DEF_CREATOR_DESCR(WORK_Fields__smallint_002__check_align::create),

 DEF_CREATOR_DESCR(WORK_Fields__integer_001::create),
 DEF_CREATOR_DESCR(WORK_Fields__integer_002__check_align::create),

 DEF_CREATOR_DESCR(WORK_Fields__bigint_001::create),
 DEF_CREATOR_DESCR(WORK_Fields__bigint_002__check_align::create),

 DEF_CREATOR_DESCR(WORK_Fields__float_001::create),

 DEF_CREATOR_DESCR(WORK_Fields__double_001::create),

 DEF_CREATOR_DESCR(WORK_Fields__numeric_001__N03_01::create),

 DEF_CREATOR_DESCR(WORK_Fields__numeric_001__N07_02::create),

 DEF_CREATOR_DESCR(WORK_Fields__numeric_001__N15_05::create),

 DEF_CREATOR_DESCR(WORK_Fields__decimal_001__D03_01::create),

 DEF_CREATOR_DESCR(WORK_Fields__decimal_001__D07_02::create),

 DEF_CREATOR_DESCR(WORK_Fields__decimal_001__D15_05::create),

 DEF_CREATOR_DESCR(WORK_Fields__time_001::create),

 DEF_CREATOR_DESCR(WORK_Fields__date_001::create),

 DEF_CREATOR_DESCR(WORK_Fields__timestamp_001::create),

 DEF_CREATOR_DESCR(WORK_Fields__char_001__sz7::create),

 DEF_CREATOR_DESCR(WORK_Fields__varchar_001__sz7::create),

 DEF_CREATOR_DESCR(WORK_Fields__boolean_001::create),

 DEF_CREATOR_DESCR(WORK_Fields__001__nulls::create),

 DEF_CREATOR_DESCR(WORK_Fields__002__nulls::create),

 DEF_CREATOR_DESCR(WORK_Blob_Test_01__WriteAndReadBinData__v1_no_lazy::create),

 DEF_CREATOR_DESCR(WORK_Blob_Test_01__WriteAndReadBinData__v2_lazy_send::create),

 DEF_CREATOR_DESCR(WORK_Array_Write_Test_001__smallint::create),

 DEF_CREATOR_DESCR(WORK_Array_Write_Test_002__integer::create),

 DEF_CREATOR_DESCR(WORK_Array_Write_Test_003__bigint::create),

 DEF_CREATOR_DESCR(WORK_Array_Write_Test_004__float::create),

 DEF_CREATOR_DESCR(WORK_Array_Write_Test_005__double::create),

 DEF_CREATOR_DESCR(WORK_Array_Write_Test_006__date::create),

 DEF_CREATOR_DESCR(WORK_Array_Write_Test_007__time::create),

 DEF_CREATOR_DESCR(WORK_Array_Write_Test_008__timestamp::create),

 DEF_CREATOR_DESCR(WORK_Array_Write_Test_009__char::create),

 DEF_CREATOR_DESCR(WORK_Array_Write_Test_010__boolean::create),

 DEF_CREATOR_DESCR(WORK_Array_Read_Test_001__smallint::create),

 DEF_CREATOR_DESCR(WORK_Array_Read_Test_002__integer::create),

 DEF_CREATOR_DESCR(WORK_Array_Read_Test_003__bigint::create),

 DEF_CREATOR_DESCR(WORK_Array_Read_Test_004__float::create),

 DEF_CREATOR_DESCR(WORK_Array_Read_Test_005__double::create),

 DEF_CREATOR_DESCR(WORK_Array_Read_Test_006__date::create),

 DEF_CREATOR_DESCR(WORK_Array_Read_Test_007__time::create),

 DEF_CREATOR_DESCR(WORK_Array_Read_Test_008__timestamp::create),

 DEF_CREATOR_DESCR(WORK_Array_Read_Test_009__char::create),

 DEF_CREATOR_DESCR(WORK_Array_Read_Test_010__boolean::create),

 //-----------------------------------------
 DEF_CREATOR_DESCR(WORK_Cancel_Test_01__StmtExecute::create),

 DEF_CREATOR_DESCR(WORK_Cancel_Test_02__StmtFetch::create),

 DEF_CREATOR_DESCR(WORK_Cancel_Test_03__ExecuteImmediate::create),

 //-----------------------------------------
 {NULL}
};//g_Tests

#undef DEF_CREATOR_DESCR

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
