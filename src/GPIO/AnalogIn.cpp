#include<Arduino.h>
#include"GPIO/AnalogIn.hpp"

Gpio::AnalogIn::AnalogIn(uint8_t pin) : pin_num(pin) {}

void Gpio::AnalogIn::init() {
    pinMode(pin_num, INPUT);
}

uint16_t Gpio::AnalogIn::read() {
    return analogRead(pin_num);
}