#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Deque
{
    public:
        int *arr;
        int front;
        int rear;
        int size;

    Deque(int size)
    {
        this->size = size;
        front = -1;
        rear = -1;
        arr = new int[size];
    }

    void push_front(int element)
    {
        if((front==0 && rear==size-1) || (rear==(front-1)%(size-1)))
        {
            cout<<"Queue is Full"<<endl;
            return;
        }
        else if(front==-1)
        {
            front=rear=0;
        }
        else if(front==0 && rear!=size-1)
        {
            front = size-1;
        }
        else
        {
            front--;
        }
        arr[front]=element;
    }

    void push_back(int element)
    {
        if((front==0 && rear==size-1) || (rear==(front-1)%(size-1)))
        {
            cout<<"Queue is Full"<<endl;
            return;
        }
        else if(front==-1)
        {
            front=rear=0;
        }
        else if(rear==size-1 && front!=0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear]=element;
    }

    void pop_front()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty"<<endl;
            return;
        }
        
        arr[front] = -1;
        
        if(front == rear) 
        { 
            front = rear = -1;
        }
        else if(front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }

    void pop_back()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty"<<endl;
            return;
        }
        
        arr[rear] = -1;
        
        if(front == rear) 
        { 
            front = rear = -1;
        }
        else if(rear == 0) 
        {
            rear = size-1; 
        }
        else
        {
            rear--;
        }
    }

    bool isEmpty()
    {
        if(front == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int Front()
    {
        if(isEmpty())
        {
            return -1;
        }
        return arr[front];
    }

    int back()
    {
        if(isEmpty())
        {
            return -1;
        }
        return arr[rear];
    }
};

int main()
{
    Deque dq(6);
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);
    dq.push_front(40);
    dq.push_front(50);
    cout<<dq.Front()<<endl;
    cout<<dq.back()<<endl;
    dq.pop_back();
    dq.pop_front();
    cout<<dq.Front()<<endl;
    cout<<dq.back()<<endl;
    dq.pop_back();
    dq.pop_front();
    cout<<dq.Front()<<endl;
    cout<<dq.back()<<endl;
    dq.pop_back();
    dq.pop_front();
    cout<<dq.Front()<<endl;
    cout<<dq.back()<<endl;

    return 0;
}