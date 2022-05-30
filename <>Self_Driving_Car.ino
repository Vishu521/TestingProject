#include <HCSR04.h>
UltraSonicDistanceSensor ultrasonic(A0,A1);
float distance;
// left motor
int leftMotorSpeedPin = 3;
int leftMotorForwardPin = 4;
int leftMotorBackwardPin = 5;
// right motor
int rightMotorSpeedPin = 11;
int rightMotorForwardPin = 12;
int rightMotorBackwardPin = 13;
void setup() {
    pinMode(leftMotorSpeedPin, OUTPUT);
    pinMode(leftMotorForwardPin, OUTPUT);
    pinMode(leftMotorBackwardPin, OUTPUT);
    pinMode(rightMotorSpeedPin, OUTPUT);
    pinMode(rightMotorForwardPin, OUTPUT);
    pinMode(rightMotorBackwardPin, OUTPUT);
    Serial.begin(9600);
  digitalWrite(leftMotorSpeedPin, HIGH);
  digitalWrite(rightMotorSpeedPin, HIGH);
   
}
void loop() {
  distance = ultrasonic.measureDistanceCm(); //Use 'CM' for centimeters or 'INC' for inches
  Serial.println(distance);
  if (distance > -1 && distance < 25) {
    stop();
    delay(1000);
    goBackward();
    delay(300);
    stop();
    delay(1000);
    
    if(random(0, 2) == 0) {
      goLeft();
    } else {
      goRight();
    }
    
    delay(500);
    stop();
    delay(700);
  } else {
    goForward();
  }
}
void goForward() {
  digitalWrite(leftMotorForwardPin, HIGH);
  digitalWrite(leftMotorBackwardPin, LOW);
  digitalWrite(rightMotorForwardPin, HIGH);
  digitalWrite(rightMotorBackwardPin, LOW);
}
void goBackward() {
  digitalWrite(leftMotorForwardPin, LOW);
  digitalWrite(leftMotorBackwardPin, HIGH);
  digitalWrite(rightMotorForwardPin, LOW);
  digitalWrite(rightMotorBackwardPin, HIGH);
}
void stop() {
  digitalWrite(leftMotorForwardPin, LOW);
  digitalWrite(leftMotorBackwardPin, LOW);
  digitalWrite(rightMotorForwardPin, LOW);
  digitalWrite(rightMotorBackwardPin, LOW);
}
void goRight() {
  digitalWrite(leftMotorForwardPin, HIGH);
  digitalWrite(leftMotorBackwardPin, LOW);
  digitalWrite(rightMotorForwardPin, LOW);
  digitalWrite(rightMotorBackwardPin, LOW);
}
void goLeft() {
  digitalWrite(leftMotorForwardPin, LOW);
  digitalWrite(leftMotorBackwardPin, LOW);
  digitalWrite(rightMotorForwardPin, HIGH);
  digitalWrite(rightMotorBackwardPin, LOW);
}