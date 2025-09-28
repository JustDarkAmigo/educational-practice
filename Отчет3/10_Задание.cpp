#include <Servo.h>
Servo myservo;
int currentAngle = 90;
int targetAngle = 90;
void setup() {
  myservo.attach(3);
  Serial.begin(9600);
  Serial.println("Введите угол (0-180):");
  myservo.write(currentAngle);
}
void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    bool isNumber = true;
    for (int i = 0; i < input.length(); i++) {
      if (!isdigit(input.charAt(i))) {
        isNumber = false;
        break;
      }
    }
    if (isNumber) {
      targetAngle = input.toInt();
      
      if (targetAngle >= 0 && targetAngle <= 180) {
        Serial.print("Поворот на: ");
        Serial.print(targetAngle);
        Serial.println("°");
        
        if (targetAngle != currentAngle) {
          int step = (targetAngle > currentAngle) ? 1 : -1;
          while (currentAngle != targetAngle) {
            currentAngle += step;
            myservo.write(currentAngle);
            delay(15);
          }
        }
      } else {
        Serial.println("Ошибка: угол должен быть от 0 до 180!");
      }
    } else {
      Serial.println("Ошибка: введите число!");
    }
  }
}
