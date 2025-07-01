#define RED_PIN 9
#define GREEN_PIN 5
#define PHOTO_PIN A0
#define LIGHT_THRESHOLD 512
#define DOOR_OPEN_DELAY 3000
unsigned long doorOpenTime = 0;
bool doorIsOpen = false;

void setup() {
  Serial.begin(115200);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  digitalWrite(RED_PIN, HIGH);
}

void loop() {
  int lightValue = analogRead(PHOTO_PIN);
  if (lightValue > LIGHT_THRESHOLD && !doorIsOpen) {
    openDoor();
    doorOpenTime = millis();
  }
  if (doorIsOpen && (millis() - doorOpenTime >= DOOR_OPEN_DELAY)) {
    if (analogRead(PHOTO_PIN) <= LIGHT_THRESHOLD) {
      closeDoor();
    } else {
      doorOpenTime = millis();
    }
  }
}

void openDoor() {
  doorIsOpen = true;
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  Serial.println("Дверь открывается");
}

void closeDoor() {
  doorIsOpen = false;
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(RED_PIN, HIGH);
  Serial.println("Дверь закрывается");
}
