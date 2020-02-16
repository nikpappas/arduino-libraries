#include <OpAmp.h>
#include <ValueConverter.h>
#include <Arduino.h>
#include <Module.h>

class OpAmpModule : public Module
{
private:
    int _inA;
    int _inB;
    int _out;
    OpAmp _opAmp;
    void setUpLog();

public:
    int valA;
    int valB;
    int valOut;
    virtual void init() override;
    virtual void tick() override;
    virtual void log() override;
    OpAmpModule(int inA, int inB, int out);
};