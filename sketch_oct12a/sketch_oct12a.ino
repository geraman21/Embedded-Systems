volatile byte state = LOW; // initially button not pushed
void setup() {
pinMode(2, INPUT); // interrupt (sensor) pin
pinMode(12, OUTPUT); // LED (actuator) pin
attachInterrupt(digitalPinToInterrupt(2), handleButton, RISING);
}
void loop() {
digitalWrite(12, state);
delay(1);
}
/****** interrupt handler ******/
void handleButton() {
  static unsigned long last_interrupt = 0;
  unsigned long interrupt_time = millis();
  if(interrupt_time - last_interrupt > 200){
    state = !state;
    last_interrupt = interrupt_time;
  }
}
