
int minLight = 1000;
int maxLight = 0;

void calibrateLight() {
  int n;
  for (n = 0; n < 1000; n++) { // take 1000 samples
        delay(10);
    int light = analogRead(A0);
    if (light < minLight)
      minLight = light;    // update = dmin
    if (light > maxLight)
      maxLight = light;   // update = dmax
  }
}

int lightMap(int light){
  int m = (int)((light-minLight)*255./(maxLight-minLight));
    m = 255-m;
    
    if(m<0) return 0;
    else if (m>255) return 255;
    else return m;
  }


void setup() {
  Serial.begin(9600);
  calibrateLight();
  Serial.println(minLight);
  Serial.println(maxLight);
  Serial.println("---------------------------------");
}

void loop() {
  
  int light = analogRead(A0);
  Serial.println(light);
  int ledLevel = lightMap(light);
  Serial.println(ledLevel);
  analogWrite(3, ledLevel);

  delay(50);
}
