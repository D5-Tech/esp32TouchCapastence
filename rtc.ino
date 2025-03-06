#include <WiFi.h>
#include "time.h"

// Replace with your WiFi credentials
const char* ssid     = "Devan";
const char* password = "devanarayanan";

// NTP Server
const char* ntpServer = "pool.ntp.org";
long  gmtOffset_sec = 19800;  // Adjust for your timezone (IST = GMT+5:30 = 19800 sec)
int   daylightOffset_sec = 0; // Set 0 if no daylight savings

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");

  // Initialize NTP
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}

void loop() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("Failed to obtain time");
    return;
  }

  // Convert 24-hour time to 12-hour format
  int hour12 = timeinfo.tm_hour % 12;
  if (hour12 == 0) hour12 = 12; // Handle midnight case

  // Determine AM or PM
  String am_pm = (timeinfo.tm_hour >= 12) ? "PM" : "AM";

  // Print time in 12-hour format
  Serial.print("Current Time: ");
  Serial.print(hour12);
  Serial.print(":");
  Serial.print(timeinfo.tm_min < 10 ? "0" : ""); // Add leading zero if needed
  Serial.print(timeinfo.tm_min);
  Serial.print(":");
  Serial.print(timeinfo.tm_sec < 10 ? "0" : ""); // Add leading zero if needed
  Serial.print(timeinfo.tm_sec);
  Serial.print(" ");
  Serial.println(am_pm);

  delay(1000); // Update every second
}
