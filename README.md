# Mechatronics
## 2022-1 Mechatronics Motor Operating Project

### Ⅰ. 프로젝트 목표

#### 1) LED 와 포토 트랜지스터를 이용한 로터리 엔코더의 원리를 이해하고, 이를 구현해본다.
- 프로그래밍 언어를 이용하여 아두이노 프로그래밍을 진행하고 직접 부품들을 이용하여 회로를 구성함으로써, 프로그래밍 능력과 회로에 대한 이해도를 높여 메카트로닉스 과목의 궁극적인 목표를 달성한다.

#### 2) Actuator(모터)와 센서(엔코더)를 마이크로 프로세서에 인터페이싱하여 프로그래밍한다.
- 엔코더를 사용하여 스위치를 눌렀을 때 3.5바퀴 회전시킬 수 있다.
- 스위치를 1000 ms 안에 2번 눌렀을 때, 반대 방향으로 3.5바퀴 회전시킬 수 있다.
- 아두이노 로터리형 엔코더 모듈(KY-040)이 회전한 만큼 모터를 회전시킬 수 있다.

### Ⅱ. 부품

![1](/image/1.png) <br />
< 그림 1 – 제공받은 부품들 >


##### - Relay (IRE-2C-D05S)
  릴레이는 쉽게 말해 ON, OFF가 있는 일종의 스위치 이다. 우리가 일반적으로 접하는 스위치는 수동으로 ON, OFF 해주지만, 릴레이는 '자동'으로 ON, OFF 할 수 있게끔 해주는 전자부품 이다. 이는 별도로 분리되어 흐르는 전기를 스위칭 할 수 있는 신호 또는 펄스를 만든다.

  릴레이는 내부에 전자석(코일)을 포함하고 있다. 이 전자석에 전류가 통하면 자석이 된다. 따라서 전원을 공급하면 릴레이 내부에 전자석이 자성을 띄어 옆에 있던 철편을 끌어당겨 스위치가 ON이 된다. 이러한 원리로, 현재 프로젝트에서 릴레이는 전류의 방향을 바꿔 모터의 회전방향을 바꾸는 역할을 한다.

##### - NPN Transistor(BC547)
  트랜지스터는 저마늄, 규소 따위의 반도체를 이용하여 전자 신호 및 전력을 증폭하거나 스위칭하는 데 사용되는 반도체소자이다. 현재 프로젝트에서 트랜지스터는 전류의 방향을 설정하는. 스위칭 용도로 사용되었다.

##### - Photo Sensor pair(EL-7L, ST-7L)
  포토센서는 빛을 매개로하여 물체를 검출하는 기기이다. 센서의 투광부에서 나온 적외선과 수광부에서 감지한 빛의 변화량이 센서의 동작을 결정한다. 현재 프로젝트에서는 회전을 감지는 역할로 사용된다.

  왼쪽의 사진은 주변을 어둡게 하여 휴대폰 카메라로 촬영한 모습이다. 분홍색 빛이 들어옴을 확인할 수 있다.
  
  ![1](/image/2.png)<br />
  < 그림 2 - Pair >

##### - Logic IC(74HC14, 74HC86)
  논리 IC는 디지털 출력 신호를 생성하기 위해 하나 이상의 디지털 입력 신호(1 과 0 또는 H와 L로 표시)에서 수행 되는 기본 논리 연산을 구현하는 반도체 장치이다. 현재 프로젝트에서 사용된 74HC86은 ‘Exclusive OR’의 의미를 지닌다.

##### - 아두이노 로터리형 엔코더 모듈(KY-040)
  일반적으로 엔코더는 특정 형식의 데이터를 다른 형식으로 변환하는 장치 또는 프로세스이다. 위치 감지에 있어 엔코더는 기계적인 움직임을 감지하여 아날로그 및 디지털 프로그래밍 출력 신호로 변환할 수 있는 장치이다. 로터리 엔코더는 회전각 변위를 측정하는 엔코더이다.
  
##### - 아두이노 우노
  아두이노는 오픈소스(Open Source)를 기반으로한 단일보드인 마이크로 컨트롤러(Micro Controller)로 완성된 보드와 관련 개발 도구 및 환경을 말한다. 아두이노 우노는 3번째 버전인 R3 보드가 가장 많이 사용되는 보드로써 표준과 같이 사용된다. 아두이노 우노는 총 44개의 핀과 단자들로 구성되어 있고, 각 핀과 단자들은 아두이노와 다른 보드 또는 센서들의 제어에 이용된다.


