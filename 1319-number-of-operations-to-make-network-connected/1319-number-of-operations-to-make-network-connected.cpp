class Solution {
public:
   int findParent(vector<int>&parent,int node){
       if(parent[node]==node)return node;
       return parent[node]=findParent(parent,parent[node]);
   }
   void unionSet(int u,int v,vector<int>&parent,vector<int>&rank){
       u=findParent(parent,u);
       v=findParent(parent,v);
       if(rank[u]>rank[v])parent[v]=u;
       else if(rank[u]<rank[v])parent[u]=v;
       else{
        parent[u]=v;
        rank[v]++;
       }
   }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int m=connections.size();
        int count=n;
        if(m<n-1)return -1;// not possible
        vector<int>parent(n);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++)parent[i]=i;
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            u=findParent(parent,u);
            v=findParent(parent,v);
            if(u!=v){
                unionSet(u,v,parent,rank);
                count--;
            }
        }
         return count -1;
    }
};