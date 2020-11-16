#ifndef VoltometerModule_h
#define VoltometerModule_h



#include <Module.h>
#include <avr/pgmspace.h>
#include <Arduino.h>
#include <ValueConverter.h>

class VoltometerModule : public Module
{
private:
    int _inA;
    int _inputMode;

public:
    virtual void init() override;
    virtual void tick() override;
    virtual void log() override;
    VoltometerModule(int inA, int inputMode);
    VoltometerModule(int inA);
    int _value;

};


#endif