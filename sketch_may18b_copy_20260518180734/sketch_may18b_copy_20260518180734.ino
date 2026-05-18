const int analogPin = A0;
const float knownResistor = 98.6; // 10kΩ — must match your resistor
const float supplyVoltage = 5.05;     // 5V from Arduino

void setup() {
  Serial.begin(9600);
  Serial.println("Arduino Ohmmeter Ready");
  Serial.println("------------------------");
}

void loop() {
  int rawValue = analogRead(analogPin);

  // Convert ADC reading to voltage at midpoint
  float vMid = rawValue * (supplyVoltage / 1023.0);

  // Avoid division by zero (open circuit)
  if (vMid >= supplyVoltage - 0.01) {
    Serial.println("No resistor detected (open circuit)");
  }
  // Avoid short circuit (R_x ≈ 0)
  else if (vMid <= 0.01) {
    Serial.println("Short circuit or 0Ω detected");
  }
  else {
    // Voltage divider formula: R_x = R_known * V_mid / (Vsupply - V_mid)
    float resistance = knownResistor * (vMid / (supplyVoltage - vMid));

    // Temperature formula: T = ((R/100) - 1) / 0.003851
    float temperature = ((resistance / 100.0) - 1.0) / 0.003851;

    // Pretty print resistance
    if (resistance >= 1000000.0) {
      Serial.print("Resistance: ");
      Serial.print(resistance / 1000000.0, 2);
      Serial.println(" MΩ");
    } else if (resistance >= 1000.0) {
      Serial.print("Resistance: ");
      Serial.print(resistance / 1000.0, 2);
      Serial.println(" kΩ");
    } else {
      Serial.print("Resistance: ");
      Serial.print(resistance, 1);
      Serial.println(" Ω");
    }

    // Print temperature
    Serial.print("Temperature: ");
    Serial.print(temperature, 2);
    Serial.println(" °C");
    Serial.println("------------------------");
  }

  delay(500);
}