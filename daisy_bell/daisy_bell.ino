#include <avr/pgmspace.h>

const int BZ1 = 5; // Violin
const int BZ2 = 6; // Piano Composite

// ALL 35 frequencies for bob.musicxml [cite: 490-962]
#define NOTE_D2    73
#define NOTE_F2S   92
#define NOTE_G2    98
#define NOTE_A2    110
#define NOTE_B2    123
#define NOTE_C3    131
#define NOTE_D3    147
#define NOTE_E3    165
#define NOTE_F3S   185
#define NOTE_G3    196
#define NOTE_A3    220
#define NOTE_B3    247
#define NOTE_C4    262
#define NOTE_C4S   277
#define NOTE_D4    294
#define NOTE_D4S   311
#define NOTE_E4    330
#define NOTE_F4S   370
#define NOTE_G4    392
#define NOTE_A4    440
#define NOTE_AS4   466
#define NOTE_B4    494
#define NOTE_C5    523
#define NOTE_CS5   554
#define NOTE_D5    587
#define NOTE_E5    659
#define NOTE_F5S   740
#define NOTE_G5    784
#define NOTE_A5    880
#define NOTE_AS5   932
#define NOTE_B5    988
#define NOTE_C6S   1109
#define NOTE_D6    1175
#define NOTE_E6    1319
#define REST       0

// Timing: 180 BPM, 3/4 waltz 
const int tempo = 180;
const long pulse = 30000000L / (tempo * 2); 

struct Note {
  int freq;
  int duration;
};

// Part 1: Violin (intro rests, then starts melody at M9)
const Note part1[] PROGMEM = {
  { REST, 96 }, { NOTE_D5, 4 }, { NOTE_CS5, 4 }, { NOTE_D5, 4 }, { NOTE_B4, 4 }, { NOTE_A4, 4 }, { NOTE_G4, 4 }, { NOTE_A4, 8 }, { NOTE_F4S, 4 }, { NOTE_D4, 8 }, { REST, 4 }, { NOTE_A4, 12 }, { NOTE_D4, 12 }, { NOTE_D5, 12 }, { NOTE_B4, 12 }, { NOTE_D5, 4 }, { NOTE_CS5, 4 }, { NOTE_D5, 4 }, { NOTE_B4, 4 }, { NOTE_A4, 4 }, { NOTE_G4, 4 }, { NOTE_A4, 8 }, { NOTE_F4S, 4 }, { NOTE_D4, 8 }, { REST, 4 }, { NOTE_G4, 4 }, { NOTE_D5, 4 }, { NOTE_G4, 4 }, { NOTE_F4S, 4 }, { NOTE_D4, 4 }, { NOTE_A4, 4 }, { NOTE_G4, 20 }, { REST, 4 }, { NOTE_B4, 4 }, { NOTE_C5, 4 }, { NOTE_B4, 4 }, { NOTE_A4, 4 }, { NOTE_G4, 4 }, { NOTE_F4S, 4 }, { NOTE_B4, 8 }, { NOTE_G4, 4 }, { NOTE_E4, 8 }, { REST, 4 }, { NOTE_D5, 4 }, { NOTE_C5, 4 }, { NOTE_B4, 4 }, { NOTE_A4, 8 }, { NOTE_AS4, 4 }, { NOTE_B4, 16 }, { REST, 8 }, { NOTE_B4, 4 }, { NOTE_C5, 4 }, { NOTE_B4, 4 }, { NOTE_A4, 4 }, { NOTE_G4, 4 }, { NOTE_F4S, 4 }, { NOTE_B4, 8 }, { NOTE_G4, 4 }, { NOTE_E4, 8 }, { NOTE_B4, 4 }, { NOTE_A4, 4 }, { NOTE_E5, 4 }, { NOTE_CS5, 4 }, { NOTE_B4, 8 }, { NOTE_A4, 4 }, { NOTE_D5, 20 }, { REST, 4 }, { NOTE_D5, 12 }, { NOTE_B4, 12 }, { NOTE_G4, 12 }, { NOTE_D4, 12 }, { NOTE_E4, 4 }, { NOTE_F4S, 4 }, { NOTE_G4, 4 }, { NOTE_E4, 8 }, { NOTE_G4, 4 }, { NOTE_D4, 20 }, { REST, 4 }, { NOTE_A4, 12 }, { NOTE_D5, 12 }, { NOTE_B4, 12 }, { NOTE_G4, 12 }, { NOTE_E4, 4 }, { NOTE_F4S, 4 }, { NOTE_G4, 4 }, { NOTE_A4, 8 }, { NOTE_B4, 4 }, { NOTE_A4, 16 }, { REST, 4 }, { NOTE_B4, 4 }, { NOTE_C5, 4 }, { NOTE_B4, 4 }, { NOTE_A4, 4 }, { NOTE_D5, 8 }, { NOTE_B4, 4 }, { NOTE_A4, 4 }, { NOTE_G4, 12 }, { REST, 4 }, { NOTE_A4, 4 }, { NOTE_B4, 8 }, { REST, 2 }, { NOTE_G4, 2 }, { NOTE_E4, 8 }, { REST, 2 }, { NOTE_G4, 2 }, { NOTE_E4, 4 }, { NOTE_D4, 12 }, { REST, 4 }, { NOTE_D4, 4 }, { NOTE_G4, 8 }, { NOTE_B4, 4 }, { NOTE_A4, 3 }, { REST, 9 }, { NOTE_G4, 8 }, { NOTE_B4, 4 }, { NOTE_A4, 3 }, { REST, 5 }, { NOTE_B4, 2 }, { NOTE_C5, 2 }, { NOTE_D5, 4 }, { NOTE_B4, 4 }, { NOTE_G4, 4 }, { NOTE_A4, 8 }, { NOTE_D4, 4 }, { NOTE_G4, 24 }
};

