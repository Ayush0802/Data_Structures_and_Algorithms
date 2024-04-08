// Time Complexity of Binary Search is O(logN)

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int>arr,int low,int high,int s)
{
    int mid = low+(high-low)/2;

    if(low>high)
    {
        return -1;
    }
    else
    {
        if(arr[mid]==s)
        {
            return mid;
        }
        else if(arr[mid]>s)
        {
            return binary_search(arr,low,mid-1,s);
        }
        else
        {
            return binary_search(arr,mid+1,high,s);
        }
    }

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

    int search;
    cin>>search;

    sort(arr.begin(),arr.end());

    int output;
    output = binary_search(arr,0,n-1,search);
    cout<<output;

    return 0;
}


// int search(vector<int>& arr, int n, int k)
// {
//     int s = 0;
//     int e = n-1;
//     int mid = s + (e-s)/2;

//     while(s<e)
//     {
//         if(arr[mid]>=arr[0])
//         {
//             s = mid+1;
//         }
//         else
//         {
//             e = mid;
//         }
//         mid = s+(e-s)/2;
//     }

//     if(k>=arr[s] && k<=arr[n-1])
//     {
//         int s1 = s;
//         int e1 = n-1;
//         int mid1 = s1+(e1-s1)/2;

//         while(s1 <= e1) 
//         {

//             if(arr[mid1] == k) 
//             {
//                 return mid1;
//             }

//             if(k > arr[mid1]) 
//             {
//                 s1 = mid1 + 1;
//             }
//             else
//             {
//                 e1 = mid1 - 1;
//             }

//             mid1 = s1 + (e1-s1)/2;
//         }
//         return -1;
//     }
//     else
//     {
//         int s2 = 0;
//         int e2 = s-1;
//         int mid2 = s2+(e2-s2)/2;

//         while(s2 <= e2) 
//         {

//             if(arr[mid2] == k) 
//             {
//                 return mid2;
//             }

//             if(k > arr[mid2]) 
//             {
//                 s2 = mid2 + 1;
//             }
//             else
//             {
//                 e2 = mid2 - 1;
//             }

//             mid2 = s2 + (e2-s2)/2;
//         }
//         return -1;
//     }
// }
