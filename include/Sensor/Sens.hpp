#pragma once
#include <Arduino.h>

namespace sensor {
template <typename ValT> class Sens {
public:
    virtual void init();
    virtual ValT getValue() const;
};
} // namespace sensor