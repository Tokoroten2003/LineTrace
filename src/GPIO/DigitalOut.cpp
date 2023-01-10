#include<Arduino.h>
#include"GPIO/DigitalOut.hpp"

gpio::DigitalOut::DigitalOut(uint8_t pin) noexcept : pin_num(pin) {}

void Gpio::DigitalOut::init() {
    pinMode(pin_num, OUTPUT);
}

void gpio::DigitalOut::write(bool arg) {
    value = arg;
    digitalWrite(pin_num, value);
}

bool gpio::DigitalOut::read() {
    return value;
}