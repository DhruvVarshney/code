#include<iostream>
#include<stdio.h>
using namespace std;
struct Node
{   
    char key;
    bool end;
    Node *left;
    Node *middle;
    Node *right;
    Node(char c)
    {
        left = NULL;
        middle = NULL;
        right =  NULL;
        key = c;
        end = false;
    }
};
class TernTree
{
    int totalWord;
    Node *root;
    public:
        TernTree()
        {
            root=NULL;
            totalWord=0;
        }
        void insert(string s);
        bool search(string s);
        void isExist(string s);
};

void TernTree::insert(string s)
{
    int len = s.size();
    Node *curr =root;
    int i= 0;
    while(i<len)
    {
        if(!root)
        {
            root = new Node(s[i]);
            curr = root;
        }
        else
        {
            if(curr->key==s[i])
            {
                i++;
                if(!curr->middle)
                    curr->middle = new Node(s[i]);
                curr = curr->middle;
            }
            else if(curr->key > s[i])
            {
                if(!curr->left)
                    curr->left = new Node(s[i++]);
                curr = curr->left;
            }
            else if(curr->key <s[i])
            {
                if(!curr->right)
                    curr->right = new Node(s[i++]);
                curr = curr->right;
            }
        }

    }
    if(i == len)
        curr->end=true;
    return ;
}
bool TernTree::search(string s)
{
    int len = s.size();
    bool found = false;
    int i = 0;
    cout<<s<<endl;
    Node *curr = root;
    while(i<len)
    {
        if(!curr)
            return false;
        if(curr->key > s[i])
        {
            curr = curr->left;
        }
        else if(curr->key < s[i])
        {
            curr = curr->right;
        }
        else if(curr->key == s[i])
        {
            if(i == len-1)
            {
                //if(curr->end == true)
                    return true;
                cout<<"returng fallse"<<endl;
                return false;
            }
            i++;
            curr = curr->middle;
        }
    }
   return false; 
    
}
int main()
{
    TernTree T;
    string S;
    for(int i=0;i<10;i++)
    {
        cin>>S;
        T.insert(S);
    }
    string p;
    for(int i=0;i<100;i++)
    {
        cin>>p;
    if(T.search(p))
        cout<<"found"<<endl;
    else cout<<"Not Found"<<endl;
    }

    //cin>>p;
    return 0;
}
