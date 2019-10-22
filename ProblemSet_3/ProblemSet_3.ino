
int minLight = 200;
int maxLight = 800;

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
    if(light-minLight<0) return 0;
    else if (light>maxLight) return 255;
    else return 255-m;
  }


void setup() {
  Serial.begin(9600);
  calibrateLight();
}

void loop() {
  
  int light = analogRead(A0);
  Serial.println(light);
  int ledLevel = lightMap(light);
  Serial.println(ledLevel);
  analogWrite(5, ledLevel);

  delay(50);
}
