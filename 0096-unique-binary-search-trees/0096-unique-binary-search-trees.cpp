class Solution {
public:
    int numTrees(int n) {
        vector<int>dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        
        for(int ind=2;ind<=n;ind++){
            int ans=0;
            for(int i=1;i<=ind;i++){

                ans+=dp[i-1]*dp[ind-i];
            }
            dp[ind]=ans;
        }
        return dp[n];
    }

};


// class Solution {
// public:
//     int solve(int n,vector<int>&dp){
//         if(n<=1)return 1;
//         if(dp[n]!=-1)return dp[n];
//         int ans=0;
//         for(int i=1;i<=n;i++){
//             ans+=solve(i-1,dp)*solve(n-i,dp);
//         }
//         return dp[n]= ans;
//     }

//     int numTrees(int n) {
//         vector<int>dp(n+1,-1);
//         return solve(n,dp);
//     }
// };https://leetcode.com/_next/static/images/light-pending-9c28f1f18993ec103b273778b5f6a648.gif$0