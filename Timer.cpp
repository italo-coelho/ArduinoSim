#include "Timer.h"

namespace prog3{

    Timer::Timer()
    {
        clock_frequency= DEFAULT_CLOCK_FREQUENCY;
        t_init = chrono::high_resolution_clock::now();
    }

    Timer::Timer (double clk_freq)
    {
        clock_frequency=clk_freq;
        t_init = chrono::high_resolution_clock::now();
    }

    double Timer::getClockFrequency() const
    {
        return clock_frequency;
    }

    string Timer::getRealTime() const
    {   
        std::string _str;
        chrono::system_clock::time_point realTime = chrono::system_clock::now();
        time_t aux = chrono::system_clock::to_time_t(realTime);
        _str = ctime(&aux);

        return _str;
    }

    double Timer::millis() const
    {
        chrono::high_resolution_clock::time_point t_atual = chrono::high_resolution_clock::now();
        chrono::duration<double>periodo = chrono::duration_cast<chrono::duration<double>>(t_atual - t_init);
        return periodo.count();
    }
}
