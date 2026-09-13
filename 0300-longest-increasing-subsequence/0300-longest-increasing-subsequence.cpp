class Solution {
public:
   int solve(vector<int>&nums,int prev,int index,int n,vector<vector<int>>&dp){
    if(index>=n)return 0;
    if(dp[index][prev+1]!=-1)return dp[index][prev+1];
    int include=0;
    if(prev==-1 || nums[prev]<nums[index])
        include=1+solve(nums,index,index+1,n,dp);
    int exclude=0+solve(nums,prev,index+1,n,dp);
    return dp[index][prev+1]= max(include,exclude);
   }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int prev=-1;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(nums,prev,0,n,dp);
    }
};