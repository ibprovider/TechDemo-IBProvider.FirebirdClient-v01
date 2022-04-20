////////////////////////////////////////////////////////////////////////////////
//Traits for worj with sequential streams.
//                                                 Kovalenko Dmitry. 07.09.2012.
#ifndef _oledb_seq_stream_traits_H_
#define _oledb_seq_stream_traits_H_

#include <lcpi/sdk/ibprovider/v05/lcpi_sdk__ibprovider__v05.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//class t_oledb_seq_stream_traits

template<class TSeqStream>
class t_oledb_seq_stream_traits
{};

////////////////////////////////////////////////////////////////////////////////
//class t_oledb_seq_stream_traits<ISequentialStream>

template<>
class t_oledb_seq_stream_traits<ISequentialStream>
{
 public:
  typedef ULONG                             block_size_type;
};//class t_oledb_seq_stream_traits<ISequentialStream>

////////////////////////////////////////////////////////////////////////////////
//class t_oledb_seq_stream_traits<IIBP_SequentialStream_WideChar>

template<>
class t_oledb_seq_stream_traits<lcpi::sdk::ibprovider::v05::IBP_ISequentialStream_WideChar>
{
 public:
  typedef SIZE_T                            block_size_type;
};//class t_oledb_seq_stream_traits<IIBP_SequentialStream_WideChar>

////////////////////////////////////////////////////////////////////////////////
//class t_oledb_seq_stream_traits<IIBP_SequentialStream_MultiByteChar>

template<>
class t_oledb_seq_stream_traits<lcpi::sdk::ibprovider::v05::IBP_ISequentialStream_MultiByteChar>
{
 public:
  typedef SIZE_T                            block_size_type;
};//class t_oledb_seq_stream_traits<IIBP_SequentialStream_MultiByteChar>

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
#endif