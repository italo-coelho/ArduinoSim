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
    //Temp
    EEPROM eeprom;
    //

    UI ui;

    ui.header();
    
    String command;
    do
    {
        std::cout << "-> ";
        command = ui.readCommand();   
    
        if(command.has("ajuda") || command.has("Ajuda") || command.has("help"))
        {
            ui.help();
        }

        if(command.has("EEPROM"))
        {
            if(command.has("begin"))
            {
                eeprom.begin(command.findNumber());
            }
            if(command.has("write"))
            {
                eeprom.write(command.betweenQuotes(), command.findNumber());
            }
            if(command.has("read"))
            {
                int pos = command.findNumber();
                char data = eeprom.read(pos);
                if(data != '\0')
                {
                    std::cout << "EEPROM[" << pos << "] = " << data << std::endl;
                }
            }

        }

        if(command.has("pinMode"))
        {   
            int pin = command.findNumber();
            std::cout <<"Pin-->"<<pin<<"\n";

            if(command.has("HIGH"))
            {
                std::cout <<"ON\n";
            }
            else if(command.has("LOW"))
            {
                std::cout <<"OFF\n";
            }
        }

        if(command.has("clear") || command.has("limpa"))
        {
            ui.clear();
            ui.header();
        }
    }
    while(!command.has("exit") && !command.has("sair"));
 
    return 0;
}

