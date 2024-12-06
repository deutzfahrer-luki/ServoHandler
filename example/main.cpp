#include <Arduino.h>
#include <ServoHandler.h>

#define PIN 33
#define DELAY_TIME 400

int i =0;

unsigned long long currentTime = 0;
unsigned long long oldTime = currentTime;

ServoHandler Servo(PIN);

void setup() {
  Serial.begin(115200);
  Servo.setDegrees(120);
  Serial.println("HALLO");
  Serial.println(Servo.calcDutyCycle(120));

}

void loop() {
  Servo.updateDegrees();
  currentTime = millis();
  if (currentTime > oldTime+DELAY_TIME)
  {
    Servo.setDegrees(i);
    if (i > 160)
      i =0;
    i = i + 10;
    Serial.println(i);
    Serial.println(Servo.getDegrees());
    oldTime = currentTime;
  }
  // Serial.println(Servo.calcDutyCycle(90));
  // delay(10000);
}
