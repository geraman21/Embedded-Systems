#include <histogram.h>
#include <TimerOne.h>
int ledState = LOW;
void timerISR() // Interrupt Service Routine for timer
  {
    ledState = HIGH - ledState; // toggle HIGH/LOW
    digitalWrite(13, ledState); // blink
  }
void setup()
  {
    pinMode(13, OUTPUT); // on-board LED
    Timer1.initialize(60000000); // timer period = 60s
    Timer1.attachInterrupt(timerISR); // attach ISR to Timer1
  }
void loop() { /* empty, the action is in timerISR */ }
