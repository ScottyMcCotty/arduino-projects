

const int SCOTT_PIN = ;
const int GUEST_PIN = ;

const int DEBOUNCE = 25; // delay in milliseconds

int SCOTT_PRESSED = HIGH;
int GUEST_PRESSED = HIGH;

unsigned int SCOTT_COUNTER = 0;
unsigned int GUEST_COUNTER = 0;

const int SCOTT_ADDRESS = 0;
const int GUEST_ADDRESS = 2;

const int MAX_UNSIGNED = (255 << 8) + 255;


void setup() {
    setupSerial();
    setupPins();
    setupCounters();
}

void loop() {
    bool scott_update = checkScottButton();
    bool guest_update = checkGuestButton();

    updateDisplay(scott_update, guest_update);
    updateEEPROM()
}

void setupSerial() {
    Serial.begin(9600);
    Serial.println("Hello, world!");
    delay(200);
}

void setupPins() {
    pinMode(SCOTT_PIN, INPUT_PULLUP);
    pinMode(GUEST_PIN, INPUT_PULLUP);
}

void setupCounters() {



    if (Serial) {
        Serial.print("Scott: "); Serial.println(SCOTT_COUNTER);
        Serial.print("Guest: "); Serial.println(GUEST_COUNTER);
    }
}

bool checkScottButton() {

    int state = digitalRead(SCOTT_PIN);

    if (state == SCOTT_PRESSED) {
        // do nothing
        return false;
    }
    // debounce
    delay(DEBOUNCE);
    state = digitalRead(SCOTT_PIN);
    if (state == SCOTT_PRESSED) {
        // it was just a blip, do nothing
        return false;
    }
    // update the new state
    SCOTT_PRESSED = state;
    if (SCOTT_PRESSED == LOW) {
        // only increment the counter when the button is first pressed
        return true;
    }
    return false;
}

bool checkGuestButton() {

    int state = digitalRead(GUEST_PIN);

    if (state == GUEST_PRESSED) {
        // do nothing
        return false;
    }
    // debounce
    delay(DEBOUNCE);
    state = digitalRead(GUEST_PIN);
    if (state == GUEST_PRESSED) {
        // it was just a blip, do nothing
        return false;
    }
    // update the new state
    GUEST_PRESSED = state;
    if (GUEST_PRESSED == LOW) {
        // only increment the counter when the button is first pressed
        return true;
    }
    return false;
}

void updateDisplay(bool scott_pressed, bool guest_pressed) {
    if (scott_pressed) {
        SCOTT_COUNTER += 1;

    }
}


/*

16x2 LED screen displaying stair counts:

[ ][ ][ ][S][C][O][T][T][:][ ][#][#][#][ ][ ][ ]
[ ][ ][ ][G][U][E][S][T][:][ ][#][#][#][ ][ ][ ]

*/