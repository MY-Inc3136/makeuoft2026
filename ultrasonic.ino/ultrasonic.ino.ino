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
  digitalWrite(echoPin, LOW);
  
  duration = pulseIn(echoPin, HIGH, 20000);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);
  delay(1000);
  
}
