#include "gpio.h"
#include <iostream>

namespace prog3
{
    gpio::gpio()
    {
        pin = 1;
        function = INPUT;
        protocol = 0;
        value = 0;
    } 

    gpio::gpio(int _pin)
    {   
        if(_pin >= 0)
        {
            pin = _pin;
        }
        else
        {
            ui->print("[gpio]: Invalid pin number\n");
            pin = 0;
        }

        function = INPUT;
        protocol = NONE;
    }

    gpio::gpio(int _pin, int _function)
    {   
        if(_pin >= 0)
        {
            pin = _pin;
        }
        else
        {
            ui->print( "[gpio]: Invalid pin number\n");
            pin = 0;
        }

        if(_function >= 1 && _function <= 5)
        {
            function = _function;
        }
        else
        {
            ui->print("[gpio]: Invalid function - defaulting to INPUT\n");
            function = INPUT;
        }

        if(function == INPUT_PULLUP)
        {
            value = 1023;
        }
        else
        {
            value = 0;
        }

        protocol = NONE;
    }

    gpio::gpio(int _pin, int _function, int _protocol)
    {   
        if(_pin >= 0)
        {
            pin = _pin;
        }
        else
        {
            ui->print("[gpio]: Invalid pin number\n");
            pin = 0;
        }

        if(_function >= 1 && _function <= 5)
        {
            function = _function;
        }
        else
        {
            ui->print("[gpio]: Invalid function - defaulting to INPUT\n");
            function = INPUT;
        }

        if(_protocol >= 0 && _protocol <= 8)
        {
            protocol = _protocol;
        }
        else
        {
            ui->print("[gpio]: Invalid protocol - defaulting to none\n");
            protocol = NONE;
        }

        if(function == INPUT_PULLUP)
        {
            value = 1023;
        }
        else
        {
            value = 0;
        }
    }
      
    //Acessors
    int gpio::getPin()
    {
        return pin;
    }

    int gpio::getFunction()
    {
        return function;
    }

    int gpio::getProtocol()
    {
        return protocol;
    }

    int gpio::getValue()
    {
        return value;
    }

    double gpio::getLoad()
    {
        return load;
    }

    double gpio::getPower()
    {
        if(function == OUTPUT)
        {
            return VOLTAGE*getCurrent();
        }
        else if(function == PWM)
        {
            return VOLTAGE*getCurrent()*(double(value)/255);
        }
        return 0;
    }

    double gpio::getCurrent()
    {
        if(function == OUTPUT || function == PWM)
        {
            double i = double(VOLTAGE)/load;

            if(i <= MAX_CURRENT)
            {
                current = i;
            }
            else
            {
                current = MAX_CURRENT;
            }

            if(value == 0)  //Pin is Off - No Current
            {
                current = 0;
            }

            return current;
        }
        else
        {
            current = 1e-3;
            return current;
        }
    }

    //Mutators
    void gpio::setPin(int _pin)
    {
        if(_pin >= 0)
        {
            pin = _pin;
        }
        else
        {
            ui->print("[gpio]: Invalid pin number\n");
            pin = 0;
        }
    }

    void gpio::setFunction(int _function)
    {
        if(function == _function)
        {
            return;
        }

        if(_function >= 1 && _function <= 5)
        {
            function = _function;
        }
        else
        {
            ui->print("[gpio]: Invalid function - defaulting to INPUT\n");
            function = INPUT;
        }

        if(function == INPUT_PULLUP)
        {
            value = 1023;
        }
    }

    void gpio::setProtocol(int _protocol)
    {
        if(_protocol >= 0 && _protocol <= 7)
        {
            protocol = _protocol;
        }
        else
        {
            ui->print("[gpio]: Invalid protocol - defaulting to none\n");
            protocol = NONE;
        }
    }

    void gpio::setValue(int _value)
    {
        if(function == OUTPUT)
        {
            if(_value == HIGH || _value == LOW)
            {
                value = _value;
            }
            else
            {
                ui->print("[gpio]: Value can only be HIGH or LOW for digital output\n");
            }
        }
        else if(function == PWM)
        {
            if(_value >= 0 && _value <= 255)
            {
                value = _value;
            }
            else
            {
                ui->print("[gpio]: Value out of bounds for PWM [0,255]\n");
            }
        }
        else
        {
            if(_value >= 0 && _value <= 1023)
            {
                if(function == ANALOG)
                {
                    value = _value;
                }
                else //Digital Input
                {
                    if(_value <= 1023/2)
                    {
                        value = 0;  //LOW
                    }
                    else
                    {
                        value = 1023;   //HIGH
                    }
                }
            }
            else
            {
                ui->print("[gpio]: Value out of bounds [0,1023]\n");
            }
        }
    }

    void gpio::setLoad(double _load)
    {
        if(function == OUTPUT || function == PWM)
        {
            if(_load > 0)
            {
                load = _load;
            }
            else
            {
                ui->print("[gpio]: Invalid Load - defaulting to 1kOhm\n");
                load = 1000;
            }
        }
        else
        {
            ui->print("[gpio]: Pin is NOT set to OUTPUT or PWM\n");
            load = 1000;
        }
    }

    void gpio::setUI(UI* _ui)
    {
        ui = _ui;
    }
}