
#include "Plotter.h"

#define REED_PIN 7

double vel = 0;
//Plotter p;
bool activated = false;
long current = millis();

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(REED_PIN, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("Welcome to the speedometer");

//  p.Begin();
//  p.AddTimeGraph( "Speed", 500, "x", vel );
}



void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(REED_PIN) == HIGH) {
    digitalWrite(LED_BUILTIN, HIGH);
    // the sensor is not being activated
    if (activated) {
      activated = false;
    }
  } else {
    digitalWrite(LED_BUILTIN, LOW);
    // sensor is being activated!
    if (not activated) {
      activated = true;
      // get angular velocity in radians / second
      vel = (2.0 * PI) / ((millis() - current) / 1000.0);
//      Serial.print("diff = "); Serial.print(millis() - current);
      current = millis();
//      Serial.print("  w = "); Serial.print(vel);
      
      // get linear velocity in meters / second
      vel = vel * .3375; // radius is about 33.75 cm
      Serial.print("  v = "); Serial.println(vel);
      
      delay(20);
      
    }
  }

//  p.Plot();
//  Serial.println(vel);
  delay(20);
}

// angular veloctiy = change in angle / change in time
// change in angle = 2 PI radians
// change in time = however much time difference is measured between ticks

// velocity = angular velocity * radius
// using meters for radius should give velocity in meters per second
