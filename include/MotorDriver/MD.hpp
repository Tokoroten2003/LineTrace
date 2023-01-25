#pragma once
#include <Arduino.h>

namespace motorDriver {
template <typename PowT> class MD {
protected:
    PowT power;

public:
    virtual void init() = 0;
    virtual void setPower(PowT) = 0;
    virtual PowT getPower() = 0;
    virtual void run() = 0;
};
} // namespace motorDriver