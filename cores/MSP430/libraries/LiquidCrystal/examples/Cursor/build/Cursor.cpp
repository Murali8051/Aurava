// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
#include "WProgram.h"
void setup();
void loop();
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of rows and columns: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

void loop() {
  // Turn off the cursor:
  lcd.noCursor();
  delay(500);
   // Turn on the cursor:
  lcd.cursor();
  delay(500);
}


