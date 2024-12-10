#include <Arduino.h>
#include <ServoHandler.h>

#define PIN 33
#define DELAY_TIME 400

unsigned long long currentTime = 0;
unsigned long long oldTime = currentTime;

float deg = 20;

ServoHandler Servo(PIN, 1.8, 12.8);

void updatePWMFromSerial()
{
  if (Serial.available() > 0)
  {
    deg = Serial.parseFloat();
    if (deg >= 0 && deg <= 180)
    {
      deg = deg;
      Servo.setDegrees(deg);
    }
    else
      Serial.println("Ungueltiger Wert! Bitte eine Zahl zwischen 0 und 180 eingeben.");
    while (Serial.available() > 0)
      Serial.read();
  }
}

void setup()
{
  Serial.begin(115200);
  Servo.setDegrees(120);
  Serial.println("HALLO");
  Serial.println(Servo.calcDutyCycle(120));
}

void loop()
{
  Servo.updateDegrees();
  updatePWMFromSerial();
}
