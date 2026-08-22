class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V=numCourses;
        vector<vector<int>>adjList(V);
        int m=prerequisites.size();
        vector<int>indegree(V,0);
        for(int i=0;i<m;i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adjList[v].push_back(u);
            indegree[u]++;
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0)q.push(i);
        }
        int count=0;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            count++;
            for(int neig:adjList[front]){
                indegree[neig]--;
                if(indegree[neig]==0){
                   q.push(neig);
                }
            }
        }
        
        return count==V;
    }
};