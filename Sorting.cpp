#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
void Selection_sort(vector<int>&arr,int n)     // Time Complexity = O(n2)
{                                              // Space Complexity = O(1)
    for(int i = 0;i < n;i++)
    {
        int min_index = i;
        for(int j=i;j<n;j++)
        {
            if(arr[j]<arr[min_index])
            {
                min_index = j;
            }
        }
        swap(arr[i],arr[min_index]);
    }
}





void Bubble_sort(vector<int>& arr, int n)     // Time Complexity = O(n2)
{                                             // Space Complexity = O(1)
    for(int i=0;i<n;i++)
    {
        bool swapped = false;
        for(int j=0;j<n-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false)
        { 
            break;
        }
    }
}





void Insertion_sort(vector<int>& arr, int n)     // Time Complexity = O(n2) -> Worst, O(n) -> Best
{                                                // Space Complexity = O(1)
    for(int i=1;i<n;i++)
    {
        int temp = arr[i];
        int j;
        for(j=i-1;j>=0;j--)
        {
            if(arr[j]>temp)
            {
                arr[j+1]=arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j+1] = temp;
    }
}





void Merge(vector<int>&arr,int s, int e)
{
    // int inv = 0;

    int mid = (s+e)/2;

    int l1 = mid-s+1;
    int l2 = e-mid;

    int *arr1 = new int[l1];
    int *arr2 = new int[l2];

    int temp=s;
    for(int i=0;i<l1;i++)
    {
        arr1[i]=arr[temp++];
    }

    temp=mid+1;
    for(int i=0;i<l2;i++)
    {
        arr2[i]=arr[temp++];
    }

    int ind1=0;
    int ind2=0;
    int main_ind=s;

    while(ind1<l1 && ind2<l2)
    {
        if(arr1[ind1]<arr2[ind2])
        {
            arr[main_ind++]=arr1[ind1++];
        }
        else
        {
            // inv+=l1-ind1;
            arr[main_ind++]=arr2[ind2++];
        }
    }

    while(ind1<l1)
    {
        arr[main_ind++]=arr1[ind1++];
    }

    while(ind2<l2)
    {
        arr[main_ind++]=arr2[ind2++];
    }

    delete []arr1;
    delete []arr2;

    // return inv;

}

void Merge_sort(vector<int>&arr,int s,int e)     // Time Complexity = O(nlog(n)) -> Best & Worst 
{                                                // Space Complexity = O(n)
    // int inv = 0;
    
    if(e<=s)
    {
        return;
        // return 0;
    }

    int mid = (s+e)/2;

    Merge_sort(arr,s,mid);
    Merge_sort(arr,mid+1,e);
    Merge(arr,s,e);

    // inv+=Merge_sort(arr,s,mid);
    // inv+=Merge_sort(arr,mid+1,e);
    // inv+=Merge(arr,s,e);
    
    // return inv;
}





int partition(vector<int>&arr,int s,int e)
{
    int pivot = arr[s];

    int count=0;
    for(int i=s+1;i<=e;i++)
    {
        if(arr[i]<=pivot)
        {
            count++;
        }
    }

    int pivot_index = s + count;
    swap(arr[pivot_index],arr[s]);

    int i=s,j=e;

    while(i<pivot_index && j>pivot_index)
    {
        while(arr[i]<=pivot)
        {
            i++;
        }

        while(arr[j]>pivot)
        {
            j--;
        }

        if(i<pivot_index && j>pivot_index)
        {
            swap(arr[i++],arr[j--]);
        }
    }

    return pivot_index;
}

void Quick_sort(vector<int>& arr,int s,int e)     // Time Complexity = O(nlogn) -> Best & Average; O(n2) -> Worst
{                                                 // Space Complexity = O(n)
    if(e<=s)
    {
        return;
    }

    int p = partition(arr,s,e);

    Quick_sort(arr,s,p-1);
    Quick_sort(arr,p+1,e);
}





void Count_sort(vector<int>&arr,int n)     // Time Complexity = O(n+k)
{                                          // Space Complexity = O(n+k)
    int k=arr[0];                          // It cannot be used for negative and decimal point values
    for(int i=0;i<n;i++)
    {
        k=max(k,arr[i]);
    }

    int count[k+1] = {0};

    for(int i=0;i<n;i++)
    {
        count[arr[i]]++;
    }

    for(int i=1;i<=k;i++)
    {
        count[i]+=count[i-1];
    }

    int output[n];
    for(int i=n-1;i>=0;i--)
    {
        output[--count[arr[i]]]=arr[i];
    }

    for(int i=0;i<n;i++)
    {
        arr[i]=output[i];
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

    // Selection_sort(arr,n);
    // Bubble_sort(arr,n);
    // Insertion_sort(arr,n);
    // Merge_sort(arr,0,n-1);
    // Quick_sort(arr,0,n-1);
    // Count_sort(arr,n);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}