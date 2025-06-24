const int buttonPin = 2;
const int ledPin = 9;

int brightnessLevel = 0;
int buttonState = 0;
int lastButtonState = 0;

int brightnessValues[] = {0, 85, 170, 255};

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW && lastButtonState == HIGH) {
    brightnessLevel++;
    if (brightnessLevel > 3) {
      brightnessLevel = 0;
    }
    analogWrite(ledPin, brightnessValues[brightnessLevel]);
    Serial.print("Brightness level: ");
    Serial.println(brightnessLevel);
    delay(200);
  }

  lastButtonState = buttonState;
}
