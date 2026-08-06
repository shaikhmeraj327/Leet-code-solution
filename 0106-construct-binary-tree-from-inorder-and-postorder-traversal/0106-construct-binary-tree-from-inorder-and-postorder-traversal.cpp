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

    unordered_map<int,int>map;
    TreeNode* solve(vector<int>&inorder,vector<int>&postorder,int &index,int inorderStart,int inorderEnd){
        if(index<0 || inorderStart>inorderEnd){
            return NULL;
        }
        int ele=postorder[index--];
        int pos=map[ele];
        TreeNode* root=new TreeNode(ele);
        root->right=solve(inorder,postorder,index,pos+1,inorderEnd);
        root->left=solve(inorder,postorder,index,inorderStart,pos-1);
        return root;
    } 
    

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        for(int i=0;i<n;i++){
            map[inorder[i]]=i;
        }
        int inorderStart=0;
        int inorderEnd=n-1;
        int index=n-1;
        return solve(inorder,postorder,index,inorderStart,inorderEnd);
    }
};