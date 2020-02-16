class OpAmp
{
private:
    int _maxValue;
    int _minValue;

public:
    OpAmp(int maxValue, int minValue);
    OpAmp();
    int operate(int inA, int inB);
};