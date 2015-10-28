#include<stdio.h>
#include<iostream>
#define uint unsigned int
void read(uint A[],uint n)
{
	for(uint i=0;i<n;i++)
		scanf("%d",&A[i]);

}
uint gcd(uint a,uint b)
{
	if(a==0)
		return b;
	return gcd(b%a,a);
}
bool isCo_prime(uint a,uint b)
{
	return 1==gcd(a,b);
}
int main()
{
	uint t,k,n,m;
	uint X[21],C[103],Z[103];
	scanf("%d",&t);
	while(t--)
	{
		uint bitVec[103]={0};
		scanf("%d%d%d",&n,&m,&k);
		read(X,n);
		read(C,m);
		read(Z,m);
		for(uint i = 0;i<m;i++)
		{
			for(uint j=0;j<n;j++)
				if(!isCo_prime(C[i],X[j]))
					bitVec[i] = bitVec[i] | 1u<<X[j];
		}
		uint res = 0;
		uint ans = 0;
		uint done = 0;
		for(uint i=0;i<k;i++)
		{
			uint maxWeight=0;
			uint maxPos=0;
			for(uint j =0;j<n;j++)
			{
				uint curr = X[j];
				if(!(res & 1u<<curr))
				{
					uint weight = 0;
					for(uint p=0;p<m;p++)
					{
			 			if((!(bitVec[p] & res)) && (bitVec[p] & 1u<<curr))	
						{
							weight += Z[p];
						}
					}
					if(weight>maxWeight)
					{
						maxWeight = weight;
						maxPos = curr;
					}
				}
			}
			ans +=maxWeight;
			res = res | 1u<<maxPos;
		}
		printf("%d\n",ans);
	}
	return 0;
}
