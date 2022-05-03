#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

int soundSensor = A0;     // 사운드 센서 핀
int SensorValue = 0; // A0 핀으로 들어오는 전압의 크기(소리의 세기)

#define PIN 6

#define NUMPIXELS      20
#define TIME 80
#define BRIGHTNESS 10 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN,  NEO_GRBW + NEO_KHZ800);

void setup() {
  Serial.begin(9600); // 시리얼모니터 출력
  pinMode(soundSensor, INPUT);  // 사운드 센서 입력으로 설정
  strip.begin();
  strip.setBrightness(BRIGHTNESS);
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  SensorValue = analogRead(soundSensor);
  Serial.println(SensorValue);
  rainbow(TIME);
}


void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
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
