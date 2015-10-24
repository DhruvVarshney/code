#include<stdio.h>
int *a;
int mul(int x)
{
    int p=8;
    a = &p;
}
int main()
{
    mul(10);
    int b[9]={10};
    printf("%d\n",*a);
    return 0;
}
