#include "gpio.h"
#include <iostream>

using namespace std;
using namespace prog3;

int main()
{
    gpio porta1( 1, PWM);

    double load;
    cout << "Digite a carga em Ohms: ";
    cin >> load;

    porta1.setLoad(load);
    porta1.setValue(255);
    cout << "Corrente: " << porta1.getCurrent()*1000 << "mA" << endl;
    cout << "Potencia: " << porta1.getPower()*1000 << "mW" << endl;

    return 0;
}