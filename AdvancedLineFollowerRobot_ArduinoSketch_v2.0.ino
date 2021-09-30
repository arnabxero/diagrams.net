#include <AFMotor.h>

//Motor Driver Variables
AF_DCMotor leftmotor(4);
AF_DCMotor rightmotor(3);

//All Sensor Readings
int s1 = A0;
int s2 = A1;
int s3 = A2;
int s4 = A3;
int s5 = A4;
int s6 = A5;

int rightled = 9;
int leftled = 10;

int last = 1;

long long int lost = 0;

// That Value Differentiates Between Black And White
int midVal = 900;

void RED()
{
  digitalWrite(2, HIGH);
  digitalWrite(13, LOW);
}
void GREEN()
{
  digitalWrite(2, LOW);
  digitalWrite(13, HIGH);
}


void setup()
{
  Serial.begin(9600);


  leftmotor.setSpeed(255);
  rightmotor.setSpeed(255);
  leftmotor.run(RELEASE);
  rightmotor.run(RELEASE);

  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);
  pinMode(s5, INPUT);
  pinMode(s6, INPUT);
  pinMode(2, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  RED();
  delay(500);
  GREEN();
  delay(500);
  RED();
  delay(500);
  GREEN();
  delay(500);
  RED();
  delay(500);
  GREEN();

}

