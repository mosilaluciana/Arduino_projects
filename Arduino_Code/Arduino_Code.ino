int ledPin = 13;
int sensorPin = 6;
boolean val = 0;

void setup() {
 pinMode(ledPin, OUTPUT);
 pinMode(sensorPin, INPUT);
 Serial.begin(9600); }

void loop() {
 val = digitalRead(sensorPin);
 Serial.println(val);
 // cand senzorul detecteaza un semnal sonor , ledul lumineaza
 if (val==HIGH) {
 digitalWrite(ledPin, HIGH);
 val=0;
 }
else {
 digitalWrite(ledPin, LOW);
 val=0;
 } 
}
