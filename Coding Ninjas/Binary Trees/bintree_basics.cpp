#include<iostream>
#include "binTree.h"
using namespace std;
#include<queue>


// Valid binary tree (level wise): 1 2 3 4 -1 5 -1 -1 -1 -1 -1

int countNodes(BinaryTreeNode<int>* root){
    int ans = 0;
    if(!root) return 0;
    int left = countNodes(root->left);
    int right = countNodes(root->right);
    return 1+left+right;
}



void printTree(BinaryTreeNode<int>* root){
    cout << root -> data << " ";
    if(root->left) printTree( root -> left );
    if(root -> right) printTree( root -> right );
}

void printLevelWise(BinaryTreeNode<int>* root){
    if(!root) return;
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << front -> data << " ";
        if(front -> left) pendingNodes.push(front->left);
        if(front-> right) pendingNodes.push(front -> right);
    }
}

BinaryTreeNode<int>* takeInputLevelWise(){
    cout << "Enter root data or -1 if NULL" << endl;
    int rootData;
    cin >> rootData;
    if(rootData == -1) return NULL;
    BinaryTreeNode<int> * root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BinaryTreeNode<int> * front = pendingNodes.front();
        pendingNodes.pop();

        int childLeft;
        cout << "Enter left child of " << front->data << endl;
        cin >> childLeft;
        BinaryTreeNode<int> * childNodeLeft = NULL,* childNodeRight = NULL;
        if(childLeft != -1) {
            childNodeLeft = new BinaryTreeNode<int>(childLeft);
            pendingNodes.push(childNodeLeft);
        }

        cout << "Enter right child of " << front->data << endl;
        int childRight;
        cin >> childRight;
        if(childRight != -1) {
            childNodeRight = new BinaryTreeNode<int>(childRight);
            pendingNodes.push(childNodeRight);
        }
        front->left = childNodeLeft;
        front->right = childNodeRight;
    }
    return root;

}
BinaryTreeNode<int>* takeInput(){

    cout << "Enter root data or -1 if NULL" << endl;
    int rootData;
    cin >> rootData;
    if(rootData == -1) return NULL;
    BinaryTreeNode<int> * root = new BinaryTreeNode<int>(rootData);
    
    cout << "Enter left of " << rootData << endl;
    root-> left = takeInput();

    cout << "Enter right of " << rootData << endl;
    root -> right = takeInput();
    
    return root;
}

int main(){ 
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* c1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* c2 = new BinaryTreeNode<int>(3);

    root->left = c1;
    root->right = c2;

    BinaryTreeNode<int>* c3 = new BinaryTreeNode<int>(4);
    c1->left = c3;
    BinaryTreeNode<int> *r1 = takeInputLevelWise();

    cout << "Level Wise Output: ";
    printLevelWise(r1);
    cout << endl;

    cout << "No. of nodes: " << countNodes(r1) << endl;
}

// Valid binary tree (level wise): 1 2 3 4 -1 5 -1 -1 -1 -1 -1