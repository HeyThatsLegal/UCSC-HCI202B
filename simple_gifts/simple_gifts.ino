  // Simple Gifts

const int BZ1 = 5;
const int BZ2 = 6;

// Frequencies (Hz) [cite: 14-241]
#define NOTE_G3  196
#define NOTE_A3  220
#define NOTE_B3  247
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4S 370
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5S 554
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5S 740
#define NOTE_G5  784
#define NOTE_A5  880
#define REST     0

// Timing (92 BPM) [cite: 12]
const int tempo = 92; 
const long quarter = 60000000L / tempo; 
const long eighth  = quarter / 2;
const long half    = quarter * 2;
const long whole   = quarter * 4;

struct Note {
  int freq;
  long duration;
};

// Part 1: Violin 1 [cite: 14-142]
Note part1[] = {
  {REST, half}, {REST, quarter}, {NOTE_A4, eighth}, {NOTE_A4, eighth}, // M1
  {NOTE_D5, quarter}, {NOTE_D5, eighth}, {NOTE_E5, eighth}, {NOTE_F5S, eighth}, {NOTE_D5, eighth}, {NOTE_F5S, eighth}, {NOTE_G5, eighth}, // M2
  {NOTE_A5, quarter}, {NOTE_A5, eighth}, {NOTE_G5, eighth}, {NOTE_F5S, quarter}, {NOTE_E5, eighth}, {NOTE_D5, eighth}, // M3
  {NOTE_E5, quarter}, {NOTE_A4, quarter}, {NOTE_E5, quarter}, {NOTE_A4, quarter}, // M4
  {NOTE_E5, eighth}, {NOTE_F5S, eighth}, {NOTE_E5, eighth}, {NOTE_E5, eighth}, {NOTE_A4, quarter}, {NOTE_A4, eighth}, {NOTE_A4, eighth}, // M5
  {NOTE_D5, quarter}, {NOTE_D5, eighth}, {NOTE_E5, eighth}, {NOTE_F5S, eighth}, {NOTE_D5, eighth}, {NOTE_F5S, eighth}, {NOTE_G5, eighth}, // M6
  {NOTE_A5, quarter}, {NOTE_A5, eighth}, {NOTE_G5, eighth}, {NOTE_F5S, quarter}, {NOTE_E5, eighth}, {NOTE_D5, eighth}, // M7
  {NOTE_E5, quarter}, {NOTE_E5, quarter}, {NOTE_E5, quarter}, {NOTE_F5S, eighth}, {NOTE_E5, eighth}, // M8
  {NOTE_D5, quarter}, {NOTE_D5, quarter}, {NOTE_D5, half}, // M9
  {NOTE_A4, half}, {NOTE_F4S, quarter}, {NOTE_E4, quarter}, // M10
  {NOTE_F4S, eighth}, {NOTE_G4, eighth}, {NOTE_F4S, eighth}, {NOTE_E4, eighth}, {NOTE_D4, quarter}, {NOTE_A3, quarter}, // M11
  {NOTE_D4, quarter}, {NOTE_D4, eighth}, {NOTE_E4, eighth}, {NOTE_F4S, quarter}, {NOTE_E4, eighth}, {NOTE_D4, eighth}, // M12
  {NOTE_E4, quarter}, {NOTE_E4, quarter}, {NOTE_E4, quarter}, {REST, quarter}, // M13
  {NOTE_A5, half}, {NOTE_F5S, quarter}, {NOTE_E5, quarter}, // M14
  {NOTE_F5S, eighth}, {NOTE_G5, eighth}, {NOTE_F5S, eighth}, {NOTE_E5, eighth}, {NOTE_D5, quarter}, {NOTE_A4, quarter}, // M15
  {NOTE_E5, quarter}, {NOTE_E5, quarter}, {NOTE_E5, quarter}, {NOTE_F5S, eighth}, {NOTE_E5, eighth}, // M16
  {NOTE_D5, half}, {NOTE_D5, half}, // M17
  {NOTE_D5, half}, {REST, quarter}, {NOTE_A4, eighth}, {NOTE_A4, eighth}, // M18
  {NOTE_D5, quarter}, {NOTE_D5, eighth}, {NOTE_E5, eighth}, {NOTE_F5S, eighth}, {NOTE_D5, eighth}, {NOTE_F5S, eighth}, {NOTE_G5, eighth}, // M19
  {NOTE_A5, quarter}, {NOTE_A5, eighth}, {NOTE_G5, eighth}, {NOTE_F5S, quarter}, {NOTE_E5, eighth}, {NOTE_D5, eighth}, // M20
  {NOTE_E5, quarter}, {NOTE_E5, quarter}, {NOTE_E5, quarter}, {NOTE_D5, quarter}, // M21
  {NOTE_E5, eighth}, {NOTE_F5S, eighth}, {NOTE_E5, eighth}, {NOTE_E5, eighth}, {NOTE_A4, quarter}, {NOTE_A3, eighth}, {NOTE_A3, eighth}, // M22
  {NOTE_D4, quarter}, {NOTE_D4, eighth}, {NOTE_E4, eighth}, {NOTE_F4S, eighth}, {NOTE_D4, eighth}, {NOTE_F4S, eighth}, {NOTE_G4, eighth}, // M23
  {NOTE_A4, quarter}, {NOTE_A4, eighth}, {NOTE_G4, eighth}, {NOTE_F4S, quarter}, {NOTE_E4, eighth}, {NOTE_D4, eighth}, // M24
  {NOTE_E4, quarter}, {NOTE_E4, quarter}, {NOTE_E4, quarter}, {NOTE_F4S, eighth}, {NOTE_E4, eighth}, // M25
  {NOTE_D4, half}, {NOTE_D4, half}, // M26
  {NOTE_D4, whole} // M27 [cite: 142]
};

