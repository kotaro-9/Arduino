int redPin = 11;
int greenPin = 10;
int bluePin = 9;

bool randomColor = false;

void setup() {
	pinMode(redPin, OUTPUT);
	pinMode(bluePin, OUTPUT);
	pinMode(greenPin, OUTPUT);
  randomSeed(analogRead(0));
}

void userCustomColor() {
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

  if (red != 0 || green != 0 || blue != 0) {
    setColor(red, blue, green);
  }
}

void setRandomColor() {
  setColor(random(256), random(256), random(256));
}

void setColor(int red, int blue, int green) {
	analogWrite(redPin, red);
	analogWrite(bluePin, green);
	analogWrite(greenPin, blue);
}

void loop() {
  if (randomColor = false) {
    userCustomColor();
  } else {
    randomColor = true;

  }
  delay(3000);
}