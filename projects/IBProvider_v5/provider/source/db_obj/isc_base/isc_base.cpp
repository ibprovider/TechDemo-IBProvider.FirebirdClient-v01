////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/db_obj/isc_base/isc_base.h"

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////

const GUID t_isc_stmt_text_translator_guid=
 {0x65C3200F,0xC238,0x456E,{0xAF,0x61,0xFF,0x8C,0xA9,0x87,0xBB,0xC9}};

const GUID t_isc_api_svc__array_reader_guid=
 {0x5E343B0B,0x4E32,0x4CBC,{0xA7,0xFF,0xC0,0x8D,0x36,0xB4,0xB4,0x0F}};

const GUID t_isc_api_svc__array_writer_guid=
 {0x4C930977,0x01A6,0x4D57,{0xAE,0xBA,0xDD,0x66,0x05,0xB8,0xCF,0xB0}};

const GUID t_isc_api_svc__blob_reader_factory_guid=
 {0x383371FA,0x19FD,0x47DE,{0x99,0xD6,0x90,0x18,0xD8,0x10,0x9E,0xCC}};

const GUID t_isc_api_svc__blob_writer_factory_guid=
 {0xF84BDBB5,0x4DBA,0x4F9A,{0x82,0x52,0x03,0xA4,0x85,0x77,0x1F,0x3A}};

const GUID t_isc_api_svc__cancel_statement_guid=
 {0x1551EF0D,0x662F,0x44CF,{0x9C,0x80,0x20,0xBD,0x0D,0x85,0xE8,0x8C}};

const GUID t_isc_svc__get_connection_settings_guid=
 {0xB1AA1780,0x588D,0x406C,{0x83,0x6C,0x6A,0x27,0x67,0x81,0x84,0xA7}};

//------------------------------------------------------------------------
extern const db_obj::t_db_svc_descr
 isc_meta_svc_descr__sp_suspend_detecter__blr
 ={
   {0x9F5B9178,0x4AB6,0x404A,{0x84,0xE8,0x37,0xBB,0xB5,0xC6,0x2A,0xD1}},
   "isc_meta_svc__sp_suspend_detecter__blr"
  };

//------------------------------------------------------------------------
extern const db_obj::t_db_svc_descr
 isc_meta_svc_descr__sp_suspend_detecter__src
 ={
   {0x6087E47A,0xBF3B,0x4A6B,{0x99,0x33,0xE9,0x57,0x5A,0xE2,0x37,0x8D}},
   "isc_meta_svc__sp_suspend_detecter__src"
  };

//------------------------------------------------------------------------
const GUID t_isc_xsqlda_v1_svc__msg_blr01_builder_guid=
 {0x8DF470CC,0x8DDE,0x4F9A,{0x9B,0x1C,0x93,0x32,0x4F,0x7E,0x7A,0xE5}};

//------------------------------------------------------------------------
const GUID t_isc_xsqlda_v1_svc__msg_data_descrs_builder_guid=
 {0xCBB91D2A,0xEA44,0x4808,{0xBF,0xE5,0x7B,0xD6,0xF4,0x92,0x0E,0xB9}};

//------------------------------------------------------------------------
const GUID t_isc_xsqlda_v1_svc__msg_data_guid=
 {0xB754BBCC,0x6CDC,0x434A,{0xB8,0x1A,0xDF,0x94,0x72,0xB7,0x8E,0x38}};

////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
