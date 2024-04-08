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

    void printAdjlist()
    {
        for(auto i:adjlist)
        {
            cout<<i.first<<"->";
            for(auto j:i.second)
            {
                cout<<j<<",";
            }
            cout<<endl;
        }
    }

    void bfs(unordered_map<int,bool>&visited,int node,vector<int>&ans)
    {
        queue<int>q;
        q.push(node);
        visited[node]=1;

        while(!q.empty())
        {   
            int frontNode = q.front();
            q.pop();

            ans.push_back(frontNode);

            for(auto i:adjlist[frontNode])
            {
                if(!visited[i])
                {
                    q.push(i);
                    visited[i]=1;
                }
            }
        }
    }

    void dfs(unordered_map<int,bool>&visited,int node,vector<int>&ans)
    {
        ans.push_back(node);
        visited[node] = 1;

        for(auto i:adjlist[node])
        {
            if(!visited[i])
            {
                dfs(visited,i,ans);
            }
        }
    }
};

int main()
{
    // Creation
    graph<int> g;
    


    // Insertion
    int n,e,d;
    cin>>n>>e>>d;
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;

        g.InsertEdge(u,v,d);
    }



    // Printing
    cout<<endl;
    g.printAdjlist();



    // BFS (Breadth First Search)
    unordered_map<int,bool>visited;
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    vector<int>ans_bfs;
    for(int i=0;i<n;i++)      // used basically for disconnected graph
    {
        if(!visited[i])
        {
            g.bfs(visited,i,ans_bfs);
        }
    }
    cout<<endl;
    for(int i=0;i<ans_bfs.size();i++)
    {
        cout<<ans_bfs[i]<<" ";
    }
    


    // DFS (Depth First Search)
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    vector<vector<int>>ans_dfs;
    for(int i=0;i<n;i++)      // used basically for disconnected graph
    {
        if(!visited[i])
        {
            vector<int>component;
            g.dfs(visited,i,component);
            ans_dfs.push_back(component);
        }
    }
    cout<<endl<<endl;
    for(int i=0;i<ans_dfs.size();i++)
    {
        for(int  j=0;j<ans_dfs[i].size();j++)
        {
            cout<<ans_dfs[i][j]<<" ";
        }
    }



    // int adjMat[n + 1][n + 1] = {0};
    // for (int i = 0; i < e; i++) {
    //     int u, v;
    //     cin >> u >> v;
    //     if(d==0)
    //     {
    //         adjMat[u][v] = 1;
    //         adjMat[v][u] = 1;
    //     }
    //     else
    //     {
    //         adjMat[u][v] = 1;
    //     }
    // }

    // for(int i=0;i<n;i++)
    // {
    //     cout<<i<<"->";
    //     for(int j=0;j<n;j++)
    //     {
    //         if(adjMat[i][j]==1)
    //         {
    //             cout<<j<<",";
    //         }     
    //     }
    //     cout<<endl;
    // }
    
    return 0;
}