#include<stdio.h>
int rightShift(int a ,int n)
{
    return a>>n;
}
void printBits(int a)
{
    int i=0;
    unsigned n=(unsigned)a;
    for(i=31;i>=0;i--)
    {
        printf("%u",(n&1<<i)>>i);
    }
    printf("\n");
}
int main()
{
    int a,n,i=0;
    scanf("%d",&a);
    for(;i<32;i++)
        printf("%d >> %d = %d\n",a,i,rightShift(a,i));
    //printf("%u\n",(unsigned)a);
    printBits(a);
    return 0;
}
