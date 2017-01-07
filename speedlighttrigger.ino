//Defines where the sensor and the shutter are attached
int sensorPin = A0;
int shutterPin = 11;
int ledPin = 13;

int currentReading = 0;
int previousReading = 0;
int delta = 0;
const int threshold = 5; //The difference between sensor samples that triggers the shutter

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  pinMode(shutterPin, OUTPUT);
  //Serial.begin(9600); --only for debug purposes
}

void triggerShutter()
{
    digitalWrite(shutterPin, HIGH);
    delay(500);
    digitalWrite(shutterPin, LOW);
}

void loop()
{
  currentReading = analogRead(sensorPin);
  delta = previousReading - currentReading;
  previousReading = currentReading;
  if (delta > threshold)
  {
    digitalWrite(ledPin, HIGH);
    //Serial.println(delta); --Only for debugging purposes
    triggerShutter();
    digitalWrite(ledPin, LOW);
  }
}
