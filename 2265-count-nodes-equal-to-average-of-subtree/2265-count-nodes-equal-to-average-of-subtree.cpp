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
    bool isPossible(TreeNode* root){
        queue<TreeNode*>pq;
        pq.push(root);
        int sum=0;
        int count=1;
    
        while(!pq.empty()){
            TreeNode* top=pq.front();
            pq.pop();
            sum+=top->val;
            if(top->left){
                pq.push(top->left);
                count++;
            }
            if(top->right){
                pq.push(top->right);
                count++;
            }
        }
        int avg=sum/count;
        if(avg==root->val)return true;
        return false;
    }

    int averageOfSubtree(TreeNode* root) {
        int count=0;
        TreeNode* ptr=root;
        queue<TreeNode*>pq;
        pq.push(ptr);
        while(!pq.empty()){
            TreeNode* top=pq.front();
            if(isPossible(top)){
                count++;
            }
            

            pq.pop();
            if(top->left)pq.push(top->left);
            if(top->right)pq.push(top->right);
        }
        return count;
    }
};