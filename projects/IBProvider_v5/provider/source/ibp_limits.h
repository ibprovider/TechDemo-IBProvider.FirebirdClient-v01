////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_limits
//! \file    ibp_limits.h
//! \brief   ���� � ����������� ���������� ����������� IBProvider-a
//! \author  Kovalenko Dmitry
//! \date    06.05.2006
#ifndef _ibp_limits_H_
#define _ibp_limits_H_

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_limits
//! @{
////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ����������� �� ���������� �������������� ������ � �������� ���������.
/// </summary>
const size_t ibp_limc_MaxErrorCountInBulkOperation=128;

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ������������ ����� ���� ��� ������ ������� ������������� ������� ��������
///  ������������ � ��-���������� ����������� ��������� ������.
/// </summary>
//! \note ����� ���������� � �������� �������
const size_t ibp_limc_MaxByteOfOneMultiByteSymbol=16;

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ������������ ���������� UNICODE �������� ��� ��������������� ������
///  ASCII �������.
/// </summary>
//! \note ����� ���������� � �������� �������
const size_t ibp_limc_MaxUnicodeSymbolsForOneMultiByteSymbol=8;

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ������������ ����� wchar_t �������� ��� ������ UTF8-�������
///  ������������ � ��-���������� ����������� ��������� ������.
/// </summary>
//! \note ����� ���������� � �������� �������
const size_t ibp_limc_MaxUnicodeSymbolsForOneUTF8Symbol
 =ibp_limc_MaxUnicodeSymbolsForOneMultiByteSymbol;

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ������������ ���������� ���������� � �������� ������
/// </summary>
//! ������������ ��� ��������� lib::structure::t_fix_vector
const size_t ibp_limc_MaxErrorArgsCount=12;

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ������������ "��������" ������ ���� ����, ��� �������� ����� ���������
///  ��������������� ������� ����� ���������������
/// </summary>
const DBLENGTH ibp_limc_MaxRawBlobSizeForSizePrediction=4*1024;

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  The maximum count of FB040 timezone transition records.
/// </summary>
const size_t ibp_limc_MaxCountOfFb040TimeZoneTransitionRecords
 =10000*4;

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
