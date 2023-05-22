const int PIN_RED = 5;
const int PIN_GREEN = 6;
const int PIN_BLUE = 9;

void setup() {
  // put your setup code here, to run once:  
  Serial.begin(9600);

  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  int RGB[3] = {251, 0, 255};
  setColor(RGB);

}

void setColor(int RGB[]) {
  analogWrite(PIN_RED, RGB[0]);
  analogWrite(PIN_GREEN, RGB[1]);
  analogWrite(PIN_BLUE, RGB[2]);
}