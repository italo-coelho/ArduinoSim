#include "UNO.h"
#include "supply.h"
#include "gpio.h"

namespace prog3{

    Uno::Uno()
    {
        /*========================
                    GPIOS
        ==========================*/

        /*========================
                    UART
        ==========================*/

        //pino 0, GPIO 0, RXD (UART)
        gpio pino_0(0,INPUT,UART_RX);
        Uno::Pinos.pushback(pino_0);

        //pino 1, GPIO 1, TXD (UART)
        gpio pino_1(1,OUTPUT,UART_TX);
        Uno::Pinos.pushback(pino_1);

        for(int i=3; i<10;i++)
        {
            gpio pino(i);
            Uno::Pinos.push_back(pino);
        }   

        /*========================
                    SPI
        ==========================*/

        //pino 10, GPIO 10,   SPI_CS
        gpio pino_10(10, INPUT, SPI_CS);
        Uno::Pinos.push_back(pino_10);

        //pino 11, GPIO 11, SPI_MOSI
        gpio pino_11(11, OUTPUT, SPI_MOSI);
        Uno::Pinos.push_back(pino_11);

        //pino 12, GPIO 12, SPI_MISO
        gpio pino_12(12, INPUT, SPI_MISO);
        Uno::Pinos.push_back(pino_12);  

        //pino 13, GPIO 13, SPI_SCK
        gpio pino_13(13,OUTPUT,SPI_SCLK);
        Uno::Pinos.pushback(pino_13);    
   
        /*========================
                    I2C
        ==========================*/
                    
        //pino 14, A5,   SPI_MISO
        gpio pino_14(14, ANALOG, I2C_SCK);
        Uno::Pinos.push_back(pino_14); 

        //pino 15, A4,   SPI_MISO
        gpio pino_15(15, ANALOG, I2C_SDA);
        Uno::Pinos.push_back(pino_15);

        /*========================
                   SUPPLY
        ==========================*/
        
        //pino 16, VIN
        supply pino_16(S_VIN);
        Uno::Pinos.push_back(pino_16); 

        //pino 17, GND
        gpio pino_17(S_GND);
        Uno::Pinos.push_back(pino_17);
        
        //pino 18, GND
        gpio pino_18(S_GND);
        Uno::Pinos.push_back(pino_18);         

        //pino 19, 5V
        gpio pino_19(S_5V);
        Uno::Pinos.push_back(pino_19);         

        //pino 20, 3V3
        gpio pino_20(S_3V3);
        Uno::Pinos.push_back(pino_20);

    }

    Uno::pino getPino(int index) const return Pinos[index];

}