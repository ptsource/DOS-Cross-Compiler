/* Copyright (C) 1995 DJ Delorie, see COPYING.DJ for details */
#ifndef __dj_include_libc_file_h__
#define __dj_include_libc_file_h__

#include <fcntl.h>
#include <libc/dosio.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __dj_ENFORCE_ANSI_FREESTANDING

#ifndef __STRICT_ANSI__

#ifndef _POSIX_SOURCE

#define _IOREAD   000010
#define _IOWRT    000020
#define _IOMYBUF  000040
#define _IOEOF    000100
#define _IOERR    000200
#define _IOSTRG   000400
#define _IORW     001000
#define _IOAPPEND 002000
#define _IORMONCL 004000  /* remove on close, for temp files */
/* if _flag & _IORMONCL, ._name_to_remove needs freeing */
#define _IOUNGETC 010000  /* there is an ungetc'ed character in the buffer */

int	_flsbuf(int, FILE*);
int	_filbuf(FILE *);
void	_fwalk(void (*)(FILE *));

int __inline__ static __getc_raw(FILE *const p)
{
   if(p->_cnt>0)
   {
      p->_cnt--;
      return((unsigned char)*(p->_ptr++));
   }
   return(_filbuf(p));
}

int __inline__ static __putc_raw(int const x,FILE *const p)
{
   if(p->_cnt>0)
   {
      p->_cnt--;
      return((unsigned char)(*(p->_ptr++)=(unsigned char)x));
   }
   return(_flsbuf(x,p));
}

int __inline__ static __is_text_file(FILE *const p)
{
   return(!((p)->_flag&_IOSTRG) && (__file_handle_modes[(p)->_file]&O_TEXT));
}

int __inline__ static __getc(FILE *const p)
{
  int __c=__getc_raw(p);
  if (__c=='\r' && __is_text_file(p))
    return __getc_raw(p);
  return __c;
}

int __inline__ static __putc(const int x,FILE *const p)
{
  if(x=='\n' && __is_text_file(p))
    __putc_raw('\r',p);
  return __putc_raw(x,p);
}

#undef  fileno
#define fileno(f)	(f->_file)
#undef  feof
#define feof(f)		(((f)->_flag&_IOEOF)!=0)
#undef  ferror
#define ferror(f)	(((f)->_flag&_IOERR)!=0)

#endif /* !_POSIX_SOURCE */
#endif /* !__STRICT_ANSI__ */
#endif /* !__dj_ENFORCE_ANSI_FREESTANDING */

#ifndef __dj_ENFORCE_FUNCTION_CALLS
#endif /* !__dj_ENFORCE_FUNCTION_CALLS */

#ifdef __cplusplus
}
#endif

#endif /* __dj_include_libc_file_h__ */
