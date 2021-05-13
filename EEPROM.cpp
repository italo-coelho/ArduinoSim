#include "EEPROM.h"

namespace prog3
{
    //Constructor
    EEPROM::EEPROM()
    {
        vector = nullptr;
        size = 0;
    }

    EEPROM::~EEPROM()
    {
        if(vector != nullptr)
        {
            delete [] vector;
        }
    }

    //Methods
    bool EEPROM::begin(int _size)
    {
        if(vector == nullptr)
        {
            if(_size >= 0 && _size <= 1e5)
            {
                size = _size;
                vector = new char[size];
                int i;
                for(i = 0; i < size; i++)
                {
                    vector[i] = '0';
                }
                return true;
            }
            else
            {
                ui->print("[EEPROM]: Invalid memory size\n");
                return false;
            }
        }
        else
        {
            ui->print("[EEPROM]: Memory was already started\n");
            return false;
        }
    }

    char EEPROM::read(int _position)
    {
        if(vector == nullptr)
        {
            ui->print("[EEPROM]: Memory was not started, first use the 'begin' method\n");
            return '\0';
        }
        else
        {
            if(_position >= 0 && _position < size)
            {
                return vector[_position];
            }
            else
            {
                ui->print("[EEPROM]: Position is out of bounds [0, " + std::to_string(size-1) + "]\n");
                return '\0';
            }
        }
    }

    void EEPROM::write(char _data, int _position)
    {
        if(vector == nullptr)
        {
            ui->print("[EEPROM]: Memory was not started, first use the 'begin' method\n");
        }
        else
        {
            if(_position >= 0 && _position < size)
            {
                vector[_position] = _data;
            }
            else
            {
                ui->print("[EEPROM]: Position is out of bounds [0, " + std::to_string(size-1) + "]\n");
            }
        }
    }

    void EEPROM::setUI(UI* _ui)
    {
        ui = _ui;
    }
}