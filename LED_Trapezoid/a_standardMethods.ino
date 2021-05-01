// PIXEL_METHODS ______________________________________________________________________________________
void clearStrip(void){
  for(int i = 0; i < PIXEL_COUNT; i++){
    strip.setPixelColor(i, 0, 0, 0);
  }
}

void changeColor(void){
  color++;
  if (color > 1) color = 0;
}

void setLine( int lineSelection, int num, Color col){
  // left lower part of trapezoid
  if(lineSelection == 1){
    setPixel(num, col);

  // middle lower part of trapezoid
  } else if(lineSelection == 2){
    setPixel(num + 22, col);

  // right lower part of trapezoid
  } else if(lineSelection == 3){
    setPixel(num + 44, col);

  // left upper part of trapezoid
  } else if (lineSelection == 10){
    setPixel(131 - num, col);
    
  // middle upper part of trapezoid
  } else if (lineSelection == 20){
    setPixel(109 - num, col);
    
  // right upper part of trapezoid
  } else if (lineSelection == 30){
    setPixel(87 - num, col);

  // left both parts of trapezoid
  } else if (lineSelection == 11){
    setPixel(num, col);
    setPixel(131 - num, col);

  // middle both parts of trapezoid
  } else if (lineSelection == 22){
    setPixel(num + 22, col);
    setPixel(109 - num, col);

  // right both parts of trapezoid
  } else if (lineSelection == 33){
    setPixel(num + 44, col);
    setPixel(87 - num, col);
  
  // right and left both parts of trapezoid
  } else if (lineSelection == 44){
    setPixel(num, col);
    setPixel(131 - num, col);
    setPixel(65 - num, col);
    setPixel(num + 66, col);
    
  // all parts of trapezoid
  } else if (lineSelection == 66){
    setPixel(num, col);
    setPixel(131 - num, col);
    setPixel(num + 22, col);
    setPixel(109 - num, col);
    setPixel(num + 44, col);
    setPixel(87 - num, col);
  }
}

void setPixel( int num, Color col){
  switch( col ){
    case red: strip.setPixelColor(num, 255, 0, 0); break;
    case green: strip.setPixelColor(num, 0, 255, 0); break;
    case blue: strip.setPixelColor(num, 0, 0, 255); break;
    case pink: strip.setPixelColor(num, 255, 0, 255); break;
    case yellow: strip.setPixelColor(num, 255, 255, 0); break;
    case orange: strip.setPixelColor(num, 255, 100, 0); break;
    case turquoise: strip.setPixelColor(num, 0, 100, 255); break;
    case white: strip.setPixelColor(num, 255, 255, 255); break;
    case black: strip.setPixelColor(num, 0, 0, 0);
  }
}

// BUTTON_METHODS _____________________________________________________________________________________
bool testL(void){
  if(button_l){
    delay(150);
    resetButtons();
    return true;
  }
  return false;
}
bool testR(void){
  if(button_r){
    delay(150);
    resetButtons();
    return true;
  }
  return false;
}
bool testC(void){
  if(button_c){
    delay(250);
    resetButtons();
    return true;
  }
  return false;
}
bool testK(void){
  if(button_k){
    delay(250);
    resetButtons();
    return true;
  }
  return false;
}
bool testB(void){
  if(button_b){
    delay(250);
    resetButtons();
    return true;
  }
  return false;
}
void resetButtons(void){
  button_l = false;
  button_r = false;
  button_c = false;
  button_k = false;
  button_b = false;
}

// TIMER_METHODS_______________________________________________________________________________________
void wait( int milliSec ){
  unsigned long prevMillis = millis();
  while(true){
    if(digitalRead(BUTTON_B) || !(millis()- prevMillis <= milliSec)) break;
  }
}
