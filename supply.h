#ifndef SUPPLY_H
#define SUPPLY_H

namespace prog3
{
    enum S_Function { S_5V    = 1,
                      S_3V3   = 2,
                      S_VIN   = 3,
                      S_GND   = 4};

    class supply
    {
        public:
            supply();
            supply(int _function);

            /**
             * @brief Retorna o tipo do pino de alimentação
             * 
             * @return int Tipo de Alimentação
             */
            int getFunction();      

            /**
             * @brief Retorna a corrente no pino
             * 
             * @return double Corrente no pino
             */
            double getCurrent();
            
            /**
             * @brief Define o tipo do pino de alimentação
             * 
             * @param _function Tipo de Alimentação
             */
            void setFunction(int _function);

            /**
             * @brief Define a corrente máxima suportada pelo pino
             * 
             * @param _maxCurrent Corrente máxima
             */
            void setMaxCurrent(double _maxCurrent);

            /**
             * @brief Define a carga conectada no pino
             * 
             * @param _load Carga(em Ohms)
             */
            void setLoad(double _load);
            
        private:
            int function;
            int maxCurrent;

            int voltage;
            double load;
            double current;
    };
}

#endif