// Motor A (Left)
const int PWMA = 3;  // Speed
const int AIN1 = 4;  // Direction 1
const int AIN2 = 5;  // Direction 2

// Motor B (Right)
const int PWMB = 10;  // Speed
const int BIN1 = 7;  // Direction 1
const int BIN2 = 8;  // Direction 2

// Standby Pin
// not necessary because it's plugged into 3.3V

void setup() {
  
  Serial.begin(9600);
  
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  // No STBY pin logic needed here

}

void loop() {

  moveForward(150);
  delay(2000);

  moveBackward(150);
  delay(2000);
    
  turnRight(150);
  delay(2000);

  turnLeft(150);
  delay(2000);
  
  stopMotors();
  delay(3000);
}

// --- HELPER FUNCTIONS ---

void moveForward(int speed) {
  // TESTED - WORKS
  
  // Motor A Forward
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, speed);

  // Motor B Forward - Revised to combine moveForward with original turnRight
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  analogWrite(PWMB, speed);
  
  Serial.println("Action: Forward");

}


void moveBackward(int speed) {
  // Motor A Backward
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, speed);
  
  // Motor B Backward
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, speed);
  
  Serial.println("Action: Backward");
}

void turnRight(int speed) {
  // Left motor forward, Right motor backward (Spin turn)
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, speed);
  
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  analogWrite(PWMB, speed);
  
  Serial.println("Action: Turning Right");
}

void turnLeft(int speed) {
  // Right motor forward, Left motor backward (Spin turn)
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, speed);
  
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, speed);
  
  Serial.println("Action: Turning Left");
}

void stopMotors() {
  analogWrite(PWMA, 0);
  analogWrite(PWMB, 0);
  // Optional: Set direction pins to LOW to save power
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
  
  Serial.println("Action: Stopped");
}
