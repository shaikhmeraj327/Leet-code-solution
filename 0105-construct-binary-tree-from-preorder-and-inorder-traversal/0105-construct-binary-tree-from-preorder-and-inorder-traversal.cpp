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
    TreeNode*solve(vector<int>& preorder, vector<int>& inorder,int &index,int inorderStart,int inorderEnd ){
        if(index>=preorder.size() || inorderStart>inorderEnd)return NULL;
        int ele=preorder[index++];
        int pos=map[ele];
        TreeNode*root=new TreeNode(ele);
        root->left=solve(preorder,inorder,index,inorderStart,pos-1);
        root->right=solve(preorder,inorder,index,pos+1,inorderEnd);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        
        for(int i=0;i<n;i++){
            map[inorder[i]]=i;
        }
        int index=0;
        int inorderStart=0;
        int inorderEnd=n-1;
        TreeNode* root=solve(preorder,inorder,index,inorderStart,inorderEnd);
        return root;
    }
};