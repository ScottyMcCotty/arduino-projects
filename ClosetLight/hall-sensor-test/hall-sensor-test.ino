/* This code is to be used with KY-024 Hall effect sensor
 * It displays both Analog and Digital values given by the sensor
 * Refer to www.surtrtech.com for more details
 */

const int Hall_Sensor = 4;

bool detected = false;


void setup() {
  Serial.begin(9600);
  pinMode(Hall_Sensor,INPUT);
 

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

  Serial.println(digitalRead(Hall_Sensor));
  delay(100);
}
