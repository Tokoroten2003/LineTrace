#pragma once
#include<Arduino.h>

namespace gpio {
    class AnalogOut {
        public:
            /*delete unexpected constractors*/
            AnalogOut() = delete;
            AnalogOut(const AnalogOut&) = delete;
            AnalogOut& operator=(const AnalogOut&) = delete;
            AnalogOut(const AnalogOut&&) = delete;
            AnalogOut& operator=(const AnalogOut&&) = delete;

            explicit AnalogOut(uint8_t pin, uint8_t pwm_ch, double freq, uint8_t resolution_bits = 8) noexcept;     //ピン番号、PWMチャネル、周波数、分解能を指定してコンストラクト

            const uint8_t pin_num;
            uint8_t pwm_channel;
            bool frequency;
            uint8_t resolution_bits;
            uint32_t value;

            void init();    //setup()内で呼び出す
            void write(uint32_t arg);   //argの値を出力
            uint32_t read();    //最後の出力値を返す
    };
}