void loop()
{

  Serial.print(analogRead(s1));
  Serial.print(" - ");

  Serial.print(analogRead(s2));
  Serial.print(" - ");

  Serial.print(analogRead(s3));
  Serial.print(" - ");

  Serial.print(analogRead(s4));
  Serial.print(" - ");

  Serial.print(analogRead(s5));
  Serial.print(" - ");

  Serial.println(analogRead(s6));


  ////////////////////////////////////////////////////////////////



  bool d[6] = {false};

  if (analogRead(s1) > midVal)
  {
    d[0] = true;
  }
  if (analogRead(s2) > midVal)
  {
    d[1] = true;
  }
  if (analogRead(s3) > midVal)
  {
    d[2] = true;
  }
  if (analogRead(s4) > midVal)
  {
    d[3] = true;
  }
  if (analogRead(s5) > midVal)
  {
    d[4] = true;
  }
  if (analogRead(s6) > midVal)
  {
    d[5] = true;
  }
  ////////////////////////////////////////////////////////////////////////


  if (lost > 351000)
  {
    leftmotor.run(FORWARD);
    rightmotor.run(FORWARD);
    delay(300);
    leftmotor.run(FORWARD);
    rightmotor.run(RELEASE);
    delay(200);
  }
  ///////////MOVE FORWARD////////////////////////
  else if (d[0] && d[1] && d[4] && d[5] && (!d[2]) && (!d[3]))
  {
    lost = 0;
    RED();
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    leftmotor.run(FORWARD);
    rightmotor.run(FORWARD);
  }


  ////////////////////FIND LINE//////////////////////
  else if (d[0] && d[1] && d[4] && d[5] && d[2] && d[3])
  {
    lost++;
    GREEN();
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);

    if (last == 1)
    {
      leftmotor.run(FORWARD);
      rightmotor.run(BACKWARD);
    }
    else if (last == 2)
    {
      leftmotor.run(BACKWARD);
      rightmotor.run(FORWARD);
    }

  }



  ////////////////////MOVE RIGHT//////////////////////
  else if (d[0] && (!d[1]) && (!d[2]) && d[3] && d[4] && d[5])
  {
    lost = 0;
    last = 1;
    GREEN();
    digitalWrite(rightled, HIGH);
    digitalWrite(leftled, LOW);
    leftmotor.run(FORWARD);
    rightmotor.run(RELEASE);
  }
  ////////////////////MOVE RIGHT 2//////////////////////
  else if ((!d[0]) && (!d[1]) && (!d[2]) && d[3] && d[4] && d[5])
  {
    lost = 0;
    last = 1;
    GREEN();
    digitalWrite(rightled, HIGH);
    digitalWrite(leftled, LOW);
    leftmotor.run(FORWARD);
    rightmotor.run(RELEASE);
  }
  //////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////
  ////////////////////MOVE RIGHT 2//////////////////////
  else if ((!d[0]) && (!d[1]) && (!d[2]) && (!d[3]) && d[4] && d[5])
  {
    lost = 0;
    last = 1;

    GREEN();
    digitalWrite(rightled, HIGH);
    digitalWrite(leftled, LOW);
    leftmotor.run(FORWARD);
    rightmotor.run(RELEASE);
  }
  ////////////////////MOVE RIGHT 2//////////////////////
  else if ((!d[0]) && (!d[1]) && (!d[2]) && (!d[3]) && (!d[4]) && d[5])
  {
    lost = 0;
    last = 1;
    GREEN();
    digitalWrite(rightled, HIGH);
    digitalWrite(leftled, LOW);
    leftmotor.run(FORWARD);
    rightmotor.run(RELEASE);
  }
  ///////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////
  ////////////////////MOVE SHARP RIGHT//////////////////////
  else if ((!d[0]) && (!d[1]) && d[2] && d[3] && d[4] && d[5])
  {
    lost = 0;
    last = 1;
    GREEN();
    digitalWrite(rightled, HIGH);
    digitalWrite(leftled, LOW);
    leftmotor.run(FORWARD);
    rightmotor.run(BACKWARD);
  }
  ///////////////////MOVE FAST RIGHT////////////////////
  else if ((!d[0]) && d[1] && d[2] && d[3] && d[4] && d[5])
  {
    lost = 0;
    last = 1;
    GREEN();
    digitalWrite(rightled, HIGH);
    digitalWrite(leftled, LOW);
    leftmotor.run(FORWARD);
    rightmotor.run(BACKWARD);
  }






  ////////////////////MOVE LEFT//////////////////////
  else if (d[0] && d[1] && d[2] && (!d[3]) && (!d[4]) && d[5])
  {
    lost = 0;
    last = 2;
    GREEN();
    digitalWrite(leftled, HIGH);
    digitalWrite(rightled, LOW);
    leftmotor.run(RELEASE);
    rightmotor.run(FORWARD);
  }
  ////////////////////MOVE LEFT 2//////////////////////
  else if (d[0] && d[1] && d[2] && (!d[3]) && (!d[4]) && (!d[5]))
  {
    lost = 0;
    last = 2;
    GREEN();
    digitalWrite(leftled, HIGH);
    digitalWrite(rightled, LOW);
    leftmotor.run(RELEASE);
    rightmotor.run(FORWARD);
  }
  /////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////
  ////////////////////MOVE LEFT 2//////////////////////
  else if (d[0] && d[1] && (!d[2]) && (!d[3]) && (!d[4]) && (!d[5]))
  {
    lost = 0;
    last = 2;
    GREEN();
    digitalWrite(leftled, HIGH);
    digitalWrite(rightled, LOW);
    leftmotor.run(RELEASE);
    rightmotor.run(FORWARD);
  }
  ////////////////////MOVE LEFT 2//////////////////////
  else if (d[0] && (!d[1]) && (!d[2]) && (!d[3]) && (!d[4]) && (!d[5]))
  {
    lost = 0;
    last = 2;
    GREEN();
    digitalWrite(leftled, HIGH);
    digitalWrite(rightled, LOW);
    leftmotor.run(RELEASE);
    rightmotor.run(FORWARD);
  }
  //////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////
  ////////////////////MOVE SHARP LEFT//////////////////////
  else if (d[0] && d[1] && d[2] && d[3] && (!d[4]) && (!d[5]))
  {
    lost = 0;
    last = 2;
    GREEN();
    digitalWrite(leftled, HIGH);
    digitalWrite(rightled, LOW);
    leftmotor.run(BACKWARD);
    rightmotor.run(FORWARD);
  }
  ///////////////////MOVE FAST LEFT////////////////////
  else if (d[0] && d[1] && d[2] && d[3] && d[4] && (!d[5]))
  {
    lost = 0;
    last = 2;
    GREEN();
    digitalWrite(leftled, HIGH);
    digitalWrite(rightled, LOW);
    leftmotor.run(BACKWARD);
    rightmotor.run(FORWARD);
  }


  /////////////////////STOP//////////////////////
  else if ((!d[0]) && (!d[1]) && (!d[2]) && (!d[3]) && (!d[4]) && (!d[5]))
  {
    lost = 0;
    RED();
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    leftmotor.run(RELEASE);
    rightmotor.run(RELEASE);

  }
}
