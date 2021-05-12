#include "Timer.h"

namespace prog3{

    Timer::Timer()
    {
        clock_frequency= DEFAULT_CLOCK_FREQUENCY;
    }

    Timer::Timer (double clk_freq)
    {
        clock_frequency=clk_freq;
    }

    double Timer::getClockFrequency() const
    {
        return clock_frequency;
    }

    string getRealTime()
    {   
        std::string _str;
        chrono::system_clock::time_point realTime = chrono::system_clock::now();
        time_t aux = chrono::system_clock::to_time_t(realTime);
        _str = ctime(&aux);

        return _str;
    }
}
