// Pulse Sensor Setup
const int pulsePin = A0; // Pulse sensor is connected to analog pin A0
int pulseValue = 0;      // Variable to store the sensor's value
int threshold = 550;     // Threshold for detecting a heartbeat
int lastPulse = 0;
unsigned long lastBeatTime = 0;
int beatsPerMinute = 0;

void setup() {
  Serial.begin(9600);    // Start the serial communication
}

void loop() {
  pulseValue = analogRead(pulsePin);  // Read the analog value from the pulse sensor

  // If the pulse value exceeds the threshold and the previous pulse was below it
  if (pulseValue > threshold && lastPulse <= threshold) {  
    lastPulse = pulseValue;
    unsigned long currentTime = millis();
    beatsPerMinute = 60000 / (currentTime - lastBeatTime); // Calculate BPM
    lastBeatTime = currentTime;
    Serial.print("Pulse detected! BPM: ");
    Serial.println(beatsPerMinute);  // Print the beats per minute to the serial monitor
  } else {
    lastPulse = pulseValue;
  }

  delay(10);  // Delay to stabilize the sensor readings
}
