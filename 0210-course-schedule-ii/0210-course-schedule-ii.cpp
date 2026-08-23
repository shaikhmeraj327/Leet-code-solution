class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>>adjList(n);
        int m=prerequisites.size();
        vector<int>indegree(n,0);
        for(int i=0;i<m;i++){
            int u=prerequisites[i][1];
            int v=prerequisites[i][0];
            adjList[u].push_back(v);
            indegree[v]++;
        }
        vector<int>ans;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int front=q.front();
            q.pop();
            ans.push_back(front);
            for(int neig:adjList[front]){
                indegree[neig]--;
                if(indegree[neig]==0){
                    q.push(neig);
                }
            }
        }
        if(ans.size()<n)return {};
        return ans;
    }
};