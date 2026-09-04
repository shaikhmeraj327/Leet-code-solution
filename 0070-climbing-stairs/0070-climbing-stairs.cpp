class Solution {
public:
    int climbStairs(int n) {
        if(n<=1)return 1;
        vector<int>dp(n+1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};


// Another way

// class Solution {
// public:
//     int climbStairs(int n) {
//         int prev1=0;
//         int prev2=1;
//         int curr=1;
//         for(int i=1;i<=n;i++){
//             curr=prev2+prev1;
//             prev1=prev2;
//             prev2=curr;
//         }
//         return curr;
//     }
// };


// using top down dp
// class Solution {
// public:
//     int solve(int n,vector<int>&dp){
//         if(n<=1)return 1;
//         if(dp[n]!=-1)return dp[n];
//         int ans=solve(n-1,dp)+solve(n-2,dp);
//         return dp[n]=ans;
//     }

//     int climbStairs(int n) {
       
//        vector<int>dp(n+1,-1);
//        return solve(n,dp);


//     }
// };