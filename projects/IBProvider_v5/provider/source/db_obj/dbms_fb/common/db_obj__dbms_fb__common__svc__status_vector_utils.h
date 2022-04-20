////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj__dbms_fb__common
//! \file    db_obj__dbms_fb__common__svc__status_vector_utils.h
//! \brief   Интерфейс для работы со статус вектором.
//! \author  Kovalenko Dmitry
//! \date    07.08.2016
#ifndef _db_obj__dbms_fb__common__svc__status_vector_utils_H_
#define _db_obj__dbms_fb__common__svc__status_vector_utils_H_

#include "source/db_obj/dbms_fb/common/db_obj__dbms_fb__common.h"
#include "source/db_obj/isc_base/isc_base.h"
#include "source/db_obj/isc_base/isc_api.h"

namespace lcpi{namespace ibp{namespace db_obj{namespace dbms_fb{namespace common{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_obj__dbms_fb__common
//! @{
////////////////////////////////////////////////////////////////////////////////
//class fb_common__svc__status_vector_utils

class fb_common__svc__status_vector_utils:public db_obj::t_db_smart_interface
{
 public: //typedefs ------------------------------------------------------
  typedef isc_base::t_isc_error_code_descr2      descr2_type;

  typedef isc_api::t_ibp_isc_status              status_type;

  enum gresult_code_type
  {
   gresult__ok      =0,
   gresult__bad_sv  =1,
  };//enum gresult_code

  struct gresult_data_type
  {
   private:
    typedef gresult_data_type               self_type;

   public:
    gresult_code_type code;
    const wchar_t*    check_place;
    const wchar_t*    check_point;

   public:
    gresult_data_type();

    gresult_data_type(gresult_code_type _code,
                      const wchar_t*    _check_place,
                      const wchar_t*    _check_point);

    //factories ----------------------------------------------------------
    static self_type create_ok();

    static self_type create_bad_sv(const wchar_t* _check_place,
                                   const wchar_t* _check_point);

    //operators ----------------------------------------------------------
    bool operator == (gresult_code_type _code)const;

    bool operator != (gresult_code_type _code)const;
  };//struct gresult_data_type

 public:
  /// <summary>
  ///  Получение описания ISC-ошибки
  /// </summary>
  //! \param[in] status
  //! \return
  //!  NULL, если описание не найдено.
  virtual const descr2_type* get_err_descr2(status_type status)=0;

  /// <summary>
  ///  Отображения status_vector на SQLSTATE code.
  /// </summary>
  //! \param[in] sv_beg
  //! \param[in] sv_end
  //! \param[out] sqlstate
  //!  Not null.
  //! \return
  //!  Result code.
  virtual gresult_data_type get_sqlstate(const status_type* sv_beg,
                                         const status_type* sv_end,
                                         std::string*       sqlstate)=0;

  /// <summary>
  ///  Получение кода основной ошибки.
  /// </summary>
  //! \param[in]  sv_beg
  //! \param[in]  sv_end
  //! \param[out] general_error_code
  //!  Not null.
  //! \return
  //!  Result data.
  virtual gresult_data_type get_general_error(const status_type* sv_beg,
                                              const status_type* sv_end,
                                              status_type*       general_error_code)=0;

  /// <summary>
  ///  Получение кода ошибки.
  /// </summary>
  //! \param[in]  sv_beg
  //! \param[in]  sv_end
  //! \param[out] error_code
  //!  Not null.
  //! \return
  //!  Result data.
  virtual gresult_data_type get_error(const status_type* sv_beg,
                                      const status_type* sv_end,
                                      status_type*       error_code)=0;

  /// <summary>
  ///  Формирование текста ошибки.
  /// </summary>
  //! \param[in]  sv_beg
  //! \param[in]  sv_end
  //! \param[out] message
  //!  Not null.
  //! \param[in]  lcid
  //! \return
  //!  Result data.
  virtual gresult_data_type get_message(const status_type* sv_beg,
                                        const status_type* sv_end,
                                        std::wstring*      message,
                                        LCID               lcid)=0;

  /// <summary>
  ///  Вычисление размера косвенных данных статус вектора
  /// </summary>
  //! \param[in]  sv_beg
  //! \param[in]  sv_end
  //! \param[out] sv_info__num_of_elements
  //!  Количество актуальных элементов. Not null.
  //! \param[out] sv_info__indirect_data_size
  //!  Размер косвенных данных статус вектора. Not null.
  //! \return
  //!  Result data.
  virtual gresult_data_type get_sv_info(const status_type* sv_beg,
                                        const status_type* sv_end,
                                        size_t*            sv_info__num_of_elements,
                                        size_t*            sv_info__indirect_data_size)=0;

  /// <summary>
  ///  Перемещение косвенных данных в буфер.
  /// </summary>
  //! \param[in] sv_beg
  //! \param[in] sv_end
  //! \param[in] buf_beg
  //! \param[in] buf_end
  //! \return
  //!  Result data.
  virtual gresult_data_type move_indirect_data_to_buf
                                      (status_type*       sv_beg,
                                       const status_type* sv_end,
                                       void*              buf_beg,
                                       const void*        buf_end)=0;
};//class fb_common__svc__status_vector_utils

////////////////////////////////////////////////////////////////////////////////

typedef structure::t_smart_object_ptr<fb_common__svc__status_vector_utils>
 fb_common__svc__status_vector_utils_ptr;

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms common*/}/*nms dbms_fb*/}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
#endif
