#include "Sensor.h"

#include <random>

namespace prog3
{
    Sensor::Sensor()
    {
        Tipo = TEMPERATURA;
        Protocolo = SPI;
    }

    Sensor::Sensor (int tipo)
    {
        Tipo = tipo;
        Protocolo = SPI;
    }

    Sensor::Sensor (int tipo, int protocolo)
    {
        Tipo = tipo;
        Protocolo = protocolo;
    }

    double Sensor::getValue() const
    {   
        std::random_device gerador;

        if(Tipo==TEMPERATURA)
        {   
            std::uniform_real_distribution<double> temp_range(20.0, 25.0);
            return temp_range(gerador);

        }
        else if(Tipo==PRESSAO)
        {   
            std::uniform_real_distribution<double> press_range(1010.0, 1050.0);
            return press_range(gerador);
            
        }
        else if(Tipo==UMIDADE)
        {   
            std::uniform_real_distribution<double> humidity_range(50.0, 100.0);
            return humidity_range(gerador);
        }

        return 0;
    }

    int Sensor::getTipo() const {return Tipo;}

    int Sensor::getProtocolo() const {return Protocolo;}

    void Sensor::setTipo(int tipo){Tipo=tipo;}

    void Sensor::setProtocolo(int protocolo){Protocolo=protocolo;}
}