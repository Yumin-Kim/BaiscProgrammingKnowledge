/*
실습명:10 실습!!
교수님 성함: 박웅규 교수님
실습일: 2020 04 23
학과 : 멀티 미디어 학과
학번 : 201610309
이름 : 김유민
*/
#include <stdio.h>
#define MAX_STACK_SIZE 100
typedef int Elements;

typedef struct stack {
	Elements data[MAX_STACK_SIZE];
	int top;
} Stack;

void error(char str[]) {
	printf("%s\n", str);
	exit(1);
}
void init_stack(Stack *s) { s->top = -1; }
int is_empty(Stack* s) { return s->top == -1; }
int is_full(Stack* s) { return s->top == MAX_STACK_SIZE; }
int size(Stack* s) { return s->top + 1; }

void push(Stack *s,Elements e) {
	if (is_full(s))  error("스택 포화 에러");
	s->data[++s->top] = e;
}

Elements pop(Stack *s) {
	if (is_empty(s))	 error("스택 공백 에러");
	return s->data[s->top--];
}

Elements peek(Stack *s) {
	if (is_empty(s)) error("스택 공백 에러");
	return s->data[s->top];
}

void print_stack(Stack *s,char msg[]) {
	int i;
	printf("%s[%2d]= ", msg, size(s));
	for (i = 0; i < size(s); i++) printf("%2d", s->data[i]);
	printf("\n");
}

void init_Stack_queue(Stack *s1, Stack *s2) {
	init_stack(s1);
	init_stack(s2);
}

void enqueue_Stack(Stack* s, Elements e) {
	push(s, e);
}

Elements dequeue_Stack(Stack* s1, Stack* s2) {
	Elements i = 0;
	if (is_empty(s2)) {
		printf("Stack 2 empty >> Stack1 의 요소 Stack 2로 옮기는중 ...\n");
		Elements stack_size = size(s1);
		while (i < stack_size) {
			enqueue_Stack(s2, pop(s1));
			i++;
		}
		return pop(s2);
	}
	return pop(s2);
}


int main() {
	Stack s1, s2;
	init_Stack_queue(&s1,&s2);
	for(int i = 0 ; i < 10 ; i ++)
		enqueue_Stack(&s1 , i );
	printf("현재 스택 1의 요소 개수 %d  \n", size(&s1));
	printf("현재 스택 2의 요소 개수 %d  \n", size(&s2));
	printf("현재 스택으로 만든 큐의 사이즈 : %d \n", size(&s1) + size(&s2));

	printf("큐 요소 삭제 하겠습니다\n");
	printf("큐의 요소가 삭제 되었습니다 삭제 요소 =  %d \n",dequeue_Stack(&s1,&s2));
	printf("큐의 요소가 삭제 되었습니다 삭제 요소 =  %d \n",dequeue_Stack(&s1,&s2));
	printf("큐의 요소가 삭제 되었습니다 삭제 요소 =  %d \n",dequeue_Stack(&s1,&s2));
	printf("큐의 요소가 삭제 되었습니다 삭제 요소 =  %d \n",dequeue_Stack(&s1,&s2));
	printf("큐의 요소가 삭제 되었습니다 삭제 요소 =  %d \n",dequeue_Stack(&s1,&s2));

	printf("현재 스택 1의 요소 개수 %d  \n", size(&s1));
	printf("현재 스택 2의 요소 개수 %d  \n", size(&s2));
	printf("현재 스택으로 만든 큐의 사이즈 : %d \n",size(&s1) + size(&s2));

}
