#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct  node{
    int nData;
    struct Node* next;
} Node;

typedef struct stack{
    Node* nodeStack;
} Stack;



// prices_len�� �迭 prices�� �����Դϴ�.
int* solution(int prices[], size_t prices_len) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    int* answer = (int*)malloc(sizeof(prices_len));
    Node * tmpNode =NULL;
    for (int i = 0;  i < (signed)prices_len; i++)
    {
        Node* psPrice = (Node*)malloc(sizeof(Node));
        if (tmpNode== NULL) {
            psPrice->nData = prices[i];
        }
        else {
            psPrice->nData = prices[i];
            psPrice->next = tmpNode;
        }
        tmpNode = psPrice;
    }
    while (tmpNode !=NULL )
    {
        printf("%d\t", tmpNode->nData);
        tmpNode
    }
    return sizeof(answer);
}

int main(void) {
    int nArray[5] = { 1, 2, 3, 2, 3 };
    printf("%d", solution(nArray, 5));
    return 0;
}