// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7,8,9,10,11,12);

int potPin1 = A1;//front_left_pressure_sensor
int potPin2 = A2;//front_Right_pressure_sensor
int potPin3 = A3;//Rear_left_pressure_sensor
int potPin4 = A4;//Rear_Right_pressure_sensor
int sen1;
int sen2;
int sen3;
int sen4;
int Engine_switch;
int Switch= 6;//ignition_switch
int led=13;//ignition_led
int pMin = 0;
int pMax = 1023;

void setup()
{
lcd.begin(16, 2);// set up the LCD's number of columns and rows:
lcd.clear();
  Serial.begin(9600);
pinMode(led, OUTPUT);  
pinMode(Switch, INPUT);
pinMode(potPin1, INPUT);
pinMode(potPin2, INPUT);
pinMode(potPin3, INPUT);
pinMode(potPin4, INPUT);
}

void loop()
{
  
  Engine_switch=digitalRead(Switch);
  if(Engine_switch==HIGH)
  { digitalWrite(led,HIGH);
lcd.setCursor(0,0); // Sets the cursor to col 0 and row 0
  sen1=analogRead(potPin1);
   sen1= map(sen1, pMin, pMax, 0,100);
lcd.print(sen1); // Prints value of Potpin1 to LCD
lcd.setCursor(4,0); // Sets the cursor to col 4 and row 0
   sen2=analogRead(potPin2);
   sen2= map(sen2, pMin, pMax, 0,100);
lcd.print(sen2); // Prints value of Potpin2 to LCD
lcd.setCursor(8,0); // Sets the cursor to col 8 and row 0
 sen3=analogRead(potPin3);
   sen3=map(sen3, pMin, pMax, 0,100);
lcd.print(sen3);// Prints value of Potpin3 to LCD
lcd.setCursor(12,0); // Sets the cursor to col 12 and row 0
 sen4=analogRead(potPin4);
   sen4=map(sen4, pMin, pMax, 0,100);
lcd.print(sen4); // // Prints value of Potpin4 to LCD


if((sen1>=25)&&(sen1<=35))
{lcd.setCursor(0,1);
 lcd.print("N"); }// Prints "N" to LCD}
  else if(sen1>35)
          { lcd.setCursor(0,1);
           lcd.print("H");}// Prints "H" to LCD}
          else
          {lcd.setCursor(0,1);
           lcd.print("L");}// Prints "L" to LCD}

if((sen2>=25)&&(sen2<=35))
          { lcd.setCursor(4,1);
           lcd.print("N");} // Prints "N" to LCD}
  else if(sen2>35)
          {lcd.setCursor(4,1);
           lcd.print("H"); }// Prints "H" to LCD}
          else
          {lcd.setCursor(4,1);
           lcd.print("L");}// Prints "L" to LCD}

 if((sen3>=25)&&(sen3<=35))
          { lcd.setCursor(8,1);
           lcd.print("N");} // Prints "N" to LCD}
  else if(sen3>35)
          {lcd.setCursor(8,1);
           lcd.print("H"); }// Prints "H" to LCD}
          else
          {lcd.setCursor(8,1);
           lcd.print("L");}// Prints "L" to LCD}

 if((sen4>=25)&&(sen4<=35))
          { lcd.setCursor(12,1);
           lcd.print("N");} // Prints "N" to LCD}
  else if(sen4>35)
          {lcd.setCursor(12,1);
           lcd.print("H");}// Prints "H" to LCD}
          else
          {lcd.setCursor(12,1);
           lcd.print("L");}// Prints "L" to LCD}

}  
  
 else
 {digitalWrite(led,LOW);
  lcd.clear();//Clears the LCD screen
 }
}
