#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <string>

using namespace std;

namespace prog3
{
    class Timer
    {
    private:
    
        double const DEFAULT_CLOCK_FREQUENCY = 16e4;
        time_t clock_frequency;

    public:   
        Timer();
        Timer(time_t clk_freq);

        string getRealTime() const;
        
        
    };
}

#endif
