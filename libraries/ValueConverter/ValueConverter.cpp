#include <ValueConverter.h>

const int ANALOG_MAX = 1023;
const int DIGITAL_MAX = 255;
const double MAX_V = 5.0;

double digital2Analog(int value)
{
    return scale(value, DIGITAL_MAX, ANALOG_MAX);
}
double analog2Digital(int value)
{
    return scale(value, ANALOG_MAX, DIGITAL_MAX);
}

double digital2V(double value)
{
    return scaleDouble(value, DIGITAL_MAX, MAX_V);
}

double analog2V(double value)
{
    return scaleDouble(value, ANALOG_MAX, MAX_V);
}

int scale(int value, int curMax, int resMax){
    return (resMax*value)/curMax;
}
double scaleDouble(double value, double curMax, double resMax){
    return (resMax*value)/curMax;
}