### Ⅲ. 회로

![1](/image/3.png)<br />
< 그림 3 – 회로 도면 >


#### ① 모터와 직접적으로 연결되어있는 부분이다. 아두이노에서 신호를 받아 모터에 입력되는 전류를 조절하여 모터의 속도 및 회전 방향을 제어한다.

#### ② 아두이노 로터리형 엔코더(KY-040)가 장착된 부분으로, 가변저항을 이용하여 모터의 운동(회전방향, 회전 횟수 등)을 제어한다.

#### ③ Logic IC칩과 포토 센서 세트를 사용한 부분이다. 적외선 파장의 빛을 감지하여 그 신호를 아두이노로 전송한다.

### Ⅳ. 프로그래밍
#### 1) 버튼 스위치를 이용한 모터의 3.5바퀴 회전 방향 설정

![1](/image/4.png)<br />
< 그림 4 – 프로그래밍 1-1 >


- 우선 사용할 변수들을 define 해주어야 한다. 아두이노에서 사용되는 핀번호에 따라서 그 핀이 어떤 부품에 연결되는지 표기하는 형식으로 사용해주었다. 위의 회로 구성을 보면 D9와 D10은 트랜지스터, D7은 스위치와 연결되기 때문에 그 핀번호들을 부품 이름으로 define 해준다.

- 이후 사용할 변수들을 초기화해주고, setup 함수에서 사용할 핀번호들을 입력으로 쓸 것인지, 출력으로 쓸 것인지 선언해준다. 지금 이 코드 같은 경우에는 스위치와 포토센서 페어가 있는 부분을 입력으로 설정하고, 2개의 트랜지스터를 출력으로 설정해주었다. 이후 포토센서 페어로 입력되는 값을 변수 led1에 저장한다. 포토센서 페어가 인식되는 경우에는 1, 아니면 0으로 저장된다.

- 이후 loop 함수를 통해 아두이노 보드에 계속 전력이 공급되면서 반복한다. 그렇기 때문에 실제로 코드가 수행되는 공간이라고 볼 수 있다. 스위치가 눌렸을 때, LOW가 입력되는 특성을 이용하여 눌렸는지를 감지하고 그 이후의 시간을 기록하는 코드를 첫 번째 if문에 구현을 해 두었다. 그 이후 1초안에 스위치가 한 번 더 눌렸을 경우를 기록하여 수행되도록 else if문에 구현하였다.

- else if문에 따르면, 스위치가 두 번 눌린 경우에 아두이노 보드의 9번 핀에 연결된 트랜지스터에 전류를 보냄으로써 한 방향으로 모터가 돌 수 있도록 한다. 참고로 9번 핀과 10번 핀에 연결된 트랜지스터 둘 다 출력이 HIGH가 되는 것과 반대 방향으로 돌게 된다. 따라서, 모터가 돌게 되면 엔코더에 의해 포토센서 페어가 인식되는 값이 달라질 것이고 그에 따라 몇 바퀴를 도는지 인식하게 된다. 그 횟수를 cnt 변수에 기록한다. 이후 다음 코드에서 살펴본다. 

![1](/image/5.png)<br />
< 그림 5 – 프로그래밍 1-2 >

- cnt의 값이 28이 되면 모터 구동을 중지시킨다. 왜냐하면 cnt값이 28이 될 때, 3.5바퀴를 도는 것이기 때문이다. 그 이유는 무엇일 까? 엔코더의 날개는 4개이다. 포토센서 페어가 날개에 들어갈 때와 날개에서 나올 때 값의 변화를 인식한다. 따라서 값의 변화가 인식될 때마다 변수 cnt의 값이 증가하는데, 이 값이 한 바퀴를 돌 때 8번 변화하기 때문에 8*3+4=28이므로 이렇게 계산된다.

- 모터 구동이 끝났으면, 모든 변수들을 다시 초기화시켜주고 트랜지스터의 출력도 LOW로 바꿔준다. 아래에 있는 if문은 스위치를 한 번 눌렀을 때 해당되는 코드로 위의 코드와 동일하나, 두 트랜지스터의 출력을 모두 HIGH로 하기 때문에 방금 전 설명했던 2번 눌렀을 때의 모터와 반대 방향으로 돌아가게 된다.

#### 2) KY-040을 이용한 모터 회전

![1](/image/6.png)<br />
< 그림 6 – 프로그래밍 2-1 >


