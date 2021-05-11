#ifndef UI_H
#define UI_H

#include <string>
#include "String.h"

namespace prog3
{
    class UI
    {
        public:
            void help();
            void clear();
            void header();
            
            String readCommand();

            // void arduinoStatus();
            // void updateUI();

            // void setArduino();
        private:
 
    };



}

#endif