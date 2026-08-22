class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int start=image[sr][sc];
        if(start==color)return image;
        int m=image.size();
        int n=image[0].size();
        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc]=color;
        int direction[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int x=temp.first;
            int y=temp.second;
            for(auto d:direction){
                int x1=x+d[0];
                int y1=y+d[1];
                if((x1>=0 && x1<m)&&(y1>=0 && y1<n) &&(image[x1][y1]==start)){
                    image[x1][y1]=color;
                    q.push({x1,y1});
                }

            }
        }
        return image;
    }
};