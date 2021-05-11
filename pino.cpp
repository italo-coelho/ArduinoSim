#include "pino.h"

namespace prog3
{
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
}
