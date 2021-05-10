#ifndef PINO_H
#define PINO_H

#include <string>

namespace prog3{

    //tipos de pinos
    #define SUPPLY_PIN 1
    #define GPIO_PIN 2

    //status
    #define OCUPADO 1
    #define DISPONIVEL 0
    
    class pino{
        int tipo;                                   //gpio ou supply pin
        bool status;                                //ocupado ou disponivel
        int N_pino;                                 //numeracao do pino

    public:
        int getTipo() const;
        bool getStatus() const;
        std::string getLabel() const;

        void setTipo(int tp);
        void setStatus(bool sts);
        void setLabel(std::string lbl)
        
    };
}
#endif