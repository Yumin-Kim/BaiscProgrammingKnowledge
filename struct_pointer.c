/*
실습명: struct pointer 실습!!
교수님 성함: 박웅규 교수님
실습일: 2020 04 20
학과 : 멀티 미디어 학과
학번 : 201610309
이름 : 김유민
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
	int id;
	char name[20];
	char dept[32];
} Student ;

void test1(Student s);
void test2(Student *s);
Student test3(Student s);

int main() {
	//struct student s; 사용 가능!! 
	Student s1, s2;
	Student* ptr_s2 = &s2;

	s1.id = 10;
	strcpy(s1.name, "Park");
	strcpy(s1.dept, "Computer Eng..");
	//*ptr_s2 = s1; 밑에 의미와 동일
	s2 = s1;
	printf(" s2 struct >>  %d , %s , %s \n", ptr_s2->id , ptr_s2->name, s2.dept);

	test1(*ptr_s2);
	printf("call-by-value s2 struct >>  %d , %s , %s \n", ptr_s2->id, ptr_s2->name, s2.dept);

	test2(ptr_s2);
	printf("call-by-reference s2 struct >>  %d , %s , %s \n", ptr_s2->id, ptr_s2->name, s2.dept);

	*ptr_s2 = test3(s2);//s2 = test3(s2);
	printf("return Student s2 struct >>  %d , %s , %s \n", ptr_s2->id, ptr_s2->name, s2.dept);

	return 0;
}

void test1(Student s) { /* call-by-value  */
	s.id = 20;
}

void test2(Student *s) { /* call-by-value  */
	s->id = 20;
}

Student test3(Student s) {
	s.id = 30;
	return s;
}






