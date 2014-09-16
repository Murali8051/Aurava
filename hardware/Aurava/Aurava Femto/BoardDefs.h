
#ifndef WBOARDDEFS_H
#define WBOARDDEFS_H

#include "WConstants.h"

#include <msp430g2553.h>
#include <signal.h>
#include <io.h>

#define TOTAL_PINS              18
#define TOTAL_ANALOG_PINS       8
#define FIRST_ANALOG_PIN        0

// For LED1
#define WLED                    0

// How many ports are on this device
#define WIRING_PORTS 2

/*************************************************************
 * Prototypes
 *************************************************************/

void boardInit(void);


/*************************************************************
 * Pin locations - constants
 *************************************************************/

// SPI port
const static uint8_t SS   = 4; //To configure P1.4 as CS pin
const static uint8_t MOSI = 8;
const static uint8_t MISO = 7;
const static uint8_t SCK  = 5;

// TWI port
const static uint8_t SCL  = 7;
const static uint8_t SDA  = 8;

// Analog pins
const static uint8_t A0 = 0;
const static uint8_t A1 = 1;
const static uint8_t A2 = 2;
const static uint8_t A3 = 3;
const static uint8_t A4 = 4;
const static uint8_t A5 = 5;
const static uint8_t A6 = 12;
const static uint8_t A7 = 13;

/*
// External Interrupts
const static uint8_t EI0 = 2;
const static uint8_t EI1 = 3;

// Hardware Serial port pins
const static uint8_t RX0 = 0;
const static uint8_t TX0 = 1;
*/

/*************************************************************
 * Pin to register mapping macros
 *************************************************************/

#define digitalPinToPortReg(PIN) \
        ( ((PIN) >= 0  && (PIN) <= 5)  ? &P1OUT : \
		( ((PIN) >= 6  && (PIN) <= 11) ? &P2OUT	: \
		( ((PIN) >= 12 && (PIN) <= 13) ? &P1OUT	: \
        ( ((PIN) >= 14  && (PIN) <= 15)  ? &P2OUT : NOT_A_REG))))

#define digitalPinToBit(PIN) \
        ( ((PIN) >= 0  && (PIN) <= 5)  ? ((PIN)) : \
		( ((PIN) >= 6  && (PIN) <= 11) ? ((PIN) - 6) : \
		( ((PIN) >= 12 && (PIN) <= 13) ? ((PIN) - 6) : \
        ( ((PIN) >= 14 && (PIN) <= 15) ? ((PIN) - 8) : 0))))

#define digitalPinToBitMask(PIN) (1 << (digitalPinToBit(PIN)))

#define digitalPinToPort(PIN) \
        ( ((PIN) >= 0  && (PIN) <= 5)  ? 1 : \
		( ((PIN) >= 6  && (PIN) <= 11) ? 2 : \
		( ((PIN) >= 12 && (PIN) <= 13) ? 1 : \
        ( ((PIN) >= 14  && (PIN) <= 15)  ? 2 : NOT_A_PORT))))

#define digitalPinToTimer(PIN) \
        ( ((PIN) == 1) ? TIMER_A0 : \
        ( ((PIN) == 2) ? TIMER_A1 : NOT_A_TIMER))

#define portOutputRegister(PORT) \
        ( ((PORT) == 1 ) ? &P1OUT : \
        ( ((PORT) == 2 ) ? &P2OUT : NOT_A_REG))

#define portInputRegister(PORT) \
        ( ((PORT) == 1 ) ? &P1IN : \
        ( ((PORT) == 2 ) ? &P2IN : NOT_A_REG))

#define portModeRegister(PORT) \
        ( ((PORT) == 1 ) ? &P1DIR : \
        ( ((PORT) == 2 ) ? &P2DIR : NOT_A_REG))
/*
#define pinToInterrupt(PIN) \
        ( ((PIN) == 2) ? EXTERNAL_INTERRUPT_0 : \
        ( ((PIN) == 3) ? EXTERNAL_INTERRUPT_1 : -1))
*/
/*************************************************************
 * Timer prescale factors
 *************************************************************/

#define TIMER0PRESCALEFACTOR 64




#endif
// BOARDDEFS_H
