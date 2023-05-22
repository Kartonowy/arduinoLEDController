const int PIN_RED = 5;
const int PIN_GREEN = 6;
const int PIN_BLUE = 9;
String pyinput;

uint8_t RGB[3];

void hexToRGBArray(const String& hex, uint8_t rgb[]) {
  if (hex.length() != 6) {
    // Invalid hexadecimal color code
    return;
  }

  for (int i = 0; i < 3; i++) {
    uint8_t highNibble = hex.charAt(i * 2);
    uint8_t lowNibble = hex.charAt(i * 2 + 1);

    uint8_t highByte = (highNibble >= '0' && highNibble <= '9') ? (highNibble - '0') : (highNibble - 'A' + 10);
    uint8_t lowByte = (lowNibble >= '0' && lowNibble <= '9') ? (lowNibble - '0') : (lowNibble - 'A' + 10);

    rgb[i] = (highByte << 4) | lowByte;
  }
}

void setup() {
  // put your setup code here, to run once:  
  Serial.begin(9600);

  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  while (Serial.available() == 0) {}

  pyinput = Serial.readStringUntil('\r');

  hexToRGBArray(pyinput, RGB);

  Serial.println(pyinput);

  setColor(RGB);

}

void setColor(uint8_t RGB[]) {
  analogWrite(PIN_RED, RGB[0]);
  analogWrite(PIN_GREEN, RGB[1]);
  analogWrite(PIN_BLUE, RGB[2]);
}