// Part 2: Piano (Waltz accompaniment + intro)
const Note part2[] PROGMEM = {
  { NOTE_D6, 4 }, { NOTE_CS5, 4 }, { NOTE_D6, 4 }, { NOTE_B5, 4 }, { NOTE_A5, 4 }, { NOTE_G5, 4 }, { NOTE_A5, 8 }, { NOTE_F5S, 4 }, { NOTE_D5, 8 }, { NOTE_D6, 4 }, { NOTE_B5, 2 }, { NOTE_D5, 2 }, { NOTE_E5, 2 }, { NOTE_F5S, 2 }, { NOTE_G5, 2 }, { NOTE_A5, 2 }, { NOTE_AS5, 2 }, { NOTE_B5, 2 }, { NOTE_E6, 2 }, { NOTE_D6, 2 }, { NOTE_B5, 2 }, { NOTE_G5, 2 }, { NOTE_A5, 8 }, { NOTE_D5, 4 }, { NOTE_G5, 12 }, { NOTE_G3, 4 }, { NOTE_D4, 4 }, { NOTE_G4, 4 }, { NOTE_G3, 4 }, { NOTE_D4, 4 }, { NOTE_G4, 4 }, { NOTE_F3S, 4 }, { NOTE_D4, 4 }, { NOTE_A4, 4 }, { NOTE_D3, 4 }, { NOTE_D4, 4 }, { NOTE_F4S, 4 }, { NOTE_F3S, 4 }, { NOTE_D4, 4 }, { NOTE_A4, 4 }, { NOTE_D3, 4 }, { NOTE_D4, 4 }, { NOTE_F4S, 4 }, { NOTE_G3, 4 }, { NOTE_D4, 4 }, { NOTE_G4, 4 }, { NOTE_D3, 4 }, { NOTE_D4, 4 }, { NOTE_G4, 4 }, { NOTE_G3, 4 }, { NOTE_D4, 4 }, { NOTE_G4, 4 }, { NOTE_G3, 4 }, { NOTE_D4, 4 }, { NOTE_G4, 4 }, { NOTE_F3S, 4 }, { NOTE_D4, 4 }, { NOTE_A4, 4 }, { NOTE_D3, 4 }, { NOTE_D4, 4 }, { NOTE_F4S, 4 }, { NOTE_G3, 4 }, { NOTE_D4, 4 }, { NOTE_G4, 4 }, { NOTE_D3, 4 }, { NOTE_D4, 4 }, { NOTE_F4S, 4 }, { NOTE_G3, 4 }, { NOTE_D3, 4 }, { NOTE_B2, 4 }, { NOTE_G2, 8 }, { REST, 4 }, { NOTE_E3, 4 }, { NOTE_B3, 4 }, { NOTE_E4, 4 }, { NOTE_B2, 4 }, { NOTE_B3, 4 }, { NOTE_D4S, 4 }, { NOTE_E3, 4 }, { NOTE_B3, 4 }, { NOTE_E4, 4 }, { NOTE_E3, 4 }, { NOTE_G3, 4 }, { NOTE_B3, 4 }, { NOTE_F3S, 4 }, { NOTE_C4, 4 }, { NOTE_D4, 4 }, { NOTE_F3S, 4 }, { NOTE_C4, 4 }, { NOTE_D4, 4 }, { NOTE_G3, 4 }, { NOTE_AS4, 2 }, { NOTE_B4, 2 }, { NOTE_D5, 2 }, { NOTE_G5, 2 }, { NOTE_B5, 8 }, { REST, 4 }, { NOTE_E3, 4 }, { NOTE_B3, 4 }, { NOTE_E4, 4 }, { NOTE_B2, 4 }, { NOTE_B3, 4 }, { NOTE_D4S, 4 }, { NOTE_E3, 4 }, { NOTE_B3, 4 }, { NOTE_E4, 4 }, { NOTE_E3, 4 }, { NOTE_B3, 4 }, { NOTE_E4, 4 }, { NOTE_A2, 4 }, { NOTE_A3, 4 }, { NOTE_C4S, 4 }, { NOTE_A2, 4 }, { NOTE_A3, 4 }, { NOTE_C4S, 4 }, { NOTE_D3, 4 }, { NOTE_F4S, 4 }, { NOTE_A4, 4 }, { NOTE_D4, 8 }, { REST, 4 }, { NOTE_G3, 4 }, { NOTE_G4, 4 }, { NOTE_B4, 4 }, { NOTE_B3, 4 }, { NOTE_D4, 4 }, { NOTE_G4, 4 }, { NOTE_B2, 4 }, { NOTE_G3, 4 }, { NOTE_D4, 4 }, { NOTE_G2, 4 }, { NOTE_G3, 4 }, { NOTE_B3, 4 }, { NOTE_C3, 4 }, { NOTE_G3, 4 }, { NOTE_C4, 4 }, { NOTE_C3, 4 }, { NOTE_G3, 4 }, { NOTE_C4, 4 }, { NOTE_G2, 4 }, { NOTE_D3, 4 }, { NOTE_B2, 4 }, { NOTE_G2, 4 }, { NOTE_G3, 4 }, { NOTE_B3, 4 }, { NOTE_F3S, 4 }, { NOTE_C4, 4 }, { NOTE_D4, 4 }, { NOTE_D3, 4 }, { NOTE_C4, 4 }, { NOTE_D4, 4 }, { NOTE_G3, 4 }, { NOTE_D4, 4 }, { NOTE_G4, 4 }, { NOTE_E3, 4 }, { NOTE_B3, 4 }, { NOTE_E4, 4 }, { NOTE_A2, 4 }, { NOTE_A3, 4 }, { NOTE_C4S, 4 }, { NOTE_A2, 4 }, { NOTE_A3, 4 }, { NOTE_C4S, 4 }, { NOTE_D3, 4 }, { NOTE_A3, 4 }, { NOTE_D4, 4 }, { NOTE_D3, 4 }, { NOTE_A3, 4 }, { NOTE_D4, 4 }, { NOTE_F3S, 4 }, { NOTE_C4, 4 }, { NOTE_D4, 4 }, { NOTE_D3, 4 }, { NOTE_C4, 4 }, { NOTE_D4, 4 }, { NOTE_G3, 4 }, { NOTE_B3, 4 }, { NOTE_D4, 4 }, { NOTE_G3, 4 }, { NOTE_B3, 4 }, { NOTE_D4, 4 }, { NOTE_E3, 4 }, { NOTE_G3, 4 }, { REST, 2 }, { NOTE_B3, 2 }, { NOTE_C3, 4 }, { NOTE_G3, 4 }, { REST, 2 }, { NOTE_C4, 2 }, { NOTE_G2, 4 }, { NOTE_G3, 4 }, { NOTE_B3, 4 }, { NOTE_F2S, 4 }, { NOTE_A3, 4 }, { NOTE_C4, 4 }, { NOTE_G2, 4 }, { NOTE_G3, 4 }, { NOTE_B3, 4 }, { NOTE_C4, 3 }, { REST, 9 }, { NOTE_G2, 4 }, { NOTE_G3, 4 }, { NOTE_B3, 4 }, { NOTE_C4, 3 }, { REST, 9 }, { NOTE_G2, 4 }, { NOTE_G3, 4 }, { NOTE_B3, 4 }, { NOTE_D2, 4 }, { NOTE_F3S, 4 }, { NOTE_C4, 4 }, { NOTE_G3, 4 }, { NOTE_D3, 4 }, { NOTE_B2, 4 }, { NOTE_G2, 12 }
};

