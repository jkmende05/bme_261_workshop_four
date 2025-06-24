const int buttonPin = 2;   // Pin number where the button is connected
const int ledPin = 9;      // Pin number where the LED is connected (must be PWM-capable)

int brightnessLevel = 0;   // Tracks current brightness level index (0 to 3)
int buttonState = 0;       // Current reading from the button pin
int lastButtonState = 0;   // Previous button state (used for edge detection)

int brightnessValues[] = {0, 85, 170, 255}; // Predefined PWM brightness levels (0 = off, 255 = full brightness)

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Configure button pin as input with internal pull-up resistor
  pinMode(ledPin, OUTPUT);          // Set LED pin as an output
  Serial.begin(9600);               // Start serial communication for debugging
}

void loop() {
  buttonState = digitalRead(buttonPin); // Read the current state of the button

  // Detect button press: only trigger when button goes from HIGH to LOW (pressed)
  if (buttonState == LOW && lastButtonState == HIGH) {
    brightnessLevel++;               // Move to the next brightness level
    if (brightnessLevel > 3) {       // Wrap around if it exceeds the last index
      brightnessLevel = 0;
    }

    // Set the LED brightness using PWM
    analogWrite(ledPin, brightnessValues[brightnessLevel]);

    // Print the current brightness level to the Serial Monitor
    Serial.print("Brightness level: ");
    Serial.println(brightnessLevel);

    delay(200); // Debounce delay to prevent multiple triggers from a single press
  }

  lastButtonState = buttonState; // Save the current button state for comparison in the next loop
}
