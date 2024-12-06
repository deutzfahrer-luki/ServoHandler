# Servo Handler
for easier use Servos with esp32

# ServoHandler Library

The **ServoHandler** library provides an efficient way to control servo motors in Arduino projects. It utilizes a `PWMHandler` object to manage PWM signals for servo operation. The library includes features for setting servo angles, computing duty cycles, and handling specific servo ranges.

---

## `ServoHandler.h`

```cpp
#ifndef SERVOHANDLER_H
#define SERVOHANDLER_H

#include <Arduino.h>
#include <PWMHandler.h>

#define STANDART_PERIOD_DURATION 20000

class ServoHandler
{
public:
    ServoHandler(uint8_t pin); // Standartconstructor for standart degress
    ServoHandler(uint8_t pin, uint8_t startRange, uint8_t endRange);
    void setDegrees(uint8_t degrees);
    uint8_t getDegrees();
    void updateDegrees(); // ask if the getDeggrss is the old degrees
    uint8_t calcDutyCycle(uint8_t degrees);
    
private:
    uint8_t pin_;
    uint8_t maxRange_[2];
    // uint8_t range_[2]; 
    unsigned long periodDuration_us_ = STANDART_PERIOD_DURATION;

    PWMHandler* PWMHandler_;
    
    uint8_t targetedDegrees_;
};

#endif // SERVOHANDLER_H
```
## Features
-   Initialize servos with default or custom angular ranges.
-   Dynamically set and retrieve servo positions in degrees.
-   Automatically calculate duty cycles for desired angles.
-   Seamless integration with ```PWMHandler``` for PWM signal generation.
   
## Installation
-   Download the library files or clone the repository.
-   Copy the ```ServoHandler.h``` and ```ServoHandler.cpp``` files into your Arduino project's library folder.
    -   or copy ```lib_deps = https://github.com/deutzfahrer-luki/ServoHandler.git``` in the ```platformio.ini``` file
-   Include the ```ServoHandler.h``` header file in your sketch.

## API Reference
### Constructor
```ServoHandler(uint8_t pin);```
-   Initializes a servo connected to the specified pin.
-   Uses the default range of 0 to 180 degrees.

```ServoHandler(uint8_t pin, uint8_t startRange, uint8_t endRange);```
-   Initializes a servo with a custom angular range.

### Public Methods
#### Setter for degrees
```void setDegrees(uint8_t degrees);```
-   Sets the desired angle for the servo in degrees.

#### Getter for degrees
```uint8_t getDegrees();```
-   Returns the current angle of the servo.

#### Update the degrees
```void updateDegrees();```
-   Ensures the servo's position is updated if the angle has changed.

#### Calc Duty Cycle
```uint8_t calcDutyCycle(uint8_t degrees);```
-   Computes the duty cycle corresponding to the specified angle.

## Usage Example
```cpp
#include <ServoHandler.h>

// Define the servo pin
#define SERVO_PIN 9

// Create a ServoHandler object
ServoHandler servo(SERVO_PIN, 0, 180);

void setup() {
    Serial.begin(9600);
    servo.setDegrees(90); // Set the servo to 90 degrees
}

void loop() {
    uint8_t currentAngle = servo.getDegrees();
    Serial.println(currentAngle);

    // Change angle dynamically
    servo.setDegrees(45);
    delay(1000);

    servo.setDegrees(135);
    delay(1000);
}
```

## Configuration
-   Default Period Duration: The default period duration for the servo signal is ```20000 µs```. This value can be adjusted by modifying the ```STANDART_PERIOD_DURATION``` macro in the ```ServoHandler.h``` file.

## Dependencies
This library requires the following:
-   ```PWMHandler.h```: A library or class for managing PWM signals. Ensure it is included in your project.

## License
This library is released under the MIT License. Feel free to use, modify, and distribute it in your projects. See the ```LICENSE``` file for details.