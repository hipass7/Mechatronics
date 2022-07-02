// 한 바퀴 돌리면 한 바퀴 돎

#define ts1 9
#define ts2 10
 
 int clk = 5;  // Pin 9 to clk on encoder // clk 핀은 5
 int dt = 6;  // Pin 8 to dt on encoder // dt 핀은 6
 int RotPosition = 0; 
 int rotation;  
 int value;
 int LED = 8; // LED 핀은 8
 int SW=7; // SW 핀은 7
 int cnt=0;
 
 void setup() { 
   Serial.begin (9600);
   pinMode (ts1, OUTPUT); // 출력 트랜지스터1 9
   pinMode (ts2, OUTPUT); // 출력 트랜지스터2 10
   pinMode (clk,INPUT); // 입력 clk 5
   pinMode (dt,INPUT); // 입력 dt 6
   rotation = digitalRead(clk); // KY-040을 통한 clk 수를 rotation에 입력
   pinMode (LED, OUTPUT); // 출력 LED 8
   digitalWrite(LED,HIGH); // LED에 불 들어오게 하기
   pinMode (SW,INPUT); // 입력 스위치 7
   pinMode(2,INPUT); // 입력 2
 } 
 
 int val1=digitalRead(2); // 2의 입력을 val1에 저장

 
 void loop() { 
  while(1){
   value = digitalRead(clk); // 클릭 수 value에 저장

   // #1
     if (value != rotation){ // we use the dt pin to find out which way we turning. // 처음 값과 현재 값이 다를 때
      if (digitalRead(dt) != value) {  // Clockwise 시계 방향
        RotPosition ++;
        Serial.println ("clockwise"); // 시계방향이라고 프린트
      } 
      else { //cnterclockwise 반시계 방향
       Serial.println("cnterclockwise"); // 반시계방향이라고 프린트
       RotPosition--;
      }
      Serial.print("Encoder RotPosition: ");
      Serial.println(RotPosition);
    }
   rotation = value;

  // #2
   if (1){ // 입력 스위치가 비활성화일 때
      int Motor_clk = RotPosition * 3;
//      digitalWrite(LED, HIGH);
      delay(10);
      if (Motor_clk>0){ // RotPosition이 1 이상일 때
        while(1){
          int MS=map(0,0,1023,255,0);
          digitalWrite(ts1, HIGH);
          int val2=digitalRead(2);
          if (val2!=val1){
            cnt++;
            Serial.println(cnt);
            val1=val2;
          }
          if (cnt==Motor_clk){
            break;
          }
        }
      }
      delay(10);
      if (Motor_clk<0){ 
        while(1){
          int MS=map(0,0,1023,255,0);
          digitalWrite(ts1, HIGH);
          digitalWrite(ts2, HIGH);
          int val2=digitalRead(2);
          if (val2!=val1){
            cnt--;
            Serial.println(cnt);
            val1=val2;
          }
          if (cnt==Motor_clk){
            break;
            }
          }
        }
      digitalWrite (ts1, LOW);
      digitalWrite (ts2, LOW);
      break;
   }
  } // while문의 끝

  
   RotPosition = 0;
   cnt=0;
   int val1=digitalRead(2);
   
 } 
 
