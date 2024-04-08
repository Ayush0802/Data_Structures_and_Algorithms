#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin >> t;

    while (t--) 
    {
        int n,k;
        cin>>n>>k;

        vector<int>arr(n);
        int mul = 1;
        int ans = 5;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i]%k==0)
            {
                ans=0;
            }
            if(arr[i]>k)
            {
                ans = min(ans,k-arr[i]%k);
            }
            else
            {
                ans = min(ans, k-arr[i]%k);
            }
            mul *=arr[i];
        }
        cout<<ans<<endl;
        // sort(arr.begin(),arr.end());
        // int ans1=0;
        // int ans2=0;
        // int temp = k;
        // while(k>1)
        // {
        //     if(mul%k!=0)
        //     {
        //         k--;
        //         ans1++;
        //     }
        //     else{
        //         break;
        //     }
        // }
        // while(k<=5)
        // {
        //     if(mul%k!=0)
        //     {
        //         k++;
        //         ans2++;
        //     }
        //     else{
        //         break;
        //     }
        // }

        // cout<<min(ans1,ans2)<<endl;
    }

    return 0;
}
