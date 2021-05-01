
#include <Adafruit_NeoPixel.h>
void matrix(int x, int y, int r, int g, int b);

#define BUTTON_1   12     //Button-Pins
#define BUTTON_2   11
#define BUTTON_3   10
#define BUTTON_4   9
#define BUTTON_5   8

#define PIXEL_PIN    6    //Neopixel-Pin
#define PIXEL_COUNT 131
#define _time 50

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

int loopnr = 0; //Arbeisvariablen
int select = 0;

int line1 = 0; // Lines der Led-Kette
int line2 = 0;
int line3 = 0;
int line4 = 0;

void setup() {
  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);
  pinMode(BUTTON_3, INPUT_PULLUP);
  pinMode(BUTTON_4, INPUT_PULLUP);
  pinMode(BUTTON_5, INPUT_PULLUP);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  bool Button1 = digitalRead(BUTTON_1);
  bool Button2 = digitalRead(BUTTON_2);
  bool Button3 = digitalRead(BUTTON_3);
  bool Button4 = digitalRead(BUTTON_4);
  bool Button5 = digitalRead(BUTTON_5);
  delay(100);

  //Programm-Auswahl----------------------------------
  if (Button1 == 1) {
    strip.setPixelColor(select, 0, 0, 0);
    --select;
  }
  if (Button2 == 1) {
    strip.setPixelColor(select, 0, 0, 0);
    ++select;
  }
  if (select > 15) select = 15;
  if (select < 0) select = 0;
  strip.setPixelColor(select, 255, 255, 255);
  strip.show();

  if (Button4 == 1) {
    switch (select) {
      case 0: WishfulSinking();
      case 1: flames();
      default: break;
    }
  }
}
//Programme_____________________________________________________________________________________

void WishfulSinking(void) {
  bool Button5 = digitalRead(BUTTON_5);
  while (Button5 == 0) {
    int Rand = random(1, 6);

    // Schachbrett -----------------------------------------------
    if (Rand == 1) {
      for (int t = 0; t < 2; ++t) {
        matrix(0, 3, 0, 100, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 2; ++i) matrix(i, i + 2, 255, 0, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 3; ++i) matrix(i, i + 1, 0, 100, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 4; ++i) matrix(i, i, 255, 0, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 3; ++i) matrix(i + 1, i, 0, 100, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 2; ++i) matrix(i + 2, i, 255, 0, 255);
        strip.show(); delay(_time);
        matrix(3, 0, 0, 100, 255);
        strip.show(); delay(_time);

        matrix(0, 3, 255, 0, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 2; ++i) matrix(i, i + 2, 0, 100, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 3; ++i) matrix(i, i + 1, 255, 0, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 4; ++i) matrix(i, i, 0, 100, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 3; ++i) matrix(i + 1, i, 255, 0, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 2; ++i) matrix(i + 2, i, 0, 100, 255);
        strip.show(); delay(_time);
        matrix(3, 0, 255, 0, 255);
        strip.show(); delay(_time);
      }
    }
    if (Rand == 2) {
      for (int t = 0; t < 2; ++t) {
        matrix(3, 0, 0, 100, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 2; ++i) matrix(i + 2, i, 255, 0, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 3; ++i) matrix(i + 1, i, 0, 100, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 4; ++i) matrix(i, i, 255, 0, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 3; ++i) matrix(i, i + 1, 0, 100, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 2; ++i) matrix(i, i + 2, 255, 0, 255);
        strip.show(); delay(_time);
        matrix(0, 3, 0, 100, 255);
        strip.show(); delay(_time);

        matrix(3, 0, 255, 0, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 2; ++i) matrix(i + 2, i, 0, 100, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 3; ++i) matrix(i + 1, i , 255, 0, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 4; ++i) matrix(i, i, 0, 100, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 3; ++i) matrix(i, i + 1, 255, 0, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 2; ++i) matrix(i, i + 2, 0, 100, 255);
        strip.show(); delay(_time);
        matrix(0, 3, 255, 0, 255);
        strip.show(); delay(_time);
      }
    }
    if (Rand == 3) {
      for (int t = 0; t < 3; ++t) {
        matrix(0, 3, 0, 100, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 2; ++i) matrix(i, i + 2, 0, 100, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 3; ++i) matrix(i, i + 1, 0, 100, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 4; ++i) matrix(i, i, 0, 100, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 3; ++i) matrix(i + 1, i, 0, 100, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 2; ++i) matrix(i + 2, i, 0, 100, 255);
        strip.show(); delay(_time);
        matrix(3, 0, 0, 100, 255);
        strip.show(); delay(_time);

        matrix(0, 3, 255, 0, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 2; ++i) matrix(i, i + 2, 255, 0, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 3; ++i) matrix(i, i + 1, 255, 0, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 4; ++i) matrix(i, i, 255, 0, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 3; ++i) matrix(i + 1, i, 255, 0, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 2; ++i) matrix(i + 2, i, 255, 0, 255);
        strip.show(); delay(_time);
        matrix(3, 0, 255, 0, 255);
        strip.show(); delay(_time);
      }
    }
    if (Rand == 4) {
      for (int t = 0; t < 3; ++t) {
        matrix(3, 0, 0, 100, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 2; ++i) matrix(i + 2, i, 0, 100, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 3; ++i) matrix(i + 1, i, 0, 100, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 4; ++i) matrix(i, i, 0, 100, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 3; ++i) matrix(i , i + 1, 0, 100, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 2; ++i) matrix(i, i + 2, 0, 100, 255);
        strip.show(); delay(_time);
        matrix(0, 3, 0, 100, 255);
        strip.show(); delay(_time);

        matrix(3, 0, 255, 0, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 2; ++i) matrix(i + 2, i , 255, 0, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 3; ++i) matrix(i + 1, i, 255, 0, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 4; ++i) matrix(i, i, 255, 0, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 3; ++i) matrix(i, i + 1, 255, 0, 255);
        strip.show(); delay(_time);
        for (int i = 0; i < 2; ++i) matrix(i , i + 2, 255, 0, 255);
        strip.show(); delay(_time);
        matrix(0, 3, 255, 0, 255);
        strip.show(); delay(_time);
      }
    }
    // Blinken --------------------------------------------------------
    if (Rand == 5) {
      for (int a = 0; a < 15; ++a) {
        for (int x = 0; x < 4; ++x) {
          for (int y = 0; y < 4; ++y) {
            matrix(x, y, 0, 100, 255);
          }
        }
        strip.show(); delay(100);
        for (int x = 0; x < 4; ++x) {
          for (int y = 0; y < 4; ++y) {
            matrix(x, y, 255, 0, 255);
          }
        }
        strip.show(); delay(100);
      }
    }
    Button5 = digitalRead(BUTTON_5);
    if (Button5 == 1) break;
  }
  for (int i = 0; i <= 15; ++i) strip.setPixelColor(i, 0, 0, 0); strip.show();

}

