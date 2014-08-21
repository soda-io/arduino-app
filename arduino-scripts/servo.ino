// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
   Serial.begin(115200); // открыть серийный порт на скорости 115200 бит/с
  myservo.attach(9);  // attaches the servo on pin 9 and 10 to the servo object 
  myservo.write(pos);
} 
 
 void move(int p)
 {
   pos += p;
   myservo.write(pos);
 }
 
void loop() 
{
 
   while(Serial.available() > 0) {
      String ttydata = Serial.readString(); // ttyData - информация с серийного порта
      if (ttydata.substring(0,6) == "left90") {
        Serial.println("left90");
        move(90);
      } else if (ttydata.substring(0,8) == "right110") {
         Serial.println("right110");
         move(-110);
         } else if (ttydata.substring(0,2) == "AD") {
           Serial.println("rl180");
           move(100);
           delay(200);
           move(-80);
      } else {
        Serial.println("error");
     }
  } 
} 
