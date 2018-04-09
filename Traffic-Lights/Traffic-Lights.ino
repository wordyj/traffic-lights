int greenMain = 13; //set pins
int orangeMain = 12;
int redMain = 11;
int turnMain = 10;
int greenSide = 9;
int orangeSide = 8;
int redSide = 7;
int turnSide = 6;
int trigPin = 5;
int echoPin = 4;
long duration, distance; //variables for sensor
boolean doLoop; //boolean for cycleLights trigger.

int delayTime = 1000; //time for all light change delays
void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT); //LEDs as outputs
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  
  pinMode(trigPin, OUTPUT); //sensor trig as output and eco as input.
  pinMode(echoPin, INPUT);

  Serial.begin(9600); // Starts the serial monitor

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(greenMain, HIGH); //set the green on while the sensor is not triggered.
  digitalWrite(redMain, LOW); //set the opposite set's red light to be on.
  // Leave green on. If sensor triggered, cycle main, wait, cycle minor, back to start.
  getDistance();
  if (distance <4){ //if there is something within 4cm of the sensor cycle the lights
  doLoop = true;
    }
    
   if (doLoop == true){ //when the sensor is triggered, loop both the lights, return to the top and wait for the sensor to be triggered again
    cycleLights(greenMain, orangeMain, redMain, turnMain);
    delay(delayTime);
    cycleLights(greenSide, orangeSide, redSide, turnSide);
    doLoop = false;
    }
}

void cycleLights(int green, int orange, int red, int turn) { //sequencialy turns lights off
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  delay(delayTime);
  digitalWrite(green, LOW);
  digitalWrite(orange, HIGH);
  delay(1000);
  digitalWrite(orange, LOW);
  digitalWrite(red, HIGH);
  delay(1000);
  digitalWrite(turn, HIGH);
  delay(1000);
  digitalWrite(turn, LOW);
}
void getDistance(){ //ping with the sensor and calculates distance

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin,HIGH);
  distance = (duration/2) / 29.1;
  Serial.println(distance);
  }
