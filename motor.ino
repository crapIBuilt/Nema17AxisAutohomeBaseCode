//Modified version of code by how2electronics
//Currently set up for 250mm ender 3 z axis.
#define dirPin 48
#define stepPin 46

const int buttonPin = 18; 
int buttonState = 0; 
int endstep = 100000;

void setup() 
{
  while (!Serial);
  // Set the maximum speed and acceleration:
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(62, OUTPUT);
  digitalWrite(62, LOW);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  int i = 0;
  int pos = 0;
  for (i = 0; i <= 5; i++) {
    buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH) {
      i = 10;
  } else {
    digitalWrite(dirPin,LOW);
    for(int x = 0; x < 10; x++) {
      digitalWrite(stepPin,HIGH); 
      delayMicroseconds(100); 
      digitalWrite(stepPin,LOW); 
      delayMicroseconds(100); 
    }
    i--;
  }
  }
  digitalWrite(dirPin,HIGH);
  for(long yu = 0; yu < 100000; yu++) { //insert end of axis in steps
      digitalWrite(stepPin,HIGH); 
      delayMicroseconds(50); 
      digitalWrite(stepPin,LOW); 
      delayMicroseconds(50); 
    }
  long position = 10000;

}
 
void loop() {
  //
}
