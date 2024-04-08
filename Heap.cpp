#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class heap
{
    public:
    int arr[100];
    int size;

    heap()
    {
        arr[0]=-1;
        size = 0;
    }

    void insertInMaxHeap(int value)
    {
        size++;
        int index =size;
        arr[index] = value;

        while(index>1)
        {
            int p =index/2;
            if(value > arr[p])
            {
                swap(arr[index],arr[p]);
                index = p;
            }
            else
            {
                return;
            }
        }
    }

    void insertInMinHeap(int value)
    {
        size++;
        int index =size;
        arr[index] = value;

        while(index>1)
        {
            int p =index/2;
            if(value < arr[p])
            {
                swap(arr[index],arr[p]);
                index = p;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for(int i=1;i<=size;i++)
        {
            cout<<arr[i]<<" ";
        }
    }

    void deleteFromMaxHeap()
    {
        if(size == 0)
        {
            cout<<"Sorry"<<endl;
            return;
        }

        arr[1]=arr[size];
        size--;

        int i=1;
        int leftIndex;
        int rightIndex;

        while(i<size)
        {
            leftIndex = 2*i;
            rightIndex = 2*i+1;

            if(leftIndex<size && arr[leftIndex]>arr[i])
            {
                swap(arr[leftIndex],arr[i]);
                i=leftIndex;
            }
            else if(rightIndex<size && arr[rightIndex]>arr[i])
            {
                swap(arr[rightIndex],arr[i]);
                i=rightIndex;
            }
            else
            {
                return;
            }
        }
    }

    void deleteFromMinHeap()
    {
        if(size == 0)
        {
            cout<<"Sorry"<<endl;
            return;
        }

        arr[1]=arr[size];
        size--;

        int i=1;
        int leftIndex;
        int rightIndex;

        while(i<size)
        {
            leftIndex = 2*i;
            rightIndex = 2*i+1;

            if(leftIndex<size && arr[leftIndex]<arr[i])
            {
                swap(arr[leftIndex],arr[i]);
                i=leftIndex;
            }
            else if(rightIndex<size && arr[rightIndex]<arr[i])
            {
                swap(arr[rightIndex],arr[i]);
                i=rightIndex;
            }
            else
            {
                return;
            }
        }
    }
};

void max_heapify(vector<int>&arr,int index,int n)
{
    int left=2*index+1;
    int right=2*index+2;
    int max=index;
    if(n>=left && arr[left]>arr[index])
    {
        max=left;
    }
    if(n>=right && arr[right]>arr[max])
    {
        max=right;
    }
    if(max!=index)
    {
        swap(arr[index],arr[max]);
        max_heapify(arr,max,n);
    }
}

void min_heapify(vector<int>&arr,int index,int n)
{
    int left=2*index+1;
    int right=2*index+2;
    int min=index;
    if(n>left && arr[left]<arr[index])
    {
        min=left;
    }
    if(n>right && arr[right]<arr[min])
    {
        min=right;
    }
    if(min!=index)
    {
        swap(arr[index],arr[min]);
        min_heapify(arr,min,n);
    }
}

void max_heap(vector<int>&array)
{
    int n = array.size();
    for(int i = n/2;i>=0;i--)
    {
        max_heapify(array,i,n);
    }
}

void min_heap(vector<int>&array)
{
    int n = array.size();
    for(int i = n/2;i>=0;i--)
    {
        min_heapify(array,i,n);
    }
}

void heapSort(vector<int>&array)
{
    max_heap(array);
    int s=array.size()-1;
    while(s>=0)
    {
        swap(array[0],array[s]);
        s--;
        max_heapify(array,0,s);
    }
}


int main()
{
    heap maxheap;
    maxheap.insertInMaxHeap(6);
    maxheap.insertInMaxHeap(5);
    maxheap.insertInMaxHeap(9);
    maxheap.insertInMaxHeap(2);
    maxheap.insertInMaxHeap(7);

    maxheap.print();
    maxheap.deleteFromMaxHeap();
    cout<<endl;
    maxheap.print();
    cout<<endl;

    heap minheap;
    minheap.insertInMinHeap(6);
    minheap.insertInMinHeap(5);
    minheap.insertInMinHeap(9);
    minheap.insertInMinHeap(2);
    minheap.insertInMinHeap(7);

    minheap.print();
    minheap.deleteFromMinHeap();
    cout<<endl;
    minheap.print();

    vector<int>arr = {1,3,2,4};

    cout<<endl;
    max_heap(arr);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl;
    min_heap(arr);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl;
    heapSort(arr);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }


    return 0;
}