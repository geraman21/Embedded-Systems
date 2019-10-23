
// define colors
#define RED 9
#define GREEN 10
#define BLUE 11

int redBr = 0;
int greenBr = 0;
int blueBr = 0;

int redLevel = 255;
int greenLevel = 255;
int blueLevel = 255;

void getBr(){
  analogWrite(RED, redLevel);
  delay(1000);
  redBr = analogRead(A0);
  Serial.print("redBr: "); Serial.println(redBr);
  analogWrite(RED, 0);
  analogWrite(GREEN, greenLevel);
  delay(1000);
  greenBr = analogRead(A0);
  Serial.print("greenBr: "); Serial.println(greenBr);
  analogWrite(GREEN, 0);
  analogWrite(BLUE, blueLevel);
  delay(1000);
  blueBr = analogRead(A0);
  Serial.print("blueBr: "); Serial.println(blueBr);
  analogWrite(BLUE, 0);
  }

 int minimumBr(int red, int green, int blue){
    if (red < green && red < blue) return red;
    else if (blue <red && blue < green) return blue;
    else return green;
  }

  void calibrateBr(int referenceBr){
    boolean redCalibrated = false;
    boolean blueCalibrated = false;
    boolean greenCalibrated = false;

    while(!redCalibrated){
      analogWrite(RED, redLevel);
      delay(20);
      if(redBr > referenceBr) {
        redBr = analogRead(A0);
        redLevel--;}
      else if(redBr < referenceBr) {redBr=analogRead(A0); redLevel++;}
      else {Serial.println("RedCalibration complete");
      redCalibrated = true;
      analogWrite(RED, 0);
      }
    }
    while(!greenCalibrated){
      analogWrite(GREEN, greenLevel);
      delay(20);
      if(greenBr > referenceBr) {greenBr=analogRead(A0); greenLevel--;}
      else if(greenBr<referenceBr) {greenBr=analogRead(A0); greenLevel++;}
      else{Serial.println("Green Calibration complete"); greenCalibrated = true; analogWrite(GREEN, 0);}
    }
    while(!blueCalibrated){
      analogWrite(BLUE, blueLevel);
      delay(20);
      if (blueBr > referenceBr) {blueBr=analogRead(A0); blueLevel--;}
      else if(blueBr<referenceBr) {blueBr=analogRead(A0); blueLevel++;}
      else {Serial.println("Blue Calibration complete"); blueCalibrated = true; analogWrite(BLUE, 0);}
    }
  }

void setup() {
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  getBr();
  delay(1000);
  int referenceBr = minimumBr(redBr, greenBr, blueBr);
  Serial.println(referenceBr);
  calibrateBr(referenceBr);
}

void loop() {

  analogWrite(RED, redLevel);
  delay(1000);
  Serial.print("redBr: "); Serial.println(analogRead(A0));
  analogWrite(RED, 0);
  analogWrite(GREEN, greenLevel);
  delay(1000);
  Serial.print("greenBr: "); Serial.println(analogRead(A0));
  analogWrite(GREEN, 0);
  analogWrite(BLUE, blueLevel);
  delay(1000);
  Serial.print("blueBr: "); Serial.println(analogRead(A0));
  analogWrite(BLUE, 0);
}
