#include<stdio.h>
#include<iostream>
using namespace std;
struct Node
{
    char key;
    int val;
    Node *left;
    Node *right;
    Node *mid;
    bool leaf;
    Node(char c,int value)
    {
        left =NULL;
        right=NULL;
        mid=NULL;
        key=c;
        val=value;
        leaf=false;
    }
    Node(char c)
    {
        left=NULL;
        right=NULL;
        mid=NULL;
        key=c;
        leaf=false;
    }
    Node()
    {
        left=NULL;
        right=NULL;
        mid=NULL;
        leaf=false;
    }
};
class TernaryTree
{
    Node *head;
    int count;
public:
    TernaryTree()
    {
        //head = new Node();
        count=0;
    }
    void putWord(string &word)
    {
        int len = word.size();
        Node *curr = head;
        int i=0;
        bool br=false;
        while(1)
        {
            if(!head)
            {
                head = new Node(word[0]);
                curr = head;
                i++;
                continue;
            }
            if(!curr->mid)
            {
                curr->mid = new Node(word[i]);
                i++;
                if(i==len)
                {
                    curr->leaf=true;
                    break;
                }
                curr= curr->mid;
            }
            else if(curr->key==word[i])
            {
                i++;
                if(i==len)
                {
                    curr->leaf=true;
                    break;
                }
                curr= curr->mid;
            }
            else if(curr->key<word[i])
            {
                curr = curr->right;    
            }
            else if(curr->key> word[i])
                curr = curr->left;
        }
    }
    bool search(string &word)
    {
        Node *curr = head;
        int len =  word.size();
        if(len==0)
            return false;
        int i=0;
        while(1)
        {
            if(!curr)
                return false;
            if(curr->key == word[i])
            {
                i++;
                if(i==len)
                    return curr->leaf;
                curr = curr->mid;
            }
            else if(curr->key>word[i])
                curr = curr->left;
            else curr = curr->right;
        }
    }

};

int main()
{
    string s;
    int k;
    TernaryTree *t = new TernaryTree();
    while(1)
    {
        cin>>k;
        cin>>s;
        switch(k)
        {
            case 1:
                t->putWord(s);
                break;
            case 2:
                if(t->search(s))
                    cout<<"found"<<endl;
                else cout<<"not found"<<endl;
        }
    }
}
