#include<Arduino.h>
#include"Sensor/PhotoRefSens.hpp"

sensor::PhotoRefSens::PhotoRefSens(uint8_t read_pin_num) : read_pin(read_pin_num) {}
sensor::PhotoRefSens::PhotoRefSens(uint8_t read_pin_num, uint16_t threshold) : read_pin(read_pin_num), threshold_value(threshold) {}

void sensor::PhotoRefSens::init() {
    read_pin.init();
}

uint16_t sensor::PhotoRefSens::getValue() {
    return read_pin.read();
}

void sensor::PhotoRefSens::setThreshold(uint16_t threshold) {
    threshold_value = threshold;
}

uint16_t sensor::PhotoRefSens::getThreshold() {
    return threshold_value;
}

bool sensor::PhotoRefSens::compareValue(bool true_if_high, bool false_if_equal) {
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