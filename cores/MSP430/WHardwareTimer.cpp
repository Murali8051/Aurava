/* $Id: WHardwareTimer.cpp 1158 2011-06-07 19:13:20Z$
||
||
*/

#include "WHardwareTimer.h"

interrupt(TIMER0_A1_VECTOR) TIMER0_COMPA1_2_OVF_routine()
{
	if(TA0IV && TA0IV_TAIFG)
	{
		if (Timer0.overflowFunction != NULL)
		Timer0.overflowFunction();
	}
	else if(TA0IV && TA0IV_TACCR1){
		if (Timer0.compareMatchBFunction != NULL)
		Timer0.compareMatchBFunction();
	}
	else if(TA0IV && TA0IV_TACCR2) {
		if (Timer0.compareMatchCFunction != NULL)
		Timer0.compareMatchCFunction();
	}
}

interrupt(TIMER0_A0_VECTOR) TIMER0_COMPA0_routine()
{
  if (Timer0.compareMatchAFunction != NULL)
    Timer0.compareMatchAFunction();
}


interrupt(TIMER1_A1_VECTOR) TIMER1_COMPA1_2_OVF_routine()
{
	if(TA1IV && TA1IV_TAIFG){
		if (Timer1.overflowFunction != NULL)
			Timer1.overflowFunction();
	}
	else if(TA1IV && TA1IV_TACCR1){
		if (Timer1.compareMatchBFunction != NULL)
			Timer1.compareMatchBFunction();
	}
	else if(TA1IV && TA1IV_TACCR2){
		if (Timer1.compareMatchCFunction != NULL)
			Timer1.compareMatchCFunction();
	}
}

interrupt(TIMER1_A0_VECTOR) TIMER1_COMPA0_routine()
{
  if (Timer1.compareMatchAFunction != NULL)
    Timer1.compareMatchAFunction();
}


// Constructor

HardwareTimer::HardwareTimer(uint8_t timerNumber)
{
  _timerNumber = timerNumber;

  switch (timerNumber)
  {
    case 0:
    	_tanr=&TA0R;
    	_tanctl=&TA0CTL;
    	_tancctl0=&TA0CCTL0;
    	_tancctl1=&TA0CCTL1;
    	_tancctl2=&TA0CCTL2;
    	_tanccr0=&TA0CCR0;
    	_tanccr1=&TA0CCR1;
    	_tanccr2=&TA0CCR2;
    	_channelCount = 3;
    break;

    case 1:
    	_tanr=&TA1R;
    	_tanctl=&TA1CTL;
    	_tancctl0=&TA1CCTL0;
    	_tancctl1=&TA1CCTL1;
    	_tancctl2=&TA1CCTL2;
    	_tanccr0=&TA1CCR0;
    	_tanccr1=&TA1CCR1;
    	_tanccr2=&TA1CCR2;
    	_channelCount = 3;
    break;
  }

  setClockSource(CLOCK_STOP);
 // if (_tcntnh != NULL)  // 16 bit timers
 //   	*_tcntnh = 0;
  	*_tanr = 0;

  overflowFunction = NULL;
  compareMatchAFunction = NULL;
  compareMatchBFunction = NULL;
  compareMatchCFunction = NULL;
}


