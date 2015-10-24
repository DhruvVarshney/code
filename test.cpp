#include"hashmap.cpp"
#define size 100
int main()
{
    MyHashMap map(10);
    for(int i=0;i<size;i++)
    {
        map.map(i,i);
    }
    for(int i=0;i<2*size;i++)
    {
        int val=map.get(i);
        if(val==INVALID)
            printf("%d key not found\n",i);
        else
        {
             printf("%d key value =  %d\n",i,val);
        }
    }
    map.printMap();
    return 0;
}
