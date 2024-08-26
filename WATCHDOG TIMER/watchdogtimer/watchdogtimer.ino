#include <avr/wdt.h>

#define tombol 12
#define potensio_mtr A0
#define LED 8

void setup() {
	MCUSR &= ~(1 << WDRF);  // Clear WDRF in MCUSR
	wdt_disable();
	pinMode(tombol, INPUT_PULLUP);
	pinMode(potensio_mtr, INPUT_PULLUP);
	pinMode(LED, OUTPUT);
	wdt_enable(WDTO_8S);

	for (int i=0; i <= 2; i++){
		digitalWrite(LED, HIGH);
		delay(500);
		digitalWrite(LED, LOW);
		delay(500);
	}
}

void loop() {
	int val = analogRead(potensio_mtr);
	analogWrite(LED, val);

	if (tombol == LOW){
		wdt_reset();
	}
}