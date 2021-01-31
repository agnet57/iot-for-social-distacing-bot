
#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  Serial.begin(9600); // set baud rate
  Serial.setTimeout(50);
  Serial.println("WELCOME++++");
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);

  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);

}

void loop() {
String ch;
 if (Serial.available() > 0) {
    ch= Serial.readString();
    Serial.println(ch);
  if (ch=="F") { 
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
 }
 if(ch=="B"){
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
 }
  if(ch=="L"){
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
 }
  if(ch=="S"){
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
 }
  if(ch=="LF"){
  motor1.run(RELEASE);
  motor2.run(FORWARD);
  motor3.run(RELEASE);
  motor4.run(FORWARD);
 }
  if(ch=="RF"){
  motor1.run(FORWARD);
  motor2.run(RELEASE);
  motor3.run(FORWARD);
  motor4.run(RELEASE);
 }
   if(ch=="LB"){
  motor1.run(RELEASE);
  motor2.run(BACKWARD);
  motor3.run(RELEASE);
  motor4.run(BACKWARD);
 }
   if(ch=="RB"){
  motor1.run(FORWARD);
  motor2.run(RELEASE);
  motor3.run(FORWARD);
  motor4.run(RELEASE);
 }
   if(ch=="R"){
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
 }
}
}
