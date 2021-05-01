//-------------------------------------------------------------------------------------------------------------------------------------
void moveStop() {
  leftMotor.run(RELEASE); // stop the motors.
  leftMotor2.run(RELEASE);
  rightMotor.run(RELEASE);
  rightMotor2.run(RELEASE);
}
//-------------------------------------------------------------------------------------------------------------------------------------
void moveForward() {
  leftMotor.run(FORWARD);      // turn it on going forward
  leftMotor2.run(FORWARD);
  rightMotor.run(FORWARD);     // turn it on going forward
  rightMotor2.run(FORWARD);
  leftMotor.setSpeed(SPEED_L);
  leftMotor2.setSpeed(SPEED_L);
  rightMotor.setSpeed(SPEED_R);
  rightMotor2.setSpeed(SPEED_R);
}
//-------------------------------------------------------------------------------------------------------------------------------------
void moveBackward() {
  leftMotor.run(BACKWARD);
  leftMotor2.run(BACKWARD);
  rightMotor.run(BACKWARD);
  rightMotor2.run(BACKWARD);
  leftMotor.setSpeed(SPEED_L);
  leftMotor2.setSpeed(SPEED_L);
  rightMotor.setSpeed(SPEED_R);
  rightMotor2.setSpeed(SPEED_R);
}
//-------------------------------------------------------------------------------------------------------------------------------------
void turnRight() {
  rightMotor.setSpeed(SPEED_R);
  rightMotor.run(BACKWARD);
  rightMotor2.setSpeed(SPEED_R);
  rightMotor2.run(BACKWARD);
  leftMotor.setSpeed(SPEED_L);
  leftMotor.run(FORWARD);
  leftMotor2.setSpeed(SPEED_L);
  leftMotor2.run(FORWARD);
  delay(300);
  moveStop();
}

//-------------------------------------------------------------------------------------------------------------------------------------
void turnContinuouslyRight() {
  rightMotor.setSpeed(SPEED_R);
  rightMotor.run(BACKWARD);
  rightMotor2.setSpeed(SPEED_R);
  rightMotor2.run(BACKWARD);
  leftMotor.setSpeed(SPEED_L);
  leftMotor.run(FORWARD);
  leftMotor2.setSpeed(SPEED_L);
  leftMotor2.run(FORWARD);
}
//-------------------------------------------------------------------------------------------------------------------------------------
void turnLeft() {
  leftMotor.setSpeed(SPEED_L);
  leftMotor.run(BACKWARD);
  leftMotor2.setSpeed(SPEED_L);
  leftMotor2.run(BACKWARD);
  rightMotor.setSpeed(SPEED_R);
  rightMotor.run(FORWARD);
  rightMotor2.setSpeed(SPEED_R);
  rightMotor2.run(FORWARD);
  delay(300);
  moveStop();
}
//-------------------------------------------------------------------------------------------------------------------------------------
void turnContinuouslyLeft() {
  leftMotor.setSpeed(SPEED_L);
  leftMotor.run(BACKWARD);
  leftMotor2.setSpeed(SPEED_L);
  leftMotor2.run(BACKWARD);
  rightMotor.setSpeed(SPEED_R);
  rightMotor.run(FORWARD);
  rightMotor2.setSpeed(SPEED_R);
  rightMotor2.run(FORWARD);
}
//-------------------------------------------------------------------------------------------------------------------------------------
void turnAround() {
  leftMotor.setSpeed(SPEED_L);
  leftMotor.run(BACKWARD);
  leftMotor2.setSpeed(SPEED_L);
  leftMotor2.run(BACKWARD);
  rightMotor.setSpeed(SPEED_R);
  rightMotor.run(FORWARD);
  rightMotor2.setSpeed(SPEED_R);
  rightMotor2.run(FORWARD);
  delay(500);
  moveStop();
}

void driveBackAndChangePath() {
  moveBackward();
  delay(600);
  changePath();
}
