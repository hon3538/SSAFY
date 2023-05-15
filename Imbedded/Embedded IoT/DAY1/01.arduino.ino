int btn1=19;
int btn2=18;

int led1=5;
int led2=17;
int led3=16;

int val=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  //Button
  pinMode(btn1,INPUT_PULLUP);
  pinMode(btn2,INPUT_PULLUP);

  //LED 
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(btn1)==0) val=1;
  if(digitalRead(btn2)==0) val=0; 
  digitalWrite(led1,val);
  digitalWrite(led2,val);
  digitalWrite(led3,val);
  delay(100);
}
