#include<iostream>
#include<stdio.h>
using namespace std;
#define FUN(a,b,c,d,t) (a*t*t*t + b*t*t + c*t +d)
int search(float low,float high,int k)
{
    while(high -low > 10e-1)
    {
        float mid = (high+low)/2;
        int res = FUN(a,b,c,d,mid);
        if(res>k)
            high = mid-1;
        else low = mid;
    }
    return (int)low;
}
