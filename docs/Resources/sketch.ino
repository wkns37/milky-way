const int PIN_LED = 2;

void setup() {
  Serial.begin(9600);
  pinMode(PIN_LED, OUTPUT);
}

enum {
	NONE,
	READ_THRESHOLD_VOLTAGE,
	SET_THRESHOLD_VOLTAGE,
	READ_CURRENT_VOLTAGE
};

static uint8_t read8() {
	return Serial.read();
}

static uint16_t read16() {
	uint16_t val = 0;
	Serial.readBytes((uint8_t*)&val, sizeof(val));
	return val;
}

static void write8(uint8_t val) {
	Serial.write(&val, sizeof(val));
}

static void write16(uint16_t val) {
	Serial.write((uint8_t*)&val, sizeof(val));
}

static uint16_t threshold_voltage;

void loop() {
	uint16_t current_voltage = analogRead(A0) / 1023.0 * 5000.0;
	
	if (Serial.available() > 0) {
		uint8_t mode = read8();
		switch (mode) {
			case READ_THRESHOLD_VOLTAGE: {
				write16(threshold_voltage);
			} break;
			
			case SET_THRESHOLD_VOLTAGE: {
				threshold_voltage = read16();
			} break;
			
			case READ_CURRENT_VOLTAGE: {
				write16(current_voltage);
			} break;
			
			default: break;
		}
	}
	
	digitalWrite(PIN_LED, current_voltage <= threshold_voltage ? HIGH : LOW);
}
