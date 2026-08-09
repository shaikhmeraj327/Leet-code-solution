class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int maxi=0;
        if(!root->left && !root->right)return 1;
        queue<pair<TreeNode*,int>>q;// node and its index
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            int si=q.front().second;
            int ei=q.back().second;
            maxi=max(maxi,ei-si+1);
            for(int i=0;i<n;i++){
                auto temp=q.front();
                q.pop();
                if(temp.first->left)q.push({temp.first->left,(long long)2*temp.second+1});
                if(temp.first->right)q.push({temp.first->right,(long long)2*temp.second+2});
            }
        }
        return maxi;
    }
};