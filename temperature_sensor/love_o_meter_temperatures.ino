const int SENSOR_PIN = A0;
const float BASELINE_TEMP = 20.0;

void setup() {
  Serial.begin(9600);

  // set the digital pins as outputs
  for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }

}

void loop() {
  int sensorVal = analogRead(SENSOR_PIN);
  Serial.print("Sensor value = ");
  Serial.print(sensorVal);
  Serial.print("\n");

  float voltage = sensorVal / 1024.0 * 5.0;
  Serial.print("Voltage = ");
  Serial.print(voltage);
  Serial.print("\n");

  Serial.print("Temperatur degrees (C) = ");
  // convert the voltage to temperatures in degress celsius.
  float temperature = (voltage - 0.5) * 100;
  Serial.print(temperature);
  Serial.print("\n");

  if (temperature < BASELINE_TEMP + 2) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature >= BASELINE_TEMP + 2 && temperature < BASELINE_TEMP + 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature >= BASELINE_TEMP + 4 && temperature < BASELINE_TEMP + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if (temperature >= BASELINE_TEMP + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(5000);
}
