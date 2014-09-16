#include <Wiring.h>

void boardInit(void)
{
 
  WDTCTL = WDTPW + WDTHOLD;
  BCSCTL1=CALBC1_8MHZ;
  DCOCTL=CALDCO_8MHZ; 
  eint();
}
