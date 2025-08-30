

#include<LiquidCrystal_I2C.h>

//#define echo 2
//#define trig 3
long duration, distance;
LiquidCrystal_I2C ITO(0x27, 16, 2);

long bacaJarak (int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin,LOW);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ITO.init();
  ITO.backlight();
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int cm = 0;
  cm = (0.03446 * bacaJarak(3, 2)/2);

  Serial.print("Jarak : ");
  Serial.print(cm);
  Serial.println("cm");
  

  ITO.setCursor(0, 0);
  ITO.print("Jarak : ");
  ITO.print(cm);
  ITO.println("cm");

  delay(100);

  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);

  if(cm > 15){
    digitalWrite(12, HIGH);
  } else if(cm >= 5 && cm <= 15){
    digitalWrite(11, HIGH);
  } else if (cm < 5){
    digitalWrite(10, HIGH);
  }

}
