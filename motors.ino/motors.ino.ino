// Motor A (Left)
const int PWMA = 3;  // Speed
const int AIN1 = 4;  // Direction 1
const int AIN2 = 5;  // Direction 2

// Motor B (Right)
const int PWMB = 6;  // Speed
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
  // Test: Spin Forward for 2 seconds
  Serial.println("Spinning forward");
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, 180); 

  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, 180);
  
  delay(2000);
  
  // Stop
  Serial.println("Stop");
  analogWrite(PWMA, 0);
  analogWrite(PWMB, 0);
  delay(2000);
}
