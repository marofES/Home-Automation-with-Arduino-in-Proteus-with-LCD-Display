#include "LiquidCrystal.h"          //Library of lcd
LiquidCrystal lcd(13,12,11,10,9,8); //pin of lcd

void setup() 
{
  Serial.begin(9600);  // buart rate
  lcd.begin(16,2);  
  lcd.setCursor(0,0);
  lcd.print("Home Automation ");
  pinMode(7,OUTPUT); // RELAY MODULE
  pinMode(6,OUTPUT); //Fan or motor

}
 
void loop()
{
 if(Serial.available()>0)
   {     
   char data= Serial.read();
   Serial.println(data);
          
     if(data=='b')
     {
   
        digitalWrite(7,HIGH); // RELAY ON
        Serial.println("Bulb ON       ");
        lcd.setCursor(0,1);
        lcd.print("    Bulb ON        ");
  }   
   if(data=='c')
     {
       digitalWrite(7,LOW);  // RELAY OFF
       Serial.println("Bulb OFF");
       lcd.setCursor(0,1);
       lcd.print("    Bulb OFF        ");
  } 

    if(data=='f')
     {
    digitalWrite(6,HIGH); // LED ON
    Serial.println("FAN ON       ");
    lcd.setCursor(0,1);
    lcd.print("    Fan ON        ");
  }   
   if(data=='g')
     {
   digitalWrite(6,LOW);  // LED OFF
   Serial.println("Fan OFF");
   lcd.setCursor(0,1);
   lcd.print("    Fan OFF        ");
  }
  
     }
}
