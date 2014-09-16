/*
 * Copyright (c) 2001 Dmitry Dicky diwil@eis.ru
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS `AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $Id: stdlib.h,v 1.13 2008/06/03 13:16:57 cliechti Exp $
 */

#if !defined(__STDLIB_H_)
#define __STDLIB_H_ 1

#include <stddef.h>
#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(__ATTR_CONST__)
#define __ATTR_CONST__ __attribute__((__const__))
#endif

#if !defined(__ATTR_MALLOC__)
#define __ATTR_MALLOC__ __attribute__((__malloc__))
#endif

#if !defined(__ATTR_NORETURN__)
#define __ATTR_NORETURN__ __attribute__((__noreturn__))
#endif
 
#if !defined(__ATTR_PURE__)
#define __ATTR_PURE__ __attribute__((__pure__))
#endif

#if !defined(exit)
extern void exit(int) __asm__("__stop_progExec__") __ATTR_CONST__;
#endif


typedef struct
{
	int quot;
	int rem;
} div_t;

extern  div_t div(int num, int denom);

typedef struct
{
	long quot;
	long rem;
} ldiv_t;

extern ldiv_t ldiv(long num, long denom);

extern int abs(int __x) __ATTR_CONST__;
extern long labs(long __x) __ATTR_CONST__;
#ifdef __GNUC_GNU_INLINE__
extern __inline__ int abs(int __x)
{
	return (__x < 0)  ?  -__x  :  __x;
}
         
extern __inline__ long labs(long __x)
{
	return (__x < 0)  ?  -__x  :  __x;
}
#endif /* __USE_EXTERN_INLINES */
extern void *realloc(void *__ptr, size_t __size) __ATTR_MALLOC__;
extern long strtol(const char *, char **, int);
extern unsigned long strtoul(const char *, char **, int);

extern int atoi(const char *p);
extern long atol(const char *p);
extern char *itoa(int num, char *str, int radix);
extern char *utoa(unsigned num, char *str, int radix);
extern char *ltoa(long num, char *str, int radix);
extern char *ultoa(unsigned long num, char *str, int radix);

extern void *malloc(size_t size);
extern void free(void *p);
extern void *bsearch(const void *, const void *, size_t, size_t, register int (*compar)(const void *, const void *));

extern void abort(void);

#ifndef RAND_MAX
#define RAND_MAX	0x7fffffffL
#endif

extern int rand(void);
extern void srand(unsigned __seed);
extern int rand_r(unsigned *__seed);

#ifdef __cplusplus
}
#endif


#endif
