#ifndef PINO_H
#define PINO_H

#include <string>

namespace prog3
{
    //tipos de pinos
    constexpr SUPPLY_PIN 1
    constexpr GPIO_PIN 2

    //status
    constexpr OCUPADO true
    constexpr DISPONIVEL false
    
    class pino
    {
        int tipo;                                   //gpio ou supply pin
        bool status;                                //ocupado ou disponivel
        int N_pino;                                 //numeracao do pino
        std::string label;                          //Nome do pino

    public:
        int getTipo();
        bool getStatus();
        std::string getLabel();

        void setTipo(int tp);
        void setStatus(bool sts);
        void setLabel(std::string lbl);
    };
}

#endif