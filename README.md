# 라즈 베리 파이3 IOT 공부!!(필기는 window 실습은 Raspberry를 통해서 진행)
## 라즈 베리 파이3 LED 제어 (C언어를 사용)-No Library


# 라즈베리파이3를 통해 배우는 Linux 공부!!
## Linux Kenrel Module Program
* 기초 
    * 커널 - 운영체제의 핵심부분으로 프로세스 파일 네트워크 장치등을 관리하는 사용자에게 편리한 인터페이스를 제공해주는 시스템 소프트웨어 이다     
        대부분의 커널 모드는 User 모드와 kenel모드로 나누어져 있다 Kenel모드는 모든 시스템 메모리와 CPU Instruction에 접근이 허가 되며 User모드에서는 접근이 제한된다.     
        이와 같은 영역을 분리한 이유는 User application이 중요한 운영체제 데이터에 접근하지 못하게 하기 위함이다.     
        그렇지만 user application으로 하드웨어를 전혀 접근할 수 없는 것은 아니다     
        * System Call : user application이 하드웨어 리소스에 접근이 필요할때, 반드시 User모드에서 Kernel모드로 레벨이 변경 되어야 사용가능하다(user모드 >> kenrel모드로 변경되는 과정을 의미한다 // 즉 프로세스가 하드웨어에 직접 접근해서 필요한 기능을 사용할 수 있게 해줌)- 이러한 모드 변환은 context switch가 아니며 , system service call이 실제로 thread scheduling에 영향을 끼치지 않기 때문이다.      
            * System Call은 필요한 기능이나 시스템 환경에 따라 시스템 콜이 발생 할때 좀 더 많은 정보가 필요할 수 있다 그러한 정보가 담긴 매개변수를 운영체제에 전달 하기 위해서 3가지 정도 있음
            1. 매개 변수를 CPU Register 내에 전달한다. 이 경우에 매개변수의 갯수가 CPU내의 총 Register 개수 보다 많을 수 있다.
            2. 위와 같은 경우에 매개변수를 메모리에 저장하고 메모리의 주소가 레지스터에 전달 된다
            3. 매개 변수는 프로그램에 의해 스택(Stack)으로 전달(push) 될 수 있다.
            ![SystemCall](https://t1.daumcdn.net/cfile/tistory/27118142535CCF060A)

        User application 코드르 통해 모든 system Instruction에 접근이 가능하다면 오작동을 유발하며 이사태를 막기 위해 모드를 분리 시켰다. 
        * Monolitic 커널 : 시스템에 관련된 모든 기능을 커널에 모두 탑재 , 모든 기능이 커널에서 동작하기 때문에 기능도 많고 Ring레벨을 변경할 필요 없기 때문에 빠르지만 기능을 추가하려면 커널을 수정후 재 컴파일 해야한다
        * 
#### 참고 링크
* [리눅스 커널 프로그래밍 기초!!](https://tribal1012.tistory.com/153)