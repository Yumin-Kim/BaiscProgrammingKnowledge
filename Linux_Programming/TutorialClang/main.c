#include <stdio.h>

extern void print(char *);
extern char* input();

int main()
{
 char * str = input();
 print(str);
 printf("\n");
}
