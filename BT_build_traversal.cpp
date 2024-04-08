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



////////////////////////////////////    Binary Tree Build using Inorder and Preorder Traversal    ////////////////////////////////////



Node *solve1(Node *root, int in[],int pre[],int &preorderindex, int i,int j,int n)
{
    if(i>j || preorderindex>=n)
    {
        return NULL;
    }
    
    root = new Node(pre[preorderindex]);

    int x;
    for(x=i;x<=j;x++)
    {
        if(pre[preorderindex]==in[x])
        {
            break;
        }
    }

    preorderindex++;
    root->left = solve1(root->left,in,pre,preorderindex,i,x-1,n);
    root->right = solve1(root->right,in,pre,preorderindex,x+1,j,n);

    return root;
}

Node* in_pre_build(Node *root, int in[],int pre[],int n)
{
    int index=0;
    Node *ans = solve1(root,in,pre,index,0,n-1,n);
    return ans;
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



////////////////////////////////////    Binary Tree Build using Inorder and Postorder Traversal    ////////////////////////////////////



Node *solve2(Node *root, int in[],int post[],int &postorderindex, int i,int j,int n)
{
    if(i>j || postorderindex<0)
    {
        return NULL;
    }
    
    root = new Node(post[postorderindex]);

    int x;
    for(x=i;x<=j;x++)
    {
        if(post[postorderindex]==in[x])
        {
            break;
        }
    }

    postorderindex--;
    root->right = solve2(root->right,in,post,postorderindex,x+1,j,n);
    root->left = solve2(root->left,in,post,postorderindex,i,x-1,n);

    return root;
}

Node* in_post_build(Node *root, int in[],int post[],int n)
{
    int index=n-1;
    Node *ans = solve2(root,in,post,index,0,n-1,n);
    return ans;
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



/////////////////////////////////////////    Binary Tree Build using Levelorder Traversal    /////////////////////////////////////////



void buildFromLevelOrder(Node* &root) {
    queue<Node*> q;

    cout << "Enter data for root" << endl;
    int data ;
    cin >> data;
    root = new Node(data);
    
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << "Enter left Node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1) {
            temp -> left = new Node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right Node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1) {
            temp -> right = new Node(rightData);
            q.push(temp->right);
        }
    }
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









int main()
{

    Node *root = NULL;
    buildFromLevelOrder(root);
    cout<<endl<<"Inorder : ";
    inorder(root);





    // int n = 4;
    // int inorder[4] = {1,6,8,7};
    // int preorder[4] = {1,6,7,8};

    // Node *root = NULL;
    // root = in_pre_build(root,inorder,preorder,n);

    // cout<<endl<<"Postorder : ";
    // postorder(root);





    // int n = 5;
    // int inorder[5] = {9,5,2,3,4};
    // int postorder[5] = {5,9,3,4,2};

    // Node *root = NULL;
    // root = in_post_build(root,inorder,postorder,n);

    // cout<<endl<<"Preorder : ";
    // preorder(root);

    return 0;
}