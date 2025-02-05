#define LED_MERAHI 13
#define LED_KUNING 12
#define LED_HIJAUI 11
#define LED_MERAHII 8
#define LED_HIJAUII 9
#define Buzzer A0
#define TOMBOL 2

int state = 1;
int input_sblm = HIGH;
int tepi_naik = HIGH;

unsigned long waktu_debouncing = 0;
unsigned long delay_debouncing = 50;

int input = LOW;
int kondisi_sblm = LOW;

unsigned long waktu_state = 0;
unsigned long delay_state1 = 10000;
unsigned long delay_state2 = 1500;
unsigned long delay_state3 = 8000;

void state_1();
void state_2();
void state_3();
void state_4();

void setup() {
Serial.begin(9600);

  pinMode(LED_MERAHI, OUTPUT);
  pinMode(LED_MERAHII, OUTPUT);
  pinMode(LED_KUNING, OUTPUT);
  pinMode(LED_HIJAUI, OUTPUT);
  pinMode(LED_HIJAUII, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(TOMBOL, INPUT_PULLUP);
}

void loop() {
Serial.println(waktu_state);
  int kondisi = digitalRead(TOMBOL);
  if (kondisi != kondisi_sblm) {
    waktu_debouncing = millis();
  }
  if ((millis() - waktu_debouncing) > delay_debouncing) {
    if (kondisi != input) {
      input = kondisi;
    }
  }
  kondisi_sblm = kondisi;
  if (input == LOW && input_sblm == HIGH) {
    input_sblm = input;
  } else if (input == HIGH && input_sblm == LOW) {
    input_sblm = input;
    tepi_naik = LOW;
  }

  switch (state) {
    case 1:
      state_1();
      if ((millis() - waktu_state) > delay_state1) {
        state = 2;
        waktu_state = millis();
      }
      break;

    case 2:
      state_2();
      if ((millis() - waktu_state) > delay_state2) {
        state = 3;
        waktu_state = millis();
      }
      break;
    case 3:
      state_3();
      if ((millis() - waktu_state) > delay_state3) {
        state = 1;
        waktu_state = millis();

      } else if (tepi_naik == LOW) {
        state = 4;
        waktu_state = millis();
      }
      break;
    case 4:
      digitalWrite(LED_MERAHI, LOW);
      digitalWrite(LED_MERAHII, HIGH);
      digitalWrite(LED_HIJAUI, HIGH);
      digitalWrite(LED_HIJAUII, LOW);
      digitalWrite(LED_KUNING, HIGH);
      digitalWrite(Buzzer, HIGH);
      delay(1000);
      digitalWrite(LED_KUNING, LOW);
      digitalWrite(Buzzer, LOW);
      delay(1000);
      digitalWrite(LED_KUNING, HIGH);
      digitalWrite(Buzzer, HIGH);
      delay(1000);
      digitalWrite(LED_KUNING, LOW);
      digitalWrite(Buzzer, LOW);
      delay(1000);
      digitalWrite(LED_KUNING, HIGH);
     digitalWrite(Buzzer, HIGH);
      delay(1000);
      digitalWrite(LED_KUNING, LOW);
      digitalWrite(Buzzer, LOW);
      delay(1000);
      state = 1;
      waktu_state = millis();
      break;
  }
  tepi_naik = HIGH;
}

void state_1() {
  digitalWrite(LED_MERAHI, HIGH);
  digitalWrite(LED_MERAHII, LOW);
  digitalWrite(LED_KUNING, LOW);
  digitalWrite(LED_HIJAUI, LOW);
  digitalWrite(LED_HIJAUII, HIGH);
}

void state_2() {
  digitalWrite(LED_MERAHI, LOW);
  digitalWrite(LED_MERAHII, LOW);
  digitalWrite(LED_KUNING, HIGH);
  digitalWrite(LED_HIJAUI, LOW);
  digitalWrite(LED_HIJAUII, LOW);
}

void state_3() {
  digitalWrite(LED_MERAHI, LOW);
  digitalWrite(LED_MERAHII, HIGH);
  digitalWrite(LED_KUNING, LOW);
  digitalWrite(LED_HIJAUI, HIGH);
  digitalWrite(LED_HIJAUII, LOW);
}
