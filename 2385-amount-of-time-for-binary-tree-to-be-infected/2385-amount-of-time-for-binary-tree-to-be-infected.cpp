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
    TreeNode* findParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent,int start){
        TreeNode *ptr=NULL;
        queue<TreeNode*>q;
        q.push(root);
        parent[root]=NULL;
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp->val==start)ptr=temp;
            if(temp->left){
                parent[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right){
                parent[temp->right]=temp;
                q.push(temp->right);
            }
        }
        return ptr;  
    }
    
    
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>parent;
        TreeNode* ptr=findParent(root,parent,start);
        unordered_map<TreeNode*,bool>visited;
        visited[ptr]=true;
        queue<TreeNode*>q;
        q.push(ptr);
        int time=0; 
        while(!q.empty()){
            bool flag=false;
            int n=q.size();
            for(int i=0;i<n;i++){
                 TreeNode* temp=q.front();
                 q.pop();
                 if(temp->left && !visited[temp->left]){
                flag=true;
                visited[temp->left]=true;
                q.push(temp->left);
            }
            if(temp->right && !visited[temp->right]){
                flag=true;
                visited[temp->right]=true;
                q.push(temp->right);
            }
            if(parent[temp] && !visited[parent[temp]]){
                flag=true;
                visited[parent[temp]]=true;
                q.push(parent[temp]);
            }
            }
            
            if(flag)time++;
        }

        return time;
    }
};