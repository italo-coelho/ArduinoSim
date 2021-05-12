#ifndef PERIFERICO_H
#define PERIFERICO_H

#include <vector>
#include "pino.h"

namespace prog3{

    enum Protocolos { UART  = 1,
                      SPI   = 2,
                      I2C   = 3};

    enum Tipos { SENSOR_TEMP            = 1,
                 GPS                    = 2,
                 SENSOR_LUMINOSIDADE    = 3};
                 
    class periferico
    {
    public:
        periferico();
        periferico(int _prot);
        periferico()
    private:
        int protocolo;
        std::vector<pino> pinos;
        int tipo;
    }

}