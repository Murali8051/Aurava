/* Copyright (c) 2002-2007  Marek Michalkiewicz
   Copyright (c) 2006, Carlos Lamas
   Copyright (c) 2009-2010, Jan Waclawek
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.
   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

/* $Id: pgmspace.h 2169 2010-06-14 06:28:23Z arcanum $ */

/*
   pgmspace.h

   Contributors:
     Created by Marek Michalkiewicz <marekm@linux.org.pl>
     Eric B. Weddington <eric@ecentral.com>
     Wolfgang Haidinger <wh@vmars.tuwien.ac.at> (pgm_read_dword())
     Ivanov Anton <anton@arc.com.ru> (pgm_read_float())
 */

/** \file */
/** \defgroup avr_pgmspace <avr/pgmspace.h>: Program Space Utilities
    \code
    #include <avr/io.h>
    #include <avr/pgmspace.h>
    \endcode

    The functions in this module provide interfaces for a program to access
    data stored in program space (flash memory) of the device.  In order to
    use these functions, the target device must support either the \c LPM or
    \c ELPM instructions.

    \note These functions are an attempt to provide some compatibility with
    header files that come with IAR C, to make porting applications between
    different compilers easier.  This is not 100% compatibility though (GCC
    does not have full support for multiple address spaces yet).

    \note If you are working with strings which are completely based in ram,
    use the standard string functions described in \ref avr_string.

    \note If possible, put your constant tables in the lower 64 KB and use
    pgm_read_byte_near() or pgm_read_word_near() instead of
    pgm_read_byte_far() or pgm_read_word_far() since it is more efficient that
    way, and you can still use the upper 64K for executable code.
    All functions that are suffixed with a \c _P \e require their
    arguments to be in the lower 64 KB of the flash ROM, as they do
    not use ELPM instructions.  This is normally not a big concern as
    the linker setup arranges any program space constants declared
    using the macros from this header file so they are placed right after
    the interrupt vectors, and in front of any executable code.  However,
    it can become a problem if there are too many of these constants, or
    for bootloaders on devices with more than 64 KB of ROM.
    <em>All these functions will not work in that situation.</em>

    \note For <b>Xmega</b> devices, make sure the NVM controller
    command register (\c NVM.CMD or \c NVM_CMD) is set to 0x00 (NOP)
    before using any of these functions.
*/

#ifndef __PGMSPACE_H_
#define __PGMSPACE_H_ 1

#define __need_size_t
#include <inttypes.h>
#include <stddef.h>
#include <io.h>

#ifndef __ATTR_CONST__
#define __ATTR_CONST__ __attribute__((__const__))
#endif

#ifndef __ATTR_PROGMEM__
#define __ATTR_PROGMEM__ __attribute__((__progmem__))
#endif

#ifndef __ATTR_PURE__
#define __ATTR_PURE__ __attribute__((__pure__))
#endif

/**
   \ingroup avr_pgmspace
   \def PROGMEM

   Attribute to use in order to declare an object being located in
   flash ROM.
 */
#define PROGMEM __ATTR_PROGMEM__

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__DOXYGEN__)
/*
 * Doxygen doesn't grok the appended attribute syntax of
 * GCC, and confuses the typedefs with function decls, so
 * supply a doxygen-friendly view.
 */
/**
   \ingroup avr_pgmspace
   \typedef prog_void

   Type of a "void" object located in flash ROM.  Does not make much
   sense by itself, but can be used to declare a "void *" object in
   flash ROM.
*/
typedef void PROGMEM prog_void;
/**
   \ingroup avr_pgmspace
   \typedef prog_char

   Type of a "char" object located in flash ROM.
*/
typedef char PROGMEM prog_char;

/**
   \ingroup avr_pgmspace
   \typedef prog_uchar

   Type of an "unsigned char" object located in flash ROM.
*/
typedef unsigned char PROGMEM prog_uchar;


/**
   \ingroup avr_pgmspace
   \typedef prog_int8_t

   Type of an "int8_t" object located in flash ROM.
*/
typedef int8_t PROGMEM prog_int8_t;

/**
   \ingroup avr_pgmspace
   \typedef prog_uint8_t

   Type of an "uint8_t" object located in flash ROM.
*/
typedef uint8_t PROGMEM prog_uint8_t;

/**
   \ingroup avr_pgmspace
   \typedef prog_int16_t

   Type of an "int16_t" object located in flash ROM.
*/
typedef int16_t PROGMEM prog_int16_t;

/**
   \ingroup avr_pgmspace
   \typedef prog_uint16_t

   Type of an "uint16_t" object located in flash ROM.
*/
typedef uint16_t PROGMEM prog_uint16_t;

/**
   \ingroup avr_pgmspace
   \typedef prog_int32_t

   Type of an "int32_t" object located in flash ROM.
*/
typedef int32_t PROGMEM prog_int32_t;

/**
   \ingroup avr_pgmspace
   \typedef prog_uint32_t

   Type of an "uint32_t" object located in flash ROM.
*/
typedef uint32_t PROGMEM prog_uint32_t;

