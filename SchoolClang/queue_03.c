/*
�ǽ���:146p  ť �ǽ�
������ ����: �ڿ��� ������
�ǽ���: 2020 04 13
�а� : ��Ƽ �̵�� �а�
�й� : 201610309
�̸� : ������
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100
#define MAX_SIZE 6

typedef struct {
	int x, y;
} Location2D ;

typedef Location2D Elements;

Elements data[MAX_QUEUE_SIZE];

int front;
int rear;

char map[MAX_SIZE][MAX_SIZE] = {
	{'1','1','1','1','1','1',},
	{'e','0','1','0','0','1',},
	{'1','0','0','0','1','1',},
	{'1','0','1','0','1','1',},
	{'1','0','1','0','0','x',},
	{'1','1','1','1','1','1',},
};

void error(char str[]) {
	printf("%s\n", str);
	exit(1);
}

void init_queue() { front = rear = 0; ; }
int is_empty() {
	return front == rear;
}
int is_full() {
	return front == (rear + 1) % MAX_QUEUE_SIZE;
}

int size() {
	return (rear - front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

void enqueue(Elements val) {
	if (is_full()) {
		error("ť ��ȭ ����");
	}
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	data[rear] = val;
}

Elements dequeue() {
	if (is_empty()) {
		error(" ť ���� ���� ");
	}
	front = (front + 1) % MAX_QUEUE_SIZE;
	return data[front];
}

Elements peek() {
	if (is_empty()) {
		error("ť ���� ����");
	}
	return data[(front + 1) % MAX_QUEUE_SIZE];
}

void init_deque() { init_queue(); }
void add_rear(Elements val) { enqueue(val); }
Elements delete_front() { return dequeue(); }
Elements get_front() { return peek(); }

void add_front(Elements val) {
	if (is_empty()) {
		error(" �� ��ȭ ���� ");
	}
	data[front] = val;
	front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

Elements delete_rear() {
	int prev = rear;
	if (is_empty()) {
		error("�� ���� ����");
	}
	rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return data[prev];
}

Elements get_rear() {
	if (is_empty()) {
		error("�� ���� ����");
	}
	return data[rear];
}

Location2D getLocation2D(int x , int y){
	Location2D p;
	p.x = x;
	p.y = y;

	return p;
}
int is_valid(int x, int y) {
	if (x < 0 || y < 0 || x >= MAX_SIZE || y >= MAX_SIZE) return 0;
	else return map[y][x] == '0' || map[y][x] == 'x';
}
int DFC() {
	int x, y;
	Location2D here;

	init_deque();
	add_rear(getLocation2D(0,1));
	printf("DFC : ");

	while (is_empty() == 0) {
		here = delete_rear();
		printf("(%2d,%2d)", here.x, here.y);
		x = here.x;
		y = here.y;
		if (map[y][x] == 'x' ) return 1;
		else {
			map[y][x] = '.';
			if (is_valid(x-1,y)) add_rear(getLocation2D(x - 1, y));
			if (is_valid(x + 1, y)) add_rear(getLocation2D(x + 1, y));
			if (is_valid(x, y -1)) add_rear(getLocation2D(x, y - 1));
			if (is_valid(x, y+1)) add_rear(getLocation2D(x, y+1));
		}
	}
	return 0;
}

int BFS() {
	int x, y;
	Location2D here;

	init_deque();
	add_rear(getLocation2D(0, 1));
	printf("BFS : ");

	while (is_empty() == 0 ) {
		here = delete_front();
		printf("(%2d,%2d)", here.x, here.y);
		x = here.x;
		y = here.y;
		if (map[y][x] == 'x') return 1;
		else {
			map[y][x] = '.';
			if (is_valid(x - 1, y)) add_rear(getLocation2D(x - 1, y));
			if (is_valid(x + 1, y)) add_rear(getLocation2D(x + 1, y));
			if (is_valid(x, y - 1)) add_rear(getLocation2D(x, y - 1));
			if (is_valid(x, y + 1)) add_rear(getLocation2D(x, y + 1));
		}
	}
	return 0;
}
void main() {
	//printf("->%s\n",DFS() ? "����" : "����");
	printf("->%s\n",BFS() ? "����" : "����");
}









