#define SIZE 5

int soundSensor = A0;     // 사운드 센서 핀
int hold1 = 150; // 소리 크기 기준
int hold2 = 200; // 소리 크기 기준
int hold3 = 250; // 소리 크기 기준
int hold4 = 300; // 소리 크기 기준
int hold5 = 350; // 소리 크기 기준

int count = 0;      // 박수를 몇 번 쳤는지 카운트

void setup() {               
  Serial.begin(9600); // 시리얼모니터 출력
  pinMode(soundSensor, INPUT);  // 사운드 센서 입력으로 설정  
  for(int i=0; i<SIZE; i++)      // LED 핀 출력으로 설정
    pinMode(led[i], OUTPUT);    
}

void loop() {     
  if( analogRead(soundSensor) >= hold1){    // 감지된 소리의 크기가 10 이상일 때
        digitalWrite(led[0], HIGH);   
        delay(100);
        digitalWrite(led[0], LOW);   
  }
  
  if(analogRead(soundSensor) >= hold2) {
        digitalWrite(led[0], HIGH);
        digitalWrite(led[1], HIGH);    
        delay(100);
        digitalWrite(led[0], LOW); 
        digitalWrite(led[1], LOW); 
  } 

  if(analogRead(soundSensor) >= hold3) {
        digitalWrite(led[0], HIGH);
        digitalWrite(led[1], HIGH);    
        digitalWrite(led[2], HIGH);   
        delay(100);
        digitalWrite(led[0], LOW); 
        digitalWrite(led[1], LOW); 
        digitalWrite(led[2], LOW); 
  } 

  if(analogRead(soundSensor) >= hold4) {
        digitalWrite(led[0], HIGH);
        digitalWrite(led[1], HIGH);    
        digitalWrite(led[2], HIGH);
        digitalWrite(led[3], HIGH);   
        delay(100);
        digitalWrite(led[0], LOW); 
        digitalWrite(led[1], LOW); 
        digitalWrite(led[2], LOW); 
        digitalWrite(led[3], LOW); 
  } 
  
  if(analogRead(soundSensor) >= hold5) {
        digitalWrite(led[0], HIGH);
        digitalWrite(led[1], HIGH);    
        digitalWrite(led[2], HIGH);
        digitalWrite(led[3], HIGH);
        digitalWrite(led[4], HIGH);   
        delay(100);
        digitalWrite(led[0], LOW);
        digitalWrite(led[1], LOW);    
        digitalWrite(led[2], LOW);
        digitalWrite(led[3], LOW);
        digitalWrite(led[4], LOW);
  }
  else {
        for(int i = 0; i < SIZE; i++) {
          digitalWrite(led[i], LOW); 
        }       
        delay(100);
  }
}
