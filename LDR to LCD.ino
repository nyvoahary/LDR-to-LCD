//Importing liquidCrystal I2C library
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3f,16,2);

// Connect the A0 pin of the LDR module to the A0 pin of Arduino
// Connect LCD SDA -> A4 and SCL -> A5

#define LDR A0    //Define A0 as LDR 

void setup(){
  
  // Initalize the lcd
  lcd.init();
  lcd.backlight();

}

void loop() {
  unsigned int AnalogValue;
  // Read the value from LDR
  AnalogValue = analogRead(LDR);

  lcd.setCursor(0,0);
  lcd.print("Brightness:");
  lcd.setCursor(12,0);
  lcd.print(AnalogValue);
  if (AnalogValue >= 680) {
    lcd.setCursor(0,1);
    lcd.print("Light: off");
  } else {
      lcd.setCursor(0,1);
      lcd.print("Light: on");
  }
  delay(1000);

  lcd.clear(); // Clear LCD to avoid overlay
  
}