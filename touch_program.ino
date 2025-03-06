void setup() {
  Serial.begin(115200);
}

void loop() {
  int touchValue = touchRead(T0); // Read touch pin T0 (GPIO4)
  Serial.println(touchValue);
  delay(100);
}
