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

int n;
int useRand=1;
int partition(int *A,int low,int high)
{
    if(useRand)
    {
        int size = high-low+1;
        int idx = rand()%size + low;
       // printf("random = %d\n",idx);
        std::swap(A[idx],A[low]);
    }

    int pivot=A[low];
    int i=low+1,j=high;

    while(i<=j)
    {
        if(A[i]<=pivot)
            i++;
        else if(A[j]>=pivot)
            j--;
        else
        {
            std::swap(A[i],A[j]);
            i++,j--;
        }

    }
    std::swap(A[low],A[j]);
    printArr(A,n,int);
    return j;
}
void quickSort(int A[],int low,int high)
{
    if(low>=high)
        return;
    int ind=partition(A,low,high);
    quickSort(A,low,ind-1);
    quickSort(A,ind+1,high);
}
int main()
{
    int A[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&A[i]);
    quickSort(A,0,n-1);
    for(int i=0;i<n;i++)
        printf("%d ",A[i]);
    printf("\n");
}

