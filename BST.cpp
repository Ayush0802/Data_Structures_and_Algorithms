#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *InsertIntoBST(Node *root,int data)
{
    if(root == NULL)
    {
        root = new Node(data);
    }
    else
    {
        if(data<root->data)
        {
            root->left = InsertIntoBST(root->left,data);
        }
        else
        {
            root->right = InsertIntoBST(root->right,data);
        }
    }
    return root;
}
   
void inorder(Node* root) 
{
    if(root == NULL) 
    {
        return ;
    }

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);
}

void preorder(Node* root) 
{
    if(root == NULL) 
    {
        return ;
    }

    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) 
{
    if(root == NULL) 
    {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";
}

bool search(Node *root,int target)
{
    if(root==NULL)
    {
        return false;
    }
    else
    {
        if(root->data==target)
        {
            return true;
        }
        else if(target<root->data)
        {
            return search(root->left,target);
        }
        else
        {
            return search(root->right,target);
        }
    }
}

int minValue(Node *root)
{
    while(root->left!=NULL)
    {
        root = root->left;
    }
    return root->data;
}

int maxValue(Node *root)
{
    while(root->right!=NULL)
    {
        root = root->right;
    } 

    return root->data;
}

Node *deleteFromBST(Node *root, int value)
{
    if(root==NULL)
    {
        return root;
    }

    if(root->data == value)
    {
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        if(root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        if(root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if(root->left != NULL && root->right != NULL)
        {
            int min = minValue(root->right);
            root->data = min;
            root->right = deleteFromBST(root->right,min);
            return root;
        }
    }
    else if(root->data>value)
    {
        root->left = deleteFromBST(root->left,value);
        return root;
    }
    else
    {
        root->right = deleteFromBST(root->right,value);
        return root;
    }
}

int main()
{
    Node *root = NULL;
    cout<< "Enter BST Values : ";
    int data;
    cin>>data;

    while(data!=-1)
    {
        root = InsertIntoBST(root,data);
        cin>>data;
    }

    cout<<"Inorder Traversal: ";
    inorder(root);
    
    cout<<endl<<"Preorder Traversal: ";
    preorder(root);
    
    cout<<endl<<"Postorder Traversal: ";
    postorder(root);

    int target ;
    cout<<endl<<"Enter the number you want to search :";
    cin>>target;
    if(search(root,target))
    {
        cout<<target<<" is present in the BST";
    }
    else
    {
        cout<<target<<" is not present in the BST";
    }

    cout<<endl<<"Max Value : "<<maxValue(root);
    cout<<endl<<"Min Value : "<<minValue(root);

    int del;
    cout<<endl<<"Enter the number you want to delete : ";
    cin>>del;
    root = deleteFromBST(root,del);

    cout<<"Inorder Traversal: ";
    inorder(root);

    return 0;
}