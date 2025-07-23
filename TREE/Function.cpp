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
//count Nodes
int countNodes(TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
//count leaves Nodes
int countLeaves(TreeNode* root){
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL)
        return 1;
    return countLeaves(root->left)+countLeaves(root->right);
}
//count Nonleaves Nodes
int countNonLeaves(TreeNode* root){
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL)
        return 0;
    return countNonLeaves(root->left)+countNonLeaves(root->right)+1;
}
//Height by edges
int HeightByEdges(TreeNode* root){
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL)
        return 0;
    return max(HeightByEdges(root->left),HeightByEdges(root->right)) +1;
}
//Height by nodes or Maximum Depth of a tree
int HeightByNodes(TreeNode* root) {
    if (root == NULL) return 0; 
    return 1 + max(HeightByNodes(root->left), HeightByNodes(root->right));
}
//minimum Depth of a tree
int minDepth(TreeNode* root){
    if(root==NULL) return 0;
    if(!root->left) return 1+minDepth(root->right);
    if(!root->right) return 1+minDepth(root->left);
    return 1+ min(minDepth(root->left),minDepth(root->right));
}

//DFS
int maxHeight=0;
int dfs(TreeNode*root){
    if(!root) return 0;
    int leftHeight=dfs(root->left);
    int rightHeight=dfs(root->right);
    maxHeight= max(maxHeight,leftHeight+rightHeight);
    return max(leftHeight,rightHeight)+1;
}
//DiameterOfBinaryTree
int diameterOfBinaryTree(TreeNode* root) {
    dfs(root);
    return maxHeight;
}

int main(){
    TreeNode* root=createNewNode(10);
    root->left=createNewNode(20);
    root->right=createNewNode(30);
    root->left->left=createNewNode(40);
    root->left->right=createNewNode(50);
    root->right->left=createNewNode(60);
    root->right->right=createNewNode(70);
    cout<<"Count of Nodes: "<<countNodes(root)<<endl;
    cout<<"Count of leaves Node: "<<countLeaves(root)<<endl;
    cout<<"Count of Non-leaves Node: "<<countNonLeaves(root)<<endl;
    cout<<"Count of Height By Edges: "<<HeightByEdges(root)<<endl;
    cout<<"Count of Height By Nodes: "<<HeightByNodes(root)<<endl;
    cout<<"Minimum Depth of a tree: "<<minDepth(root)<<endl;
    cout<<"Diameter of a tree: "<<diameterOfBinaryTree(root)<<endl;
    return 0;
}
