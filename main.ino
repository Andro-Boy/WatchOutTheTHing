#include <rgb_lcd.h>

#define BUZZER 3
#define trigPin 10
#define echoPin 11

rgb_lcd lcd;

#define colorR 255
#define colorG 0
#define colorB 0

// defining variables
long duration;
int distance, prev_dist;

// the setup function runs once when you press reset or power the board
void setup() {
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);

  // Print a message to the LCD.
  lcd.print("Welcome");
  delay(1000);
  fade();
  lcd.setCursor(0, 1);
  lcd.print("TOOOOOOO");
  delay(1000);
  fade();
  lcd.setCursor(0, 1);
  lcd.print("ManMetHack 2020");
  delay(2000);
  fade();
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 0);
  lcd.setRGB(0, 255, 0);
  lcd.print("Distance is:");
  //  delay(1000);

  Serial.begin(115200);
  // initialize digital pin 3 as an output.
  pinMode(BUZZER, OUTPUT);

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}

// the loop function runs over and over again forever
void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;

  if (distance <= 15 && distance > 10) {
    digitalWrite(BUZZER, HIGH);   // turn the LED on (HIGH is the voltage level)
    Serial.print("1");
    delay(50);                       // wait for a second
    digitalWrite(BUZZER, LOW);    // turn the LED off by making the voltage LOW
    Serial.println("0");
    delay(100);                       // wait for a second
  } else if (distance <= 10 && distance > 5) {
    digitalWrite(BUZZER, HIGH);   // turn the LED on (HIGH is the voltage level)
    Serial.print("1");
    delay(50);                       // wait for a second
    digitalWrite(BUZZER, LOW);    // turn the LED off by making the voltage LOW
    Serial.println("0");
    delay(50);
  } else if (distance <= 5  && distance > 0) {
    digitalWrite(BUZZER, HIGH);   // turn the LED on (HIGH is the voltage level)
    Serial.print("1");
    delay(50);                       // wait for a second
    digitalWrite(BUZZER, LOW);    // turn the LED off by making the voltage LOW
    Serial.println("0");
    delay(30);
  }

  //Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  //Prints the distance to the LCD
  if (prev_dist != distance){
    lcd.setCursor(0, 1);
    lcd.print(distance);
    lcd.print("                  ");
    prev_dist = distance;
  }
}

void fade() {
  lcd.noDisplay();
  delay(1000);
  // Turn on the display:
  lcd.display();
}

void clearLCDLine(int line)
{
  lcd.setCursor(0, line);
  for (int n = 0; n < 20; n++) // 20 indicates symbols in line. For 2x16 LCD write - 16
  {
    lcd.print(" ");
  }
}
