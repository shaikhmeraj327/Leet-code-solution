class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int>row;
        vector<int>col;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        for(int i=0;i<row.size();i++){
            for(int j=0;j<n;j++){
                matrix[row[i]][j]=0;
            }
        }
        for(int j=0;j<col.size();j++){
            for(int i=0;i<m;i++){
                matrix[i][col[j]]=0;
            }
        }

    }
};


// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int m=matrix.size();
//         int n=matrix[0].size();
//         vector<int>index;
//         vector<int>index2;

//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(matrix[i][j]==0){
//                   index.push_back(i);
//                   index2.push_back(j);
                  
//                 }
//             }
//         }
//         int n1=index.size();
        
         
//         for(int i=0;i<n1;i++){
//             for(int j=0;j<n;j++){
//                 matrix[index[i]][j]=0;
//             }
//         }
//         int n2=index2.size();
//         for(int j=0;j<n2;j++){
//             for(int i=0;i<m;i++){
//                 matrix[i][index2[j]]=0;
//             }
//         }
        

//     }
// };