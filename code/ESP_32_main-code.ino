
#define BLYNK_TEMPLATE_ID "TMPL6hyJjoi5A"
#define BLYNK_TEMPLATE_NAME "FC project"
#define BLYNK_AUTH_TOKEN  "POu-6dlPWXMNkA6xCMFcN7KGa3WlILAk"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// WIFI 
char ssid[] = "Galaxy A06 7916";
char pass[] = "23456789";

// LIBRARIES 
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// PIN DEFINITIONS  
#define DHTPIN 18
#define DHTTYPE DHT11

#define RELAY_PIN 23        
#define MQ2_AO 34
#define BUZZER 33

// Room light LEDs
#define LED1 25
#define LED2 26
#define LED3 27
#define LED4 13

// THRESHOLDS 
#define TEMP_THRESHOLD 30
#define GAS_THRESHOLD  2000


DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
BlynkTimer timer;


volatile int lightControl = 0;
bool fanState = false;
bool gasAlert = false;

// BLYNK LIGHT CONTROL (V3) 
BLYNK_WRITE(V3) {
  lightControl = param.asInt();

  digitalWrite(LED1, lightControl);
  digitalWrite(LED2, lightControl);
  digitalWrite(LED3, lightControl);
  digitalWrite(LED4, lightControl);

  Blynk.virtualWrite(V4, lightControl ? "ON" : "OFF");
}


void updateSystem() {

  float temperature = dht.readTemperature();
  float humidity    = dht.readHumidity();
  int gasValue      = analogRead(MQ2_AO);

  if (isnan(temperature) || isnan(humidity)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("DHT ERROR");
    lcd.setCursor(0, 1);
    lcd.print("Check Sensor");

    Blynk.virtualWrite(V4, "ERR");
    Blynk.virtualWrite(V5, "ERR");
    Blynk.virtualWrite(V7, "DHT ERROR\nCheck Sensor");
    return;
  }

  //FAN CONTROL 
  if (temperature >= TEMP_THRESHOLD) {
    digitalWrite(RELAY_PIN, LOW);  
    fanState = true;
  } else {
    digitalWrite(RELAY_PIN, HIGH); 
    fanState = false;
  }

  // GAS ALERT 
  if (gasValue >= GAS_THRESHOLD) {
    gasAlert = true;
    tone(BUZZER, 3000);
  } else {
    gasAlert = false;
    noTone(BUZZER);
  }

  // BLYNK UPDATE 
  Blynk.virtualWrite(V0, temperature);
  Blynk.virtualWrite(V1, humidity);
  Blynk.virtualWrite(V2, gasValue);
  Blynk.virtualWrite(V4, lightControl ? "ON" : "OFF");
  Blynk.virtualWrite(V5, gasAlert ? "ALERT" : "SAFE");
  Blynk.virtualWrite(V6, "17:00-06:00");

 
  char appLcd[80];
  snprintf(appLcd, sizeof(appLcd),
           "Temp:%.1fC Hum:%.0f%%\nGas:%d %s",
           temperature, humidity, gasValue,
           gasAlert ? "ALERT" : "SAFE");
  Blynk.virtualWrite(V7, appLcd);

 
  static bool screen = false;
  screen = !screen;

  lcd.clear();
  if (!screen) {
    lcd.setCursor(0, 0);
    lcd.print("Gas:");
    lcd.print(gasValue);
    lcd.setCursor(0, 1);
    lcd.print(gasAlert ? "Gas: ALERT" : "Gas: SAFE ");
  } else {
    lcd.setCursor(0, 0);
    lcd.print("T:");
    lcd.print((int)temperature);
    lcd.print(" H:");
    lcd.print((int)humidity);
    lcd.print("%");
    lcd.setCursor(0, 1);
    lcd.print("Fan:");
    lcd.print(fanState ? "ON " : "OFF");
    lcd.print(" L:");
    lcd.print(lightControl ? "ON" : "OFF");
  }

  
  Serial.print("T:");
  Serial.print(temperature);
  Serial.print(" H:");
  Serial.print(humidity);
  Serial.print(" Gas:");
  Serial.print(gasValue);
  Serial.print(" Fan:");
  Serial.print(fanState ? "ON" : "OFF");
  Serial.print(" Lights:");
  Serial.println(lightControl ? "ON" : "OFF");
}

void setup() {
  Serial.begin(115200);

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  digitalWrite(RELAY_PIN, HIGH);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  noTone(BUZZER);

  analogReadResolution(12);
  analogSetAttenuation(ADC_11db);

  dht.begin();
  Wire.begin(21, 22);
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("HiveLink Home");
  lcd.setCursor(0, 1);
  lcd.print("Starting...");
  delay(2000);
  lcd.clear();

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(2000L, updateSystem);
}

void loop() {
  Blynk.run();
  timer.run();
}

