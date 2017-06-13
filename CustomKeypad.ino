/* @file CustomKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates changing the keypad size and key values.
|| # 
ye bu 8
bu gre2 4
bu red 0
bk bu cook
gre1 pu 9
pu bk cancel
pu red start
pu gre2 1
pu ye 5
bk gy time
bk or temp
gy ye 6
ot ye 7

0+7 1+8         8

1+5+6+7+8       7
7 with 5
1 with 6
1 with 7
5 with 7
1 with 8

1+4+7+8         6
7 with 4
1 with 5
1 with 6
1 with 7
4 with 7

7+8 8+7         5

0+1+6+8         4
0 with 6
1 with 7
1 with 8

1+5+6+7         3
6 with 5
1 with 6
5 with 6
1 with 7

1+4+6+7         2
6 with 4
1 with 5
1 with 6
4 with 6

6+8             1
8 with 6
1 with 8
6 with 8

0+3 1+6+7+8     0
0 with 3
1 with 4
1 with 5
1 with 6
1 with 7
1 with 8



*/
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'0','1','2','3'},
  {'4','5','6','7'},
  {'8','9','A','B'},
  {'C','D','E','F'}
};
byte rowPins[9] = {0,1,2,3,4,5,6,7,8}; //connect to the row pinouts of the keypad
//byte colPins[COLS] = {}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
//Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(115200);
  for (int x = 0; x < 9; x++) 
    pinMode(rowPins[x], INPUT_PULLUP);
  pinMode(12, OUTPUT);
  tone(12, 4699, 500);
  delay(500);
  noTone(12);
}
  
void loop(){
  //char customKey = customKeypad.getKey();

  for (int x = 0; x < 9; x++) 
  {
    pinMode(rowPins[x], INPUT_PULLUP);
  }
  for (int x = 0; x < 9; x++) 
  {
    pinMode(rowPins[x], OUTPUT);
    digitalWrite(rowPins[x], LOW);
    for (int j = 0; j < 9; j++)  
    {
      if ( x == 8 && (j == 0 or j == 1 or j == 3 or j == 4 or j == 5)) continue;
      if (x!=j && !digitalRead(rowPins[j])) {
        Serial.print(j);
        Serial.print(" with ");
        Serial.println(x);
      }
    }
    digitalWrite(rowPins[x], HIGH);
    pinMode(rowPins[x], INPUT_PULLUP);
  }
  /*pinMode(8, OUTPUT);  // this section of code will output multiple 1s to serial monitor and if I press key "5" on the
  digitalWrite(8, LOW);  // keypad it will then print 0s to the serial monitor. 
  Serial.println(digitalRead(7));*/
  
  delay(500);
}




