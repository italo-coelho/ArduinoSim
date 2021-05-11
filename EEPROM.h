#ifndef EEPROM_H
#define EEPROM_H

#include "ui.h"

namespace prog3
{
    class EEPROM
    {
    public:
        EEPROM();
        ~EEPROM();

        void setUI(UI* ui);

        bool begin(int _size);
        char read(int _position);
        void write(char _data, int _position);

    private:
        int size;
        char* vector;

        UI* ui;
    }; 
}

#endif