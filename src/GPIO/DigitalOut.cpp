#include<Arduino.h>
#include"GPIO/DigitalOut.hpp"

Gpio::DigitalOut::DigitalOut(uint8_t pin) noexcept : pin_num(pin) {}

void Gpio::DigitalOut::init() {
    pinMode(pin_num, OUTPUT);
}

void Gpio::DigitalOut::write(bool arg) {
    value = arg;
    digitalWrite(pin_num, value);
}

bool Gpio::DigitalOut::read() {
    return value;
}