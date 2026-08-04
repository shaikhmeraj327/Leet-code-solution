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
   pair<bool,int> solve(TreeNode* root){
      if(root==NULL)return {true,0};
      pair<bool,int>left=solve(root->left);
      pair<bool,int>right=solve(root->right);
      bool cond=abs(left.second-right.second)<=1;
      pair<bool,int>ans;
      if(left.first && right.first && cond){
        ans.first=true;
        ans.second=1+max(left.second,right.second);
      }
      else ans.first=false;
      return ans;
   }


    bool isBalanced(TreeNode* root) {
        return solve(root).first;
    }
};



//  Another method o(n2) time complexity
// class Solution {
// public:
//     int height(TreeNode*root){
//         if(root==NULL)return 0;
//         int leftHt=height(root->left);
//         int rightHt=height(root->right);
//         int ans=1+max(leftHt,rightHt);
//         return ans;
//     }
//     bool isBalanced(TreeNode* root) {
//         if(root==NULL)return true;
//         bool left=isBalanced(root->left);
//         bool right=isBalanced(root->right);
//         bool diff=abs(height(root->left)-height(root->right))<=1;
//         if(left&&right&&diff)return true;
//         return false;
//     }
// };