class Solution {
public:
   int solve(vector<int>&coins,int amount,int index,int n,vector<vector<int>>&dp){
    if(amount==0)return 0;
    if(amount<0 || index>=n)return 1e9;
    if(dp[index][amount]!=-1)return dp[index][amount];
    int include=1e9;
    if(coins[index]<=amount){
        include=1+solve(coins,amount-coins[index],index,n,dp);
    }
    int exclude=solve(coins,amount,index+1,n,dp);
    return dp[index][amount]= min(include,exclude);
   }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int index=0;
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans=solve(coins,amount,index,n,dp);
        if(ans==1e9)return -1;
        return ans;
    }
};