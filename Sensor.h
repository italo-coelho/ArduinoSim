#ifndef SENSOR_H
#define SENSOR_H

#include <string>
#include <vector>



namespace prog3
{   
    enum protocolo {SPI = 1, I2C = 2, UART = 3};
    enum tipos_sensor {TEMPERATURA = 1, PRESSAO = 2, UMIDADE = 3};

    class Sensor
    {
    private:
    
        int Tipo;
        int Protocolo;

    public:
        Sensor();
        Sensor(int tipo);
        Sensor(int tipo, int protocolo);

        double getValue()const;
        int getTipo()const;
        int getProtocolo()const;

};

}

#endif