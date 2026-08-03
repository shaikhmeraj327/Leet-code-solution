class Solution {
public:
    int solve(vector<int>& stoneValue,int i,int n,vector<int>&dp){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int first=stoneValue[i]-solve(stoneValue,i+1,n,dp);
        if(i+1<n){
            int second=stoneValue[i]+stoneValue[i+1]-solve(stoneValue,i+2,n,dp);
            first=max(first,second);
        }
        if(i+2<n){
            int third=stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-solve(stoneValue,i+3,n,dp);
            first=max(first,third);
        }
        return dp[i]=first;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int>dp(n+1,-1);
        int ans=solve(stoneValue,0,n,dp);
        if(ans>0)return "Alice";
        else if(ans<0)return "Bob";
        return "Tie";
    }
};