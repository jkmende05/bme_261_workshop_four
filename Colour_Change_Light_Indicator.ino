// Pin definitions
const int ldrPin = A0;     // Pin connected to LDR (Light Dependent Resistor)
const int redPin = 9;      // Red channel of RGB LED (PWM pin)
const int greenPin = 10;   // Green channel of RGB LED (PWM pin)
const int bluePin = 11;    // Blue channel of RGB LED (PWM pin)

// Light thresholds (adjust these based on your actual lighting conditions)
int darkThreshold = 800;     // Above this value, it's considered dark
int brightThreshold = 200;   // Below this value, it's considered bright

void setup() {
  // Set RGB LED pins as output
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Start serial communication for monitoring light level
  Serial.begin(9600);
}

void loop() {
  // Read the current light level from the LDR
  int lightLevel = analogRead(ldrPin);

  // Print the light level to the Serial Monitor
  Serial.print("Light Level: ");
  Serial.println(lightLevel);

  // Conditional logic based on light level:
  if (lightLevel > darkThreshold) {
    // If it's dark → turn LED blue
    setColor(0, 0, 255);
  } else if (lightLevel < brightThreshold) {
    // If it's bright → turn LED red
    setColor(255, 0, 0);
  } else {
    // If it's moderate → turn LED green (dimmed)
    setColor(0, 50, 0);
  }

  delay(200); // Small delay for stability
}

// Function to set RGB LED color using PWM values (0–255)
void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
