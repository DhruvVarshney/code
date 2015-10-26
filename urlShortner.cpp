#include<map>
#include<vector>
#include<string>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include <string>
#include <sstream>

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}
using namespace std;
class AutoIncreament
{
    static int k;
    public:
    int getId()
    {
        return k;
    }
    void increamentId()
    {
        k++;
    }
};
int AutoIncreament::k=0;
class urlShortner
{
    static const int BASE=63;
    map<int,char> charMap;
    map<int,string> m;
    map<string,int> url2id;
    AutoIncreament *A;
    int count;
    public:
    urlShortner()
    {
        A = new AutoIncreament();
        count=0;
    }
    char getChar(int num)
    {
        char ans;
        if(num<=9)
            ans = num + '0';
        else if(num<=35)
            ans = 'a'+num-10;
        else if(num<=61)
            ans = 'A'+num-36;
		else if(num==62)
			ans = '/';
        else
            printf("wrong choice");
        return ans;

    }
    int getNum(char c)
    {
        int num;
        if (c<='9')
            num = c-'0';
        else if (c<='Z')
            num = c - 'A' +36;
        else if(c<='z')
            num = c-'a'+10;
        else if(c=='/')
			num = 62;
		else
            printf("wrong choice\n");
        return num;
    }
    string fromId(int id)
    {
        string s;
        while(id>0)
        {
            int rem = id%BASE;
            s = (getChar(rem))+s;
            id = id/BASE;
        }
        return s;
    }
    int toId(string &s)
    {
        int pos=0,len=s.size();
        int ans=0;
        while(pos<len)
        {
            char c = s.at(pos);
            int k = getNum(c);;
            ans = ans*BASE+k;
            pos++;
        }
        return ans;
    }
    void mapUrl(int key,string url)
    {
        if(m.find(key) == m.end())
        {

            m[key] = url;
            url2id[url] = key;
            count++;
        }

    }
    string shortUrl(string url)
    {     
        string ans;
        map<string,int>::iterator it;
        if(url2id.find(url)==url2id.end())
        {
            A->increamentId();
            mapUrl(A->getId(),url);
            ans = fromId(A->getId()); 
        }
        else
        {
            it = url2id.find(url);
            int key = it->second;
			ans = fromId(key);
        }
        return ans;
    }
    string getUrl(string sUrl)
    {
        string ans;
        int key = toId(sUrl);        

        if(m.find(key)!=m.end())
        {
            ans = (m.find(key))->second;
        }
        return ans;
    }
};
int main()
{
    urlShortner *us = new urlShortner();
    vector<string> urls;
    vector<string> sUrls;
    for(int i=0;i<100000;i++)
    {
        urls.push_back("facebook.com/abhay/kumar"+patch::to_string(i));
    }
    for(int i=0;i<urls.size();i++)
    {
        string s = us->shortUrl(urls[i]);
        sUrls.push_back(s);
    }
    for(int i=0;i<sUrls.size();i++)
    {
        string s = us->getUrl(sUrls[i]);
        cout<<sUrls[i]<<" -->"<<s<<endl;
    }
}
