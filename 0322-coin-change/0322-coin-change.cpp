class Solution {
public:
    int solve(vector<int>&coins,int amount,int ind,vector<vector<int>>&dp){
        if(amount==0)return 0;
        if(amount<0 || ind>=coins.size())return 1e9;
        if(dp[ind][amount]!=-1)return dp[ind][amount];
        int include=1e9;
        if(amount-coins[ind]>=0)include=1+solve(coins,amount-coins[ind],ind,dp);
        int exclude=solve(coins,amount,ind+1,dp);
        return dp[ind][amount]= min(include,exclude);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans=solve(coins,amount,0,dp);

        if(ans==1e9)return -1;
        return ans;
    }
};