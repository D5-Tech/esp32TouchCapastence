#define TOUCH_PIN T0  // Touch sensor pin (GPIO4)
#define LED_PIN 2      // Built-in LED on GPIO2

void setup() {
  pinMode(LED_PIN, OUTPUT);  
  Serial.begin(115200);
}

void loop() {
  int touchValue = touchRead(TOUCH_PIN);  // Read touch input
  Serial.println(touchValue);  // Print value for debugging

  if (touchValue < 60) {  // Adjust this threshold if needed
    digitalWrite(LED_PIN, HIGH); // Turn LED ON
  } else {
    digitalWrite(LED_PIN, LOW);  // Turn LED OFF
  }

  delay(100);
}
