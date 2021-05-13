/*
Frase ->    Classe para manipulação de objetos do tipo std::strings, 
            de forma similar a possível com a classe Frase para Arduino
*/


#ifndef FRASE_H
#define FRASE_H

#include <string>

namespace prog3
{
    class Frase
    {   
        private:
            std::string str;

        public:
            Frase();
            Frase(std::string _str);

            /**
             * @brief Extrair o número do objeto
             * 
             * @return int Número presente no objeto
             */
            int findNumber();

            /**
             * @brief Obtêm o caractere entre aspas simples ou duplas
             * 
             * @return char Caractere encontrado
             */
            char betweenQuotes();

            /**
             * @brief Procura um pedaço de texto na string
             * 
             * @param _search Texto de deseja procurar
             * @return true Texto faz parte da Frase
             * @return false Texto não faz parte da Frase
             */
            bool has(std::string _search);

            /**
             * @brief Retorna a posição da Frase que se encontra o texto
             * 
             * @param _search Texto procurado
             * @return int Posição do texto na Frase, -1 se não encontrado
             */
            int indexOf(std::string _search);

            /**
             * @brief Retorna a subFrase entre as posições
             * 
             * @param _begining Posição Inicial
             * @param _end Posição Final (opcional - por padrão vai até o final da Frase)
             * @return Frase Sub Frase 
             */
            Frase subFrase(int _begining, int _end = -2);

            /**
             * @brief Inclui novo caractere ao final da Frase
             * 
             * @param _add Novo Caractere
             */
            void append(char _add);

            /**
             * @brief Inclui nova Frase ao final da Frase
             * 
             * @param _add Nova Frase
             */
            void append(std::string _add);

            /**
             * @brief Retorna a Frase no tipo std::string
             * 
             * @return std::string com os dados da Frase
             */
            std::string cppString();
    };
}

#endif