#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2]<b[2];
}

int findparent(vector<int>&parent,int node)
{
    if(parent[node]==node)
    {
        return node;
    }
    return parent[node] = findparent(parent,parent[node]);
}

void Union(int u,int v, vector<int>&parent,vector<int>&rank)
{
    u = findparent(parent,u);
    v = findparent(parent,v);

    if(rank[u]<rank[v])
    {
        parent[u] = v;
    }
    else if(rank[u]>rank[v])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

void make_set(vector<int>&parent,vector<int>&rank,int n)
{
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
        rank[i]=0;
    }
}
int kruskal(vector<vector<int>>g,int n)
{
    int min_weight = 0;
    
    sort(g.begin(),g.end(),cmp);
    
    vector<int>parent(n);
    vector<int>rank(n);
    make_set(parent,rank,n);


    for(int i=0;i<g.size();i++)
    {
        
        int u = g[i][0];
        int v = g[i][1];
        int w = g[i][2];

        u = findparent(parent,u);
        v = findparent(parent,v);

        if(u!=v)
        {
            Union(u,v,parent,rank);
            min_weight+=w;
        }

    }
    return min_weight;
}

int main()
{
    int n,e;
    cin>>n>>e;

    vector<vector<int>>graph(n);

    for(int i=0;i<e;i++)
    {
        graph[i]=vector<int>(3);
        for(int j=0;j<3;j++)
        {
            cin>>graph[i][j];
        }
    }

    int ans = kruskal(graph,n);
    cout<<ans;

    return 0;
}