void HardwareTimer::setClockSource(uint8_t clockSource)
{
	//Section to set clock sources:
  if(_timerNumber == 0){
	switch (clockSource)
    {
      case TMR_12KHZ:
		BCSCTL1 &= ~DIVA_3;
		BCSCTL1 |= DIVA_0;
		BCSCTL3 |=  LFXT1S_2;	//Select VCLO clock.
		TA0CTL = TASSEL_1 | MC_1 | ID_0; // Timer clock source ACLK, Upcounter and divide nothing
	  break;
      case TMR_6KHZ:
		BCSCTL1 &= ~DIVA_3;
		BCSCTL1 |= DIVA_0;
		BCSCTL3 |=  LFXT1S_2;
		TA0CTL = TASSEL_1 | MC_1 | ID_1; 
	  break;
      case TMR_3KHZ:
		BCSCTL1 &= ~DIVA_3;
		BCSCTL1 |= DIVA_0;
		BCSCTL3 |=  LFXT1S_2;
		TA0CTL = TASSEL_1 | MC_1 | ID_2; 
      break;
      case TMR_1K5HZ:
		BCSCTL1 &= ~DIVA_3;
		BCSCTL1 |= DIVA_0;
		BCSCTL3 |=  LFXT1S_2;
		TA0CTL = TASSEL_1 | MC_1 | ID_3;
	  break;
      case TMR_0K75Hz:
		BCSCTL1 &= ~DIVA_3;
		BCSCTL1 |= DIVA_1;
		BCSCTL3 |=  LFXT1S_2;
		TA0CTL = TASSEL_1 | MC_1 | ID_3;
	  break;
      case TMR_0K375HZ:
		BCSCTL1 &= ~DIVA_3;
		BCSCTL1 |= DIVA_2;		
		BCSCTL3 |=  LFXT1S_2;
		TA0CTL = TASSEL_1 | MC_1 | ID_3;
	  break;
      case TMR_0K1875HZ:
		BCSCTL1 |= DIVA_3;		
		BCSCTL3 |=  LFXT1S_2;
		TA0CTL = TASSEL_1 | MC_1 | ID_3;
	  break;
	  case TMR_8MHZ:
		BCSCTL2 &= ~SELS;	// Clear bit:3 to use DCO
		BCSCTL2 &= ~DIVS_3;	// Clear SMCLK Div bits.
		BCSCTL2 |= DIVS_0;	// SMCLK Divide by 1 option.
		TA0CTL = TASSEL_2 | MC_1 | ID_0; // Select SMCLK as clock source and Divide by one.
	  break;
      case TMR_4MHZ:
		BCSCTL2 &= ~SELS;	
		BCSCTL2 &= ~DIVS_3;	
		BCSCTL2 |= DIVS_0;	
		TA0CTL = TASSEL_2 | MC_1 | ID_1;
	  break;
      case TMR_2MHZ:
		BCSCTL2 &= ~SELS;	
		BCSCTL2 &= ~DIVS_3;	
		BCSCTL2 |= DIVS_0;	
		TA0CTL = TASSEL_2 | MC_1 | ID_2;
	  break;
      case TMR_1MHZ:
		BCSCTL2 &= ~SELS;	
		BCSCTL2 &= ~DIVS_3;	
		BCSCTL2 |= DIVS_0;	
		TA0CTL = TASSEL_2 | MC_1 | ID_3;
	  break;
      case TMR_0M5Hz:
		BCSCTL2 &= ~SELS;	
		BCSCTL2 &= ~DIVS_3;	
		BCSCTL2 |= DIVS_1;	
		TA0CTL = TASSEL_2 | MC_1 | ID_3;
	  break;
	  case TMR_0M25HZ:
		BCSCTL2 &= ~SELS;	
		BCSCTL2 &= ~DIVS_3;	
		BCSCTL2 |= DIVS_2;	
		TA0CTL = TASSEL_2 | MC_1 | ID_3;
	  break;
      case TMR_0M125HZ:
		BCSCTL2 &= ~SELS;	
		BCSCTL2 |= DIVS_3;	
		TA0CTL = TASSEL_2 | MC_1 | ID_3;
	  break;
      case TMR_TACLK:
		TA0CTL = TASSEL_0;
		P1SEL|=BIT0;
	  break;	
      default:
      break;
    }
	}
	else{
	switch (clockSource)
    {
      case TMR_12KHZ:
		BCSCTL1 &= ~DIVA_3;
		BCSCTL1 |= DIVA_0;
		BCSCTL3 |=  LFXT1S_2;	//Select VCLO clock.
		TA1CTL = TASSEL_1 | MC_1 | ID_0; // Timer clock source ACLK, Upcounter and divide nothing
	  break;
      case TMR_6KHZ:
		BCSCTL1 &= ~DIVA_3;
		BCSCTL1 |= DIVA_0;
		BCSCTL3 |=  LFXT1S_2;
		TA1CTL = TASSEL_1 | MC_1 | ID_1; 
	  break;
      case TMR_3KHZ:
		BCSCTL1 &= ~DIVA_3;
		BCSCTL1 |= DIVA_0;
		BCSCTL3 |=  LFXT1S_2;
		TA1CTL = TASSEL_1 | MC_1 | ID_2; 
      break;
      case TMR_1K5HZ:
		BCSCTL1 &= ~DIVA_3;
		BCSCTL1 |= DIVA_0;
		BCSCTL3 |=  LFXT1S_2;
		TA1CTL = TASSEL_1 | MC_1 | ID_3;
	  break;
      case TMR_0K75Hz:
		BCSCTL1 &= ~DIVA_3;
		BCSCTL1 |= DIVA_1;
		BCSCTL3 |=  LFXT1S_2;
		TA1CTL = TASSEL_1 | MC_1 | ID_3;
	  break;
      case TMR_0K375HZ:
		BCSCTL1 &= ~DIVA_3;
		BCSCTL1 |= DIVA_2;		
		BCSCTL3 |=  LFXT1S_2;
		TA1CTL = TASSEL_1 | MC_1 | ID_3;
	  break;
      case TMR_0K1875HZ:
		BCSCTL1 |= DIVA_3;		
		BCSCTL3 |=  LFXT1S_2;
		TA1CTL = TASSEL_1 | MC_1 | ID_3;
	  break;
	  case TMR_8MHZ:
		BCSCTL2 &= ~SELS;	// Clear bit:3 to use DCO
		BCSCTL2 &= ~DIVS_3;	// Clear SMCLK Div bits.
		BCSCTL2 |= DIVS_0;	// SMCLK Divide by 1 option.
		TA1CTL = TASSEL_2 | MC_1 | ID_0; // Select SMCLK as clock source and Divide by one.
	  break;
      case TMR_4MHZ:
		BCSCTL2 &= ~SELS;	
		BCSCTL2 &= ~DIVS_3;	
		BCSCTL2 |= DIVS_0;	
		TA1CTL = TASSEL_2 | MC_1 | ID_1;
	  break;
      case TMR_2MHZ:
		BCSCTL2 &= ~SELS;	
		BCSCTL2 &= ~DIVS_3;	
		BCSCTL2 |= DIVS_0;	
		TA1CTL = TASSEL_2 | MC_1 | ID_2;
	  break;
      case TMR_1MHZ:
		BCSCTL2 &= ~SELS;	
		BCSCTL2 &= ~DIVS_3;	
		BCSCTL2 |= DIVS_0;	
		TA1CTL = TASSEL_2 | MC_1 | ID_3;
	  break;
      case TMR_0M5Hz:
		BCSCTL2 &= ~SELS;	
		BCSCTL2 &= ~DIVS_3;	
		BCSCTL2 |= DIVS_1;	
		TA1CTL = TASSEL_2 | MC_1 | ID_3;
	  break;
	  case TMR_0M25HZ:
		BCSCTL2 &= ~SELS;	
		BCSCTL2 &= ~DIVS_3;	
		BCSCTL2 |= DIVS_2;	
		TA1CTL = TASSEL_2 | MC_1 | ID_3;
	  break;
      case TMR_0M125HZ:
		BCSCTL2 &= ~SELS;	
		BCSCTL2 |= DIVS_3;	
		TA1CTL = TASSEL_2 | MC_1 | ID_3;
	  break;
      case TMR_TACLK:
		TA1CTL = TASSEL_0;
	  break;	
      default:
      break;
    }
	}
}


