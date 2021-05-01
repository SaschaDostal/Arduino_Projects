// INCLUDES ___________________________________________________________________________________________
#include <AFMotor.h>      //add Adafruit Motor Shield library
#include <Servo.h>        //add Servo Motor library            
#include <NewPing.h>      //add Ultrasonic sensor library

// PORTS ______________________________________________________________________________________________
#define TRIG_PIN A0 // Pin A0 on the Motor Drive Shield soldered to the ultrasonic sensor
#define ECHO_PIN A1 // Pin A1 on the Motor Drive Shield soldered to the ultrasonic sensor

// GLOBAL VARIABLES ___________________________________________________________________________________
#define MAX_DISTANCE 300 // sets maximum useable sensor measuring distance to 300cm
#define SPEED_R 150 // sets speed of DC traction motors to 150/250 or about 70% of full speed - to get power drain down.
#define SPEED_L 200
#define COLL_DIST 40 // sets distance at which robot stops and reverses to 30cm
#define TURN_DIST COLL_DIST+20 // sets distance at which robot veers away from object
#define BUTTON1 16
#define BUTTON2 17
#define CRASH 18
#define SPEAKER 19
#define SERVO_MIDDLE 58
#define SERVO_RIGHT 10
#define SERVO_LEFT 105
#define SERVO_PIN 10

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); // sets up sensor library to use the correct pins to measure distance.

AF_DCMotor leftMotor(3, MOTOR12_1KHZ); // create motor #1 using M1 output on Motor Drive Shield, set to 1kHz PWM frequency
AF_DCMotor leftMotor2(4, MOTOR34_1KHZ); // create motor #1 using M1 output on Motor Drive Shield, set to 1kHz PWM frequency
AF_DCMotor rightMotor(1, MOTOR12_1KHZ);// create motor #3, using M2 output, set to 1kHz PWM frequency
AF_DCMotor rightMotor2(2, MOTOR34_1KHZ);// create motor #3, using M2 output, set to 1kHz PWM frequency
Servo myservo;  // create servo object to control a servo

int leftDistance, rightDistance; //distances on either side
int curDist = 0;
bool button1pressed = false;
bool button2pressed = false;

// SETUP ______________________________________________________________________________________________
void setup() {
  myservo.write(SERVO_MIDDLE); // tells the servo to position at 90-degrees ie. facing forward.
  myservo.attach(SERVO_PIN);  // attaches the servo on pin 10 (SERVO_1 on the Motor Drive Shield to the servo object

  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(CRASH, INPUT_PULLUP);
  pinMode(SPEAKER, OUTPUT);

  stay();
}

// MAIN LOOP __________________________________________________________________________________________
void loop() {
  if (digitalRead(CRASH)) {
    moveStop();
    sound(-2);
    driveBackAndChangePath();
  }
  checkButtons();
  if (button1pressed && !digitalRead(CRASH)) {
    stay();
  }
  myservo.write(SERVO_MIDDLE);
  delay(20);
  curDist = readPing();   // read distance
  if (curDist < COLL_DIST) {
    changePath(); // if forward is blocked change direction
  }
  moveForward();  // move forward
  delay(200);
}
