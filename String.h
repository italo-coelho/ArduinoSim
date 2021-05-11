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

            int findNumber();
            char betweenQuotes();
            bool has(std::string _search);
            int indexOf(std::string _search);
            String subString(int _begining, int _end = -2);

            void append(char _add);
            void append(std::string _add);
            std::string cppString();
    };
}

#endif