//Using 2 pointer array method.
#include<algorithm>
void inorder(vector<int>& res, BinaryTreeNode<int>* root){
    if(!root) return;
    inorder(res,root->left);
    res.push_back(root->data);
    inorder(res,root->right);
}

void pairSum(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
    if(!root) return;
    vector<int> res;
    inorder(res, root);
    sort(res.begin(), res.end());
    for(int i=0,j=res.size()-1; i<j;){
        if(res[i] + res[j] == sum){
            cout << res[i] << " " << res[j] << endl;
            i++;
            j--;
        }
        else if(res[i]+res[j] < sum) i++;
        else j--;
    }
}