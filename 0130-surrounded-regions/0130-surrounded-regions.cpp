class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        queue<pair<int,int>>q;
        for(int j=0;j<n;j++){
            if(board[0][j]=='O'){
                q.push({0,j});
            }
            if(board[m-1][j]=='O')q.push({m-1,j});
        }
        for(int i=1;i<m-1;i++){
            if(board[i][0]=='O')q.push({i,0});
            if(board[i][n-1]=='O')q.push({i,n-1});
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
                if((x1>=0 && x1<m) &&(y1>=0 && y1<n) &&(!visited[x1][y1]) &&(board[x1][y1]=='O')){
                    q.push({x1,y1});
                    // visited[x1][y1]=true;
                }
             }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j])board[i][j]='O';
                else board[i][j]='X';
            }
        }
    }
};