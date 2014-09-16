/* $Id: WHardwareTimer.h 1154 2011-06-07 01:25:23Z bhagman $
||
|| @author         Brett Hagman <bhagman@wiring.org.co>
|| @url            http://wiring.org.co/
|| @contribution   Hernando Barragan <b@wiring.org.co>
||
|| @description
|| | Hardware Timer class for Atmel AVR 8 bit microcontroller series core.
|| |
|| | Wiring Core API
|| #
||
|| @license Please see cores/Common/License.txt.
||
*/

#ifndef WHARDWARETIMER_H
#define WHARDWARETIMER_H

#include <inttypes.h>
#include <io.h>
#include <signal.h>
#include <stddef.h>

#define NUM_16BIT_TIMERS 2
#define CLOCK_STOP 			0
#define	TMR_12KHZ			1
#define	TMR_6KHZ			2
#define	TMR_3KHZ			3
#define	TMR_1K5HZ			4
#define	TMR_0K75Hz			5
#define	TMR_0K375HZ			6
#define	TMR_0K1875HZ		7
#define	TMR_8MHZ			8	
#define	TMR_4MHZ			9	
#define	TMR_2MHZ			10
#define	TMR_1MHZ			11
#define	TMR_0M5Hz			12	
#define	TMR_0M25HZ			13	
#define	TMR_0M125HZ			14
#define	TMR_TACLK			15

//Compare/Capture channel declarations:
#define CHANNEL_A                       0
#define CHANNEL_B                       1
#define CHANNEL_C                       2
//Channels rename:
#define CHANNEL_0 	CHANNEL_A                       
#define CHANNEL_1 	CHANNEL_B                       
#define CHANNEL_2	CHANNEL_C           

#define INTERRUPT_OVERFLOW              0
#define INTERRUPT_COMPARE_MATCH_A       1
#define INTERRUPT_COMPARE_MATCH_B       2
#define INTERRUPT_COMPARE_MATCH_C       3     

#define STOP_MODE 	0	//Stop mode: the timer is halted.
#define UP_MODE		1	//Up mode: the timer counts up to TACCR0.
#define CONT_MODE	2	//Continuous mode: the timer counts up to 0FFFFh.
#define UD_MODE		3	//Up/down mode: the timer counts up to TACCR0 then down to 0000h.       
#define CAP_RISING	4
#define CAP_FALLING	5

interrupt(TIMER0_A1_VECTOR) TIMER0_COMPA1_2_OVF_routine();
interrupt(TIMER0_A0_VECTOR) TIMER0_COMPA0_routine();


interrupt(TIMER1_A1_VECTOR) TIMER1_COMPA1_2_OVF_routine();
interrupt(TIMER1_A0_VECTOR) TIMER1_COMPA0_routine();

class HardwareTimer
{

  friend void TIMER0_COMPA1_2_OVF_routine();
  friend void TIMER0_COMPA0_routine();
  friend void TIMER1_COMPA1_2_OVF_routine();
  friend void TIMER1_COMPA0_routine();

  private:
    uint8_t _timerNumber;
    uint8_t _channelCount;
    // Control registers
    volatile uint16_t *_tanr;
    volatile uint16_t *_tanctl;
    volatile uint16_t *_tancctl0;
    volatile uint16_t *_tancctl1;
    volatile uint16_t *_tancctl2;
    volatile uint16_t *_tanccr0;
    volatile uint16_t *_tanccr1;
    volatile uint16_t *_tanccr2;
    // User function pointers
    void (*overflowFunction)(void);
    void (*compareMatchAFunction)(void);
    void (*compareMatchBFunction)(void);
    void (*compareMatchCFunction)(void);
  
  public:
    HardwareTimer(uint8_t timerNumber);

    inline void stop(void) { setMode(CLOCK_STOP); };
    void setClockSource(uint8_t clockSource);
    void setInterrupt(uint8_t interrupt, uint8_t value);
    inline void enableInterrupt(uint8_t interrupt) { setInterrupt(interrupt, 1); };
    inline void disableInterrupt(uint8_t interrupt) { setInterrupt(interrupt, 0); };
    void attachInterrupt(uint8_t interrupt, void (*userFunc)(void), uint8_t enable = 1);
    inline void detachInterrupt(uint8_t interrupt) { attachInterrupt(interrupt, NULL, 0); };
    void setMode(uint8_t mode);
    // uint16_t getClockSource();
    void setOutputMode(uint8_t channel, uint8_t outputMode);
    void setOCR(uint8_t channel, uint16_t value);
    void setCounter(uint16_t value);
    uint16_t getCounter(void);
};

extern HardwareTimer Timer0;

extern HardwareTimer Timer1;


#endif
// WHARDWARETIMER_H
