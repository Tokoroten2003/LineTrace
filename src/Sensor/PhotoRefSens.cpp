#include<Arduino.h>
#include"Sensor/PhotoRefSens.hpp"

Sensor::PhotoRefSens::PhotoRefSens(uint8_t read_pin_num) : read_pin(read_pin_num) {}
Sensor::PhotoRefSens::PhotoRefSens(uint8_t read_pin_num, uint16_t threshold) : read_pin(read_pin_num), threshold_value(threshold) {}

void Sensor::PhotoRefSens::init() {
    read_pin.init();
}

uint16_t Sensor::PhotoRefSens::getValue() {
    return read_pin.read();
}

void Sensor::PhotoRefSens::setThreshold(uint16_t threshold) {
    threshold_value = threshold;
}

uint16_t Sensor::PhotoRefSens::getThreshold() {
    return threshold_value;
}

bool Sensor::PhotoRefSens::compareValue(bool true_if_high, bool false_if_equal) {
    if(true_if_high) {
        if(false_if_equal) {
            return getValue() > threshold_value;
        }
        else {
            return getValue() >= threshold_value;
        }
    }
    else {
        if(false_if_equal) {
            return getValue() < threshold_value;
        }
        else {
            return getValue() <= threshold_value;
        }
     }
}