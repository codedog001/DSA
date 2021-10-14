class BST {
  BinaryTreeNode < int > * root;
  public: BST() {
    root = NULL;
  }
  ~BST() {
    delete root;
  }
    
  private: 


  void print(BinaryTreeNode < int > * root) {
    if (root == NULL) {
      return;
    }
    cout << root -> data << ":";
    if (root -> left != NULL) {
      cout << "L:" << root -> left -> data << ",";
    }
    if (root -> right != NULL) {
      cout << "R:" << root -> right -> data;
    }
    cout << endl;
    print(root -> left);
    print(root -> right);
  }
  public:
  void print() {
    print(root);
  }
    
  private: 
bool search(BinaryTreeNode < int > * node, int data) {
    if (node == NULL) {
      return false;
    }
    if (node -> data == data) {
      return true;
    } else if (data < node -> data) {
      return search(node -> left, data);
    }
    return search(node -> right, data);
  }
  public: bool search(int data) {
    return search(root, data);
  }
};