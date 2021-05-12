#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <string>

namespace prog3
{
    class Timer
    {
    private:

        double const DEFAULT_CLOCK_FREQUENCY = 16e6;
        double clock_frequency;
        std::chrono::high_resolution_clock::time_point t_init;

    public:   
        Timer();
        Timer(double clk_freq);
        
        /**
         * @brief Retorna o tempo em segundos desde a criação do objeto
         * 
         * @return double Tempo em segundos
         */
        double millis()const;

        /**
         * @brief Retorna o tempo real RTC
         * 
         * @return std::string Tempo real
         */
        std::string getRealTime() const;

        /**
         * @brief Retorna a frequência do relógio
         * 
         * @return double Frequência
         */
        double getClockFrequency()const;     
    };
}

#endif
