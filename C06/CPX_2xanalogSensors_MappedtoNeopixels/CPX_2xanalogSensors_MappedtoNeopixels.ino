// map the value of two analog sensors to the number of neopixels lit up on either half of the CPX

#include <Adafruit_CircuitPlayground.h>

#define sensorA_Pin A0
#define sensorA_firstNeopixel 0
#define sensorA_lastNeopixel 4
#define sensorB_Pin A4
#define sensorB_firstNeopixel 5
#define sensorB_lastNeopixel 9

// Change to the lowest & highest values you see in the Serial Monitor
int sensorA_ValueLow = 0;
int sensorA_ValueHigh = 1023;
int sensorB_ValueLow = 0;
int sensorB_ValueHigh = 1023;

int sensorA_value;
int sensorA_value_constrained;
int sensorA_value_mapped;
int sensorB_value;
int sensorB_value_constrained;
int sensorB_value_mapped;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop() {
  CircuitPlayground.clearPixels();

  sensorA_value = analogRead(sensorA_Pin);
  sensorA_value_constrained = constrain(sensorA_value, sensorA_ValueLow, sensorA_ValueHigh);
  sensorA_value_mapped = map(sensorA_value_constrained, sensorA_ValueLow, sensorA_ValueHigh, sensorA_firstNeopixel, sensorA_lastNeopixel);

  for (int i = sensorA_firstNeopixel; i <= sensorA_value_mapped; i++) {
    CircuitPlayground.setPixelColor(i, 0xFF00FF);
  }

  Serial.print(" Sensor A: ");
  Serial.print(sensorA_value);
  Serial.print("\t Constrained A: ");
  Serial.print(sensorA_value_constrained);
  Serial.print("\t Mapped A: ");
  Serial.print(sensorA_value_mapped);
    Serial.print("\t\t");

  sensorB_value = analogRead(sensorB_Pin);
  sensorB_value_constrained = constrain(sensorB_value, sensorB_ValueLow, sensorB_ValueHigh);
  sensorB_value_mapped = map(sensorB_value_constrained, sensorB_ValueLow, sensorB_ValueHigh, sensorB_firstNeopixel, sensorB_lastNeopixel);

  for (int i = sensorB_firstNeopixel; i <= sensorB_value_mapped; i++) {
    CircuitPlayground.setPixelColor(i, 0xFF00FF);
  }

  Serial.print("Sensor B: ");
  Serial.print(sensorB_value);
  Serial.print("\t Constrained B: ");
  Serial.print(sensorB_value_constrained);
  Serial.print("\t Mapped B: ");
  Serial.print(sensorB_value_mapped);

  Serial.println();

  delay(10);
}