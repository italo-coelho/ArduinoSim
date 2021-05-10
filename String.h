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
            bool has(std::string _search);
            int indexOf(std::string _search);
            int findNumber();

    };

}

#endif