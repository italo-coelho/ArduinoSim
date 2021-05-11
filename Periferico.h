#ifndef PERIFERICO_H
#define PERIFERICO_H

#include <vector>
#include "pino.h"

namespace prog3{

    //protocolos
    #define UART 1
    #define SPI 2
    #define I2C 3

    //tipo
    #define SENSOR_TEMP 1
    #define GPS 2
    #define SENSOR_LUMINOSIDADE 3

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