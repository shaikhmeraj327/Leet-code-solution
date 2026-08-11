class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int c0=1;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    if(j==0)c0=0;
                    else{
                        matrix[0][j]=0;
                    }
                }
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0)matrix[i][j]=0;
            }
        }
        if(matrix[0][0]==0){
            for(int j=0;j<n;j++){
                matrix[0][j]=0;
            }
        }
        if(c0==0){
            for(int i=0;i<m;i++){
                matrix[i][0]=0;
            }
        }
    }
};






// another method having time and space complexity is o(n2)
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         vector<int>row;
//         vector<int>col;
//         int m=matrix.size();
//         int n=matrix[0].size();
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(matrix[i][j]==0){
//                     row.push_back(i);
//                     col.push_back(j);
//                 }
//             }
//         }
//         for(int i=0;i<row.size();i++){
//             for(int j=0;j<n;j++){
//                 matrix[row[i]][j]=0;
//             }
//         }
//         for(int j=0;j<col.size();j++){
//             for(int i=0;i<m;i++){
//                 matrix[i][col[j]]=0;
//             }
//         }

//     }
// };