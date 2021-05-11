#include "String.h"

#include <sstream>
#include <iostream>

namespace prog3
{
    String::String(std::string _str)
    {
        str = _str;
    }

    String::String()
    {
        str = "";
    }

    int String::indexOf(std::string _search)
    {
        if(str.find(_search) != std::string::npos)
        {
            return str.find(_search);
        }
        else
        {
            return -1;
        }
    }

    bool String::has(std::string _search)
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

    int String::findNumber()
    {
        int number = 0;
        std::string substr;
        int i = 0;

        for(i = 0; i < str.length(); i++)
        {
            if(str[i] >= '0' && str[i] <= '9')
            {
                substr += str[i];
            }
        }

        // sscanf(substr.c_str(), "%d", &number);

        std::stringstream stream(substr);
        stream >> number;

        return number;
    }

    char String::betweenQuotes()
    {
        int i;
        for(i = 0; i < str.length(); i++)
        {
            if(str[i] == '\"' || str[i] == '\'') 
            {
                return str[i+1];
            }
        }

        return '\"';
    }

    void String::append(std::string _add)
    {
        str += _add;
    }

    void String::append(char _add)
    {
        str += _add;
    }

    String String::subString(int _begining, int _end)
    {
        String sub;

        if(_end == -2)
        {
            _end = str.length() - 1;
        }

        if(_begining >= 0 && _end < str.length())
        {
            if(_begining < _end)
            {
                int i;
                for(i = _begining; i <= _end; i++)
                {
                    sub.append(str[i]); 
                }

                return sub;
            }
        }
    }

    std::string String::cppString()
    {
        return str;
    }
}