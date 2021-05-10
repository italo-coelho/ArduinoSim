#include "EEPROM.h"

#include <iostream>

namespace prog3
{
    //Constructor
    EEPROM::EEPROM()
    {
        vector = NULL;
        size = 0;
    }

    EEPROM::~EEPROM()
    {
        if(vector != NULL)
        {
            delete [] vector;
        }
    }

    //Methods
    bool EEPROM::begin(int _size)
    {
        if(vector == NULL)
        {
            if(_size >= 0 && _size <= 1e5)
            {
                size = _size;
                vector = new char[size];
                return true;
            }
            else
            {
                std::cout << "[EEPROM]: Invalid memory size\n";
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
        if(vector == NULL)
        {
            std::cout << "[EEPROM]: Memory was not started, first use the 'begin' method\n";
        }
        else
        {
            if(_position >= 0 && _position <= size)
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
        if(vector == NULL)
        {
            std::cout << "[EEPROM]: Memory was not started, first use the 'begin' method\n";
        }
        else
        {
            if(_position >= 0 && _position <= size)
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
