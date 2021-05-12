#ifndef SENSOR_H
#define SENSOR_H

#include <string>
#include <vector>
#include "pino.h"

namespace prog3
{   
    enum protocolo {SPI = 1, I2C = 2, UART = 3};
    enum tipos_sensor {TEMPERATURA, PRESSAO, UMIDADE};

    class Sensor
    {
    private:
        
        
        std::vector<pino> Pinos;
        int Tipo;
        int Protocolo;

    public:
        Sensor();
        Sensor(int tipo);
        Sensor(int protocolo, int tipo);

        double getValue()const;
        int getTipo()const;
        int getProtocolo()const;
        std::string getPinos();
};

}

#endif