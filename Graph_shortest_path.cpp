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

    void shortest_path_bfs(unordered_map<int,bool>&visited,unordered_map<int,int>&parent,int src,int dest,stack<int>&ans)
    {
        queue<int>q;
        visited[src]=1;
        parent[src]=-1;
        q.push(src);

        while(!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            for(auto i:adjlist[frontNode])
            {
                if(!visited[i])
                {
                    visited[i]=1;
                    parent[i]=frontNode;
                    q.push(i);
                } 
            }
        }

        int j = dest;
        while(j!=src)
        {
            ans.push(j);
            j=parent[j];
        }
        ans.push(src);
    }
};


class newgraph
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

    void topoSort_dfs(unordered_map<int,bool>&visited,int src,stack<int>&s)
    {
        visited[src]=1;

        for(auto i:adjlist[src])
        {
            if(!visited[i.first])
            {
                topoSort_dfs(visited,i.first,s);
            }
        }

        s.push(src);
        
    }

    void shortest_path_DAG(int src, vector<int>&dist,stack<int>&s)
    {
        dist[src]=0;

        while(!s.empty())
        {
            int top = s.top();
            s.pop();

            if(dist[top]!=INT_MAX)
            {
                for(auto i:adjlist[top])
                {
                    if(dist[i.first]>dist[top]+i.second)
                    {
                        dist[i.first]=dist[top]+i.second;
                    }
                }
            }
        }
    }

    void Dijkstra(priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>&pq,vector<int>&dist,unordered_map<int,bool>&visited)
    {
        while(!pq.empty())
        {
            pair<int,int>p = pq.top();
            pq.pop();
            visited[p.second]=1;

            for(auto i:adjlist[p.second])
            {
                if(!visited[i.first])
                {
                    visited[i.first]=1;
                }
                if(dist[i.first] > i.second + p.first)
                {
                    dist[i.first] = i.second + p.first;
                    pq.push(make_pair(dist[i.first],i.first));
                }
                
            }
        }

        
    }
};

int main()
{
    // graph<int> g;

    // int n,e,d;
    // cin>>n>>e>>d;
    // for(int i=0;i<e;i++)
    // {
    //     int u,v;
    //     cin>>u>>v;

    //     g.InsertEdge(u,v,d);
    // }

    // int dest,src;
    // cin>>src;
    // cin>>dest;
    // unordered_map<int,bool>visited;
    // unordered_map<int,int>parent;
    // stack<int>ans;
    // for(int i=0;i<n;i++)
    // {
    //     visited[i]=false;
    // }

    // g.shortest_path_bfs(visited,parent,src,dest,ans);

    // while(!ans.empty())
    // {
    //     cout<<ans.top()<<" ";
    //     ans.pop();
    // }







    newgraph ng;

    int n,e,d;
    cin>>n>>e>>d;
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;

        ng.InsertEdge(u,v,w,d);
    }

    int src;
    cin>>src;
    
    
    
    
    
    // vector<int>dist(n);
    // unordered_map<int,bool>visited;
    
    // stack<int>s;
    // for(int i=0;i<n;i++)
    // {
    //     visited[i]=false;
    //     dist[i]=INT_MAX;
    // }
    // ng.topoSort_dfs(visited,src,s);
    // ng.shortest_path_DAG(src,dist,s);

    // for(int i=0;i<n;i++)
    // {
    //     cout<<dist[i]<<" ";
    // }





    vector<int>dist(n);
    unordered_map<int,bool>visited;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
        dist[i]=INT_MAX;
    }

    dist[src] = 0;
    pq.push(make_pair(0,src));
    ng.Dijkstra(pq,dist,visited);

    for(int i=0;i<n;i++)
    {
        cout<<dist[i]<<" ";
    }

    return 0;
}