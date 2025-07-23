#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
    TreeNode*right;
    int data;
    TreeNode*left;
};

TreeNode* createNewNode(int gd){
	TreeNode* newNode;
    newNode= new TreeNode;
    newNode->data=gd;
    newNode->left= newNode->right = NULL;
    return  newNode;
}

//Recursive inOrder LCR
void inOrder(TreeNode* curr, vector<int>&v){
	if(curr==NULL) return;
    inOrder( curr->left,v);
    v.push_back(curr->data);
    inOrder(curr->right,v);
}
/*
//Recursive inOrder RCL
void inOrder(TreeNode* curr, vector<int>&v){
	if(curr==NULL) return;
    inOrder( curr->right,v);
    v.push_back(curr->data);
    inOrder(curr->left,v);
}
*/
//Recursive PreOrder CLR
void preOrder(TreeNode* root,vector<int>&v){
    if(root==NULL) return;
    v.push_back(root->data);
    preOrder(root->left,v);
    preOrder(root->right,v);
}
/*
//Recursive PreOrder CRL
void preOrder(TreeNode* root,vector<int>&v){
    if(root==NULL) return;
    v.push_back(root->data);
    preOrder(root->right,v);
    preOrder(root->left,v);
}
*/
//Recursive PostOrder LRC
void postOrder(TreeNode* root,vector<int>&v){
    if(root==NULL) return;
    postOrder(root->left,v);
    postOrder(root->right,v);
    v.push_back(root->data);
}
/*
//Recursive PostOrder RLC
void postOrder(TreeNode* root,vector<int>&v){
    if(root==NULL) return;
    postOrder(root->right,v);
    postOrder(root->left,v);
    v.push_back(root->data);
}
*/
int main(){
    TreeNode* root=createNewNode(10);
    root->left=createNewNode(20);
    root->right=createNewNode(30);
    root->left->left=createNewNode(40);
    root->left->right=createNewNode(50);
    root->right->left=createNewNode(60);
    root->right->right=createNewNode(70);
    vector<int>v;
    postOrder(root,v);
    for(int val:v){
        cout<<val<<" ";
    }
    return 0;
}
