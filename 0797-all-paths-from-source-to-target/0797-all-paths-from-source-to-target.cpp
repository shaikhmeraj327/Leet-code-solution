class Solution {
public:
   void dfs(int node,vector<vector<int>>&graph,vector<int>&path,vector<vector<int>>&ans,int target){
        path.push_back(node);
        if(node==target)ans.push_back(path);
        else{ 
            for(int num:graph[node]){
               dfs(num,graph,path,ans,target);
           }
        }
        path.pop_back();
   }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>path;
        int target=graph.size()-1;
        vector<vector<int>>ans;
        dfs(0,graph,path,ans,target);
        return ans;
    }
};