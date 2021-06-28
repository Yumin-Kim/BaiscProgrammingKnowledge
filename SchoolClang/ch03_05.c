/*
실습명:This program is for studying struct and Max_Score_Student function  
교수님 성함: 박웅규 교수님
실습일: 2020 04 01
학과 : 멀티 미디어 학과
학번 : 201610309
이름 : 김유민
*/
#include <stdio.h>
#include <string.h>

typedef struct student {
	int id;
	char name[200];
	double score;
}Student;

void printf_student(Student s);
Student Max_score_student(Student s[]);

int main() {
	struct student s1 = { 1 , "Park" , 80.5 }, s2;
	Student s[3];
	int i;

	s2.id = 2;
	strcpy(s1.name, "Kim");
	printf_student(s1);

	for (i = 0; i < 3; i++) {
		printf("ID , name , score  >>");
		scanf("%d %s %lf", &s[i].id, &s[i].name, &s[i].score);
	}
	for (i = 0; i < 3; i++) {
		printf("ID = %d , Name = %s , score = %lf \n", s[i].id, s[i].name, s[i].score);
	}

	s2 = Max_score_student(s);
	printf("Max_Score_Student Result : ID = %d , Name = %s , Score = %lf", s2.id, s2.name, s2.score);
	return 0;
}

void printf_student(Student s) {
	printf("ID = %d , Name = %s , score = %lf \n", s.id, s.name, s.score);
}

Student Max_score_student(Student s[]){
	Student tmp = s[0];
	for (int j = 0; j < 3; j++) {
		if (s[j].score > tmp.score) tmp = s[j];
	}
	return  tmp;
}
