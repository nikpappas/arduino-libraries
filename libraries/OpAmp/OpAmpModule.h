#include <OpAmp.h>
#include <Arduino.h>

const int ANALOG_MAX = 1023;

class OpAmpModule
{
private:
    int _inA;
    int _inB;
    int _out;
    OpAmp _lm;
    void init();

    /* data */
public:
    OpAmpModule(int inA, int inB, int out);
    void tick();
};

OpAmpModule::OpAmpModule(int inA, int inB, int out)
{
    _inA = inA;
    _inB = inB;
    _out = out;
    _lm = OpAmp(ANALOG_MAX, 0);
}
void OpAmpModule::tick()
{
    pinMode(_inA, INPUT);
    pinMode(_inB, INPUT);
    pinMode(_out, OUTPUT);
}

void OpAmpModule::tick()
{
    valA = analogRead(_inA);
}
