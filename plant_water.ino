
const int WATER_ME = 15;
const int DONT_WATER_ME = 50;
const int DRY = 650;
const int WET = 428;
const int MOISTURE_SENSOR_PIN = A7;
const int PUMP_PINS[] = {2, 3, 4, 5};

void pump_control(bool power_on) {
  int setting = LOW;
  if (power_on) {
    setting = HIGH;
  }
  for (byte i = 0; i < (sizeof(PUMP_PINS) / sizeof(PUMP_PINS[0])); i++) {
    digitalWrite(PUMP_PINS[i], setting);
  }
}

void setup() {
  // Serial.begin(9600);
  for (byte i = 0; i < (sizeof(PUMP_PINS) / sizeof(PUMP_PINS[0])); i++) {
    pinMode(PUMP_PINS[i], OUTPUT);
  }
  pump_control(false);
}

void loop() {
  int moisture_val = analogRead(MOISTURE_SENSOR_PIN);
  int moisture_percent = map(moisture_val, WET, DRY, 100, 0);
  // Serial.println(moisture_val);
  // Serial.print(moisture_percent);
  // Serial.println("%");
  if (moisture_percent <= WATER_ME) {
    pump_control(true);
  } else if (moisture_percent >= DONT_WATER_ME) {
    pump_control(false);
  }
  delay(1000);
}
