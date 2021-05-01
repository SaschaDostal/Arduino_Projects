void stay(void) {
  resetButtons();
  moveStop();
  while (!button1pressed) {
    int whatToDo = random(0, 4);
    int howLong = random(3, 6);

    if (whatToDo == 0) {
      int n = random(1, 4);
      randomSound(n);
    } else if (whatToDo == 1) {
      myservo.write(SERVO_LEFT);
    } else if (whatToDo == 2) {
      myservo.write(SERVO_RIGHT);
    } else if (whatToDo == 3) {
      myservo.write(SERVO_MIDDLE);
    }
    delay(howLong * 1000);
    resetButtons();
    checkButtons();
    if (button2pressed) {
      delay(500);
      randomTrick();
      delay(500);
    }
  }
  resetButtons();
}

//-------------------------------------------------------------------------------------------------------------------------------------
void doTrick(int number) {
  if (number == 0) {
    turnContinuouslyLeft();
    delay(2000);
    moveStop();
    randomSound(1);
    turnContinuouslyRight();
    delay(2000);
    moveStop();
    delay(300);
  } else if (number == 1) {
    myservo.write(SERVO_LEFT);
    randomSound(1);
    turnContinuouslyLeft();
    delay(1000);
    moveStop();
    myservo.write(SERVO_RIGHT);
    randomSound(1);
    turnContinuouslyRight();
    delay(1000);
    moveStop();
    myservo.write(SERVO_MIDDLE);
    randomSound(1);
  } else if (number == 2) {
    randomSound(1);
    for (int i = 0; i < 3; i++) {
      myservo.write(SERVO_RIGHT);
      delay(400);
      myservo.write(SERVO_LEFT);
      delay(400);
    }
    myservo.write(SERVO_MIDDLE);
    randomSound(2);
  }
}

//-------------------------------------------------------------------------------------------------------------------------------------
void randomTrick() {
  int randNum = random(0, 3);
  doTrick(randNum);
}
