#include <Adafruit_NeoPixel.h>

void setPixel(int number , int r, int g, int b);
void setRandomColor(int number);
void setRandomColor(void);

void rainbow(void);
void halfHalf(void);
void color(void);
void partymode(void);
void heartbeat(void);
void all(void);

#define BUTTON_1   D5      //Button-Pins
#define BUTTON_2   D6

#define PIXEL_PIN   D1    //Neopixel-Pin
#define PIXEL_COUNT 11

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

int loopnr = 0;            //Arbeisvariablen
int select = 0;

void setup() {
  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);
  
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  all(); delay(200);
  heartbeat(); delay(200);
  halfHalf(); delay(200);
  rainbow(); delay(200);
  color(); delay(200);
  partymode(); delay(200);
}
//Programme_________________________________________________________________________________
//Heartbeat_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
void heartbeat(void){
   int multi = 1; //max 51
   boolean rise = 1;
   int doubleBeat = 0;
   int color = 5;
   while(true){ 
    if (color == 0){ for (int i = 0; i < PIXEL_COUNT; ++i){setPixel(i, multi * 5, 0, 0);}}
    if (color == 1){ for (int i = 0; i < PIXEL_COUNT; ++i){setPixel(i, multi * 5, multi * 5, 0);}}
    if (color == 2){ for (int i = 0; i < PIXEL_COUNT; ++i){setPixel(i, 0, multi * 5, 0);}}
    if (color == 3){ for (int i = 0; i < PIXEL_COUNT; ++i){setPixel(i, 0, multi * 5, multi * 5);}}
    if (color == 4){ for (int i = 0; i < PIXEL_COUNT; ++i){setPixel(i, 0, 0, multi * 5);}}
    if (color == 5){ for (int i = 0; i < PIXEL_COUNT; ++i){setPixel(i, multi * 5, 0, multi * 5);}}
    strip.show();
    
    if(multi < 51 && rise == 1) multi++;
    if(multi == 51) rise = 0;
    if(multi > 0 && rise == 0) multi--;
    if(multi == 0) {rise = 1; doubleBeat++;}
    if (doubleBeat > 1){ doubleBeat = 0; delay(250);}
    
    if (digitalRead(BUTTON_2)){ color++; delay(200);}
    delay(7);
    if (color > 5) color = 0;
    if (digitalRead(BUTTON_1)) break;
   }
   for (int i = 0; i < PIXEL_COUNT; ++i) setPixel(loopnr, 0, 0, 0); // alle LEDs ausschalten
   strip.show();
}
//Rainbow_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
void rainbow(void) {
  while (true) {
    setPixel(10 - loopnr, 255, 0, 0);
    setPixel(9 - loopnr, 200, 55, 0);
    setPixel(8 - loopnr, 200, 200, 0);
    setPixel(7 - loopnr, 55, 200, 0);
    setPixel(6 - loopnr, 0, 255, 0);
    setPixel(5 - loopnr, 0, 200, 55);
    setPixel(4 - loopnr, 0, 200, 200);
    setPixel(3 - loopnr, 0, 55, 200);
    setPixel(2 - loopnr, 0, 0, 255);
    setPixel(1 - loopnr, 55, 0, 200);
    setPixel(0 - loopnr, 200, 0, 200);
    strip.show();
    ++loopnr;
    if (loopnr > PIXEL_COUNT) loopnr = 0;
    if (digitalRead(BUTTON_1)) break;
    delay(75);
  }
  for (int i = 0; i < PIXEL_COUNT; ++i) setPixel(loopnr, 0, 0, 0); // alle LEDs ausschalten
  strip.show();
}
//HalfHalf_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
void halfHalf(void) {
  int color = 2;
  loopnr = 0;
  while (true) {
    if (digitalRead(BUTTON_2)){ color++; delay(200);}
    if (color > 2) color = 0;
    if(color == 0){setPixel(loopnr, 255, 255, 0); setPixel(loopnr+6, 0, 0, 255);} 
    if(color == 1){setPixel(loopnr, 255, 0, 255); setPixel(loopnr+6, 0, 255, 0);} 
    if(color == 2){setPixel(loopnr, 0, 255, 255); setPixel(loopnr+6, 255, 0, 0);} 
    strip.show();
    ++loopnr;
    if (loopnr > PIXEL_COUNT) loopnr = 0;
    if (digitalRead(BUTTON_1)) break;
    delay(75);
  }
  for (int i = 0; i < PIXEL_COUNT; ++i) setPixel(loopnr, 0, 0, 0); // alle LEDs ausschalten
  strip.show();
}
//Partymode_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
void partymode(void) {
  while (true) {
    if (loopnr == 0) {
      for (int i = 0; i <= PIXEL_COUNT; ++i) setPixel(i, 200, 0, 200);;
      strip.show();
    }
    if (loopnr == 1) {
      for (int i = 0; i <= PIXEL_COUNT; ++i) setPixel(i, 0, 255, 255);
      strip.show();
    }
    if (loopnr == 2) {
      for (int i = 0; i <= PIXEL_COUNT; ++i) setPixel(i, 0, 255, 0);
      strip.show();
    }
    if (loopnr == 3) {
      for (int i = 0; i <= PIXEL_COUNT; ++i) setPixel(i, 255, 0, 255);
      strip.show();
    }
    if (loopnr == 4) {
      for (int i = 0; i <= PIXEL_COUNT; ++i) setPixel(i, 0, 0, 255);
      strip.show();
    }
    if (loopnr == 5) {
      for (int i = 0; i <= PIXEL_COUNT; ++i) setPixel(i, 255, 0, 255);
      strip.show();
    }
    delay(50);
    for (int i = 0; i <= PIXEL_COUNT; ++i) setPixel(i, 0, 0, 0);
    strip.show();
    delay(50);
    ++loopnr;
    if (loopnr > 5) loopnr = 0;
    if (digitalRead(BUTTON_1)) break;
  }
  for (int i = 0; i < PIXEL_COUNT; ++i) setPixel(loopnr, 0, 0, 0); // alle LEDs ausschalten
  strip.show();
}
//Color_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 
void color(void) {
  int color = 0;
  while (true) {
    if (digitalRead(BUTTON_2)){ color++; delay(200);}
    if (color > 5) color = 0;
    delay(20);
    if (color == 0){ for (int i = 0; i < PIXEL_COUNT; ++i){setPixel(i, 255, 0, 0);}}
    if (color == 1){ for (int i = 0; i < PIXEL_COUNT; ++i){setPixel(i, 255, 255, 0);}}
    if (color == 2){ for (int i = 0; i < PIXEL_COUNT; ++i){setPixel(i, 0, 255, 0);}}
    if (color == 3){ for (int i = 0; i < PIXEL_COUNT; ++i){setPixel(i, 0, 255, 255);}}
    if (color == 4){ for (int i = 0; i < PIXEL_COUNT; ++i){setPixel(i, 0, 0, 255);}}
    if (color == 5){ for (int i = 0; i < PIXEL_COUNT; ++i){setPixel(i, 255, 0, 255);}}
    if (digitalRead(BUTTON_1)) break;
    strip.show();
  }
  for (int i = 0; i < PIXEL_COUNT; ++i) setPixel(loopnr, 0, 0, 0); // alle LEDs ausschalten
  strip.show();
}
//All_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
void all(void) {
  int color = 0;
  int modeNumber = 0;
  while (true) {
    // Choose random mode: heartbeat() 3, halfHalf 2, rainbow() 1
    modeNumber = random(0, 6);
    //rainbow()
    if ( modeNumber == 0 ) {
      for( int i = 0 ; i < PIXEL_COUNT*10; i++) {
        setPixel(10 - loopnr, 255, 0, 0);
        setPixel(9 - loopnr, 200, 55, 0);
        setPixel(8 - loopnr, 200, 200, 0);
        setPixel(7 - loopnr, 55, 200, 0);
        setPixel(6 - loopnr, 0, 255, 0);
        setPixel(5 - loopnr, 0, 200, 55);
        setPixel(4 - loopnr, 0, 200, 200);
        setPixel(3 - loopnr, 0, 55, 200);
        setPixel(2 - loopnr, 0, 0, 255);
        setPixel(1 - loopnr, 55, 0, 200);
        setPixel(0 - loopnr, 200, 0, 200);
        strip.show();
        ++loopnr;
        if (loopnr > PIXEL_COUNT) loopnr = 0;
        if (digitalRead(BUTTON_1)) goto breakLoop;
        delay(75);
      }
      for (int i = 0; i < PIXEL_COUNT; ++i) setPixel(loopnr, 0, 0, 0); // alle LEDs ausschalten
      strip.show();
    }
    //halfHalf()
    if (modeNumber == 1 || modeNumber == 2 ) {
      color = random(0, 3);
      loopnr = 0;
      for (int i = 0; i < PIXEL_COUNT*4; i++) {
        if(color == 0){setPixel(loopnr, 255, 255, 0); setPixel(loopnr+6, 0, 0, 255);} 
        if(color == 1){setPixel(loopnr, 255, 0, 255); setPixel(loopnr+6, 0, 255, 0);} 
        if(color == 2){setPixel(loopnr, 0, 255, 255); setPixel(loopnr+6, 255, 0, 0);} 
        strip.show();
        ++loopnr;
        if (loopnr > PIXEL_COUNT) loopnr = 0;
        if (digitalRead(BUTTON_1)) goto breakLoop;
        delay(75);
      }
      for (int i = 0; i < PIXEL_COUNT; ++i) setPixel(loopnr, 0, 0, 0); // alle LEDs ausschalten
      strip.show();
    }
    //heartbeat()
    if (modeNumber == 3 || modeNumber == 4 || modeNumber == 5){
      int multi = 1; //max 51
      boolean rise = 1;
      int doubleBeat = 0;
      int color = random(0, 6);
      for (int j = 0; j < 51*10; j++) { 
        if (color == 0){ for (int i = 0; i < PIXEL_COUNT; ++i){setPixel(i, multi * 5, 0, 0);}}
        if (color == 1){ for (int i = 0; i < PIXEL_COUNT; ++i){setPixel(i, multi * 5, multi * 5, 0);}}
        if (color == 2){ for (int i = 0; i < PIXEL_COUNT; ++i){setPixel(i, 0, multi * 5, 0);}}
        if (color == 3){ for (int i = 0; i < PIXEL_COUNT; ++i){setPixel(i, 0, multi * 5, multi * 5);}}
        if (color == 4){ for (int i = 0; i < PIXEL_COUNT; ++i){setPixel(i, 0, 0, multi * 5);}}
        if (color == 5){ for (int i = 0; i < PIXEL_COUNT; ++i){setPixel(i, multi * 5, 0, multi * 5);}}
        strip.show();
    
        if(multi < 51 && rise == 1) multi++;
        if(multi == 51) rise = 0;
        if(multi > 0 && rise == 0) multi--;
        if(multi == 0) {rise = 1; doubleBeat++;}
        if (doubleBeat > 1){ doubleBeat = 0; delay(250);}
    
        delay(7);
        if (color > 5) color = 0;
        if (digitalRead(BUTTON_1)) goto breakLoop;
      }
      for (int i = 0; i < PIXEL_COUNT; ++i) setPixel(loopnr, 0, 0, 0); // alle LEDs ausschalten
      strip.show();
    }
  }
  breakLoop:
  for (int i = 0; i < PIXEL_COUNT; ++i) setPixel(loopnr, 0, 0, 0); // alle LEDs ausschalten
  strip.show();
}
//Methodes_______________________________________________________________________________________
void setPixel(int number , int r, int g, int b){
  if (number >= PIXEL_COUNT) number = number - PIXEL_COUNT;
  if (number < 0) number = number + PIXEL_COUNT;
  strip.setPixelColor(number, r, g, b);
}
void setRandomColor(int number){
  int r = 255 * random(0, 1);
  int g = 255 * random(0, 1);
  int b = 255 * random(0, 1);
  while(r==0 && g==0 && b==0){
    r = 255 * random(0, 1);
    g = 255 * random(0, 1);
    b = 255 * random(0, 1);
  }
  strip.setPixelColor(number, r, g, b);
}
void setRandomColor(void){
  int r = 255 * random(0, 1);
  int g = 255 * random(0, 1);
  int b = 255 * random(0, 1);
  while(r==0 && g==0 && b==0){
    r = 255 * random(0, 1);
    g = 255 * random(0, 1);
    b = 255 * random(0, 1);
  }
  for(int i = 0; i < 11; i++) strip.setPixelColor(i, r, g, b);
}
