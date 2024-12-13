int pinA = 2;               // Encoder pin
volatile int encoder = 0;    // Pulse counter

int motorPin1 = 7;           // Motor driver IN1 pin
int motorPin2 = 8;           // Motor driver IN2 pin
int enablePin = 9;           // Motor driver ENA (speed control, PWM pin)

unsigned long startTime;     // Variable to store the start time

void setup() {
  pinMode(pinA, INPUT);      // Set encoder pin as input
  pinMode(motorPin1, OUTPUT); // Set motor control pins as output
  pinMode(motorPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  startTime = millis();

  Serial.begin(9600);

  // Attach interrupt to encoder pin
  attachInterrupt(digitalPinToInterrupt(pinA), interrupt, RISING);


  
  
}

void loop() {
  if (millis() - startTime < 2000) {
    runMotor(255);
    Serial.print("Pulses: ");
    Serial.println(encoder);
  } else {
    // Stop the motor after 2 seconds
    stopMotor();
  }
}

// Interrupt Service Routine (ISR) to count encoder pulses
void interrupt() {
  encoder++;
}

// Function to run motor at a specific speed
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
