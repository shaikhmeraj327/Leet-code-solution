class Solution {
public:
    void dfs(int node,vector<vector<int>>& isConnected,vector<bool>&visited){
        visited[node]=true;
        for(int neig=0;neig<isConnected[node].size();neig++){
            if(isConnected[node][neig]==1 && !visited[neig])dfs(neig,isConnected,visited);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool>visited(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,isConnected,visited);
                count++;
            }
        }
        return count;
    }
};