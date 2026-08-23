class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        // vector<vector<bool>>visited(m,vector<int>(n,false));
        int count=0;
        queue<pair<int,int>>q;
        int direction[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                bool flag=false;
                if(grid[i][j]=='1'){
                    q.push({i,j});
                    grid[i][j]='0';
                    flag=true;
                    while(!q.empty()){
                        auto temp=q.front();
                        q.pop();
                        int x=temp.first;
                        int y=temp.second;
                        for(auto d:direction){
                            int x1=x+d[0];
                            int y1=y+d[1];
                            if((x1>=0 && x1<m)&& (y1>=0 && y1<n) &&(grid[x1][y1]=='1')){
                                grid[x1][y1]='0';
                                q.push({x1,y1});
                            }
                        }
                    }
                }
                if(flag)count++;
            }
        }
        return count;

    }
};