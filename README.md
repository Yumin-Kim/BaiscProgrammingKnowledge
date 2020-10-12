# 라즈베리파이3를 통해 배우는 Linux 공부!!
# OS 기본 구조 
![OS기본 구조](https://i.imgur.com/a5Eedfm.png)
* 출처 - (https://i.imgur.com/a5Eedfm.png)
    * * *
    * **Context Switching**     
        멀티 프로세스 환경에서 CPU가 어떤 하나의 프로세스를 실행하고 있는 상태에서 인터럽트 요청에 의해 다음 우선 순위의 프로세스가 실행되어야 할때 기존의 프로세스의 상태 또는 레지스터값(Context)을 저장하고  CPU가 다음 프로세스를 수행하도록 새로운 프로게그의 상태 또는 레지스터 값(Context)를 교체하는 작벙르 Context Switching라고 한다.     
        Context Switching을 진행 할 시 해당 CPU에서는 아무런 일을 하지 못하며 Context Switching이 자주 발생하게 되면 오히려 오버헤드가 발생한다.     
        오버헤드는 하나의 프로세스를 해결하기 위햇 부수적인 프로세스드 , 추가 적인 연산을 진행 함으로서 하나의 프로세스에 대한 일의 지연을 발생하는것을 의미한다.
        * Context의 의미     
            사용자와 다른 사용자 , 사용자와 시스템 꼬는 디바이스간의 상호 작용에 영향을 미치는 사람 , 장소 , 객체등의 현재 상황을 규정하는 정보를 말한다.      
            Context는 프로세스의 PCB(Process Control Block)에 저장된다.그래서 Context Switching때 PCB의 정보를 읽어(적재) CPU가 전에 프로세스가 일을 하던거에 이어서 수행이 가능한것이다.       
            PCB의 저장 정보 
            | 정보 | 저장정보 |
            |---|:---:|
            | 프로세스 상태 | 생성 ,준비 , 수행 , 대기 , 중지 |
            | 프로그램 카운터 | 프로세스가 다음에 실행할 명령어 주소 | 
            | 레지스터 | 누산기 , 스택 , 색인 레지스터 |
            | 프로세스 번호 | pid |
  * * *
    * **IPC(InterProcess Control)**     
        1. 프로세스간 통신이란?     
            프로세스들 간 데이터 및 정보를 주고 받기 위한 메커니즘을 말한다.(메커니즘이란 사물의 동작 하기 위한 원리)       
            커널에서 IPC를 위한 도구를 제공하며 시스템 콜의 형태로 프로세스에게 제공된다.
        2. 프로세스간의 통신의 필요성    
            운영체제 내에서 실행되는 프로세스들은 독립적이거나 협력적인 프로세스들 일 수 있다.     
            프로세스 협력 모델을 구현하기 위해서 IPC가 반드시 필요하다.
            1. 독립적인 프로세스(Independent Process)    
                시스템에서 실행 중인 다른 프로세스들에게 영향을 주거나 받지 않는 프로세스
            2. 협력적인 프로세스(Cooperatice Process)
                시스템에서 실행 중인 다른 프로세스들게게 영향을 주거나 받는 프로세스                
    * 프로세스 간 통신에는 크게 두가지 모델 존재
        1. **공유 메모리(Shared Memory) Model**
            1. 정의    
                두 개 이상의 프로세스들이 주소 공간의 공유함 ㅡ 공유한 메모리 영역에 읽기 / 쓰기를 통해서 통신을 수행한다.(Read and Write)진행     
                공유 메모리가 설정되면 그 이후의 통신을 커널의 관여없이 진행 가능하다.
            2. 장 / 단점 
                - 장점 : 커널의 관여 없이 메모리를 직접 사용하여 IPC 속도가 빠르며 프로그램 레벨에서 통신 기능을 제공하여 자유로운 통신이 가능한다.
                - 단점 : 구현하기 어렵다는 단점.
            3. 컨텍스트 스위칭 관점     
                공유 메모리 모델에서의 IPC는 해당 프로세스가 CPU를 사용하는 행위     
                즉 IPC를 많이 한다고 컨텍스트 스위칭 많이 일어나지 않는다
            4. 동기화 관점     
                메모리 영역에 동시적인 접근을 제어 하기 위한 방법이 필요하다.     
                커널이 동기화를 제공하지 않으며 부가적인 방법이 필요하다.    
                접근 제어 방식은 locking이나 semaphore(세마포어)가 있다.
            5. 활용 예 : 데이터 베이스 
            6. 공유 메모리 모델의 구현 IPC : 공유 메모리     
            ![공유 메모리(IPC)](http://postfiles11.naver.net/MjAxNzA0MTdfMTUx/MDAxNDkyNDM1NjQxMzY4.-klYLOIPb--eitK8y2LVnP28CLMG32b-HPuZa0NF6hQg.H_ULo6VW2fmQlyUbBMbKmURL37_Ofd4B0VEvmTjjVd8g.PNG.bycho211/image.png?type=w773)
            7. 버퍼(Buffer)    
                협력적인 프로세스의 예로 , 생산자 - 소비자 문제를 들 수 있다.    
                생산자 - 소비자 문제에 대한 하나의 해셜책은 공유메모리를 사용하는 것이며 이떄 생산자가 정를 채워 넣을 수 있고 소비자가 정보를 소모할 수 있는 버퍼(Buffer)가 반그시 사용 가능해야한다.    
                버퍼 크기 별로 분류    
                | 명칭 | 저장가능 메시지 크키 및 갯수 | 설명 |
                | --- | --------- | --- |
                | `Zero capacity` | 0개 | `no buffering` 송신자는 수신자가 메시지를 받을 떄 까지 대기해야한다 |
                | `bounded capacity(유한 버퍼)` | n개 | `automatic buffering` 버퍼가 가득하 있지 않을때에는 송신자는 메시지를 보내고 대기할 필요가 없으며 , 버퍼가 가득차 있을 경우 송신자는 버퍼에 빈공간이 갱길떄 까지 대기해야한다. |
                | `unbounded capacity(무한 버퍼)` |  무한개 | `automatic buffering` 버퍼가 가득 찰 일이 없기 떄문에 , 모든 경우에 송신자는 대기할 필요가 없다. | 
        2. **메시지 전달(Message Passing) Model**
            1. 정의    
                커널을 경우하여 고정 길이 메시지 , 가변 길이 메시지를 송/수신자끼리 주고 받으며 커널에서는 데이터를 버퍼링한다.(Send and Receive)    
                프로세스 간 메모리 공유 없이 동작이 가능하다.
            2. 장 / 단점    
                - 장점 : 구현하기에 간단하여 사용하기 편리하다.
                - 단점 : 커넣을 경유하므로 , 속도가 느리다.
            3. 컨텍스트 스위칭 관점     
                메시지 전달 모겔에서의 IPC는 해당 프로세스 입장에서 일종의 입출력(I/O)로 볼 수 있다.즉 Context Switching이 자주 발생한다.    
                - ex) Send하고 상대발이 받을 때까지 기다려야 하며 , 이 떄 컨텍스트 스위칭이 발생한다. 마찬가지로 Receive 하면 상대방이 보낼때까지 기다려야 하며 또한 컨텍스트 스위칭이 발생한다.
            4. 동기화 관점     
                send 와 receive와 같은 연산에 대해서 커널이 동기화를 제공한다.     
                send 와 receive를 수행 할때에 프로그램은 동기화에 고려 없이 사용 할 수 있다.
            5. 활용 예 : 서버와 클라이언트 방식의 통신 
            6. 메시지 전달 모델의 구현 IPC : PIPE , Message Queue , Socket , Signal ...     
            ![메시지 전달 모델(IPC)](http://postfiles5.naver.net/MjAxNzA0MTdfMTM1/MDAxNDkyNDM1NzYxODgx.YZv1JMBQqeHya7ifPRCG3leuKEonfCqb5lUrCQa0j_Ag.f5_-S2yyV_6Qnb6-NLPQfasnLIokHZrlIkofIsCpK08g.PNG.bycho211/image.png?type=w773)
## Linux Kenrel Module Program
* 기초 
    * 커널 - 운영체제의 핵심부분으로 프로세스 파일 네트워크 장치등을 관리하는 사용자에게 편리한 인터페이스를 제공해주는 시스템 소프트웨어 이다     
        대부분의 커널 모드는 User 모드와 kenel모드로 나누어져 있다 Kenel모드는 모든 시스템 메모리와 CPU Instruction에 접근이 허가 되며 User모드에서는 접근이 제한된다.     
        이와 같은 영역을 분리한 이유는 User application이 중요한 운영체제 데이터에 접근하지 못하게 하기 위함이다.     
        그렇지만 user application으로 하드웨어를 전혀 접근할 수 없는 것은 아니다     
        * System Call : user application이 하드웨어 리소스에 접근이 필요할때, 반드시 User모드에서 Kernel모드로 레벨이 변경 되어야 사용가능하다(user모드 >> kenrel모드로 변경되는 과정을 의미한다 // 즉 프로세스가 하드웨어에 직접 접근해서 필요한 기능을 사용할 수 있게 해줌)- 이러한 모드 변환은 context switch가 아니며 , system service call이 실제로 thread scheduling에 영향을 끼치지 않기 때문이다. 
            * 시스템 콜의 종류
            1. 프로세스 제어 
            2. 파일 조작
            3. 장치 관리
            4. 시스템 정보 및 자원 관리
            5. 통신 관련
            * System Call은 필요한 기능이나 시스템 환경에 따라 시스템 콜이 발생 할때 좀 더 많은 정보가 필요할 수 있다 그러한 정보가 담긴 매개변수를 운영체제에 전달 하기 위해서 3가지 정도 있음
            1. Register를 통한 전송 - 매개 변수를 CPU Register 내에 전달한다. 이 경우에 매개변수의 갯수가 CPU내의 총 Register 개수 보다 많을 수 있다.
            2. 블록 또는 테이블을 통한 전송 - 위와 같은 경우에 매개변수를 메모리에 저장하고 메모리의 주소가 레지스터에 전달 된다
            3. 스택을 통한 전송 - 매개 변수는 프로그램에 의해 스택(Stack)으로 전달(push) 될 수 있다.
            ![SystemCall](https://t1.daumcdn.net/cfile/tistory/27118142535CCF060A)
            ![C언어 에서의 시스템 콜](https://i.imgur.com/UH0DDZt.png)
        User application 코드르 통해 모든 system Instruction에 접근이 가능하다면 오작동을 유발하며 이사태를 막기 위해 모드를 분리 시켰다. 
        * Monolitic 커널 : 시스템에 관련된 모든 기능을 커널에 모두 탑재 , 모든 기능이 커널에서 동작하기 때문에 기능도 많고 Ring레벨을 변경할 필요 없기 때문에 빠르지만 기능을 추가하려면 커널을 수정후 재 컴파일 해야한다     
        * Micro 커널 : 시스템의 주요 핵심 기능만을 커널에 넣고 그이외는 프로세스로 돌리는 형태 , 핵심 기능은 커널이 처리해주기 때문에 기능 추가를 원할 때 프로세스만 추가하면 커널을 재컴파일 해야하는 일은 없다 . (Ring은 인텔X86계열릐 마이크로 프로세서는 접근 제어를 위해서 Ring이라는 개념을 사용한다 0~4까지 있고 숫자가 작을 수록 권한이 강화 된다 0일때는 슈퍼바이저 모드라고한다)      
        kernel은  memorry관리 scheduling , 기본적인 IPC(Interaction Process Communication)등 최소한의 가장 core한 부분만을 담당하며 나머지는 user영역에서 모듈 형태로 개발하여 덧붙이는 방식    
        * Ring간단하게 정리 - 커널의 불안정한 동작을 방지하기 위해 CPU가 제공하는 보호 모드
            1. Ring 0 소프트웨어 부분에서의 최고 권한이다(슈퍼바이저 모드) - 커널에 접근하고 수정할 수 있음
            2. Ring 1 , Ring 2 장치 드라이버를 담당
            3. Ring 3 프로세스 코드 실행(user mode)
        * Hybrid 커널 : 커널의 본래 역할이 아니더라도 어느정도 커널에 기능을 집어넣은 Mirco커널이다 어느정도 기능을 기존의 Micro커널의 단점을 조금은 해결            
        ![커널종류]](https://upload.wikimedia.org/wikipedia/commons/thumb/d/d0/OS-structure2.svg/1280px-OS-structure2.svg.png)
## Linux Complie gcc
* gcc 동작 과정
    * GNU C Compiler룰 의미했지만 1999년부터 GNU Compiler Collection을 의미한다
    * GCC 실행시키는 프로그램 >> CPP 전처리기 , CC1 컴파일러 , as 어셈블러 , ld 링커 
        1. 전처리 단계       
            소스 파일(file.c)에 gcc를 동작시키면 가장 먼저 전처리기인 cpp가 동작 한다. cpp는 소스파일의 #include와 #define과 같은 #으로 시작되는 전처리기 부분을 처리한다.      
            즉 필요한 헤더 파일을 삽입하고 실행 문장의 매크로를 상수로 변환한다.     
            소스 파일(file.c)이 전처리기를 거치면 file.i라는 이름의 파일이 생성 되지만 디스크에는 지장되지 않는다.
        2. 컴파일 단계     
            컴파일러가 전처리된 파일(file.i)로부터 어셈블리어로 된 파일(file.s)을 생성한다.     
            그런데 일반적으로 다음 단계인 어셉블 단계를 바로 실행하므로 file.s파일은 디스크에 저장되지 않는다.     
        3. 어셉블 단계    
            이 단계에서는 어셉블리어로 된 파일(file.s)을 기계가 직접 이해할 수 있는 기계어로 된 오브젝트 파일(file.o)로 변환한다.
        4. 링크 단계    
            오브젝트 파일(file.o)은 printf() , scanf() 와 같은 라이브러리 함수에 해당하는 코드가 없기 떄문에 실행될 수 없다.    
            또한 여러 파일로 이루어진 프로그램의 경우에도 파일 간에 연결이 이루어지지 않아 실행될 수 없는데 , 이러한 라이브러리 함수와 오브젝트파일들을 연결해 실행 파일을 생성하는 단계가 링크 단계이다.     
            그리고 컴파일 할때는 각 단계별로 옵션을 사용해 얼마나 진행되었는지 그 상황을 볼 수 있게 수동으로 제어할 수 있는데 , 이에 대한 자세한 내용은 gcc 옵션으로 다룬다.
        5.  파일 확장자에 따른 처리 방법    
            gcc는 파일 확장자에따라 다른다
            * 파일 확장자에 따른 처리 방법
                | 확장자 | 종류 | 처리 방법 |
                | ---- |:-----:| ------------:|
                | `.c` | C 소스 파일 | `gcc로 전처리 , 컴파일 , 어셉블 , 링크` |
                | `.C .CC` | C++ 소스 파일 | `g++로 전처리 , 컴파일 , 어셉블 , 링크` |
                | `.i` | 전처리된 C 파일 | `gcc호 컴파일 , 어셉블 , 링크` |
                | `.ii` | 전처리된 C++ 파일 | `g++호 컴파일 , 어셉블 , 링크` |
                | `.s` | 어셉블리어로된 파일 | ` 어셉블 , 링크` |
                | `.S` | 어셉블리어로된 파일 | `전처리 , 어셉블 , 링크` |
                | `.o` | 오브젝트 파일 | `링크` |
                | `.a .so` | 컴파일된 라이브러리 파일 | `링크` |     
* gcc 옵션
    | 옵션 | 의미 |
    | ----:| ----:|
    | `-o` | 바이너리 형식의 출력 파일 이름을 지정하는데 지정하지 않으면 a.out라는 기본 이름이 적용된다.**컴파일 결과 파일 지정 옵션 gcc -o [실행파일 이름] [컴파일할 파일]** |
    | `-c` | 소스 파일을 컴파일만 하고 링크를 수행하지않으며 , 오브젝트 파일을 생성한다.**목적(Object)파일 생성** |
    | `-E` | 전처리를 실행하고 컴파일을 중단하게 한다. |
                                    
### Linux 에디터 Vim 간단한 명령어 (라즈베리파이에서 vim을 따로 설치해야지만 일반적으로 사용하는 vim을 사용 할 수 있다)
* Linux 나 Unix에서 사용하는 vi 편집기는 명령모드 , 입력 모드 , 마지막 행 모드로 총 3가지 모드가 있다
1. 명령 모드(command mode) 처음 vi 명령어로 vi를 시작하게되면 들어가게 되며 여기서는 방향키로 커서 이동 할 수 있고 줄 글자 삭제 및 복사 가능
* 실질적으로 많이 사용하는 명령어
    * 파일의 끝으로 이동할때 (G)
    * 한줄 잘라내기 (dd)ctrl + X
    * 세줄 잘라내기 (3dd) 
    * 붙여 넣기 (p)ctrl + v
    * 한글자 삭제 (x) Delete
    * 단어 삭제 (dw) ctrl + D
    * 실행취소 (u)
    * 줄의 맨앞 (o)
    * 줄의 맨뒤($)
2. 입력 모드(insert mode) 명령어 "i" , "a" 명령을 통해서 입력 모드로 넘아 갈수 있음. 명령 모드로 다시 돌아오려면 "ESC"를 누르면된다
3. 마지막 행 모드 (Last line mode) 마지막 행 모드는 명령 모드에서 ":"을 입력하면 화면 맨 밑단에 :__하며 공간이 나오는데 현재 작성한 코드를 저장하고 종료 "wq" 그냥 종료 "q" , "q!"할 수 있다            
* 실질적으로 많이 사용하는 명령어
    * 저장만 : w
    * 종료만 : q
    * 저장 후 종료 : wq
    * 라인 번호좀 보자 : set nu
    * 커서 위치 뒤로 문자열좀 찾자 : ?문자열
    * 커서 위치 앞으로 문자열좀 찾자 : /문자열
### Window 환경
* windows환경에서 32bit와 64bit 차이
간단히 정리하면  CPU가 처리하는 데이터의 최소 단위인 Register의 크기가 몇bit인지 또는 메모리에서 처리하는데 단위    
그렇지만 꼭 2배차이가 난다고 연산 속도도 2배 차이는 아니다   
32bit 와 64bit의 가장 큰 차이는 메모리 인식 가능한 크기 차이 이다    
32bit는 2^32 = 4GB 이고 64bit는 2 ^64 = 1000TB이다 32bit기반의 운영체제에 4GB의 메모리를 장착해도 의미가 없고 64bit라고 1000TB까지 전부 인식하는것이 아니다     

#### 참고 링크
* [리눅스 커널 프로그래밍 기초!!](https://tribal1012.tistory.com/153)
* [임베디드 시스템 엔지니어를 위한 리눅스 커널 분석](https://www.joinc.co.kr/w/Site/Embedded/Documents/LinuxKernelStudyForSystemenginer/index.html)

##### README.md 작성법
* table
```
<table> 태그로 변환됩니다.
헤더 셀을 구분할 때 3개 이상의 -(hyphen/dash) 기호가 필요합니다.
헤더 셀을 구분하면서 :(Colons) 기호로 셀(열/칸) 안에 내용을 정렬할 수 있습니다.
가장 좌측과 가장 우측에 있는 |(vertical bar) 기호는 생략 가능합니다.

```