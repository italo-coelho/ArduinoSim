#include "supply.h"

namespace prog3
{
    supply::supply(){}
    supply::supply(int _function){ function = _function;}
    double supply::getCurrent(){ return 0;}
    int supply::getFunction(){ return 0;}
    void supply::setFunction(int _function){function = _function;}
    void supply::setLoad(double _load){load = _load;}
    void supply::setMaxCurrent(double _maxCurrent){maxCurrent = _maxCurrent;}
}