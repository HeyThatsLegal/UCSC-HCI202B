/* Acknowledgements
Uses example code from:
Tilt Sensor: https://wiki.keyestudio.com/Ks0025_keyestudio_Digital_Tilt_Sensor
LCD 1602 I2C Module: https://wiki.keyestudio.com/Ks0061_keyestudio_1602_I2C_Module
Piezo: https://projecthub.arduino.cc/Sparkbuzzer/happy-birthday-tone-using-arduino-uno-66a676*/

int blueLED = 10; // pin 10
int redLED = 9; // pin 9
int tiltSwitch = 6; // pin 6
int buzzer = 3; // pin 3 (PWM)

int iterator = 0; // "timer" of sorts for how long the output will continue playing after sensor is tripped
int speed = 200; // speed variable for audio

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {
  // put your setup code here, to run once:

  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(tiltSwitch, INPUT);
  pinMode(buzzer, OUTPUT);

  lcd.init(); // initialize the lcd
  lcd.init();
}

// playTone function used to play a specific tone for a specific duration

void playTone(int tone, int duration)   {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(buzzer,   HIGH);
    delayMicroseconds(tone);
    digitalWrite(buzzer, LOW);
    delayMicroseconds(tone);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(tiltSwitch) == HIGH) {
    // Print a message to the LCD.
    lcd.backlight();
    lcd.setCursor(3,0);
    lcd.print("earthquack");
    lcd.setCursor(0,1);
    lcd.print("AAAAAAAAAAAAAAAA");
    while (digitalRead(tiltSwitch) == HIGH) {
      playTone(769, speed);
      digitalWrite(blueLED, HIGH);
      iterator ++;
    }
    digitalWrite(buzzer, LOW);
    digitalWrite(blueLED, LOW);
    lcd.clear();
    lcd.noBacklight();
    iterator = 0;
  }

}