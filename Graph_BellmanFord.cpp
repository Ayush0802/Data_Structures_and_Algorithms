#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int BellmanFord(int src,int dest,vector<vector<int>>graph,int n)
{
    vector<int>dist(n+1,INT_MAX);
    dist[src]=0;

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<graph.size();j++)
        {
            int u = graph[j][0];
            int v = graph[j][1];
            int w = graph[j][2];

            if(dist[u]!=INT_MAX && (dist[v]>dist[u]+w))
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    bool count = false;
    for(int i=0;i<graph.size();i++)
    {
        int u = graph[i][0];
        int v = graph[i][1];
        int w = graph[i][2];

        if(dist[u]!=INT_MAX && (dist[v]>dist[u]+w))
        {
            dist[v] = dist[u] + w;
            count = true;
        }
    }

    if(count != true)
    {
        return dist[dest];
    }
    else
    {
        return INT_MAX;
    }
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

    int src,dest;
    cin>>src>>dest;

    int ans = BellmanFord(src,dest,graph,n);
    if(ans == INT_MAX)
    {
        cout<<"Graph contains a negative cycle."<<endl;
    }
    else
    {
        cout<<ans;
    }


    
    return 0;
}