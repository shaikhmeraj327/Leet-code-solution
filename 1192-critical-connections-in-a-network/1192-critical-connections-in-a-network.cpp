class Solution {
public:
    void dfs(int node,int parent,vector<vector<int>>&adjList,
              vector<bool>&visited,vector<int>&disc,vector<int>&low,vector<vector<int>>&ans,int &timer){
            visited[node]=true;
            disc[node]=low[node]=timer++;
            for(int neig:adjList[node]){
                if(parent==neig)continue;
                if(!visited[neig]){
                    dfs(neig,node,adjList,visited,disc,low,ans,timer);
                    low[node]=min(low[neig],low[node]);
                    if(low[neig]>disc[node])ans.push_back({node,neig});
                }
                else{
                     low[node]=min(low[neig],low[node]);
                }
            }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adjList(n);
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        vector<bool>visited(n,false);
        vector<int>disc(n,0);
        vector<int>low(n,0);
        int timer=0;
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,-1,adjList,visited,disc,low,ans,timer);
            }
        }
        return ans;
    }
};