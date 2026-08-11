class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // first we have to do yranspose of the given matrix;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=i+1;j<n;j++)swap(matrix[i][j],matrix[j][i]);
        }
        // reverse each row
        for(int i=0;i<m;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};