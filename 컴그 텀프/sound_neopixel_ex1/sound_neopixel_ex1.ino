 #include <Adafruit_NeoPixel.h> //라이브러리와 파일은 첨부하였습니다.
#ifdef __AVR__
#include <avr/power.h>
#endif

int DO = 7;
int DA = A0;
int sensorvalue = 0;

#define PIN            7

#define NUMPIXELS      20
#define BRIGHTNESS 10  

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRBW + NEO_KHZ800);

void setup() {
  Serial.begin(9600); //시리얼 모니터 출력
    // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
    // End of trinket special code
    pixels.begin(); // This initializes the NeoPixel library.
    
    pixels.setBrightness(BRIGHTNESS);
}

void loop() {  
 sensorvalue = analogRead(DA);
 Serial.println(sensorvalue);

 int sound = map(abs(sensorvalue),0,30,0,30);

 //위는 인식된 음량의 크기를 구하는 부분입니다. 소리가 들릴 때 센서의 값이 약 300의 기준으로 요동치게 되는데. 300을 기준으로 벗어난 값을 음량으로 정하였습니다.
 int g = 0;
 int b = 0;
 int r = 0;
 int rscore = random(3);
 switch(rscore){
   case 0: r = random(100); g = random (100-r); b = 100-r-g ; break;
   case 1: g = random(100); b = random (100-g); r = 100-g-b ; break;
   case 2: b = random(100); r = random (100-b); g = 100-b-r ; break;
 }

 //위는 음량에 맞게 총 밝기의 비를 100단위로 나누어서 각 rgb코드에 분배하는 명령입니다. 초반 어느 색을 특징 색으로 하고, 특징 색을 우선으로 밝기를 분배하는 방식입니다.
 
 r = (float) r*(sound);
 g = (float) g*(sound);
 b = (float) b*(sound);

 // 이 안에 입력한 내용들이 반복 실행됩니다
 pixels.begin();                           // 네오픽셀 제어시작  
 //위는 분배된 밝기의 비율을 소리의 크기로, 
 for(int i = 0; i < NUMPIXELS; i++) {
     if(analogRead(DA) >= 25) {
          colorWipe(pixels.Color(255, 0, 0), 50); // Red
    } 
   
    if(analogRead(DA) >= 19) {
          colorWipe(pixels.Color(0, 255, 0), 50); // Green
    }
    
    if(analogRead(DA) >= 15) {
          colorWipe(pixels.Color(0, 0, 255), 50); // Blue
    }
    if(analogRead(DA) >= 10) {
          colorWipe(pixels.Color(0, 0, 0, 255), 50); // White
    }
    //pixels.show();                            // 네오픽셀 초기화
 }
 delay(500); 

 //딜레이0.05초.
}
