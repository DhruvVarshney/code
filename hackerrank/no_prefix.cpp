#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
#define NUM_CHAR 10
struct TrieNode
{
	bool leaf;
	TrieNode *child[NUM_CHAR];
	
	TrieNode()
	{
		for(int i=0;i<NUM_CHAR;i++)
			child[i] = NULL;
		leaf=false;
	}
	bool isLeaf()
	{
		return leaf;
	}
};

struct Trie
{
	TrieNode *trie;
	int count;
	public:
		Trie()
		{
			trie = new TrieNode();
			count=0;
		}
		bool insert(string &s)
		{
			TrieNode *curr = trie;
			int len = s.size();
			for(int i=0;i<s.size();i++)
			{
				int idx = s[i] - 'a';
	
				if(!curr->child[idx])
					curr->child[idx] = new TrieNode();
				curr = curr->child[idx];
				if(curr->leaf)
				{
					return false;
				}
			}
			for(int i=0;i<NUM_CHAR;i++)
			{
				if(curr->child[i])
				{
					return false;
				}
			}
			curr->leaf = true;
			count++;
			return true;
		}
};
int main()
{
	int n;
	scanf("%d",&n);
	bool badSet  = false;
	Trie *t = new Trie();
	while(n--)
	{
		string s;
		cin>>s;
		if(t->insert(s) == false)
		{
			cout<<"BAD SET"<<endl;
			cout<<s<<endl;
			badSet=true;
			break;
		}
	}
	if(!badSet)
		cout<<"GOOD SET"<<endl;
	return 0;
}
