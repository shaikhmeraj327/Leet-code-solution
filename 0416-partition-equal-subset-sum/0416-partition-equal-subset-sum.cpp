class Solution {
public:
   bool solve(vector<int>&nums,int ind,int sum,vector<vector<int>>&dp){
       if(ind>=nums.size()){
          if(sum==0)return true;
          return false;
       }
       if(dp[ind][sum]!=-1)return dp[ind][sum];
       bool include=false;
       if(sum-nums[ind]>=0){
          include=solve(nums,ind+1,sum-nums[ind],dp);
       }
       bool exclude=solve(nums,ind+1,sum,dp);
       return dp[ind][sum]= include || exclude;
   }

    bool canPartition(vector<int>& nums) {
        long long sum=0;
        for(int num:nums)sum+=num;
        if(sum%2==1)return false;
        sum=sum/2;
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solve(nums,0,sum,dp);
    }
};