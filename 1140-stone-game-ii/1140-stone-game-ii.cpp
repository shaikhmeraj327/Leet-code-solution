class Solution {
public:
   int solve(vector<int>& piles,int person,int ind,int m,vector<vector<vector<int>>>&dp){
       int n=piles.size();
       if(ind>=piles.size())return 0;
       if(dp[person][ind][m]!=-1)return dp[person][ind][m];
       int res;
       if(person==1)res=-1;
       else res=INT_MAX;
       int sum=0;
       for(int x=1;x<=min(2*m,n-ind);x++){
           sum+=piles[ind+x-1];
           if(person==1){
              res=max(res,sum+solve(piles,0,ind+x,max(m,x),dp));
           }
           else res=min(res,solve(piles,1,ind+x,max(m,x),dp));
       }
       return dp[person][ind][m]=res;
   }

    int stoneGameII(vector<int>& piles) {
        int person=1;
        int ind=0;
        int m=1;
        int n=piles.size();
        vector<vector<vector<int>>>dp(2,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
        return solve(piles,person,ind,m,dp);
    }
};