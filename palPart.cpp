#include<iostream>
#include<limits.h>
using namespace std;
bool palindrome(string &s,int low,int high)
{
    while(low<high)
    {
        if(s[low]!=s[high])
            return false;
        low++,high--;
    }
    return true;
}
int minPart(string s)
{
    int len = s.size();
    if(len<2)
        return len;
    if(palindrome(s,0,len-1))
        return 0;
    int mins = INT_MAX; 
    for(int i=0;i<len;i++)
    {
        if(palindrome(s,0,i))
            mins = min(minPart(s.substr(i+1,len-i-1))+1,mins);
    }
    return mins;
}
int main()
{
    string s;
    cin>>s;
    cout<<minPart(s)<<endl;
    return 0;
}
