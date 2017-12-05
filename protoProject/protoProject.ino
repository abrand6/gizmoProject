
/* ***********************************
Title: Control DC motor speed from FSR 
Author: Frederic A. Macher
Last modified: 04/12/17
Description:
Connect one end of FSR to 5V, the other end to Analog 0
Then connect one end of a 10K resistor from Analog 0 to ground
Connect transitor base (control) to PWM pin through a resistor
For more information please refer to schematic
************************************ */
 
 
int fsrAnalogPin = 0; // FSR is connected to analog 0
int motorPin = 11;      // Connect motor to pin 11 (PWM pin)
int led = 9; // Connect led to pin 9 (PWM pin)
int fsrReading;      // The analog reading from the FSR resistor divider
int motorSpeed; // Self explanatory
int ledBrightness; // Self explanatory
 
void setup(void) {
  Serial.begin(9600);   // Sending debugging information via the Serial monitor
  pinMode(motorPin, OUTPUT); // Pin 11 an output
  pinMode(led, OUTPUT); // Pin 9 an output
}
 
void loop(void) {
  fsrReading = analogRead(fsrAnalogPin);
  Serial.print("Analog reading = ");
  Serial.println(fsrReading);
 
  // We'll need to change the range from the analog reading (0-1023) down to the range
  // Used by analogWrite (0-255) with map for both the motor speed and the led brightness
  motorSpeed = map(fsrReading, 0, 1023, 0, 255);
  ledBrightness = map(fsrReading, 0, 1023, 0, 255);
  // Motor spins faster the harder we press, led lights brighter the harder we press
  analogWrite(motorPin, motorSpeed);
  analogWrite(led, ledBrightness);
 
  delay(100);
}
