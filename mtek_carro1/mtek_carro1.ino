// C++ code
// Código para o carro seguir em frente e se detectar um obstaculo, dar ré e mudar de direção

int Distancia = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop()
{
  if (0.01723 * readUltrasonicDistance(12, 13) < 10) {
    digitalWrite(2, LOW);
    analogWrite(5, 80);
    digitalWrite(4, HIGH);
    analogWrite(6, 80);
    delay(1000); // Wait for 1000 millisecond(s)
    digitalWrite(2, HIGH);
    analogWrite(5, 80);
    digitalWrite(4, HIGH);
    analogWrite(6, 80);
    delay(500); // Wait for 500 millisecond(s)
  } else {
    digitalWrite(2, HIGH);
    analogWrite(5, 80);
    digitalWrite(4, LOW);
    analogWrite(6, 80);
  }
}