#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#define INT 1
#define CHAR 2
#define printArr(Arr,n,type)                   \
{                                           \
    for(int i=0;i<n;i++)                     \
    printf("%d ",((type*)Arr)[i]);   \
    printf("\n");                            \
}   
using namespace std;
void countSort(int A[],int n)
{
    int *count = new int[n];
    int *B     = new int[n];
    for(int i=0;i<n;i++)
        count[A[i]]++;
    for(int i=1;i<n;i++)
        count[i]+=count[i-1];
    for(int i=n-1;i>=0;i--)
    {
        B[count[A[i]]-1] = A[i]; 
        count[A[i]]--;
    }
    for(int i=0;i<n;i++)
        A[i]=B[i];
}

int main()
{
    int A[100];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&A[i]);
    countSort(A,n);
    for(int i=0;i<n;i++)
        printf("%d ",A[i]);
    printf("\n");
}

