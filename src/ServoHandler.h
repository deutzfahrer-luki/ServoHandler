// EEPROMHandler.h
#ifndef SERVOHANDLER_H
#define SERVOHANDLER_H

#include <Arduino.h>
#include <PWMHandler.h>

#define STANDART_PERIOD_DURATION 20000

class ServoHandler
{
public:
    ServoHandler(uint8_t pin, float minPWM, float maxPWM); // Standartconstructor for standart degress
    ServoHandler(uint8_t pin, uint8_t startRange, uint8_t endRange, float minPWM, float maxPWM);
    void setDegrees(uint8_t degrees);
    uint8_t getDegrees();
    void updateDegrees(); // ask if the getDeggrss is the old degrees
    float calcDutyCycle(uint8_t degrees);
    
private:
    uint8_t pin_;
    uint8_t maxRange_[2];
    float PWMRange_[2];
    // uint8_t range_[2]; 
    unsigned long periodDuration_us_ = STANDART_PERIOD_DURATION;

    PWMHandler* PWMHandler_;
    
    uint8_t targetedDegrees_;
};

#endif // SERVOHANDLER_H
