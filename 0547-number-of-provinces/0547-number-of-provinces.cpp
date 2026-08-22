class Solution {
public:
   void dfs(int node,vector<vector<int>>&adjList,vector<bool>&visited){
        visited[node]=true;
        for(int neig:adjList[node]){
            if(!visited[neig])dfs(neig,adjList,visited);
        }
   }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>adjList(n+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j  && isConnected[i][j]==1){
                    adjList[i].push_back(j); 
                    adjList[j].push_back(i);
                }
            }
        }
        vector<bool>visited(n+1,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,adjList,visited);
                count++;
            }
        }
        return count;
    }
};