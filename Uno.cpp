#include "UNO.h"
#include "supply.h"
#include "pino.h"
#include "gpio.h"

namespace prog3
{

    UNO::UNO()
    {
        //pino 0, GPIO 0, RXD (UART)
        gpio pino_0(0,INPUT,UART_RX);
        UNO::pinD.push_back(pino_0);

        //pino 1, GPIO 1, TXD (UART)
        gpio pino_1(1,OUTPUT,UART_TX);
        UNO::pinD.push_back(pino_1);

        for(int i=3; i<10;i++)
        {
            gpio pino(i);
            UNO::pinD.push_back(pino);
        }   

        //pino 10, GPIO 10,   SPI_CS
        gpio pino_10(10, INPUT, SPI_CS);
        UNO::pinD.push_back(pino_10);

        //pino 11, GPIO 11, SPI_MOSI
        gpio pino_11(11, OUTPUT, SPI_MOSI);
        UNO::pinD.push_back(pino_11);

        //pino 12, GPIO 12, SPI_MISO
        gpio pino_12(12, INPUT, SPI_MISO);
        UNO::pinD.push_back(pino_12);  

        //pino 13, GPIO 13, SPI_SCK
        gpio pino_13(13,OUTPUT,SPI_SCLK);
        UNO::pinD.push_back(pino_13);    
   
        for(int i=0 ; i < 4; i++)
        {
            gpio pino(i + 14, ANALOG);
            UNO::pinA.push_back(pino);
            pinA.back().setStatus(DISPONIVEL);
        }

        //pino 1, A4,   I2C_SDA
        gpio pino_A4(18, ANALOG, I2C_SDA);
        UNO::pinA.push_back(pino_A4); 

        //pino 1, A5,   I2C_SCK
        gpio pino_A5(19, ANALOG, I2C_SCK);
        UNO::pinA.push_back(pino_A5);
        
        //pino 16, VIN
        supply pino_16(S_VIN);
        UNO::pinS.push_back(pino_16); 

        //pino 17, GND
        supply pino_17(S_GND);
        UNO::pinS.push_back(pino_17);
        
        //pino 18, GND
        supply pino_18(S_GND);
        UNO::pinS.push_back(pino_18);         

        //pino 19, 5V
        supply pino_19(S_5V);
        UNO::pinS.push_back(pino_19);         

        //pino 20, 3V3
        supply pino_20(S_3V3);
        UNO::pinS.push_back(pino_20);

    }

    pino UNO::getPinD(int index)
    {
        unsigned int _index = unsigned(index);

        return pinD[_index];
    } 

    pino UNO::getPinA(int index)
    {
        unsigned int _index = unsigned(index);

        return pinA[_index];
    }

    
    void UNO::EEPROMbegin(int _size)
    {
        eeprom.begin(_size);
    }

    void UNO::EEPROMwrite(int _pos, char _data)
    {
        eeprom.write(_data, _pos);
    }

    char UNO::EEPROMread(int _pos)
    {
        return eeprom.read(_pos);
    }

    double UNO::analogRead(int _pin)
    {
        if(_pin < 0 || _pin > 5)
        {
            ui->print("[analogRead]: Invalid Pin Number");
            return 0;
        }
        unsigned int pin = unsigned(_pin);

        return pinA[pin].getValue();
    }

    int UNO::digitalRead(int _pin)
    {
        if(_pin < 0 || _pin > 13)
        {
            ui->print("[digitalRead]: Invalid Pin Number\n");
            return 0;
        }

        unsigned int pin = unsigned(_pin);

        return int(pinD[pin].getValue());
    }

    void UNO::pinMode(int _pin, int _mode)
    {
        if(_pin < 0 || _pin > 13)
        {
            ui->print("[pinMode]: Invalid Pin Number\n");
            return;
        }
        
        unsigned int pin = unsigned(_pin);

        pinD[pin].setFunction(_mode);
    }

    void UNO::analogWrite(int _pin, int _state)
    {
        
        if(_pin < 0 || _pin > 13)
        {
            ui->print("[analogWrite]: Invalid Pin Number");
            return;
        }
        
        unsigned int pin = unsigned(_pin);

        if(pinD[pin].getFunction() == PWM)
        {
            pinD[pin].setValue(_state);
        }
        else
        {
            ui->print("[analogWrite]: Cannot analog-write to non-PWM pin\n");
        }
    }

    void UNO::digitalWrite(int _pin, int _state)
    {
        unsigned int pin = unsigned(_pin);

        if(pinD[pin].getFunction() == OUTPUT)
        {
            pinD[pin].setValue(_state);
        }
        else if(pinD[pin].getFunction() == INPUT)
        {
            ui->print("[digitalWrite]: Cannot write to INPUT pin\n");
        }
        else if(pinD[pin].getFunction() == INPUT_PULLUP)
        {
            ui->print("[digitalWrite]: Cannot write to INPUT_PULLUP pin\n");
        }
    }

    void UNO::setUI(UI* _ui)
    {
        ui = _ui;
        eeprom.setUI(ui);
        
        unsigned int i;
        for(i = 0; i < pinD.size(); i++)
        {
            pinD[i].setUI(ui);
        }
        for(i = 0; i < pinA.size(); i++)
        {
            pinA[i].setUI(ui);
        }
    }

    unsigned long UNO::seconds()
    {
        long millis = long(timer.millis());
        return unsigned(millis);
    }

    unsigned long UNO::millis()
    {
        long millis = long(timer.millis() * 1000);
        return unsigned(millis);
    }

    void UNO::connectSensor(int _pin, int _type, int _protocol)
    {
        if(_pin < 0 || _pin > 5)
        {
            ui->print("[connectSensor]: Invalid Pin Number\n");
            return;
        }

        unsigned int pin = unsigned(_pin);
        if(pinA[pin].getStatus() == DISPONIVEL)
        {            
            Sensor _sensor(_type, _protocol);
            UNO::sensor.push_back(_sensor);
            pinA[pin].setSensor(&sensor.back());
            pinA[pin].setStatus(OCUPADO);
            std::string tipo;
            switch (_type)
            {
                case TEMPERATURA: tipo = "TEMP"; break;
                case UMIDADE: tipo = "HUMIDITY"; break;
                case PRESSAO: tipo = "PRESSURE"; break;
                default: tipo = "";
            }
            ui->print("[connectSensor]: " + tipo + " Sensor successfully attached to pin A" + std::to_string(pin) + "\n");
        }
        else if(pinA[pin].getStatus() == OCUPADO)
        {            
            ui->print("[connectSensor]: The pin is already Occupied\n");
        }
    }

    void UNO::disconnectSensor(int _pin)
    {
        if(_pin < 0 || _pin > 5)
        {
            ui->print("[disconnectSensor]: Invalid Pin Number\n");
            return;
        }

        unsigned int pin = unsigned(_pin);
        if(pinA[pin].getStatus() == OCUPADO)
        {            
            pinA[pin].setSensor(nullptr);
            pinA[pin].setStatus(DISPONIVEL);
            ui->print("[disconnectSensor]: Sensor successfully disconnected from pin A" + std::to_string(pin) + "\n");
        }
        else if(pinA[pin].getStatus() == DISPONIVEL)
        {            
            ui->print("[disconnectSensor]: The pin is already Free\n");
        }
    }
}