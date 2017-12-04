# Breadboard Schematics and Explanations
### Dc Motor

### DC Motor
A [DC motor](https://www.wikiwand.com/en/DC_motor) is any of a class of rotary electrical machines that converts direct current electrical energy into mechanical energy. The most common types rely on the forces produced by magnetic fields. Nearly all types of DC motors have some internal mechanism, either electromechanical or electronic, to periodically change the direction of current flow in part of the motor.

##### Example Circuit
* Stepper Motor
* Adafruit TB6612 Driver
* Jumper Wires
* Arduino

![DC Wiring](gizmoProject/breadBoardSchematics/arduino-dc_wiring.JPG)

+ AIN1 to pin 8
+ AIN2 to pin 9
+ PWMA to 5V
+ GND to Arduino GND
+ Vcc to 5V
+ Vm to 5V
+ motorA to DC motor


##### Code
For this sketch copy and paste the following code:

```C

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
```

You can also try to control this DC motor from your Raspberry Pi [here](https://gpiozero.readthedocs.io/en/stable/api_output.html#motor) you can find the GPIOzero API Reference.
