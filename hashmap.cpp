#include<iostream>
#include<cstdio>
#include<cstdlib>
#define INVALID -9999999
using namespace std;
struct MyHashList
{
    int key;
    int val;
    MyHashList *next;
    MyHashList(int val_key,int value)
    {
        key=val_key;
        val=value;
        next=NULL;
    }
};
class MyHashMap
{
    public:
        MyHashList **arr;
        int num_element;
        int size;
    public:
        MyHashMap(int n)
        {
            arr =  new  MyHashList*[n];
            size=n;
            cout<<"Creating hashMap of size  "<<n<<endl;
            for(int i=0;i<n;i++)
            {
                arr[i]=NULL;
            }
        };
        ~MyHashMap()
        {
            delete[] arr;
        } 
        int max_capacity(void)
        {
            return size;
        }
        void map(int key,int value)
        {
            int hashIndex=key%size;
            if(arr[hashIndex] == NULL)
            {
                arr[hashIndex]=new MyHashList(key,value);
                return;
            }
            MyHashList *head=arr[hashIndex];
            while(head->key!=key && head->next)
                head=head->next;
            if(head->key==key)
                head->val=value;
            else
                head->next=new MyHashList(key,value);
            return;
        }
        int get(int key)
        {
            int hashIndex=key%size;
            MyHashList *head=arr[hashIndex];
            while(head && head->key!=key)
                head=head->next;
            if(head)
                return head->val;
            else
                return INVALID;
        }
        int contains(int key)
        {
            return get(key) == INVALID ? false : true;
        }
        void printMap(void);

};
void MyHashMap::printMap(void)
{
    int n=max_capacity();
    for(int i=0;i<n;i++)
    {
        MyHashList *node=arr[i];
        if(node)
            printf(" %d ",node->key);
        do
        {
            if(node!=NULL)
            {
                printf("-->%d",node->val);
                node=node->next;
            }
            if(!node) printf("---> NULL");

        }while(node!=NULL);
        printf("\n");
    }
}
