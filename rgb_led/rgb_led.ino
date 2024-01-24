int redPin = 11;
int greenPin = 10;
int bluePin = 9;

void setup() {
	pinMode(redPin, OUTPUT);
	pinMode(bluePin, OUTPUT);
	pinMode(greenPin, OUTPUT);
}

void userInput() {
  Serial.begin(4800);
  int red = Serial.parseInt();
  int blue = Serial.parseInt();
  int green = Serial.parseInt();

  // Werte zwischen 0-255
  red = constrain(red, 0, 255);
  green = constrain(green, 0, 255);
  blue = constrain(blue, 0, 255);

  if (red >= 0 && red <= 255 || green >= 0 && green <= 255 || blue >= 0 && blue <= 255) {
    Serial.print("red: " + String(red) + "green: " + String(green) + "blue: " + String(blue));
  }

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