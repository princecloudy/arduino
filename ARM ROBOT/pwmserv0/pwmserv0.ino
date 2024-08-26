#include <ESP32Servo.h>

//Servo servo1;
//Servo servo2;
//Servo servo3; 
//Servo servo4; 
//int angle = 0;

Servo myservo;

void setup() {
  // servo0.attach(3);
  // servo1.attach(5); 
  // servo2.attach(6); 
  myservo.attach(23); 
}


void loop() {
  // for (angle = 0; angle = 30; angle--) { 
  // servo0.write(angle);              
  // servo1.write(angle);     
  // servo2.write(angle);
  // servo3.write(angle);         
  // delay(10);                      
  // }

  // for (angle = 30; angle = 0; angle++) { 
  // servo0.write(angle);                
  // servo1.write(angle);     
  // servo2.write(angle);
  // servo3.write(angle);          
  // delay(10);                      
  // }

  // servo0.write(1);                
  // servo1.write(angle);     
  // servo2.write(angle);
  myservo.write(0);
  delay(2000);
  myservo.write(90);
  delay(2000);
}

