#include<iostream>
#include "bintree.h"
void inOrder(BinaryTreeNode<int>* root){
    if(!root) return;
    inOrder(root->left);
    cout << root -> data << " ";
    inOrder(root->right);
}

void preOrder(BinaryTreeNode<int> *root) {
	// Write your code here
    if(!root) return;
    cout << root-> data << " ";
    preOrder(root->left);
    preOrder(root->right);
}