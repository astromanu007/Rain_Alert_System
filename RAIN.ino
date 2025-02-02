int rainSensorPin = A0;   // Pin connected to the rain sensor (analog output)
int buzzerPin = 3;         // Pin connected to the buzzer
int ledPin = 9;            // Pin connected to the LED
int rainThreshold = 500;   // Adjust this threshold value based on your sensor readings

void setup() {
  Serial.begin(9600);         // Start serial communication for debugging
  pinMode(buzzerPin, OUTPUT); // Set buzzerPin as output
  pinMode(ledPin, OUTPUT);    // Set ledPin as output
  pinMode(rainSensorPin, INPUT); // Set rainSensorPin as input
}

void loop() {
  int sensorValue = analogRead(rainSensorPin);  // Read rain sensor value

  Serial.print("Rain Sensor Value: ");
  Serial.println(sensorValue); // Print the sensor value to Serial Monitor

  // If sensor value exceeds threshold, rain is detected
  if (sensorValue < rainThreshold) {   // Change logic to < for rain detection
    digitalWrite(buzzerPin, HIGH);     // Turn on the buzzer
    digitalWrite(ledPin, HIGH);        // Turn on the LED
    Serial.println("Rain detected! Alert triggered.");
  } else {
    digitalWrite(buzzerPin, LOW);      // Turn off the buzzer
    digitalWrite(ledPin, LOW);         // Turn off the LED
    Serial.println("No rain detected.");
  }
  delay(1000); // Delay for stability
}
