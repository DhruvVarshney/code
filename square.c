#include<stdio.h>
float absolute(float a)
{
    int isPositive = a>0?1:-1;
    return a*isPositive;
}
float newtonSQRT(float n)
{
    float x0=1,x1=0;
    int counter=0;
    do
    {
        counter++;
        printf("%10f %10f %3d\n",x0,x1,counter);
        x1=(x0+n/x0)/2;
        if(absolute(x1-x0)<1e-3)
            return x1;
        x0=x1;
    }while(1);
    return x0;
}
float SQRT(float n)
{
    if(n<0)
        return -1;
    int counter=0;
    float low=0,high=n;
    if(high<1)
        high=1;
    do
    {
        counter++;
        float mid= low + (high-low)/2;
        float root=mid*mid;
        printf("%10f %10f %10f %10f %3d\n",low,mid,high,mid*mid,counter);
        if(absolute(root-n)<1e-4)
            return mid;
        if(root<n)
            low=mid;
        else high=mid;
    }while(absolute(high-low)>1e-3);
    return low;
}
int main()
{
    float n;
    scanf("%f",&n);
    printf("%.2f\n",SQRT(n));
    printf("%.2f\n",newtonSQRT(n));
    return 0;
}
