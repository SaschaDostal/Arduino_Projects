#include <Adafruit_NeoPixel.h>
void lines(int number, int r, int b, int g);
void linesl(int number, int r, int g, int b);
void linesr(int number, int r, int g, int b);
void lineso(int number, int r, int g, int b);
void linesu(int number, int r, int g, int b);
void bluerain(void);
void rainbow(void);
void flames(void);
void color(void);
void partymode(void);
#define BUTTON_1   12     //Button-Pins
#define BUTTON_2   11
#define BUTTON_3   10
#define BUTTON_4   9
#define BUTTON_5   8

#define PIXEL_PIN    6    //Neopixel-Pin
#define PIXEL_COUNT 131

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
  color();
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
    lines(select, 0, 0, 0);
    --select;
  }
  if (Button2 == 1) {
    lines(select, 0, 0, 0);
    ++select;
  }
  if (select > 31) select = 31;
  if (select < 0) select = 0;
  lines(select, 255, 255, 255);
  strip.show();

  if (Button4 == 1) {
    switch (select) {
      case 0: flames(); loopnr = 0; break;
      case 1: rainbow(); loopnr = 0; break;
      case 2: partymode(); loopnr = 0; break;
      case 3: color(); loopnr = 0; break;
      case 31: bluerain(); loopnr = 0; break;
      default: break;
    }
  }
}
//Programme_____________________________________________________________________________________

void rainbow(void) {
  bool Button5 = digitalRead(BUTTON_5);
  while (Button5 == 0) {
    lines(32 - loopnr, 255, 0, 0);  // rot
    lines(33 - loopnr, 0, 0, 0);
    lines(28 - loopnr, 255, 255, 0); // gelb
    lines(29 - loopnr, 0, 0, 0);
    lines(24 - loopnr, 0, 255, 0);  // grün
    lines(25 - loopnr, 0, 0, 0);
    lines(20 - loopnr, 0, 255, 255); // türkis
    lines(21 - loopnr, 0, 0, 0);
    lines(16 - loopnr, 0, 0, 255);  // blau
    lines(17 - loopnr, 0, 0, 0);
    lines(12 - loopnr, 255, 0, 255); // violett
    lines(13 - loopnr, 0, 0, 0);
    lines(8 - loopnr, 255, 255, 255); // weiss
    lines(9 - loopnr, 0, 0, 0);
    lines(4 - loopnr, 160, 255, 40); // blass grün
    lines(5 - loopnr, 0, 0, 0);
    strip.show();
    ++loopnr;
    if (loopnr > 31) loopnr = 0;
    Button5 = digitalRead(BUTTON_5);
    delay(40);
  }
  for (int i = 0; i <= 32; ++i) lines(i, 0, 0, 0); // alle LEDs ausschalten
  strip.show();
}

void flames(void) {
  bool Button5 = digitalRead(BUTTON_5);
  int color = 1;
  while (Button5 == 0) {
    bool Button3 = digitalRead(BUTTON_3);
    if (Button3 == 1) {
      ++color;
      delay(200);
    }
    if (color == 3) color = 0;
    if (color == 0) {
      for (int i = 0; i < 16; ++i) {
        lineso(i + loopnr, 0, pow(i, 2) / 250 * 50, i / 16.0 * 255);
        linesu(i + loopnr, i / 16.0 * 255, 0, pow(i, 2) / 250 * 50);
      }
      for (int i = 16; i < 32; ++i) {
        lineso(i + loopnr, 0, 50 - (pow((i - 16), 2) / 250 * 50), 255 - ((i - 16) / 16.0 * 255));
        linesu(i + loopnr, 255 - ((i - 16) / 16.0 * 255), 0 , 50 - (pow((i - 16), 2) / 250 * 50));
      }
    }
    if (color == 1) {
      for (int i = 0; i < 16; ++i) {
        lines(i + loopnr, i / 16.0 * 255, pow(i, 2) / 250 * 50, 0);
      }
      for (int i = 16; i < 32; ++i) {
        lines(i + loopnr, 255 - ((i - 16) / 16.0 * 255), 50 - (pow((i - 16), 2) / 250 * 50), 0);
      }
    }
    if (color == 2) {
      for (int i = 0; i < 16; ++i) {
        lines(i + loopnr, 0, pow(i, 2) / 250 * 50, i / 16.0 * 255);
      }
      for (int i = 16; i < 32; ++i) {
        lines(i + loopnr, 0, 50 - (pow((i - 16), 2) / 250 * 50), 255 - ((i - 16) / 16.0 * 255));
      }
    }
    strip.show();
    ++loopnr;
    if (loopnr > 31) loopnr = 0;
    Button5 = digitalRead(BUTTON_5);
    delay(50);
  }
  for (int i = 0; i <= 32; ++i) lines(i, 0, 0, 0); // alle LEDs ausschalten
  strip.show();
}

