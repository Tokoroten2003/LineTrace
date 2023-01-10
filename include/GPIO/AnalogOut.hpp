#pragma once
#include <Arduino.h>

namespace gpio {
class AnalogOut {
private:
    double frequency;
    uint8_t resol_bits;
    uint32_t value;

public:
    /*delete unexpected constractors*/
    AnalogOut() = delete;
    AnalogOut(const AnalogOut &) = delete;
    AnalogOut &operator=(const AnalogOut &) = delete;
    AnalogOut(const AnalogOut &&) = delete;
    AnalogOut &operator=(const AnalogOut &&) = delete;

    explicit AnalogOut(
        uint8_t pin, uint8_t pwm_ch, double freq,
        uint8_t resolution_bits =
            8) noexcept; // ピン番号、PWMチャネル、周波数、分解能を指定してコンストラクト

    const uint8_t pin_num;
    const uint8_t pwm_channel;

    void init();                            // setup()内で呼び出す
    void write(uint32_t arg);               // argの値を出力
    uint32_t read();                        // 最後の出力値を返す
    void setFreq(double freq);              // 周波数を設定
    double getFreq();                       // 周波数を返す
    void setResol(uint8_t resolution_bits); // 分解能を設定
    uint8_t getResol(); // 分解能の値(*分解能: 2^(返り値))を返す
};
} // namespace gpio