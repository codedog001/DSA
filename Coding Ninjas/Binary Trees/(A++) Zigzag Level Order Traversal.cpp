vector < vector < int >> zigzagLevelOrder(TreeNode * root) {
      vector < int > temp;
      vector < vector < int >> res;
      if (!root) return res;

      stack < TreeNode * > s1, s2;
      s1.push(root);
      int currentLevelRemaining = 1;
      int nextLevelCount = 0;
      bool flag = true;
      while (!s1.empty() || !s2.empty()) {
        if (flag) {
          TreeNode * top = s1.top();
          s1.pop();
          temp.push_back(top -> val);
          currentLevelRemaining--;
          if (top -> left != NULL) {
            s2.push(top -> left);
            nextLevelCount++;
          }
          if (top -> right != NULL) {
            s2.push(top -> right);
            nextLevelCount++;
          }
          if (currentLevelRemaining == 0) {
            res.push_back(temp);
            temp.clear();
            currentLevelRemaining = nextLevelCount;
            nextLevelCount = 0;
            flag = false;
          }
        } else {
          TreeNode * top = s2.top();
          s2.pop();
          temp.push_back(top -> val);
          currentLevelRemaining--;
          if (top -> right != NULL) {
            s1.push(top -> right);
            nextLevelCount++;
          }
          if (top -> left != NULL) {
            s1.push(top -> left);
            nextLevelCount++;
          }
          if (currentLevelRemaining == 0) {
            res.push_back(temp);
            temp.clear();
            currentLevelRemaining = nextLevelCount;
            nextLevelCount = 0;
            flag = true;
          }
        }
      }
      return res;
    }