class Solution {
public:
    int solve(int start,int n,vector<vector<int>>&dp){
        if(start>=n)return 0;
        if(dp[start][n]!=-1)return dp[start][n];
        int ans=INT_MAX;
        for(int i=start;i<=n;i++){
            ans=min(ans,i+max(solve(start,i-1,dp),solve(i+1,n,dp)));
        }
        return dp[start][n]= ans;

    }

    int getMoneyAmount(int n) {
        int start=1;
        // vector<vector<int>>dp()
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(start,n,dp);
    }
};