#include <NewPing.h>
int greenMain = 13;
int orangeMain = 12;
int redMain = 11;
int turnMain = 10;
int greenSide = 9;
int orangeSide = 8;
int redSide = 7;
int turnSide = 6;
int trigPin = 5;
int echoPin = 4;
long duration;
int distance;
#define MAX_DISTANCE 200
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

int delayTime = 1000;
void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600); // Starts the serial communication

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(greenMain, HIGH);
  // Leave green on. If sensor triggered, cycle main, wait, cycle minor, back to start.
  getDistance();
  delay(100);
  if (distance <1){
  //if (0 == 1){
    cycleLights(greenMain, orangeMain, redMain, turnMain);
    delay(delayTime);
    cycleLights(greenSide, orangeSide, redSide, turnSide);
    }
}

void cycleLights(int green, int orange, int red, int turn) {
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  delay(delayTime);
  digitalWrite(green, LOW);//29.1
  digitalWrite(orange, HIGH);
  delay(1000);
  digitalWrite(orange, LOW);
  digitalWrite(red, HIGH);
  delay(1000);
  digitalWrite(turn, HIGH);
  delay(1000);
  digitalWrite(turn, LOW);
}
void getDistance(){
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  }
