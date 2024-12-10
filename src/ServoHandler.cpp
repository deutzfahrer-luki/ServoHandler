// ServoHandler.cpp
#include "ServoHandler.h"

ServoHandler::ServoHandler(uint8_t pin, float minPWM, float maxPWM) : pin_(pin) // Standartconstructor for standart degress
{
    this->PWMHandler_ = new PWMHandler(pin_, periodDuration_us_);

    this->maxRange_[0] = 0;
    this->maxRange_[1] = 180;
    if (minPWM < maxPWM)
    {
        this->PWMRange_[0] = minPWM;
        this->PWMRange_[1] = maxPWM;
    }
}

ServoHandler::ServoHandler(uint8_t pin, uint8_t startRange, uint8_t endRange, float minPWM, float maxPWM) : pin_(pin)
{
    this->PWMHandler_ = new PWMHandler(pin_, periodDuration_us_);

    this->maxRange_[0] = startRange;
    this->maxRange_[1] = endRange;
    if (minPWM < maxPWM)
    {
        this->PWMRange_[0] = minPWM;
        this->PWMRange_[1] = maxPWM;
    }
}

void ServoHandler::setDegrees(uint8_t degrees)
{
    if (degrees > maxRange_[0] && degrees <= maxRange_[1])
    {
        targetedDegrees_ = degrees;
        PWMHandler_->setDutyCycle(this->calcDutyCycle(targetedDegrees_));
        Serial.println(PWMHandler_->getDutyCycle);
    }
    else
    {
        Serial.println("Error set Degrees");
    }
}

uint8_t ServoHandler::getDegrees()
{
    return this->targetedDegrees_;
}

void ServoHandler::updateDegrees() // ask if the getDeggrss is the old degrees else turn the servo!
{
    PWMHandler_->updateModulation();
}

float ServoHandler::calcDutyCycle(uint8_t degrees)
{
    degrees = constrain(degrees, maxRange_[0], maxRange_[1]);
    return map(degrees, maxRange_[0], maxRange_[1], PWMRange_[0], PWMRange_[1]); // map(long x, long in_min, long in_max, long out_min, long out_max)
}