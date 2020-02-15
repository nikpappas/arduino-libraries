#include <LedMonitor.h>
// #include <LedControl.h>

const byte levels[] = {
    B00000001,
    B00000010,
    B00000100,
    B00001000,
    B00010000,
    B00100000,
    B01000000,
    B10000000};

byte _screenBuffer[] = {
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000};
// Put values in arrays
byte _screenResult[] = {
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000};

LedMonitor::LedMonitor(int toneIn, unsigned long delayTime, LedControl ledControl)
{
  _delayTime = delayTime;
  _lc = ledControl;
  _in = toneIn;
  _lastRendered = millis();
}

void LedMonitor::draw()
{
  for (int i = 0; i < LEVEL_COUNT; i++)
  {
    _lc.setRow(0, i, _screenBuffer[i]);
  }
  clone(_screenBuffer, _screenResult, LEVEL_COUNT);
  shiftLeft(_screenBuffer, _screenResult, LEVEL_COUNT);
}

void LedMonitor::tick(double curIn)
{
  _screenBuffer[0] = currentToByte(curIn);
  draw();
  // unsigned long diff = millis() - _lastRendered;
  delay(_delayTime );//- diff);
  // printBuffer();
  _lastRendered = millis();
}

void LedMonitor::init()
{
  _lc.shutdown(0, false);
  _lc.setIntensity(0, 5);
  _lc.clearDisplay(0);
}

byte currentToByte(double current)
{
  int quantizedValue = floor(scale(current, ANALOG_MAX, LEVEL_COUNT));
  // Serial.println(quantizedValue);
  return levels[quantizedValue];
}

double scale(double value, int initial, int result)
{
  return result * value / initial;
}

void clone(byte *screenBuffer, byte *screenResult, int size)
{
  memcpy(screenResult, screenBuffer, sizeof(screenBuffer[0]) * size);
}

void shiftLeft(byte *screenBuffer, byte *screenResult, int size)
{
  clone(screenBuffer, screenResult, size);
  for (int i = 0; i < size - 1; i++)
  {
    screenBuffer[i + 1] = screenResult[i]; //move all element to the right except last one
  }
}
void LedMonitor::printBuffer(){
 for(int i=0; i < LEVEL_COUNT; i++){
   Serial.println(_screenBuffer[i], BIN);
 }
}
