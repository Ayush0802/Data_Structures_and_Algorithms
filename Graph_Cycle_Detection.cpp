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

    bool iscyclic_bfs(unordered_map<int,bool>&visited,int src)
    {
        unordered_map<int,int>parent;

        parent[src]=-1;
        queue <int> q;
        q.push(src);
        visited[src]=1;

        while(!q.empty())
        {   
            int frontNode = q.front();
            q.pop();

            for(auto i:adjlist[frontNode])
            {
                if(!visited[i])
                {
                    q.push(i);
                    visited[i]=1;
                    parent[i]=frontNode;
                }
                else if(visited[i]==1 && i!=parent[frontNode])
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool iscyclic_dfs(unordered_map<int,bool>&visited,int src,unordered_map<int,int>&parent)
    {
        visited[src] = 1;

        for(auto i:adjlist[src])
        {
            if(!visited[i])
            {
                parent[i]=src;
                return iscyclic_dfs(visited,i,parent);   
            }
            else if(visited[i]==1 && i!=parent[src])
            {
                return true;
            }
        }
        return false;
    }

    bool iscyclic_directed_dfs(unordered_map<int,bool>&visited,int src,unordered_map<int,bool>&dfs_visited)
    {
        visited[src] = 1;
        dfs_visited[src] = 1;

        for(auto i:adjlist[src])
        {
            if(!visited[i])
            {
                bool detect = iscyclic_directed_dfs(visited,i,dfs_visited);   
                if(detect)
                {
                    return true;
                }
            }
            else if(visited[i]==1 && dfs_visited[i]==1)
            {
                return true;
            }
        }

        dfs_visited[src]=0;
        return false;
    }

    bool iscyclic_directed_bfs_kahn(int &ans,int n)
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

            ans++;
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

    unordered_map<int,bool>visited;
    string ans;





    // // Cycle Detection Through DFS
    // for(int i=0;i<n;i++)
    // {
    //     visited[i]=false;
    // }
    // ans = "Acyclic";
    // for(int i=0;i<n;i++)      // used basically for disconnected graph
    // {
    //     if(!visited[i])
    //     {
    //         if(g.iscyclic_bfs(visited,i))
    //         {
    //             ans = "Cyclic";
    //         }
    //     }
    // }
    // cout<<ans<<endl;





    // // Cycle Detection Through DFS
    // unordered_map<int,int>parent;
    // for(int i=0;i<n;i++)
    // {
    //     visited[i]=false;
    // }
    // ans = "Acyclic";
    // for(int i=0;i<n;i++)      // used basically for disconnected graph
    // {
    //     if(!visited[i])
    //     {
    //         parent[i]=-1;
    //         if(g.iscyclic_dfs(visited,i,parent))
    //         {
    //             ans = "Cyclic";
    //         }
    //     }
    // }
    // cout<<ans<<endl;





    // // Cycle Detection Through DFS for directed graph
    // unordered_map<int,bool>dfs_visited;
    // for(int i=0;i<n;i++)
    // {
    //     visited[i]=false;
    //     dfs_visited[i]=false;
    // }
    // ans = "Acyclic";
    // for(int i=0;i<n;i++)      // used basically for disconnected graph
    // {
    //     if(!visited[i])
    //     {
    //         if(g.iscyclic_directed_dfs(visited,i,dfs_visited))
    //         {
    //             ans = "Cyclic";
    //         }
    //     }
    // }
    // cout<<ans<<endl;





    // // Cycle Detection Through BFS for directed graph
    // ans = "Acyclic";
    // int count = 0;
    // g.iscyclic_directed_bfs_kahn(count,n);
    // if(count != n)
    // {
    //     ans = "Cyclic";
    // }
    // cout<<ans<<endl;

    return 0;
}