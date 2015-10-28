#include<iostream>
#include<climits>
#include<vector>
#include<queue>
#include<stdio.h>
using namespace std;
struct Node
{
	int weight;
	int id;
	Node(int id,int weight)
	{
		this->id=id;
		this->weight=weight;
	}
	Node()
	{
		weight=INT_MAX;
		id=INT_MAX;
	}
};
class CompNode
{
	public:
		bool operator()(const Node &a,const Node &b)
		{
			return a.weight > b.weight;
		}
};
void printVec(vector<int> &vec)
{
	for(int i=0;i<vec.size();i++)
		printf("%d ",vec[i]);
	printf("\n");
}
void Dijkstra(vector<vector<Node> > &Graph,int st,vector<int> &dist)
{
	priority_queue<Node,vector<Node>,CompNode> minQ;
	int n = Graph.size();
	Node start(st,0);
	vector<bool> visited(n,false);
	for(int i=0;i<n;i++)
		visited[i] = false;
	minQ.push(start);
	visited[start.id] = true;
	dist[start.id]=0;
	while(!minQ.empty())
	{
		Node curr = minQ.top();
		minQ.pop();
//		printf("visisting %d node \n",curr.id);

		int id=curr.id;
		for(int i=0;i<Graph[id].size();i++)
		{
			Node v = Graph[id][i];
			//cout<<"considering node "<<v.id<<endl;
			if(dist[v.id] > dist[id] + v.weight)
			{
				dist[v.id] = dist[id] + v.weight;
				if(!visited[v.id])
				{
					minQ.push(v);
					visited[v.id] =true;
				}
			}
		}
	}
}

void printGraph(vector<vector<Node> > &Graph)
{
	for(int i=0;i<Graph.size();i++)
	{
		for(int j=0;j<Graph[i].size();j++)
			printf("%d ",Graph[i][j].id);
		printf("\n");
	}
}
int main()
{
	int m,n;
	scanf("%d%d",&n,&m);
	Node start,end;
	vector<int> s_dist(n,INT_MAX);
	vector<int> d_dist(n,INT_MAX);
	vector<vector<Node> > graph(n);
	for(int i=0;i<m;i++)
	{
		int a,b,w;
		cin>>a>>b>>w;
		a--,b--;
		Node node1(a,w);
		Node node2(b,w);
		graph[a].push_back(node2);
		graph[b].push_back(node1);
	}
//	printGraph(graph);
	Dijkstra(graph,0,s_dist);
	Dijkstra(graph,n-1,d_dist);
	//printVec(s_dist);
	//printVec(d_dist);
	int ans = 0,min_dist = s_dist[n-1];
	for(int i=0;i<n;i++)
	{
		if(s_dist[i] < min_dist)
			ans += min_dist-s_dist[i]-1;
	}
	printf("%d\n",ans);
}