void setup() {
  pinMode(BZ1, OUTPUT);
  pinMode(BZ2, OUTPUT);

  int p1Idx = 0, p2Idx = 0;
  long p1Next = 0, p2Next = 0;
  long p1Flip = 0, p2Flip = 0;
  long p1Half = 0, p2Half = 0;
  bool s1 = false, s2 = false;

  long start = micros();
  long total = 864 * pulse; // Complete duration of 72 measures

  while (micros() - start < total) {
    long now = micros() - start;
    long curr = now / pulse;

    if (p1Idx < (sizeof(part1)/sizeof(Note)) && curr >= p1Next) {
      int f = pgm_read_word(&(part1[p1Idx].freq));
      p1Half = (f == 0) ? 0 : 500000L / f;
      p1Next += pgm_read_word(&(part1[p1Idx].duration));
      p1Flip = now + p1Half;
      p1Idx++;
    }

    if (p2Idx < (sizeof(part2)/sizeof(Note)) && curr >= p2Next) {
      int f = pgm_read_word(&(part2[p2Idx].freq));
      p2Half = (f == 0) ? 0 : 500000L / f;
      p2Next += pgm_read_word(&(part2[p2Idx].duration));
      p2Flip = now + p2Half;
      p2Idx++;
    }

    // Pin Flipper
    if (p1Half > 0 && now >= p1Flip) {
      s1 = !s1; digitalWrite(BZ1, s1); p1Flip += p1Half;
    } else if (p1Half == 0) digitalWrite(BZ1, LOW);

    if (p2Half > 0 && now >= p2Flip) {
      s2 = !s2; digitalWrite(BZ2, s2); p2Flip += p2Half;
    } else if (p2Half == 0) digitalWrite(BZ2, LOW);
  }
  
  digitalWrite(BZ1, LOW);
  digitalWrite(BZ2, LOW);
}

void loop() {}