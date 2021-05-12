/*
UI ->       Classe para apresentar a interface para o usuário na linha
            de comando e extrair os comandos digitados pelo mesmo
*/

#ifndef UI_H
#define UI_H

#include "String.h"
//#include "EEPROM.h"
#include <string>

namespace prog3
{
    class UI
    {
        public:
            void help();
            void clear();
            void header();
            void console();
            
            
            static void print(std::string _text);
            void clearConsole();

            String readCommand();

            // void arduinoPins();
            void show();

            // void setArduino();
        private:
            static std::string console_str;
            
            //friend class EEPROM;
    };
}

#endif