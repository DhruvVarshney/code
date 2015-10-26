#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#define read(x) scanf("%d",&x);
#define SIZE 101
#define FOR(I,N)	for(int i=0;i<N;i++)
#define DESTINATION 100
using namespace std;
int bfs(vector<int> &snake,vector<int> &ladder)
{
	vector<bool> visited(SIZE,false);
	queue<int> q;
	q.push(1);
	vector<int> dist(SIZE);
	dist[1] = 0;
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
		if(curr == DESTINATION)
			return dist[curr];
		for(int i=curr+1;i<=curr+6 && i<=DESTINATION;i++)
		{
			int v = i;
			if(snake[i]!=-1)
				v = snake[i];
			else if(ladder[i]!=-1)
				v = ladder[i];
			if(!visited[v])
			{
				visited[v] = true;
				dist[v] = dist[curr]+1;
				q.push(v);
			}
		}
	}
	return -1;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N,M;
		vector<int> ladder(SIZE);
		vector<int> snake(SIZE);
		for(int i=0;i<SIZE;i++)
		{
			snake[i] = -1;
			ladder[i] = -1;
		}
		read(N);
		FOR(i,N)
		{
			int r,s;
			read(r);
			read(s);
			ladder[r]=s;
		}

		read(M);
		FOR(i,M)
		{
			int r,s;
			read(r);
			read(s);
			snake[r]=s;
		}

		int res = bfs(snake,ladder);
		printf("%d\n",res);
	}
}
