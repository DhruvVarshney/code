#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;
struct Node 
{
    int key;
    Node *prev;
    Node *next;
    Node(int data)
    {
        prev = NULL;
        next = NULL;
        key=data;
    }
};
class LRUCache
{
    private:
        int capacity;
        int curr_size;    
        map<int,Node*> hash;
        Node *root;
        Node *back;
    public:
        LRUCache(int cap)
        {
            capacity=cap;
            curr_size = 0;
            root = NULL;
            back = NULL;
        }
        void set(int key);
        void remove(Node* &back)
        {
            Node *temp = back;
            back = back->prev;
            back->next=NULL;
            delete(temp);
        }
        void insert(Node* &root, Node* target)
        {
            if(!root)
            {
                root = target;
                back = target;
                return;
            }
            target->next=root;
            root->prev = target;
            root = target;
        }
        void move(Node* &root,Node *target)
        {
            if(root == target)
                return ;
            if(target->prev)
                target->prev->next = target->next;
            if(target->next)
                target->next->prev = target->prev;
            insert(root,target);
        }
        void printLRU(Node *root)
        {
            while(root)
            {
                cout<<root->key<<" ";
                root= root->next;
            }
            cout<<endl;
        }
};
void LRUCache::set(int key)
{
    if(hash.find(key)!=hash.end())
    {
        map<int,Node*>::iterator it;
        it = hash.find(key);
        move(root,it->second);
        cout<<"cache hit"<<endl;
    }
    else if(curr_size == capacity)
    {
        remove(back);
        Node *temp = new Node(key);
        insert(root,temp);
        cout<<"cache miss"<<endl;
    }
    else 
    {
        Node *temp = new Node(key);
        insert(root,temp);
        curr_size++;
        cout<<"cache miss"<<endl;
        hash[key] = temp;
    }
    //printLRU(root);
}
int main()
{
    LRUCache C(2);

    for(int i=0;i<10;i++)
    {
        int a;
        cin>>a;
        C.set(a);
    }
}
