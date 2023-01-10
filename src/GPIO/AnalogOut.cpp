#include<Arduino.h>
#include"GPIO/AnalogOut.hpp"

Gpio::AnalogOut::AnalogOut(uint8_t pin, uint8_t pwm_ch, double freq, uint8_t) noexcept :
    pin_num(pin),
    pwm_channel(pwm_ch),
    frequency(freq),
    resolution_bits(resolution_bits) {}

void Gpio::AnalogOut::init() {
    pinMode(pin_num, OUTPUT);
    ledcSetup(pwm_channel, frequency, resolution_bits);
    ledcAttachPin(pin_num, pwm_channel);
}

void Gpio::AnalogOut::write(uint32_t arg) {
    value = arg;
    ledcWrite(pwm_channel, value);
}

uint32_t Gpio::AnalogOut::read() {
    return value;
}