void HardwareTimer::setInterrupt(uint8_t interrupt, uint8_t value)
{
	uint8_t bitValue = 0;

  if (value)
    bitValue = 1;

	switch (interrupt)
  {
    case INTERRUPT_OVERFLOW:
		if (_timerNumber == 0)
			TA0CTL |= TAIE;
		else if (_timerNumber == 1)
			TA1CTL |= TAIE;
    break;
    case INTERRUPT_COMPARE_MATCH_A:
		if (_timerNumber == 0)
			TA0CCTL0 |= CCIE;
		else if (_timerNumber == 1)
			TA1CCTL0 |= CCIE; 
    break;
    case INTERRUPT_COMPARE_MATCH_B:
		if (_timerNumber == 0)
			TA0CCTL1 |= CCIE;
		else if (_timerNumber == 1)
			TA1CCTL1 |= CCIE;
	break;
    case INTERRUPT_COMPARE_MATCH_C:
		if (_timerNumber == 0)
			TA0CCTL2 |= CCIE;
		else if (_timerNumber == 1)
			TA1CCTL2 |= CCIE;
	break;
	default:
	break;
  }
}

void HardwareTimer::attachInterrupt(uint8_t interrupt, void (*userFunc)(void), uint8_t enable)
{
  switch (interrupt)
  {
    case INTERRUPT_OVERFLOW:
      overflowFunction = userFunc;
      break;
    case INTERRUPT_COMPARE_MATCH_A:
      compareMatchAFunction = userFunc;
      break;
    case INTERRUPT_COMPARE_MATCH_B:
      compareMatchBFunction = userFunc;
      break;
    case INTERRUPT_COMPARE_MATCH_C:
      compareMatchCFunction = userFunc;
      break;
  }

  if (userFunc == NULL)
    setInterrupt(interrupt, 0);
  else if (enable)
    setInterrupt(interrupt, 1);
}

