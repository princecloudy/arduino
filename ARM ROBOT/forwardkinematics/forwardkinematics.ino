#include <math.h>
#include <Servo.h>

Servo servo0;
Servo servo1;
Servo servo2;
Servo servo3;

const float d0 = 0; //Define DH parameters
const float d1 = 0;
const float d2 = 0;
const float d3 = 0;

float theta0 = 0; // Joint angles in degrees
float theta1 = 0;
float theta2 = 0;
float theta3 = 0;

float theta0_rad = radians(theta0); // Convert joint angles in radian
float theta1_rad = radians(theta1);
float theta2_rad = radians(theta2);
float theta3_rad = radians(theta3);

// float x = 0; // Coordinates in mm
// float y = 0;
// float z = 0;

//Calculate forward kinematics
void forwardkinematics(float& endeff_x, float& endeff_y){
  endeff_x = cos(theta0_rad) + d1 * cos(theta0_rad + theta1_rad) + d2 * cos(theta0_rad + theta1_rad + theta2_rad) + d3 * cos(theta0_rad + theta1_rad + theta2_rad + theta3_rad);
  endeff_y = sin(theta0_rad) + d1 * sin(theta0_rad + theta1_rad) + d2 * sin(theta0_rad + theta1_rad + theta2_rad) + d3 * sin(theta0_rad + theta1_rad + theta2_rad + theta3_rad);
}

void setup() {
 Serial.begin(9600);
 servo0.attach(9);
 servo1.attach(3);
 servo2.attach(5);
 servo3.attach(6);
}

void loop() {
  // Print the calculated end effector position (x, y, z)
  float endeff_x, endeff_y;
  forwardkinematics(endeff_x, endeff_y);
  Serial.print("End Effector Position (x, y): ");
  Serial.print(endeff_x);
  Serial.print(", ");
  Serial.print(endeff_y);

  // Add a delay between calculations
  delay(1000);
}