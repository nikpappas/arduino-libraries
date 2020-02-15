// int max(int a, int b);
#include <arduino.h>


class OpAmp
{
private:
    int _maxValue;
    int _minValue;

public:
    OpAmp(int maxValue, int minValue);
    int operate(int inA, int inB);
};