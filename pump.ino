
#include "ultrasonic.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

Ultrasonic tank(2, 3);
Ultrasonic reserve(4, 5);

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);


int tank1;
int reserve1;

const int tankEmpty = 23;
const int reserveEmpty = 23;
const int pumpPin = 7;

void setup() {
  // put your setup code here, to run once:
  // initialize the LCD
  lcd.begin();
  lcd.backlight();
  Serial.begin(9600);
  tank.initialize();
  reserve.initialize();
  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  tank1 = tank.getDistance();
  reserve1 = reserve.getDistance();
  float tankLevel = 100.0 - ((tank1 / (tankEmpty + 0.0)) * 100);
  float reserveLevel = 100.0 - ((reserve1 / (reserveEmpty + 0.0)) * 100);

  if (tankLevel < (0 + 0.0)) {
    tankLevel = 0 + 0.0;
  }
  if (reserveLevel < (0 + 0.0)) {
    reserveLevel = 0 + 0.0;
  }

  if (tankLevel < (20 + 0.0)) {
    if(tankLevel<(3+0.0)){
      digitalWrite(pumpPin, LOW);
      
    }
    else if (reserveLevel < (20 + 0.0)) {
      //DONT TURN ON PUMP
      digitalWrite(pumpPin, HIGH);
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("RSRVE EMPTY");
      delay(1000);
    }
    else {
      //TURN ON PUMP
      digitalWrite(pumpPin,LOW);
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("PUMP ON");
      delay(1000);
    }
  }

  
  if(reserveLevel < (20 + 0.0)){
          //DONT TURN ON PUMP
      digitalWrite(pumpPin, HIGH);
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("RSRVE EMPTY");
      delay(1000);
    
  }
  if (tankLevel > (75 + 0.0)) {
    //TURN OFF PUMP
    digitalWrite(pumpPin, HIGH);
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("TNK LVL: ");
  lcd.setCursor(9, 0);
  lcd.print(tankLevel);
  lcd.setCursor(15, 0);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("RSV LVL: ");
  lcd.setCursor(9, 1);
  lcd.print(reserveLevel);
  lcd.setCursor(15, 1);
  lcd.print("%");


  Serial.print("Tank: ");
  Serial.print(tankLevel);
  Serial.print("  ");
  Serial.print(tank1);
  Serial.print("   ");
  Serial.print("Reserve: ");
  Serial.print(reserveLevel);
  Serial.print("   ");
  Serial.println(reserve1);


  delay(500);
  //lcd.clear();


}
