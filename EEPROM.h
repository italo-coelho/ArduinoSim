/*
EEPROM ->   Classe para armazenamento de dados na memória
*/


#ifndef EEPROM_H
#define EEPROM_H

#include "ui.h"

namespace prog3
{
    class EEPROM
    {
    public:
        EEPROM();
        ~EEPROM();

        /**
         * @brief Define o objeto responsável pela interface
         * 
         * @param ui Objeto da classe prog3::UI responsável pela função print
         */
        void setUI(UI* ui);

        /**
         * @brief Inicia a memória
         * 
         * @param _size Tamanho da memória
         * @return true Bem-sucedida
         * @return false Malsucedida
         */
        bool begin(int _size);
        /**
         * @brief Lê uma posição da memória
         * 
         * @param _position Posição que deseja acessar
         * @return char Caractere contido na região de memória
         */
        char read(int _position);
        /**
         * @brief Escreve na posição de memória
         * 
         * @param _data Caractere que deseja armazenar
         * @param _position Posição onde deseja armazenar
         */
        void write(char _data, int _position);

    private:
        int size;
        char* vector;

        UI* ui;
    }; 
}

#endif