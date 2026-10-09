class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<m;i++){
            dp[i][n]=m-i;
        }
        for(int j=0;j<n;j++){
            dp[m][j]=n-j;;
        }
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int ans=0;
                if(word1[i]==word2[j])ans=dp[i+1][j+1];
                else ans=1+min(dp[i+1][j],dp[i][j+1]);
                dp[i][j]=ans;
            }
        }
        return dp[0][0];

    }
};





// class Solution {
// public:
//     int solve(string word1,string word2,int i,int j,int m,int n,vector<vector<int>>&dp){
//         if(i>=m || j>=n){
//             return (m-i)+(n-j);
//         }
//         if(dp[i][j]!=-1)return dp[i][j];
//         // int nodelete=1e9;
//         // int deletest=1e9;
//         int ans=0;
//         if(word1[i]==word2[j])ans=solve(word1,word2,i+1,j+1,m,n,dp);
//         else ans=1+min(solve(word1,word2,i+1,j,m,n,dp),solve(word1,word2,i,j+1,m,n,dp));
//         return dp[i][j]= ans;

//     }

//     int minDistance(string word1, string word2) {
//         int m=word1.size();
//         int n=word2.size();
//         vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
//         return solve(word1,word2,0,0,m,n,dp); 
//     }
// };