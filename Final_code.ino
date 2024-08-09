
#include <Servo.h>
Servo s = Servo();

#include <Ultrasonic.h>
Ultrasonic u = Ultrasonic(4,3);

void setup() {
  // put your setup code here, to run once:
  s.attach(8);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  analogWrite(11, 200);

  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  analogWrite(5, 200);

  pinMode(2, OUTPUT);
  pinMode(10, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int d = u.distanceRead();
  Serial.println(d);
  int x = Serial.read();
  if (x == '1') {
    s.write(90);
    digitalWrite(2, HIGH);
    delay(300);
    digitalWrite(2, LOW);
    int d = u.read();
    if (d > 10) {
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      delay(500);
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
    }
    if (d < 10) {
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
    }
  }
  if (x == '2') {
    digitalWrite(10, HIGH);
    delay(300);
    digitalWrite(10, LOW);
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    delay(500);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }

  if (x == '0') {
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }

  if (x == '3') {
    s.write(120);
    delay(300);
    int d = u.read();
    if (d > 10) {
      digitalWrite(12, HIGH);
      digitalWrite(13, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(6, HIGH);
      delay(500);
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
    }
    s.write(90);
  }

  if (x == '4') {
    s.write(30);
    delay(300);
    int d = u.read();
    if (d > 10) {
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(6, HIGH );
      delay(500);
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
    }
    s.write(90);
  }
}
