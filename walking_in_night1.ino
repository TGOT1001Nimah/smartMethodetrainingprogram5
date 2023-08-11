#define echopin  A1 // echo pin
#define trigpin A0 // Trigger pin
float duration, distance;
float l =A2;
int d1=6;
int d2 =5;
int d3=7;
float sensorValue;
void setup()
{
 pinMode(d1, OUTPUT);
   pinMode(d3, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode (l, INPUT );
   pinMode (trigpin, OUTPUT);
  pinMode (echopin, INPUT );
  Serial.begin(9600);
   
}
void loop()
{
 sensorValue = analogRead(A2);
  Serial.println( sensorValue);
 delay(20);
  digitalWrite(trigpin,LOW);
    delayMicroseconds(2);
    
    digitalWrite(trigpin,HIGH);
    delayMicroseconds(10);
    
    duration=pulseIn(echopin,HIGH);
   distance = duration * 0.034 / 2;
  Serial.println(distance);
   delay (10);
 
  if (sensorValue <=500){
    digitalWrite(7,HIGH);
    delay(50);
  } else {
    digitalWrite(7,LOW);
    delay(50);
  }
 if (distance < 60 ){
 digitalWrite(6,HIGH);
 digitalWrite(5,HIGH);
   delay(100);
   
}
  else{
digitalWrite(6,LOW);
 digitalWrite(5,LOW); 
    delay(100);
   
}

  
}