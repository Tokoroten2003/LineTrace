#include<Arduino.h>
#include"GPIO/DigitalIn.hpp"

Gpio::DigitalIn::DigitalIn(uint8_t pin) noexcept : pin_num(pin) {}

void Gpio::DigitalIn::init() {
    pinMode(pin_num, INPUT);
}

bool Gpio::DigitalIn::read() {
    return digitalRead(pin_num);
}