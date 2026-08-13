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
   void inorder(TreeNode* root,vector<int>&output){
         if(root==NULL)return;
         inorder(root->left,output);
         output.push_back(root->val);
         inorder(root->right,output);
   }

    bool findTarget(TreeNode* root, int k) {
        vector<int>output;
        inorder(root,output);
        int s=0,e=output.size()-1;
        while(s<e){
            int sum=output[s]+output[e];
            if(sum==k)return true;
            else if(sum>k)e--;
            else s++;
        }
        return false;
    }
};