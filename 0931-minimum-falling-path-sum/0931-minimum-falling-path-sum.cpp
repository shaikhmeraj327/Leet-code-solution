// class Solution {
// public:
//     int solve(vector<vector<int>>& matrix,int row,int col,int m,int n, vector<vector<int>>&dp){
//          if (col < 0 || col >= n) return 1e9;
//         if(row==m-1)return dp[row][col] = matrix[row][col];
//         if(dp[row][col]!=-1)return dp[row][col];
//         int below=matrix[row][col]+solve(matrix,row+1,col,m,n,dp);
//         int diagLeft=matrix[row][col]+solve(matrix,row+1,col-1,m,n,dp);
//         int diagRight=matrix[row][col]+solve(matrix,row+1,col+1,m,n,dp);
//         return dp[row][col]= min({below,diagLeft,diagRight});
//     }

//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int m=matrix.size();
//         int n=matrix[0].size();
//         int mini=1e9;
//         vector<vector<int>>dp(m,vector<int>(n,-1));
//         for(int j=0;j<n;j++){
            
//             mini=min(mini,solve(matrix,0,j,m,n,dp));
//         }
//         return mini;

//     }
// };
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Create a dp table where dp[i][j] represents the min falling path sum to reach (i, j)
        // We can also optimize space to O(n), but an m x n table is easiest to understand first.
        vector<vector<int>> dp = matrix; // Initialize with the matrix values
        
        // Process row by row from bottom-to-top (starting from m-2 down to 0)
        for (int row = m - 2; row >= 0; row--) {
            for (int col = 0; col < n; col++) {
                // Option 1: Below
                int down = dp[row + 1][col];
                
                // Option 2: Diagonal Left
                int leftDiag = (col > 0) ? dp[row + 1][col - 1] : 1e9;
                
                // Option 3: Diagonal Right
                int rightDiag = (col < n - 1) ? dp[row + 1][col + 1] : 1e9;
                
                // Current cell value + minimum of the 3 paths below it
                dp[row][col] = matrix[row][col] + min({down, leftDiag, rightDiag});
            }
        }
        
        // The answer is the minimum value in the first row of our completed dp table
        int mini = 1e9;
        for (int j = 0; j < n; j++) {
            mini = min(mini, dp[0][j]);
        }
        
        return mini;
    }
};