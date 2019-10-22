int ledState = LOW;
unsigned long prevMillis = 0; // last time state was updated
const long interval = 1000; // blink interval in ms
  void setup() {
    pinMode(13, OUTPUT); // on-board LED
  }
  void loop() {
  unsigned long currMillis = millis(); // time since startup
  if (currMillis - prevMillis >= interval) {
  prevMillis = currMillis;
  ledState = HIGH - ledState; // toggle HIGH=1/LOW=0
  digitalWrite(13, ledState); // blink
  }
  }
