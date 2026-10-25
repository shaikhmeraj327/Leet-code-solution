class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int direction[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            if(grid[i][0]==0){
                q.push({i,0});
                grid[i][0]=1;
            }
            if(grid[i][n-1]==0){
                q.push({i,n-1});
                grid[i][n-1]=1;
            }
        }
        for(int j=1;j<n-1;j++){
            if(grid[0][j]==0){
                q.push({0,j});
                grid[0][j]=1;
            }
            if(grid[m-1][j]==0){
                grid[m-1][j]=1;
                q.push({m-1,j});
            }
        }
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int x=temp.first;
            int y=temp.second;
            for(auto d:direction){
                int nx=x+d[0];
                int ny=y+d[1];
                if((nx>=0 && nx<m) &&(ny>=0 && ny<n) && (grid[nx][ny]==0)){
                    grid[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
        int count=0;
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(grid[i][j]==0){
                    queue<pair<int,int>>q1;
                    q1.push({i,j});
                    grid[i][j]=1;
                    while(!q1.empty()){
                        auto temp=q1.front();
                        q1.pop();
                        int x=temp.first;
                        int y=temp.second;
                        for(auto d:direction){
                            int nx=x+d[0];
                            int ny=y+d[1];
                            if((nx>=0 && nx<m) && (ny>=0 && ny<n) && grid[nx][ny]==0){
                                grid[nx][ny]=1;
                                q1.push({nx,ny});
                            }
                        }
                    }
                    count++;
                }
            }
        }
        return count;
    }
};