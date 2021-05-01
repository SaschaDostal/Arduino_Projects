void startUp(void){
  for(int i = 0; i < 66; i++){
    if(color == 0){
      setPixel(i, pink);
      setPixel(66 + i, turquoise);
    } else if(color == 1){
      setPixel(i, red);
      setPixel(66 + i, orange);
    }
    delay(10);
    strip.show();
  }
  for(int i = 0; i < 22; i++){
    setLine(44, i, black);
    delay(10);
    strip.show();
  }
  startUpDone = true;
}

void activationShow(void){
  for(int i = 0; i < 22; i++){
    if(color == 0){
      setLine(44, i, pink);
    } else if(color == 1){
      setLine(44, i, red);
    }
    strip.show();
    delay(10);
  }
  for(int i = 21; i >= 0; i--){
    if(color == 0){
      setLine(44, i, turquoise);
    } else if(color == 1){
      setLine(44, i, orange);
    }
    strip.show();
    delay(10);
  }
  for(int i = 0; i < 66; i++){
    setPixel(i, black);
    setPixel(66 + i, black);
    strip.show();
    delay(10);
  }
  startUpDone = false;
}

void gaming(void){
  while(true) { 
    for(int i = 0; i < 22; i++){
      if(color == 0){
        setLine(1, i, turquoise);
        setLine(2, i, pink);
        setLine(3, 21 - i, turquoise);
        setLine(10, i, pink);
        setLine(20, 21 - i, turquoise);
        setLine(30, 21 - i, pink);
      } else if(color == 1){
        setLine(1, i, red);
        setLine(2, i, orange);
        setLine(3, 21 - i, red);
        setLine(10, i, orange);
        setLine(20, 21 - i, red);
        setLine(30, 21 - i, orange);
      }
      strip.show();
      wait(50);
      if(testB()){
        clearStrip();
        return;
      }
    }
    wait(3000);
    if(testC()) changeColor();
    for(int i = 0; i < 22; i++){
      if(color == 0){
        setLine(1, i, pink);
        setLine(2, 21 - i, turquoise);
        setLine(3, 21 - i, pink);
        setLine(10, i, turquoise);
        setLine(20, i, pink);
        setLine(30, 21 - i, turquoise);
      } else if(color == 1){
        setLine(1, i, orange);
        setLine(2, 21 - i, red);
        setLine(3, 21 - i, orange);
        setLine(10, i, red);
        setLine(20, i, orange);
        setLine(30, 21 - i, red);
      }
      strip.show();
      wait(50);
      if(testB()){
        clearStrip();
        return;
      }
    }
    wait(3000);
    if(testC()) changeColor();
  }
}

