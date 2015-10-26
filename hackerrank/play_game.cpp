#include<iostream>
#include<stdio.h>
#include<vector>
#define f(A,i) i>=0?A[i]:0
#define FOR(st,end)\
	for(int i=st;i<=end;i++)
#define cal(A,i)\
		min(f(A,i),min(f(A,i-1),f(A,i-2)))
using namespace std;
int calculate(vector<int> &A)
{
	int len= A.size();
	vector<int> dp(len+1);
	dp[0]=0;
	for(int i=1;i<=len;i++)
	{
		dp[i] = max(cal(dp,i-1)+f(A,i-1),
					max(cal(dp,i-2)+f(A,i-1)+f(A,i-2),
						cal(dp,i-3)+f(A,i-3)+f(A,i-2)+f(A,i-1)));
	}
	FOR(0,len)
		printf("%d ",dp[i]);
	cout<<endl;
	return dp[len];
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		vector<int> A;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			int k;
			scanf("%d",&k);
			A.push_back(k);
		}
		printf("%d\n",calculate(A));
	}
	return 0;
}
