// PIN DEFINITIONS 
const int ldrPin   = A0;
const int ledPin   = 7;
const int trigPin  = 9;
const int echoPin  = 10;
const int buzzer   = 8;



long duration;
float distance;
int frequency;
int ldrValue;

const int ldrThreshold = 100;   

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  //  LDR + LED LOGIC 
  ldrValue = analogRead(ldrPin);

  Serial.print("LDR Value: ");
  Serial.print(ldrValue);

  if (ldrValue > ldrThreshold) {
    digitalWrite(ledPin, HIGH);   // Bright → LED ON
  } else {
    digitalWrite(ledPin, LOW);    // Dark → LED OFF
  }

  //  ULTRASONIC SENSOR 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.034) / 2;

  Serial.print(" | Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  //  BUZZER (PARKING SOUND)
  if (distance > 0 && distance <= 2.7) {

    
    frequency = map(distance * 100, 230, 10, 1000, 3000);
    frequency = constrain(frequency, 1000, 3000);

    tone(buzzer, frequency);
    delay(60);
    noTone(buzzer);
    delay(30);

  } else {
    noTone(buzzer);
  }

  delay(100);
}

