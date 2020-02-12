#include<Arduino.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4); 
int A, Ac1, Ac2, Ac3, Ac0;
int B, Bc1, Bc2, Bc3, Bc0;
int C, Cc1, Cc2, Cc3, Cc0;
int D, Dc1, Dc2, Dc3, Dc0;
void setup() {
  lcd.begin(20,4);
  lcd.init();
  lcd.backlight();

  Serial.begin(9600);

  pinMode(A3, INPUT);
  pinMode(A2, INPUT);
  pinMode(A1, INPUT);
  pinMode(A0, INPUT);

  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);

  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);

  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  
}

void loop() {
  //magia matematica pro
  Ac0 = digitalRead(A3);
  Ac1 = digitalRead(A2);
  Ac2 = digitalRead(A1);
  Ac3 = digitalRead(A0);
  D = (Ac3 * 8) + (Ac2 * 4) + (Ac1 * 2) + (Ac0 * 1); 
  
  Bc0 = digitalRead(5);
  Bc1 = digitalRead(4);
  Bc2 = digitalRead(2);
  Bc3 = digitalRead(3);
  C = (Bc3 * 8) + (Bc2 * 4) + (Bc1 * 2) + (Bc0 * 1); 
  
  Cc0 = digitalRead(9);
  Cc1 = digitalRead(8);
  Cc2 = digitalRead(7);
  Cc3 = digitalRead(6);
  B = (Cc3 * 8) + (Cc2 * 4) + (Cc1 * 2) + (Cc0 * 1); 
  
 
  Dc0 = digitalRead(13);
  Dc1 = digitalRead(12);
  Dc2 = digitalRead(11);
  Dc3 = digitalRead(10);
  A = (Dc3 * 8) + (Dc2 * 4) + (Dc1 * 2) + (Dc0 * 1);  

 
  lcd.clear();
  lcd.setCursor(0, 1);//most
  lcd.print(D);
  lcd.setCursor(4, 1);
  lcd.print(C);
  lcd.setCursor(8, 1);
  lcd.print(B);
  lcd.setCursor(12, 1);//less
  lcd.print(A);


  delay(500);
}