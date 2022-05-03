#include <Adafruit_NeoPixel.h>   // 네오픽셀 라이브러리를 불러옵니다.
#ifdef __AVR__
  #include <avr/power.h>
#endif
/*
 * 2019.5.30 Computer Graphics Term Project
 * 20174069 현지원
*/

/* 
 * LEDNUM : 연결된 네오픽셀의 숫자
 * PIN : 아두이노 디지털 핀
 * BRIGHTNESS : 네오픽셀 밝기(0~255)
*/

/* 
 * pixels.setBrightness() : 네오픽셀 밝기 조절
 * pixels.setPixelColor(LED 위치, pixels.Color(적색, 녹색, 청색, 백색)) : 해당 위치 픽셀 색상 설정
 * pixels.show() : 설정된 값 출력
 * pixels.clear() : 색상 초기화 함수, show()함수를 실행 해야 작동 
*/

/********** SOUND **********/
int soundSensor = A0;     // 사운드 센서 핀
int sensorValue;
int hold1 = 150; // 소리 크기 기준
int hold2 = 200; // 소리 크기 기준
int hold3 = 250; // 소리 크기 기준
int hold4 = 300; // 소리 크기 기준
int hold5 = 350; // 소리 크기 기준

/********** Neo Pixel **********/
#define PIN 6                  
#define LEDNUM 20                 
#define BRIGHTNESS 50             

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(LEDNUM, PIN, NEO_GRBW + NEO_KHZ800);  

void setup() {
  Serial.begin(9600); //시리얼 모니터 출력
  //pinMode(soundSensor); //사운드 센서 입력으로 설정
  
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code
  pixels.begin(); // This initializes the NeoPixel library.
  
  pixels.setBrightness(BRIGHTNESS);  
}

void loop() {
  sensorValue = analogRead(soundSensor);
  Serial.println(sensorValue);
  delay(100);
  
  // 이 안에 입력한 내용들이 반복 실행됩니다
  pixels.begin();                           // 네오픽셀 제어시작
  pixels.show();                            // 네오픽셀 초기화
  pixels.setPixelColor(0, 255, 0, 255, 0);     // (A,R,G,B,W) A번째 LED를 RGBW (0~255) 만큼의 밝기로 켭니다.
}
