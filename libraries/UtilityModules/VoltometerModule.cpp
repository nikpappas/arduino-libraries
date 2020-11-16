#include <VoltometerModule.h>

VoltometerModule::VoltometerModule(int inA)
{
    _value = 0;
    _inA = inA;
    _inputMode = INPUT;
}
VoltometerModule::VoltometerModule(int inA, int inputMode)
{
    _value = 0;
    _inA = inA;
    _inputMode = inputMode;
}

void VoltometerModule::init()
{
    pinMode(_inA, _inputMode);
    Serial.begin(9600);
    Serial.print(_inA);
    Serial.print("(V)");
}
void VoltometerModule::tick()
{
    _value = analogRead(_inA);
}
void VoltometerModule::log()
{
    Serial.print(analog2V(_value));
}
