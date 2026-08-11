class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int m=matrix.size();
        int n=matrix[0].size();
        int total=m*n;
        int sr=0,er=m-1;
        int sc=0,ec=n-1;
        int count=0;
        while(count<total){
            // printing the first row;
            for(int j=sc;j<=ec && count<total;j++){
                ans.push_back(matrix[sr][j]);
                count++;
            }
            sr++;
            // printing the last column
            for(int i=sr;i<=er && count<total;i++){
                ans.push_back(matrix[i][ec]);
                count++;
            }
            ec--;
            // printing the last rows
            for(int j=ec;j>=sc && count<total;j--){
                 ans.push_back(matrix[er][j]);
                 count++;
            }
            er--;
            // print the first col
            for(int i=er;i>=sr && count<total;i--){
                ans.push_back(matrix[i][sc]);
                count++;
            }
            sc++;

        }
        return ans;
    }
};