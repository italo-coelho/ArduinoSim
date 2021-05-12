/*
gpio ->     Classe para representar as funcionalidade de parâmetros
            de um pino de General Purpose Input/Output de um Arduino
*/

#ifndef GPIO_H
#define GPIO_H

#include "ui.h"

namespace prog3
{
    //Function
    enum Function { OUTPUT        = 1, 
                    INPUT         = 2, 
                    INPUT_PULLUP  = 3, 
                    ANALOG        = 4, 
                    PWM           = 5};

    //Protocol  
    enum Protocol { NONE        = 0,
                    UART_RX     = 1,
                    UART_TX     = 2,
                    I2C_SCK     = 3,
                    I2C_SDA     = 4,
                    SPI_SCLK    = 5,
                    SPI_MOSI    = 6,
                    SPI_MISO    = 7,
                    SPI_CS      = 8};

    const int VOLTAGE       = 5;
    const double MAX_CURRENT   = 40e-3;

    const int LOW     = 0;
    const int HIGH    = 1023;

    class gpio
    {
        public:
            gpio();
            gpio(int _pin);
            gpio(int _pin, int _function);
            gpio(int _pin, int _function, int _protocol);

            /**
             * @brief Retorna o número do pino
             * 
             * @return int Número do pino
             */
            int getPin();

            /**
             * @brief Retorna a função do pino
             * 
             * @return int 
             */
            int getFunction();

            /**
             * @brief Retorna o protocolo do pino
             * 
             * @return int Protocolo de Comunicação
             */
            int getProtocol();

            /**
             * @brief Retorna a leitura do pino
             * 
             * @return int Valor da Leitura
             */
            int getValue();

            /**
             * @brief Retorna a carga no pino
             * 
             * @return double Carga
             */
            double getLoad();

            /**
             * @brief Retorna a potência do pino
             * 
             * @return double Potência do pino
             */
            double getPower();

            /**
             * @brief Retorna a corrente passando pelo pino
             * 
             * @return double Corrente no pelo
             */
            double getCurrent();
            
            /**
             * @brief Define o número do pino
             * 
             * @param _pin Número do pino
             */
            void setPin(int _pin);

            /**
             * @brief Define a função do pino
             * 
             * @param _function Função do pino
             */
            void setFunction(int _function);

            /**
             * @brief Define o protocolo
             * 
             * @param _protocol Protocolo do Pino
             */
            void setProtocol(int _protocol);

            /**
             * @brief Define a Leitura/Estado do pino
             * 
             * @param _value Estado do pino
             */
            void setValue(int _value);

            /**
             * @brief Define a carga conectada ao pino
             * 
             * @param _load Carga (em Ohms) conectada ao pino
             */
            void setLoad(double _load);

            /**
             * @brief Define o objeto da classe UI responsável por imprimir texto na tela
             * 
             * @param _ui Objeto da classe UI
             */
            void setUI(UI* _ui);
            
        private:
            int pin;
            int function;
            int protocol;

            int value;
            double load;
            double current;

            UI* ui;
    };
}

#endif