/* ============================================================================ */
/* Copyright (c) 2011, Texas Instruments Incorporated                     */
/*  All rights reserved.                                                        */
/*                                                                              */
/*  Redistribution and use in source and binary forms, with or without          */
/*  modification, are permitted provided that the following conditions          */
/*  are met:                                                                    */
/*                                                                              */
/*  *  Redistributions of source code must retain the above copyright           */
/*     notice, this list of conditions and the following disclaimer.            */
/*                                                                              */
/*  *  Redistributions in binary form must reproduce the above copyright        */
/*     notice, this list of conditions and the following disclaimer in the      */
/*     documentation and/or other materials provided with the distribution.     */
/*                                                                              */
/*  *  Neither the name of Texas Instruments Incorporated nor the names of      */
/*     its contributors may be used to endorse or promote products derived      */
/*     from this software without specific prior written permission.            */
/*                                                                              */
/*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" */
/*  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,       */
/*  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR      */
/*  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR            */
/*  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,       */
/*  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,         */
/*  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; */
/*  OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,    */
/*  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR     */
/*  OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,              */
/*  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                          */
/* ============================================================================ */

/********************************************************************
*
* Standard register and bit definitions for the Texas Instruments
* MSP430 microcontroller.
*
* This file supports assembler and C development for
* MSP430x16x devices.
*
* Texas Instruments, Version 2.7
*
* Rev. 2.0, Fixed definitions for DMA
* Rev. 2.1, Alignment of defintions in Users Guide and of version numbers
* Rev. 2.2, Fixed definitions for I2C
* Rev. 2.21,Fixed definitions for I2C for assembler
* Rev. 2.3, Fixed type in ADC12 bit definitions (replaced ADC10 with ADC12)
*           Added SVS
*           Added DMA request definitions
* Rev. 2.4, Removed unused def of TASSEL2 / TBSSEL2
* Rev. 2.5, Added VLD bits in SVS module
* Rev. 2.6, Fixed incorrect bits in I2C STT (wrong:SST) and I2C prefix was missing at some bits
* Rev. 2.7, added definitions for Interrupt Vectors xxIV
*
********************************************************************/

#ifndef __msp430x16x
#define __msp430x16x

#define __MSP430_TI_HEADERS__

