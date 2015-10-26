#include<stdio.h>
#include<stdint.h>
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
int main()
{	
	#define ub8 unsigned long
	ub8 p,m,t;
	uint128_t k;
	scanf("%lu",&t);
	while(t--)
	{
		scanf("%lu%lu",&m,&p);
		int res = m^p;
		printf("%d\n",numSetBit(res));
	}
	return 0;
}
