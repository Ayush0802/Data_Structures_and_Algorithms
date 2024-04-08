#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    //constructor
    Node(int data) 
    {
        this -> data = data;
        this -> next = NULL;
    }

    //destructor
    ~Node() 
    {
        int value = this -> data;
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
    }
};

void Insert_at_Head(Node* &head,int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void Insert_at_Tail(Node* &head,int data)
{
    Node *temp = head;
    Node *n = new Node(data);
    while(1)
    {
        if(head->next==NULL)
        {
            head->next = n;
            break;
        }
        head = head->next;
    }
    head = temp;
}

void Insert_at_Position(Node* &head,int position,int data)
{
    if(position == 1)
    {
        Insert_at_Head(head,data);
        return;
    }
    Node *temp = head;
    Node *n = new Node(data);
    for(int i=1;i<position-1;i++)
    {
        temp = temp->next;
    }

    if(temp->next==NULL)
    {
        Insert_at_Tail(head,data);
        return;
    }
    n->next = temp->next;
    temp->next = n;
}

void deleteNode(Node *&head,int position)
{
    if(position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next  = NULL;
        delete curr; 
    }
}

void print(Node* &head)
{
    Node*temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int length(Node* &head)
{
    int len = 0;
    Node*temp = head;
    while(temp!=NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}


int main()
{
    Node *head = new Node(10);
    print(head);

    Insert_at_Head(head,15);
    Insert_at_Head(head,20);
    print(head);

    Insert_at_Position(head,4,2);
    Insert_at_Position(head,2,3);
    print(head);

    Insert_at_Tail(head,5);
    Insert_at_Tail(head,0);
    print(head);

    deleteNode(head,1);
    print(head);

    deleteNode(head,6);
    print(head);

    deleteNode(head,3);
    print(head);

    cout<<length(head)<<endl;

    return 0;
}