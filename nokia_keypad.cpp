#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

void pk(vector<string>&ans,string output,string num,int index)
{
    if(index>=num.length())
    {
        ans.push_back(output);
        return;
    }

    for(int i=0;i<3;i++)
    {
        int n = num[index]-'0';
        output.push_back(char(97+3*(n-2)+i));
        pk(ans,output,num,index+1);
        output.pop_back();
    }
}

int main()
{
    string s;
    cin>>s;
    int index=0;
    string output;
    vector<string>ans;

    if(s.length()==0)
    {
        cout<<" ";
        exit(0);
    }
    
    pk(ans,output,s,index);


    int i=0;
    while(i<pow(3,s.length()))
    {
        int j=0;
        while(j<s.length())
        {
            cout<<ans[i][j];
            j++;
        }
    
        cout<<" ";
        i++;
    }

    return 0;
}