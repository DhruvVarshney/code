#include<queue>
#include<iostream>
#include<cstdio>
using namespace std;
int findDirty(int n)
{
    priority_queue<int,vector<int>,greater<int> > q2,q3,q5;
    int min_num;
    int counter = 0;
    q2.push(2);
    q3.push(3);
    q5.push(5);
    while(counter < n)
    {
        min_num = min(q2.top(),min(q3.top(),q5.top()));
        if(min_num == q2.top())
        {
            q2.push(min_num *2);
            q2.push(min_num*3);
            q2.push(min_num*5);
            q2.pop();
        }
        else if(min_num == q3.top())
        {
            q3.push(min_num*3);
            q3.push(min_num*5);
            q3.pop();
        }
        else
        {
            q5.push(min_num*5);
            q5.pop();
        }
        counter++;
        printf("%d ",min_num);
    }
    return min_num;
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("\n%d\n",findDirty(n));
    return 0;
}
