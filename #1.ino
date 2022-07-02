
#define ts1 9
#define ts2 10
#define Switch 7

int cnt=0;
int buttonS;
unsigned long time1 = 0;
unsigned long timeLimit = 0;
int clk = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(Switch ,INPUT); // 스위치 입력 7
  pinMode (ts1, OUTPUT); // 트랜지스터1 출력 9
  pinMode (ts2, OUTPUT); // 트랜지스터2 출력 10
  Serial.begin(9600);
  pinMode(2,INPUT); // 2번 핀 입력
}

int led1=digitalRead(2); // 2번 핀 입력값 led1에 저장

void loop() {
  buttonS = digitalRead(Switch); // 스위치가 0인지 1인지 판단해서 buttonS에 넣기
  delay(200);
  
  if (buttonS == LOW){ // 스위치가 눌린다면
    Serial.println("Button Pressed"); // 버튼이 눌렸다는 내용을 프린트
//    Serial.println(digitalRead(2));
    if (clk == 0) {
    time1 = millis(); // time을 ms 단위로 기록
    timeLimit = time1 + 1000;
    clk = 1;
    }

    else if (clk == 1 && millis() < timeLimit){
      delay(1000);
      Serial.println("Button Pressed twice"); // 버튼이 두번 눌렸다는 내용을 프린트
      while(1){
          digitalWrite(ts1, HIGH); // 트랜지스터1을 활성화
          int led2=digitalRead(2); // 2번 핀 입력을 led2
          if (led2!=led1){ // 2번 핀 입력이 처음과 달라졌으면
            cnt++; // 카운트
//            Serial.println(cnt); // 횟수 프린트
            led1=led2;
          }
          if (cnt==28){ // 18번 반복되면 중지
            break;
          }
        }
      digitalWrite (ts1, LOW);
      digitalWrite (ts2, LOW);
      cnt=0;
      int led1=digitalRead(2);
      time1 = 0;
      timeLimit = 0;
      clk = 0;      
     }
}
  if (clk == 1 && timeLimit != 0 && millis() > timeLimit){ // 시간제한 넘어갔을 때
     Serial.println("Button Pressed Once"); // 버튼이 한번만 눌렸다
     while(1){
          digitalWrite(ts1, HIGH);
          digitalWrite(ts2, HIGH);
          int led2=digitalRead(2);
//          Serial.println(led2);
//          Serial.println(led1);
          if (led2!=led1){
            cnt--;
//            Serial.println(cnt);
            led1=led2;
          }
          if (cnt==-28){ // 반대 방향으로 18번
            break;
            }
          }
     
     digitalWrite (ts1, LOW);
     digitalWrite (ts2, LOW);
     cnt=0;
     int led1=digitalRead(2);
     time1 = 0;
     timeLimit = 0;
     clk = 0;      
  }
}
