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

Node *buildTree(Node *root)
{
    cout << "Enter the data: " ;
    int data;
    cin >> data;
    root = new Node(data);    

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void level_order_traversal(Node *root)
{
    queue<Node*>qq;
    qq.push(root);
    qq.push(NULL);

    while(!qq.empty())
    {
        Node *temp = qq.front();
        qq.pop();

        if(temp==NULL)
        {
            cout<<endl;
            if(!qq.empty())
            {
                qq.push(NULL);
            }
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left)
            {
                qq.push(temp->left);
            }

            if(temp->right)
            {
                qq.push(temp->right);
            }
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

void morris(Node *root)
{
    if(root == NULL)
    {
        return;
    }

    Node *curr = root;
    Node *pre;

    while(curr!=NULL)
    {
        if(curr->left==NULL)
        {
            cout<<curr->data<<" ";
            curr = curr->right;
        }
        else
        {
            pre = curr->left;
            while(pre->right!=NULL && pre->right!=curr)
            {
                pre=pre->right;
            }

            if(pre->right==NULL)
            {
                pre->right = curr;
                curr = curr->left;
            }
            else
            {
                pre->right = NULL;
                cout<<curr->data<<" ";
                curr = curr->right;
            }
        }
    }

    
}

 int height(Node *root)
 {
    if(root==NULL)
    {
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left,right)+1;

    return ans;
    // int count = 1;
    // queue<Node*>qq;
    // qq.push(root);
    // qq.push(NULL);

    // while(!qq.empty())
    // {
    //     Node *temp = qq.front();
    //     qq.pop();

    //     if(temp==NULL)
    //     {
    //         if(!qq.empty())
    //         {
    //             qq.push(NULL);
    //             count++;
    //         } 
    //     }
    //     else
    //     {
    //         if(temp->left)
    //         {
    //             qq.push(temp->left);
    //         }

    //         if(temp->right)
    //         {
    //             qq.push(temp->right);
    //         }
    //     }  
    // }
    // return count;
 }

 int diameter(Node *root)
 {
    if(root == NULL)
    {
        return 0;
    }
    int d1 = diameter(root->left);
    int d2 = diameter(root->right);
    int d3 = height(root->left)+1+height(root->right);

    return max(d1,max(d2,d3));
 }

 void check_balance(Node *root,bool &ans)
 {
    if(root == NULL)
    {
        return;
    }

    check_balance(root->left,ans);
    check_balance(root->right,ans);

    int h1 = height(root->left);
    int h2 = height(root->right);

    if(abs(h1-h2)>1)
    {
        ans = false;
    }
 }

 bool checkBalance(Node * root)
 {
    bool ans = true;
    check_balance(root,ans);
    if(ans==true)
    {
        return true;
    }
    else
    {
        return false;
    }
 }

 pair<bool,int> isSumTree(Node *root)
 {
    if(root == NULL)
    {
        pair<bool,int>temp = make_pair(true,0);
        return temp;
    }

    if(root->left == NULL && root->right == NULL)
    {
        pair<bool,int>temp = make_pair(true,root->data);
        return temp;
    }

    pair<bool,int> left = isSumTree(root->left);
    pair<bool,int> right = isSumTree(root->right);

    bool leftbool = left.first;
    bool rightbool = right.first;

    int leftint = left.second;
    int rightint = right.second;

    bool cond = false;
    if(root->data == leftint+rightint)
    {
        cond = true;
    }

    pair<bool,int> ans;

    if(leftbool && rightbool && cond)
    {
        ans.first = true;
        ans.second = root->data + leftint + rightint;
    }
    else
    {
        ans.first = false;
        ans.second = root->data + leftint + rightint;
    }
    return ans;
 }

int main()
{
    // 1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1
    /*
            1
           / \
         2     5
        / \   / \
       3   4 6   7

    */
    Node *root = NULL;
    root = buildTree(root);
    
    cout<<endl<<"Level Order Traversal : "<<endl;
    level_order_traversal(root);
    
    cout<<"Inorder Traversal: ";
    inorder(root);
    
    cout<<endl<<"Preorder Traversal: ";
    preorder(root);
    
    cout<<endl<<"Postorder Traversal: ";
    postorder(root);

    cout<<endl<<"Morris Traversal: ";
    morris(root);

    cout<<endl<<"Height : ";
    cout<<height(root);

    cout<<endl<<"Diameter : ";
    cout<<diameter(root);

    cout<<endl<<"Check Balance of the Tree : ";
    cout<<checkBalance(root);

    cout<<endl<<"Check Sum Tree : ";
    cout<<isSumTree(root).first;

    

    return 0;
}