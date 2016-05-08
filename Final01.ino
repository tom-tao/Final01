#include <Servo.h>
Servo myservo;

//adding comments
int pos = 0;

//add unncessary stuff
int someUnnecessaryVariable=0;

int buttonPin = 2;
int buttonVal = 0;
int pButtonVal = 0;

int counter = 0;

i am adding a space ship

void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
}

void loop() {
  pButtonVal = buttonVal;
  buttonVal = digitalRead(buttonPin);
  //Serial.println(buttonVal);
  Serial.println(counter);

  if (pButtonVal == 1) {
    if (buttonVal == 0) {
      counter = 1;
    } else {
      counter = 0;
    }
  }

  pButtonVal=buttonVal;

  if (counter == 0) { // counter even number
    pos = 0;
    myservo.write(pos);
  } else if (counter == 1) {  // counter odd number
    for (pos = 0; pos < 180; pos += 1) {
      myservo.write(pos);
      delay(30);
    }
    for (pos = 180; pos >= 1; pos -= 1) {
      myservo.write(pos);
      delay(30);
    }
  }

}

