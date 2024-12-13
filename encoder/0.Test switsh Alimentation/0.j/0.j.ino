int motorPin1 = 7;           // Motor driver IN1 pin
int motorPin2 = 8;           // Motor driver IN2 pin
int enablePin = 9;  
void setup() {
  // put your setup code here, to run once:
  pinMode(motorPin1, OUTPUT); // Set motor control pins as output
  pinMode(motorPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  runMotor(155);
  delay(1000);
  stopMotor();
  delay(1000);

}
void runMotor(int speed) {
  Serial.println("Motor running...");
  digitalWrite(motorPin1, HIGH); // Set motor direction
  digitalWrite(motorPin2, LOW);
  analogWrite(enablePin, speed); // Control motor speed with PWM (0-255)
}

// Function to stop the motor
void stopMotor() {
  Serial.println("Motor stopped.");
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  analogWrite(enablePin, 0); // Stop motor by setting PWM to 0
}
