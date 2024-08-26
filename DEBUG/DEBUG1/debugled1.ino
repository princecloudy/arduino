char pinsCount = 6;
int pins[] = { 3, 5, 6, 9, 10, 11 };

// void Turn(int i) {
//   for (int j = 0; j <= 255; j++) {
//     analogWrite(pins[i], j);
//     delay(5);
//   }
//   for (int j = 255; j >= 0; j--) {
//     analogWrite(pins[i], j);
//     delay(5);
//   }
// }

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < pinsCount; i++) {
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  int sensorValue = analogRead(A2);
  Serial.println(sensorValue);
  if (sensorValue < 512){
    for (int i = 0; i < 3; i++){
      for (int j = 0; j >= 255; j++){
        analogWrite(pins[i], j);
        delay(5);
      }
      for (int j = 255; j >= 0; j--){
        analogWrite(pins[i], j);
        delay(5);
      }
    }
    for (int i = 3; i > 0; i--){
      for (int j = 0; j >= 255; j++){
        analogWrite(pins[i], j);
        delay(5);
      }
      for (int j = 255; j >= 0; j--){
        analogWrite(pins[i], j);
        delay(5);
      }
    }
  }

  else if (sensorValue >= 512) {
    for (int i = pinsCount - 1; i >= 3; i--){
      for (int j = 0; j <= 255; j++){
        analogWrite(pins[i], j);
        delay(5);
      }
      for (int j = 255; j >= 0; j--){
        analogWrite(pins[i], j);
        delay(5);
      }
    }
    for (int i = 3; i < pinsCount; i++){
      for (int j = 0; j <= 255; j++){
        analogWrite(pins[i], j);
        delay(5);
      }
      for (int j = 255; j >= 0; j--){
        analogWrite(pins[i], j);
        delay(5);
      }
    }
  }
}