#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main_56412()
{
   /* double a;
    double b;
    double c;
    double d;
    scanf("%lf %lf", &a, &b);
    printf("\n");
    scanf("%lf %lf", &c, &d);
    double e = a * 2 / b / b;
    double f = c * 2 / d / d;
    printf("%.3lf\n", e);
    printf("%.3lf", f);*/
    printf("ÄãºÃ");
    int a, b, c, d;
    int dic[4];
    dic[scanf("%d %d %d %d", &a, &b, &c, &d)];
    
    for (int i = 0; i <= 3; i++)
    {
        dic[i] = 65 + i;
    }
    for (int i = 0; i <= 3; i++)
    {
        printf("%d\n",dic[i]+4);
    }
    return 0;
}