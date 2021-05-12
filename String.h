/*
String ->   Classe para manipulação de objetos do tipo std::strings, 
            de forma similar a possível com a classe String para Arduino
*/


#ifndef STRING_H
#define STRING_H

#include <string>

namespace prog3
{
    class String
    {   
        private:
            std::string str;

        public:
            String();
            String(std::string _str);

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
             * @return true Texto faz parte da String
             * @return false Texto não faz parte da String
             */
            bool has(std::string _search);

            /**
             * @brief Retorna a posição da String que se encontra o texto
             * 
             * @param _search Texto procurado
             * @return int Posição do texto na String, -1 se não encontrado
             */
            int indexOf(std::string _search);

            /**
             * @brief Retorna a subString entre as posições
             * 
             * @param _begining Posição Inicial
             * @param _end Posição Final (opcional - por padrão vai até o final da String)
             * @return String Sub String 
             */
            String subString(int _begining, int _end = -2);

            /**
             * @brief Inclui novo caractere ao final da String
             * 
             * @param _add Novo Caractere
             */
            void append(char _add);

            /**
             * @brief Inclui nova String ao final da String
             * 
             * @param _add Nova String
             */
            void append(std::string _add);

            /**
             * @brief Retorna a String no tipo std::string
             * 
             * @return std::string com os dados da String
             */
            std::string cppString();
    };
}

#endif