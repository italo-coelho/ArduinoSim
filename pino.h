#ifndef PINO_H
#define PINO_H

#include <string>

namespace prog3
{
    //tipos de pinos
    enum tipos_pinos
    {
        SUPPLY_PIN=1,
        GPIO_PIN=2
    };  

    //status
    enum status
    {
        OCUPADO=0,
        DISPONIVEL=1
    };

    
    class pino
    {
        int tipo;                                   //gpio ou supply pin
        bool status=DISPONIVEL;                                //ocupado ou disponivel
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