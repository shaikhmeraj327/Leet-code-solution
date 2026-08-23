class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i]=0;
                queue<int>q;
                q.push(i);
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(int neig:graph[node]){
                        if(color[neig]==-1){
                            color[neig]=1-color[node];
                            q.push(neig);
                        }
                        else if(color[neig]==color[node])return false;
                    }
                }
            }
        }
        return true;
    }
};



// class Solution {
// public:
//    bool dfs(int node,vector<vector<int>>&graph,vector<int>&color){

//        for(int neig:graph[node]){
//            if(color[neig]==-1){
//                color[neig]=1-color[node];
//                bool check=dfs(neig,graph,color);
//                if(!check)return false;
//            }
//            else if(color[node]==color[neig])return false;
//        }
//        return true;
//    }

//     bool isBipartite(vector<vector<int>>& graph) {
//         int n=graph.size();
//         vector<int>color(n,-1);
//         for(int i=0;i<n;i++){
//             if(color[i]==-1){
//                 color[i]=0;
//                 bool check=dfs(i,graph,color);
//                 if(!check)return false; 
//             }
//         }
//         return true;
//     }
// };