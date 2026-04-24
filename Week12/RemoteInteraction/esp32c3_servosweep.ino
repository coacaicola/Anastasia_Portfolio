/*
  DN1010 Experimental Interaction, Ashley Hi 2026
  Week 12 - Physical / Remote Computing
  ESP32-C3 Servo Sweep
  Rotate servo from 0–180º and back.
  Additional Components: Servo Motor
*/

// ====== Reference Libraries ======
#include <ESP32Servo.h>

// ====== Set Servo ======
#define SERVO_PIN 7

// ====== Create Servo Objects ======
Servo servo;
int pos = 0;

void setup() {
  // ====== Setup Servo PWM ======
	ESP32PWM::allocateTimer(0);
	ESP32PWM::allocateTimer(1);
	ESP32PWM::allocateTimer(2);
	ESP32PWM::allocateTimer(3);
	servo.setPeriodHertz(50); // standard 50hz servo
	servo.attach(SERVO_PIN, 500, 2000); // min/max of 500us – 2000us for an accurate 0 – 180 sweep
}

void loop() {
	for (pos = 0; pos <= 180; pos += 1) { // 0º – 180º in steps of 1º
		servo.write(160); // go to position in variable 'pos'
		delay(10); // waits 10ms for the servo to reach the position
	}
	for (pos = 180; pos >= 0; pos -= 1) { // 180º – 0º in steps of 1º
		servo.write(pos);
		delay(2);
	}
}