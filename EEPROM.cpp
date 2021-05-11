#include "EEPROM.h"

#include <iostream>
#include "ui.h"

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
    bool EEPROM::begin(int _size, UI& interface)
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
                interface.print ("[EEPROM]: Invalid memory size\n");
                return false;
            }
        }
        else
        {
            std::cout << "[EEPROM]: Memory was already started\n";
            return false;
        }
    }

    char EEPROM::read(int _position)
    {
        if(vector == nullptr)
        {
            std::cout << "[EEPROM]: Memory was not started, first use the 'begin' method\n";
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
                std::cout << "[EEPROM]: Position is out of bounds [0, " << size-1 <<"]\n";
                return '\0';
            }
        }
    }

    void EEPROM::write(char _data, int _position)
    {
        if(vector == nullptr)
        {
            std::cout << "[EEPROM]: Memory was not started, first use the 'begin' method\n";
        }
        else
        {
            if(_position >= 0 && _position < size)
            {
                vector[_position] = _data;
            }
            else
            {
                std::cout << "[EEPROM]: Position is out of bounds [0, " << size-1 <<"]\n";
            }
        }
    }









}
