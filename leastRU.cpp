#include<iostream>
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
struct myNode
{
    private:
        Node *head;
        map<int,Node*> m;
    public:
        myNode()
        {
            head=NULL;
        }
        bool empty()
        {
            return head==NULL;
        }
        bool exist(int data)
        {
            if(m.find(data) != m.end())
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
        }
        void remove(Node *node)
        {
            if(node==head)
            {
                head=node->next;
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
        void insert(Node *node)
        {
            if(!head)
                head=node;
            else
            {
                node->next=head;
                head->prev=node;
                head=node;
            }
        }
        void move2Front(Node *node)
        {
            remove(node);
            insert(node);
        }
        int getMostRecent()
        {
            if(!head)
                printf("empty list\n");
            else
                return head->data;
           return -1;
        }
        void Insert(int data)
        {
          if(exist(data))
          {
            Node *node = getNode(data); 
            move2Front(node);
          }
          else    
          {
            Node *node=new Node(data);    
            insert(node);
            m[data]=node;
          }
        }
        void Remove(int data)
        {
          if(exist(data))
          {
            Node *node = getNode(data); 
            remove(node);
            m.erase(data);
          }
        }

};
int main()
{
    myNode *obj = new myNode();
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int x,y;
        int elem;
        scanf("%d",&x);
        switch(x)
        {
            case 1:
                scanf("%d",&y);
                obj->Insert(y);
                break;
           case 2:
                scanf("%d",&y);
                obj->Remove(y);
                break;
           case 3:
                scanf("%d",&y);
                if(obj->exist(y))
                    printf("1\n");
                else
                    printf("0\n");
                break;
           case 4:
                elem= obj->getMostRecent();
                printf("%d\n",elem);
                break;
           default:
                printf("Invalid inpunt\n");
                
        }
    }
    
}