void flames(void) {
  bool Button5 = digitalRead(BUTTON_5);
  int upordown = 0;
  while (Button5 == 0) {
    
    int Rand = random(0 , 12);
    
    while(upordown == 0){
    for (int i = 0; i < 16; ++i) {
      strip.setPixelColor(i, 155 + loopnr, 50 + loopnr, 0);
    }
    loopnr++;
    delay(Rand);
    strip.show();
    if (loopnr >= 100) upordown = 1;
    }
    
    while(upordown == 1){
    for (int i = 0; i < 16; ++i) {
      strip.setPixelColor(i, 155 + loopnr, 50 + loopnr, 0);
    }
    loopnr--;
    delay(Rand);
    strip.show();
    if (loopnr <= 0) upordown = 0;
    }

    Button5 = digitalRead(BUTTON_5);
    delay(random(0, 120));
  }
  for (int i = 0; i <= 15; ++i) strip.setPixelColor(i, 0, 0, 0); // alle LEDs ausschalten
  strip.show();
}

//Functions_______________________________________________________________________________________

void matrix(int x, int y, int r, int g, int b) {
  if (x == 0) {
    switch (y) {
      case 0: strip.setPixelColor(0, r, g, b); break;
      case 1: strip.setPixelColor(1, r, g, b); break;
      case 2: strip.setPixelColor(2, r, g, b); break;
      case 3: strip.setPixelColor(3, r, g, b); break;
      default: break;
    }
  }
  if (x == 1) {
    switch (y) {
      case 0: strip.setPixelColor(7, r, g, b); break;
      case 1: strip.setPixelColor(6, r, g, b); break;
      case 2: strip.setPixelColor(5, r, g, b); break;
      case 3: strip.setPixelColor(4, r, g, b); break;
      default: break;
    }
  }
  if (x == 2) {
    switch (y) {
      case 0: strip.setPixelColor(8, r, g, b); break;
      case 1: strip.setPixelColor(9, r, g, b); break;
      case 2: strip.setPixelColor(10, r, g, b); break;
      case 3: strip.setPixelColor(11, r, g, b); break;
      default: break;
    }
  }
  if (x == 3) {
    switch (y) {
      case 0: strip.setPixelColor(15, r, g, b); break;
      case 1: strip.setPixelColor(14, r, g, b); break;
      case 2: strip.setPixelColor(13, r, g, b); break;
      case 3: strip.setPixelColor(12, r, g, b); break;
      default: break;
    }
  }
}
