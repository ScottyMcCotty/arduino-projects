

const int BUTTON_INPUT = 8;
const int RELAY_OUTPUT = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTON_INPUT, INPUT_PULLUP);
  pinMode(RELAY_OUTPUT, OUTPUT);

  Serial.begin(9600);
  Serial.println("Hello, world!");
}

void loop() {
  // put your main code here, to run repeatedly:

  if (digitalRead(BUTTON_INPUT) == LOW) {
    digitalWrite(RELAY_OUTPUT, HIGH);
  } else {
    digitalWrite(RELAY_OUTPUT, LOW);
  }
}
