#ifndef UNO_H
#define UNO_H

#include <vector>

#include "ui.h"
#include "pino.h"
#include "EEPROM.h"
#include "Timer.h"

namespace prog3{

    class Uno 
    {
    private:
        std::vector<pino> pinD;
        std::vector<pino> pinA;
        std::vector<pino> pinS;

        EEPROM eeprom;
        Timer timer;
        

        UI* ui;
        // friend class UI;

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

        double millis();

        void setUI(UI* _ui);
    };
}

#endif
