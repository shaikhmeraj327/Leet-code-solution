class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        for(int j=0;j<n;j++){
            if(grid[0][j]==1)q.push({0,j});
            if(grid[m-1][j]==1)q.push({m-1,j});
        }
        for(int i=1;i<m-1;i++){
            if(grid[i][0]==1)q.push({i,0});
            if(grid[i][n-1]==1)q.push({i,n-1});
        }
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        int direction[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int x=temp.first;
            int y=temp.second;
            visited[x][y]=true;
            for(auto d:direction){
                int x1=x+d[0];
                int y1=y+d[1];
                if((x1>=0 && x1<m)&&(y1>=0 &&y1<n)&&(!visited[x1][y1])&& (grid[x1][y1]==1)){
                    q.push({x1,y1});
                    visited[x1][y1]=true;
                }
            }
        }
        int total=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !visited[i][j])total++;
            }
        }
        return total;
    }
};