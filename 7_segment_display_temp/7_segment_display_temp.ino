int SDI = 3;
int SCLK = 5;
int LOAD = 6;

int zahl[16];

// Low-Aktiv - 10 Ziffern mit jeweils 8 Bits
int ziffern[11][8] = { 
  { 1, 1, 0, 0, 0, 0, 0, 0 }, // 0
  { 1, 1, 1, 1, 1, 0, 0, 1 }, // 1
  { 1, 0, 1, 0, 0, 1, 0, 0 }, // 2
  { 1, 0, 1, 1, 0, 0, 0, 0 }, // 3
  { 1, 0, 0, 1, 1, 0, 0, 1 }, // 4
  { 1, 0, 0, 1, 0, 0, 1, 0 }, // 5
  { 1, 0, 0, 0, 0, 0, 1, 0 }, // 6
  { 1, 1, 1, 1, 1, 0, 0, 0 }, // 7
  { 1, 0, 0, 0, 0, 0, 0, 0 }, // 8
  { 1, 0, 0, 1, 0, 0, 0, 0 }, // 9
  { 1, 0, 1, 1, 1, 1, 1, 1 }  // -
};

void setup() {
  pinMode(SDI, OUTPUT);
  pinMode(SCLK, OUTPUT);
  pinMode(LOAD, OUTPUT);
}

void to16Bits(int nummer) {
  if (nummer >= 0 && nummer <= 99) { // 0 - 99
    for (int i = 0; i < 8; i++) {
      zahl[i] = ziffern[nummer / 10][i];
      zahl[i + 8] = ziffern[nummer % 10][i];
    }
    sendToDisplay();
  } else if (nummer <= -1 && nummer >= -9) { // -1 - -9
    for (int i = 0; i < 8; i++) {
      zahl[i] = ziffern[-1][i];
      zahl[i + 8] = ziffern[(nummer*(-1))]; 
    }
    sendToDisplay();
  } else if (nummer > 99) { // >99
    for (int i = 0; i < 8; i++) {
      zahl[i] = ziffern[9][i];
      zahl[i + 8] = ziffern[9][i];
    }
    sendToDisplay();
  } else if (nummer < -9) { // <-9
    for (int i = 0; i < 8; i++) {
      zahl[i] = ziffern[-1][i];
      zahl[i + 8] = ziffern[9][i];
    }
    sendToDisplay();
  }
}

void sendToDisplay() {
  digitalWrite(LOAD, LOW); // LOAD auf LOW, um Latch-Vorgang zu aktivieren - Speichermodus
  for (int i = 0; i < 16; i++) { // Schleife fuer 16 Bit Muster
    digitalWrite(SCLK, LOW);
    digitalWrite(SDI, zahl[i]);
    Serial.print(zahl[i]); // Kontrolle
    digitalWrite(SCLK, HIGH);
  }
  Serial.println("\n"); // Kontrolle
  digitalWrite(LOAD, HIGH);
}

void loop() {
  /* Test 0-99
  for(int i = 0; i <= 99; i++) {
    to16Bits(i);
    delay(1000);
  }
  */
}

// temp erfassung und berechnung einbauen
// erfasste temp in to16Bits() eingeben