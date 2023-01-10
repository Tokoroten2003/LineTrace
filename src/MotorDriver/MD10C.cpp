#include "MotorDriver/MD10C.hpp"
#include <Arduino.h>

motorDriver::MD10C::MD10C(uint8_t pwm_pin, uint8_t pwm_ch)
    : pwm(pwm_pin, pwm_ch, 20000), dir(0), use_dir_pin(false) {}
motorDriver::MD10C::MD10C(uint8_t pwm_pin, uint8_t pwm_ch, uint8_t dir_pin,
                          bool usage_dir)
    : pwm(pwm_pin, pwm_ch, 20000), dir(dir_pin), use_dir_pin(usage_dir) {}

void motorDriver::MD10C::init() {
    pwm.init();
    dir.init();
    setPower();
}

void motorDriver::MD10C::setPower(int16_t pow) { power = pow; }

int16_t motorDriver::MD10C::getPower() { return power; }

void motorDriver::MD10C::run() {
    if (use_dir_pin) {
        pwm.write(abs(power));
        dir.write(power >= 0);
    } else {
        pwm.write(128 + int(power / 2));
    }
}