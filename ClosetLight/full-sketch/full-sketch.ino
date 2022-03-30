

const long AUTO_SHUTOFF_MIN = 10;
const long AUTO_SHUTOFF_MS = AUTO_SHUTOFF_MIN * 60 * 1000; // conver minutes to milliseconds
const int DEBOUNCING_DELAY = 300;
const int HALL_TURNON_DELAY = 20;

const int RELAY_RIGHT = 4;
const int HALL_SENSOR_RIGHT = 8;
const int HALL_POWER_RIGHT = 9;
long START_TIME_RIGHT = 0;
int STATE_RIGHT = LOW;

const int RELAY_LEFT = 2;
const int HALL_SENSOR_LEFT = 6;
const int HALL_POWER_LEFT = 7;
long START_TIME_LEFT = 0;
int STATE_LEFT = LOW;

void setup() {

  Serial.begin(9600);
  pinMode(RELAY_RIGHT, OUTPUT);
  pinMode(HALL_SENSOR_RIGHT, INPUT);
  pinMode(HALL_POWER_RIGHT, OUTPUT);
  pinMode(RELAY_LEFT, OUTPUT);
  pinMode(HALL_SENSOR_LEFT, INPUT);
  pinMode(HALL_POWER_LEFT, OUTPUT);

  // use these lines for hall sensors to be always on
  digitalWrite(HALL_POWER_RIGHT, HIGH);
  digitalWrite(HALL_POWER_LEFT, HIGH);

  Serial.print("Auto shutoff minutes: "); Serial.println(AUTO_SHUTOFF_MIN);
  Serial.print("Auto shutoff ms:      "); Serial.println(AUTO_SHUTOFF_MS);
  Serial.print("De-bouncing delay:    "); Serial.println(DEBOUNCING_DELAY);
  Serial.print("Hall turn-on delay:   "); Serial.println(HALL_TURNON_DELAY);

}

void loop() {

//  Serial.println(digitalRead(HALL_SENSOR_RIGHT));
//  delay(100);

  bool toggle_right = shouldToggleLight(HALL_SENSOR_RIGHT, HALL_POWER_RIGHT, RELAY_RIGHT, START_TIME_RIGHT, STATE_RIGHT);
  if (toggle_right) {
    if (STATE_RIGHT == HIGH) {
      // turn off light
      STATE_RIGHT = LOW;
      digitalWrite(RELAY_RIGHT, STATE_RIGHT);
      Serial.println("Right light off");
    } else {
      // turn on light 
      STATE_RIGHT = HIGH;
      digitalWrite(RELAY_RIGHT, STATE_RIGHT);
      Serial.println("Right light on");
      START_TIME_RIGHT = millis();
    }
  }

  bool toggle_left = shouldToggleLight(HALL_SENSOR_LEFT, HALL_POWER_LEFT, RELAY_LEFT, START_TIME_LEFT, STATE_LEFT);
  if (toggle_left) {
    if (STATE_LEFT == HIGH) {
      // turn off light
      STATE_LEFT = LOW;
      digitalWrite(RELAY_LEFT, STATE_LEFT);
      Serial.println("Left light off");
    } else {
      // turn on light
      STATE_LEFT = HIGH;
      digitalWrite(RELAY_LEFT, STATE_LEFT);
      Serial.println("Left light on");
      START_TIME_LEFT = millis();
    }
  }
}


bool shouldToggleLight(int hall_sensor, int hall_power, int relay_pin, long start_time, int light_state) {

  int reading = getSensorReading(hall_sensor, hall_power);

  if (reading == LOW) {
    // light should be turned on
    Serial.println("Light should be on");

    if (light_state == HIGH) {
      // light was already on
      if (millis() - start_time > AUTO_SHUTOFF_MS) {
        // light has been on too long, time to toggle
        Serial.println("  light on too long, time to toggle");
        Serial.print("  "); Serial.print(millis());
        Serial.print(" - "); Serial.println(start_time);
        return true;
      } else {
        // light hasn't been on too long, don't toggle
        return false;
      }

    } else {
      // light is not already on, need to toggle
      Serial.println("  light isn't on, need to toggle");
      return true;
    }

  } else {
    // light should be turned off
    Serial.println("Light should be off");

    if (light_state == HIGH) {
      // light is currently on, need to toggle
      Serial.println("  light is on, need to toggle");
      return true;
    } else {
      // light is already off, don't toggle
      return false;
    }
  }
}

int getSensorReading(int hall_pin, int hall_power) {

  // turn on hall sensor
  // digitalWrite(hall_power, HIGH);

  int previous = digitalRead(hall_pin);
  int current;
  
  // read values until result is consistent
  while (true) {
    delay(DEBOUNCING_DELAY);
    current = digitalRead(hall_pin);
    if (current == previous) {
      break;
    } else {
      previous = current;
    }
  }

  // turn off hall sensor
  // digitalWrite(hall_power, LOW);

  return current;
}
