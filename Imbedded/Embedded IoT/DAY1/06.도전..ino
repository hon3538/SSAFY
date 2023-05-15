

//스케치-> 라이브러리 포함하기 -> 라이브러리 관리
//dht11 검색 -> DHT sensor library 설치 -> 종속된 라이브러리 같이 설치
//파일 -> 예제 -> DHT sensor library -> DHT_Unified_sensor
//예제 코드 불러왔으면 핀과 dht sensor type 등만 수정해서 사용

// DHT Temperature & Humidity Sensor
// Unified Sensor Library Example
// Written by Tony DiCola for Adafruit Industries
// Released under an MIT license.

// REQUIRES the following Arduino libraries:
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 13     // Digital pin connected to the DHT sensor 
// Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
// Pin 15 can work but DHT must be disconnected during program upload.

// Uncomment the type of sensor in use:
#define DHTTYPE    DHT11     // DHT 11
//#define DHTTYPE    DHT22     // DHT 22 (AM2302)
//#define DHTTYPE    DHT21     // DHT 21 (AM2301)

// See guide for details on sensor wiring and usage:
//   https://learn.adafruit.com/dht/overview

DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;
const int btn_up=19;
const int btn_down=18;

const int led1=5;
const int led2=17;
const int led3=16;

const int adc=36;
const int freq=5000;

const int ledChannel =0;
const int resolution =8;

int bright=255;
int btn_val;
int adc_val; //0~4095

int cnt=0;
void setup() {
  Serial.begin(9600);
  // Initialize device.
  pinMode(btn_up,INPUT_PULLUP);
  pinMode(btn_down,INPUT_PULLUP);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(adc,INPUT);

  ledcSetup(ledChannel,freq,resolution);
  ledcAttachPin(led1,ledChannel);

  dht.begin();
  Serial.println(F("DHTxx Unified Sensor Example"));
  // Print temperature sensor details.
  sensor_t sensor;

  Serial.begin(9600);
  // Initialize device.
  dht.temperature().getSensor(&sensor);
  Serial.println(F("------------------------------------"));
  Serial.println(F("Temperature Sensor"));
  Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
  Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version);
  Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id);
  Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("°C"));
  Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("°C"));
  Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("°C"));
  Serial.println(F("------------------------------------"));
  // Print humidity sensor details.
  dht.humidity().getSensor(&sensor);
  Serial.println(F("Humidity Sensor"));
  Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
  Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version);
  Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id);
  Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("%"));
  Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("%"));
  Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("%"));
  Serial.println(F("------------------------------------"));
  // Set delay between sensor readings based on sensor details.
  delayMS = sensor.min_delay / 1000;
}

void loop() {
   btn_val=0;
  if(digitalRead(btn_up)==0) btn_val=1;
  if(digitalRead(btn_down)==0) btn_val=2;

  if(btn_val==1){
    bright+=50;
    if(bright>255) bright=255;
  }else if(btn_val==2){
    bright-=50;
    if(bright<0) bright=0;
  }

  adc_val=analogRead(adc);
  ledcWrite(ledChannel,bright);
  if(adc_val>1500){
    digitalWrite(led2,LOW);
    digitalWrite(led3,HIGH);
  }else if(adc_val<700){
    digitalWrite(led3,LOW);
    digitalWrite(led2,HIGH);
  }else{
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
  }

  if(Serial.available()){
    String s=Serial.readString();
    int n=s.toInt();
    bright=25*n;
    if(bright>255) bright=255;
    if(bright<0) bright=0;
    ledcWrite(ledChannel,bright);
  }
  delay(100);
  cnt++;
  if(cnt<10) return;
  cnt=0;
  // Get temperature event and print its value.
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println(F("Error reading temperature!"));
  }
  else {
    Serial.print("ID: ");
    Serial.println(event.sensor_id);
    Serial.print("PWM: ");
    Serial.println(bright);
    Serial.print(F("Temperature: "));
    Serial.print(event.temperature);
    Serial.println(F("°C"));
  }

  Serial.println("adc_val: "+String(adc_val));
  
}

   