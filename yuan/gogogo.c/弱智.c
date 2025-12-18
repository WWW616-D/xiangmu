#include<stdio.h>
int main_2145()
{
    int i = 0;
    float f = 1.05;
    unsigned char* q = (unsigned char*)&f;
    char* number = "1.05";            //0.105* 10^1
    char result[4];
    unsigned char* p;
    p = number;
    int a = -1;
    printf("a=%d ,result=%x\n", a, result);
    for (i = 0; i <= 3; i++)
        printf("%x ", *(q+i));
    printf("\n");
}
