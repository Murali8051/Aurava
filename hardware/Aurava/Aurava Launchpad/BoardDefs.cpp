#include <Wiring.h>

void boardInit(void)
{
 
  WDTCTL = WDTPW + WDTHOLD;
  BCSCTL1=CALBC1_1MHZ;
  DCOCTL=CALDCO_1MHZ;

}
