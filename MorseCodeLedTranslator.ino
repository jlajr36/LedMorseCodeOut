int ledPin = 3;
int dotDelay = 200;
char ch;

char* letters[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",
                   ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
                   "...","-","..-","...-",".--","-..-","-.--","--.."};

char* numbers[] = {"-----",".----","..---","...--","....-","....","-....",
                   "--...","---..","----."};

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    ch = Serial.read();
    if(ch >= 'a' && ch <= 'z') {
      flashSequence(letters[ch - 'a']); 
    }
    else if(ch >= 'A' && ch <= 'Z') {
      flashSequence(letters[ch - 'A']); 
    }
    else if(ch >= '0' && ch <= '9') {
      flashSequence(letters[ch - '0']); 
    }
    else if (ch == ' ')
    {
      delay(dotDelay * 4);
    }
  }
}

void flashSequence(char* sequence) {
  int i = 0;
  while (sequence[i] != NULL) {
    flashDotOrDash(sequence[i]);
    i++;
  }
  delay(dotDelay * 3);
}

void flashDotOrDash(char dotOrDash) {
  digitalWrite(ledPin, HIGH);
  if(dotOrDash == '.') {
    delay(dotDelay);
  } else {
    delay(dotDelay * 3);
  }
  digitalWrite(ledPin, LOW);
  delay(dotDelay);
}
