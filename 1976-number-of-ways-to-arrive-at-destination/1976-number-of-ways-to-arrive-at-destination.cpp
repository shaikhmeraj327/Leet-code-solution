class Solution {
public:
    int m=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adjList(n);
        
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int w=roads[i][2];
            adjList[u].push_back({v,w});
            adjList[v].push_back({u,w});
        }
         vector<long long> dist(n, LLONG_MAX);
        dist[0]=0;
        vector<long long>ways(n,0);
        ways[0]=1;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});// wt and node
        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();
            int wt=temp.first;
            int node=temp.second;
            if(dist[node]<wt)continue;
            for(auto p:adjList[node]){
                int v=p.first;
                int w=p.second;
                if(dist[node]+w<dist[v]){
                    dist[v]=dist[node]+w;
                    pq.push({dist[v],v});
                    ways[v]=ways[node];
                }
                else if(dist[node]+w==dist[v]){
                    ways[v]=(ways[v]+ways[node])%m;
                }
            }
        }
        // cout<<ways[1]<<" ";
        return ways[n-1]%m;
    }
};