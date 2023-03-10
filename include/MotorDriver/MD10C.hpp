#pragma once
#include<Arduino.h>
#include"MotorDriver/MD.hpp"
#include"GPIO/AnalogOut.hpp"
#include"GPIO/DigitalOut.hpp"

namespace MotorDriver {
    class MD10C : MotorDriver::MD<int16_t> {
        private:
            Gpio::AnalogOut pwm;
            Gpio::DigitalOut dir;
            bool use_dir_pin;
        protected:
            int16_t power;
        public:
            /*delete unexpected constractors*/
            MD10C() = delete;
            MD10C(const MD10C&) = delete;
            MD10C& operator=(const MD10C&) = delete;
            MD10C(const MD10C&&) = delete;
            MD10C& operator=(const MD10C&&) = delete;

            MD10C(uint8_t pwm_pin, uint8_t pwm_ch);
            MD10C(uint8_t pwm_pin, uint8_t pwm_ch, uint8_t dir_pin, bool usage_dir = true);

            void init() override;   //setup()内で呼び出す
            void setPower(int16_t pow = 0) override;    //powerの値を設定
            int16_t getPower() override;    //powerの値を返す
            void run() override;    //powerの値を出力
    };
}