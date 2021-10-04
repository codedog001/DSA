#include<iostream>
#include "tree.h"
using namespace std;

TreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter root Data " << endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    int n;
    cout << "Enter number of children: " << endl;
    cin >> n;
    
    for(int i=0; i<n; i++){
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printTree(TreeNode<int>* root){

    if(root == NULL) return; // --> Edge Case.
    //Above not a base case, just the edge case: Becuase, if a non-null node is given, this case will
    //run.

    cout << root->data << ": ";
    for(int i=0; i<root->children.size(); i++){
        cout << root -> children[i]->data << ", ";
    }
    cout << endl;
    for(int i=0; i<root->children.size(); i++){
        printTree(root->children[i]);
    }
}
int main(){
    // TreeNode<int>* root = new TreeNode<int>(1);

    // //Children of root
    // TreeNode<int>* c1 = new TreeNode<int>(2);
    // TreeNode<int>* c2 = new TreeNode<int>(3);

    // //Children of C1
    // TreeNode<int>* c11 = new TreeNode<int>(5);
    // TreeNode<int>* c12 = new TreeNode<int>(4);

    // //Children of C2
    // TreeNode<int>* c21 = new TreeNode<int>(6);
    // TreeNode<int>* c22 = new TreeNode<int>(7);
    // TreeNode<int>* c23 = new TreeNode<int>(8);

    // root->children.push_back(c1);
    // root->children.push_back(c2);

    // c1->children.push_back(c11);
    // c1->children.push_back(c12);
    // c2->children.push_back(c21);
    // c2->children.push_back(c22);

    TreeNode<int> * root = takeInput();
    printTree(root);
}