#include<stdio.h>
#include<iostream>
#include<string.h>
#define uint64 long long int
#define SIZE 1000090
#include<math.h>
#define size 1000090
using namespace std;
int p[1000004];
bool primes[size];
int primeCount=0;
void sieve(int n)
{
	uint64 i;
	for(i=0;i<=n;i++) primes[i]=true;
		for(i=2;i*i<=n;i++)
		{
			for(uint64 j= i*i; j<=n ; j+= i)
			{
				primes[j]=false;
			}
		}
	for(i=2; i<=n;i++)
	{
		if(primes[i])
			p[primeCount++] =i;
	}
}
int main()
{
	int t;
	u64 n;
	preCompute(size-1);
	scanf("%d",t);
	while(t--)
	{
		int i=0,count=0;
		scanf("%lld",&n);
		while(n || i<primeCount)
		{
			while(n%p[i]==0)
			{
				n=n/prime[i];
				count++;
			}
			i++;
		}
		printf("%d\n",count);
		
	}
	return 0;
}
