const int trigPin = 9;
const int echoPin = 10;

void setup() {
  Serial.begin(9600); // Talk to the computer
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {

  // search function

  if(objectDetected()) {
    Serial.println("Object within range detected!");
    // run some function
  }
    
  delay(1000);

  
  
}

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

  Serial.print("Object detected ");
  Serial.print(distance);
  Serial.println("cm away");

  if(distance >= 0 && distance < 20)
    return true;
  else
    return false;

  
}
