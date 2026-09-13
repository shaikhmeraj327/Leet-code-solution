class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int include=0;
                if(prev==-1 || nums[curr]>nums[prev]){
                    include=1+dp[curr+1][curr+1];
                }
                int exclude=0+dp[curr+1][prev+1];
                dp[curr][prev+1]=max(include,exclude);
            }
        }
        return dp[0][0];
    }
};






// class Solution {
// public:
//    int solve(vector<int>&nums,int prev,int index,int n,vector<vector<int>>&dp){
//     if(index>=n)return 0;
//     if(dp[index][prev+1]!=-1)return dp[index][prev+1];
//     int include=0;
//     if(prev==-1 || nums[prev]<nums[index])
//         include=1+solve(nums,index,index+1,n,dp);
//     int exclude=0+solve(nums,prev,index+1,n,dp);
//     return dp[index][prev+1]= max(include,exclude);
//    }

//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         int prev=-1;
//         vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
//         return solve(nums,prev,0,n,dp);
//     }
// };