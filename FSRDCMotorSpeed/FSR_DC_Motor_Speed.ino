
/* Control DC motor speed from FSR 
 
Connect one end of FSR to 5V, the other end to Analog 0.
Then connect one end of a 10K resistor from Analog 0 to ground
Connect transitor base (control) to PWM pin through a resistor 
 
 
int fsrAnalogPin = 0; // FSR is connected to analog 0
int motorPin = 11;      // connect motor to pin 11 (PWM pin)
int fsrReading;      // the analog reading from the FSR resistor divider
int motorSpeed;
 
void setup(void) {
  Serial.begin(9600);   // We'll send debugging information via the Serial monitor
  pinMode(motorPin, OUTPUT);
}
 
void loop(void) {
  fsrReading = analogRead(fsrAnalogPin);
  Serial.print("Analog reading = ");
  Serial.println(fsrReading);
 
  // we'll need to change the range from the analog reading (0-1023) down to the range
  // used by analogWrite (0-255) with map!
  motorSpeed = map(fsrReading, 0, 1023, 0, 255);
  // Motor spins faster the harder you press
  analogWrite(motorPin, motorSpeed);
 
  delay(100);
}
