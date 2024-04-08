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

void insertNode(Node* &tail, int element, int d) 
{
    
    if(tail == NULL) {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{

        Node* curr = tail;

        while(curr->data != element) {
            curr = curr -> next;
        }
        
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;

    }

}   

void deleteNode(Node* &tail, int value) 
{
    if(tail == NULL) 
    {
        cout << " List is empty, please check again" << endl;
        return;
    }
    else
    {
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != value) 
        {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;

        if(curr == prev) 
        {
            tail = NULL;
        }
        else if(tail == curr ) 
        {
            tail = prev;
        }

        curr -> next = NULL;
        delete curr;
    }
}

void print(Node* tail) 
{

    Node* temp = tail;

    //empty list
    if(tail == NULL) 
    {
        cout << "List is Empty "<< endl;
        return ;
    }

    do 
    {
        cout << tail -> data << " ";
        tail = tail -> next;
    } while(tail != temp);

    cout << endl;
} 

int length(Node* tail) 
{

    Node* temp = tail;
    int len=0;
    //empty list
    if(tail == NULL) 
    {
        return len;
    }

    do 
    {
        len++;
        tail = tail -> next;
    } while(tail != temp);

    return len;
} 

int main()
{
    Node* tail = NULL;

    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 5);
    print(tail);

    insertNode(tail, 5, 7);
    print(tail);

    insertNode(tail, 7, 9);
    print(tail);

    insertNode(tail, 5, 6);
    print(tail);
    
    insertNode(tail, 9, 10);
    print(tail);

    insertNode(tail, 3, 4);
    print(tail);

    deleteNode(tail, 3);
    print(tail);

    deleteNode(tail, 10);
    print(tail);

    deleteNode(tail, 6);
    print(tail);

    cout<<length(tail);

    return 0;
}