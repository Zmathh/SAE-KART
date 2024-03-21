#ifndef LM74_V2_H
#define LM74_V2_H

#include "Arduino.h"
#include "shiftReg.cpp"

class LM74 {
    public:
        LM74(shiftReg &shiftRegister);

        void begin();

        float read(int selecteur);

    private:
        shiftReg &shiftRegister;
};

#endif
