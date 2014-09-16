/* $Id: Wiring.h 1154 2011-06-07 01:25:23Z bhagman $
||
|| @author         Murali Srinivasa
|| @url            http://
|| @contribution   
|| @contribution   
||
|| @description
|| | Wiring core prototype definitions.
|| | TI MSP430 microcontroller series core.
|| |
|| | Wiring Core API
|| #
||
|| @license Please see cores/Common/License.txt.
||
*/

#ifndef WIRING_H
#define WIRING_H

// Set our Core Platform
#define WIRING_CORE_TI_MSP430

#ifdef __cplusplus
extern "C" {
#endif

/*************************************************************
 * C Includes
 *************************************************************/

#include <math.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <msp430.h>
#include <isr_compat.h>
#include <pgmspace.h>

#include "WConstants.h"
#include "Binary.h"

/*************************************************************
 * Board specific definitions
 *************************************************************/

#define NOT_A_REG  NULL
#define NOT_A_PORT 0xFF

#include "BoardDefs.h"

/*************************************************************
 * C Core API Functions
 *
 * Delay and Timing
 *************************************************************/

#include "WDelay.h"

/*************************************************************
 * Digital
 *************************************************************/

#include "WDigital.h"

#define digitalWrite(PIN, VALUE) pinWrite(PIN, VALUE)
#define digitalRead(PIN) pinRead(PIN)

static inline void pullup(uint8_t PIN) { pinWrite(PIN, HIGH); }
static inline void noPullup(uint8_t PIN) { pinWrite(PIN, LOW); }


#ifdef __cplusplus
}
#endif



/*************************************************************
 * C++ Core API Functions
 *************************************************************/

#ifdef __cplusplus
#include "WVector.h"
#include "WString.h"
#include "WCharacter.h"
#include "WMemory.h"
#include "WShift.h"
#include "WMath.h"

#include "WHardwareSerial.h"

#include "WConstantTypes.h"

#include "WHardwareTimer.h"

// C++ Protection
__extension__ typedef int __guard __attribute__((mode (__DI__)));
extern "C" int __cxa_guard_acquire(__guard *);
extern "C" void __cxa_guard_release(__guard *);
extern "C" void __cxa_guard_abort(__guard *);
extern "C" void __cxa_pure_virtual(void);


// main program prototypes
void setup(void);
void loop(void);
// OS_main added to avr-gcc 4.4, WinAVR 4.3
// OS_main eliminates register save on main() entry
int main(void) __attribute__ ((noreturn,OS_main));

#endif // __cplusplus

#endif
// WIRING_H