void partymode(void) {
  bool Button5 = digitalRead(BUTTON_5);
  while (Button5 == 0) {
    if (loopnr == 0) {
      for (int i = 0; i <= 32; ++i) lines(i, 255, 0, 0);
      strip.show();
    }
    if (loopnr == 1) {
      for (int i = 0; i <= 32; ++i) lines(i, 0, 255, 255);
      strip.show();
    }
    if (loopnr == 2) {
      for (int i = 0; i <= 32; ++i) lines(i, 0, 255, 0);
      strip.show();
    }
    if (loopnr == 3) {
      for (int i = 0; i <= 32; ++i) lines(i, 255, 0, 255);
      strip.show();
    }
    if (loopnr == 4) {
      for (int i = 0; i <= 32; ++i) lines(i, 0, 0, 255);
      strip.show();
    }
    if (loopnr == 5) {
      for (int i = 0; i <= 32; ++i) lines(i, 255, 0, 255);
      strip.show();
    }
    delay(50);
    for (int i = 0; i <= 32; ++i) lines(i, 0, 0, 0);
    strip.show();
    delay(50);
    ++loopnr;
    if (loopnr > 5) loopnr = 0;
    Button5 = digitalRead(BUTTON_5);
  }
}

void color(void) {
  bool Button5 = digitalRead(BUTTON_5);
  // start
  bool arr[32] = {false} ;
  bool test = false;
  float numb = 1.0f;
  while(!test){
    if( numb < 33.0f ) numb+= 0.2f;
    int number = random(0, (int) numb);
    if(!arr[number]){
      arr[number] = true;
      lineso(number, 255, 0, 255 );
      linesu(number, 0, 100, 255 );
      strip.show();
      delay(20);
    } else {
      continue;
    }
    test = true;
    for(int i = 0; i < 32; i++){
      if(!arr[i]){
        test = false;
        break;
      }
    }
  }
  
  while (Button5 == 0) {

      // smooth change
      for (int i = 0; i <= 64; ++i) {
        strip.setPixelColor(i, 255, 0, 255 );
        strip.setPixelColor(i + 68, 0, 100, 255 );
        strip.show();
        delay(10);
        Button5 = digitalRead(BUTTON_5);
        if (Button5 == 1) break;
      }
      if (Button5 == 1) break;
      delay(1000);
      Button5 = digitalRead(BUTTON_5);

      for (int i = 64; i >= 0; --i) {
        strip.setPixelColor(i, 0, 100, 255 );
        strip.setPixelColor(i + 68, 255, 0, 255 );
        strip.show();
        delay(10);
        Button5 = digitalRead(BUTTON_5);
        if (Button5 == 1) break;
      }
      if (Button5 == 1) break;
      delay(1000);
      Button5 = digitalRead(BUTTON_5);
      
      //small block change
      int x = 0;
      while(x < 32){
        for (int i = 32; i > x; --i) {
          lineso(i, 0, 100, 255 );
          linesu(i, 255, 0, 255 );
          if( i + 4 < 32){
            lineso(i + 4, 255, 0, 255 );
            linesu(i + 4, 0, 100, 255 );
          }
          strip.show();
          delay(20);
        }
        Button5 = digitalRead(BUTTON_5);
        if (Button5 == 1) break;
        delay(500);
        x += 4;
      }

      x = 32;
      while(x > 0){
        for (int i = 0; i < x; ++i) {
          lineso(i, 255, 0, 255 );
          linesu(i, 0, 100, 255 );
          if( i - 4 >= 0){
            lineso(i - 4, 0, 100, 255 );
            linesu(i - 4, 255, 0, 255 );
          }
          strip.show();
          delay(20);
        }
        Button5 = digitalRead(BUTTON_5);
        if (Button5 == 1) break;
        delay(500);
        x -= 4;
      }
      
      // large block change
      x = 64;
      while(x > 0){
        for (int i = 0; i <= x; ++i) {
        
          strip.setPixelColor(i, 255, 0, 255 );
          strip.setPixelColor(131 - i, 0, 100, 255 );

          if( i - 8 > 0){
            strip.setPixelColor(i - 8, 0, 100, 255 );
            strip.setPixelColor(131 - i + 8, 255, 0, 255 );
          }
          strip.show();
          delay(10);
        }
        Button5 = digitalRead(BUTTON_5);
        if (Button5 == 1) break;
        delay(500);
        x -= 8;
      }

      while(x < 64){
        for (int i = 64; i >= x; --i) {
        
          strip.setPixelColor(i, 0, 100, 255 );
          strip.setPixelColor(131 - i, 255, 0, 255 );

          if( i + 8 <= 64){
            strip.setPixelColor(i + 8, 255, 0, 255 );
            strip.setPixelColor(131 - i - 8, 0, 100, 255 );
          }
          strip.show();
          delay(10);
        }
        delay(500);
        x += 8;
      }
      if (Button5 == 1) break;
      delay(1000);
      Button5 = digitalRead(BUTTON_5);

      //small block change
      x = 32;
      while(x > 0){
        for (int i = 0; i < x; ++i) {
          lineso(i, 0, 100, 255 );
          linesu(i, 255, 0, 255 );
          if( i - 4 > 0){
            lineso(i - 4, 255, 0, 255 );
            linesu(i - 4, 0, 100, 255 );
          }
          strip.show();
          delay(20);
        }
        Button5 = digitalRead(BUTTON_5);
        if (Button5 == 1) break;
        delay(500);
        x -= 4;
      }

      x = 0;
      while(x < 32){
        for (int i = 32; i > x; --i) {
          lineso(i, 255, 0, 255 );
          linesu(i, 0, 100, 255 );
          if( i + 4 < 32){
            lineso(i + 4, 0, 100, 255 );
            linesu(i + 4, 255, 0, 255 );
          }
          strip.show();
          delay(20);
        }
        Button5 = digitalRead(BUTTON_5);
        if (Button5 == 1) break;
        delay(500);
        x += 4;
      }

      
  }

  
  for (int i = 0; i <= 32; ++i) lines(i, 0, 0, 0);
  strip.show();
}




