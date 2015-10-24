#include<stdio.h>
int multiply(int a,int b)
{
    int res=0;
    if(a>1)
    {
        res=multiply(a>>1,b<<1);
    }
    if(a%2)
        res+=b;
    return res;
}
int mult(int a,int b)
{
    int isPos=1;
    if((a<0 && b>0) || (a>0 && b<0))
        isPos=0;
   int result= multiply(abs(a),abs(b));
   if(isPos)
       return result;
   return -result;

}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d\n",mult(a,b));
}
