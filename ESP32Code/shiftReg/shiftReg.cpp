// const int dataPin = 5;
// const int clockPin = 6;
// const int strobePin = 7;

// void setup() {
//   pinMode(dataPin, OUTPUT);
//   pinMode(clockPin, OUTPUT);
//   pinMode(strobePin, OUTPUT);

//   digitalWrite(dataPin, LOW);
//   digitalWrite(clockPin, LOW);
//   digitalWrite(strobePin, LOW);
// }

// void loop() {
//   for (int capteur = 0; capteur < 5; capteur++) {
//     Selecteur_CS(capteur);
//   }
// }

// void Selecteur_CS(int capteur) {
//   shiftOut(dataPin, clockPin, MSBFIRST, 1 << capteur);
//   digitalWrite(strobePin, HIGH);
//   digitalWrite(strobePin, LOW);
// }