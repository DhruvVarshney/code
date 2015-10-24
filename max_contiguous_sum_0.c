/*Given is an array containing N numbers, which are either 1, 0 or -1. Find out the length of the longest contiguous subsequence going from index i to j, such that A[i]+A[i+1]..+A[j-1]+A[j] == 0.*/
#include<stdio.h>
int find(int a[],int n)
{
    int sum=0,hash[n];
    int minSum=0,largest=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+a[i];
        if(sum>minSum)
            sum=minSum;
    }
    for(int i=0;i<n;i++)
    {
        int index=sum+minSum;
        if(hash[index] == -1)
            hash[index]=i;
        else 
        {
            if(i-hash[index] > largest)
                largest=i-hash[index]+1;
        }
        sum+=a[i];
    }
    return largest;
}
int main()
{
    int a[10];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
   printf("%d\n",find(a,n));
}
