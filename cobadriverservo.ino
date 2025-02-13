#include <Servo.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>


int led = 13;


Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);
Servo myservo;


void setup() {
  Serial.begin(9600);
  Serial.println("16 channel PWM test!");

  pwm.begin();
  pwm.setPWMFreq(60);  // This is the maximum PWM frequency

  myservo.attach(8);
}

void loop() {
  // put your main code here, to run repeatedly:
  pwm.setPWM(3, 0, 125);
  delay(500);
  pwm.setPWM(3, 0, 575);
  delay(500);
}