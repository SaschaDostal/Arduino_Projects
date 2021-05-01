//-------------------------------------------------------------------------------------------------------------------------------------
void changePath() {
  moveStop();   // stop forward movement
  myservo.write(SERVO_RIGHT);  // check distance to the right
  delay(500);
  rightDistance = readPing(); //set right distance
  delay(500);
  myservo.write(SERVO_LEFT);  // check distace to the left
  delay(700);
  leftDistance = readPing(); //set left distance
  delay(500);
  myservo.write(SERVO_MIDDLE); //return to center
  delay(100);
  compareDistance();
}

//-------------------------------------------------------------------------------------------------------------------------------------
void compareDistance()   // find the longest distance
{
  if (leftDistance > rightDistance) //if left is less obstructed
  {
    turnLeft();
  }
  else if (rightDistance > leftDistance) //if right is less obstructed
  {
    turnRight();
  }
  else //if they are equally obstructed
  {
    turnAround();
  }
}

//-------------------------------------------------------------------------------------------------------------------------------------
void checkButtons(void) {
  if (digitalRead(BUTTON1)) {
    button1pressed = true;
    sound(-1);
    delay(200);
  }
  if (digitalRead(BUTTON2)) {
    button2pressed = true;
    sound(-1);
    delay(200);
  }
}

//-------------------------------------------------------------------------------------------------------------------------------------
void resetButtons(void) {
  button1pressed = false;
  button2pressed = false;
}

//-------------------------------------------------------------------------------------------------------------------------------------
