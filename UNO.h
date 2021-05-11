#ifndef UNO_H
#define UNO_H

#include <vector>

#include "pino.h"
#include "EEPROM.h"

namespace prog3{

    class Uno 
    {
    private:
        std::vector<pino> pinD;
        std::vector<pino> pinA;
        std::vector<pino> pinS;

        EEPROM eeprom;
    public:
        Uno();

        pino getPinD(int index);
        pino getPinA(int index);

        int analogRead(int _pin);
        int digitalRead(int _pin);
        void pinMode(int _pin, int _mode);
        void analogWrite(int _pin, int _state);
        void digitalWrite(int _pin, int _state);
        
        void EEPROMbegin(int _size);
        void EEPROMwrite(int _pos, char _data);
        char EEPROMread(int _pos);

    };
}

#endif
