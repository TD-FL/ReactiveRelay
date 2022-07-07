#ifndef RELAY_H
#define RELAY_H

#include <Arduino.h>
#include <arduino-timer.h>

class Relay
{
private:
    uint8_t _pin;
    bool _onIsLow = true;
    Timer<1, millis, Relay*> _timer;

public:
    Relay(uint8_t pin);
    Relay(uint8_t pin, bool onIsLow);
    ~Relay();

    void off();
    void on();

    void click();
    void click(unsigned long ms);
    void poll();
};

#endif