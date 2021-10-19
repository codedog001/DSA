#include <stack>

int countNodes(BinaryTreeNode < int > * root) {
  if (root == NULL) {
    return 0;
  }
  return countNodes(root -> left) + countNodes(root -> right) + 1;
}
void printNodesSumToS(BinaryTreeNode < int > * root, int s) {
  if (root == NULL) {
    return;
  }
  int totalCount = countNodes(root);
  int count = 0;
  stack < BinaryTreeNode < int > * > inorder;
  stack < BinaryTreeNode < int > * > revInorder;
  BinaryTreeNode < int > * currentNode = root;
  while (currentNode != NULL) {
    inorder.push(currentNode);
    currentNode = currentNode -> left;
  }
  currentNode = root;
  while (currentNode != NULL) {
    revInorder.push(currentNode);
    currentNode = currentNode -> right;
  }
  while (count < totalCount - 1) {
    BinaryTreeNode < int > * inorderTop = inorder.top();
    BinaryTreeNode < int > * revInorderTop = revInorder.top();
    if (inorderTop -> data + revInorderTop -> data == s) {
      cout << inorderTop -> data << " " << revInorderTop -> data << endl;
      BinaryTreeNode < int > * top = inorderTop;
      inorder.pop();
      count++;
      if (top -> right != NULL) {
        top = top -> right;
        while (top != NULL) {
          inorder.push(top);
          top = top -> left;
        }
      }
      top = revInorderTop;
      revInorder.pop();
      count++;
      if (top -> left != NULL) {
        top = top -> left;
        while (top != NULL) {
          revInorder.push(top);
          top = top -> right;
        }
      }
    } else if (inorderTop -> data + revInorderTop -> data > s) {
      BinaryTreeNode < int > * top = revInorderTop;
      revInorder.pop();
      count++;
      if (top -> left != NULL) {
        top = top -> left;
        while (top != NULL) {
          revInorder.push(top);
          top = top -> right;
        }
      }
    } else {
      BinaryTreeNode < int > * top = inorderTop;
      inorder.pop();
      count++;
      if (top -> right != NULL) {
        top = top -> right;
        while (top != NULL) {
          inorder.push(top);
          top = top -> left;
        }
      }
    }
  }
}