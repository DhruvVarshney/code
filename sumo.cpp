#include <iostream>
#include<map>
#include<stdio.h>
#include<queue>
using namespace std;
struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int data)
    {
        this->data=data;
        prev=NULL;
        next=NULL;
    }
};
class SumoDs
{
    private:
        Node *head;
        map<int,Node*>m;
    public:
        SumoDs()
        {
            head=NULL;
        }
        bool emptyList()
        {
            return head==NULL;
        }
        bool exist(int data)
        {
            if(m.find(data)!=m.end())
                return true;
            return false;
        }
        Node *getNode(int data)
        {
            if(exist(data))
            {
                map<int,Node*>::iterator it = m.find(data);
                return it->second;
            }
            return NULL;
        }
        void removeNode(Node *node)
        {
            if(node==head)
            {
                head=head->next;
            }
            else
            {
                node->prev->next=node->next;
                if(node->next)
                    node->next->prev=node->prev;
            }
            node->next=NULL;
            node->prev=NULL;
        }
        void insertNode(Node *node)
        {
            if(!node)
                return;
            if(!head)
                head=node;
            else
            {
                node->next=head;
                head->prev=node;
                head=node;
            }
            return;
        }
        void move2Front(Node *node)
        {
            removeNode(node);
            insertNode(node);
            return;
        }
        void add(int data)
        {
            if(exist(data))
            {
                Node *node = getNode(data);
                move2Front(node);
            }
            else
            {
                Node *node = new Node(data);
                insertNode(node);
                m[data]=node;
            }
            return;
        }
        void _delete(int data)
        {
            if(exist(data))
            {
                Node *node=getNode(data);
                removeNode(node);
                m.erase(data);
                delete(node);
            }
        }
        bool contains(int data)
        {
            return exist(data);
        }
        int getMostRecent(int data)
        {
            if(head)
                return head->data;
            return -1;
        }
};
int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

