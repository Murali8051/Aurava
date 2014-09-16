/* $Id: WMath.h 1156 2011-06-07 04:01:16Z bhagman $
||
|| @author         Hernando Barragan <b@wiring.org.co>
|| @url            http://wiring.org.co/
|| @contribution   Brett Hagman <bhagman@wiring.org.co>
|| @contribution   Alexander Brevig <abrevig@wiring.org.co>
||
|| @description
|| | Math methods.
|| |
|| | Wiring Common API
|| #
||
|| @license Please see cores/Common/License.txt.
||
*/

#ifndef WMATH_H
#define WMATH_H

#include <math.h>
#include <stdlib.h>
#include <stdint.h>


//int32_t random(int32_t);
//int32_t random(int32_t, int32_t);
int32_t map(int32_t, int32_t, int32_t, int32_t, int32_t);
//void randomSeed(uint16_t);
uint16_t makeWord(uint8_t, uint8_t);
uint16_t makeWord(uint16_t);

#endif
// WMATH_H