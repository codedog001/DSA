    vector<int> topView(Node *root){
        vector<int> res;
        if(!root) return res;
        queue<pair<int,Node*>> q;
        map<int,int> m;
        q.push({0,root});
        while(!q.empty()){
            int n= q.size();

            for(int i=0; i<n; i++){
                auto front = q.front().second;
                auto line = q.front().first;
                if(m.find(line) == m.end()) m[line] = front->data;
                if(front->left) q.push({line-1, front->left});
                if(front->right) q.push({line+1,front->right});
                q.pop();
            }
        }
        for(auto g:m){
                res.push_back(g.second);
            }
        return res;
    }