const int dotLength = 100;  // Length of a Morse code "dot" in milliseconds
const int dashLength = 400;  // Length of a Morse code "dash" in milliseconds
const int symbolSpace = 300; // Space between dots and dashes in a letter
const int letterSpace = 500; // Space between letters

// Morse code for each letter (a-z)
String morseCode[] = {
  ".-",   // a
  "-...", // b
  "-.-.", // c
  "-..",  // d
  ".",    // e
  "..-.", // f
  "--.",  // g
  "....", // h
  "..",   // i
  ".---", // j
  "-.-",  // k
  ".-..", // l
  "--",   // m
  "-.",   // n
  "---",  // o
  ".--.", // p
  "--.-", // q
  ".-.",  // r
  "...",  // s
  "-",    // t
  "..-",  // u
  "...-", // v
  ".--",  // w
  "-..-", // x
  "-.--", // y
  "--.."  // z
};

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter a string to convert to Morse code. Press Enter after each input.");
}

void loop() {
  digitalWrite(LED_BUILTIN, LOW);  // Turn off the LED by default

  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');  // Read input until a newline character is received
    input.trim();  // Remove any leading/trailing whitespace including newline characters
    input.toLowerCase();  // Convert the input string to lowercase

    if (input.length() > 0) {
      Serial.print("Translating: ");
      Serial.println(input);
      translateToMorse(input);  // Call the function to convert and blink the Morse code
    }
  }
}

// Function to convert a string to Morse code and blink the LED
void translateToMorse(String input) {
  for (int i = 0; i < input.length(); i++) {
    char character = input[i];
    
    if (character >= 'a' && character <= 'z') {
      int index = character - 'a';  // Get the corresponding Morse code from the array
      String morseCodeLetter = morseCode[index];
      showCode(morseCodeLetter);  // Blink the Morse code using the LED
      delay(letterSpace);  // Delay between letters
    }
    else if (character == ' ') {
      delay(letterSpace * 2);  // Longer delay for spaces between words
    }
  }
}

// Function to blink the Morse code for each letter
void showCode(String morseCodeLetter) {
  for (int i = 0; i < morseCodeLetter.length(); i++) {
    if (morseCodeLetter[i] == '.') {
      digitalWrite(LED_BUILTIN, HIGH);  // Dot
      delay(dotLength);
    } 
    else if (morseCodeLetter[i] == '-') {
      digitalWrite(LED_BUILTIN, HIGH);  // Dash
      delay(dashLength);
    }
    digitalWrite(LED_BUILTIN, LOW);  // Turn off the LED after each dot/dash
    delay(symbolSpace);  // Space between symbols in a letter
  }
}
