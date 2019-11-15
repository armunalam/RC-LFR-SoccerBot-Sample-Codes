#include <QTRSensors.h>

#define NUM_SENSORS   6     // number of sensors used
#define TIMEOUT       2500  // waits for 2500 microseconds for sensor outputs to go low
#define EMITTER_PIN   2     // emitter is controlled by digital pin 2

// sensors 0 through 7 are connected to digital pins 3 through 10, respectively
QTRSensorsRC qtrrc((unsigned char[]) {3, 8, 9, 10, 11, 12}, NUM_SENSORS, TIMEOUT, EMITTER_PIN);
unsigned int sensorValues[NUM_SENSORS];

int E2 = 6; //M2 speed control
int E1 = 5; //M1 speed control. E1 and E2 are pwm pins.
int M1 = 4; //M1 Direction Control
int M2 = 7; //M2 Direction Control

void setup()
{
  delay(500);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);    // turn on Arduino's LED to indicate we are in calibration mode
  for (int i = 0; i < 200; i++)  // make the calibration take about 10 seconds
  {
    qtrrc.calibrate();       // reads all sensors 10 times at 2500 us per read (i.e. ~25 ms per call)
  }
  digitalWrite(13, LOW);     // turn off Arduino's LED to indicate we are through with calibration

  // print the calibration minimum values measured when emitters were on (mostly used for testing)
  Serial.begin(9600);
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(qtrrc.calibratedMinimumOn[i]);
    Serial.print(' ');
  }
  Serial.println();

  // print the calibration maximum values measured when emitters were on (mostly used for testing)
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(qtrrc.calibratedMaximumOn[i]);
    Serial.print(' ');
  }
  Serial.println();
  Serial.println();
  delay(1000);

  //move robot forward and begin loop
  digitalWrite(M1, HIGH);
  digitalWrite(M2, HIGH);
}

void loop()
{
  int lastError;

  // read calibrated sensor values and obtain a measure of the line position from 0 to 5000
  unsigned int position = qtrrc.readLine(sensorValues);

  //compute error from line position. error will be near-zero when robot is centered
  //over line.

  int error = position - 2460;

  delay(250);

  // set the motor speed based on proportional and derivative PID terms (experimentally determined)
  // KP is the a floating-point proportional constant
  // KD is the floating-point derivative constant

  float KP = 0.05;
  float KD = 2.0;

  lastError = error;

  int motorSpeed = KP * error + KD * (error - lastError);

  //change our motor speeds based on PD calculation
  int m1Speed = 100 + motorSpeed;
  int m2Speed = 100 - motorSpeed;

  //force motor speeds to be positive
  if (m1Speed < 0)
    m1Speed = 0;
  if (m2Speed < 0)
    m2Speed = 0;

  // set motor speeds using the two motor speed variables above
  digitalWrite(E1, m2Speed);
  digitalWrite(E2, m1Speed);
}
