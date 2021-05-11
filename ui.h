/*
UI ->       Classe para apresentar a interface para o usuário na linha
            de comando e extrair os comandos digitados pelo mesmo
*/

#ifndef UI_H
#define UI_H

#include "String.h"
#include "EEPROM.h"
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
<<<<<<< HEAD
            std::string console_str;
=======
            static std::string console_str;
            
            friend class EEPROM;
>>>>>>> c5e7a35a75c5bdb2a6cfd02a8a27c3c5360f61cc
    };
}

#endif