int pwmctrl = 20; // must be in [0, 255] for analogWrite
int up = 1;
void setup() { 
  Serial.begin(9600); 
  pinMode(2, INPUT_PULLUP);
  }
void loop() {
  Serial.println(digitalRead(2));
  delay(100);
}
