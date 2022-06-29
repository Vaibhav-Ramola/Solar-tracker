#include <Servo.h>

Servo motor;

void setup()
{
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  motor.attach(6);
  delay(500);
  Serial.begin(9600);
  motor.write(90);
}

void loop()
{
  int pr1 = analogRead(A5);
  int pr2 = analogRead(A4);
  Serial.print("Value of top Photo resistor : ");
  Serial.println(pr1);
  Serial.print("Value of bottom Photo resistor : ");
  Serial.println(pr2);
  orient(pr1, pr2);
  delay(1000); // Wait for 1000 millisecond(s)
}

void orient(int pr1, int pr2)
{
  int diff = pr1-pr2;
  float angle = (diff * 90.0)/679.0;
  Serial.println(angle);
  motor.write(90.0+angle);
}