// Part 2: Violin 2 [cite: 143-241]
Note part2[] = {
  {REST, half}, {REST, quarter}, {NOTE_A4, eighth}, {NOTE_A4, eighth}, // M1
  {NOTE_D5, quarter}, {NOTE_D5, eighth}, {NOTE_E5, eighth}, {NOTE_F5S, eighth}, {NOTE_D5, eighth}, {NOTE_F5S, eighth}, {NOTE_G5, eighth}, // M2
  {NOTE_A5, quarter}, {NOTE_A5, eighth}, {NOTE_G5, eighth}, {NOTE_F5S, quarter}, {NOTE_E5, eighth}, {NOTE_D5, eighth}, // M3
  {NOTE_E5, quarter}, {NOTE_A4, quarter}, {NOTE_E5, quarter}, {NOTE_A4, quarter}, // M4
  {NOTE_E5, eighth}, {NOTE_F5S, eighth}, {NOTE_E5, eighth}, {NOTE_C5S, eighth}, {NOTE_A4, quarter}, {NOTE_A4, eighth}, {NOTE_A4, eighth}, // M5
  {NOTE_A4, half}, {NOTE_A4, quarter}, {NOTE_D5, quarter}, // M6
  {NOTE_D5, half}, {NOTE_D5, quarter}, {NOTE_A4, quarter}, // M7
  {NOTE_A4, quarter}, {NOTE_A4, quarter}, {NOTE_A4, half}, // M8
  {NOTE_G4, quarter}, {NOTE_G4, quarter}, {NOTE_F4S, half}, // M9
  {NOTE_A4, half}, {NOTE_A4, quarter}, {NOTE_A4, quarter}, // M10
  {NOTE_A4, quarter}, {NOTE_A4, quarter}, {NOTE_A4, quarter}, {NOTE_A4, quarter}, // M11
  {NOTE_A4, half}, {NOTE_A4, half}, // M12
  {NOTE_A4, quarter}, {NOTE_A4, quarter}, {NOTE_A4, quarter}, {REST, quarter}, // M13
  {NOTE_F5S, half}, {NOTE_D5, quarter}, {NOTE_A4, quarter}, // M14
  {NOTE_D5, eighth}, {NOTE_E5, eighth}, {NOTE_D5, eighth}, {NOTE_A4, eighth}, {NOTE_F4S, quarter}, {NOTE_D4, quarter}, // M15
  {NOTE_A4, quarter}, {NOTE_A4, quarter}, {NOTE_C5S, quarter}, {NOTE_A4, quarter}, // M16
  {NOTE_B4, half}, {NOTE_G4, half}, // M17
  {NOTE_F4S, half}, {REST, quarter}, {NOTE_A4, eighth}, {NOTE_A4, eighth}, // M18
  {NOTE_A4, quarter}, {NOTE_F4S, eighth}, {NOTE_A4, eighth}, {NOTE_D5, eighth}, {NOTE_A4, eighth}, {NOTE_D5, eighth}, {NOTE_E5, eighth}, // M19
  {NOTE_F5S, quarter}, {NOTE_F5S, eighth}, {NOTE_D5, eighth}, {NOTE_D5, quarter}, {NOTE_A4, quarter}, // M20
  {NOTE_A4, quarter}, {NOTE_A4, quarter}, {NOTE_A4, quarter}, {NOTE_A4, quarter}, // M21
  {NOTE_A4, half}, {NOTE_A4, quarter}, {NOTE_A3, eighth}, {NOTE_A3, eighth}, // M22
  {NOTE_A3, half}, {NOTE_B3, half}, // M23
  {NOTE_D4, quarter}, {NOTE_D4, quarter}, {NOTE_D4, quarter}, {NOTE_A3, quarter}, // M24
  {NOTE_B3, half}, {NOTE_A3, half}, // M25
  {NOTE_B3, half}, {NOTE_G3, half}, // M26
  {NOTE_A3, whole} // M27 [cite: 241]
};

