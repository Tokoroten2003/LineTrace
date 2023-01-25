#pragma once
#include <Arduino.h>

namespace gpio {
class AnalogIn {
public:
    /*delete unexpected constractors*/
    AnalogIn() = delete;
    AnalogIn(const AnalogIn &) = delete;
    AnalogIn &operator=(const AnalogIn &) = delete;
    AnalogIn(const AnalogIn &&) = delete;
    AnalogIn &operator=(const AnalogIn &&) = delete;

    AnalogIn(uint8_t pin); // ピン番号を指定してコンストラクト

    const uint8_t pin_num;
    void init();    //setup()内で呼び出す
    uint16_t read() const;    //入力値を返す
};
}