
#include <FirebaseArduino.h>

#include <ESP8266WiFi.h>

#define FIREBASE_HOST "smart-home-iot-ab2d0.firebaseio.com"
#define FIREBASE_AUTH "wtqvhF8I7Uzzx2E2rMlWp6qykINuKMByPzUDaPgK"
#define WIFI_SSID "smart-home-iot"
#define WIFI_PASSWORD "15042741052"

void setup() {

  Serial.begin(115200);
  Serial.println();
  Serial.print("Wifi connecting to ");
  Serial.println(WIFI_SSID);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.println();
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
    Serial.println("begin failed.");
    Serial.println(Firebase.error());
  }

}

void firebasereconnect()
{
  Serial.println("Trying to reconnect");
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {

  delay(120000);

  Serial.println("Reading from firebase : ");
  Serial.println(Firebase.getString("/Tracking/Location_Name"));

}

