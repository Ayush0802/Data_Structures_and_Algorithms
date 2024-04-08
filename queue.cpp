#include <iostream>
#include <queue>
using namespace std;

class Queue
{
    public:
        int *arr;
        int front;
        int rear;
        int size;

    Queue(int size)
    {
        this->size=size;
        front = 0;
        rear = 0;
        arr = new int[size];
    }

    void push(int element)
    {
        if(size>rear)
        {
            arr[rear++]=element;
        }
        else
        {
            cout<<"Queue is Full"<<endl;
        }
    }

    void pop()
    {
        if(front!=rear)
        {
            arr[front++]=-1;
            if(front==rear)
            {
                front = 0;
                rear = 0;
            }
        }
        else
        {
            front = 0;
            rear = 0;
            cout<<"Queue is already Empty"<<endl;
        }
    }

    bool isEmpty()
    {
        if(front==rear)
        {
            front = 0;
            rear = 0;
            return true;
        }
        else
        {
            return false;
        }
    }

    int first()
    {
        if(front!=rear)
            return arr[front];
        else
            return -1;   
    }

    int back()
    {
        if(front!=rear)
            return arr[rear-1];
        else
            return -1;
    }
};

int main()
{
    Queue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    cout<<q.back()<<endl;
    cout<<q.first()<<endl;
    q.pop();
    cout<<q.back()<<endl;
    cout<<q.first()<<endl;
    q.pop();
    q.pop();
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    cout<<q.back()<<endl;
    cout<<q.first()<<endl;
    return 0;
}