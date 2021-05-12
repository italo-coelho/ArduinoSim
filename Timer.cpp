#include "Timer.h"

namespace prog3
{

    Timer::Timer()
    {
        clock_frequency= DEFAULT_CLOCK_FREQUENCY;
        t_init = std::chrono::high_resolution_clock::now();
    }

    Timer::Timer (double clk_freq)
    {
        clock_frequency=clk_freq;
        t_init = std::chrono::high_resolution_clock::now();
    }

    double Timer::getClockFrequency() const
    {
        return clock_frequency;
    }

    std::string Timer::getRealTime() const
    {   
        std::string _str;
        std::chrono::system_clock::time_point realTime = std::chrono::system_clock::now();
        time_t aux = std::chrono::system_clock::to_time_t(realTime);
        _str = ctime(&aux);

        return _str;
    }

    double Timer::millis() const
    {
        std::chrono::high_resolution_clock::time_point t_atual = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double>periodo = std::chrono::duration_cast<std::chrono::duration<double>>(t_atual - t_init);
        return periodo.count();
    }
}
