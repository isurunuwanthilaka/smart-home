#include <FirebaseArduino.h>
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>

#define FIREBASE_HOST "******"
#define FIREBASE_AUTH "******"
#define WIFI_SSID "smart-home-iot"
#define WIFI_PASSWORD "15042741052"

SoftwareSerial NodeMCU(D2, D3);
String LocationName;

void setup() {

  Serial.begin(9600);
  NodeMCU.begin(9600);
  pinMode(D2, INPUT);
  pinMode(D3, OUTPUT);

  Serial.println();
  Serial.print("Wifi connecting to ");
  Serial.println(WIFI_SSID);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.print("Connecting");

  while ( WiFi.status() != WL_CONNECTED ) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Wifi Connected Success!");
  Serial.print("NodeMCU IP Address : ");
  Serial.println(WiFi.localIP() );

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  if (Firebase.failed()) {
    Serial.println(Firebase.error());
  }
}

void firebasereconnect()
{
  Serial.println("Trying to reconnect");
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  Serial.print("Reading from firebase : ");
  LocationName = Firebase.getString("/Tracking/Location_Name");
  Serial.println(LocationName);
  NodeMCU.print(LocationName);
  NodeMCU.print("\n");
  delay(10000);
}

