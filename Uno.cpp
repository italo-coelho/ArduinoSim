#include "UNO.h"
#include "supply.h"
#include "pino.h"
#include "gpio.h"

namespace prog3
{

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
        Uno::pinD.push_back(pino_0);

        //pino 1, GPIO 1, TXD (UART)
        gpio pino_1(1,OUTPUT,UART_TX);
        Uno::pinD.push_back(pino_1);

        for(int i=3; i<10;i++)
        {
            gpio pino(i);
            Uno::pinD.push_back(pino);
        }   

        /*========================
                    SPI
        ==========================*/

        //pino 10, GPIO 10,   SPI_CS
        gpio pino_10(10, INPUT, SPI_CS);
        Uno::pinD.push_back(pino_10);

        //pino 11, GPIO 11, SPI_MOSI
        gpio pino_11(11, OUTPUT, SPI_MOSI);
        Uno::pinD.push_back(pino_11);

        //pino 12, GPIO 12, SPI_MISO
        gpio pino_12(12, INPUT, SPI_MISO);
        Uno::pinD.push_back(pino_12);  

        //pino 13, GPIO 13, SPI_SCK
        gpio pino_13(13,OUTPUT,SPI_SCLK);
        Uno::pinD.push_back(pino_13);    
   
        /*========================
                    I2C
        ==========================*/

        for(int i=0 ; i < 4; i++)
        {
            gpio pino(i + 14, ANALOG);
            Uno::pinA.push_back(pino);
        }

        //pino 1, A4,   I2C_SDA
        gpio pino_A4(18, ANALOG, I2C_SDA);
        Uno::pinA.push_back(pino_A4); 

        //pino 1, A5,   I2C_SCK
        gpio pino_A5(19, ANALOG, I2C_SCK);
        Uno::pinA.push_back(pino_A5);

        /*========================
                   SUPPLY
        ==========================*/
        
        // //pino 16, VIN
        // supply pino_16(S_VIN);
        // Uno::pinS.push_back(pino_16); 

        // //pino 17, GND
        // gpio pino_17(S_GND);
        // Uno::pinS.push_back(pino_17);
        
        // //pino 18, GND
        // gpio pino_18(S_GND);
        // Uno::pinS.push_back(pino_18);         

        // //pino 19, 5V
        // gpio pino_19(S_5V);
        // Uno::pinS.push_back(pino_19);         

        // //pino 20, 3V3
        // gpio pino_20(S_3V3);
        // Uno::pinS.push_back(pino_20);

    }

    pino Uno::getPinD(int index)
    {
        return pinD[index];
    } 

    pino Uno::getPinA(int index)
    {
        return pinA[index];
    }

    void Uno::EEPROMbegin(int _size)
    {
        eeprom.begin(_size);
    }

    void Uno::EEPROMwrite(int _pos, char _data)
    {
        eeprom.write(_data, _pos);
    }

    char Uno::EEPROMread(int _pos)
    {
        return eeprom.read(_pos);
    }

    int Uno::analogRead(int _pin)
    {
        return pinA[_pin].getValue();
    }

    int Uno::digitalRead(int _pin)
    {
        return pinD[_pin].getValue();
    }

    void Uno::pinMode(int _pin, int _mode)
    {
        pinD[_pin].setFunction(_mode);
    }

    void Uno::analogWrite(int _pin, int _state)
    {
        pinD[_pin].setValue(_state);
    }

    void Uno::digitalWrite(int _pin, int _state)
    {
        pinD[_pin].setValue(_state);
    }
}