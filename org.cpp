#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<map>
#include<string>
#define MI map<int,empNode*>::iterator
using namespace std;
struct empNode
{
    int empId;
    string name;
    empNode *parent;
    vector<empNode*> child;
    empNode(int Id,string s,empNode *p)
    {
        empId = Id;
        name =s;
        parent  = p;
    }

};

class org
{
    int count;
    empNode *ceo;
    int increament;
    map<int,empNode*> m;
    public:
        org()
        {
            count = 0;
            ceo = NULL;
            increament=0;
        }
        empNode *getEmp(int id)
        {
            MI it;
            if(m.find(id) != m.end())
            {
                it = m.find(id);
                return it->second;
            }
            return NULL;
        }
        void add(string name,int pId)
        {
           int id =  increament;
           empNode *p = getEmp(pId);
          
           empNode *curr = new empNode(id,name,p);
           if(p)
           {
                p->child.push_back(curr);
           }
           m[id] = curr;
           increament++;
           cout<<"adding node "<<name<<" "<<pId<<endl;
        }
        void setCeo(int id)
        {
            empNode *emp  = getEmp(id);
            if(!ceo)
            {
                ceo = emp;
            }
        }
        void bfs(empNode *emp)
        {
            queue<empNode*> q;
            
            q.push(emp);
            while(!q.empty())
            {
                empNode *curr = q.front();
                q.pop();
                cout<<curr->empId<<" "<<curr->name<<endl;
                int len  = curr->child.size();
                for(int i=0;i<len;i++)
                {
                    q.push(curr->child[i]);               
                }
            }
        }
        void listAllEmp(int id)
        {
           empNode *emp = getEmp(id); 
           bfs(emp);
        }
};
int main()
{
    org *myOrg  = new org();
    vector<string> svec;
    string s ;
    cin>>s;
    for(int i=0;i<10;i++)
        svec.push_back(s+std::to_string(i));
    for( int i=0;i<10;i++)
        myOrg->add(svec[i],0);
    myOrg->listAllEmp(0);
}


