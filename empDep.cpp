#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#define MI map<int,empNode>:: iterator
struct empNode
{
    int id;
    string name;
    empNode *manager;
    vector<emoNode*> child;
    empNode(int Id,string Name,empNode* mngr)
    {
        id = Id;
        name =Name;
        manager = mngr;
    }
};
class org
{
    emoNode *ceo;
    int empCount;
    int maxEmpId;
    map<int,empNode*> m;
    public:
        void insertEmp(empNode *emp)
        {
            Node *mngr = emp->manager;
            mngr->child.push_back(emp);
        }
        void addEmp(string empName,int managerId)
        {
            empNode *mngr;
            if(m.find(managerId)!=m.end())
            {
              empCount++;
              maxEmpId++;
              empNode *emp;  
              mngr = map.find(managerId);
              emp = new empNode(maxEmpId,empName,mngr);
              insertEmp(emp);
            }
            else 
            {
                cout<<"Invalid manager"<<endl;
            }
        }
        void setCeo(int empId)
        {
            if(ceo)
            {
                MI it;
                it = m.find(empId);
                if(it!=m.end())
                {
                    *emp = it->second;
                    *ceo = *emp;
                }
            }
        }
        void bsf(empNode *emp)
        {
            if(!emp)
                return;
            queue<empNode *emp> q;
            q.push(emp);
            while(!q.empty())
            {
                empNode *curr = q.top();
                q.pop();
                cout<<curr->id<<endl;
                for(int i = 0;i<curr->child.size();i++)
                {
                    q.push(curr->child[i]);
                }
            }
        }
        void listAllEmp(int empId)
        {
            MI it = m.find(empId); 
            empNode *emp = it->second; 
            bfs(emp);
        }
}
