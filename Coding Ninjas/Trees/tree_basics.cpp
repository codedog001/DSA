#include<iostream>
#include "tree.h"
using namespace std;
#include<queue>

//Valid Tree (for level wise input): 1 2 2 5 2 3 4 2 6 7 0 0 0 0

void preorderTraversal(TreeNode<int>* root){
    //Edge Case
    if(root == NULL) return;
    cout << root-> data << " ";
    for(int i=0; i<root->children.size(); i++){
        preorderTraversal(root->children[i]);
    }
}

void postorderTraversal(TreeNode<int>* root){
    //Edge Case
    if(root == NULL) return;
    for(int i=0; i<root->children.size(); i++){
        postorderTraversal(root->children[i]);
    }
    cout << root->data << " ";
}

int countLeafNodes(TreeNode<int>* root){
    if(root->children.size() == 0) return 1;
    int count = 0;
    for(int i=0; i<root->children.size(); i++){
        count += countLeafNodes(root->children[i]);
    }
    return count;
}


void printAtLevelK(TreeNode<int>* node, int k){ 
    //Base Case
    if(k==0){
        cout << node -> data << " ";
        return;
    }
    for(int i=0; i<node->children.size(); i++){
        printAtLevelK(node->children[i], k-1);
    }
}

int getHeight(TreeNode<int>* node) {
    // Write your code here
    if (node == NULL) return 0;
    int ans = 0;
    for(int i=0; i<node->children.size(); i++){
        int childHeight = getHeight(node->children[i]);
        ans = max(childHeight, ans);
    }
    return ans+1;
}

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    // Write your code here
    if(root==NULL) return nullptr;
    TreeNode<int>* result = root;
    int maxi = root-> data;
    for(int i=0; i<root->children.size(); i++){
        TreeNode<int>* temp = maxDataNode(root->children[i]);
        if(temp -> data > maxi){
            maxi= temp->data;
            result = temp;
        }
    }
    return result;
}

int sumOfNodes(TreeNode<int>* root) {
    // Write your code here
    if(root==NULL) return 0;
    int sum =root->data;
    for(int i=0; i<root->children.size(); i++){
        sum += sumOfNodes(root->children[i]);
    }
    return sum;
}

void printLevelWise(TreeNode<int>* root){
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        TreeNode<int>* front = pendingNodes.front();
        cout << front-> data << ": ";
        pendingNodes.pop();

        for(int i=0; i<front->children.size(); i++){
            cout << front->children[i]->data << ",";
        }
        cout << endl;
        for(int i=0; i<front->children.size(); i++){
            pendingNodes.push(front->children[i]);
        }
    }
}

TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() > 0){
        TreeNode<int> * front = pendingNodes.front();
        pendingNodes.pop();

        int n;
        cout << "Enter number of children of " << front->data << endl;
        cin >> n;

        for(int i=0; i<n; i++){
            int childData;
            cout << "Enter the data of " << i << "th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            pendingNodes.push(child);
            front->children.push_back(child);
        }
    }
    return root;
}

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

    TreeNode<int> * root = takeInputLevelWise();
    // printTree(root);
    // printLevelWise(root);
    cout << "Preorder Traversal" << endl;
    preorderTraversal(root);
     
    cout << endl;
    cout << "Postorder Traversal" << endl;
    postorderTraversal(root);

    cout << endl;
    cout << "Nodes at level 2" << endl;
    printAtLevelK(root, 2);

    cout << endl;
    cout << "Max Data Node: " << maxDataNode(root)->data << endl;

    delete root;
}

//Valid Tree (for level wise input): 1 2 2 5 2 3 4 2 6 7 0 0 0 0