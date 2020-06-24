#include <sevenSegmentDisplay.h>
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
//define the cymbols on the buttons of the keypads
char keypadArray[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {6, 5, 4, 3}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {2, 1, 0}; //connect to the column pinouts of the keypad

//initialize an instance of the Keypad class
Keypad myKeypad = Keypad(makeKeymap(keypadArray), rowPins, colPins, ROWS, COLS); 
//create a 7 Segment Display library intance
sevenSegmentDisplay ssd(COMMON_ANODE, 13, 12, 11, 10, 9, 8, 7, A0);

void setup() {
}
  
void loop() {
  char key = myKeypad.getKey();
  int num = key - '0';
  
  if (key) {
    if (key == '*' || key == '#') {         
    } else {
      ssd.set(num); 
    }
  }
}
