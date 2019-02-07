#pragma once

#include "mbed.h"

class NovaSDS011
{

public:

    enum Mode { SERIAL, PWM};

    NovaSDS011(PinName pm10PWM, PinName pm2_5PWM);
    NovaSDS011(Serial* serial);
    void read();
    float getPM10();
    float getPM2_5();
private:
    Serial* serial;
    float pm10_count;
    float pm2_5_count;

    Mode mode;

    static const uint8_t PACKET_SIZE = 10;
    uint8_t buffer[PACKET_SIZE];

};