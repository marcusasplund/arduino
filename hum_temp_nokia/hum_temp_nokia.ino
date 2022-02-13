#include <PCD8544.h>
#include <dht11.h>
#define DHT11PIN 8

dht11 DHT11;
PCD8544 lcd;

int gas = A5;
int sensorThreshold = 150;
int val = 0; //value for storing moisture value
int soilPin = A0;//Declare a variable for the soil moisture sensor
int soilPower = 7;//Variable for Soil moisture Power

void setup() {

  lcd.begin(84, 48);
  pinMode(gas, INPUT);
  pinMode(soilPower, OUTPUT);//Set D7 as an OUTPUT
  digitalWrite(soilPower, LOW);//Set to LOW so no power is flowing through the sensor
  Serial.begin(9600);
}

void loop() {
  lcd.clear();
  Serial.println();

  int chk = DHT11.read(DHT11PIN);
  float temp = DHT11.temperature;         //Reading the temperature in degrees
  float hum = DHT11.humidity;
  int gasQ = analogRead(gas);
  int soil = readSoil();

  Serial.print("Luftkvalitet: ");
  Serial.println(gasQ);
  Serial.print("Luftfuktighet (%): ");
  Serial.println(hum, 2);
  Serial.print("Temperatur (C): ");
  Serial.println(temp, 2);
  Serial.print("Soil Moisture = ");
  Serial.println(soil);

  lcd.setCursor(0, 0);
  lcd.print("Fukt: ");
  lcd.print(hum);
  lcd.print(" %\t");
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" *C ");
  lcd.setCursor(0, 2);
  lcd.print("Luft: ");
  lcd.print(gasQ);
  lcd.print(" ppm ");
  lcd.setCursor(0, 3);
  lcd.print("Jord: ");
  lcd.print(soil);
  delay(2000);
}

int readSoil()
{

  digitalWrite(soilPower, HIGH);//turn D7 "On"
  delay(10);//wait 10 milliseconds
  val = analogRead(soilPin);//Read the SIG value form sensor
  digitalWrite(soilPower, LOW);//turn D7 "Off"
  return val;//send current moisture value
}
