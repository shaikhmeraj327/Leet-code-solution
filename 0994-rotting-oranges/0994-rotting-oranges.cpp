class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int fresh=0;
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2)q.push({i,j});
                else if(grid[i][j]==1)fresh++;
            }
        }
        if(fresh==0)return 0;
        int time=-1;
        int direction[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            int size=q.size();
            time++;
            for(int i=0;i<size;i++){
                auto temp=q.front();
                q.pop();
                int x=temp.first;
                int y=temp.second;
                for(auto d:direction){
                    int x1=x+d[0];
                    int y1=y+d[1];
                    if((x1>=0 && x1<m) && (y1>=0 && y1<n) &&(grid[x1][y1]==1)){
                        q.push({x1,y1});
                        grid[x1][y1]=2;
                        fresh--;
                    }
                }
            }

        }
        if(fresh!=0)return -1;
        return time;
    }
};