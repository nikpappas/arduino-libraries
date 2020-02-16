#include <OpAmpModule.h>

const int ANALOG_MAX = 1023;

OpAmpModule::OpAmpModule(int inA, int inB, int out)
{
    _inA = inA;
    _inB = inB;
    _out = out;
    _opAmp = OpAmp(ANALOG_MAX, 0);
}
void OpAmpModule::init()
{
    pinMode(_inA, INPUT);
    pinMode(_inB, INPUT);
    pinMode(_out, OUTPUT);
    setUpLog();
}

void OpAmpModule::tick()
{
    valA = analogRead(_inA);
    valB = analogRead(_inB);
    valOut = _opAmp.operate(valA, valB);
    analogWrite(_out, analog2Digital(valOut));
}

void OpAmpModule::log()
{
    Serial.print(analog2V(valA)); // inA
    Serial.print(" ");
    Serial.print(analog2V(valB)); // inB
    Serial.print(" ");
    Serial.print(analog2V(valOut)); // out
}
void OpAmpModule::setUpLog()
{
    Serial.println("inA inB out");
}
