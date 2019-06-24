#include <Adafruit_NeoPixel.h>

#define BUTTON_PIN_1   5    // Digital IO pin connected to the button.  This will be
                          // driven with a pull-up resistor so the switch should
                          // pull the pin to ground momentarily.  On a high -> low
                          // transition the button press logic will execute.5

#define PIXEL_PIN    3    // Digital IO pin connected to the NeoPixels.

#define PIXEL_COUNT 64

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

bool oldState1 = HIGH;
bool newState1 = HIGH;
int colorIndicator = 0;

void setup() {
  pinMode(BUTTON_PIN_1, INPUT_PULLUP);

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  colorType(0);
}

void loop() {
//  // Get current button state.
  newState1 = digitalRead(BUTTON_PIN_1);

  // Check if state changed from high to low (button press).
  if (newState1 == LOW && oldState1 == HIGH) {
    // Short delay to debounce button.
    delay(15);
    // Check if button is still low after debounce.
    newState1 = digitalRead(BUTTON_PIN_1);
    if (newState1 == LOW) {
      colorIndicator++;
      if (colorIndicator > 4)
        colorIndicator=0;
      oldState1 = newState1;
      colorType(colorIndicator);
    }
  }

  // Set the last button state to the old state.
  oldState1 = newState1;
}

void colorType(int i) {
  switch(i){
    case 0: 
      solid(0, 30); 
      break;
    case 1:
      solid(1,30);
      break;
    case 2: 
      solid(2,30);
      break;
    case 3: 
      rainbow(30);
      break;
    case 4: 
      rainbowCycle(30);
      break;
  }
}


// Fill the dots one after the other with a color
void solid(uint8_t color, uint8_t wait) {
  if(color==0) {
    for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, strip.Color(10, 190, 10));
      delay(wait);
      strip.show();
    }
  }
  if(color==1) {
    for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, strip.Color(190, 30, 0));
      delay(wait);
      strip.show();
    }
  }
  if(color==2) {
    for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, strip.Color(10,50,190));
      delay(wait);
      strip.show();
    }
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;
  while(1){
  for(j=0; j<256; j++) {
    newState1 = digitalRead(BUTTON_PIN_1);

    if (newState1 == LOW && oldState1 == HIGH) {
      // Short delay to debounce button.
      delay(15);
      // Check if button is still low after debounce.
      newState1 = digitalRead(BUTTON_PIN_1);
      if (newState1 == LOW) {
        colorIndicator++;
        if (colorIndicator > 4)
          colorIndicator=0;
        oldState1 = newState1;
        colorType(colorIndicator);
      }
      return;
    }
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
    oldState1 = newState1;
  }
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;
  while(1){
  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    newState1 = digitalRead(BUTTON_PIN_1);

    if (newState1 == LOW && oldState1 == HIGH) {
      // Short delay to debounce button.
      delay(15);
      // Check if button is still low after debounce.
      newState1 = digitalRead(BUTTON_PIN_1);
      if (newState1 == LOW) {
        colorIndicator++;
        if (colorIndicator > 4)
          colorIndicator=0;
        oldState1 = newState1;
        colorType(colorIndicator);
      }
      return;
    }
    
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
    oldState1 = newState1;
  }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
