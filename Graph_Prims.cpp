#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class graph
{
    public:
    unordered_map<int,list<pair<int,int>>> adjlist;

    void InsertEdge(int u,int v,int w,bool direction)
    {
        adjlist[u].push_back(make_pair(v,w));
        if(direction == 0)
        {
            adjlist[v].push_back(make_pair(u,w));
        }
    }

    void mst_prims_algorithm(int n,vector<bool>&mst,vector<int>&parent,vector<int>&key)
    {

        for(int i=1;i<=n;i++)
        {
            int min = INT_MAX;
            int index;

            for(int i=1;i<=n;i++)
            {
                if(mst[i]==false && key[i]<min)
                {
                    min = key[i];
                    index = i;
                }
            }

            mst[index] = true;
            for(auto i:adjlist[index])
            {
                if(mst[i.first]==false && key[i.first] > i.second)
                {
                    key[i.first] = i.second;
                    parent[i.first] = index;
                }
            }
        }
    }

};

int main()
{
    graph g;

    int n,e,d;
    cin>>n>>e>>d;
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;

        g.InsertEdge(u,v,w,d);
    }

    int src;
    cin>>src;

    vector<int>key(n+1);
    vector<int>parent(n+1);
    vector<bool>mst(n+1);

    for(int i=0;i<=n;i++)
    {
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    key[src] = 0;
    parent[src] = -1;

    g.mst_prims_algorithm(n,mst,parent,key);

    for(int i=2;i<=n;i++)
    {
        cout<<parent[i]<<"->"<<i<<" "<<key[i]<<endl;
    }


    return 0;
}