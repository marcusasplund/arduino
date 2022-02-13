

int LED1 = 12; // red
int LED2 = 8; // green
int buzzer = 10; // here you could put a relay or whatever
int mq4 = A5; // MQ-4Natural Gas Sensor
int sensorThreshold = 150; // check log output to adjust

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(mq4, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensorValue = analogRead(mq4);

  Serial.print("Pin A0: ");
  Serial.println(mq4);
  // Checks if gas levels has reached the threshold value
  if (analogSensorValue > sensorThreshold) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    tone(buzzer, 1000, 200);
  } else {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    noTone(buzzer);
  }
  delay(100); // interval for checking
}
