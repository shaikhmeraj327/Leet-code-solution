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
    void solve(TreeNode* root,int k,vector<int>&sum,int &count){
        if(root==NULL)return;
        sum.push_back(root->val);
        long long  total=0;
        for(int i=sum.size()-1;i>=0;i--){
            total+=sum[i];
            if(k==total){
                count++;
            }
        }
        solve(root->left,k,sum,count);
        solve(root->right,k,sum,count);
        sum.pop_back();
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)return 0;
        vector<int>sum;
        int count=0;
        solve(root,targetSum,sum,count);
        return count;
    }
};