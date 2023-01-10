#pragma once
#include <Arduino.h>

namespace sensor {
template <typename valT> class Sens {
public:
    virtual void init();
    virtual valT getValue();
};
} // namespace sensor