#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void topoSort(unordered_map<int,list<int>>&adj,unordered_map<int,bool>&visited,int src,stack<int>&s)
{
    visited[src]=1;

    for(auto i:adj[src])
    {
        if(!visited[i])
        {
            topoSort(adj,visited,i,s);
        }
    }

    s.push(src);
    
}

void dfs(unordered_map<int,bool>&visited,int node,unordered_map<int,list<int>>&adj)
{
    visited[node] = 1;

    for(auto i:adj[node])
    {
        if(!visited[i])
        {
            dfs(visited,i,adj);
        }
    }
}

int SCC(vector<vector<int>>graph,int n)
{
    unordered_map<int,list<int>>adj;
    for(int i=0;i<graph.size();i++)
    {
        int u = graph[i][0];
        int v = graph[i][1];

        adj[u].push_back(v);
    }


    stack<int>s;
    unordered_map<int,bool>visited;
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            topoSort(adj,visited,i,s);
        }
    }


    unordered_map<int,list<int>>adj_trans;

    for(int i=0;i<n;i++)
    {
        visited[i]=0;
        for(auto j:adj[i])
        {
            adj_trans[j].push_back(i);
        }
    }

    int ans = 0;
    while(!s.empty())
    {
        int top = s.top();
        s.pop();
        if(!visited[top])
        {
            ans++;
            dfs(visited,top,adj_trans);
            
        }
    }
    return ans;

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

    for(int i=0;i<e;i++)
    {
        graph[i]=vector<int>(2);
        for(int j=0;j<2;j++)
        {
            cin>>graph[i][j];
        }
    }

    int ans = SCC(graph,n);
    cout<<ans;

    return 0;
}