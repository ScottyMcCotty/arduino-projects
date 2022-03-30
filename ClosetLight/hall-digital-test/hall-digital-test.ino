/* This code is to be used with KY-024 Hall effect sensor
 * It displays both Analog and Digital values given by the sensor
 * Refer to www.surtrtech.com for more details
 */

const int Hall_Sensor = 4;
const int Hall_Power = 7;
const int Hall_Switch = 8;

int count = 0;
bool powered = false;


void setup() {
  Serial.begin(9600);
  pinMode(Hall_Sensor, INPUT);
  pinMode(Hall_Power, OUTPUT);
  pinMode(Hall_Switch, INPUT_PULLUP);

}

void loop() {

//  if (digitalRead(Hall_Sensor) == HIGH) {
//    if (detected) {
//      // do nothing
//    } else {
//      Serial.println("Detected");
//      detected = true;
//    }
//  } else {
//    if (detected) {
//      Serial.println("Not detected");
//      detected = false;
//    } else {
//      // do nothing
//    }
//  }

//  Serial.println(digitalRead(Hall_Sensor));
//  delay(100);

  if (digitalRead(Hall_Switch) == LOW) {
    // send power to hall sensor
    digitalWrite(Hall_Power, HIGH);
    powered = true;
  } else {
    // don't send power to hall sensor
    digitalWrite(Hall_Power, LOW);
    powered = false;
  }

  Serial.print(count++); Serial.print(": ");
  Serial.println(digitalRead(Hall_Sensor));
  delay(100);
}
