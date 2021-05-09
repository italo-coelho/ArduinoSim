#ifndef SUPPLY_H
#define SUPPLY_H

namespace prog3
{
    //Function
    #define S_5V    1
    #define S_3V3   2
    #define S_VIN   3
    #define S_GND   4


    class supply
    {
        public:
            supply();
            supply(int _function);

            int getFunction();      

            double getCurrent();
            
            void setFunction(int _function);

            void setMaxCurrent(int _maxCurrent);
            void setLoad(double _load);
        private:
            int function;
            int maxCurrent;

            int voltage;
            double load;
            double current;
    };
}

#endif