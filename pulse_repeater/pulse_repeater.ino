#define   PWM_RES             8

#define   PIN_OSCILLATOR      4
#define   PIN_PULSE_LED       1
#define   PIN_INTERRUPT       0

volatile unsigned long  PULSE_TIME = 17000;
volatile boolean       _semaphore = false;
volatile unsigned long _lastTime  = 0;


const int PULSE_WIDTH = pow(2,PWM_RES);

void setup()  
{ 
  analogWrite(PIN_OSCILLATOR, PULSE_WIDTH);
  
  attachInterrupt(PIN_INTERRUPT,flankUp,RISING);  

  pinMode(PIN_PULSE_LED,   OUTPUT);
} 



void loop() 
{
  while(true)
  {
    if(_semaphore)
      triggerPulse();
  }

}


void flankUp()
{
  
  if(!_semaphore)
    interruptAction();
}
void interruptAction()
{
  noInterrupts();
  _lastTime = micros();
  setSemaphore(true);
//  interrupts();
}

boolean pulseTimeOver()
{
  return (micros() - _lastTime) > PULSE_TIME;
}


void setSemaphore(boolean b)
{
  _semaphore = b;
}

void triggerPulse()
{
  noInterrupts();
//  setLedState(_semaphore);
//  delay(PULSE_TIME);
// pulseOutput(PIN_PULSE_LED); 
  if(pulseTimeOver())
    setSemaphore(false);
  setLedState(_semaphore);

  interrupts();
}
/*
============================
        Debug methods
============================
*/

// void setPinState(int pin, int st)
// {
//  digitalWriteFast(pin,st); 
 
// }
 void setLedState(int l)
 {
  digitalWrite(PIN_PULSE_LED,l); 
 
 }
// void toggleLed()
// {
//   digitalWriteFast(PIN_PULSE_LED,_ledState = !_ledState); 
// }
void pulseOutput(int l)
{

  digitalWrite(l,1);
  delay(PULSE_TIME);
  digitalWrite(l,0);
}
