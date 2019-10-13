void setup() {
  Serial.begin(9600);

}

void loop() {
  float resistance = analogRead(A0);
  float brightness = 255*(resistance/1010);

 Serial.println(resistance);
 Serial.println(brightness);

 if(brightness > 255) brightness = 255;

  analogWrite(3, brightness);

  delay(50);
}
