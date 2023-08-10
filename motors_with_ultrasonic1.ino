#define echopin  A1 // echo pin
#define trigpin A0 // Trigger pin
float duration, distance;

void setup() {
  pinMode (trigpin, OUTPUT);
  pinMode (echopin, INPUT );
  //H-bridge motors pins
pinMode(11, OUTPUT);
pinMode(6, OUTPUT);

pinMode(10, OUTPUT);
pinMode(5, OUTPUT);
  Serial.begin(9600);

}
void loop() {
  {
    digitalWrite(trigpin,LOW);
    delayMicroseconds(2);
    
    digitalWrite(trigpin,HIGH);
    delayMicroseconds(10);
    
    duration=pulseIn(echopin,HIGH);
   distance = duration * 0.034 / 2;
  Serial.println(distance);
   
    delay (50);
    
  }  
if (distance >= 60 ){
    digitalWrite(11,HIGH);
    digitalWrite(6,LOW);
    
    digitalWrite(5,LOW);
    digitalWrite(10,HIGH);//move forward
   
 
}

  if (distance <= 60 ){
    
    digitalWrite(11,LOW);
   
    digitalWrite(6,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(10,LOW);
    
 }//move backward
 
}