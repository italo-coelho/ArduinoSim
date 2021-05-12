#include "pino.h"

namespace prog3
{

    pino::pino(gpio _port)
    {
        sensor = nullptr;
        port = _port;
    }

    pino::pino(supply _power)
    {
        power = _power;
    }

    int pino::getTipo()
    {
        sensor = nullptr;
        return tipo;
    }

    bool pino::getStatus()
    {
        return status;
    }

    std::string pino::getLabel()
    {
        return label;
    }

    void pino::setTipo(int tp)
    {
        if(tp == SUPPLY_PIN || tp == GPIO_PIN)
        {
            tipo = tp;
        }
    }

    void pino::setStatus(bool sts)
    {
        status = sts;
    }

    void pino::setLabel(std::string lbl)
    {
        label = lbl;
    }

    int pino::getPin() {return port.getPin();}
    double pino::getValue()
    {
        if(sensor != nullptr )
        {
            return sensor->getValue();
        }

        return port.getValue();
    }
    int pino::getFunction(){return port.getFunction();}
    int pino::getProtocol(){return port.getProtocol();}
    void pino::setUI(UI* _ui) {port.setUI(_ui);}
    void pino::setPin(int _pin) {port.setPin(_pin);}
    void pino::setValue(int _value) { port.setValue(_value);}
    void pino::setFunction(int _function) {port.setFunction(_function);}
    void pino::setProtocol(int _protocol) {port.setProtocol(_protocol);}

    void pino::setSensor(Sensor* _sensor)
    {
        sensor = _sensor;
    }

    Sensor* pino::getSensor()
    {
        return sensor;
    }
}
