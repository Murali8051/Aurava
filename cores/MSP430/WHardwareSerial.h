/* $Id: WHardwareSerial.h 1154 2011-06-07 01:25:23Z bhagman $
||
||   Aurava Modification
|| @license Please see cores/Common/License.txt.
||
*/

#ifndef WHARDWARESERIAL_H
#define WHARDWARESERIAL_H

#include <inttypes.h>
#include <isr_compat.h>
#include <Stream.h>
#include <FIFO.h>

#define RX_BUFFER_SIZE 32
#define TX_BUFFER_SIZE 16

#define SERIALPORTS 0

#if defined(USCIAB0RX_VECTOR)
#undef SERIALPORTS
#define SERIALPORTS 1
#define Serial_RX_vect USCIAB0RX_VECTOR
#define Serial_TX_vect USCIAB0TX_VECTOR
#endif


// Now, provide the class only if the hardware has at least one serial port.
#if SERIALPORTS > 0

#if !defined(SINGLEUSART1)
interrupt(Serial_RX_vect) receive_routine(void);
interrupt(Serial_TX_vect) transmit_routine(void);
#endif


class HardwareSerial : public Stream
{
#if !defined(SINGLEUSART1)
  friend void receive_routine();
  friend void transmit_routine();
#endif

  private:
      FIFO<uint8_t,RX_BUFFER_SIZE> rxfifo;
      FIFO<uint8_t,TX_BUFFER_SIZE> txfifo;
    volatile uint8_t *_ubrrh;
    volatile uint8_t *_ubrrl;
    volatile uint8_t *_ucr0;
    volatile uint8_t *_ucr1;
    volatile uint8_t *_umodctl;
    const volatile unsigned char *_urxbuf;
    volatile unsigned char *_utxbuf;
  public:
    HardwareSerial(uint8_t SerialPortNumber);
    void begin(const uint32_t baud = 9600,
               const uint8_t data_bits = 8,
               const uint8_t stop_bits = 1,
               const uint8_t parity = 0);
    void end();
    int available(void);
      int read(void);
    int peek(void);
    void flush(void);
      void write(uint8_t);
};

#if !defined(SINGLEUSART1)
extern HardwareSerial Serial;
#endif

#endif // SERIALPORTS > 0

#endif
// WHARDWARESERIAL_H
