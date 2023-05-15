
//ESP32 는 아두이노에서 제공하는 PWM제어를 사용할 수 없다
//-> 직접 구현해야한다.
const int led=16;
const int freq=5000;
const int ledChannel = 0;
const int resolution =8;

int val=0;
void setup() {
  // put your setup code here, to run once:
  ledcSetup(ledChannel, freq, resolution); // 채널, 주파수, 해상도
  ledcAttachPin(led, ledChannel); //핀 번호, 채널

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int dutyCycle=0;dutyCycle<=255;dutyCycle++){
    ledcWrite(ledChannel,dutyCycle);
    delay(15);
  }
  for(int dutyCycle=255;dutyCycle>=0;dutyCycle--){
    ledcWrite(ledChannel,dutyCycle);
    delay(15);
  }
}
