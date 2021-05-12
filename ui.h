/*
UI ->       Classe para apresentar a interface de usuário na linha
            de comando e extrair os comandos digitados pelo mesmo
*/

#ifndef UI_H
#define UI_H

#include "String.h"

#include <string>
#include <vector>

namespace prog3
{
    class UI
    {
        public:
            /**
             * @brief Imprime na tela a mensagem de ajuda
             * 
             */
            void help();

            /**
             * @brief Limpa a tela do usuário
             * 
             */
            void clear();

            /**
             * @brief Imprime na tela o cabeçalho do programa
             * 
             */
            void header();

            /**
             * @brief Imprime na tela o console com os comandos e saídas
             * 
             */
            void console();
            
            /**
             * @brief Adiciona um texto no console e imprime a interface
             * 
             * @param _text 
             */
            void print(std::string _text);

            /**
             * @brief Limpa o console
             * 
             */
            void clearConsole();

            /**
             * @brief Espera por um comando no usuário no terminal
             * 
             * @return String 
             */
            String readCommand();

            /**
             * @brief Limpa a tela e depois imprime o cabeçalho e o console
             * 
             */
            void show();

        private:
            std::string console_str;
    };
}

#endif