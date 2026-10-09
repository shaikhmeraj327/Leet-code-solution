class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        string s1=s;
        reverse(s1.begin(),s1.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int ans=0;
                if(s[i-1]==s1[j-1]){
                    ans=1+dp[i-1][j-1];
                }
                else{
                    ans=max(dp[i-1][j],dp[i][j-1]);
                }
                dp[i][j]=ans;
            }
        }
        int lcs=dp[n][n];
        return n-lcs;
    }
};





// class Solution {
// public:
//    int  solve(string &s,int i,int j,int n,vector<vector<int>>&dp){
//     if(i>=j)return 0;
//     if(dp[i][j]!=-1)return dp[i][j]; 
//     int notInsert=INT_MAX,insert=INT_MAX;
//     if(s[i]==s[j])notInsert=solve(s,i+1,j-1,n,dp);
//     else{
//         insert=1+min(solve(s,i+1,j,n,dp),solve(s,i,j-1,n,dp));
//     }
//     return dp[i][j]= min(notInsert,insert);


//    }

//     int minInsertions(string s) {
//         int i=0;
//         int n=s.size();
//         int j=n-1;
//         vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
//         return solve(s,i,j,n,dp);
//     }
// };