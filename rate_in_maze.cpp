#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>>maze,vector<vector<int>>visited,vector<string>ans,string path,int n,int x,int y)
{
    if(x==n-1 && y==n-1)
    {
        cout<<path;
        ans.push_back(path);
        return;
    }

    visited[x][y]=1;

    int nx=x+1;
    int ny=y;
    if(nx>=0 && nx<n && ny>=0 && ny<n && maze[nx][ny]==1 && visited[nx][ny]==0)
    {
        path.push_back('D');
        solve(maze,visited,ans,path,n,nx,ny);
        path.pop_back();
    }

    nx=x-1;
    ny=y;
    if(nx>=0 && nx<n && ny>=0 && ny<n && maze[nx][ny]==1 && visited[nx][ny]==0)
    {
        path.push_back('U');
        solve(maze,visited,ans,path,n,nx,ny);
        path.pop_back();
    }

    nx=x;
    ny=y+1;
    if(nx>=0 && nx<n && ny>=0 && ny<n && maze[nx][ny]==1 && visited[nx][ny]==0)
    {
        path.push_back('R');
        solve(maze,visited,ans,path,n,nx,ny);
        path.pop_back();
    }

    nx=x;
    ny=y-1;
    if(nx>=0 && nx<n && ny>=0 && ny<n && maze[nx][ny]==1 && visited[nx][ny]==0)
    {
        path.push_back('L');
        solve(maze,visited,ans,path,n,nx,ny);
        path.pop_back();
    }

    visited[x][y]=0;
}

int main()
{
    int n;
    cin>>n;

    vector<vector<int>>maze(n);
    for(int i=0;i<n;i++)
    {
        maze[i] = vector<int>(n);
        for(int j=0;j<n;j++)
        {
            cin>>maze[i][j];
        }
    }

    if(maze[0][0]==0)
    {
        cout<<-1;
        exit(0);
    }

    vector<vector<int>>visited = maze;
    string path;
    vector<string>ans;

    solve(maze,visited,ans,path,n,0,0);

    int i=0;
    if(ans[0]=="")
    {
        cout<<-1;
        exit(0);
    }
    while(ans[i]!="\0")
    {
        cout<<ans[i]<<" ";
    }

    return 0;
}