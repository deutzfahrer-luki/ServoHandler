#include <Arduino.h>
#include <ServoHandler.h>

#define PIN 8

ServoHandler Servo(PIN);

void setup() {
  Serial.begin(115200);

}

void loop() {
  for (int i = 0; i < 180; i++)
  {
    Servo.setDegrees(i);
    Servo.updateDegrees();
    delay(100);
  }
}