/**
   \ingroup avr_pgmspace
   \typedef prog_int64_t

   Type of an "int64_t" object located in flash ROM.

   \note This type is not available when the compiler
   option -mint8 is in effect.
*/
typedef int64_t PROGMEM prog_int64_t;

/**
   \ingroup avr_pgmspace
   \typedef prog_uint64_t

   Type of an "uint64_t" object located in flash ROM.

   \note This type is not available when the compiler
   option -mint8 is in effect.
*/
typedef uint64_t PROGMEM prog_uint64_t;
#else  /* !DOXYGEN */
typedef void prog_void PROGMEM;
typedef char prog_char PROGMEM;
typedef unsigned char prog_uchar PROGMEM;

typedef int8_t    prog_int8_t   PROGMEM;
typedef uint8_t   prog_uint8_t  PROGMEM;
typedef int16_t   prog_int16_t  PROGMEM;
typedef uint16_t  prog_uint16_t PROGMEM;
typedef int32_t   prog_int32_t  PROGMEM;
typedef uint32_t  prog_uint32_t PROGMEM;
#if !__USING_MINT8
typedef int64_t   prog_int64_t  PROGMEM;
typedef uint64_t  prog_uint64_t PROGMEM;
#endif
#endif /* defined(__DOXYGEN__) */

/* Although in C, we can get away with just using __c, it does not work in
   C++. We need to use &__c[0] to avoid the compiler puking. Dave Hylands
   explaned it thusly,

     Let's suppose that we use PSTR("Test"). In this case, the type returned
     by __c is a prog_char[5] and not a prog_char *. While these are
     compatible, they aren't the same thing (especially in C++). The type
     returned by &__c[0] is a prog_char *, which explains why it works
     fine. */

#if defined(__DOXYGEN__)
/*
 * The #define below is just a dummy that serves documentation
 * purposes only.
 */
/** \ingroup avr_pgmspace
    \def PSTR(s)

    Used to declare a static pointer to a string in program space. */
# define PSTR(s) ((const PROGMEM char *)(s))
#else  /* !DOXYGEN */
/* The real thing. */
# define PSTR(s) (__extension__({static char __c[] PROGMEM = (s); &__c[0];}))
#endif /* DOXYGEN */

#define __LPM_classic__(addr)   \
(__extension__({                \
    uint16_t __addr16 = (uint16_t)(addr); \
    uint8_t __result;           \
    ( __result=*((uint8_t *)__addr16)); \
    __result;                   \
}))


#define __LPM_word_classic__(addr)          \
(__extension__({                            \
    uint16_t __addr16 = (uint16_t)(addr);   \
    uint16_t __result;                      \
 ( __result=*((uint16_t*)__addr16)); \
   __result;                               \
}))


#define __LPM_dword_classic__(addr)         \
(__extension__({                            \
    uint16_t __addr16 = (uint16_t)(addr);   \
    uint32_t __result;                      \
 ( __result=*((uint32_t*)__addr16)); \
    __result;                               \
}))


#define __LPM_float_classic__(addr)         \
(__extension__({                            \
    uint16_t __addr16 = (uint16_t)(addr);   \
    float __result;                         \
 ( __result=*((float*)__addr16)); \
    __result;                               \
}))

#define __LPM(addr)         __LPM_classic__(addr)
#define __LPM_word(addr)    __LPM_word_classic__(addr)
#define __LPM_dword(addr)   __LPM_dword_classic__(addr)
#define __LPM_float(addr)   __LPM_float_classic__(addr)


/** \ingroup avr_pgmspace
    \def pgm_read_byte_near(address_short)
    Read a byte from the program space with a 16-bit (near) address. 
    \note The address is a byte address.
    The address is in the program space. */

#define pgm_read_byte_near(address_short) __LPM((uint16_t)(address_short))

/** \ingroup avr_pgmspace
    \def pgm_read_word_near(address_short)
    Read a word from the program space with a 16-bit (near) address. 
    \note The address is a byte address. 
    The address is in the program space. */

#define pgm_read_word_near(address_short) __LPM_word((uint16_t)(address_short))

/** \ingroup avr_pgmspace
    \def pgm_read_dword_near(address_short)
    Read a double word from the program space with a 16-bit (near) address. 
    \note The address is a byte address. 
    The address is in the program space. */

#define pgm_read_dword_near(address_short) \
    __LPM_dword((uint16_t)(address_short))

/** \ingroup avr_pgmspace
    \def pgm_read_float_near(address_short)
    Read a float from the program space with a 16-bit (near) address. 
    \note The address is a byte address. 
    The address is in the program space. */

#define pgm_read_float_near(address_short) \
    __LPM_float((uint16_t)(address_short))


/** \ingroup avr_pgmspace
    \def pgm_read_byte(address_short)
    Read a byte from the program space with a 16-bit (near) address. 

    \note The address is a byte address. 
    The address is in the program space. */

#define pgm_read_byte(address_short)    pgm_read_byte_near(address_short)

/** \ingroup avr_pgmspace
    \def pgm_read_word(address_short)
    Read a word from the program space with a 16-bit (near) address. 

    \note The address is a byte address. 
    The address is in the program space. */

