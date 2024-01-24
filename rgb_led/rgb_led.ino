int redPin = 11;
int greenPin = 10;
int bluePin = 9;

void setup() {
	pinMode(redPin, OUTPUT);
	pinMode(bluePin, OUTPUT);
	pinMode(greenPin, OUTPUT);
}

void userInput() {
  Serial.begin(9600);
  int red = Serial.parseInt();
  int blue = Serial.parseInt();
  int green = Serial.parseInt();

  // Werte zwischen 0-255
  red = constrain(red, 0, 255);
  green = constrain(green, 0, 255);
  blue = constrain(blue, 0, 255);

  Serial.println(red);
  Serial.println(green);
  Serial.println(blue);

  setColor(red, blue, green);
}

void setColor(int red, int blue, int green) {
	analogWrite(redPin, red);
	analogWrite(bluePin, green);
	analogWrite(greenPin, blue);
}

void loop() { 
  userInput();
  delay(3000);
}