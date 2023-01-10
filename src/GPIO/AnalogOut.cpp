#include "GPIO/AnalogOut.hpp"
#include <Arduino.h>

gpio::AnalogOut::AnalogOut(uint8_t pin, uint8_t pwm_ch, double freq,
                           uint8_t resolution_bits) noexcept
    : pin_num(pin), pwm_channel(pwm_ch), frequency(freq),
      resol_bits(resolution_bits) {}

void gpio::AnalogOut::init() {
    pinMode(pin_num, OUTPUT);
    ledcSetup(pwm_channel, frequency, resol_bits);
    ledcAttachPin(pin_num, pwm_channel);
}

void gpio::AnalogOut::write(uint32_t arg) {
    value = arg;
    ledcWrite(pwm_channel, value);
}

uint32_t gpio::AnalogOut::read() { return value; }

void gpio::AnalogOut::setFreq(double freq) { frequency = freq; }

double gpio::AnalogOut::getFreq() { return frequency; }

void gpio::AnalogOut::setResol(uint8_t resolution_bits) {
    resol_bits = resolution_bits;
}

uint8_t gpio::AnalogOut::getResol() { return resol_bits; }