#include "String.h"

#include <stdio.h>

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

        sscanf(substr.c_str(), "%d", &number);

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
}