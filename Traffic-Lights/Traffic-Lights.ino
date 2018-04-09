int green = 13; //define pins
int orange = 12;
int red = 11;
int turn = 10;
int delayTime = 1000; //time to use in all delays
void setup() {
  // put your setup code here, to run once:
  pinMode(green, OUTPUT); //set pins to output
  pinMode(orange, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(turn, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  cycle(); //call the cycle function, looping through the lights
}

void cycle() {
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
