#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3f,16,2);

#define LDR A0
#define LAMP1 2
#define LAMP2 3

/*
  Behavior,
  If the value is HIGH, the light in the room should be darker.
  Otherwise, the light in the room should be lighter.
*/


void setup(){
  // pinMode(LAMP1,OUTPUT);
  // pinMode(LAMP2,OUTPUT);
  
  lcd.init();
  lcd.backlight();
  
  Serial.begin(9600);
}

void loop() {
  unsigned int AnalogValue;
  AnalogValue = analogRead(LDR);
  lcd.setCursor(0,0);
  lcd.print("Brightness:");
  lcd.setCursor(12,0);
  lcd.print(AnalogValue);
  if (AnalogValue >= 680) {
    lcd.setCursor(0,1);
    lcd.print("Jiro: Maty");    
  } else {
      lcd.setCursor(0,1);
      lcd.print("Jiro: Mirehitra");
  }
  delay(1000);
  lcd.clear();
  
}