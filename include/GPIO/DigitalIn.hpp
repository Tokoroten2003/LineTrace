#pragma once
#include<Arduino.h>

namespace Gpio {
    class DigitalIn {
        public:
            /*delete unexpected constractors*/
            DigitalIn() = delete;
            DigitalIn(const DigitalIn&) = delete;
            DigitalIn& operator=(const DigitalIn&) = delete;
            DigitalIn(const DigitalIn&&) = delete;
            DigitalIn& operator=(const DigitalIn&&) = delete;

            explicit DigitalIn(uint8_t pin) noexcept;   //ピン番号を指定してコンストラクト

            const uint8_t pin_num;

            void init();    //setup()内で呼び出す
            bool read();    //入力値を返す
    };
}