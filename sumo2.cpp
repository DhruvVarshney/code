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
    public:
        SumoDs()
        {
            head=NULL;
        }

        void add(int data);
        void deleteElem(int data);
        bool contains(int data);
        int getMostRecent(void);
};
void SumoDs::add(int data)
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
void SumoDs::deleteElem(int data)
{
    if(exist(data))
    {
        Node *node=getNode(data);
        removeNode(node);
        m.erase(data);
        delete(node);
    }
}
bool SumoDs::contains(int data)
{
    return exist(data);
}
int SumoDs::getMostRecent(void)
{
    if(head)
        return head->data;
    return -1;
}
int main()
{
    SumoDs *obj = new SumoDs();
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
                obj->add(y);
                break;
            case 2:
                scanf("%d",&y);
                obj->deleteElem(y);
                break;
            case 3:
                scanf("%d",&y);
                if(obj->contains(y))
                    printf("1\n");
                else
                    printf("0\n");
                break;
            case 4:
                elem= obj->getMostRecent();
                printf("%d\n",elem);
                break;
            default:
                printf("Invalid input\n");

        }
    }

}

