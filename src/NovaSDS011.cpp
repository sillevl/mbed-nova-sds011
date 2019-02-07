#include "NovaSDS011.h"



NovaSDS011::NovaSDS011(PinName pm10PWM, PinName pm2_5PWM)
{
    mode = PWM;
}

NovaSDS011::NovaSDS011(Serial* serial)
{
    mode = SERIAL;
    this->serial = serial;
    serial->baud(9600);
    pm10_count = 0;
    pm2_5_count = 0;
}

float NovaSDS011::getPM10()
{
    return pm10_count;
}

float NovaSDS011::getPM2_5()
{
    return pm2_5_count;
}

void NovaSDS011::read() 
{
    serial->read(buffer, PACKET_SIZE, NULL);
    if(buffer[9] == 0xAB) {
        pm10_count = ((buffer[5] << 8) + buffer[4]) / 10.0;
        pm2_5_count = ((buffer[3] << 8) + buffer[2]) / 10.0;
    }
}

