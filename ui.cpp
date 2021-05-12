#include "ui.h"
#include "Frase.h"

#include <string>
#include <iostream>

namespace prog3
{
    void UI::clear()
    {
        std::cout << std::flush;
        std::system("clear");
    }

    void UI::show()
    {
        clear();
        header();
        console();
    }

    void UI::header()
    {
        std::cout << std::endl;
        std::cout << "    #     ###   ###   #   #  #  #    #   ###  " << std::endl;
        std::cout << "   # #    #  #  #  #  #   #  #  # #  #  #   # " << std::endl;
        std::cout << "  # # #   # #   #  #  #   #  #  #  # #  #   # " << std::endl;
        std::cout << " #     #  #  #  ###    ###   #  #    #   ###  " << std::endl;

        std::cout << std::endl;
    }

    void UI::console()
    {
        std::cout << console_str;
    }

    void UI::help()
    {
        std::string help_str = "\n";
        help_str += "COMANDOS:                    UTILIZAÇÃO:\n";
        help_str += "limpa/clear                  -> limpa o console\n";
        help_str += "sair/exit                    -> encerra o programa\n";
        help_str += "\n";
        help_str += "analogRead(n)                -> retorna o estado do pino analógico, onde 'n' é o número do pino e o retorno varia de 0 a 1023\n";
        help_str += "digitalRead(n)               -> retorna o estado do pino on/off, onde 'n' é o número do pino e 'estado' pode ser HIGH ou LOW\n";
        help_str += "pinMode(n, modo)             -> define a funcionalidade do pino, onde 'n' é o número do pino e 'modo' pode ser INPUT, OUTPUT, INPUT_PULLUP\n";
        help_str += "digitalWrite(n, estado)      -> define o estado do pino on/off, onde 'n' é o número do pino e 'estado' pode ser HIGH ou LOW\n";
        help_str += "analogWrite(n, intensidade)  -> define o estado do pino PWM, onde 'n' é o número do pino e 'intensidade' pode ser um valor de 0 a 255\n";
        help_str += "\n";
        help_str += "connectSensor(pin, type)     -> conecta o sensor do 'type' (TEMP/HUMIDITY/PRESSURE) no pino analógico 'pin'\n";
        help_str += "disconnectSensor(pin)        -> desconecta o sensor do pino analógico 'pin'\n";
        help_str += "\n";
        help_str += "EEPROM.begin(n)              -> inicializa a memória EEPROM, onde 'n' é o tamanho da memória\n";
        help_str += "EEPROM.read(pos)             -> retorna o caracter armazenado na posição 'pos'\n";
        help_str += "EEPROM.write(pos, \"c\")       -> grava o caracter na memória, na posiçõa 'pos' e o caracter deve estar entre aspas duplas ou simples\n";
        help_str += "\n";
        help_str += "millis()                     -> retorna o tempo em milissegundos desde a execução do programa\n";
        help_str += "seconds()                    -> retorna o tempo em milissegundos desde a execução do programa\n";
        help_str += "\n";
        print(help_str);
    }
 
    Frase UI::readCommand()
    {
        std::string input;

        std::getline(std::cin, input);
        Frase command(input);

        return command;
    }

    void UI::print(std::string _text)
    {
        console_str += _text;
        show();
    }
    
    void UI::clearConsole()
    {
        console_str = "";
        show();
    }
}