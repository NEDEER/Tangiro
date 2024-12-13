//Pin Out
const int IN1 = 2;
const int IN2 = 3;


const int ENA = 5; //pin for speed control en1

void setup() {

  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);

  pinMode (ENA, OUTPUT);


}

void loop() {
 //control speed 
          //(pin, speed)  
  analogWrite(ENA, 200);

  
  //control direction 
  digitalWrite(IN1, HIGH);
  delay(2000);
  digitalWrite(IN1, LOW);
  delay(2000);
  digitalWrite(IN2, HIGH);
  delay(2000);
  digitalWrite(IN2, LOW);
  delay(2000);


}
