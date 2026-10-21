class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(grid[0][0]==1 || grid[m-1][n-1]==1)return -1;
        queue<pair<int,int>>q;
        int direction[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,-1},{1,1},{-1,1},{-1,-1}};
        q.push({0,0});
        grid[0][0]=1;
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int x=temp.first;
            int y=temp.second;
            if(x==m-1 && y==n-1)return grid[x][y];
            for(auto d:direction){
                int nx=x+d[0];
                int ny=y+d[1];
                if((nx>=0 && nx<m) &&(ny>=0 &&ny<n) && (grid[nx][ny]==0)){
                    grid[nx][ny]=grid[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
        if(grid[m-1][n-1]==0)return -1;
        return grid[m-1][n-1];
    }
};