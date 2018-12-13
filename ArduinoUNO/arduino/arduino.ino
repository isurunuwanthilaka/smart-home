#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
SoftwareSerial ArduinoUno(3, 2);
String readline;

void setup() {
  Serial.begin(9600);
  ArduinoUno.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Location : ");
}

void loop() {

  if (ArduinoUno.available() > 0) {
    char c = ArduinoUno.read();
    if (c == '\n') {
      lcd.clear();
      lcd.print(readline);
      delay(500);
      Serial.println(readline);
      readline = "";
    } else {
      readline += c;
    }
  }
}
