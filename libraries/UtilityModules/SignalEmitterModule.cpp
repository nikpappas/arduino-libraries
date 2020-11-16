#include <SignalEmitterModule.h>


SignalEmitterModule::SignalEmitterModule(int out, int value)
{
    _value = abs(value)%256;
    _out = out;
}

void SignalEmitterModule::init()
{
    pinMode(_out, OUTPUT);
    Serial.begin(9600);
}
void SignalEmitterModule::tick()
{
    analogWrite(_out, _value);
}
void SignalEmitterModule::log()
{
}
