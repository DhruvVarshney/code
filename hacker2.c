#include<stdio.h>
#define size 2000004
int main()
{
	int n,k;
	char s[size],ans[size];
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	int i=0,xor=0;
	while(i<n)
	{
		int k=s[i]-'48';
		if(xor^1==k)
		{
			ans[i]='1';
			xor^=1;
		}
		else 
		{
			ans[i]='0';
			xor^=0;
		}
		i++;
	}
	ans[i]='\0';
	printf("%s\n",ans);
	return 0;
}
