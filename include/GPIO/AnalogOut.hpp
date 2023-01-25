#pragma once
#include<Arduino.h>

namespace gpio {
    class AnalogOut {
        private:
            uint8_t pwm_channel;
            uint32_t value;

        public:
            /*delete unexpected constractors*/
            AnalogOut() = delete;
            AnalogOut(const AnalogOut&) = delete;
            AnalogOut& operator=(const AnalogOut&) = delete;
            AnalogOut(const AnalogOut&&) = delete;
            AnalogOut& operator=(const AnalogOut&&) = delete;

            explicit AnalogOut(uint8_t pin, uint8_t pwm_ch, double freq, uint8_t resolution_bits = 8) noexcept;     //ピン番号、PWMチャネル、周波数、分解能を指定してコンストラクト

            const uint8_t pin_num;
            const uint8_t resol_bits;
            const double frequency;

            void init();    //setup()内で呼び出す
            void write(uint32_t arg);   //argの値を出力
            const uint32_t &read() const;    //最後の出力値を返す
            void setFreq(double freq);
            const double &getFreq() const;
    };
}