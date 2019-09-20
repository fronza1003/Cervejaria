#include <Servo.h>

Servo servo;
int angle = 10;

void setup() {
  servo.attach(8);
  servo.write(angle);
}

void loop() 
{ 
  // de a 0 a 180 graus
  for(angle = 10; angle < 180; angle++)  
  {                                  
    servo.write(angle);               
    delay(15);                   
  } 
  // de 180 a 0 graus
  for(angle = 180; angle > 10; angle--)    
  {                                
    servo.write(angle);           
    delay(15);       
  } 
}
