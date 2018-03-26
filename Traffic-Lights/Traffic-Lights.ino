int greenMain = 13;
int orangeMain = 12;
int redMain = 11;
int turnMain = 10;
int greenSide = 9;
int orangeSide = 8;
int redSide = 7;
int turnSide = 6;


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
}

void loop() {
  // put your main code here, to run repeatedly:
  cycleLights(greenMain, orangeMain, redMain, turnMain);
  delay(delayTime);
  cycleLights(greenSide, orangeSide, redSide, turnSide);
}

void cycleLights(int green, int orange, int red, int turn) {
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
