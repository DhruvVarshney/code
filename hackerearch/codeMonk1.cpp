#include<stdio.h>
#include<iostream>
#include<algorithm>
#define SIZE 100005
using namespace std;
int numSetBit(int n)
{
	int count=0;
	while(n>0)
	{
		n = n&(n-1);
		count++;
	}
	return count;
}
bool comparator(int a,int b)
{
	return numSetBit(a) > numSetBit(b);
}
int findMaxCandy(int A[],int n,int k)
{
	std::sort(A,A+n,comparator);
	int ans = 0;
	for(int i=0;i<k;i++)
		ans += numSetBit(A[i]);
	return ans;
}
int main()
{	
	int A[SIZE];
	int n,k,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=0 ; i<n; i++)
			scanf("%d",&A[i]);
		printf("%d\n",findMaxCandy(A,n,k));
	}
	return 0;
}
