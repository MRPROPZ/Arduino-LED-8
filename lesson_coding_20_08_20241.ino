#define SOIL_SENSOR_PIN A2
const int LED_PINS[] = {2, 3, 4, 5, 6, 7, 8, 9};

void setup() {
  pinMode(SOIL_SENSOR_PIN, INPUT);
  for (int i = 0; i < 8; i++) {
    pinMode(LED_PINS[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  int soilValue = analogRead(SOIL_SENSOR_PIN);
  int moistureLevel = map(soilValue, 0, 876, 0, 255);
  String moistureBinary = String(moistureLevel, BIN);
  Serial.print("Soil Decimal: ");
  Serial.println(moistureLevel);
  Serial.print("Soil Binary: ");
  Serial.println(moistureBinary);
  Serial.println();
  for (int i = 0; i < 8; i++) {
    if (moistureLevel & (1 << i)) {
      digitalWrite(LED_PINS[i], HIGH);
    } else {
      digitalWrite(LED_PINS[i], LOW);
    }
  }

  delay(500);
}