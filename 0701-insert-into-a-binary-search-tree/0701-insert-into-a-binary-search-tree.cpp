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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            root=new TreeNode(val);
            return root;
        }
        TreeNode* ptr=root;
        while(ptr){
            if(ptr->val>val){
                if(!ptr->left){
                    ptr->left=new TreeNode(val);
                    return root;
                }
                else{
                    ptr=ptr->left;
                }
            }
            else{
                if(!ptr->right){
                    ptr->right=new TreeNode(val);
                    return root;
                }
                else ptr=ptr->right;
            }
        }
        return root;
    }
};