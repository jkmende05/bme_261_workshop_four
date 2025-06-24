// Pin definitions
const int ldrPin = A0;
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

// Light thresholds
int darkThreshold = 800;
int brightThreshold = 200;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lightLevel = analogRead(ldrPin);
  Serial.print("Light Level: ");
  Serial.println(lightLevel);

  if (lightLevel > darkThreshold) {
    setColor(0, 0, 255);
  } else if (lightLevel < brightThreshold) {
    setColor(255, 0, 0);
  } else {
    setColor(0, 50, 0);
  }

  delay(200);
}

void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
