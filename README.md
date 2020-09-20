# 라즈 베리 파이3 IOT 공부!!(필기는 window 실습은 Raspberry를 통해서 진행)
## 라즈 베리 파이3 LED 제어 (C언어를 사용)-No Library


# 라즈베리파이3를 통해 배우는 Linux 공부!!
# OS 기본 구조 
![OS기본 구조](https://i.imgur.com/a5Eedfm.png)
* 출처 - (https://i.imgur.com/a5Eedfm.png)
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
    * 
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