#include"hashmap.cpp"
#include<iostream>
using namespace std;
#include<cstdio>
int longest(int a[],int n)
{
     int max=0;
     MyHashMap map(n);
     for(int i=0;i<n;i++ )
     {
         int key=a[i];
         if(map.contains(key))
             continue;
         int l=0;
         int r=0;
         if(map.contains(key-1))
             l=map.get(key-1);
         if(map.contains(key+1))
             r=map.get(key+1);
         int v=l+r+1;
         map.map(key-l,v);
         map.map(key+r,v);
         if(max<v)
             max=v;
     }
     return max;
}
int main()
{
    int a[100];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int ans=longest(a,n);
    cout<<ans<<endl;
    return 0; 
}
