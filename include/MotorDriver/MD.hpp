#pragma once
#include<Arduino.h>

namespace MotorDriver {
    template<typename PowT> class MD {
        protected:
            PowT power;
        public:
            virtual void init();
            virtual void setPower(PowT);
            virtual PowT getPower();
            virtual void run();
    };
}