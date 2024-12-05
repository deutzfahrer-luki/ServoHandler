// EEPROMHandler.h
#ifndef SERVOHANDLER_H
#define SERVOHANDLER_H

#include <Arduino.h>
#include <ServoHandler.h>
class ServoHandler
{
public:
    ServoHandler(uint8_t pin); // Standartconstructor for standart degress
    ServoHandler(uint8_t pin, uint8_t startDegress, uint8_t endDegrees);
    void setDegrees(uint8_t degrees);
    uint8_t getDegrees();
    void updateDegrees(); // ask if the 

private:
    uint8_t startDegress_; 
    uint8_t endDegrees_;

    uint8_t currentDegress_;
};

#endif // SERVOHANDLER_H
