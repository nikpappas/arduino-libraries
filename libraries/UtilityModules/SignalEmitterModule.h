#ifndef SignalEmitterModule_h
#define SignalEmitterModule_h

#include <Module.h>
#include <avr/pgmspace.h>
#include <Arduino.h>

class SignalEmitterModule : public Module
{
private:
    int _out;
    int _value;

public:
    virtual void init() override;
    virtual void tick() override;
    virtual void log() override;
    SignalEmitterModule(int out, int value);
};

#endif
