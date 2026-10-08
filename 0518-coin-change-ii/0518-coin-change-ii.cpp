class Solution {
public:
   int solve(vector<int>&coins,int amount,int index,int n,vector<vector<int>>&dp){
      if(index>=n){
        if(amount==0)return 1;
        return 0;
      }
      if(dp[index][amount]!=-1)return dp[index][amount];
      int include=0;
      if(coins[index]<=amount){
        include=solve(coins,amount-coins[index],index,n,dp);
      }
      int exclude=solve(coins,amount,index+1,n,dp);
      return dp[index][amount]= include+exclude;
   }

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        int index=0;
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return solve(coins,amount,index,n,dp);

        // long long n=coins.size();
        
        // vector<vector<long long>> dp(n + 1, vector<long long>(amount + 1, 0));
        // for(int i=0;i<=n;i++){
        //     dp[i][0]=1;
        // }
        // for(int ind=n-1;ind>=0;ind--){
        //     for(int sum=0;sum<=amount;sum++){
        //         int include=0;
        //         if(sum-coins[ind]>=0){
        //             include=dp[ind][sum-coins[ind]];
        //         }
        //         int exclude=dp[ind+1][sum];
        //         dp[ind][sum]=include+exclude;
        //     }
        // }
        // return dp[0][amount];

    }
};