class Solution {
public:
   long long solve(vector<int>& piles,int i,int j,vector<vector<long long>>&dp){
      if(i>j)return 0;
      if(i==j)return piles[i];
      if(dp[i][j]!=-1)return dp[i][j];
      long long take_i=piles[i]+min(solve(piles,i+2,j,dp),solve(piles,i+1,j-1,dp));
      long long take_j=piles[j]+min(solve(piles,i+1,j-1,dp),solve(piles,i,j-2,dp));
      return dp[i][j]= max(take_i,take_j);

   }

    bool stoneGame(vector<int>& piles) {
        long long n=piles.size();
        long long totalsum=0;
        for(int p:piles)totalsum+=p;
        vector<vector<long long>>dp(n+1,vector<long long>(n+1,-1));
        long long first_score=solve(piles,0,n-1,dp);
        long long second_score=totalsum-first_score;
        return first_score>second_score;

    }
};