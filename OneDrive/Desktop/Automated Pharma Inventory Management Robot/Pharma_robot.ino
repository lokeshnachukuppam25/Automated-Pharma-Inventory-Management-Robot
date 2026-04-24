#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// RFID configuration
#define SS_PIN 10
#define RST_PIN 9
MFRC522 rfid(SS_PIN, RST_PIN);

// Ultrasonic sensor pins
#define trigPin 6
#define echoPin 7

// Motor driver pins
#define motor1 2
#define motor2 3
#define motor3 4
#define motor4 5

// Servo motor
Servo arm;

// LCD display
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Distance variables
long duration;
int distance;

// Medicine RFID IDs
byte med1[4] = {0xA3, 0xB1, 0xC2, 0xD4};
byte med2[4] = {0xF2, 0x11, 0x22, 0x33};

void setup()
{
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);

  arm.attach(8);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Pharma Robot");
  delay(2000);
}

void loop()
{
  readRFID();
  obstacleDetection();
}

// RFID reading function
void readRFID()
{
  if (!rfid.PICC_IsNewCardPresent())
    return;

  if (!rfid.PICC_ReadCardSerial())
    return;

  lcd.clear();

  if (compareUID(rfid.uid.uidByte, med1))
  {
    lcd.print("Medicine 1");
    moveRobot();
  }
  else if (compareUID(rfid.uid.uidByte, med2))
  {
    lcd.print("Medicine 2");
    moveRobot();
  }
  else
  {
    lcd.print("Unknown Item");
  }

  delay(2000);
}

// Compare RFID UID
boolean compareUID(byte a[], byte b[])
{
  for (int i = 0; i < 4; i++)
  {
    if (a[i] != b[i])
      return false;
  }
  return true;
}

// Robot movement
void moveRobot()
{
  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, HIGH);
  digitalWrite(motor4, LOW);

  delay(2000);

  stopRobot();
  pickMedicine();
}

void stopRobot()
{
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, LOW);
}

// Robotic arm
void pickMedicine()
{
  arm.write(0);
  delay(1000);

  arm.write(90);
  delay(1000);

  arm.write(0);
}

// Ultrasonic obstacle detection
void obstacleDetection()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  if (distance < 20)
  {
    stopRobot();
    lcd.clear();
    lcd.print("Obstacle!");
  }
}