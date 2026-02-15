const int trigPin = 9;
const int echoPin = 10;

void setup() {
  Serial.begin(9600); // Talk to the computer
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration;
  int distance;
  
  // Standard Ultrasonic Ping
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // If object is closer than 20cm, alert the computer
  if (distance > 0 && distance < 20) {
    Serial.println("DETECTED");
    delay(2000); // Pause so we don't save 100 images a second
  }
}
