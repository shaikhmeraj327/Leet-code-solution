class Solution {
public:
 

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adjList(n+1);
        int m=times.size();
        for(int i=0;i<m;i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            adjList[u].push_back({v,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();
            int wt=temp.first;
            int u=temp.second;
            if(dist[u]<wt)continue;
            for(auto p:adjList[u]){
                int v=p.first;
                int w=p.second;
                if(dist[u]+w<dist[v]){
                    dist[v]=wt+w;
                    pq.push({dist[u]+w,v});
                }
            }
        }



        int maxi=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX)return -1;
            else maxi=max(maxi,dist[i]);
        }
        return maxi;
    }
};