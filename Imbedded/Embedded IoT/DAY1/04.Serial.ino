
int led=17;

void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600); //baud rate 맞춰줘야함
}

void loop() {
  if( Serial.available()){
    char a=Serial.read();
    if(a=='o'){
      digitalWrite(led,HIGH);
      Serial.println("LED ON");
    }
    if(a=='x'){
      digitalWrite(led,LOW);
      Serial.println("LED OFF");
    }
  }
  delay(100);
}
