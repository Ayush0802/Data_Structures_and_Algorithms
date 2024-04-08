#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pi 3.14
inline int func()
{
    
}
int main()
{
    int n;
    cin>>n;

    // 1D ARRAY
    int *arr = new int[n];     // Good practice to make variable size array
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    delete []arr;

    // 2D ARRAY
    int row,col;
    cin>>row>>col;

    int **array = new int*[row];
    for(int i=0;i<row;i++)
    {
        array[i]= new int[col];
    } 
    return 0;

    for(int i=0;i<row;i++)
    {
        delete []array[i];
    }
    delete []array;
}