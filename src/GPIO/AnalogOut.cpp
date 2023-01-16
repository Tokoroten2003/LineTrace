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
const uint32_t &gpio::AnalogOut::read() const { return value; }
void gpio::AnalogOut::setFreq(double freq) { frequency = freq; }
const double &gpio::AnalogOut::getFreq() const { return frequency; }
