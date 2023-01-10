#include "Sensor/PhotoRefSens.hpp"
#include <Arduino.h>

sensor::PhotoRefSens::PhotoRefSens(uint8_t read_pin_num)
    : read_pin(read_pin_num) {}
sensor::PhotoRefSens::PhotoRefSens(uint8_t read_pin_num, uint16_t threshold)
    : read_pin(read_pin_num), threshold_value(threshold) {}

void sensor::PhotoRefSens::init() { read_pin.init(); }

uint16_t sensor::PhotoRefSens::getValue() { return read_pin.read(); }

void sensor::PhotoRefSens::setThreshold(uint16_t threshold) {
    threshold_value = threshold;
}

uint16_t sensor::PhotoRefSens::getThreshold() { return threshold_value; }

int8_t sensor::PhotoRefSens::compareValue() {
    if (getValue() < threshold_value) {
        return -1;
    } else if (getValue() == threshold_value) {
        return 0;
    } else {
        return 1;
    }
}