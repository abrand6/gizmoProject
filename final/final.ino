/* ***************************
 * Gizmo Project Code
 * Last edited: 11/12/17
 * Description: 
 * speed and brightness control by motion sensor
 * (c) F. A. Macher 2017
 */



#include <FastLED.h> // import LED helper library

#define LED_PIN   9 // define the Led Pin
#define NUM_LEDS  24 // number of LED's
#define COLOR_ORDER GRB // color RGB order
CRGB leds[NUM_LEDS]; // apply the number of LED's  to the necessary
int fsrAnalogPin = 0; // FSR is connected to analog 0
int motorPin = 11;      // Connect motor to pin 11 (PWM pin)
int fsrReading;      // The analog reading from the FSR resistor divider
int motorSpeed; // Self explanatory
int ledBrig; // led brightness


void setup(void) {
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS); // pin identifiaction via C file
  pinMode(motorPin, OUTPUT); // Pin 11 an output

}

void loop(void) {
  fsrReading = analogRead(fsrAnalogPin); // Read the pressure sensor reading
  Serial.print("Analog reading = "); // Serial add reading description
  Serial.println(fsrReading); // Serial fsrReading
  motorSpeed = map(fsrReading, 0, 1023, 50, 255); // map different min and max values to translate intensity on pressure sensor to bit motor scale
  ledBrig = map(fsrReading, 0, 1023, 40, 200); // same but to LED's
  analogWrite(motorPin, motorSpeed); // wirte digital value to analog motor pin of motor speed
  delay(100); // wait

  // We'll need to change the range from the analog reading (0-1023) down to the range
  // Used by analogWrite (0-255) with map for both the motor speed and the led brightness
  // ledBrightness = map(fsrReading, 0, 1023, 50, 200);
  // Motor spins faster the harder we press, led lights brighter the harder we press

  FastLED.setBrightness( ledBrig ); // High = 200, Low = 50
  leds[0] = CRGB::Yellow; // Add colour name here
  leds[1] = CRGB::Yellow; // assign to all LED's
  leds[2] = CRGB::Yellow;
  leds[3] = CRGB::Yellow;
  leds[4] = CRGB::Yellow;
  leds[5] = CRGB::Yellow;
  leds[6] = CRGB::Yellow;
  leds[7] = CRGB::Yellow;
  leds[8] = CRGB::Yellow;
  leds[9] = CRGB::Yellow;
  leds[10] = CRGB::Yellow;
  leds[11] = CRGB::Yellow;
  leds[12] = CRGB::Yellow;
  leds[13] = CRGB::Yellow;
  leds[14] = CRGB::Yellow;
  leds[15] = CRGB::Yellow;
  leds[16] = CRGB::Yellow;
  leds[17] = CRGB::Yellow;
  leds[18] = CRGB::Yellow;
  leds[19] = CRGB::Yellow;
  leds[20] = CRGB::Yellow;
  leds[21] = CRGB::Yellow;
  leds[22] = CRGB::Yellow;
  leds[23] = CRGB::Yellow;
  leds[24] = CRGB::Yellow;
  leds[25] = CRGB::Yellow;
  //List of possible colours
  //Aquamarine - Cold Blue - Good for scared
  //SteelBlue - May also be good for scared
  //DarkRed - Powerful Red - Good Anger
  //Yellow - Very Golden - May be good for happiness
  //Deep Pink - Powerful Pink - May be good for friendly
  //Greens all come out very yellow or very blue
  FastLED.show(); // show light


}


