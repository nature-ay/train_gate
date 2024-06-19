#include <Servo.h>

Servo myservo;  

const int triggerPinA = 4;// D2
const int echoPinA = 5;// D1
const int triggerPinB = 12;// D6
const int echoPinB = 13;// D7
int distanceA, distanceB;
long durationA, durationB;
int servo = 180;


void setup() {
  myservo.attach(2);  // D4
  pinMode(triggerPinA, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPinA, INPUT); // Sets the echoPin as an Input
  pinMode(triggerPinB, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPinB, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
SensorA();
SensorB();
delay(20);
myservo.write(servo);

 
 
if (distanceA < 15 && distanceB > 15) 
  {   
        myservo.write(servo);
        delay(21);
  }

if (distanceA < 15 && distanceB < 15) 
  {
    for (; servo >= 0; servo -= 1)
    {
        myservo.write(servo);
        delay(35);
    }
  }

if (distanceA > 15 && distanceB < 15) 
    {
      myservo.write(servo);
      delay(35);
    }

if (distanceA > 15 && distanceB > 15) 
    {
      for (; servo <= 180; servo += 1)
      {
          myservo.write(servo);
          delay(21);
      }
    }
  
}

void SensorA() {
  digitalWrite(triggerPinA, LOW);                   
  delayMicroseconds(2);
  digitalWrite(triggerPinA, HIGH);                  
  delayMicroseconds(10);
  digitalWrite(triggerPinA, LOW);                   

  durationA = pulseIn(echoPinA, HIGH);
  distanceA = (durationA * 0.0343) / 2;
  delay(100);

  Serial.print("distance A = ");
  Serial.print(distanceA);
  Serial.print(" cm");
  Serial.println();
  delay(100);
}


void SensorB() {
  digitalWrite(triggerPinB, LOW);                   
  delayMicroseconds(2);
  digitalWrite(triggerPinB, HIGH);                  
  delayMicroseconds(10);
  digitalWrite(triggerPinB, LOW);                   

  durationB = pulseIn(echoPinB, HIGH);
  distanceB = (durationB * 0.0343) / 2;
  delay(100);

  Serial.print("distance B = ");
  Serial.print(distanceB);
  Serial.print(" cm");
  Serial.println();
  delay(100);
}