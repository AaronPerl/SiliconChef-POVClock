#include <PinChangeInt.h>

#define DEBOUNCE 20

int led = 13;
int trigger = 12;

long prev = 0;
long cycleTime = 1000;

uint8_t state = 0x00;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
  DDRD = 0xFF; // Port D is all output
  pinMode(trigger, INPUT); // Set trigger as input
  //digitalWrite(trigger, HIGH); // Enable pull-up
  PCintPort::attachInterrupt(trigger, triggerPulse, FALLING);
}

uint8_t getState(int hours, int minutes, int seconds, float percent)
{
  int curSec = (int)round(percent * 60)

  return 0xFF;
}

// the loop routine runs over and over again forever:
void loop() {
  long now = millis();
  float cyclePercent = (float)(now - prev) / (float) cycleTime;
  state = getState(0, 0, 0, cyclePercent);
  PORTD = state;
  delay(100);
}

void triggerPulse()
{
  long now = millis();
  if (now - prev > DEBOUNCE)
  {
    //state = 0xFF ^ state;
    cycleTime = now - prev;
    prev = now;
    //if (cycleTime < 1000)
    //  state ^= 0xFF;
  }
}
