#include "GPIO/AnalogIn.hpp"
#include "Sensor/Sens.hpp"
#include <Arduino.h>

namespace sensor {
class PhotoRefSens : sensor::Sens<uint16_t> {
private:
    gpio::AnalogIn read_pin;
    uint16_t threshold_value;

public:
    /*delete unexpected constractor*/
    PhotoRefSens() = delete;
    PhotoRefSens(const PhotoRefSens &) = delete;
    PhotoRefSens &operator=(const PhotoRefSens &) = delete;
    PhotoRefSens(const PhotoRefSens &&) = delete;
    PhotoRefSens &operator=(const PhotoRefSens &&) = delete;

    PhotoRefSens(uint8_t read_pin_num); // ピン番号を指定してコンストラクト
    PhotoRefSens(
        uint8_t read_pin_num,
        uint16_t threshold); // ピン番号、しきい値を指定してコンストラクト

    void init() override;                  // setup()内で呼び出す
    uint16_t getValue() const override;          // 入力値を返す
    void setThreshold(uint16_t threshold); // しきい値を設定
    const uint16_t &getThreshold() const;               // しきい値を返す
    int8_t compareValue(); // 入力値としきい値の比較を返す
};
} // namespace sensor