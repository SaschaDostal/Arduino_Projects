// Use "Ambibox" on PC (Windows) with Adalight-Mode
// Following Method uses FastLED library

void ambilight66(void) {

  #define NUM_LEDS 132
  #define serialRate 115200
  static const uint8_t prefix[] = {'A', 'd', 'a'};

  CRGB leds[NUM_LEDS];

  FastLED.addLeds<WS2811, PIXEL_PIN, RGB>(leds, NUM_LEDS);
  Serial.begin(serialRate);
  Serial.print("Ada\n");

  while (true) {
    start:
    if(testB()){
      clearStrip();
      return;
    }
    for (int i = 0; i < sizeof(prefix); ++i) {
      while (!Serial.available());
      if (prefix[i] != Serial.read())
        goto start;
    }
    while (Serial.available() < 3);
    int highByte = Serial.read();
    int lowByte  = Serial.read();
    int checksum = Serial.read();
    if (checksum != (highByte ^ lowByte ^ 0x55)) {
      goto start;
    }

    uint16_t ledCount = ((highByte & 0x00FF) << 8 | (lowByte & 0x00FF) ) + 1;
    if (ledCount > NUM_LEDS) {
      ledCount = NUM_LEDS;
    }

    for (int i = 0; i < NUM_LEDS/2; i++) {
      while (Serial.available() < 3);
      leds[i].r = Serial.read();
      leds[131-i].r = leds[i].r;

      leds[i].g = Serial.read();
      leds[131-i].g = leds[i].g;

      leds[i].b = Serial.read();
      leds[131-i].b = leds[i].b;
    }
    FastLED.show();
  }
}

void ambilight3(void) {

  #define NUM_LEDS 132
  #define serialRate 115200
  static const uint8_t prefix[] = {'A', 'd', 'a'};

  CRGB leds[NUM_LEDS];

  FastLED.addLeds<WS2811, PIXEL_PIN, RGB>(leds, NUM_LEDS);
  Serial.begin(serialRate);
  Serial.print("Ada\n");

  while (true) {
    start:
    if(testB()){
      clearStrip();
      return;
    }
    for (int i = 0; i < sizeof(prefix); ++i) {
      while (!Serial.available());
      if (prefix[i] != Serial.read())
        goto start;
    }
    while (Serial.available() < 3);
    int highByte = Serial.read();
    int lowByte  = Serial.read();
    int checksum = Serial.read();
    if (checksum != (highByte ^ lowByte ^ 0x55)) {
      goto start;
    }

    uint16_t ledCount = ((highByte & 0x00FF) << 8 | (lowByte & 0x00FF) ) + 1;
    if (ledCount > NUM_LEDS) {
      ledCount = NUM_LEDS;
    }

    for (int i = 0; i < NUM_LEDS/2; i+=22) {
      while (Serial.available() < 3);

      leds[i].r = Serial.read();
      leds[131-i].r = leds[i].r;
      leds[i].g = Serial.read();
      leds[131-i].g = leds[i].g;
      leds[i].b = Serial.read();
      leds[131-i].b = leds[i].b;
      
      for(int j = 1; j < 22; j++){
        leds[i+j].r = leds[i].r;
        leds[131-i-j].r = leds[i].r;
        leds[i+j].g = leds[i].g;
        leds[131-i-j].g = leds[i].g;
        leds[i+j].b = leds[i].b;
        leds[131-i-j].b = leds[i].b;
      }

    }
    FastLED.show();
  }
}
