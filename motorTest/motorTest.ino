/*
Gizmo Project Fall/Winter 2017
(c) Frederic Macher and affiliates
Last modified: 27/11/17
Next steps: check multiple motor controls
*/

int ain1 = 8;
int ain2 = 9;

void setup(){
  pinMode(ain1,OUTPUT);  //Logic pins are also set as output
  pinMode(ain2,OUTPUT);
  Serial.begin(9600);
}

void loop(){

  /*CLOCKWISE MOTION:
     + ain1 = HIGH
     + ain2 = LOW
  */
  digitalWrite(ain1,HIGH);
  digitalWrite(ain2,LOW);

  Serial.println("Clockwise");

  //Clockwise for 3 secs
  delay(3000);     

  /*STOPPING:
     + ain1 = HIGH
     + ain2 = LOW
  */
  digitalWrite(ain1,HIGH);
  digitalWrite(ain2,HIGH);

  Serial.println("Braking");

  delay(1000);

  /*STOPPING:
     + ain1 = LOW
     + ain2 = HIGH
  */
  digitalWrite(ain1,LOW);
  digitalWrite(ain2,HIGH);

  Serial.println("Anti-Clockwise");

  delay(3000);

  //TO PAUSE THE MOTOR
  digitalWrite(ain1,HIGH);
  digitalWrite(ain2,HIGH);

  Serial.println("On Pause");

  delay(1000);
 }