void setup() {
  pinMode(BZ1, OUTPUT);
  pinMode(BZ2, OUTPUT);

  int p1Index = 0, p2Index = 0;
  long p1NoteStart = 0, p2NoteStart = 0;
  long p1HalfPeriod = 0, p2HalfPeriod = 0;
  long p1NextFlip = 0, p2NextFlip = 0;
  bool p1State = false, p2State = false;

  int numNotes1 = sizeof(part1) / sizeof(part1[0]);
  int numNotes2 = sizeof(part2) / sizeof(part2[0]);

  long startTime = micros();
  long totalDuration = 0;

  // Calculate the maximum duration to ensure we play to the very end
  for(int i=0; i<numNotes1; i++) totalDuration += part1[i].duration;

  while (micros() - startTime < totalDuration) {
    long now = micros() - startTime;

    if (p1Index < numNotes1 && now >= p1NoteStart) {
      p1HalfPeriod = (part1[p1Index].freq == 0) ? 0 : 500000L / part1[p1Index].freq;
      p1NoteStart += part1[p1Index].duration;
      p1NextFlip = now + p1HalfPeriod;
      p1Index++;
    }

    if (p2Index < numNotes2 && now >= p2NoteStart) {
      p2HalfPeriod = (part2[p2Index].freq == 0) ? 0 : 500000L / part2[p2Index].freq;
      p2NoteStart += part2[p2Index].duration;
      p2NextFlip = now + p2HalfPeriod;
      p2Index++;
    }

    if (p1HalfPeriod > 0 && now >= p1NextFlip) {
      p1State = !p1State;
      digitalWrite(BZ1, p1State);
      p1NextFlip += p1HalfPeriod;
    } else if (p1HalfPeriod == 0) {
      digitalWrite(BZ1, LOW);
    }

    if (p2HalfPeriod > 0 && now >= p2NextFlip) {
      p2State = !p2State;
      digitalWrite(BZ2, p2State);
      p2NextFlip += p2HalfPeriod;
    } else if (p2HalfPeriod == 0) {
      digitalWrite(BZ2, LOW);
    }
  }
  
  digitalWrite(BZ1, LOW);
  digitalWrite(BZ2, LOW);
}

void loop() {}