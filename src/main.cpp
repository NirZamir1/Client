#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include <WiFi.h>
#include <ETH.h>
LiquidCrystal lcd(12,13,14,15,16,17);
WiFiClient client;
const char* name = "Zamir_2GExt"; //name of wifi network
const char* pssd = "sz123456";//password for the wifi
const char* Host = "DESKTOP-ORV5GO1";
const int port = 5000;
IPAddress ip;
int led = 18;
String Data;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  WiFi.begin(name,pssd);
  lcd.print("Connecting to");
  lcd.setCursor(0,1);
  lcd.print("WiFi");
  delay(2000);
  lcd.clear();
  while (WiFi.status() != WL_CONNECTED)
  {
    lcd.print("Connecting");
    delay(500);
    for (int i = 0; i < 3; i++)
    {
      lcd.print(".");
      delay(500);
    }
    lcd.clear();
    lcd.setCursor(0,0); 
  }
  lcd.print("Connected To");
  lcd.setCursor(0,1);
  lcd.print("WiFi-"+(String)name);
  delay(4000);
  lcd.clear();
  lcd.setCursor(0,0);
  int err = 0;
  while (err != 1)
  {
    err = WiFi.hostByName(Host,ip);
    delay(500);
  }
  
  lcd.print((String)Host);
  lcd.setCursor(0,1);
  lcd.print(ip);
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Connecting to");
  lcd.setCursor(0,1);
  lcd.print(Host);
  delay(3000);
  lcd.clear();
  client.connect(ip,port);
  while (client.connected() != true)
  {
    lcd.print("Connecting");
    delay(500);
    for (int i = 0; i < 3; i++)
    {
      lcd.print(".");
      delay(500);
    }
    lcd.clear();
    lcd.setCursor(0,0); 
  }
  lcd.print("Connected to");
  lcd.setCursor(0,1);
  lcd.print(Host);
  delay(3000);
  lcd.clear();
}

void loop() {
  lcd.setCursor(0,0);
  if (client.available())
  {
    Data = client.readStringUntil('\n');
    lcd.clear();
  }
  lcd.print("Data - " + Data);
  }