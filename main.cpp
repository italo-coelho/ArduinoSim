#include "ui.h"
#include "UNO.h"
#include "gpio.h"
#include "pino.h"
#include "EEPROM.h"
#include "String.h"

#include <cctype>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace prog3;

int main()
{
    UI ui;                  //Objeto de Interface - Linha de Comando
    String command;         //Objeto de manipulação de Strings - Comandos
    Uno arduino;            //Objeto Arduino Uno

    arduino.setUI(&ui);     //Especifica a classe responsável por imprimir as informações para o usuário

    ui.show();              //Mostra a interface
    
    do
    {
        // std::cout << "-> ";
        ui.print("-> ");
        command = ui.readCommand();
        ui.print(command.cppString() + "\n");   
    
        if(command.has("ajuda") || command.has("Ajuda") || command.has("help"))
        {
            ui.help();
        }

        if(command.has("EEPROM") || command.has("eeprom"))
        {
            if(command.has("begin"))
            {
                arduino.EEPROMbegin(command.findNumber());
            }
            if(command.has("write"))
            {
                arduino.EEPROMwrite(command.findNumber(), command.betweenQuotes());
            }
            if(command.has("read"))
            {
                int pos = command.findNumber();
                char data = arduino.EEPROMread(pos);
                if(data != '\0')
                {
                    // std::cout << "EEPROM[" << pos << "] = " << data << std::endl;
                    ui.print("EEPROM[" + std::to_string(pos) + "] = " + data + "\n");
                }
            }

        }

        if(command.has("pinMode"))
        {   
            int pin = command.findNumber();
            
            if(command.has("INPUT_PULLUP"))
            {
                arduino.pinMode(pin, INPUT_PULLUP);
            } 
            else if(command.has("INPUT"))
            {
                arduino.pinMode(pin, INPUT);
            }
            else if(command.has("OUTPUT"))
            {
                arduino.pinMode(pin, OUTPUT);
            }
        }

        if(command.has("digitalWrite"))
        {   
            int pin = command.findNumber();
            
            if(command.has("HIGH"))
            {
                arduino.digitalWrite(pin, HIGH);
            }
            else if(command.has("LOW"))
            {
                arduino.digitalWrite(pin, LOW);
            }
            else
            {
                ui.print("[digitalWrite]: Can only write HIGH or LOW\n");
            }
        }

        if(command.has("analogWrite"))
        {   
            String pinStr(command.subString(0, command.indexOf(",")));
            String valueStr(command.subString(command.indexOf(",")));

            int pin = pinStr.findNumber();
            int value = valueStr.findNumber();

            arduino.pinMode(pin, PWM);
            arduino.analogWrite(pin, value);
        }

        if(command.has("analogRead"))
        {   
            int pin = command.findNumber();            
            // std::cout <<"Pino[" << pin << "] = " << /*estado do pino << */"\n";
            ui.print("Pino[A" + std::to_string(pin) + "] = " + std::to_string(arduino.analogRead(pin)) + "\n");
        }

        if(command.has("digitalRead"))
        {   
            int pin = command.findNumber();
            // std::cout <<"Pino[" << pin << "] = " << /*estado do pino << */"\n";
            if(arduino.digitalRead(pin) == 1023)
            {
                ui.print("Pino[D" + std::to_string(pin) + "] = " + "HIGH" + "\n");
            }
            else if (arduino.digitalRead(pin) == 0)
            {
                ui.print("Pino[D" + std::to_string(pin) + "] = " + "LOW" + "\n");
            }
        }

        if(command.has("clear") || command.has("limpa"))
        {
            ui.clearConsole();
        }
    }
    while(!command.has("exit") && !command.has("sair"));
 
    return 0;
}

