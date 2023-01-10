#include<Arduino.h>
#include"GPIO/DigitalIn.hpp"

gpio::DigitalIn::DigitalIn(uint8_t pin) noexcept : pin_num(pin) {}

void gpio::DigitalIn::init() {
    pinMode(pin_num, INPUT);
}

bool gpio::DigitalIn::read() {
    return digitalRead(pin_num);
}