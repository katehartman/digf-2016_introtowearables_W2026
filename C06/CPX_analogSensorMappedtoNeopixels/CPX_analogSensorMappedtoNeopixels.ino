// map an analog sensor value to the number of neopixels lit up on the CPX

#include <Adafruit_CircuitPlayground.h>

#define sensorPin A0
#define firstNeopixel 0
#define lastNeopixel 9

int sensorValueLow = 0; // Change to the lowest value you see in the Serial Monitor
int sensorValueHigh = 1023; // Change to the highest value you see in the Serial Monitor

int sensorValue;
int constrainedSensorValue;
int mappedSensorValue;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop() {
  sensorValue = analogRead(sensorPin);
  constrainedSensorValue = constrain(sensorValue, sensorValueLow, sensorValueHigh);
  mappedSensorValue = map(constrainedSensorValue, sensorValueLow, sensorValueHigh, firstNeopixel, lastNeopixel);

  Serial.print(" Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print("\t Constrained Sensor Value: ");
  Serial.print(constrainedSensorValue);
  Serial.print("\t Mapped Sensor Value: ");
  Serial.print(mappedSensorValue);
  Serial.println();

  CircuitPlayground.clearPixels();

  for (int i = firstNeopixel; i < mappedSensorValue; i++) {
    CircuitPlayground.setPixelColor(i, 0xFF00FF);
  }

  delay(5);
}