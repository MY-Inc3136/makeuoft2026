// Ultrasonic Sensor Pins
const int trigPin = 9;
const int echoPin = 11;

// Motor A (Left)
const int PWMA = 3;  // Speed
const int AIN1 = 4;  // Direction 1
const int AIN2 = 5;  // Direction 2

// Motor B (Right)
const int PWMB = 10;  // Speed
const int BIN1 = 7;  // Direction 1
const int BIN2 = 8;  // Direction 2

// Coordinates for Map Plotting
const int posX = 0;
const int posY = 1;
const int negX = 2;
const int negY = 3;

int currentCoord = posX;
int coords[4] = {1, 1, -1, -1}; // coordinates array

void setup() {
  Serial.begin(9600); // Talk to the computer

  // Ultrasonic Sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Motor Driver
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

}

void loop() {

  // search function
  search();

  if(objectDetected()) {
    Serial.println("Object within range detected!");
    goToObject();
  }

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
    
  delay(1000);

}


// --- HELPER FUNCTIONS ---

bool objectDetected() {

  long duration;
  int distance;
  
  // Standard Ultrasonic Ping
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(echoPin, LOW);
  
  duration = pulseIn(echoPin, HIGH, 20000);
  distance = duration * 0.034 / 2;

  Serial.print("Object within ");
  Serial.print(distance);
  Serial.println(" cm");

  if(distance >= 0 && distance < 20)
    return true;
  else
    return false;
  
}

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

  coord[currentCoord] += 10;

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

  coord[currentCoord] -= 10;

  Serial.println("Action: Backward");
}

void turnRight() {
  // Left motor forward, Right motor backward (Spin turn)
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, 150);
  
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  analogWrite(PWMB, 150);
  

  if (currentCoord < 3)
    currentCoord += 1;
  else
    currentCoord = x;

  Serial.println("Action: Turning Right");

  delay(1000) // calibrate to be 90 degrees
}

// REMOVED TURN LEFT FUNCTION. Reason: redundant

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

void search() {

  // Search for objects
  while(!objectDetected()) {
    turnRight();
    moveForward(50);
    delay(1000);
    
  }
  
}

void goToObject() {

  // Move towards an identified object

  Serial.println("Moving towards detected object...");
  while (objectDetected()) {
    moveForward(150);
  }
  
  Serial.println("Object location found.");
  // Print to Serial at the end to communicate with map.py script
  Serial.print("MAP:");
  Serial.print(coords[0] - coords[2]);  // x + (-x)
  Serial.print(",");
  Serial.println(coords[1] - coords[3]); // y + (-y)
  
}