- 앞선 프로그래밍과 동일하게 처음에는 변수들을 정의해주어야 한다. 위의 전처리문과 변수 초기화는 이 코드에서는 같은 방식으로 적용되며, 아두이노의 핀번호에 따라 부품이 있는 곳을 지정해준다.

![1](/image/7.png)<br />
< 그림 7 – 프로그래밍 2-2 >


- KY-040에서 입력되는 clk와 dt값, 그리고 버튼 스위치와 포토센서 페어를 입력으로 설정해주고 두 트랜지스터와 LED를 출력으로 설정해준다. 기본적인 아두이노 보드의 세팅은 끝났다.

![1](/image/8.png)<br />
< 그림 8 – 프로그래밍 2-3 >


- 1번 프로그래밍과 같이 loop 함수에 들어가게 되면 KY-040을 돌린 횟수를 value 변수에 기록하게 된다. 그렇게 되면 value 변수가 기존값과 달라지게 되면서 얼마나 달라졌는지를 계속 RotPosition 변수에 기록하면서 저장한다. KY-040의 DT값을 읽으면서 value와 다를 경우에는 시계방향으로 돌린 것이기 때문에 그 방향까지 기록되어 +값으로 누적되고, 반시계방향으로 돌렸다면 –값으로 누적된다. 

![1](/image/9.png)<br />
< 그림 9 – 프로그래밍 2-4 >


- 버튼 스위치를 눌렀을 때, 모터를 돌리게 된다. KY-040을 얼마나 조정했는지, 어떤 방향으로 돌렸는지에 따라 그 값이 누적된 만큼 버튼 스위치를 누르면 모터가 돌아간다. 모터가 돌아가는 정도는 1번 프로그래밍에서 했던 것처럼 포토센서 페어가 인식되는 값이 변화하는 정도를 이용하여 돌리게 된다. 만약 KY-040을 한 번 돌렸다면 포토센서 페어의 인식 값이 1번 변화하는 동안 모터가 돌아가게 된다. 따라서, 모터를 한 바퀴 돌리기 위해서는 KY-040을 한 방향으로 8번 똑딱 소리가 나게 돌려주면 되는 것이다.


### Ⅴ. 결과
#### 1) 버튼 스위치를 이용한 모터의 3.5바퀴 회전 방향 설정


![1](/image/10.png)<br />
< 그림 10 – 1번 결과 >



- 결과를 사진으로 첨부하여도 이해가 어렵고 동영상 첨부는 더욱 더 안 되기 때문에 로그를 남겨서 결과란에 첨부한다. 지금처럼 버튼이 한 번 눌린 경우에는 인식하여서 값을 음수로 누적하여 포토센서 페어가 28번 인식할 정도로 돌아가는 모습이고, 버튼이 두 번 눌렸을 경우에도 값을 양수로 누적하여 마찬가지로 실행되는 것을 볼 수 있다. 실제로 엔코더도 그만큼 돌아가기 때문에 확인할 수 있다.

![1](/image/anigif1.gif)<br />
< 버튼을 한 번 눌렀을 때, 시계방향으로 돌아가는 영상 >

![1](/image/anigif2.gif)<br />
< 버튼을 두 번 눌렀을 때, 반시계방향으로 돌아가는 영상 >

#### 2) KY-040을 이용한 모터 회전

![1](/image/11.png)<br />
< 그림 11 – 2번 결과 >


- 다음과 같이 KY-040을 시계 방향으로 돌렸을 때, 양수 값으로 누적이 되고 반시계방향으로 돌리게 되면 음수 값으로 누적이 되기 때문에 KY-040을 얼마나 돌렸는지에 따라서 누적을 한 뒤 버튼 스위치를 누르게 되면 그 횟수만큼 포토센서 페어가 인식하면서 모터를 돌리는 것을 확인할 수 있다. 영상을 찍지 못한 채 제출을 하여 누락된 점이 아쉽다.

#### 3) 회로 구성 사진

![1](/image/12.png)<br />
< 그림 12 – 회로 구성 사진 >



### Ⅵ. 참고문헌

1. RLS - <https://www.rls.si/ko/encoder-handbook/what-is-encoder>
2. DIY 메카솔루션 오픈랩 - <https://m.blog.naver.com/roboholic84/220460268471>
3. Toshiba - <https://toshiba.semicon-storage.com/kr/semiconductor/knowledge/e-learning/cmos-logic-basics/chap1/chap1-1.html>
