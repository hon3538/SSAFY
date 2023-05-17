// #include <MsTimer2.h>

/*
  SimpleMQTTClient.ino
  The purpose of this exemple is to illustrate a simple handling of MQTT and Wifi connection.
  Once it connects successfully to a Wifi network and a MQTT broker, it subscribe to a topic and send a message to it.
  It will also send a message delayed 5 seconds later.
*/

#include "EspMQTTClient.h"
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

hw_timer_t *timer = NULL;

int btn1=19;
int btn2=18;
int led1=5;
int led2=17;
#define DHTPIN 13
#define DHTTYPE DHT11
DHT_Unified dht(DHTPIN, DHTTYPE);

EspMQTTClient client(
  "MULTI_GUEST",
  "guest1357",
  "70.12.226.249",  // MQTT Broker server ip
  "MQTTUsername",   // Can be omitted if not needed
  "MQTTPassword",   // Can be omitted if not needed
  "TestClient",     // Client name that uniquely identify your device
  1883              // The MQTT port, default to 1883. this line can be omitted
);
int cnt=0;
char *topic="euiseon/hi";
String buf="Faker~";
void tx(){
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  client.publish("myroom/temp",String(event.temperature));
  dht.humidity().getEvent(&event);
  client.publish("myroom/humid", String(event.relative_humidity));
  client.publish("myroom/enter",buf); //btn
  cnt++;
}

void IRAM_ATTR onTimer() {
    // 이곳에 인터럽트 핸들링 코드를 작성한다.
    if (digitalRead(btn1) == 0)
      buf = "hi~"+String(cnt);
    else buf = "Faker~"+String(cnt);
}
void setup()
{
  Serial.begin(115200);

  // Optional functionalities of EspMQTTClient
  client.enableDebuggingMessages(); // Enable debugging messages sent to serial output
  client.enableHTTPWebUpdater(); // Enable the web updater. User and password default to values of MQTTUsername and MQTTPassword. These can be overridded with enableHTTPWebUpdater("user", "password").
  client.enableOTA(); // Enable OTA (Over The Air) updates. Password defaults to MQTTPassword. Port is the default OTA port. Can be overridden with enableOTA("password", port).
  client.enableLastWillMessage("TestClient/lastwill", "I am going offline");  // You can activate the retain flag by setting the third parameter to true
  //timer
  timer = timerBegin(0, 80, true); //프리스케일러 80, esp32 80Mhz이므로 1Mhz -> 1us 로 사용가능
  timerAttachInterrupt(timer, &onTimer, true);
  timerAlarmWrite(timer, 1000*100, true);
  timerAlarmEnable(timer);
  //Btn
  pinMode(btn1,INPUT_PULLUP);
  // MsTimer2::set(100,btn);
  // MsTimer2::start();
  dht.begin();

  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
}

// This function is called once everything is connected (Wifi and MQTT)
// WARNING : YOU MUST IMPLEMENT IT IF YOU USE EspMQTTClient
void onConnectionEstablished()
{
  // Subscribe to "mytopic/test" and display received message to Serial
  client.subscribe("myroom/led", [](const String & payload) {
    Serial.println("sd");
    if(payload.equals("ON")){
      if(digitalRead(led1)==LOW){
        digitalWrite(led1,HIGH);
      }else 
        digitalWrite(led1,LOW);
    }else if(payload.equals("OFF")){
      if(digitalRead(led2)==LOW){
        digitalWrite(led2,HIGH);
      }else 
        digitalWrite(led2,LOW);
    }
  });

  // Execute delayed instructions
  client.executeDelayed(5 * 1000, []() {
    client.publish("mytopic/wildcardtest/test123", "This is a message sent 5 seconds later");
  });
}

void loop()
{
  tx();
  client.loop();
  delay(2000);
}
