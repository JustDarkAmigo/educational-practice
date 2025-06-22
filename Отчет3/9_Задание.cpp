const int redLedPin = 9;
const int greenLedPin = 5;
const int photoResistorPin = A0;
const int threshold = 512;
const unsigned long doorOpenTime = 5000;

bool doorOpen = false;
unsigned long doorOpenStartTime = 0;

void setup() {
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  Serial.begin(9600);
  digitalWrite(redLedPin, HIGH);
  digitalWrite(greenLedPin, LOW);
  Serial.println("Двери закрыты");
}

void loop() {
  int sensorValue = analogRead(photoResistorPin);
  
  if (sensorValue > threshold) {
    if (!doorOpen) {
      doorOpen = true;
      doorOpenStartTime = millis();
      digitalWrite(redLedPin, LOW);
      digitalWrite(greenLedPin, HIGH);
      Serial.println("Двери открываются");
    } else {
      if (millis() - doorOpenStartTime >= doorOpenTime) {
        sensorValue = analogRead(photoResistorPin);
        if (sensorValue <= threshold) {
          doorOpen = false;
          digitalWrite(greenLedPin, LOW);
          digitalWrite(redLedPin, HIGH);
          Serial.println("Двери закрываются");
        } else {
          doorOpenStartTime = millis();
        }
      }
    }
  } else if (doorOpen && (millis() - doorOpenStartTime >= doorOpenTime)) {
    doorOpen = false;
    digitalWrite(greenLedPin, LOW);
    digitalWrite(redLedPin, HIGH);
    Serial.println("Двери закрываются (время истекло)");
  }
  
  delay(100);
}
