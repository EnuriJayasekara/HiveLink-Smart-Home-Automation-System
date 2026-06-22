#include <SPI.h>
#include <MFRC522.h>
#include <ESP32Servo.h>

#define SS_PIN      5
#define RST_PIN     15
#define SERVO_PIN   12

MFRC522 rfid(SS_PIN, RST_PIN);
Servo myServo;

void setup() {
  Serial.begin(115200);

  SPI.begin();
  rfid.PCD_Init();

  myServo.setPeriodHertz(50);
  myServo.attach(SERVO_PIN, 500, 2400);

  myServo.write(0);

  Serial.println("Tap RFID card...");
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent()) return;
  if (!rfid.PICC_ReadCardSerial()) return;

  Serial.println("Card detected!");

  for (int pos = 0; pos <= 180; pos++) {
    myServo.write(pos);
    delay(10);
  }

  delay(3000);

  for (int pos = 180; pos >= 0; pos--) {
    myServo.write(pos);
    delay(10);
  }

  delay(1000);

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}