void bluerain(void) {
  bool Button5 = digitalRead(BUTTON_5);
  for (int i = 0; i <= 32; ++i) lines(i, 0, 0, 0); // alle LEDs ausschalten
  while (Button5 == 0) {
    int chance = random(0, 6);
    if (chance == 0 || chance == 1) {
      for (int i = 0; i <= 31; ++i) {
        linesr(31 - i, 0, 100, 255);
        linesr(32 - i, 0, 0, 0);
        strip.show();
        if (i == 31) linesr(0, 0, 0, 0);
        Button5 = digitalRead(BUTTON_5);
        if (Button5 == 1) break;
        delay(random(1, 15));
      }
      delay(random(10, 50));
    }
    if (chance == 2 || chance == 3) {
      for (int i = 0; i <= 31; ++i) {
        linesl(31 - i, 0, 100, 255);
        linesl(32 - i, 0, 0, 0);
        strip.show();
        if (i == 31) linesl(0, 0, 0, 0);
        Button5 = digitalRead(BUTTON_5);
        if (Button5 == 1) break;
        delay(random(1, 15));
      }
      delay(random(10, 50));
    }
    if (chance == 4) {
      for (int i = 0; i <= 31; ++i) {
        lines(31 - i, 0, 100, 255);
        lines(32 - i, 0, 0, 0);
        strip.show();
        if (i == 31) lines(0, 0, 0, 0);
        Button5 = digitalRead(BUTTON_5);
        if (Button5 == 1) break;
        delay(random(1, 15));
      }
      delay(random(10, 50));
    }
    Button5 = digitalRead(BUTTON_5);
  }
  for (int i = 0; i <= 32; ++i) lines(i, 0, 0, 0); // alle LEDs ausschalten
  strip.show();
}
//Methodes_______________________________________________________________________________________
void lines(int number, int r, int g, int b) {
  while (number > 32) number = number - 32;
  while (number < 0) number = number + 32;
  line1 = number;
  line2 = 63 - number;
  line3 = 67 + number;
  line4 = 130 - number;
  strip.setPixelColor(line1, r, g, b);
  strip.setPixelColor(line2, r, g, b);
  strip.setPixelColor(line3, r, g, b);
  strip.setPixelColor(line4, r, g, b);
}

void linesl(int number, int r, int g, int b) {
  while (number > 32) number = number - 32;
  while (number < 0) number = number + 32;
  line1 = number;
  line4 = 130 - number;
  strip.setPixelColor(line1, r, g, b);
  strip.setPixelColor(line4, r, g, b);
}

void linesr(int number, int r, int g, int b) {
  while (number > 32) number = number - 32;
  while (number < 0) number = number + 32;
  line2 = 63 - number;
  line3 = 67 + number;
  strip.setPixelColor(line2, r, g, b);
  strip.setPixelColor(line3, r, g, b);
}

void lineso(int number, int r, int g, int b) {
  while (number > 32) number = number - 32;
  while (number < 0) number = number + 32;
  line3 = 67 + number;
  line4 = 130 - number;
  strip.setPixelColor(line3, r, g, b);
  strip.setPixelColor(line4, r, g, b);
}

void linesu(int number, int r, int g, int b) {
  while (number > 32) number = number - 32;
  while (number < 0) number = number + 32;
  line1 = number;
  line2 = 63 - number;
  strip.setPixelColor(line1, r, g, b);
  strip.setPixelColor(line2, r, g, b);
}
