#pragma once
#include<Arduino.h>

namespace Sensor {
    template<typename valT> class Sens {
        protected:
            valT value;
        public:
            virtual void init();
            virtual valT getValue();
    };
}