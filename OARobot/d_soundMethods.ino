void buzzer(int duration, int pitch) {
  for (int i = 0; i < duration; i++) {
    digitalWrite(SPEAKER, HIGH);
    delayMicroseconds(pitch);
    digitalWrite(SPEAKER, LOW);
    delayMicroseconds(pitch);
  }
}

//-------------------------------------------------------------------------------------------------------------------------------------
void sound(int number) {
  if (number == -2) {
    buzzer(1000, 250);

  } else if (number == -1) {
    buzzer(100, 500);
    delay(20);
    buzzer(100, 500);
    delay(20);
    buzzer(100, 500);

  } else if (number == 0) {
    buzzer(100, 1000);
    buzzer(100, 2000);
    delay(50);
    buzzer(100, 1000);

  } else if (number == 1) {
    buzzer(50, 2000);
    delay(50);
    buzzer(100, 1000);
    delay(50);
    buzzer(50, 2000);

  } else if (number == 2) {
    for (int i = 1000; i > 250; i -= 10) {
      buzzer(5, i);
    }

  } else if (number == 3) {
    for (int i = 1000; i > 400; i -= 10) {
      buzzer(5, i);
    }
    delay(100);
    for (int i = 400; i < 1000; i += 10) {
      buzzer(5, i);
    }
  }
}

//-------------------------------------------------------------------------------------------------------------------------------------
void randomSound(int count) {
  for (int i = 0; i < count; i++) {
    int randNum = random(0, 4);
    sound(randNum);
    if (count > 1) delay(200);
  }
}
