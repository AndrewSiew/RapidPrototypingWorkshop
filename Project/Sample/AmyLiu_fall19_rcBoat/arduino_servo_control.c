#include <Servo.h> //like import; brings in servo library


// pin slots
const int switchPin = 8; //numbers correspond to pin slot
const int ledPin = 10;

// servo pin
const int servoPin = 9;
Servo servo; //create a servo object



int buttonState;
bool state = false; //whether or not motor is sweeping
bool fwd = true; //direction of motor sweep
int angle;

int time = millis();
int press = 0;

void setup()
{
  servo.attach(servoPin);

  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop()
{

  buttonState = digitalRead(buttonPin);
  angle = servo.read();

  if (buttonState == HIGH)
  {
    //check that it has been at least 1s since last effective press
    if (time >= press + 1000)
    {
      //if sweeping, stop. if stopped, start sweeping
      if (state == true)
      {
        state = false;
        digitalWrite(ledPin, LOW);

      } 
      else
      {
        state = true;
        digitalWrite(ledPin, HIGH);
      }
      press = time; //set new effective press
    }
  }

  //while state is active & dir is forward
  while (state == true && fwd == true)
  {
    if (angle >= 0 && angle < 180)
    {
      servo.write(angle++);
    } 
    else
    {
      fwd == false;
    }
  }

  //while state is active & dir is reverse
  while (state == true && fwd == false)
  {
    if (angle > 0 && angle <= 180)
    {
      servo.write(angle--);
    } 
    else
    {
      fwd = true;
    }
  }

}