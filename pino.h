#ifndef PINO_H
#define PINO_H

#include "gpio.h"
#include <string>

namespace prog3
{
    //tipos de pinos
    #define SUPPLY_PIN 1
    #define GPIO_PIN 2

    //status
    #define OCUPADO 1
    #define DISPONIVEL 0
    
    class pino
    {
    private:
        int tipo;                                   //gpio ou supply pin
        bool status;                                //ocupado ou disponivel
        int N_pino;                                 //numeracao do pino
        std::string label;                          //Nome do pino
        gpio port;

    public:
        pino(gpio _port);

        int getTipo();
        bool getStatus();
        std::string getLabel();

        void setTipo(int tp);
        void setStatus(bool sts);
        void setLabel(std::string lbl);

        //GPIO functions;
        int getPin();
        int getValue();
        int getFunction();
        int getProtocol();
        void setUI(UI* _ui);
        void setPin(int _pin);
        void setValue(int _value);
        void setFunction(int _function);
        void setProtocol(int _protocol);

    };
}

#endif