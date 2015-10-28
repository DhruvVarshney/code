#include<stdio.h>
#include<iostream>
using namespace std;
float itoa(string &s)
{
	float res = 0;
	int len = s.size();
	bool dotFound=false;
	int sign = 1;
	int i=0;
	int factor = 1;
	while(i<len)
	{
		if(s.at(i)=='-')
		{
			if(i==0)
				sign=-1;
			else cout<<"wrong format";
		}
		else if(s.at(i) == '.')
		{
			if(dotFound)
				cout<<"wrong format"<<endl;
			dotFound = true;
			factor =10;
		}
		else if(s.at(i)>='0' && s.at(i)<='9')
		{
			float digit = s.at(i) - '0';
			if(dotFound)
			{
				res = res + digit/factor;
				factor = factor*10;
			}
			else 
			{
				res = res*10 + digit;
			}
		}
		else cout<<"wrong format\n"<<endl;
		i++;
	}
	return res*sign;
}
int main()
{
	string s;
	while(1)
	{
		cin>>s;
		printf("%f\n",itoa(s));
	}
	return 0;
}
