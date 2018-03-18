int green = 13;
int orange = 12;
int red = 11;
int turn = 10;
int delayTime = 1000;
void setup() {
  // put your setup code here, to run once:
  pinMode(green, OUTPUT);
  pinMode(orange, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(turn, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  cycle();
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
