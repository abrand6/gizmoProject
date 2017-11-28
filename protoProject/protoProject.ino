/*
Gizmo Project Fall/Winter 2017
(c) Frederic Macher and affiliates
Last modified: 27/11/17
Next steps: check multiple motor controls
*/

int fsrPin = 0;     // the FSR and 10K pulldown are connected to a0
int pressureInput;     // the analog reading from the FSR resistor divider
//int ain1 = 8; // High handle
int ain2 = 9; // Low handle
int motorValue = 0;

void setup(void) {
  // put your setup code here, to run once:
  // pinMode(ain1,OUTPUT);  //Logic pins are also set as output
  pinMode(ain2,OUTPUT);
  Serial.begin(9600); // send debugging information via the Serial monitor
}

void loop() {
  /*
  //CLOCKWISE MOTION:
  //   + ain1 = HIGH
  //   + ain2 = LOW
  
  digitalWrite(ain1,HIGH);
  digitalWrite(ain2,LOW);

  Serial.println("Clockwise");

  //Clockwise for 3 secs
  delay(3000);     

  //STOPPING:
  //   + ain1 = HIGH
  //  + ain2 = LOW
  
  digitalWrite(ain1,HIGH);
  digitalWrite(ain2,HIGH);

  Serial.println("Braking");

  delay(1000);

  //STOPPING:
  //   + ain1 = LOW
  //   + ain2 = HIGH
     
  digitalWrite(ain1,LOW);
  digitalWrite(ain2,HIGH);

  Serial.println("Anti-Clockwise");

  delay(3000);

  //TO PAUSE THE MOTOR
  digitalWrite(ain1,HIGH);
  digitalWrite(ain2,HIGH);

  Serial.println("On Pause");

  delay(1000);*/
  
  // put your main code here, to run repeatedly:
  pressureInput = analogRead(fsrPin); 
  motorValue = map(pressureInput, 0, 1023, 0, 255); 

  Serial.print("Analog reading = ");
  Serial.print(pressureInput);     // the raw analog reading

  // We'll have a few threshholds, qualitatively determined
  if (pressureInput = 0) {
    Serial.println(" - No pressure");
    analogWrite(ain2, motorValue);
  } else if (pressureInput < 10) {
    Serial.println(" - Very light touch");
    analogWrite(ain2, motorValue);
  } else if (pressureInput < 200) {
    Serial.println(" - Light touch");
    analogWrite(ain2, motorValue);
  } else if (pressureInput < 500) {
    Serial.println(" - Light squeeze");
    analogWrite(ain2, motorValue);
  } else if (pressureInput < 800) {
    Serial.println(" - Medium squeeze");
    analogWrite(ain2, motorValue);
  } else {
    Serial.println(" - Big squeeze");
    analogWrite(ain2, LOW);
  }
  delay(1000);
}
