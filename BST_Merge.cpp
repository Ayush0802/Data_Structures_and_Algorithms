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

void mergeSortedArray(vector<int>&arr1,vector<int>&arr2,vector<int>&ans)
{
    int i=0;
    int j=0;

    while(i<arr1.size() && j<arr2.size())
    {
        if(arr1[i]<arr2[j])
        {
            ans.push_back(arr1[i++]);
        }
        else
        {
            ans.push_back(arr2[j++]); 
        }
    }

    while(i<arr1.size())
    {
        ans.push_back(arr1[i++]);
    }

    while(j<arr2.size())
    {
        ans.push_back(arr2[j++]);
    }

}

void inorder(Node* root,vector<int>&arr) 
{
    if(root == NULL) 
    {
        return ;
    }

    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}

void inorder1(Node* root) 
{
    if(root == NULL) 
    {
        return ;
    }

    inorder1(root->left);
    cout << root-> data << " ";
    inorder1(root->right);
}

Node *inorderToBST(int s,int e,vector<int>mergeInorder)
{
    if(s>e)
    {
        return NULL;
    }
    
    int mid = (s+e)/2;
    Node * root = new Node(mergeInorder[mid]);
    root->left = inorderToBST(s,mid-1,mergeInorder);
    root->right = inorderToBST(mid+1,e,mergeInorder);

    return root;
}

Node *mergeBST(Node *root1,Node *root2)
{
    vector<int>inorder1;
    vector<int>inorder2;
    vector<int>mergedInoder(inorder1.size()+inorder2.size());

    inorder(root1,inorder1);
    inorder(root2,inorder2);

    mergeSortedArray(inorder1,inorder2,mergedInoder);

    int s = 0;
    int e = mergedInoder.size() - 1;

    return inorderToBST(s,e,mergedInoder);
}

int main()
{
    Node *root1 = NULL;
    cout<< "Enter 1st BST Values : ";
    int data;
    cin>>data;

    while(data!=-1)
    {
        root1 = InsertIntoBST(root1,data);
        cin>>data;
    }

    Node *root2 = NULL;
    cout<< "Enter 2nd BST Values : ";
    cin>>data;

    while(data!=-1)
    {
        root2 = InsertIntoBST(root2,data);
        cin>>data;
    }

    Node *root = NULL;
    root = mergeBST(root1,root2);

    inorder1(root);
    return 0;
}