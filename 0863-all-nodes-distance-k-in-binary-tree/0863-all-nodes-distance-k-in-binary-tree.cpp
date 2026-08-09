/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   unordered_map<TreeNode*,TreeNode*>parent;
   TreeNode* findParent(TreeNode* root,TreeNode* target){
        queue<TreeNode*>q;
        q.push(root);
        parent[root]=NULL;
        TreeNode* start=NULL;
        while(!q.empty()){
            TreeNode* temp = q.front();;
            q.pop();
            if(temp==target)start=temp;
            if(temp->left){
                q.push(temp->left);
                parent[temp->left]=temp;
            }
            if(temp->right){
                q.push(temp->right);
                parent[temp->right]=temp;
            }
        }
        return start;
   }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        TreeNode* start=findParent(root,target);
        queue<TreeNode*>q;
        q.push(start);
        unordered_map<TreeNode*,bool>visited;
        visited[start]=true;
        int level=0;
        while(!q.empty()){
            int n=q.size();
            if(level==k)break;
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left && !visited[temp->left]){
                    q.push(temp->left);
                    visited[temp->left]=true;
                }
                if(temp->right && !visited[temp->right]){
                    q.push(temp->right);
                    visited[temp->right]=true;
                }
                if(parent[temp] && !visited[parent[temp]]){
                    q.push(parent[temp]);
                    visited[parent[temp]]=true;
                }
            }
            level++;
        }
        vector<int>ans;
        if(level<k)return ans;
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            ans.push_back(temp->val);
        }
        return ans;
    }
};




