#include <PCD8544.h>
 PCD8544 lcd;
void setup() {
   lcd.begin(84, 48);
}
void loop() {
  lcd.setCursor(0, 0);
  lcd.print("   HEJ  ");
  lcd.setCursor(0, 1);
  lcd.print("     pa dig!");
  lcd.setCursor(0,2);
  lcd.print("Ester Asplund");
  delay(200);
 }
