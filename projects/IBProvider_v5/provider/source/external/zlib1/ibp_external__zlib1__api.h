////////////////////////////////////////////////////////////////////////////////
//ZLib1 API.
//                                                 Dmitry Kovalenko. 06.01.2019.
#ifndef _ibp_external__zlib1__api_H_
#define _ibp_external__zlib1__api_H_

namespace lcpi{namespace ibp{namespace external{namespace zlib1{namespace api{
////////////////////////////////////////////////////////////////////////////////

static const char ZLIB_VERSION[]="1.2.8";

////////////////////////////////////////////////////////////////////////////////

typedef unsigned char  Byte;  /* 8 bits */
typedef unsigned int   uInt;  /* 16 bits or more */
typedef unsigned long  uLong; /* 32 bits or more */

typedef void*          voidpf;

////////////////////////////////////////////////////////////////////////////////

typedef Byte           Bytef;

////////////////////////////////////////////////////////////////////////////////

typedef voidpf (*alloc_func)(voidpf opaque, uInt items, uInt size);

typedef void   (*free_func)(voidpf opaque, voidpf address);

////////////////////////////////////////////////////////////////////////////////

typedef uInt zbuf_size_type;

////////////////////////////////////////////////////////////////////////////////

typedef struct z_stream_s
{
 const Bytef*   next_in;     /* next input byte */
 zbuf_size_type avail_in;    /* number of bytes available at next_in */
 uLong          total_in;    /* total number of input bytes read so far */

 Bytef*         next_out;    /* next output byte should be put there */
 zbuf_size_type avail_out;   /* remaining free space at next_out */
 uLong          total_out;   /* total number of bytes output so far */

 const char*    msg;         /* last error message, NULL if no error */
 void*          state;       /* not visible by applications */

 alloc_func     zalloc;      /* used to allocate the internal state */
 free_func      zfree;       /* used to free the internal state */
 voidpf         opaque;      /* private data object passed to zalloc and zfree */

 int            data_type;   /* best guess about the data type: binary or text */
 uLong          adler;       /* adler32 value of the uncompressed data */
 uLong          reserved;    /* reserved for future use */
} z_stream;

typedef z_stream* z_streamp;

////////////////////////////////////////////////////////////////////////////////

enum
{
 Z_OK            = 0,
 Z_STREAM_END    = 1,
 Z_NEED_DICT     = 2,
 Z_ERRNO         = -1,
 Z_STREAM_ERROR  = -2,
 Z_DATA_ERROR    = -3,
 Z_MEM_ERROR     = -4,
 Z_BUF_ERROR     = -5,
 Z_VERSION_ERROR = -6,
};//enum

////////////////////////////////////////////////////////////////////////////////

enum
{
 Z_NO_COMPRESSION         =0,
 Z_BEST_SPEED             =1,
 Z_BEST_COMPRESSION       =9,
 Z_DEFAULT_COMPRESSION    =-1,
};//enum

////////////////////////////////////////////////////////////////////////////////

enum
{
 Z_NO_FLUSH      = 0,
 Z_PARTIAL_FLUSH = 1,
 Z_SYNC_FLUSH    = 2,
 Z_FULL_FLUSH    = 3,
 Z_FINISH        = 4,
 Z_BLOCK         = 5,
 Z_TREES         = 6,
};//enum

////////////////////////////////////////////////////////////////////////////////

#define ZLIB1_EXPORT

#define ZLIB1_FN(name) t_fn_##name

////////////////////////////////////////////////////////////////////////////////

typedef int ZLIB1_EXPORT ZLIB1_FN(deflateInit_)
                            (z_stream*   strm,
                             int         level,
                             const char* version,
                             int         stream_size);

//------------------------------------------------------------------------

typedef int ZLIB1_EXPORT ZLIB1_FN(deflate)
                            (z_stream* strm,
                             int       flush);

//------------------------------------------------------------------------

typedef int ZLIB1_EXPORT ZLIB1_FN(deflateEnd)
                            (z_stream* strm);

////////////////////////////////////////////////////////////////////////////////

typedef int ZLIB1_EXPORT ZLIB1_FN(inflateInit_)
                            (z_stream*   strm,
                             const char* version,
                             int         stream_size);

//------------------------------------------------------------------------

typedef int ZLIB1_EXPORT ZLIB1_FN(inflate)
                            (z_stream* strm,
                             int       flush);

//------------------------------------------------------------------------

typedef int ZLIB1_EXPORT ZLIB1_FN(inflateEnd)
                            (z_stream* strm);

////////////////////////////////////////////////////////////////////////////////

#undef ZLIB1_FN
#undef ZLIB1_EXPORT

////////////////////////////////////////////////////////////////////////////////
}/*nms api*/}/*nms zlib1*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
#endif
