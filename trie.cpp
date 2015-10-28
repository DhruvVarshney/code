
class TrieNode
{
	public:
		TrieNode *child[26];
		int value;
		TrieNode()
		{
			for(int i=0;i<26;i++)
				child[i]=(TrieNode*)0;
			value=0;
		}
		bool isLeaf()
		{
			return value==0;
		}
};
class WordDictionary
{
	private:
		TrieNode *trie;
		int count;
	public:
		wordDictionary()
		{
			trie = new TrieNode();
			count=0;
		}
		void addWord(string word)
		{
			TrieNode *p =trie;
			int l = word.size();
			for(int i=0;i<l;i++)
			{
				char c = word.at(i);
				if(!p->child[c-'a'])
					p->child[c-'a'] = new TrieNode();
				p = p->child[c-'a'];
			}
			p->value++;
		}
		bool search2(string &word,int pos, TrieNode *p)
		{
			if(pos == word.size())
			{
				return p->isLeaf();
			}
			if(word.at(pos) =='.')
			{
				for(int i=0;i<26;i++)
				{
					if(p->child[i])
					{
						if(search2(word,pos+1,p->child[i]))
							return true;
					}
				}
				return false;
			}
			else
			{
				int idx = word.at(pos)-'a';
				if(p->child[idx])
				{
					return search2(word,pos+1,p->child[idx]);
				}
				return false;
			}
		}
		bool search(string word)
		{
			return search2(word,0,trie);
		}
};
int main()
{
	return 0;
}

