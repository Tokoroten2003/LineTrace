#pragma once
#include <Arduino.h>

namespace sensor {
template <typename ValT> class Sens {
public:
    virtual void init() = 0;
    virtual ValT getValue() const = 0;
};
} // namespace sensor