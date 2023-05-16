#include <WiFi.h>
#include <FirebaseESP32.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#define FIREBASE_HOST "https://ssafy-70efb-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "0MxqC4juXDMygcYf7RFjXQwcxhbmWLqeUVLoljgT"

FirebaseData firebaseData;
FirebaseJson json;

#define WIFI_SSID "MULTI_GUEST"
#define WIFI_PASSWORD "guest1357"

#define DHTPIN 13
#define DHTTYPE DHT11
DHT_Unified dht(DHTPIN, DHTTYPE);
void setup()
{
  Serial.begin(115200);
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
  
  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

   dht.begin();
}

void loop()
{
    String str= "hello world!";
    sensors_event_t event;
    dht.temperature().getEvent(&event);
    json.set("temp", event.temperature);
    dht.humidity().getEvent(&event);
    json.set("humid", event.relative_humidity);
    Firebase.pushJSON(firebaseData, "/response", json); // 보내기, 송신
    Serial.println("PATH: " + firebaseData.dataPath());
    Serial.println("PUSH NAME: " + firebaseData.pushName());    
    

    delay(2000);
}