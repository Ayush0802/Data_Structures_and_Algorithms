#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void subset(vector<vector<int>>&ans,vector<int>arr,vector<int>output,int index)
{
    if(index>=arr.size())
    {
        ans.push_back(output);
        return;
    }

    subset(ans,arr,output,index+1);

    int element = arr[index];
    output.push_back(element);
    // cout<<output[0];
    subset(ans,arr,output,index+1);
    
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int index=0;
    vector<int>output;
    vector<vector<int>>ans;
    subset(ans,arr,output,index);

    int i=0;
    while(i<2^n)
    {
        int j=0;
        while(j<end(ans[i])-begin(ans[i]))
        {
            cout<<ans[i][j];
            j++;
        }
        cout<<" ";
        i++;
    }

    return 0;
}