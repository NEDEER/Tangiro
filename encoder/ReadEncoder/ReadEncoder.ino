int pinA=4;
volatile int encoder=0 ;
void setup(){
  pinMode(pinA,INPUT);
  Serial.begin(9600);
  attachInterrupt(1,interrupt,RISING);
}
void loop(){
  Serial.print("pulses:");
  Serial.println(encoder);
}
void interrupt(){
  encoder++;
}
