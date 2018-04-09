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
long duration, distance;
boolean doLoop;

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
  digitalWrite(redMain, LOW);
  // Leave green on. If sensor triggered, cycle main, wait, cycle minor, back to start.
  getDistance();
  if (distance <4){
  doLoop = true;
    }
    
   if (doLoop == true){
    cycleLights(greenMain, orangeMain, redMain, turnMain);
    delay(delayTime);
    cycleLights(greenSide, orangeSide, redSide, turnSide);
    doLoop = false;
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

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin,HIGH);
  distance = (duration/2) / 29.1;
  Serial.println(distance);
  
  /*digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pulseWidth = pulseIn(echoPin, HIGH);
  Serial.print("Width")
  Serial.print(*/
  }
