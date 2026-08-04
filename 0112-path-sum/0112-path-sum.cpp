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
   bool solve(TreeNode* root,int k){
     if(root==NULL)return false;
     if(root->left==NULL && root->right==NULL){
        return k-root->val==0;
     }
     k=k-root->val;
     bool left=solve(root->left,k);
     bool right=solve(root->right,k);
     return right || left;
   }

    bool hasPathSum(TreeNode* root, int k) {
        return solve(root,k);
    }
};