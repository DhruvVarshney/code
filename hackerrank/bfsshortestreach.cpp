#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void bfs(vector<vector<int> > &graph,int start,vector<int> &dist)
{
	int len  = graph.size();
	queue<int> q;
	q.push(start);
	vector<bool> visited(len,false);
	for(int i=0;i<len;i++)
	{
		visited[i]=false;
		dist[i] = -1;
	}

	visited[start]=true;
	dist[start]=0;


	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
		for(int i=0;i<graph[curr].size();i++)
		{
			int ver = graph[curr][i];
			if(!visited[ver])
			{
				visited[ver] = true;
				dist[ver] = dist[curr]+6;
				q.push(ver);
			}
		}
		printf("%d\n",dist[curr]);
	}
	return;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{   
		int N,M,S;
		scanf("%d%d",&N,&M);
		vector<vector<int> > graph(N);
		for(int i=0;i<M;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			graph[a-1].push_back(b-1);
			graph[b-1].push_back(a-1);
		}
		vector<int> dist(N);
		scanf("%d",&S);
		bfs(graph,S-1,dist);
		for(int i=S;i<N+S-1;i++)
		{
			printf("%d ",dist[i%N]);
		}
		printf("\n");
	}
}
