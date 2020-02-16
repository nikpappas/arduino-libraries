#include <OpAmp.h>

OpAmp::OpAmp(int maxValue, int minValue)
{
    _maxValue = maxValue;
    _minValue = minValue;
}

int OpAmp::operate() {}
int OpAmp::operate(int inA, int inB)
{
    if(inA-inB>0){
        return _maxValue;
    } else{
        return  _minValue;
    }
}
