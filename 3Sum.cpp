#include<iostream>
using namespace std;
#include<stdio.h>
int count=0;
void Sum(int n,int k)
{
    if(n==0 && k ==0)
    {
        count ++;
        return ;
    }
    if(n==0 ||  k==0)
        return;
    for(int i=1;i<=9;i++)
        Sum(n-i,k-1);
}

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    Sum(n,k);
    printf("%d\n",count);
}
