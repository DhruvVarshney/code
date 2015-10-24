#include<stdio.h>
int add(int a,int b)
{
    int sum=a^b;
    int carry=a&b;
    if(!carry)
        return sum;
    return add(sum,carry<<1);
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d\n",add(a,b));
}
