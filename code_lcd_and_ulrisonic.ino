#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
int trigPin = 8;
int echoPin = 9;
 
void setup() 
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Ultrasonic Sensor");
  lcd.setCursor(0,1);
  lcd.print("Distance:");
}
 
void loop()
{
    long duration, inches, cm;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    inches = microsecondsToInches(duration);
    cm = microsecondsToCentimeters(duration);
    lcd.setCursor(10,1);
    lcd.print(cm);
    lcd.print("CM");
    Serial.print(inches);
    Serial.print("in, ");
    Serial.print(cm);
    Serial.print("cm");
    Serial.println();
    delay(100);
}
 
long microsecondsToInches(long microseconds)
{
return microseconds / 74 / 2;
}
 
long microsecondsToCentimeters(long microseconds)
{
return microseconds / 29 / 2;
}
