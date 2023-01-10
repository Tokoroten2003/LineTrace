#include<Arduino.h>
#include"Sensor/Sens.hpp"
#include"GPIO/AnalogIn.hpp"

namespace sensor {
    class PhotoRefSens : sensor::Sens<uint16_t> {
        private:
            gpio::AnalogIn read_pin;
            uint16_t threshold_value;
        protected:
            uint16_t value;
        public:
            /*delete unexpected constractor*/
            PhotoRefSens() = delete;
            PhotoRefSens(const PhotoRefSens&) = delete;
            PhotoRefSens& operator=(const PhotoRefSens&) = delete;
            PhotoRefSens(const PhotoRefSens&&) = delete;
            PhotoRefSens& operator=(const PhotoRefSens&&) = delete;

            PhotoRefSens(uint8_t read_pin_num);     //ピン番号を指定してコンストラクト
            PhotoRefSens(uint8_t read_pin_num, uint16_t threshold);     //ピン番号、しきい値を指定してコンストラクト

            void init() override;       //setup()内で呼び出す
            uint16_t getValue() override;       //入力値を返す
            void setThreshold(uint16_t threshold);      //しきい値を設定
            uint16_t getThreshold();    //しきい値を返す
            bool compareValue(bool true_if_high = true, bool false_if_equal = true);    //入力値としきい値の比較を返す
    };
}