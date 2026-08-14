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
class BSTIterator {
public:
   stack<TreeNode*>st;
   void storeLeft(TreeNode* root){
        while(root){
            st.push(root);
            root=root->left;
        }
   }


    BSTIterator(TreeNode* root) {
        storeLeft(root);
    }
    
    int next() {
        if(st.empty())return -1;
        TreeNode* temp=st.top();
        st.pop();
        if(temp->right){
            storeLeft(temp->right);
        }
        return temp->val;
    }
    
    bool hasNext() {
        return st.size()>0;
    }
};

// class BSTIterator {
// public:
//     stack<TreeNode*>st;
//     void storeLeftNode(TreeNode* root){
//         while(root){
//             st.push(root);
//             root=root->left;
//         }
//     }
//     BSTIterator(TreeNode* root) {
//         storeLeftNode(root);
//     }
    
//     int next() {
//         TreeNode*ans=st.top();
//         int res=ans->val;
//         st.pop();
//         if(ans->right){
//             storeLeftNode(ans->right);
//         }
        
//         return res;
//     }
    
//     bool hasNext() {
//         return st.size()>0;
//     }
// };

// /**
//  * Your BSTIterator object will be instantiated and called as such:
//  * BSTIterator* obj = new BSTIterator(root);
//  * int param_1 = obj->next();
//  * bool param_2 = obj->hasNext();
//  */