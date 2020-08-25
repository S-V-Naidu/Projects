int WATERPUMP = 13; //motor pump connected to pin 13
int sensor = 8; //sensor digital pin vonnected to pin 8
int val; 
void setup() {
  
  pinMode(13,OUTPUT); //Set pin 13 as OUTPUT pin
  pinMode(8,INPUT); 
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  while (! Serial);// wait for serial port to connect.
  Serial.println("Speed 0 to 255");
}

void loop()
  { 
  if (Serial.available()) //loop to operate motor
  {
    int speed = Serial.parseInt(); 
    if (speed >= 0 && speed <= 255)
    {
      analogWrite(WATERPUMP, speed); 
    }
  }
  val = digitalRead(8);  //Read data from soil moisture sensor  
  if(val == LOW) 
  {
  digitalWrite(13,LOW); 
  }
  else
  {
  digitalWrite(13,HIGH);
  }
  delay(400); //Wait for few second and then continue the loop.
}