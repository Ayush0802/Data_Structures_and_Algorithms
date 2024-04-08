#include <iostream>
#include <bits/stdc++.h>
using namespace std;
template <typename T>

class graph
{
    public:
    unordered_map<T,set<T>> adjlist;

    void InsertEdge(int u,int v,bool direction)
    {
        adjlist[u].insert(v);
        if(direction == 0)
        {
            adjlist[v].insert(u);
        }
    }

    void topoSort_dfs(unordered_map<int,bool>&visited,int src,stack<int>&s)
    {
        visited[src]=1;

        for(auto i:adjlist[src])
        {
            if(!visited[i])
            {
                topoSort_dfs(visited,i,s);
            }
        }

        s.push(src);
        
    }

    void topoSort_kahn(vector<int>&ans,int n)
    {
        vector<int>indegree(n);

        for(auto i:adjlist)
        {
            for(auto j:i.second)
            {
                indegree[j]++;
            }
        }

        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int front = q.front();
            q.pop();

            ans.push_back(front);

            for(auto i:adjlist[front])
            {
                indegree[i]--;
                if(indegree[i]==0)
                {
                    q.push(i);
                }
            }
        }
    }
};

int main()
{
    graph<int> g;

    int n,e,d;
    cin>>n>>e>>d;
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;

        g.InsertEdge(u,v,d);
    }



    // Topological Sort using DFS
    unordered_map<int,bool>visited;
    stack<int>s;
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            g.topoSort_dfs(visited,i,s);
        }
    }

    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }



    // Topological Sort using Kahn's Algorithm
    vector<int>ans;
    cout<<endl;
    g.topoSort_kahn(ans,n);
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }



    return 0;
}