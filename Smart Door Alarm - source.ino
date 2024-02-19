#include <LiquidCrystal.h>
#include <Servo.h> 
// Declare the Servo pin 
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 7;
const int micSensor = A0; 
const int buttonPin = 8;
boolean mic = 0;
long duration;
int distance;
int button = 0;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Servo Servo1;
void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT); 
pinMode(buzzer, OUTPUT);
pinMode(micSensor, INPUT);
lcd.begin(16, 2);
Serial.begin(9600); 
lcd.setCursor(0, 0);

}


void loop() {
button = digitalRead(buttonPin);
//digitalWrite(buzzer, LOW);
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

delayMicroseconds(10);
mic = digitalRead(micSensor);
duration = pulseIn(echoPin, HIGH);

//Calculez distanța cu formula distanta = timpPropagare * 0.034/2;
distance= duration*0.034/2;

if (distance <= 20 and button == LOW){
  //dacă distanța este mai mică de 20 cm față de obiect, buzzer-ul produce un sunet constant;
  digitalWrite(buzzer, HIGH);
  Serial.println("Postas");
  //AFISAM pers si buzzer
  updateLCD("Postas");
  
}
if(distance <= 20 or mic == HIGH or button == HIGH){
  Serial.println(button);
  Serial.println("Persoana");
  //AFISAM pers si buzzer
  updateLCD("Persoana");
}
else if( distance >= 20 and distance <=60 or mic == HIGH and button == LOW){
   
  Serial.println("Animalut");
  updateLCD("Animalut :)");

}
else 
  { 
    updateLCD("Home");
    digitalWrite(buzzer,LOW);
    
  }

  
  digitalWrite(11,0);
  //dacă distanța este mai mare de 20 cm, atunci buzzer-ul nu produce niciun sunet;

//Afișez distanța pe ecran pentru teste;
Serial.print("button: ");
Serial.println(button);
}

void updateLCD(String S)
{
   static unsigned long lcdTimer = 0;
   unsigned long lcdInterval = 500; // update the LCD 2 times a second
   if (millis() - lcdTimer >= lcdInterval)
   {
      lcdTimer = millis();
      lcd.setCursor(8, 1);
      lcd.print("        "); // overwrite old data
      lcd.setCursor(8, 1);  // reset the cursor
      lcd.print(S);
   }
}
