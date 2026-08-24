class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int direction[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,-1},{1,1},{-1,-1},{-1,1}};
        if(grid[0][0]==1 || grid[m-1][n-1]==1)return -1;
        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0]=1;
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int x=temp.first;
            int y=temp.second;
            if(x==m-1 && y==n-1)return grid[x][y];
            for(auto d:direction){
                int x1=x+d[0];
                int y1=y+d[1];
                if((x1>=0 && x1<m) &&(y1>=0&& y1<n) &&(grid[x1][y1]==0)){
                    grid[x1][y1]=grid[x][y]+1;
                    q.push({x1,y1});
                }
            }
        }
        return -1;
    }
};




