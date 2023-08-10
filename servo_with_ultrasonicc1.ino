#define echopin  A1 // echo pin
#define trigpin A0 // Trigger pin
float duration, distance;
#include <Servo.h>
Servo s9;
#define servoPin 9
void setup()
{
 s9.attach( 9);
   pinMode (trigpin, OUTPUT);
  pinMode (echopin, INPUT );
  Serial.begin(9600);
   s9.write(90);
}

void loop()
{
  digitalWrite(trigpin,LOW);
    delayMicroseconds(2);
    
    digitalWrite(trigpin,HIGH);
    delayMicroseconds(10);
    
    duration=pulseIn(echopin,HIGH);
   distance = duration * 0.034 / 2;
  Serial.println(distance);
   
    delay (50);  
if (distance >= 60 ){
 s9.write(0);
   
}
else if (distance <= 60 ){
 s9.write(170);
   
}
  
}