class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>>mat(m,vector<int>(n,INT_MAX));
        int direction[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});// diff and and the initital index 0,0
        mat[0][0]=0;
        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();
            int dif=temp.first;
            int x=temp.second.first;
            int y=temp.second.second;
            if(mat[x][y]<dif)continue;
            for(auto d:direction){
                int x1=x+d[0];
                int y1=y+d[1];
                
                if((x1>=0 && x1<m) &&(y1>=0 && y1<n)){
                    int maxDiff=max(abs(heights[x1][y1]-heights[x][y]),dif);
                    if(maxDiff<mat[x1][y1]){
                       mat[x1][y1]=maxDiff;
                       pq.push({maxDiff,{x1,y1}});
                    }
                }
            }
        }
        return mat[m-1][n-1];
    }
};