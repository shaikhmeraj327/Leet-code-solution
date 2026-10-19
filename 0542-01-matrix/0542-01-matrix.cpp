class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>res(m,vector<int>(n,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    res[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        
        int direction[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto temp=q.front();
                q.pop();
                int x=temp.first;
                int y=temp.second;
                for(auto d:direction){
                    int nx=x+d[0];
                    int ny=y+d[1];
                    if((nx>=0 && nx<m) &&(ny>=0 && ny<n) && res[nx][ny]==-1){
                        res[nx][ny]=1+res[x][y];
                        q.push({nx,ny});
                    }
                    
                }
            }
        }

        return res;

    }
};