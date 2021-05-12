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

        double const DEFAULT_CLOCK_FREQUENCY = 16e6;
        double clock_frequency;
        chrono::high_resolution_clock::time_point t_init;

    public:   
        Timer();
        Timer(double clk_freq);

        string getRealTime() const;
        double getClockFrequency()const;
        double millis()const;

        
    };
}

#endif
