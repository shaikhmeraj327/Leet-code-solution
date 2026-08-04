/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        if(root==NULL)return ans;
        q.push(root);
        int count=0;
        while(!q.empty()){
            int n=q.size();
            vector<int>output;
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                q.pop();
                output.push_back(temp->val);
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            if(count%2==0)ans.push_back(output);
            else{
                reverse(output.begin(),output.end());
                ans.push_back(output);
            }
            count++;
        }
        return ans;
    }
};