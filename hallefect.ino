void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("ESP32 Hall Sensor Reading Example (Alternative)");
  Serial.println("--------------------------------------------");
}

void loop() {
  // Alternative method using analogRead
  int hallValue = analogRead(36);  // GPIO 36 on some ESP32 boards
  
  Serial.print("Hall sensor value: ");
  Serial.println(hallValue);
  
  delay(500);
}
