#include "ui.h"
#include "UNO.h"
#include "Frase.h"

using namespace prog3;

int main()
{
    UI ui;                  //Objeto de Interface - Linha de Comando
    Frase command;          //Objeto de manipulação de Frases - Comandos
    UNO arduino;            //Objeto Arduino Uno

    arduino.setUI(&ui);     //Especifica a classe responsável por imprimir as informações para o usuário

    ui.show();              //Mostra a interface
    ui.print("Bem-Vindo ao Simulador de Arduino! Digite 'ajuda' para ver a lista de comandos.\n\n");
    
    do
    {
        ui.print("-> ");
        command = ui.readCommand();
        ui.print(command.cppFrase() + "\n");   
    
        if(command.has("ajuda") || command.has("Ajuda") || command.has("help"))
        {
            ui.help();
        }

        if(command.has("millis"))
        {
            ui.print("Milliseconds = " + std::to_string(arduino.millis()) + "\n");
        }

        if(command.has("seconds"))
        {
            ui.print("Seconds = " + std::to_string(arduino.seconds()) + "\n");
        }
        
        if (command.has("getRTC"))
        {
            ui.print(arduino.getRTC());
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
            Frase pinStr(command.subFrase(0, command.indexOf(",")));
            Frase valueStr(command.subFrase(command.indexOf(",")));

            int pin = pinStr.findNumber();
            int value = valueStr.findNumber();

            arduino.pinMode(pin, PWM);
            arduino.analogWrite(pin, value);
        }

        if(command.has("analogRead"))
        {   
            int pin = command.findNumber();            
            ui.print("Pino[A" + std::to_string(pin) + "] = " + std::to_string(arduino.analogRead(pin)) + "\n");
        }

        if(command.has("digitalRead"))
        {   
            int pin = command.findNumber();
            if(arduino.digitalRead(pin) == 1023)
            {
                ui.print("Pino[D" + std::to_string(pin) + "] = " + "HIGH" + "\n");
            }
            else if (arduino.digitalRead(pin) == 0)
            {
                ui.print("Pino[D" + std::to_string(pin) + "] = " + "LOW" + "\n");
            }
        }

        if(command.has("disconnectSensor") || command.has("dettachSensor"))
        {
            int pin = command.findNumber();
            arduino.disconnectSensor(pin);
        }
        else if(command.has("connectSensor") || command.has("attachSensor"))
        {
            int pin = command.findNumber();
            
            int protocol = SPI;
            if(command.has("SPI"))
            {
                protocol = SPI;
            }
            else if(command.has("I2C"))
            {
                protocol = I2C;
            }
            else if(command.has("UART"))
            {
                protocol = UART;
            }
            
            int type = 0;
            if(command.has("TEMP"))
            {
                type = TEMPERATURA;
            }
            else if(command.has("HUMIDITY"))
            {
                type = UMIDADE;
            }
            else if(command.has("PRESSURE"))
            {
                type = PRESSAO;
            }
            if(type == 0)
            {
                ui.print("[connectSensor]: Invalid Sensor Type\n");
            }
            else
            {
                arduino.connectSensor(pin, type, protocol);
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