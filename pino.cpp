#include "pino.h"

#include "gpio.h"

namespace prog3
{

    pino::pino(gpio _port)
    {
        port = _port;
    }

    int pino::getTipo()
    {
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
    int pino::getValue(){return port.getValue();}
    int pino::getFunction(){return port.getFunction();}
    int pino::getProtocol(){return port.getProtocol();}
    void pino::setPin(int _pin) {port.setPin(_pin);}
    void pino::setValue(int _value) { port.setValue(_value);}
    void pino::setFunction(int _function) {port.setFunction(_function);}
    void pino::setProtocol(int _protocol) {port.setProtocol(_protocol);}
}
