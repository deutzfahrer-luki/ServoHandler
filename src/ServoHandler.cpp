// ServoHandler.cpp
#include "ServoHandler.h"

ServoHandler::ServoHandler(uint8_t pin) : pin_(pin)// Standartconstructor for standart degress
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

    this->range_[0] = startRange;
    this->range_[1] = endRange;

    this->maxRange_[0] = 0;
    this->maxRange_[1] = 180;
}

void ServoHandler::setDegrees(uint8_t degrees)
{
    this->targetedDegrees_ = degrees; 
}

uint8_t ServoHandler::getDegrees()
{
    return this->currentDegress_;
}

void ServoHandler::updateDegrees() // ask if the getDeggrss is the old degrees else turn the servo!
{
    if (this->currentDegress_ != this->targetedDegrees_)
    {
        PWMHandler_->updateModulation(); // Frage ob er direkt geht 
        Serial.println("TODO");
        currentDegress_ = targetedDegrees_;
    }
}

uint8_t ServoHandler::calcDutyCycle(uint8_t degrees)
{
    degrees = constrain(degrees, maxRange_[0], maxRange_[1]);
}