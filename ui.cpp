#include "ui.h"
#include "String.h"

#include <string>
#include <iostream>

namespace prog3
{
    void UI::clear()
    {
        std::cout << std::flush;
        std::system("clear");
    }

    void UI::header()
    {
        std::cout << std::endl;
        // std::cout << "+----------------------+" << std::endl;
        // std::cout << "| SIMULADOR DE ARDUINO |" << std::endl;
        // std::cout << "+----------------------+" << std::endl;
        // std::cout << "#----------------------------------------------#" << std::endl;
        std::cout << "    #     ###   ###   #   #  #  #    #   ###  " << std::endl;
        std::cout << "   # #    #  #  #  #  #   #  #  # #  #  #   # " << std::endl;
        std::cout << "  # # #   # #   #  #  #   #  #  #  # #  #   # " << std::endl;
        std::cout << " #     #  #  #  ###    ###   #  #    #   ###  " << std::endl;
        // std::cout << "#----------------------------------------------#" << std::endl;

        // std::cout << "    @     @@@   @@@   @   @  @  @    @   @@@  " << std::endl;
        // std::cout << "   @ @    @  @  @  @  @   @  @  @ @  @  @   @ " << std::endl;
        // std::cout << "  @ @ @   @ @   @  @  @   @  @  @  @ @  @   @ " << std::endl;
        // std::cout << " @     @  @  @  @@@    @@@   @  @    @   @@@  " << std::endl;

        std::cout << std::endl;
    }

    void UI::help()
    {
        std::cout << std::endl;
        std::cout << "COMANDOS:                    UTILIZAÇÃO:" << std::endl << std::endl;
        std::cout << "limpa/clear                  -> limpa o console" << std::endl;
        std::cout << "sair/exit                    -> encerra o programa" << std::endl;
        std::cout << std::endl;
        std::cout << "analogRead(n)                -> retorna o estado do pino analógico, onde 'n' é o número do pino e o retorno varia de 0 a 1023" << std::endl;
        std::cout << "digitalRead(n)               -> retorna o estado do pino on/off, onde 'n' é o número do pino e 'estado' pode ser HIGH ou LOW" << std::endl;
        std::cout << "pinMode(n, modo)             -> define a funcionalidade do pino, onde 'n' é o número do pino e 'modo' pode ser INPUT, OUTPUT, INPUT_PULLUP" << std::endl;
        std::cout << "digitalWrite(n, estado)      -> define o estado do pino on/off, onde 'n' é o número do pino e 'estado' pode ser HIGH ou LOW" << std::endl;
        std::cout << "analogWrite(n, intensidade)  -> define o estado do pino PWM, onde 'n' é o número do pino e 'intensidade' pode ser um valor de 0 a 255" << std::endl;
        std::cout << std::endl;
        std::cout << "EEPROM.begin(n)              -> inicializa a memória EEPROM, onde 'n' é o tamanho da memória" << std::endl;
        std::cout << "EEPROM.read(pos)             -> retorna o caracter armazenado na posição 'pos'" << std::endl;
        std::cout << "EEPROM.write(pos, \"c\")       -> grava o caracter na memória, na posiçõa 'pos' e o caracter deve estar entre aspas duplas ou simples" << std::endl;
        std::cout << std::endl;
    }
 
    String UI::readCommand()
    {
        std::string input;

        std::getline(std::cin, input);
        String command(input);

        return command;
    }
}