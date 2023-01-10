#include "GPIO/AnalogIn.hpp"
#include <Arduino.h>

gpio::AnalogIn::AnalogIn(uint8_t pin) : pin_num(pin) {}

void gpio::AnalogIn::init() { pinMode(pin_num, INPUT); }

uint16_t gpio::AnalogIn::read() { return analogRead(pin_num); }