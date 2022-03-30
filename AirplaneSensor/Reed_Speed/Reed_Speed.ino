
#define REED_PIN 7
#define HISTORY_SIZE 10

bool magnetized = false;
long start = 0;
long now = 0;

long history[HISTORY_SIZE];
int index = 0;

// the setup function runs once when you press reset or power the board
void setup()
{

  Serial.begin(9600);
  
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  // we're using INPUT_PULLUP, which means the internal resistor for that pin is being turned on
  // this means the default value of the pin is HIGH, and will only read LOW if we connect the pin to ground
  // by default, the reed switch is OPEN, which means it's NOT making a connection to ground
  // when a magnet comes into range of the switch, it will become CLOSED, which connects the pin to ground
  // so when pin reads LOW, we know the switch is being activated.
  pinMode(REED_PIN, INPUT_PULLUP);

//  Serial.println("Beginning test");
}

// the loop function runs over and over again forever
void loop()
{
//  if (millis() % 20 == 0) printInformation();

  if (digitalRead(REED_PIN) == LOW)
  {
    // reed switch is activated
    digitalWrite(LED_BUILTIN, HIGH);
    
    if (magnetized)
    {
      // magnet has already been sensed, so we're in the same short activation period. Do nothing
    }
    else
    {
      // this is the first time the magnet is being sensed for this activation period

      // update the bool
      magnetized = true;
      
      // for now, just a send a message to the console with the current time
//      Serial.print("Rising edge sensed at ");
//      Serial.println(millis());

      // calculate the change in time
      now = millis();

//      Serial.print("dt: "); Serial.println(now - start);
//      Serial.print("RPM: "); Serial.println(60000 / (now - start));

      // put the current delta t value into the array
      history[index] = now - start;

      // increment the index variable
      incrementIndex();

      // print the current history information
      printInformation();

      start = now;
    }
  }
  else
  {
    // reed switch is not activated
    digitalWrite(LED_BUILTIN, LOW);

    if (magnetized)
    {
      // the magnet sensing period has ended, update the bool
      magnetized = false;
    }
    else
    {
      // we're currently in a trough, do nothing
    }
  }
}

long historySum()
{
  long sum = 0;
  
  for (int ii = 0; ii < HISTORY_SIZE; ++ii)
  {
    sum += history[ii];
  }

  return sum;
}

void incrementIndex()
{
  index = (index + 1) % HISTORY_SIZE;
}

void printInformation()
{
//  Serial.print("Average RPM: ");
//  Serial.print(" ");
  Serial.println( 60000 * HISTORY_SIZE / historySum() );
}
