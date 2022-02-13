

int LED1 = 12;
int LED2 = 8;
int buzzer = 10;
int smokeA0 = A5;
int sensorThreshold = 150;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThreshold)
  {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    tone(buzzer, 1000, 200);
  }
  else
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    noTone(buzzer);
  }
  delay(100);
}