#define pgm_read_word(address_short)    pgm_read_word_near(address_short)

/** \ingroup avr_pgmspace
    \def pgm_read_dword(address_short)
    Read a double word from the program space with a 16-bit (near) address. 

    \note The address is a byte address. 
    The address is in the program space. */

#define pgm_read_dword(address_short)   pgm_read_dword_near(address_short)

/** \ingroup avr_pgmspace
    \def pgm_read_float(address_short)
    Read a float from the program space with a 16-bit (near) address. 

    \note The address is a byte address. 
    The address is in the program space. */

#define pgm_read_float(address_short)   pgm_read_float_near(address_short)

/** \ingroup avr_pgmspace
    \def PGM_P

    Used to declare a variable that is a pointer to a string in program
    space. */

#ifndef PGM_P
#define PGM_P const prog_char *
#endif

/** \ingroup avr_pgmspace
    \def PGM_VOID_P

    Used to declare a generic pointer to an object in program space. */

#ifndef PGM_VOID_P
#define PGM_VOID_P const prog_void *
#endif



extern PGM_VOID_P memchr_P(PGM_VOID_P, int __val, size_t __len) __ATTR_CONST__;
extern int memcmp_P(const void *, PGM_VOID_P, size_t) __ATTR_PURE__;
extern void *memccpy_P(void *, PGM_VOID_P, int __val, size_t);
extern void *memcpy_P(void *, PGM_VOID_P, size_t);
extern void *memmem_P(const void *, size_t, PGM_VOID_P, size_t) __ATTR_PURE__;
extern PGM_VOID_P memrchr_P(PGM_VOID_P, int __val, size_t __len) __ATTR_CONST__;
extern char *strcat_P(char *, PGM_P);
extern PGM_P strchr_P(PGM_P, int __val) __ATTR_CONST__;
extern PGM_P strchrnul_P(PGM_P, int __val) __ATTR_CONST__;
extern int strcmp_P(const char *, PGM_P) __ATTR_PURE__;
extern char *strcpy_P(char *, PGM_P);
extern int strcasecmp_P(const char *, PGM_P) __ATTR_PURE__;
extern char *strcasestr_P(const char *, PGM_P) __ATTR_PURE__;
extern size_t strcspn_P(const char *__s, PGM_P __reject) __ATTR_PURE__;
extern size_t strlcat_P (char *, PGM_P, size_t );
extern size_t strlcpy_P (char *, PGM_P, size_t );
extern size_t strlen_P(PGM_P) __ATTR_CONST__; /* program memory can't change */
extern size_t strnlen_P(PGM_P, size_t) __ATTR_CONST__; /* program memory can't change */
extern int strncmp_P(const char *, PGM_P, size_t) __ATTR_PURE__;
extern int strncasecmp_P(const char *, PGM_P, size_t) __ATTR_PURE__;
extern char *strncat_P(char *, PGM_P, size_t);
extern char *strncpy_P(char *, PGM_P, size_t);
extern char *strpbrk_P(const char *__s, PGM_P __accept) __ATTR_PURE__;
extern PGM_P strrchr_P(PGM_P, int __val) __ATTR_CONST__;
extern char *strsep_P(char **__sp, PGM_P __delim);
extern size_t strspn_P(const char *__s, PGM_P __accept) __ATTR_PURE__;
extern char *strstr_P(const char *, PGM_P) __ATTR_PURE__;
extern char *strtok_P(char *__s, PGM_P __delim);
extern char *strtok_rP(char *__s, PGM_P __delim, char **__last);

//extern size_t strlen_PF (uint_farptr_t src) __ATTR_CONST__; /* program memory can't change */
//extern size_t strnlen_PF (uint_farptr_t src, size_t len) __ATTR_CONST__; /* program memory can't change */
//extern void *memcpy_PF (void *dest, uint_farptr_t src, size_t len);
//extern char *strcpy_PF (char *dest, uint_farptr_t src);
//extern char *strncpy_PF (char *dest, uint_farptr_t src, size_t len);
//extern char *strcat_PF (char *dest, uint_farptr_t src);
//extern size_t strlcat_PF (char *dst, uint_farptr_t src, size_t siz);
//extern char *strncat_PF (char *dest, uint_farptr_t src, size_t len);
//extern int strcmp_PF (const char *s1, uint_farptr_t s2) __ATTR_PURE__;
//extern int strncmp_PF (const char *s1, uint_farptr_t s2, size_t n) __ATTR_PURE__;
//extern int strcasecmp_PF (const char *s1, uint_farptr_t s2) __ATTR_PURE__;
//extern int strncasecmp_PF (const char *s1, uint_farptr_t s2, size_t n) __ATTR_PURE__;
//extern char *strstr_PF (const char *s1, uint_farptr_t s2);
//extern size_t strlcpy_PF (char *dst, uint_farptr_t src, size_t siz);
//extern int memcmp_PF(const void *, uint_farptr_t, size_t) __ATTR_PURE__;


#ifdef __cplusplus
}
#endif

#endif /* __PGMSPACE_H_ */
