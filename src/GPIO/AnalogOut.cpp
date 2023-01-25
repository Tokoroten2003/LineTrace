#include<Arduino.h>
#include"GPIO/AnalogOut.hpp"

gpio::AnalogOut::AnalogOut(uint8_t pin, uint8_t pwm_ch, double freq, uint8_t) noexcept :
    pin_num(pin),
    pwm_channel(pwm_ch),
    frequency(freq),
    resolution_bits(resolution_bits) {}

void gpio::AnalogOut::init() {
    pinMode(pin_num, OUTPUT);
    ledcSetup(pwm_channel, frequency, resolution_bits);
    ledcAttachPin(pin_num, pwm_channel);
}

void gpio::AnalogOut::write(uint32_t arg) {
    value = arg;
    ledcWrite(pwm_channel, value);
}

uint32_t gpio::AnalogOut::read() {
    return value;
}