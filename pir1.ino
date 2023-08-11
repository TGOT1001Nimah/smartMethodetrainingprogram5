// C++ code
int pir = 3;
int r = 13;

void setup()
{
  pinMode(r, OUTPUT);
  pinMode(pir, INPUT);
  Serial.begin(9600);
}

void loop()
{
  if (digitalRead(pir)){
    Serial.print("light");
    digitalWrite(r, HIGH);}
  else{
   digitalWrite(r,LOW);
   Serial.print("no light");}
   delay(100);
}