void randomBlocks(void){
  int randomNum;
  byte blockStatus[30] = {0}; // 0: not set, 1: color1, 2: color2
  bool allSet = false;
  int blockColor = 1; // 1: color1, 2: color2
  
  while(true) {
    randomNum = (int) random(0, 30);

    if(!allSet && (blockStatus[randomNum]!=0)) continue;
    if(blockStatus[randomNum] == blockColor) continue; 

    int i, j;
    switch(randomNum){
      case 0: i=0; j=i+5; break;
      case 1: i=5; j=i+4; break;
      case 2: i=9; j=i+4; break;
      case 3: i=13; j=i+4; break;
      case 4: i=17; j=i+5; break;
      case 5: i=22; j=i+5; break;
      case 6: i=27; j=i+4; break;
      case 7: i=31; j=i+4; break;
      case 8: i=35; j=i+4; break;
      case 9: i=39; j=i+5; break;
      case 10: i=44; j=i+5; break;
      case 11: i=49; j=i+4; break;
      case 12: i=53; j=i+4; break;
      case 13: i=57; j=i+4; break;
      case 14: i=61; j=i+5; break;
      case 15: i=66; j=i+5; break;
      case 16: i=71; j=i+4; break;
      case 17: i=75; j=i+4; break;
      case 18: i=79; j=i+4; break;
      case 19: i=83; j=i+5; break;
      case 20: i=88; j=i+5; break;
      case 21: i=93; j=i+4; break;
      case 22: i=97; j=i+4; break;
      case 23: i=101; j=i+4; break;
      case 24: i=105; j=i+5; break;
      case 25: i=110; j=i+5; break;
      case 26: i=115; j=i+4; break;
      case 27: i=119; j=i+4; break;
      case 28: i=123; j=i+4; break;
      case 29: i=127; j=i+5; break;
    }
    blockStatus[randomNum]=blockColor;
    for(; i < j; i++){
      if(blockColor == 1){
        if(color == 0){
          setPixel(i, pink);
        } else if(color == 1){
          setPixel(i, red);
        }
      } else {
        if(color == 0){
          setPixel(i, turquoise);
        } else if(color == 1){
          setPixel(i, orange);
        }
      }
    }
    strip.show();
    if(blockColor == 1){
      blockColor = 2;
    } else {
      blockColor = 1;
    }
    if(!allSet){
      bool tester = true;
      for(int x = 0; x < 30; x++){
        if(blockStatus[x] == 0){
          tester = false; 
          break;
        }
      }
      if(tester) allSet = true;
    }
    if(testC()){
      changeColor();
      for(int x = 0; x < 30; x++){
        blockStatus[x] = 0;
      }
      allSet = false;
    }
    if(allSet){
      wait(500);
    } else {
      wait(30);
    }
    if (testB()){
      clearStrip();
      return;
    }
  }
}

void randomBigBlocks(void){
  int randomNum;
  byte blockStatus[6] = {0}; // 0: not set, 1: color1, 2: color2
  bool allSet = false;
  int blockColor = 1; // 1: color1, 2: color2
  
  while(true) {
    randomNum = (int) random(0, 6);

    if(!allSet && (blockStatus[randomNum]!=0)) continue;
    if(blockStatus[randomNum] == blockColor) continue; 

    int i, j;
    switch(randomNum){
      case 0: i=0; j=i+22; break;
      case 1: i=22; j=i+22; break;
      case 2: i=44; j=i+22; break;
      case 3: i=66; j=i+22; break;
      case 4: i=88; j=i+22; break;
      case 5: i=110; j=i+22; break;
    }
    blockStatus[randomNum]=blockColor;
    for(; i < j; i++){
      if(blockColor == 1){
        if(color == 0){
          setPixel(i, pink);
        } else if(color == 1){
          setPixel(i, red);
        }
      } else {
        if(color == 0){
          setPixel(i, turquoise);
        } else if(color == 1){
          setPixel(i, orange);
        }
      }
    }
    strip.show();
    if(blockColor == 1){
      blockColor = 2;
    } else {
      blockColor = 1;
    }
    if(!allSet){
      bool tester = true;
      for(int x = 0; x < 6; x++){
        if(blockStatus[x] == 0){
          tester = false; 
          break;
        }
      }
      if(tester) allSet = true;
    }
    if(testC()){
      changeColor();
      for(int x = 0; x < 6; x++){
        blockStatus[x] = 0;
      }
      allSet = false;
    }
    if(allSet){
      wait(1000);
    } else {
      wait(100);
    }
    if (testB()){
      clearStrip();
      return;
    }
  }
}

void flames(void){
  while(true) {
    clearStrip();
    if (testB()){
      clearStrip();
      return;
    }
  }
}
void colorPalette(void){
  while(true) {
    setPixel(0, red);
    setPixel(1, green);
    setPixel(2, blue);
    setPixel(3, pink);
    setPixel(4, yellow);
    setPixel(5, orange);
    setPixel(6, turquoise);
    setPixel(7,white);
    strip.show();
    wait(10000);
    if (testB()){
      clearStrip();
      return;
    }
  }
}
