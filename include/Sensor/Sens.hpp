#pragma once
#include<Arduino.h>

namespace sensor {
    template<typename valT> class Sens {
        protected:
            valT value;
        public:
            virtual void init();
            virtual valT getValue();
    };
}