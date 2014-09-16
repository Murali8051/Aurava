

#ifndef WBOARDDEFS_H
#define WBOARDDEFS_H

//#include "WConstants.h"

#include <msp430g2231.h>
#include <signal.h>
#include <io.h>

#define TOTAL_PINS              14
#define TOTAL_ANALOG_PINS       7
#define FIRST_ANALOG_PIN        2

#define WLED                    2

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
const static uint8_t SS   = 10;
const static uint8_t MOSI = 8;
const static uint8_t MISO = 9;
const static uint8_t SCK  = 7;

// TWI port
const static uint8_t SCL  = 8;
const static uint8_t SDA  = 9;

// Analog pins
const static uint8_t A0 = 0;
const static uint8_t A1 = 1;
const static uint8_t A2 = 2;
const static uint8_t A3 = 3;
const static uint8_t A4 = 4;
const static uint8_t A5 = 5;

// External Interrupts
const static uint8_t EI0 = 2;
const static uint8_t EI1 = 3;

// Hardware Serial port pins
const static uint8_t RX0 = 0;
const static uint8_t TX0 = 1;


/*************************************************************
 * Pin to register mapping macros
 *************************************************************/

#define digitalPinToPortReg(PIN) \
        ( ((PIN) >= 0  && (PIN) <= 7)  ? &PORTD : \
        ( ((PIN) >= 8  && (PIN) <= 13) ? &PORTB : \
        ( ((PIN) >= 14 && (PIN) <= 19) ? &PORTC : NOT_A_REG)))

#define digitalPinToBit(PIN) \
        ( ((PIN) >= 0  && (PIN) <= 7)  ? ((PIN)) : \
        ( ((PIN) >= 8  && (PIN) <= 13) ? ((PIN) - 8) : \
        ( ((PIN) >= 14 && (PIN) <= 19) ? ((PIN) - 14) : 0)))

#define digitalPinToBitMask(PIN) (1 << (digitalPinToBit(PIN)))

#define digitalPinToPort(PIN) \
        ( ((PIN) >= 0  && (PIN) <= 7)  ? 0 : \
        ( ((PIN) >= 8  && (PIN) <= 13) ? 1 : \
        ( ((PIN) >= 14 && (PIN) <= 19) ? 2 : NOT_A_PORT)))

#define digitalPinToTimer(PIN) \
        ( ((PIN) == 3) ? TIMER2B : \
        ( ((PIN) == 5) ? TIMER0B : \
        ( ((PIN) == 6) ? TIMER0A : \
        ( ((PIN) == 9) ? TIMER1A : \
        ( ((PIN) == 10) ? TIMER1B : \
        ( ((PIN) == 11) ? TIMER2A : NOT_A_TIMER))))))

#define portOutputRegister(PORT) \
        ( ((PORT) == 0 ) ? &PORTD : \
        ( ((PORT) == 1 ) ? &PORTB : \
        ( ((PORT) == 2 ) ? &PORTC : NOT_A_REG)))

#define portInputRegister(PORT) \
        ( ((PORT) == 0 ) ? &PIND : \
        ( ((PORT) == 1 ) ? &PINB : \
        ( ((PORT) == 2 ) ? &PINC : NOT_A_REG)))

#define portModeRegister(PORT) \
        ( ((PORT) == 0 ) ? &DDRD : \
        ( ((PORT) == 1 ) ? &DDRB : \
        ( ((PORT) == 2 ) ? &DDRC : NOT_A_REG)))

#define pinToInterrupt(PIN) \
        ( ((PIN) == 2) ? EXTERNAL_INTERRUPT_0 : \
        ( ((PIN) == 3) ? EXTERNAL_INTERRUPT_1 : -1))

/*************************************************************
 * Timer prescale factors
 *************************************************************/

#define TIMER0PRESCALEFACTOR 64




#endif
// BOARDDEFS_H
