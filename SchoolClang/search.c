/*
�ǽ���: Search Programing �ǽ�!!
������ ����: �ڿ��� ������
�ǽ���: 2020 06 15
�а� : ��Ƽ �̵�� �а�
�й� : 201610309
�̸� : ������
*/



/* C��� ǥ�� ���̺귯�� �Լ� :  bsearch (binary search)
   void* bsearch (const void* key, const void* base,size_t num, size_t size, int (*compare)(const void*,const void*)); ���� Ž�� �Լ�
   ���� ������ �迭���� �˻�   */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int compare_int(const void* a, const void* b)   /* �� ���� ������ ���ϴ� �˰���(�Է� ���ڷ� ������ �ִ� �޸� �ּҸ� �����ؾ� ��)   */
                                                                /*  if *a > *b ,   ��� ��ȯ,  if *a == *b ,  0 ��ȯ,  if  *a < *b, ���� ��ȯ  */
{
    const int* p1 = (const int*)a;
    const int* p2 = (const int*)b;
    return *p1 - *p2;
}
int compare_str(const void* a, const void* b)  /* �� ���� ���ڿ��� ���ϴ� �˰���(�Է� ���ڷ� ���ڿ� �ּҸ� �����ؾ� ��)   */
{
    const char* p1 = (const char*)a;
    const char* p2 = (const char*)b;

    return strcmp(p1, p2);
}

typedef char strelem[20];  /* ���� ������ char�̰� ũ�Ⱑ 20�� �迭 ������ strelem ���� Ÿ�Ը� ����  */

int main(void)
{
    int arr[10] = { 1, 10 , 15, 20, 29, 30, 31, 33, 35, 50 };  /*  ���� ����  */
    strelem arr2[5] = { "������","�豸","��������","�̼���","ȫ�浿" };  /*  ���� ����  */
    int* pos;
    strelem* pos2;

    int key = 29;
    pos = (int*)bsearch(&key, arr, 10, sizeof(int), compare_int);  /* ���� Ž��  */
    if (pos != NULL) {
        printf("%d is in the array %d index.\n", *pos, pos - arr);  /*  Ž�� Ű�� �ε��� ���  */
    }
    else {
        printf("%d is not in the array.\n", key);
    }
    pos2 = (strelem*)bsearch("�̼���", arr2, 5, sizeof(strelem), compare_str);   /*  ���� Ž��   */
    if (pos2 != NULL) {
        printf("%s is in the array %d index.\n", pos2, pos2 - arr2);   /*  Ž�� Ű�� �ε��� ���  */
    }
    else
    {
        printf("%d is not in the array.\n", "�̼���");
    }

    return 0;
}

