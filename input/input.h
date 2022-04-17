/** @file */
#ifdef ARDUINO
#include <Arduino.h>
#else
#define HIGH 0x1
#define LOW  0x0
#define INPUT 0x0
#define OUTPUT 0x1
void pinMode(uint8_t pin, uint8_t mode) {}
void digitalWrite(uint8_t pin, uint8_t mode) {}
int digitalRead(uint8_t pin) { return 0; }
unsigned long millis() { return 0; }
int analogRead(uint8_t pin) { return 0; }
#endif

#ifndef INPUT_H
#define INPUT_H

#include <stdint.h>


class AbstractInputHandler
{
    public:
    uint8_t pin_;

    AbstractInputHandler(uint8_t pin) {
        pin_ = pin;
    }

    virtual void setup(void) = 0;
    virtual void update(void) = 0;

    virtual void setPinMode(uint8_t mode) {
        pinMode(pin_, mode);
    };

    virtual void writeDigital(uint8_t value) {
        digitalWrite(pin_, value);
    };

    virtual int readDigital() {
        return digitalRead(pin_);
    };

    virtual unsigned long getTimestamp() {
        return millis();
    };

    virtual int readAnalog() {
        return analogRead(pin_);
    };
};
#endif
