class Solution {
public:
   void dfs(int node,vector<vector<int>>&adjList,vector<bool>&visited){
        visited[node]=true;
        for(int num:adjList[node]){
            if(!visited[num])dfs(num,adjList,visited);
        }
   }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adjList(n);
        int m=invocations.size();
        for(int i=0;i<m;i++){
            int u=invocations[i][0];
            int v=invocations[i][1];
            adjList[u].push_back(v);
        }
        vector<bool>visited(n,false);
        dfs(k,adjList,visited);
        bool canRemove=true;
        for(int i=0;i<m;i++){
            int u=invocations[i][0];
            int v=invocations[i][1];
            if(!visited[u] && visited[v]){
                canRemove=false;
                break;
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(canRemove){
                if(!visited[i])ans.push_back(i);
            }
            else{
                ans.push_back(i);
            }
        }
        return ans;
    }
};