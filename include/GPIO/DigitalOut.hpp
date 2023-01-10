#pragma once
#include<Arduino.h>

namespace gpio {
    class DigitalOut {
        public:
            /*delete unexpected constractors*/
            DigitalOut() = delete;
            DigitalOut(const DigitalOut &) = delete;
            DigitalOut &operator=(const DigitalOut &) = delete;
            DigitalOut(const DigitalOut &&) = delete;
            DigitalOut &operator=(const DigitalOut &&) = delete;

            explicit DigitalOut(uint8_t pin) noexcept;  //ピン番号を指定してコンストラクト

            const uint8_t pin_num;
            bool value;

            void init();    //setup()内で呼び出す
            void write(bool arg);   //argの値を出力
            bool read();    //最後の出力値を返す
    };
}