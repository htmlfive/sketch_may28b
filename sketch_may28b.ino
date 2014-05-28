/*4x4 Matrix Keypad with LiquidCrystal - Calculator*/

#include <Keypad.h>
#include <LiquidCrystal.h>

const byte numRows= 4; //number of rows on the keypad
const byte numCols= 4; //number of columns on the keypad
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);      // select the pins used on the LCD panel

//keymap defines the key pressed according to the row and columns just as appears on the keypad
char keymap[numRows][numCols]= 
{
{'1', '2', '3', '+'}, 
{'4', '5', '6', '-'}, 
{'7', '8', '9', 'x'},
{'C', '0', '=', '/'}
};

//Code that shows the the keypad connections to the arduino terminals
byte rowPins[numRows] = {22,24,26,28}; //Rows 0 to 3
byte colPins[numCols]= {30,32,34,36}; //Columns 0 to 3

//initializes an instance of the Keypad class
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

void setup(){
Serial.begin(9600);
lcd.begin(16, 2);
lcd.clear();
}

//If key is pressed, this key is stored in 'keypressed' variable
//If key is not equal to 'NO_KEY', then this key is printed out
//if count=17, then count is reset back to 0 (this means no key is pressed during the whole keypad scan process

void loop(){
char keypressed = myKeypad.getKey();
if (keypressed != NO_KEY){
  lcd.setCursor(15, 1);
  lcd.print(keypressed);}
}

