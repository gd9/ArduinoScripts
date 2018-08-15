const int ledPin = 9;
int i=0;
const int trigPin = 11;
const int echoPin = 13;
float duration,distance;
int fre;
int de=30;
void setup() {
  // put your setup code here, to run once:
 pinMode(ledPin,OUTPUT);
 Serial.begin(9600);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW); 
delayMicroseconds(2); 
digitalWrite(trigPin, HIGH); 
delayMicroseconds(2); 
digitalWrite(trigPin, LOW); 
duration = pulseIn(echoPin, HIGH);

distance=(duration/2)*0.0343;
distance=constrain(distance,0,200);
de=constrain(int(map(distance,0,200,10,3)),3,10);
fre=constrain(int(map(distance,0,200,100,30)),30,100);
Serial.println(distance);
for(i=0;i<255;i+=de){

  analogWrite(ledPin,i);
  if(distance<100){
  tone(6,fre);
  }else{
    noTone(6);
    }
  delay(10);
  }
  for(i=255;i>0;i-=de){
    analogWrite(ledPin,i);
    if(distance<100){
  tone(6,100-fre);
  }else{
    noTone(6);
    }
    delay(10);
    }
}

