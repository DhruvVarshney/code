#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
class Solution {
    public:
        void printVec(vector<int> &vec)
        {
            for(int i=0;i<vec.size();i++)
            {
                cout<<vec[i]<<" ";
            }
            cout<<endl;
        }
        void PrintPath(vector<vector<int> > &path,int target,vector<vector<int> >&ans,vector<int> &temp)
        {
            if(target == 0)
            {
                ans.push_back(temp);
                printVec(temp);
                return;
            }
            else if(target<0)
                temp.clear();
            for(int i=0;i<path[target].size();i++)
            {
                if(temp.size() == 0 || temp[temp.size()-1] <=path[target][i] )
                {
                    temp.push_back(path[target][i]);
                    PrintPath(path,target-path[target][i],ans,temp);
                    temp.pop_back();
                }
            }
        }
        void  combinationSum(vector<int>& candidates, int target) 
        {
            vector<vector<int> > path(target+1);
            vector<vector<int> > ans;
            vector<int> temp;
            bool dp[10000] ={false};
            dp[0] = true;

            for(int i=0;i<candidates.size();i++)
            {
                for(int j=0;j<=target;j++)
                {
                    if(dp[j])
                    {
                        if(j+candidates[i]<=target)
                        {
                            dp[j+candidates[i]] = true;
                            path[j+candidates[i]].push_back(candidates[i]);
                        }
                    }
                }
            }
            for(int i=0;i<path.size();i++)
            {
                cout<<i<<"->  ";
                printVec(path[i]);
            }
            PrintPath(path,target,ans,temp);
            
        }
};
int main()
{
    Solution S;
    int a[]={1,2,3};
    vector<int> vec(a,a+3);
    S.combinationSum(vec,5);
}
