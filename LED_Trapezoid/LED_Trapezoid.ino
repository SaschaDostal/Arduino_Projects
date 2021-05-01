// INCLUDES ___________________________________________________________________________________________
#include <Adafruit_NeoPixel.h>
#include <avr/interrupt.h>
#include "FastLED.h"

// METHOD DECLARATION _________________________________________________________________________________

// standardMethods
void clearStrip(void);
enum Color { red, green, blue, pink, yellow, orange, turquoise, white, black};
void changeColor(void);
void setLine( int lineSelection, int num, Color col);
void setPixel( int num, Color col);
bool testL(void);
bool testR(void);
bool testC(void);
bool testK(void);
bool testB(void);
void wait( int milliSec );

// programMethods
void startUp(void);
void activationShow(void);
void gaming(void);
void randomBlocks(void);
void randomBigBlocks(void);
void flames(void);
void colorPalette(void);

void ambilight66(void);
void ambilight3(void);

// PORTS ______________________________________________________________________________________________
#define BUTTON_L   12     // left
#define BUTTON_R   11     // right
#define BUTTON_C   10     // color/change
#define BUTTON_K   9      // okay
#define BUTTON_B   8      // back

#define PIXEL_PIN    6    // Neopixel-Pin
#define PIXEL_COUNT 132   // 6 x 22 Neopixel LEDs

// GLOBAL VARIABLES ___________________________________________________________________________________
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);
bool button_l = false;
bool button_r = false;
bool button_c = false;
bool button_k = false;
bool button_b = false;
int select = 0; // used for selected program
int color = 0; // global color setting
bool startUpDone = false;

// SETUP ______________________________________________________________________________________________
void setup() {
  pinMode(BUTTON_L, INPUT_PULLUP);
  pinMode(BUTTON_R, INPUT_PULLUP);
  pinMode(BUTTON_C, INPUT_PULLUP);
  pinMode(BUTTON_K, INPUT_PULLUP);
  pinMode(BUTTON_B, INPUT_PULLUP);
  cli();
  // Setup Timer-Interrupt
  OCR1A = 312; // compare value (smaller -> faster)
  TCCR1B = (1 << CS12) | ( 1 << WGM12); // set prescaler
  TIMSK1 = (1 << OCF1A); // enable timer interrupt
  sei();
  strip.begin(); // start strip
  strip.show(); // initialize all pixels to 'off'
}

// MAIN LOOP __________________________________________________________________________________________
void loop() {
  if(!startUpDone) startUp();
  for(int i = 0; i < 22; i++){
    if(color == 0){
      setLine(2, i, pink);
      setLine(20, i, turquoise);
    } else if(color == 1){
      setLine(2, i, red);
      setLine(20, i, orange);
    }
  }
  
  if (testL()) {
    setLine(44, select, black);
    --select;
  }
  if (testR()) {
    setLine(44, select, black);
    ++select;
  }
  if (select > 21) select = 21;
  if (select < 0) select = 0;
  setLine(44, select, white);
  strip.show();

  if (testK()) {
    switch (select) {
      case 0: activationShow(); gaming(); break;
      case 1: activationShow(); randomBlocks(); break;
      case 2: activationShow(); randomBigBlocks(); break;
      case 19: activationShow(); colorPalette(); 
      case 20: activationShow(); ambilight3(); break;
      case 21: activationShow(); ambilight66(); break;
      default: break;
    }
  }
  if(testC()){
    color++;
    if (color > 1) color = 0;
  }
}

// INTERRUPT ROUTINE __________________________________________________________________________________
ISR(TIMER1_COMPA_vect){
  if(digitalRead(BUTTON_L)) button_l = true;
  if(digitalRead(BUTTON_R)) button_r = true;
  if(digitalRead(BUTTON_C)) button_c = true;
  if(digitalRead(BUTTON_K)) button_k = true;
  if(digitalRead(BUTTON_B)) button_b = true;
}
