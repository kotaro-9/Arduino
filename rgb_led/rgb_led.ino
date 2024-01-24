int redPin = 11;
int greenPin = 10;
int bluePin = 9;

void setup() {
	pinMode(redPin, OUTPUT);
	pinMode(greenPin, OUTPUT);
	pinMode(bluePin, OUTPUT);
}

void setColor(int red, int green, int blue) {
	analogWrite(redPin, red);
	analogWrite(greenPin, green);
	analogWrite(bluePin, blue);
}

void loop() {
  setColor(255, 0, 255);
}