# Operation Systam관련 프로그래밍
## Pthread를 활용한 스레드 프로그래밍
* 스레드 : CPU의 기본 연산 단위라고도 하며 프로세스내에서 실제로 작업을 수행하는 주체를 의미한다.     
    모든 프로세스에는 한개이상의 스레드가 존재하여 작업을 수행한다.
* 사용 해본 라이브러리
    * unistd.h : 유닉스에서 사용하는 C컴파일러 헤더 파일 , window에서 사용 하지 못한다.
    * stdlib.h : C언어의 표준의 라이브러리로 문자열 변환 , 의자 난수 생성 , 동적 메모리 관리 등의 함수들을 포함하고 있다.
    * fcntl.h : file control의 함수 조회와 설정을 할 수 있는 함수
    * 
* Pthread API
    * 기본적으로 pthread.h 라이브러리를 사용하기 위해서 -l 옵션을 사용해야한다 **EX gcc -o Test Test.c -lpthread** 이와 같이 작성해야한다. 
    * pthread_create(pthread_t *thread , const pthread_attr_t *attr , void *(*start_routine)(void *) , void *arg)- 스레드를 생성라는 매소드
    * pthread_join(pthread_t thread , void **thread_return) - 특정 스레드가 종료 되기를 기다렸다가 스레드가 종료된 이후 다음 진행 >> join된 스레드(종료됨)는 모든 자원을 반납하게 된다. 
    * pthread_detach(pthread_t th) - 특정 스레드 분리