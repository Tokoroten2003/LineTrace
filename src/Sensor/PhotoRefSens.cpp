#include "Sensor/PhotoRefSens.hpp"

#include <Arduino.h>

sensor::PhotoRefSens::PhotoRefSens(uint8_t read_pin_num) : read_pin(read_pin_num) {}
sensor::PhotoRefSens::PhotoRefSens(uint8_t read_pin_num, uint16_t threshold) :
    read_pin(read_pin_num), threshold_value(threshold) {}
void sensor::PhotoRefSens::init() { read_pin.init(); }
uint16_t sensor::PhotoRefSens::getValue() const { return read_pin.read(); }
void sensor::PhotoRefSens::setThreshold(uint16_t threshold) { threshold_value = threshold; }
const uint16_t& sensor::PhotoRefSens::getThreshold() const { return threshold_value; }
int8_t sensor::PhotoRefSens::compareValue() {
    uint16_t v = getValue();
    if (v < threshold_value) {
        return -1;
    } else if (v == threshold_value) {
        return 0;
    } else {
        return 1;
    }
}