#ifdef __cplusplus
extern "C" {
#endif

#include <iomacros.h>

/************************************************************
* STANDARD BITS
************************************************************/

#define BIT0                (0x0001)
#define BIT1                (0x0002)
#define BIT2                (0x0004)
#define BIT3                (0x0008)
#define BIT4                (0x0010)
#define BIT5                (0x0020)
#define BIT6                (0x0040)
#define BIT7                (0x0080)
#define BIT8                (0x0100)
#define BIT9                (0x0200)
#define BITA                (0x0400)
#define BITB                (0x0800)
#define BITC                (0x1000)
#define BITD                (0x2000)
#define BITE                (0x4000)
#define BITF                (0x8000)

/************************************************************
* STATUS REGISTER BITS
************************************************************/

#define C                   (0x0001)
#define Z                   (0x0002)
#define N                   (0x0004)
#define V                   (0x0100)
#define GIE                 (0x0008)
#define CPUOFF              (0x0010)
#define OSCOFF              (0x0020)
#define SCG0                (0x0040)
#define SCG1                (0x0080)

/* Low Power Modes coded with Bits 4-7 in SR */

#ifndef __STDC__ /* Begin #defines for assembler */
#define LPM0                (CPUOFF)
#define LPM1                (SCG0+CPUOFF)
#define LPM2                (SCG1+CPUOFF)
#define LPM3                (SCG1+SCG0+CPUOFF)
#define LPM4                (SCG1+SCG0+OSCOFF+CPUOFF)
/* End #defines for assembler */

#else /* Begin #defines for C */
#define LPM0_bits           (CPUOFF)
#define LPM1_bits           (SCG0+CPUOFF)
#define LPM2_bits           (SCG1+CPUOFF)
#define LPM3_bits           (SCG1+SCG0+CPUOFF)
#define LPM4_bits           (SCG1+SCG0+OSCOFF+CPUOFF)

#include "in430.h"

#define LPM0      _BIS_SR(LPM0_bits)     /* Enter Low Power Mode 0 */
#define LPM0_EXIT _BIC_SR_IRQ(LPM0_bits) /* Exit Low Power Mode 0 */
#define LPM1      _BIS_SR(LPM1_bits)     /* Enter Low Power Mode 1 */
#define LPM1_EXIT _BIC_SR_IRQ(LPM1_bits) /* Exit Low Power Mode 1 */
#define LPM2      _BIS_SR(LPM2_bits)     /* Enter Low Power Mode 2 */
#define LPM2_EXIT _BIC_SR_IRQ(LPM2_bits) /* Exit Low Power Mode 2 */
#define LPM3      _BIS_SR(LPM3_bits)     /* Enter Low Power Mode 3 */
#define LPM3_EXIT _BIC_SR_IRQ(LPM3_bits) /* Exit Low Power Mode 3 */
#define LPM4      _BIS_SR(LPM4_bits)     /* Enter Low Power Mode 4 */
#define LPM4_EXIT _BIC_SR_IRQ(LPM4_bits) /* Exit Low Power Mode 4 */
#endif /* End #defines for C */

/************************************************************
* PERIPHERAL FILE MAP
************************************************************/

/************************************************************
* SPECIAL FUNCTION REGISTER ADDRESSES + CONTROL BITS
************************************************************/

#define IE1_                  0x0000    /* Interrupt Enable 1 */
sfrb(IE1, IE1_);
#define U0IE                IE1       /* UART0 Interrupt Enable Register */
#define WDTIE               (0x01)
#define OFIE                (0x02)
#define NMIIE               (0x10)
#define ACCVIE              (0x20)
#define URXIE0              (0x40)
#define UTXIE0              (0x80)

#define IFG1_                 0x0002    /* Interrupt Flag 1 */
sfrb(IFG1, IFG1_);
#define U0IFG               IFG1      /* UART0 Interrupt Flag Register */
#define WDTIFG              (0x01)
#define OFIFG               (0x02)
#define NMIIFG              (0x10)
#define URXIFG0             (0x40)
#define UTXIFG0             (0x80)

#define ME1_                  0x0004    /* Module Enable 1 */
sfrb(ME1, ME1_);
#define U0ME                ME1       /* UART0 Module Enable Register */
#define URXE0               (0x40)
#define UTXE0               (0x80)
#define USPIE0              (0x40)

#define IE2_                  0x0001    /* Interrupt Enable 2 */
sfrb(IE2, IE2_);
#define U1IE                IE2       /* UART1 Interrupt Enable Register */
#define URXIE1              (0x10)
#define UTXIE1              (0x20)

#define IFG2_                 0x0003    /* Interrupt Flag 2 */
sfrb(IFG2, IFG2_);
#define U1IFG               IFG2      /* UART1 Interrupt Flag Register */
#define URXIFG1             (0x10)
#define UTXIFG1             (0x20)

#define ME2_                  0x0005    /* Module Enable 2 */
sfrb(ME2, ME2_);
#define U1ME                ME2       /* UART1 Module Enable Register */
#define URXE1               (0x10)
#define UTXE1               (0x20)
#define USPIE1              (0x10)

/************************************************************
* WATCHDOG TIMER
************************************************************/
#define __MSP430_HAS_WDT__            /* Definition to show that Module is available */

#define WDTCTL_               0x0120    /* Watchdog Timer Control */
sfrw(WDTCTL, WDTCTL_);
/* The bit names have been prefixed with "WDT" */
#define WDTIS0              (0x0001)
#define WDTIS1              (0x0002)
#define WDTSSEL             (0x0004)
#define WDTCNTCL            (0x0008)
#define WDTTMSEL            (0x0010)
#define WDTNMI              (0x0020)
#define WDTNMIES            (0x0040)
#define WDTHOLD             (0x0080)

#define WDTPW               (0x5A00)

/* WDT-interval times [1ms] coded with Bits 0-2 */
/* WDT is clocked by fSMCLK (assumed 1MHz) */
#define WDT_MDLY_32         (WDTPW+WDTTMSEL+WDTCNTCL)                         /* 32ms interval (default) */
#define WDT_MDLY_8          (WDTPW+WDTTMSEL+WDTCNTCL+WDTIS0)                  /* 8ms     " */
#define WDT_MDLY_0_5        (WDTPW+WDTTMSEL+WDTCNTCL+WDTIS1)                  /* 0.5ms   " */
#define WDT_MDLY_0_064      (WDTPW+WDTTMSEL+WDTCNTCL+WDTIS1+WDTIS0)           /* 0.064ms " */
/* WDT is clocked by fACLK (assumed 32KHz) */
#define WDT_ADLY_1000       (WDTPW+WDTTMSEL+WDTCNTCL+WDTSSEL)                 /* 1000ms  " */
#define WDT_ADLY_250        (WDTPW+WDTTMSEL+WDTCNTCL+WDTSSEL+WDTIS0)          /* 250ms   " */
#define WDT_ADLY_16         (WDTPW+WDTTMSEL+WDTCNTCL+WDTSSEL+WDTIS1)          /* 16ms    " */
#define WDT_ADLY_1_9        (WDTPW+WDTTMSEL+WDTCNTCL+WDTSSEL+WDTIS1+WDTIS0)   /* 1.9ms   " */
/* Watchdog mode -> reset after expired time */
/* WDT is clocked by fSMCLK (assumed 1MHz) */
#define WDT_MRST_32         (WDTPW+WDTCNTCL)                                  /* 32ms interval (default) */
#define WDT_MRST_8          (WDTPW+WDTCNTCL+WDTIS0)                           /* 8ms     " */
#define WDT_MRST_0_5        (WDTPW+WDTCNTCL+WDTIS1)                           /* 0.5ms   " */
#define WDT_MRST_0_064      (WDTPW+WDTCNTCL+WDTIS1+WDTIS0)                    /* 0.064ms " */
/* WDT is clocked by fACLK (assumed 32KHz) */
#define WDT_ARST_1000       (WDTPW+WDTCNTCL+WDTSSEL)                          /* 1000ms  " */
#define WDT_ARST_250        (WDTPW+WDTCNTCL+WDTSSEL+WDTIS0)                   /* 250ms   " */
#define WDT_ARST_16         (WDTPW+WDTCNTCL+WDTSSEL+WDTIS1)                   /* 16ms    " */
#define WDT_ARST_1_9        (WDTPW+WDTCNTCL+WDTSSEL+WDTIS1+WDTIS0)            /* 1.9ms   " */

/* INTERRUPT CONTROL */
/* These two bits are defined in the Special Function Registers */
/* #define WDTIE               0x01 */
/* #define WDTIFG              0x01 */

/************************************************************
* HARDWARE MULTIPLIER
************************************************************/
#define __MSP430_HAS_MPY__            /* Definition to show that Module is available */

#define MPY_                  0x0130    /* Multiply Unsigned/Operand 1 */
sfrw(MPY, MPY_);
#define MPYS_                 0x0132    /* Multiply Signed/Operand 1 */
sfrw(MPYS, MPYS_);
#define MAC_                  0x0134    /* Multiply Unsigned and Accumulate/Operand 1 */
sfrw(MAC, MAC_);
#define MACS_                 0x0136    /* Multiply Signed and Accumulate/Operand 1 */
sfrw(MACS, MACS_);
#define OP2_                  0x0138    /* Operand 2 */
sfrw(OP2, OP2_);
#define RESLO_                0x013A    /* Result Low Word */
sfrw(RESLO, RESLO_);
#define RESHI_                0x013C    /* Result High Word */
sfrw(RESHI, RESHI_);
#define SUMEXT_               0x013E    /* Sum Extend */
const_sfrw(SUMEXT, SUMEXT_);

/************************************************************
* DIGITAL I/O Port1/2
************************************************************/
#define __MSP430_HAS_PORT1__          /* Definition to show that Module is available */
#define __MSP430_HAS_PORT2__          /* Definition to show that Module is available */

#define P1IN_                 0x0020    /* Port 1 Input */
const_sfrb(P1IN, P1IN_);
#define P1OUT_                0x0021    /* Port 1 Output */
sfrb(P1OUT, P1OUT_);
#define P1DIR_                0x0022    /* Port 1 Direction */
sfrb(P1DIR, P1DIR_);
#define P1IFG_                0x0023    /* Port 1 Interrupt Flag */
sfrb(P1IFG, P1IFG_);
#define P1IES_                0x0024    /* Port 1 Interrupt Edge Select */
sfrb(P1IES, P1IES_);
#define P1IE_                 0x0025    /* Port 1 Interrupt Enable */
sfrb(P1IE, P1IE_);
#define P1SEL_                0x0026    /* Port 1 Selection */
sfrb(P1SEL, P1SEL_);

#define P2IN_                 0x0028    /* Port 2 Input */
const_sfrb(P2IN, P2IN_);
#define P2OUT_                0x0029    /* Port 2 Output */
sfrb(P2OUT, P2OUT_);
#define P2DIR_                0x002A    /* Port 2 Direction */
sfrb(P2DIR, P2DIR_);
#define P2IFG_                0x002B    /* Port 2 Interrupt Flag */
sfrb(P2IFG, P2IFG_);
#define P2IES_                0x002C    /* Port 2 Interrupt Edge Select */
sfrb(P2IES, P2IES_);
#define P2IE_                 0x002D    /* Port 2 Interrupt Enable */
sfrb(P2IE, P2IE_);
#define P2SEL_                0x002E    /* Port 2 Selection */
sfrb(P2SEL, P2SEL_);

/************************************************************
* DIGITAL I/O Port3/4
************************************************************/
#define __MSP430_HAS_PORT3__          /* Definition to show that Module is available */
#define __MSP430_HAS_PORT4__          /* Definition to show that Module is available */

#define P3IN_                 0x0018    /* Port 3 Input */
const_sfrb(P3IN, P3IN_);
#define P3OUT_                0x0019    /* Port 3 Output */
sfrb(P3OUT, P3OUT_);
#define P3DIR_                0x001A    /* Port 3 Direction */
sfrb(P3DIR, P3DIR_);
#define P3SEL_                0x001B    /* Port 3 Selection */
sfrb(P3SEL, P3SEL_);

#define P4IN_                 0x001C    /* Port 4 Input */
const_sfrb(P4IN, P4IN_);
#define P4OUT_                0x001D    /* Port 4 Output */
sfrb(P4OUT, P4OUT_);
#define P4DIR_                0x001E    /* Port 4 Direction */
sfrb(P4DIR, P4DIR_);
#define P4SEL_                0x001F    /* Port 4 Selection */
sfrb(P4SEL, P4SEL_);

/************************************************************
* DIGITAL I/O Port5/6
************************************************************/
#define __MSP430_HAS_PORT5__          /* Definition to show that Module is available */
#define __MSP430_HAS_PORT6__          /* Definition to show that Module is available */

#define P5IN_                 0x0030    /* Port 5 Input */
const_sfrb(P5IN, P5IN_);
#define P5OUT_                0x0031    /* Port 5 Output */
sfrb(P5OUT, P5OUT_);
#define P5DIR_                0x0032    /* Port 5 Direction */
sfrb(P5DIR, P5DIR_);
#define P5SEL_                0x0033    /* Port 5 Selection */
sfrb(P5SEL, P5SEL_);

#define P6IN_                 0x0034    /* Port 6 Input */
const_sfrb(P6IN, P6IN_);
#define P6OUT_                0x0035    /* Port 6 Output */
sfrb(P6OUT, P6OUT_);
#define P6DIR_                0x0036    /* Port 6 Direction */
sfrb(P6DIR, P6DIR_);
#define P6SEL_                0x0037    /* Port 6 Selection */
sfrb(P6SEL, P6SEL_);

/************************************************************
* USART
************************************************************/

/* UxCTL */
#define PENA                (0x80)        /* Parity enable */
#define PEV                 (0x40)        /* Parity 0:odd / 1:even */
#define SPB                 (0x20)        /* Stop Bits 0:one / 1: two */
#define CHAR                (0x10)        /* Data 0:7-bits / 1:8-bits */
#define LISTEN              (0x08)        /* Listen mode */
#define SYNC                (0x04)        /* UART / SPI mode */
#define MM                  (0x02)        /* Master Mode off/on */
#define SWRST               (0x01)        /* USART Software Reset */

/* UxTCTL */
#define CKPH                (0x80)        /* SPI: Clock Phase */
#define CKPL                (0x40)        /* Clock Polarity */
#define SSEL1               (0x20)        /* Clock Source Select 1 */
#define SSEL0               (0x10)        /* Clock Source Select 0 */
#define URXSE               (0x08)        /* Receive Start edge select */
#define TXWAKE              (0x04)        /* TX Wake up mode */
#define STC                 (0x02)        /* SPI: STC enable 0:on / 1:off */
#define TXEPT               (0x01)        /* TX Buffer empty */

/* UxRCTL */
#define FE                  (0x80)        /* Frame Error */
#define PE                  (0x40)        /* Parity Error */
#define OE                  (0x20)        /* Overrun Error */
#define BRK                 (0x10)        /* Break detected */
#define URXEIE              (0x08)        /* RX Error interrupt enable */
#define URXWIE              (0x04)        /* RX Wake up interrupt enable */
#define RXWAKE              (0x02)        /* RX Wake up detect */
#define RXERR               (0x01)        /* RX Error Error */

/************************************************************
* USART 0
************************************************************/
#define __MSP430_HAS_UART0__          /* Definition to show that Module is available */

#define U0CTL_                0x0070    /* USART 0 Control */
sfrb(U0CTL, U0CTL_);
#define U0TCTL_               0x0071    /* USART 0 Transmit Control */
sfrb(U0TCTL, U0TCTL_);
#define U0RCTL_               0x0072    /* USART 0 Receive Control */
sfrb(U0RCTL, U0RCTL_);
#define U0MCTL_               0x0073    /* USART 0 Modulation Control */
sfrb(U0MCTL, U0MCTL_);
#define U0BR0_                0x0074    /* USART 0 Baud Rate 0 */
sfrb(U0BR0, U0BR0_);
#define U0BR1_                0x0075    /* USART 0 Baud Rate 1 */
sfrb(U0BR1, U0BR1_);
#define U0RXBUF_              0x0076    /* USART 0 Receive Buffer */
const_sfrb(U0RXBUF, U0RXBUF_);
#define U0TXBUF_              0x0077    /* USART 0 Transmit Buffer */
sfrb(U0TXBUF, U0TXBUF_);

/* Alternate register names */

#define UCTL0               U0CTL     /* USART 0 Control */
#define UTCTL0              U0TCTL    /* USART 0 Transmit Control */
#define URCTL0              U0RCTL    /* USART 0 Receive Control */
#define UMCTL0              U0MCTL    /* USART 0 Modulation Control */
#define UBR00               U0BR0     /* USART 0 Baud Rate 0 */
#define UBR10               U0BR1     /* USART 0 Baud Rate 1 */
#define RXBUF0              U0RXBUF   /* USART 0 Receive Buffer */
#define TXBUF0              U0TXBUF   /* USART 0 Transmit Buffer */
#define UCTL0_              U0CTL_    /* USART 0 Control */
#define UTCTL0_             U0TCTL_   /* USART 0 Transmit Control */
#define URCTL0_             U0RCTL_   /* USART 0 Receive Control */
#define UMCTL0_             U0MCTL_   /* USART 0 Modulation Control */
#define UBR00_              U0BR0_    /* USART 0 Baud Rate 0 */
#define UBR10_              U0BR1_    /* USART 0 Baud Rate 1 */
#define RXBUF0_             U0RXBUF_  /* USART 0 Receive Buffer */
#define TXBUF0_             U0TXBUF_  /* USART 0 Transmit Buffer */
#define UCTL_0              U0CTL     /* USART 0 Control */
#define UTCTL_0             U0TCTL    /* USART 0 Transmit Control */
#define URCTL_0             U0RCTL    /* USART 0 Receive Control */
#define UMCTL_0             U0MCTL    /* USART 0 Modulation Control */
#define UBR0_0              U0BR0     /* USART 0 Baud Rate 0 */
#define UBR1_0              U0BR1     /* USART 0 Baud Rate 1 */
#define RXBUF_0             U0RXBUF   /* USART 0 Receive Buffer */
#define TXBUF_0             U0TXBUF   /* USART 0 Transmit Buffer */
#define UCTL_0_             U0CTL_    /* USART 0 Control */
#define UTCTL_0_            U0TCTL_   /* USART 0 Transmit Control */
#define URCTL_0_            U0RCTL_   /* USART 0 Receive Control */
#define UMCTL_0_            U0MCTL_   /* USART 0 Modulation Control */
#define UBR0_0_             U0BR0_    /* USART 0 Baud Rate 0 */
#define UBR1_0_             U0BR1_    /* USART 0 Baud Rate 1 */
#define RXBUF_0_            U0RXBUF_  /* USART 0 Receive Buffer */
#define TXBUF_0_            U0TXBUF_  /* USART 0 Transmit Buffer */

/************************************************************
* USART 1
************************************************************/
#define __MSP430_HAS_UART1__          /* Definition to show that Module is available */

#define U1CTL_                0x0078    /* USART 1 Control */
sfrb(U1CTL, U1CTL_);
#define U1TCTL_               0x0079    /* USART 1 Transmit Control */
sfrb(U1TCTL, U1TCTL_);
#define U1RCTL_               0x007A    /* USART 1 Receive Control */
sfrb(U1RCTL, U1RCTL_);
#define U1MCTL_               0x007B    /* USART 1 Modulation Control */
sfrb(U1MCTL, U1MCTL_);
#define U1BR0_                0x007C    /* USART 1 Baud Rate 0 */
sfrb(U1BR0, U1BR0_);
#define U1BR1_                0x007D    /* USART 1 Baud Rate 1 */
sfrb(U1BR1, U1BR1_);
#define U1RXBUF_              0x007E    /* USART 1 Receive Buffer */
const_sfrb(U1RXBUF, U1RXBUF_);
#define U1TXBUF_              0x007F    /* USART 1 Transmit Buffer */
sfrb(U1TXBUF, U1TXBUF_);

/* Alternate register names */

#define UCTL1               U1CTL     /* USART 1 Control */
#define UTCTL1              U1TCTL    /* USART 1 Transmit Control */
#define URCTL1              U1RCTL    /* USART 1 Receive Control */
#define UMCTL1              U1MCTL    /* USART 1 Modulation Control */
#define UBR01               U1BR0     /* USART 1 Baud Rate 0 */
#define UBR11               U1BR1     /* USART 1 Baud Rate 1 */
#define RXBUF1              U1RXBUF   /* USART 1 Receive Buffer */
#define TXBUF1              U1TXBUF   /* USART 1 Transmit Buffer */
#define UCTL1_              U1CTL_    /* USART 1 Control */
#define UTCTL1_             U1TCTL_   /* USART 1 Transmit Control */
#define URCTL1_             U1RCTL_   /* USART 1 Receive Control */
#define UMCTL1_             U1MCTL_   /* USART 1 Modulation Control */
#define UBR01_              U1BR0_    /* USART 1 Baud Rate 0 */
#define UBR11_              U1BR1_    /* USART 1 Baud Rate 1 */
#define RXBUF1_             U1RXBUF_  /* USART 1 Receive Buffer */
#define TXBUF1_             U1TXBUF_  /* USART 1 Transmit Buffer */
#define UCTL_1              U1CTL     /* USART 1 Control */
#define UTCTL_1             U1TCTL    /* USART 1 Transmit Control */
#define URCTL_1             U1RCTL    /* USART 1 Receive Control */
#define UMCTL_1             U1MCTL    /* USART 1 Modulation Control */
#define UBR0_1              U1BR0     /* USART 1 Baud Rate 0 */
#define UBR1_1              U1BR1     /* USART 1 Baud Rate 1 */
#define RXBUF_1             U1RXBUF   /* USART 1 Receive Buffer */
#define TXBUF_1             U1TXBUF   /* USART 1 Transmit Buffer */
#define UCTL_1_             U1CTL_    /* USART 1 Control */
#define UTCTL_1_            U1TCTL_   /* USART 1 Transmit Control */
#define URCTL_1_            U1RCTL_   /* USART 1 Receive Control */
#define UMCTL_1_            U1MCTL_   /* USART 1 Modulation Control */
#define UBR0_1_             U1BR0_    /* USART 1 Baud Rate 0 */
#define UBR1_1_             U1BR1_    /* USART 1 Baud Rate 1 */
#define RXBUF_1_            U1RXBUF_  /* USART 1 Receive Buffer */
#define TXBUF_1_            U1TXBUF_  /* USART 1 Transmit Buffer */

/************************************************************
* USART0  I2C
************************************************************/
#define __MSP430_HAS_I2C__              /* Definition to show that Module is available */

#define I2CIE_                0x0050    /* I2C Interrupt Enable */
sfrb(I2CIE, I2CIE_);
#define ALIE                (0x01)      /* Arbitration lost */
#define NACKIE              (0x02)      /* No acknowledge */
#define OAIE                (0x04)      /* Own address */
#define ARDYIE              (0x08)      /* Access ready (opeation complete) */
#define RXRDYIE             (0x10)      /* Receive ready (data received) */
#define TXRDYIE             (0x20)      /* Transmit ready (transmit register empty) */
#define GCIE                (0x40)      /* General call */
#define STTIE               (0x80)      /* Start condition */

#define I2CIFG_               0x0051    /* I2C Interrupt Flag */
sfrb(I2CIFG, I2CIFG_);
#define ALIFG               (0x01)      /* Arbitration lost */
#define NACKIFG             (0x02)      /* No acknowledge */
#define OAIFG               (0x04)      /* Own address */
#define ARDYIFG             (0x08)      /* Access ready (opeation complete) */
#define RXRDYIFG            (0x10)      /* Receive ready (data received) */
#define TXRDYIFG            (0x20)      /* Transmit ready (transmit register empty) */
#define GCIFG               (0x40)      /* General call */
#define STTIFG              (0x80)      /* Start condition */

#define I2CNDAT_              0x0052    /* I2C Data Count */
sfrb(I2CNDAT, I2CNDAT_);

/* USART 0 Control */
#define I2CEN               (0x01)      /* I2C enable */
#define MST                 (0x02)      /* I2C master */
#define XA                  (0x10)      /* I2C extended addressing */
#define I2C                 (0x20)      /* USART I2C */
#define TXDMAEN             (0x40)      /* Transmit DMA enable */
#define RXDMAEN             (0x80)      /* Receive DMA enable */

#define I2CTCTL_              0x0071    /* I2C Transfer Control */
sfrb(I2CTCTL, I2CTCTL_);
#define I2CSTT              (0x01)      /* Start bit */
#define I2CSTP              (0x02)      /* Stop bit */
#define I2CSTB              (0x04)      /* Start byte mode */
#define I2CTRX              (0x08)      /* Transmit */
#define I2CSSEL0            (0x10)      /* Clock select bit 0 */
#define I2CSSEL1            (0x20)      /* Clock select bit 1 */
#define I2CRM               (0x40)      /* Repeat mode */
#define I2CWORD             (0x80)      /* Word data mode */

#define I2CSSEL_0           (0x0000)    /* I2C clock select 0: UCLK */
#define I2CSSEL_1           (0x0010)    /* I2C clock select 1: ACLK */
#define I2CSSEL_2           (0x0020)    /* I2C clock select 2: SMCLK */
#define I2CSSEL_3           (0x0030)    /* I2C clock select 3: SMCLK */

#define I2CMM_0             (0x00)      /* Master mode 0 */
#define I2CMM_1             (I2CSTT)    /* Master mode 1 */
#define I2CMM_2             (I2CSTP+I2CSTT) /* Master mode 2 */
#define I2CMM_3             (I2CRM+I2CSTT)  /* Master mode 3 */
#define I2CMM_4             (I2CSTP)    /* Master mode 4 */

#define I2CDCTL_              0x0072    /* I2C Data Control */
sfrb(I2CDCTL, I2CDCTL_);
#define I2CBB               (0x01)      /* Bus busy */
#define I2CRXOVR            (0x02)      /* Receiver overrun */
#define I2CTXUDF            (0x04)      /* Transmit underflow */
#define I2CSBD              (0x08)      /* Received byte */
#define I2CSCLLOW           (0x10)      /* SCL being held low */
#define I2CBUSY             (0x20)      /* I2C Busy Flag */

#define I2CPSC_               0x0073    /* I2C Pre-scaler */
sfrb(I2CPSC, I2CPSC_);
#define I2CSCLH_              0x0074    /* I2C SCL High */
sfrb(I2CSCLH, I2CSCLH_);
#define I2CSCLL_              0x0075    /* I2C SCL Low */
sfrb(I2CSCLL, I2CSCLL_);
#define I2CDRB_               0x0076    /* I2C Data for Byte access */
sfrb(I2CDRB, I2CDRB_);
#define I2CDRW_               0x0076    /* I2C Data for Word access */
sfrw(I2CDRW, I2CDRW_);

#define I2COA_                0x0118    /* I2C Own Address */
sfrw(I2COA, I2COA_);
#define I2CSA_                0x011A    /* I2C Slave Address */
sfrw(I2CSA, I2CSA_);

#define I2CIV_                0x011C    /* I2C Interrupt Vector */
const_sfrw(I2CIV, I2CIV_);
#define I2CIV_NONE          (0x0000)    /* I2C interrupt vector: No interrupt pending */
#define I2CIV_AL            (0x0002)    /* I2C interrupt vector: Arbitration lost (ALIFG) */
#define I2CIV_NACK          (0x0004)    /* I2C interrupt vector: No acknowledge (NACKIFG) */
#define I2CIV_OA            (0x0006)    /* I2C interrupt vector: Own address (OAIFG) */
#define I2CIV_ARDY          (0x0008)    /* I2C interrupt vector: Access ready (ARDYIFG) */
#define I2CIV_RXRDY         (0x000A)    /* I2C interrupt vector: Receive ready (RXRDYIFG) */
#define I2CIV_TXRDY         (0x000C)    /* I2C interrupt vector: Transmit ready (TXRDYIFG) */
#define I2CIV_GC            (0x000E)    /* I2C interrupt vector: General call (GCIFG) */
#define I2CIV_STT           (0x0010)    /* I2C interrupt vector: Start condition (STTIFG) */

/************************************************************
* Timer A3
************************************************************/
#define __MSP430_HAS_TA3__            /* Definition to show that Module is available */

#define TAIV_                 0x012E    /* Timer A Interrupt Vector Word */
const_sfrw(TAIV, TAIV_);
#define TACTL_                0x0160    /* Timer A Control */
sfrw(TACTL, TACTL_);
#define TACCTL0_              0x0162    /* Timer A Capture/Compare Control 0 */
sfrw(TACCTL0, TACCTL0_);
#define TACCTL1_              0x0164    /* Timer A Capture/Compare Control 1 */
sfrw(TACCTL1, TACCTL1_);
#define TACCTL2_              0x0166    /* Timer A Capture/Compare Control 2 */
sfrw(TACCTL2, TACCTL2_);
#define TAR_                  0x0170    /* Timer A */
sfrw(TAR, TAR_);
#define TACCR0_               0x0172    /* Timer A Capture/Compare 0 */
sfrw(TACCR0, TACCR0_);
#define TACCR1_               0x0174    /* Timer A Capture/Compare 1 */
sfrw(TACCR1, TACCR1_);
#define TACCR2_               0x0176    /* Timer A Capture/Compare 2 */
sfrw(TACCR2, TACCR2_);

/* Alternate register names */
#define CCTL0               TACCTL0   /* Timer A Capture/Compare Control 0 */
#define CCTL1               TACCTL1   /* Timer A Capture/Compare Control 1 */
#define CCTL2               TACCTL2   /* Timer A Capture/Compare Control 2 */
#define CCR0                TACCR0    /* Timer A Capture/Compare 0 */
#define CCR1                TACCR1    /* Timer A Capture/Compare 1 */
#define CCR2                TACCR2    /* Timer A Capture/Compare 2 */
#define CCTL0_              TACCTL0_  /* Timer A Capture/Compare Control 0 */
#define CCTL1_              TACCTL1_  /* Timer A Capture/Compare Control 1 */
#define CCTL2_              TACCTL2_  /* Timer A Capture/Compare Control 2 */
#define CCR0_               TACCR0_   /* Timer A Capture/Compare 0 */
#define CCR1_               TACCR1_   /* Timer A Capture/Compare 1 */
#define CCR2_               TACCR2_   /* Timer A Capture/Compare 2 */

#define TASSEL1             (0x0200)  /* Timer A clock source select 0 */
#define TASSEL0             (0x0100)  /* Timer A clock source select 1 */
#define ID1                 (0x0080)  /* Timer A clock input divider 1 */
#define ID0                 (0x0040)  /* Timer A clock input divider 0 */
#define MC1                 (0x0020)  /* Timer A mode control 1 */
#define MC0                 (0x0010)  /* Timer A mode control 0 */
#define TACLR               (0x0004)  /* Timer A counter clear */
#define TAIE                (0x0002)  /* Timer A counter interrupt enable */
#define TAIFG               (0x0001)  /* Timer A counter interrupt flag */

#define MC_0                (0x0000)  /* Timer A mode control: 0 - Stop */
#define MC_1                (0x0010)  /* Timer A mode control: 1 - Up to CCR0 */
#define MC_2                (0x0020)  /* Timer A mode control: 2 - Continous up */
#define MC_3                (0x0030)  /* Timer A mode control: 3 - Up/Down */
#define ID_0                (0x0000)  /* Timer A input divider: 0 - /1 */
#define ID_1                (0x0040)  /* Timer A input divider: 1 - /2 */
#define ID_2                (0x0080)  /* Timer A input divider: 2 - /4 */
#define ID_3                (0x00C0)  /* Timer A input divider: 3 - /8 */
#define TASSEL_0            (0x0000) /* Timer A clock source select: 0 - TACLK */
#define TASSEL_1            (0x0100) /* Timer A clock source select: 1 - ACLK  */
#define TASSEL_2            (0x0200) /* Timer A clock source select: 2 - SMCLK */
#define TASSEL_3            (0x0300) /* Timer A clock source select: 3 - INCLK */

#define CM1                 (0x8000)  /* Capture mode 1 */
#define CM0                 (0x4000)  /* Capture mode 0 */
#define CCIS1               (0x2000)  /* Capture input select 1 */
#define CCIS0               (0x1000)  /* Capture input select 0 */
#define SCS                 (0x0800)  /* Capture sychronize */
#define SCCI                (0x0400)  /* Latched capture signal (read) */
#define CAP                 (0x0100)  /* Capture mode: 1 /Compare mode : 0 */
#define OUTMOD2             (0x0080)  /* Output mode 2 */
#define OUTMOD1             (0x0040)  /* Output mode 1 */
#define OUTMOD0             (0x0020)  /* Output mode 0 */
#define CCIE                (0x0010)  /* Capture/compare interrupt enable */
#define CCI                 (0x0008)  /* Capture input signal (read) */
#define OUT                 (0x0004)  /* PWM Output signal if output mode 0 */
#define COV                 (0x0002)  /* Capture/compare overflow flag */
#define CCIFG               (0x0001)  /* Capture/compare interrupt flag */

#define OUTMOD_0            (0x0000)  /* PWM output mode: 0 - output only */
#define OUTMOD_1            (0x0020)  /* PWM output mode: 1 - set */
#define OUTMOD_2            (0x0040)  /* PWM output mode: 2 - PWM toggle/reset */
#define OUTMOD_3            (0x0060)  /* PWM output mode: 3 - PWM set/reset */
#define OUTMOD_4            (0x0080)  /* PWM output mode: 4 - toggle */
#define OUTMOD_5            (0x00A0)  /* PWM output mode: 5 - Reset */
#define OUTMOD_6            (0x00C0)  /* PWM output mode: 6 - PWM toggle/set */
#define OUTMOD_7            (0x00E0)  /* PWM output mode: 7 - PWM reset/set */
#define CCIS_0              (0x0000) /* Capture input select: 0 - CCIxA */
#define CCIS_1              (0x1000) /* Capture input select: 1 - CCIxB */
#define CCIS_2              (0x2000) /* Capture input select: 2 - GND */
#define CCIS_3              (0x3000) /* Capture input select: 3 - Vcc */
#define CM_0                (0x0000) /* Capture mode: 0 - disabled */
#define CM_1                (0x4000) /* Capture mode: 1 - pos. edge */
#define CM_2                (0x8000) /* Capture mode: 1 - neg. edge */
#define CM_3                (0xC000) /* Capture mode: 1 - both edges */

/* TA3IV Definitions */
#define TAIV_NONE           (0x0000)    /* No Interrupt pending */
#define TAIV_TACCR1         (0x0002)    /* TACCR1_CCIFG */
#define TAIV_TACCR2         (0x0004)    /* TACCR2_CCIFG */
#define TAIV_6              (0x0006)    /* Reserved */
#define TAIV_8              (0x0008)    /* Reserved */
#define TAIV_TAIFG          (0x000A)    /* TAIFG */

/************************************************************
* Timer B7
************************************************************/
#define __MSP430_HAS_TB7__            /* Definition to show that Module is available */

#define TBIV_                 0x011E    /* Timer B Interrupt Vector Word */
const_sfrw(TBIV, TBIV_);
#define TBCTL_                0x0180    /* Timer B Control */
sfrw(TBCTL, TBCTL_);
#define TBCCTL0_              0x0182    /* Timer B Capture/Compare Control 0 */
sfrw(TBCCTL0, TBCCTL0_);
#define TBCCTL1_              0x0184    /* Timer B Capture/Compare Control 1 */
sfrw(TBCCTL1, TBCCTL1_);
#define TBCCTL2_              0x0186    /* Timer B Capture/Compare Control 2 */
sfrw(TBCCTL2, TBCCTL2_);
#define TBCCTL3_              0x0188    /* Timer B Capture/Compare Control 3 */
sfrw(TBCCTL3, TBCCTL3_);
#define TBCCTL4_              0x018A    /* Timer B Capture/Compare Control 4 */
sfrw(TBCCTL4, TBCCTL4_);
#define TBCCTL5_              0x018C    /* Timer B Capture/Compare Control 5 */
sfrw(TBCCTL5, TBCCTL5_);
#define TBCCTL6_              0x018E    /* Timer B Capture/Compare Control 6 */
sfrw(TBCCTL6, TBCCTL6_);
#define TBR_                  0x0190    /* Timer B */
sfrw(TBR, TBR_);
#define TBCCR0_               0x0192    /* Timer B Capture/Compare 0 */
sfrw(TBCCR0, TBCCR0_);
#define TBCCR1_               0x0194    /* Timer B Capture/Compare 1 */
sfrw(TBCCR1, TBCCR1_);
#define TBCCR2_               0x0196    /* Timer B Capture/Compare 2 */
sfrw(TBCCR2, TBCCR2_);
#define TBCCR3_               0x0198    /* Timer B Capture/Compare 3 */
sfrw(TBCCR3, TBCCR3_);
#define TBCCR4_               0x019A    /* Timer B Capture/Compare 4 */
sfrw(TBCCR4, TBCCR4_);
#define TBCCR5_               0x019C    /* Timer B Capture/Compare 5 */
sfrw(TBCCR5, TBCCR5_);
#define TBCCR6_               0x019E    /* Timer B Capture/Compare 6 */
sfrw(TBCCR6, TBCCR6_);

#define TBCLGRP1            (0x4000)  /* Timer B Compare latch load group 1 */
#define TBCLGRP0            (0x2000)  /* Timer B Compare latch load group 0 */
#define CNTL1               (0x1000)  /* Counter lenght 1 */
#define CNTL0               (0x0800)  /* Counter lenght 0 */
#define TBSSEL1             (0x0200)  /* Clock source 1 */
#define TBSSEL0             (0x0100)  /* Clock source 0 */
#define TBCLR               (0x0004)  /* Timer B counter clear */
#define TBIE                (0x0002)  /* Timer B interrupt enable */
#define TBIFG               (0x0001)  /* Timer B interrupt flag */

#define SHR1                (0x4000)  /* Timer B Compare latch load group 1 */
#define SHR0                (0x2000)  /* Timer B Compare latch load group 0 */

#define TBSSEL_0            (0x0000)  /* Clock Source: TBCLK */
#define TBSSEL_1            (0x0100)  /* Clock Source: ACLK  */
#define TBSSEL_2            (0x0200)  /* Clock Source: SMCLK */
#define TBSSEL_3            (0x0300)  /* Clock Source: INCLK */
#define CNTL_0              (0x0000)  /* Counter lenght: 16 bit */
#define CNTL_1              (0x0800)  /* Counter lenght: 12 bit */
#define CNTL_2              (0x1000)  /* Counter lenght: 10 bit */
#define CNTL_3              (0x1800)  /* Counter lenght:  8 bit */
#define SHR_0               (0x0000)  /* Timer B Group: 0 - individually */
#define SHR_1               (0x2000)  /* Timer B Group: 1 - 3 groups (1-2, 3-4, 5-6) */
#define SHR_2               (0x4000)  /* Timer B Group: 2 - 2 groups (1-3, 4-6)*/
#define SHR_3               (0x6000)  /* Timer B Group: 3 - 1 group (all) */
#define TBCLGRP_0           (0x0000)  /* Timer B Group: 0 - individually */
#define TBCLGRP_1           (0x2000)  /* Timer B Group: 1 - 3 groups (1-2, 3-4, 5-6) */
#define TBCLGRP_2           (0x4000)  /* Timer B Group: 2 - 2 groups (1-3, 4-6)*/
#define TBCLGRP_3           (0x6000)  /* Timer B Group: 3 - 1 group (all) */

/* Additional Timer B Control Register bits are defined in Timer A */
#define CLLD1               (0x0400)  /* Compare latch load source 1 */
#define CLLD0               (0x0200)  /* Compare latch load source 0 */

#define SLSHR1              (0x0400)  /* Compare latch load source 1 */
#define SLSHR0              (0x0200)  /* Compare latch load source 0 */

#define SLSHR_0             (0x0000)  /* Compare latch load sourec : 0 - immediate */
#define SLSHR_1             (0x0200)  /* Compare latch load sourec : 1 - TBR counts to 0 */
#define SLSHR_2             (0x0400)  /* Compare latch load sourec : 2 - up/down */
#define SLSHR_3             (0x0600)  /* Compare latch load sourec : 3 - TBR counts to TBCTL0 */

#define CLLD_0              (0x0000)  /* Compare latch load sourec : 0 - immediate */
#define CLLD_1              (0x0200)  /* Compare latch load sourec : 1 - TBR counts to 0 */
#define CLLD_2              (0x0400)  /* Compare latch load sourec : 2 - up/down */
#define CLLD_3              (0x0600)  /* Compare latch load sourec : 3 - TBR counts to TBCTL0 */

/* TB7IV Definitions */
#define TBIV_NONE           (0x0000)    /* No Interrupt pending */
#define TBIV_TBCCR1         (0x0002)    /* TBCCR1_CCIFG */
#define TBIV_TBCCR2         (0x0004)    /* TBCCR2_CCIFG */
#define TBIV_TBCCR3         (0x0006)    /* TBCCR3_CCIFG */
#define TBIV_TBCCR4         (0x0008)    /* TBCCR4_CCIFG */
#define TBIV_TBCCR5         (0x000A)    /* TBCCR3_CCIFG */
#define TBIV_TBCCR6         (0x000C)    /* TBCCR4_CCIFG */
#define TBIV_TBIFG          (0x000E)    /* TBIFG */

/************************************************************
* Basic Clock Module
************************************************************/
#define __MSP430_HAS_BASIC_CLOCK__    /* Definition to show that Module is available */

#define DCOCTL_               0x0056    /* DCO Clock Frequency Control */
sfrb(DCOCTL, DCOCTL_);
#define BCSCTL1_              0x0057    /* Basic Clock System Control 1 */
sfrb(BCSCTL1, BCSCTL1_);
#define BCSCTL2_              0x0058    /* Basic Clock System Control 2 */
sfrb(BCSCTL2, BCSCTL2_);

#define MOD0                (0x01)   /* Modulation Bit 0 */
#define MOD1                (0x02)   /* Modulation Bit 1 */
#define MOD2                (0x04)   /* Modulation Bit 2 */
#define MOD3                (0x08)   /* Modulation Bit 3 */
#define MOD4                (0x10)   /* Modulation Bit 4 */
#define DCO0                (0x20)   /* DCO Select Bit 0 */
#define DCO1                (0x40)   /* DCO Select Bit 1 */
#define DCO2                (0x80)   /* DCO Select Bit 2 */

#define RSEL0               (0x01)   /* Range Select Bit 0 */
#define RSEL1               (0x02)   /* Range Select Bit 1 */
#define RSEL2               (0x04)   /* Range Select Bit 2 */
#define XT5V                (0x08)   /* XT5V should always be reset */
#define DIVA0               (0x10)   /* ACLK Divider 0 */
#define DIVA1               (0x20)   /* ACLK Divider 1 */
#define XTS                 (0x40)   /* LFXTCLK 0:Low Freq. / 1: High Freq. */
#define XT2OFF              (0x80)   /* Enable XT2CLK */

#define DIVA_0              (0x00)   /* ACLK Divider 0: /1 */
#define DIVA_1              (0x10)   /* ACLK Divider 1: /2 */
#define DIVA_2              (0x20)   /* ACLK Divider 2: /4 */
#define DIVA_3              (0x30)   /* ACLK Divider 3: /8 */

#define DCOR                (0x01)   /* Enable External Resistor : 1 */
#define DIVS0               (0x02)   /* SMCLK Divider 0 */
#define DIVS1               (0x04)   /* SMCLK Divider 1 */
#define SELS                (0x08)   /* SMCLK Source Select 0:DCOCLK / 1:XT2CLK/LFXTCLK */
#define DIVM0               (0x10)   /* MCLK Divider 0 */
#define DIVM1               (0x20)   /* MCLK Divider 1 */
#define SELM0               (0x40)   /* MCLK Source Select 0 */
#define SELM1               (0x80)   /* MCLK Source Select 1 */

#define DIVS_0              (0x00)   /* SMCLK Divider 0: /1 */
#define DIVS_1              (0x02)   /* SMCLK Divider 1: /2 */
#define DIVS_2              (0x04)   /* SMCLK Divider 2: /4 */
#define DIVS_3              (0x06)   /* SMCLK Divider 3: /8 */

#define DIVM_0              (0x00)   /* MCLK Divider 0: /1 */
#define DIVM_1              (0x10)   /* MCLK Divider 1: /2 */
#define DIVM_2              (0x20)   /* MCLK Divider 2: /4 */
#define DIVM_3              (0x30)   /* MCLK Divider 3: /8 */

#define SELM_0              (0x00)   /* MCLK Source Select 0: DCOCLK */
#define SELM_1              (0x40)   /* MCLK Source Select 1: DCOCLK */
#define SELM_2              (0x80)   /* MCLK Source Select 2: XT2CLK/LFXTCLK */
#define SELM_3              (0xC0)   /* MCLK Source Select 3: LFXTCLK */

/************************************************************
* Brown-Out, Supply Voltage Supervision (SVS)
************************************************************/
#define __MSP430_HAS_SVS__            /* Definition to show that Module is available */

#define SVSCTL_               0x0055    /* SVS Control */
sfrb(SVSCTL, SVSCTL_);
#define SVSFG               (0x01)    /* SVS Flag */
#define SVSOP               (0x02)    /* SVS output (read only) */
#define SVSON               (0x04)    /* Switches the SVS on/off */
#define PORON               (0x08)    /* Enable POR Generation if Low Voltage */
#define VLD0                (0x10)
#define VLD1                (0x20)
#define VLD2                (0x40)
#define VLD3                (0x80)

#define VLDON               (0x10)
#define VLDOFF              (0x00)
#define VLD_1_8V            (0x10)

/*************************************************************
* Flash Memory
*************************************************************/
#define __MSP430_HAS_FLASH__          /* Definition to show that Module is available */

#define FCTL1_                0x0128    /* FLASH Control 1 */
sfrw(FCTL1, FCTL1_);
#define FCTL2_                0x012A    /* FLASH Control 2 */
sfrw(FCTL2, FCTL2_);
#define FCTL3_                0x012C    /* FLASH Control 3 */
sfrw(FCTL3, FCTL3_);

#define FRKEY               (0x9600)  /* Flash key returned by read */
#define FWKEY               (0xA500)  /* Flash key for write */
#define FXKEY               (0x3300)  /* for use with XOR instruction */

#define ERASE               (0x0002)  /* Enable bit for Flash segment erase */
#define MERAS               (0x0004)  /* Enable bit for Flash mass erase */
#define WRT                 (0x0040)  /* Enable bit for Flash write */
#define BLKWRT              (0x0080)  /* Enable bit for Flash segment write */
#define SEGWRT              (0x0080)  /* old definition */ /* Enable bit for Flash segment write */

#define FN0                 (0x0001)  /* Divide Flash clock by 1 to 64 using FN0 to FN5 according to: */
#define FN1                 (0x0002)  /*  32*FN5 + 16*FN4 + 8*FN3 + 4*FN2 + 2*FN1 + FN0 + 1 */
#ifndef FN2
#define FN2                 (0x0004)
#endif
#ifndef FN3
#define FN3                 (0x0008)
#endif
#ifndef FN4
#define FN4                 (0x0010)
#endif
#define FN5                 (0x0020)
#define FSSEL0              (0x0040)  /* Flash clock select 0 */        /* to distinguish from USART SSELx */
#define FSSEL1              (0x0080)  /* Flash clock select 1 */

#define FSSEL_0             (0x0000)  /* Flash clock select: 0 - ACLK */
#define FSSEL_1             (0x0040)  /* Flash clock select: 1 - MCLK */
#define FSSEL_2             (0x0080)  /* Flash clock select: 2 - SMCLK */
#define FSSEL_3             (0x00C0)  /* Flash clock select: 3 - SMCLK */

#define BUSY                (0x0001)  /* Flash busy: 1 */
#define KEYV                (0x0002)  /* Flash Key violation flag */
#define ACCVIFG             (0x0004)  /* Flash Access violation flag */
#define WAIT                (0x0008)  /* Wait flag for segment write */
#define LOCK                (0x0010)  /* Lock bit: 1 - Flash is locked (read only) */
#define EMEX                (0x0020)  /* Flash Emergency Exit */

/************************************************************
* Comparator A
************************************************************/
#define __MSP430_HAS_COMPA__          /* Definition to show that Module is available */

#define CACTL1_               0x0059    /* Comparator A Control 1 */
sfrb(CACTL1, CACTL1_);
#define CACTL2_               0x005A    /* Comparator A Control 2 */
sfrb(CACTL2, CACTL2_);
#define CAPD_                 0x005B    /* Comparator A Port Disable */
sfrb(CAPD, CAPD_);

#define CAIFG               (0x01)    /* Comp. A Interrupt Flag */
#define CAIE                (0x02)    /* Comp. A Interrupt Enable */
#define CAIES               (0x04)    /* Comp. A Int. Edge Select: 0:rising / 1:falling */
#define CAON                (0x08)    /* Comp. A enable */
#define CAREF0              (0x10)    /* Comp. A Internal Reference Select 0 */
#define CAREF1              (0x20)    /* Comp. A Internal Reference Select 1 */
#define CARSEL              (0x40)    /* Comp. A Internal Reference Enable */
#define CAEX                (0x80)    /* Comp. A Exchange Inputs */

#define CAREF_0             (0x00)    /* Comp. A Int. Ref. Select 0 : Off */
#define CAREF_1             (0x10)    /* Comp. A Int. Ref. Select 1 : 0.25*Vcc */
#define CAREF_2             (0x20)    /* Comp. A Int. Ref. Select 2 : 0.5*Vcc */
#define CAREF_3             (0x30)    /* Comp. A Int. Ref. Select 3 : Vt*/

#define CAOUT               (0x01)    /* Comp. A Output */
#define CAF                 (0x02)    /* Comp. A Enable Output Filter */
#define P2CA0               (0x04)    /* Comp. A Connect External Signal to CA0 : 1 */
#define P2CA1               (0x08)    /* Comp. A Connect External Signal to CA1 : 1 */
#define CACTL24             (0x10)
#define CACTL25             (0x20)
#define CACTL26             (0x40)
#define CACTL27             (0x80)

#define CAPD0               (0x01)    /* Comp. A Disable Input Buffer of Port Register .0 */
#define CAPD1               (0x02)    /* Comp. A Disable Input Buffer of Port Register .1 */
#define CAPD2               (0x04)    /* Comp. A Disable Input Buffer of Port Register .2 */
#define CAPD3               (0x08)    /* Comp. A Disable Input Buffer of Port Register .3 */
#define CAPD4               (0x10)    /* Comp. A Disable Input Buffer of Port Register .4 */
#define CAPD5               (0x20)    /* Comp. A Disable Input Buffer of Port Register .5 */
#define CAPD6               (0x40)    /* Comp. A Disable Input Buffer of Port Register .6 */
#define CAPD7               (0x80)    /* Comp. A Disable Input Buffer of Port Register .7 */

/************************************************************
* ADC12
************************************************************/
#define __MSP430_HAS_ADC12__          /* Definition to show that Module is available */

#define ADC12CTL0_            0x01A0    /* ADC12 Control 0 */
sfrw(ADC12CTL0, ADC12CTL0_);
#define ADC12CTL1_            0x01A2    /* ADC12 Control 1 */
sfrw(ADC12CTL1, ADC12CTL1_);
#define ADC12IFG_             0x01A4    /* ADC12 Interrupt Flag */
sfrw(ADC12IFG, ADC12IFG_);
#define ADC12IE_              0x01A6    /* ADC12 Interrupt Enable */
sfrw(ADC12IE, ADC12IE_);
#define ADC12IV_              0x01A8    /* ADC12 Interrupt Vector Word */
sfrw(ADC12IV, ADC12IV_);

#define ADC12MEM_           (0x0140)  /* ADC12 Conversion Memory */
#ifndef __STDC__
#define ADC12MEM            (ADC12MEM_) /* ADC12 Conversion Memory (for assembler) */
#else
#define ADC12MEM            ((volatile int*) ADC12MEM_) /* ADC12 Conversion Memory (for C) */
#endif
#define ADC12MEM0_            0x0140    /* ADC12 Conversion Memory 0 */
sfrw(ADC12MEM0, ADC12MEM0_);
#define ADC12MEM1_            0x0142    /* ADC12 Conversion Memory 1 */
sfrw(ADC12MEM1, ADC12MEM1_);
#define ADC12MEM2_            0x0144    /* ADC12 Conversion Memory 2 */
sfrw(ADC12MEM2, ADC12MEM2_);
#define ADC12MEM3_            0x0146    /* ADC12 Conversion Memory 3 */
sfrw(ADC12MEM3, ADC12MEM3_);
#define ADC12MEM4_            0x0148    /* ADC12 Conversion Memory 4 */
sfrw(ADC12MEM4, ADC12MEM4_);
#define ADC12MEM5_            0x014A    /* ADC12 Conversion Memory 5 */
sfrw(ADC12MEM5, ADC12MEM5_);
#define ADC12MEM6_            0x014C    /* ADC12 Conversion Memory 6 */
sfrw(ADC12MEM6, ADC12MEM6_);
#define ADC12MEM7_            0x014E    /* ADC12 Conversion Memory 7 */
sfrw(ADC12MEM7, ADC12MEM7_);
#define ADC12MEM8_            0x0150    /* ADC12 Conversion Memory 8 */
sfrw(ADC12MEM8, ADC12MEM8_);
#define ADC12MEM9_            0x0152    /* ADC12 Conversion Memory 9 */
sfrw(ADC12MEM9, ADC12MEM9_);
#define ADC12MEM10_           0x0154    /* ADC12 Conversion Memory 10 */
sfrw(ADC12MEM10, ADC12MEM10_);
#define ADC12MEM11_           0x0156    /* ADC12 Conversion Memory 11 */
sfrw(ADC12MEM11, ADC12MEM11_);
#define ADC12MEM12_           0x0158    /* ADC12 Conversion Memory 12 */
sfrw(ADC12MEM12, ADC12MEM12_);
#define ADC12MEM13_           0x015A    /* ADC12 Conversion Memory 13 */
sfrw(ADC12MEM13, ADC12MEM13_);
#define ADC12MEM14_           0x015C    /* ADC12 Conversion Memory 14 */
sfrw(ADC12MEM14, ADC12MEM14_);
#define ADC12MEM15_           0x015E    /* ADC12 Conversion Memory 15 */
sfrw(ADC12MEM15, ADC12MEM15_);

#define ADC12MCTL_          (0x0080)  /* ADC12 Memory Control */
#ifndef __STDC__
#define ADC12MCTL           (ADC12MCTL_) /* ADC12 Memory Control (for assembler) */
#else
#define ADC12MCTL           ((volatile char*) ADC12MCTL_) /* ADC12 Memory Control (for C) */
#endif
#define ADC12MCTL0_           0x0080    /* ADC12 Memory Control 0 */
sfrb(ADC12MCTL0, ADC12MCTL0_);
#define ADC12MCTL1_           0x0081    /* ADC12 Memory Control 1 */
sfrb(ADC12MCTL1, ADC12MCTL1_);
#define ADC12MCTL2_           0x0082    /* ADC12 Memory Control 2 */
sfrb(ADC12MCTL2, ADC12MCTL2_);
#define ADC12MCTL3_           0x0083    /* ADC12 Memory Control 3 */
sfrb(ADC12MCTL3, ADC12MCTL3_);
#define ADC12MCTL4_           0x0084    /* ADC12 Memory Control 4 */
sfrb(ADC12MCTL4, ADC12MCTL4_);
#define ADC12MCTL5_           0x0085    /* ADC12 Memory Control 5 */
sfrb(ADC12MCTL5, ADC12MCTL5_);
#define ADC12MCTL6_           0x0086    /* ADC12 Memory Control 6 */
sfrb(ADC12MCTL6, ADC12MCTL6_);
#define ADC12MCTL7_           0x0087    /* ADC12 Memory Control 7 */
sfrb(ADC12MCTL7, ADC12MCTL7_);
#define ADC12MCTL8_           0x0088    /* ADC12 Memory Control 8 */
sfrb(ADC12MCTL8, ADC12MCTL8_);
#define ADC12MCTL9_           0x0089    /* ADC12 Memory Control 9 */
sfrb(ADC12MCTL9, ADC12MCTL9_);
#define ADC12MCTL10_          0x008A    /* ADC12 Memory Control 10 */
sfrb(ADC12MCTL10, ADC12MCTL10_);
#define ADC12MCTL11_          0x008B    /* ADC12 Memory Control 11 */
sfrb(ADC12MCTL11, ADC12MCTL11_);
#define ADC12MCTL12_          0x008C    /* ADC12 Memory Control 12 */
sfrb(ADC12MCTL12, ADC12MCTL12_);
#define ADC12MCTL13_          0x008D    /* ADC12 Memory Control 13 */
sfrb(ADC12MCTL13, ADC12MCTL13_);
#define ADC12MCTL14_          0x008E    /* ADC12 Memory Control 14 */
sfrb(ADC12MCTL14, ADC12MCTL14_);
#define ADC12MCTL15_          0x008F    /* ADC12 Memory Control 15 */
sfrb(ADC12MCTL15, ADC12MCTL15_);

/* ADC12CTL0 */
#define ADC12SC             (0x001)   /* ADC12 Start Conversion */
#define ENC                 (0x002)   /* ADC12 Enable Conversion */
#define ADC12TOVIE          (0x004)   /* ADC12 Timer Overflow interrupt enable */
#define ADC12OVIE           (0x008)   /* ADC12 Overflow interrupt enable */
#define ADC12ON             (0x010)   /* ADC12 On/enable */
#define REFON               (0x020)   /* ADC12 Reference on */
#define REF2_5V             (0x040)   /* ADC12 Ref 0:1.5V / 1:2.5V */
#define MSC                 (0x080)   /* ADC12 Multiple SampleConversion */
#define SHT00               (0x0100)  /* ADC12 Sample Hold 0 Select 0 */
#define SHT01               (0x0200)  /* ADC12 Sample Hold 0 Select 1 */
#define SHT02               (0x0400)  /* ADC12 Sample Hold 0 Select 2 */
#define SHT03               (0x0800)  /* ADC12 Sample Hold 0 Select 3 */
#define SHT10               (0x1000)  /* ADC12 Sample Hold 0 Select 0 */
#define SHT11               (0x2000)  /* ADC12 Sample Hold 1 Select 1 */
#define SHT12               (0x4000)  /* ADC12 Sample Hold 2 Select 2 */
#define SHT13               (0x8000)  /* ADC12 Sample Hold 3 Select 3 */
#define MSH                 (0x080)

#define SHT0_0               (0x0000) /* ADC12 Sample Hold 0 Select Bit: 0 */
#define SHT0_1               (0x0100) /* ADC12 Sample Hold 0 Select Bit: 1 */
#define SHT0_2               (0x0200) /* ADC12 Sample Hold 0 Select Bit: 2 */
#define SHT0_3               (0x0300) /* ADC12 Sample Hold 0 Select Bit: 3 */
#define SHT0_4               (0x0400) /* ADC12 Sample Hold 0 Select Bit: 4 */
#define SHT0_5               (0x0500) /* ADC12 Sample Hold 0 Select Bit: 5 */
#define SHT0_6               (0x0600) /* ADC12 Sample Hold 0 Select Bit: 6 */
#define SHT0_7               (0x0700) /* ADC12 Sample Hold 0 Select Bit: 7 */
#define SHT0_8               (0x0800) /* ADC12 Sample Hold 0 Select Bit: 8 */
#define SHT0_9               (0x0900) /* ADC12 Sample Hold 0 Select Bit: 9 */
#define SHT0_10             (0x0A00) /* ADC12 Sample Hold 0 Select Bit: 10 */
#define SHT0_11             (0x0B00) /* ADC12 Sample Hold 0 Select Bit: 11 */
#define SHT0_12             (0x0C00) /* ADC12 Sample Hold 0 Select Bit: 12 */
#define SHT0_13             (0x0D00) /* ADC12 Sample Hold 0 Select Bit: 13 */
#define SHT0_14             (0x0E00) /* ADC12 Sample Hold 0 Select Bit: 14 */
#define SHT0_15             (0x0F00) /* ADC12 Sample Hold 0 Select Bit: 15 */

#define SHT1_0               (0x0000) /* ADC12 Sample Hold 1 Select Bit: 0 */
#define SHT1_1               (0x1000) /* ADC12 Sample Hold 1 Select Bit: 1 */
#define SHT1_2               (0x2000) /* ADC12 Sample Hold 1 Select Bit: 2 */
#define SHT1_3               (0x3000) /* ADC12 Sample Hold 1 Select Bit: 3 */
#define SHT1_4               (0x4000) /* ADC12 Sample Hold 1 Select Bit: 4 */
#define SHT1_5               (0x5000) /* ADC12 Sample Hold 1 Select Bit: 5 */
#define SHT1_6               (0x6000) /* ADC12 Sample Hold 1 Select Bit: 6 */
#define SHT1_7               (0x7000) /* ADC12 Sample Hold 1 Select Bit: 7 */
#define SHT1_8               (0x8000) /* ADC12 Sample Hold 1 Select Bit: 8 */
#define SHT1_9               (0x9000) /* ADC12 Sample Hold 1 Select Bit: 9 */
#define SHT1_10             (0xA000) /* ADC12 Sample Hold 1 Select Bit: 10 */
#define SHT1_11             (0xB000) /* ADC12 Sample Hold 1 Select Bit: 11 */
#define SHT1_12             (0xC000) /* ADC12 Sample Hold 1 Select Bit: 12 */
#define SHT1_13             (0xD000) /* ADC12 Sample Hold 1 Select Bit: 13 */
#define SHT1_14             (0xE000) /* ADC12 Sample Hold 1 Select Bit: 14 */
#define SHT1_15             (0xF000) /* ADC12 Sample Hold 1 Select Bit: 15 */

/* ADC12CTL1 */
#define ADC12BUSY           (0x0001)    /* ADC12 Busy */
#define CONSEQ0             (0x0002)    /* ADC12 Conversion Sequence Select 0 */
#define CONSEQ1             (0x0004)    /* ADC12 Conversion Sequence Select 1 */
#define ADC12SSEL0          (0x0008)    /* ADC12 Clock Source Select 0 */
#define ADC12SSEL1          (0x0010)    /* ADC12 Clock Source Select 1 */
#define ADC12DIV0           (0x0020)    /* ADC12 Clock Divider Select 0 */
#define ADC12DIV1           (0x0040)    /* ADC12 Clock Divider Select 1 */
#define ADC12DIV2           (0x0080)    /* ADC12 Clock Divider Select 2 */
#define ISSH                (0x0100)    /* ADC12 Invert Sample Hold Signal */
#define SHP                 (0x0200)    /* ADC12 Sample/Hold Pulse Mode */
#define SHS0                (0x0400)    /* ADC12 Sample/Hold Source 0 */
#define SHS1                (0x0800)    /* ADC12 Sample/Hold Source 1 */
#define CSTARTADD0          (0x1000)    /* ADC12 Conversion Start Address 0 */
#define CSTARTADD1          (0x2000)    /* ADC12 Conversion Start Address 1 */
#define CSTARTADD2          (0x4000)    /* ADC12 Conversion Start Address 2 */
#define CSTARTADD3          (0x8000)    /* ADC12 Conversion Start Address 3 */

#define CONSEQ_0             (0x0000)      /* ADC12 Conversion Sequence Select: 0 */
#define CONSEQ_1             (0x0002)      /* ADC12 Conversion Sequence Select: 1 */
#define CONSEQ_2             (0x0004)      /* ADC12 Conversion Sequence Select: 2 */
#define CONSEQ_3             (0x0006)      /* ADC12 Conversion Sequence Select: 3 */
#define ADC12SSEL_0          (0x0000)      /* ADC12 Clock Source Select: 0 */
#define ADC12SSEL_1          (0x0008)      /* ADC12 Clock Source Select: 1 */
#define ADC12SSEL_2          (0x0010)      /* ADC12 Clock Source Select: 2 */
#define ADC12SSEL_3          (0x0018)      /* ADC12 Clock Source Select: 3 */
#define ADC12DIV_0           (0x0000)   /* ADC12 Clock Divider Select: 0 */
#define ADC12DIV_1           (0x0020)   /* ADC12 Clock Divider Select: 1 */
#define ADC12DIV_2           (0x0040)   /* ADC12 Clock Divider Select: 2 */
#define ADC12DIV_3           (0x0060)   /* ADC12 Clock Divider Select: 3 */
#define ADC12DIV_4           (0x0080)   /* ADC12 Clock Divider Select: 4 */
#define ADC12DIV_5           (0x00A0)   /* ADC12 Clock Divider Select: 5 */
#define ADC12DIV_6           (0x00C0)   /* ADC12 Clock Divider Select: 6 */
#define ADC12DIV_7           (0x00E0)   /* ADC12 Clock Divider Select: 7 */
#define SHS_0                (0x0000)  /* ADC12 Sample/Hold Source: 0 */
#define SHS_1                (0x0400)  /* ADC12 Sample/Hold Source: 1 */
#define SHS_2                (0x0800)  /* ADC12 Sample/Hold Source: 2 */
#define SHS_3                (0x0C00)  /* ADC12 Sample/Hold Source: 3 */
#define CSTARTADD_0          (0x0000) /* ADC12 Conversion Start Address: 0 */
#define CSTARTADD_1          (0x1000) /* ADC12 Conversion Start Address: 1 */
#define CSTARTADD_2          (0x2000) /* ADC12 Conversion Start Address: 2 */
#define CSTARTADD_3          (0x3000) /* ADC12 Conversion Start Address: 3 */
#define CSTARTADD_4          (0x4000) /* ADC12 Conversion Start Address: 4 */
#define CSTARTADD_5          (0x5000) /* ADC12 Conversion Start Address: 5 */
#define CSTARTADD_6          (0x6000) /* ADC12 Conversion Start Address: 6 */
#define CSTARTADD_7          (0x7000) /* ADC12 Conversion Start Address: 7 */
#define CSTARTADD_8          (0x8000) /* ADC12 Conversion Start Address: 8 */
#define CSTARTADD_9          (0x9000) /* ADC12 Conversion Start Address: 9 */
#define CSTARTADD_10        (0xA000) /* ADC12 Conversion Start Address: 10 */
#define CSTARTADD_11        (0xB000) /* ADC12 Conversion Start Address: 11 */
#define CSTARTADD_12        (0xC000) /* ADC12 Conversion Start Address: 12 */
#define CSTARTADD_13        (0xD000) /* ADC12 Conversion Start Address: 13 */
#define CSTARTADD_14        (0xE000) /* ADC12 Conversion Start Address: 14 */
#define CSTARTADD_15        (0xF000) /* ADC12 Conversion Start Address: 15 */

/* ADC12MCTLx */
#define INCH0               (0x0001)    /* ADC12 Input Channel Select Bit 0 */
#define INCH1               (0x0002)    /* ADC12 Input Channel Select Bit 1 */
#define INCH2               (0x0004)    /* ADC12 Input Channel Select Bit 2 */
#define INCH3               (0x0008)    /* ADC12 Input Channel Select Bit 3 */
#define SREF0               (0x0010)    /* ADC12 Select Reference Bit 0 */
#define SREF1               (0x0020)    /* ADC12 Select Reference Bit 1 */
#define SREF2               (0x0040)    /* ADC12 Select Reference Bit 2 */
#define EOS                 (0x0080)    /* ADC12 End of Sequence */

#define INCH_0               (0)        /* ADC12 Input Channel 0 */
#define INCH_1               (1)        /* ADC12 Input Channel 1 */
#define INCH_2               (2)        /* ADC12 Input Channel 2 */
#define INCH_3               (3)        /* ADC12 Input Channel 3 */
#define INCH_4               (4)        /* ADC12 Input Channel 4 */
#define INCH_5               (5)        /* ADC12 Input Channel 5 */
#define INCH_6               (6)        /* ADC12 Input Channel 6 */
#define INCH_7               (7)        /* ADC12 Input Channel 7 */
#define INCH_8               (8)        /* ADC12 Input Channel 8 */
#define INCH_9               (9)        /* ADC12 Input Channel 9 */
#define INCH_10             (10)        /* ADC12 Input Channel 10 */
#define INCH_11             (11)        /* ADC12 Input Channel 11 */
#define INCH_12             (12)        /* ADC12 Input Channel 12 */
#define INCH_13             (13)        /* ADC12 Input Channel 13 */
#define INCH_14             (14)        /* ADC12 Input Channel 14 */
#define INCH_15             (15)        /* ADC12 Input Channel 15 */

#define SREF_0               (0x0000)   /* ADC12 Select Reference 0 */
#define SREF_1               (0x0010)   /* ADC12 Select Reference 1 */
#define SREF_2               (0x0020)   /* ADC12 Select Reference 2 */
#define SREF_3               (0x0030)   /* ADC12 Select Reference 3 */
#define SREF_4               (0x0040)   /* ADC12 Select Reference 4 */
#define SREF_5               (0x0050)   /* ADC12 Select Reference 5 */
#define SREF_6               (0x0060)   /* ADC12 Select Reference 6 */
#define SREF_7               (0x0070)   /* ADC12 Select Reference 7 */

/* ADC12IV Definitions */
#define ADC12IV_NONE        (0x0000)    /* No Interrupt pending */
#define ADC12IV_ADC12OVIFG  (0x0002)    /* ADC12OVIFG */
#define ADC12IV_ADC12TOVIFG (0x0004)    /* ADC12TOVIFG */
#define ADC12IV_ADC12IFG0   (0x0006)    /* ADC12IFG0 */
#define ADC12IV_ADC12IFG1   (0x0008)    /* ADC12IFG1 */
#define ADC12IV_ADC12IFG2   (0x000A)    /* ADC12IFG2 */
#define ADC12IV_ADC12IFG3   (0x000C)    /* ADC12IFG3 */
#define ADC12IV_ADC12IFG4   (0x000E)    /* ADC12IFG4 */
#define ADC12IV_ADC12IFG5   (0x0010)    /* ADC12IFG5 */
#define ADC12IV_ADC12IFG6   (0x0012)    /* ADC12IFG6 */
#define ADC12IV_ADC12IFG7   (0x0014)    /* ADC12IFG7 */
#define ADC12IV_ADC12IFG8   (0x0016)    /* ADC12IFG8 */
#define ADC12IV_ADC12IFG9   (0x0018)    /* ADC12IFG9 */
#define ADC12IV_ADC12IFG10  (0x001A)    /* ADC12IFG10 */
#define ADC12IV_ADC12IFG11  (0x001C)    /* ADC12IFG11 */
#define ADC12IV_ADC12IFG12  (0x001E)    /* ADC12IFG12 */
#define ADC12IV_ADC12IFG13  (0x0020)    /* ADC12IFG13 */
#define ADC12IV_ADC12IFG14  (0x0022)    /* ADC12IFG14 */
#define ADC12IV_ADC12IFG15  (0x0024)    /* ADC12IFG15 */

/************************************************************
* DAC12
************************************************************/
#define __MSP430_HAS_DAC12_2__          /* Definition to show that Module is available */

#define DAC12_0CTL_           0x01c0    /* DAC12_0 Control */
sfrw(DAC12_0CTL, DAC12_0CTL_);
#define DAC12_1CTL_           0x01c2    /* DAC12_1 Control */
sfrw(DAC12_1CTL, DAC12_1CTL_);

#define DAC12GRP            (0x0001)    /* DAC12 group */
#define DAC12ENC            (0x0002)    /* DAC12 enable conversion */
#define DAC12IFG            (0x0004)    /* DAC12 interrupt flag */
#define DAC12IE             (0x0008)    /* DAC12 interrupt enable */
#define DAC12DF             (0x0010)    /* DAC12 data format */
#define DAC12AMP0           (0x0020)    /* DAC12 amplifier bit 0 */
#define DAC12AMP1           (0x0040)    /* DAC12 amplifier bit 1 */
#define DAC12AMP2           (0x0080)    /* DAC12 amplifier bit 2 */
#define DAC12IR             (0x0100)    /* DAC12 input reference and output range */
#define DAC12CALON          (0x0200)    /* DAC12 calibration */
#define DAC12LSEL0          (0x0400)    /* DAC12 load select bit 0 */
#define DAC12LSEL1          (0x0800)    /* DAC12 load select bit 1 */
#define DAC12RES            (0x1000)    /* DAC12 resolution */
#define DAC12SREF0          (0x2000)    /* DAC12 reference bit 0 */
#define DAC12SREF1          (0x4000)    /* DAC12 reference bit 1 */

#define DAC12AMP_0          (0x0000)  /* DAC12 amplifier 0: off,    3-state */
#define DAC12AMP_1          (0x0020)  /* DAC12 amplifier 1: off,    off */
#define DAC12AMP_2          (0x0040)  /* DAC12 amplifier 2: low,    low */
#define DAC12AMP_3          (0x0060)  /* DAC12 amplifier 3: low,    medium */
#define DAC12AMP_4          (0x0080)  /* DAC12 amplifier 4: low,    high */
#define DAC12AMP_5          (0x00A0)  /* DAC12 amplifier 5: medium, medium */
#define DAC12AMP_6          (0x00C0)  /* DAC12 amplifier 6: medium, high */
#define DAC12AMP_7          (0x00E0)  /* DAC12 amplifier 7: high,   high */

#define DAC12LSEL_0         (0x0000)  /* DAC12 load select 0: direct */
#define DAC12LSEL_1         (0x0400)  /* DAC12 load select 1: latched with DAT */
#define DAC12LSEL_2         (0x0800)  /* DAC12 load select 2: latched with pos. Timer_A3.OUT1 */
#define DAC12LSEL_3         (0x0C00)  /* DAC12 load select 3: latched with pos. Timer_B7.OUT1 */

#define DAC12SREF_0         (0x0000)  /* DAC12 reference 0: Vref+ */
#define DAC12SREF_1         (0x2000)  /* DAC12 reference 1: Vref+ */
#define DAC12SREF_2         (0x4000)  /* DAC12 reference 2: Veref+ */
#define DAC12SREF_3         (0x6000)  /* DAC12 reference 3: Veref+ */

#define DAC12_0DAT_           0x01c8    /* DAC12_0 Data */
sfrw(DAC12_0DAT, DAC12_0DAT_);
#define DAC12_1DAT_           0x01ca    /* DAC12_1 Data */
sfrw(DAC12_1DAT, DAC12_1DAT_);
/************************************************************
* DMA
************************************************************/
#define __MSP430_HAS_DMA_3__            /* Definition to show that Module is available */

#define DMACTL0_              0x0122    /* DMA Module Control 0 */
sfrw(DMACTL0, DMACTL0_);
#define DMA0TSEL0           (0x0001)    /* DMA channel 0 transfer select bit 0 */
#define DMA0TSEL1           (0x0002)    /* DMA channel 0 transfer select bit 1 */
#define DMA0TSEL2           (0x0004)    /* DMA channel 0 transfer select bit 2 */
#define DMA0TSEL3           (0x0008)    /* DMA channel 0 transfer select bit 3 */
#define DMA1TSEL0           (0x0010)    /* DMA channel 1 transfer select bit 0 */
#define DMA1TSEL1           (0x0020)    /* DMA channel 1 transfer select bit 1 */
#define DMA1TSEL2           (0x0040)    /* DMA channel 1 transfer select bit 2 */
#define DMA1TSEL3           (0x0080)    /* DMA channel 1 transfer select bit 3 */
#define DMA2TSEL0           (0x0100)    /* DMA channel 2 transfer select bit 0 */
#define DMA2TSEL1           (0x0200)    /* DMA channel 2 transfer select bit 1 */
#define DMA2TSEL2           (0x0400)    /* DMA channel 2 transfer select bit 2 */
#define DMA2TSEL3           (0x0800)    /* DMA channel 2 transfer select bit 3 */

#define DMA0TSEL_0          (0x0000)  /* DMA channel 0 transfer select 0:  DMA_REQ (sw)*/
#define DMA0TSEL_1          (0x0001)  /* DMA channel 0 transfer select 1:  Timer_A (TACCR2.IFG) */
#define DMA0TSEL_2          (0x0002)  /* DMA channel 0 transfer select 2:  Timer_B (TBCCR2.IFG) */
#define DMA0TSEL_3          (0x0003)  /* DMA channel 0 transfer select 3:  UART0/I2C receive */
#define DMA0TSEL_4          (0x0004)  /* DMA channel 0 transfer select 4:  UART0/I2C transmit */
#define DMA0TSEL_5          (0x0005)  /* DMA channel 0 transfer select 5:  DAC12_0CTL.DAC12IFG */
#define DMA0TSEL_6          (0x0006)  /* DMA channel 0 transfer select 6:  ADC12 (ADC12IFG) */
#define DMA0TSEL_7          (0x0007)  /* DMA channel 0 transfer select 7:  Timer_A (TACCR0.IFG) */
#define DMA0TSEL_8          (0x0008)  /* DMA channel 0 transfer select 8:  Timer_B (TBCCR0.IFG) */
#define DMA0TSEL_9          (0x0009)  /* DMA channel 0 transfer select 9:  UART1 receive */
#define DMA0TSEL_10         (0x000A) /* DMA channel 0 transfer select 10: UART1 transmit */
#define DMA0TSEL_11         (0x000B) /* DMA channel 0 transfer select 11: Multiplier ready */
#define DMA0TSEL_14         (0x000E) /* DMA channel 0 transfer select 14: previous DMA channel DMA2IFG */
#define DMA0TSEL_15         (0x000F) /* DMA channel 0 transfer select 15: ext. Trigger (DMAE0) */

#define DMA1TSEL_0          (0x0000)  /* DMA channel 1 transfer select 0:  DMA_REQ */
#define DMA1TSEL_1          (0x0010)  /* DMA channel 1 transfer select 1:  Timer_A CCRIFG.2 */
#define DMA1TSEL_2          (0x0020)  /* DMA channel 1 transfer select 2:  Timer_B CCRIFG.2 */
#define DMA1TSEL_3          (0x0030)  /* DMA channel 1 transfer select 3:  UART0/I2C receive */
#define DMA1TSEL_4          (0x0040)  /* DMA channel 1 transfer select 4:  UART0/I2C transmit */
#define DMA1TSEL_5          (0x0050)  /* DMA channel 1 transfer select 5:  DAC12.0IFG */
#define DMA1TSEL_6          (0x0060)  /* DMA channel 1 transfer select 6:  ADC12 (ADC12IFG) */
#define DMA1TSEL_7          (0x0070)  /* DMA channel 1 transfer select 7:  Timer_A (TACCR0.IFG) */
#define DMA1TSEL_8          (0x0080)  /* DMA channel 1 transfer select 8:  Timer_B (TBCCR0.IFG) */
#define DMA1TSEL_9          (0x0090)  /* DMA channel 1 transfer select 9:  UART1 receive */
#define DMA1TSEL_10         (0x00A0) /* DMA channel 1 transfer select 10: UART1 transmit */
#define DMA1TSEL_11         (0x00B0) /* DMA channel 1 transfer select 11: Multiplier ready */
#define DMA1TSEL_14         (0x00E0) /* DMA channel 1 transfer select 14: previous DMA channel DMA0IFG */
#define DMA1TSEL_15         (0x00F0) /* DMA channel 1 transfer select 15: ext. Trigger (DMAE0) */

#define DMA2TSEL_0          (0x0000)  /* DMA channel 2 transfer select 0:  DMA_REQ */
#define DMA2TSEL_1          (0x0100)  /* DMA channel 2 transfer select 1:  Timer_A CCRIFG.2 */
#define DMA2TSEL_2          (0x0200)  /* DMA channel 2 transfer select 2:  Timer_B CCRIFG.2 */
#define DMA2TSEL_3          (0x0300)  /* DMA channel 2 transfer select 3:  UART0/I2C receive */
#define DMA2TSEL_4          (0x0400)  /* DMA channel 2 transfer select 4:  UART0/I2C transmit */
#define DMA2TSEL_5          (0x0500)  /* DMA channel 2 transfer select 5:  DAC12.0IFG */
#define DMA2TSEL_6          (0x0600)  /* DMA channel 2 transfer select 6:  ADC12 (ADC12IFG) */
#define DMA2TSEL_7          (0x0700)  /* DMA channel 2 transfer select 7:  Timer_A (TACCR0.IFG) */
#define DMA2TSEL_8          (0x0800)  /* DMA channel 2 transfer select 8:  Timer_B (TBCCR0.IFG) */
#define DMA2TSEL_9          (0x0900)  /* DMA channel 2 transfer select 9:  UART1 receive */
#define DMA2TSEL_10         (0x0A00) /* DMA channel 2 transfer select 10: UART1 transmit */
#define DMA2TSEL_11         (0x0B00) /* DMA channel 2 transfer select 11: Multiplier ready */
#define DMA2TSEL_14         (0x0E00) /* DMA channel 2 transfer select 14: previous DMA channel DMA1IFG */
#define DMA2TSEL_15         (0x0F00) /* DMA channel 2 transfer select 15: ext. Trigger (DMAE0) */

#define DMACTL1_              0x0124    /* DMA Module Control 1 */
sfrw(DMACTL1, DMACTL1_);
#define ENNMI               (0x0001)    /* Enable NMI interruption of DMA */
#define ROUNDROBIN          (0x0002)    /* Round-Robin DMA channel priorities */
#define DMAONFETCH          (0x0004)    /* DMA transfer on instruction fetch */

#define DMA0CTL_              0x01e0    /* DMA Channel 0 Control */
sfrw(DMA0CTL, DMA0CTL_);
#define DMA1CTL_              0x01e8    /* DMA Channel 1 Control */
sfrw(DMA1CTL, DMA1CTL_);
#define DMA2CTL_              0x01f0    /* DMA Channel 2 Control */
sfrw(DMA2CTL, DMA2CTL_);

#define DMAREQ              (0x0001)    /* Initiate DMA transfer with DMATSEL */
#define DMAABORT            (0x0002)    /* DMA transfer aborted by NMI */
#define DMAIE               (0x0004)    /* DMA interrupt enable */
#define DMAIFG              (0x0008)    /* DMA interrupt flag */
#define DMAEN               (0x0010)    /* DMA enable */
#define DMALEVEL            (0x0020)    /* DMA level sensitive trigger select */
#define DMASRCBYTE          (0x0040)    /* DMA source byte */
#define DMADSTBYTE          (0x0080)    /* DMA destination byte */
#define DMASRCINCR0         (0x0100)    /* DMA source increment bit 0 */
#define DMASRCINCR1         (0x0200)    /* DMA source increment bit 1 */
#define DMADSTINCR0         (0x0400)    /* DMA destination increment bit 0 */
#define DMADSTINCR1         (0x0800)    /* DMA destination increment bit 1 */
#define DMADT0              (0x1000)    /* DMA transfer mode bit 0 */
#define DMADT1              (0x2000)    /* DMA transfer mode bit 1 */
#define DMADT2              (0x4000)    /* DMA transfer mode bit 2 */

#define DMASWDW             (0x0000)  /* DMA transfer: source word to destination word */
#define DMASBDW             (0x0040)  /* DMA transfer: source byte to destination word */
#define DMASWDB             (0x0080)  /* DMA transfer: source word to destination byte */
#define DMASBDB             (0x00C0)  /* DMA transfer: source byte to destination byte */

#define DMASRCINCR_0        (0x0000)  /* DMA source increment 0: source address unchanged */
#define DMASRCINCR_1        (0x0100)  /* DMA source increment 1: source address unchanged */
#define DMASRCINCR_2        (0x0200)  /* DMA source increment 2: source address decremented */
#define DMASRCINCR_3        (0x0300)  /* DMA source increment 3: source address incremented */

#define DMADSTINCR_0        (0x0000)  /* DMA destination increment 0: destination address unchanged */
#define DMADSTINCR_1        (0x0400)  /* DMA destination increment 1: destination address unchanged */
#define DMADSTINCR_2        (0x0800)  /* DMA destination increment 2: destination address decremented */
#define DMADSTINCR_3        (0x0C00)  /* DMA destination increment 3: destination address incremented */

#define DMADT_0             (0x0000)  /* DMA transfer mode 0: single */
#define DMADT_1             (0x1000)  /* DMA transfer mode 1: block */
#define DMADT_2             (0x2000)  /* DMA transfer mode 2: interleaved */
#define DMADT_3             (0x3000)  /* DMA transfer mode 3: interleaved */
#define DMADT_4             (0x4000)  /* DMA transfer mode 4: single, repeat */
#define DMADT_5             (0x5000)  /* DMA transfer mode 5: block, repeat */
#define DMADT_6             (0x6000)  /* DMA transfer mode 6: interleaved, repeat */
#define DMADT_7             (0x7000)  /* DMA transfer mode 7: interleaved, repeat */

#define DMA0SA_               0x01e2    /* DMA Channel 0 Source Address */
sfrw(DMA0SA, DMA0SA_);
#define DMA0DA_               0x01e4    /* DMA Channel 0 Destination Address */
sfrw(DMA0DA, DMA0DA_);
#define DMA0SZ_               0x01e6    /* DMA Channel 0 Transfer Size */
sfrw(DMA0SZ, DMA0SZ_);
#define DMA1SA_               0x01ea    /* DMA Channel 1 Source Address */
sfrw(DMA1SA, DMA1SA_);
#define DMA1DA_               0x01ec    /* DMA Channel 1 Destination Address */
sfrw(DMA1DA, DMA1DA_);
#define DMA1SZ_               0x01ee    /* DMA Channel 1 Transfer Size */
sfrw(DMA1SZ, DMA1SZ_);
#define DMA2SA_               0x01f2    /* DMA Channel 2 Source Address */
sfrw(DMA2SA, DMA2SA_);
#define DMA2DA_               0x01f4    /* DMA Channel 2 Destination Address */
sfrw(DMA2DA, DMA2DA_);
#define DMA2SZ_               0x01f6    /* DMA Channel 2 Transfer Size */
sfrw(DMA2SZ, DMA2SZ_);

/************************************************************
* Interrupt Vectors (offset from 0xFFE0)
************************************************************/

#define DACDMA_VECTOR       (0x0000)  /* 0xFFE0 DAC/DMA */
#define PORT2_VECTOR        (0x0002)  /* 0xFFE2 Port 2 */
#define USART1TX_VECTOR     (0x0004)  /* 0xFFE4 USART 1 Transmit */
#define USART1RX_VECTOR     (0x0006)  /* 0xFFE6 USART 1 Receive */
#define PORT1_VECTOR        (0x0008)  /* 0xFFE8 Port 1 */
#define TIMERA1_VECTOR      (0x000A)  /* 0xFFEA Timer A CC1-2, TA */
#define TIMERA0_VECTOR      (0x000C)  /* 0xFFEC Timer A CC0 */
#define ADC12_VECTOR          (0x000E)  /* 0xFFEE ADC */
#define USART0TX_VECTOR     (0x0010)  /* 0xFFF0 USART 0 Transmit */
#define USART0RX_VECTOR     (0x0012)  /* 0xFFF2 USART 0 Receive */
#define WDT_VECTOR          (0x0014) /* 0xFFF4 Watchdog Timer */
#define COMPARATORA_VECTOR  (0x0016) /* 0xFFF6 Comparator A */
#define TIMERB1_VECTOR      (0x0018) /* 0xFFF8 Timer B CC1-6, TB */
#define TIMERB0_VECTOR      (0x001A) /* 0xFFFA Timer B CC0 */
#define NMI_VECTOR          (0x001C) /* 0xFFFC Non-maskable */
#define RESET_VECTOR        (0x001E) /* 0xFFFE Reset [Highest Priority] */

#define UART1TX_VECTOR      USART1TX_VECTOR
#define UART1RX_VECTOR      USART1RX_VECTOR
#define UART0TX_VECTOR      USART0TX_VECTOR
#define UART0RX_VECTOR      USART0RX_VECTOR
#define ADC_VECTOR          ADC12_VECTOR

/************************************************************
* End of Modules
************************************************************/
#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* #ifndef __msp430x16x */

