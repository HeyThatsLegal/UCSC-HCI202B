#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Global setup
const int buzzerPin = 5; 
LiquidCrystal_I2C lcd(0x27, 16, 2); 

// 120 BPM Timing
const int eighth = 250; 
const int quarter = 500;
const int dottedQuarter = 750;

#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_G5  784
#define REST     0

int melody[] = {
  NOTE_D4,                                // M1 pickup [cite: 10]
  NOTE_G4, NOTE_B4, NOTE_D5, NOTE_G4,     // M2 [cite: 11-14]
  NOTE_C5, NOTE_E5, NOTE_G5, NOTE_E5, NOTE_D5, NOTE_B4, // M3 [cite: 15-20]
  NOTE_C5, NOTE_A4, NOTE_D4, NOTE_C5, NOTE_B4, NOTE_G4, NOTE_D4, NOTE_B4, // M4 [cite: 21-27]
  NOTE_FS4, NOTE_E4, NOTE_D4, REST, NOTE_D4, // M5 [cite: 28-31]
  NOTE_G4, NOTE_B4, NOTE_D5, NOTE_G4,     // M6 [cite: 33-36]
  NOTE_C5, NOTE_E5, NOTE_G5, NOTE_E5, NOTE_D5, NOTE_B4, // M7 [cite: 37-42]
  NOTE_C5, NOTE_A4, NOTE_D4, NOTE_C5, NOTE_B4, NOTE_G4, NOTE_D4, NOTE_B4, // M8 [cite: 43-50]
  NOTE_FS4, NOTE_E4, NOTE_D4, REST, NOTE_D4, // M9 [cite: 51-54]
  NOTE_C5, NOTE_B4, NOTE_A4, NOTE_D4,     // M10 [cite: 55-57]
  NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_D4, // M11 [cite: 59-64]
  NOTE_G4, NOTE_B4, NOTE_D5, NOTE_G4,     // M12 [cite: 65-68]
  NOTE_C5, NOTE_E5, NOTE_G5, NOTE_E5, NOTE_D5, NOTE_B4, // M13 [cite: 69-74]
  NOTE_C5, NOTE_A4, NOTE_D4, NOTE_C5, NOTE_B4, NOTE_G4, NOTE_D4, NOTE_B4, // M14 [cite: 75-81]
  NOTE_A4, NOTE_FS4, NOTE_G4, REST, NOTE_D4, // M15 [cite: 82-85]
  NOTE_C5, NOTE_B4, NOTE_A4, NOTE_D4,     // M16 [cite: 87-90]
  NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_D4, // M17 [cite: 91-96]
  NOTE_G4, NOTE_B4, NOTE_D5, NOTE_G4,     // M18 [cite: 97-100]
  NOTE_C5, NOTE_E5, NOTE_G5, NOTE_E5, NOTE_D5, NOTE_B4, // M19 [cite: 101-105]
  NOTE_C5, NOTE_A4, NOTE_D4, NOTE_C5, NOTE_B4, NOTE_G4, NOTE_D4, NOTE_B4, // M20 [cite: 106-113]
  NOTE_A4, NOTE_FS4, NOTE_G4              // M21 [cite: 115-117]
};

int durations[] = {
  eighth, dottedQuarter, eighth, dottedQuarter, eighth, eighth, eighth, eighth, eighth, dottedQuarter, eighth,
  eighth, eighth, eighth, eighth, eighth, eighth, eighth, eighth, quarter, quarter, quarter, eighth, eighth,
  dottedQuarter, eighth, dottedQuarter, eighth, eighth, eighth, eighth, eighth, dottedQuarter, eighth,
  eighth, eighth, eighth, eighth, eighth, eighth, eighth, eighth, quarter, quarter, quarter, eighth, eighth,
  dottedQuarter, eighth, dottedQuarter, eighth, eighth, eighth, eighth, eighth, dottedQuarter, eighth,
  dottedQuarter, eighth, dottedQuarter, eighth, eighth, eighth, eighth, eighth, dottedQuarter, eighth,
  eighth, eighth, eighth, eighth, eighth, eighth, eighth, eighth, quarter, quarter, quarter, eighth, eighth,
  dottedQuarter, eighth, dottedQuarter, eighth, eighth, eighth, eighth, eighth, dottedQuarter, eighth,
  dottedQuarter, eighth, dottedQuarter, eighth, eighth, eighth, eighth, eighth, dottedQuarter, eighth,
  eighth, eighth, eighth, eighth, eighth, eighth, eighth, eighth, quarter, quarter, quarter
};

void setup() {
  lcd.init();
  lcd.backlight();
  
  lcd.setCursor(0, 0); 
  lcd.print("THE HAPPY FARMER");
  lcd.setCursor(0, 1); 
  lcd.print("R. Schumann");

  for (int i = 0; i < sizeof(melody) / sizeof(int); i++) {
    if (melody[i] != REST) {
      tone(buzzerPin, melody[i], durations[i]);
    }
    delay(durations[i] * 1.30);
    noTone(buzzerPin);
  }
  lcd.noBacklight();
  lcd.clear();
}

void loop() {}