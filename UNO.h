#ifndef UNO_H
#define UNO_H

#include <vector>
#include "pino.h"

namespace prog3{

    class Uno {
    private:
        std::vector<pino> Pinos;
    public:
        Uno();

        pino getPino(int index) const;

    };s
}

#endif
