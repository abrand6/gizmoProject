#include <FastLED.h>

#define LED_PIN   9
#define NUM_LEDS  24
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];
int fsrAnalogPin = 0; // FSR is connected to analog 0
int motorPin = 11;      // Connect motor to pin 11 (PWM pin)
int fsrReading;      // The analog reading from the FSR resistor divider
int motorSpeed; // Self explanatory
int ledBrig; // led brightness


void setup(void) {
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS);
  pinMode(motorPin, OUTPUT); // Pin 11 an output

}

void loop(void) {
  fsrReading = analogRead(fsrAnalogPin);
  Serial.print("Analog reading = ");
  Serial.println(fsrReading);
  motorSpeed = map(fsrReading, 0, 1023, 50, 255);
  ledBrig = map(fsrReading, 0, 1023, 40, 200);
  analogWrite(motorPin, motorSpeed);
  delay(100);

  FastLED.setBrightness( ledBrig ); //High = 200, Low = 50
  leds[0] = CRGB::Yellow; //Add colour name here
  leds[1] = CRGB::Yellow;
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
  FastLED.show();


}


