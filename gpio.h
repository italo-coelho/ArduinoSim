/*
gpio ->     Classe para representar as funcionalidade de parâmetros
            de um pino de General Purpose Input/Output de um Arduino
*/

#ifndef GPIO_H
#define GPIO_H

#include "pino.h"

namespace prog3
{
    //Function
    #define OUTPUT          1
    #define INPUT           2
    #define INPUT_PULLUP    3
    #define ANALOG          4
    #define PWM             5

    //Protocol  
    #define NONE            0
    #define UART_RX         1
    #define UART_TX         2
    #define I2C_SCK         3
    #define I2C_SDA         4
    #define SPI_SCLK        5
    #define SPI_MOSI        6
    #define SPI_MISO        7
    #define SPI_CS          8

    #define VOLTAGE         5
    #define MAX_CURRENT     40e-3

    #define LOW     0
    #define HIGH    1023

    class gpio: public pino
    {
        public:
            gpio();
            gpio(int _pin);
            gpio(int _pin, int _function);
            gpio(int _pin, int _function, int _protocol);

            int getPin();
            int getFunction();
            int getProtocol();

            int getValue();
            double getLoad();
            double getPower();
            double getCurrent();
            
            void setPin(int _pin);
            void setFunction(int _function);
            void setProtocol(int _protocol);

            void setValue(int _value);
            void setLoad(double _load);
            
        private:
            int pin;
            int function;
            int protocol;

            int value;
            double load;
            double current;
    };
}

#endif