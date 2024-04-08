#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dfs(int node,unordered_map<int,list<int>>&adj,unordered_map<int,bool>&visited,vector<int>&low,vector<int>&disc,int &parent,vector<int>&ans,int &timer)
{
    visited[node]=1;
    disc[node] = low[node] = timer++;

    int child = 0;
    for(auto nbr : adj[node])
    {
        if(parent == nbr)
        {
            continue;
        }

        if(!visited[nbr])
        {
            dfs(nbr,adj,visited,low,disc,node,ans,timer);
            low[node]=min(low[node],low[nbr]);
            if(low[nbr]>=disc[node] && parent!=-1)
            {
                ans.push_back(node);
            }
            child++;
        }
        else
        {
            low[node]=min(low[node],disc[nbr]);
        }
    }
    if(parent==-1 && child>1)
    {
        ans.push_back(node);
    }
}

void ArticulationPoint(vector<vector<int>>graph,int n,vector<int>&ans)
{
    unordered_map<int,list<int>>adj;
    for(int i=0;i<graph.size();i++)
    {
        int u = graph[i][0];
        int v = graph[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int>disc(n);
    vector<int>low(n);
    unordered_map<int,bool>visited;
    for(int i=0;i<n;i++)
    {
        disc[i]=-1;
        low[i]=-1;
        visited[i]=false;
    }

    int parent = -1;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            dfs(i,adj,visited,low,disc,parent,ans,timer);
        }
    }
}

int main()
{
    int n,e;
    cin>>n>>e;

    if(e==0)
    {
        cout<<1;
        exit(0);
    }

    vector<vector<int>>graph(n);
    vector<int>ans;
    for(int i=0;i<e;i++)
    {
        graph[i]=vector<int>(2);
        for(int j=0;j<2;j++)
        {
            cin>>graph[i][j];
        }
    }

    ArticulationPoint(graph,n,ans);

    for(int i=0;i<ans.size();i++)
    {
        cout<<"-> ";
        cout<<ans[i];
        cout<<endl;
    }

    return 0;
}