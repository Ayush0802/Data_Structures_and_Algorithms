#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int stairs(int n)
{
    if(n<0)
    {
        return 0;
    }
    if(n==0)
    {
        return 1;
    }
    
    int count = stairs(n-1)+ stairs(n-2);
    return count;
}
int main()
{
    int n;
    cin>>n;

    int ans = stairs(n);
    cout<<ans;
    return 0;
}