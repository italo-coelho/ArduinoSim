/*
UI ->       Classe para apresentar a interface para o usuário na linha
            de comando e extrair os comandos digitados pelo mesmo
*/

#ifndef UI_H
#define UI_H

#include "String.h"

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
            
            void print(std::string _text);
            void clearConsole();

            String readCommand();

            // void arduinoPins();
            void show();

            // void setArduino();

        private:
            std::string console_str;
    };
}

#endif