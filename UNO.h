/*
UNO ->   Classe para representar o Arduino UNO
*/


#ifndef UNO_H
#define UNO_H

#include <vector>

#include "ui.h"
#include "pino.h"
#include "Timer.h"
#include "Sensor.h"
#include "EEPROM.h"

namespace prog3{

    class UNO 
    {
    private:
        std::vector<pino> pinD;
        std::vector<pino> pinA;
        std::vector<pino> pinS;

        std::vector<Sensor> sensor;

        EEPROM eeprom;
        
        Timer timer;

        UI* ui;
        
    public:
        UNO();

        /**
         * @brief Retorna os pinos digitais
         * 
         * @param index Número do pino
         * @return pino Objeto do tipo pino digital
         */
        pino getPinD(int index);

        /**
         * @brief Retorna os pinos analógicos
         * 
         * @param index Número do pino
         * @return pino Objeto do tipo pino analógico
         */
        pino getPinA(int index);

        /**
         * @brief Lê o valor do pino Analógico
         * 
         * @param _pin Número do pino
         * @return int Valor da Leitura
         */
        double analogRead(int _pin);

        /**
         * @brief Lê o valor do pino Digital
         * 
         * @param _pin Número do pino
         * @return int Valor da Leitura
         */
        int digitalRead(int _pin);

        /**
         * @brief Define o modo de operação do pino
         * 
         * @param _pin Número do pino
         * @param _mode Modo de Operação
         */
        void pinMode(int _pin, int _mode);

        /**
         * @brief Define a intensidade do pino PWM
         * 
         * @param _pin Número do pino
         * @param _state Intensidade
         */
        void analogWrite(int _pin, int _state);

        /**
         * @brief Define o estado do pino digital
         * 
         * @param _pin Número do pino
         * @param _state Estado do pino
         */
        void digitalWrite(int _pin, int _state);
        
        /**
         * @brief Inicializa a memória EEPROM
         * 
         * @param _size Tamanho da memóra desejada
         */
        void EEPROMbegin(int _size);

        /**
         * @brief Escreve na Memória
         * 
         * @param _pos Posição da Memória
         * @param _data Caractere que deseja armazenar
         */
        void EEPROMwrite(int _pos, char _data);

        /**
         * @brief Lê dado da memória
         * 
         * @param _pos Posição da memória
         * @return char Caractere Armazenado na posição
         */
        char EEPROMread(int _pos);

        /**
         * @brief Define o objeto de prog3::UI responsável por imprimir na tela
         * 
         * @param _ui Obejto de prog3::UI
         */
        void setUI(UI* _ui);

        /**
         * @brief Retorna o tempo em segundos
         * @details Desde o início do programa, ou seja, desde a
         *          construção do objeto UNO
         * @return unsigned long Tempo em segundos
         */
        unsigned long seconds();

        /**
         * @brief Retorna o tempo em millisegundos
         * @details Desde o início do programa, ou seja, desde a
         *          construção do objeto UNO
         * @return unsigned long Tempo em millisegundos
         */
        unsigned long millis();

        /**
         * @brief Conecta o sensor no pino
         * 
         * @param _pin Pino
         * @param _type Tipo do sensor 
         * @param _protocol Protocolo do Sensor (opcional - padrao = SPI)
         */
        void connectSensor(int _pin, int _type, int _protocol = SPI);

        /**
         * @brief Desconecta o sensor do pino
         * 
         * @param _pin Pino
         */
        void disconnectSensor(int _pin);

        /**
         * @brief Retorna a data e hora
         * 
         * @return std::string com a data e hora atual
         */
        std::string getRTC() const;
    };
}

#endif
