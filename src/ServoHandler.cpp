// ServoHandler.cpp
#include "ServoHandler.h"

ServoHandler::ServoHandler(uint8_t pin) : pin_(pin) // Standartconstructor for standart degress
{
    this->PWMHandler_ = new PWMHandler(pin_, periodDuration_us_);
    this->currentDegress_ = 0;
    this->oldCurrentDegrees_ = 0;

    this->maxRange_[0] = 0;
    this->maxRange_[1] = 180;
}

ServoHandler::ServoHandler(uint8_t pin, uint8_t startRange, uint8_t endRange) : pin_(pin)
{
    this->PWMHandler_ = new PWMHandler(pin_, periodDuration_us_);
    this->currentDegress_ = 0;
    this->oldCurrentDegrees_ = 0;

    this->maxRange_[0] = startRange;
    this->maxRange_[1] = endRange;

    // this->maxRange_[0] = 0;
    // this->maxRange_[1] = 180;
}

void ServoHandler::setDegrees(uint8_t degrees)
{
    if (degrees > maxRange_[0] && degrees < maxRange_[1])
    {
        targetedDegrees_ = degrees;
        PWMHandler_->setDutyCycle(this->calcDutyCycle(targetedDegrees_));
    }
    else
    {
        Serial.println("Error set Degrees");
    }
}

uint8_t ServoHandler::getDegrees()
{
    return this->currentDegress_;
}

void ServoHandler::updateDegrees() // ask if the getDeggrss is the old degrees else turn the servo!
{
    PWMHandler_->updateModulation();
}

uint8_t ServoHandler::calcDutyCycle(uint8_t degrees)
{
    degrees = constrain(degrees, maxRange_[0], maxRange_[1]);
    return map(degrees, maxRange_[0], maxRange_[1], 0, 100); // map(long x, long in_min, long in_max, long out_min, long out_max)
}