void HardwareTimer::setMode(uint8_t mode){
  mode &= 0x0003; 	//Only xx modes are possible:
  switch(mode){
	case STOP_MODE:
		*_tanctl &= ~MC_3;
		*_tanctl |= MC_0;
		break;
	case UP_MODE:
		*_tanctl &= ~MC_3;
		*_tanctl|= MC_1;
		break;
	case CONT_MODE:
		*_tanctl &= ~MC_3;
		*_tanctl|= MC_2;
		break;
	case UD_MODE:
		*_tanctl|= MC_3;
		break;
	default:
		break;
	}
}

void HardwareTimer::setOutputMode(uint8_t channel, uint8_t outputMode)
{

  outputMode &= 0b111;  // only 7 modes
  uint16_t outModes[] = { OUTMOD_0, OUTMOD_1, OUTMOD_2, OUTMOD_3, OUTMOD_4, OUTMOD_5, OUTMOD_6, OUTMOD_7};
  if (channel < _channelCount)
  {
	if (channel == CHANNEL_A){
		*_tancctl0 &= ~OUTMOD_7;
		*_tancctl0 |= outModes[outputMode];
	}
    else if (channel == CHANNEL_B){
		*_tancctl1 &= ~OUTMOD_7;
		*_tancctl1 |= outModes[outputMode];
	}
    else if (channel == CHANNEL_C){
		*_tancctl2 &= ~OUTMOD_7;
		*_tancctl2 |= outModes[outputMode];
	}
  }
}

void HardwareTimer::setOCR(uint8_t channel, uint16_t value)
{
  if (channel < _channelCount)
  {
    if (channel == CHANNEL_A)
    {
      *_tancctl0	=	value;
    }
    else if (channel == CHANNEL_B)
    {
      *_tancctl1	=	value;
    }
    else if (channel == CHANNEL_C)
    {
      *_tancctl2	=	value;
    }
  }
}


void HardwareTimer::setCounter(uint16_t value)
{
  uint8_t oldSREG = READ_SR; // Read Status register
  dint();	//Disable the interrupts
  *_tanr = value;
  eint(); //Enable the interrupt.
  WRITE_SR(oldSREG); 	//Write status reg.
}


uint16_t HardwareTimer::getCounter(void)
{
  uint16_t value = 0;
  uint8_t oldSREG = READ_SR; // Read Status register
  dint();	//Disable the interrupts
  value = *_tanr;
  eint(); //Enable the interrupt.
  WRITE_SR(oldSREG); 	//Write status reg.

  return value;
}


// Preinstantiate Objects
HardwareTimer Timer0(0);
HardwareTimer Timer1(1);


