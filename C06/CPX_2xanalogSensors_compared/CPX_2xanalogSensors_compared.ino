// light up neopixels on the half of the CPX that corresponds with the sensor with the highest value

#include <Adafruit_CircuitPlayground.h>

#define sensorA_Pin A4
#define sensorA_firstNeopixel 0
#define sensorA_lastNeopixel 4
#define sensorB_Pin A0
#define sensorB_firstNeopixel 5
#define sensorB_lastNeopixel 9

int sensorA_value;
int sensorB_value;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop() {
  CircuitPlayground.clearPixels();

  sensorA_value = analogRead(sensorA_Pin);
  Serial.print("Sensor A: ");
  Serial.print(sensorA_value);
  Serial.print("\t");

  sensorB_value = analogRead(sensorB_Pin);
  Serial.print("Sensor B: ");
  Serial.print(sensorB_value);
  Serial.println();

    if (sensorA_value > sensorB_value) {
    for (int i = sensorA_firstNeopixel; i <= sensorA_lastNeopixel; i++) {
      CircuitPlayground.setPixelColor(i, 0xFF00FF);
    }
  } else {
    for (int i = sensorB_firstNeopixel; i <= sensorB_lastNeopixel; i++) {
      CircuitPlayground.setPixelColor(i, 0xFF00FF);
    }
  }

  delay(100);
}