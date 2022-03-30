

const int RELAY_PIN = 7;  // the Arduino pin, which connects to the IN pin of relay
const int BUTTON_PIN = 2;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin as an output.
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
  
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

// the loop function runs over and over again forever
void loop() {

  // if the button is pressed, flicker the relay
  if (digitalRead(BUTTON_PIN) == LOW)
  {
    digitalWrite(RELAY_PIN, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
    
    delay(500);
    digitalWrite(RELAY_PIN, LOW);
    digitalWrite(LED_BUILTIN, LOW);

    // delay a lot, to avoid noisy button presses
    delay(2000);
  }

  // stop the loop from spamming too fast
  delay(20);
  
//  digitalWrite(RELAY_PIN, HIGH);
//  digitalWrite(LED_BUILTIN, HIGH);
//  delay(10000);
//  digitalWrite(RELAY_PIN, LOW);
//  digitalWrite(LED_BUILTIN, LOW);
//  delay(10000);
}
