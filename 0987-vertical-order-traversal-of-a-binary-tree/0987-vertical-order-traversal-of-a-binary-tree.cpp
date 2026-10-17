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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>>map;
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int hd=temp.second.first;
            int lv=temp.second.second;
            map[hd][lv].push_back(temp.first->val);
            if(temp.first->left)q.push({temp.first->left,{hd-1,lv+1}});
            if(temp.first->right)q.push({temp.first->right,{hd+1,lv+1}});;

        }

        for(auto p:map){
            vector<int>output;
            for(auto p2:p.second){
                sort(p2.second.begin(),p2.second.end());
                for(int num:p2.second)output.push_back(num);
            }
            ans.push_back(output);
        }
        return ans;
        
    }
};