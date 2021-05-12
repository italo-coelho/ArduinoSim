#include "Frase.h"

#include <sstream>

namespace prog3
{
    Frase::Frase(std::string _str)
    {
        str = _str;
    }

    Frase::Frase()
    {
        str = "";
    }

    int Frase::indexOf(std::string _search)
    {
        if(str.find(_search) != std::string::npos)
        {
            return int(str.find(_search));
        }
        else
        {
            return -1;
        }
    }

    bool Frase::has(std::string _search)
    {
        if(str.find(_search) != std::string::npos)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int Frase::findNumber()
    {
        int number = 0;
        std::string substr;
        
        unsigned int i = 0;
        for(i = 0; i < str.length(); i++)
        {
            if(str[i] >= '0' && str[i] <= '9')
            {
                substr += str[i];
            }
        }

        std::stringstream stream(substr);
        stream >> number;

        return number;
    }

    char Frase::betweenQuotes()
    {
        unsigned int i;
        for(i = 0; i < str.length(); i++)
        {
            if(str[i] == '\"' || str[i] == '\'') 
            {
                return str[i+1];
            }
        }

        return '\"';
    }

    void Frase::append(std::string _add)
    {
        str += _add;
    }

    void Frase::append(char _add)
    {
        str += _add;
    }

    Frase Frase::subFrase(int _begining, int _end)
    {
        Frase sub;
        int len = int(str.length());

        if(_end < 0)
        {
            _end = len - 1;
        }


        if(_begining >= 0 && _end < len)
        {
            if(_begining < _end)
            {
                unsigned int i;
                for(i = unsigned(_begining); i <= unsigned(_end); i++)
                {
                    sub.append(str[i]); 
                }

                return sub;
            }
        }
        return sub;
    }

    std::string Frase::cppString()
    {
        return str;
    }
}