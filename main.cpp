#include "ui.h"
#include "gpio.h"
#include "EEPROM.h"
#include "String.h"

#include <string>
#include <stdio.h>
#include <sstream>
#include <iostream>
#include <cctype>
#include <algorithm>

using namespace prog3;
using namespace std;

int main()
{
    UI ui;

    ui.header();
    
    String command;
    do
    {
        std::cout << "-> ";
        command = ui.readCommand();   
        ui.parseCommand(command);
    }
    while(!command.has("exit") && !command.has("sair"));

    return 0;
}

