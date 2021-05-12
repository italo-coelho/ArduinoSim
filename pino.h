#ifndef PINO_H
#define PINO_H

#include "gpio.h"
#include "Sensor.h"
#include <string>

namespace prog3
{
    //tipos de pinos
    const int SUPPLY_PIN    = 1;
    const int GPIO_PIN      = 2;

    //status
    const int OCUPADO       = 1;
    const int DISPONIVEL    = 0;
    
    class pino
    {
    private:
        int tipo;                                   //gpio ou supply pin
        bool status;                                //ocupado ou disponivel
        int N_pino;                                 //numeracao do pino
        std::string label;                          //Nome do pino
        gpio port;
        Sensor* sensor;

    public:
        pino(gpio _port);

        /**
         * @brief Retorna o tipo do Pino
         * 
         * @return int Tipo do Pino (SUPPLU_PIN, GPIO_PIN)
         */
        int getTipo();

        /**
         * @brief Retorna o status do pino
         * 
         * @return true Ocupado
         * @return false Disponível
         */
        bool getStatus();

        /**
         * @brief Retorna a Legenda do pino
         * 
         * @return std::string Legenda do pino
         */
        std::string getLabel();

        /**
         * @brief Define o tipo do objeto
         * 
         * @param tp Tipo do pino (SUPPLU_PIN, GPIO_PIN)
         */
        void setTipo(int tp);

        /**
         * @brief Define o status do pino
         * 
         * @param sts true = ocupado, false = disponível
         */
        void setStatus(bool sts);

        /**
         * @brief Define a Legenda do pino
         * 
         * @param lbl string com a Legenda do pino
         */
        void setLabel(std::string lbl);

        //GPIO functions;

        /**
         * @brief Retorna o número do pino
         * 
         * @return int Número do pino
         */
        int getPin();

        /**
         * @brief Retorna a leitura do pino
         * 
         * @return double Valor da Leitura
         */
        double getValue();

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
         * @brief Define o objeto da classe UI responsável por imprimir texto na tela
         * 
         * @param _ui Objeto da classe UI
         */
        void setUI(UI* _ui);

        /**
         * @brief Define o número do pino
         * 
         * @param _pin Número do pino
         */
        void setPin(int _pin);

        /**
         * @brief Define a Leitura/Estado do pino
         * 
         * @param _value Estado do pino
         */
        void setValue(int _value);

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
         * @brief Define o objeto sensor conectado ao pino
         * 
         * @param _sensor Ponteiro para o objeto sensor
         */
        void setSensor(Sensor* _sensor);

        /**
         * @brief Retorna o objeto sensor conectado
         * 
         * @return Sensor* Ponteiro para o sensor conectado
         */
        Sensor* getSensor();

    };
}

#endif