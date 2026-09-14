class Solution {
public:
    bool canPartition(vector<int>& nums) {
       long long target=0;
       for(int num:nums)target+=num;
       if(target%2==1)return false;
       target/=2;
       int n=nums.size();
       vector<vector<int>>dp(n+1,vector<int>(target+1,0));
       
       for(int i=0;i<=n;i++){
          dp[i][0]=1;
       }
       for(int ind=n-1;ind>=0;ind--){
        for(int t=0;t<=target;t++){
            bool include=false;
            if(t-nums[ind]>=0){
                include=dp[ind+1][t-nums[ind]];
            }
            bool exclude=dp[ind+1][t];
            dp[ind][t]=include || exclude;
        }
       }
       return dp[0][target];
    }
};


// class Solution {
// public:
//    bool solve(vector<int>&nums,int ind,int sum,vector<vector<int>>&dp){
//        if(sum==0)return true;
//        if(sum<0)return false;
//        if(ind>=nums.size()){
//           return false;
//        }
//        if(dp[ind][sum]!=-1)return dp[ind][sum];
//        bool include=false;
//        if(sum-nums[ind]>=0){
//           include=solve(nums,ind+1,sum-nums[ind],dp);
//        }
//        bool exclude=solve(nums,ind+1,sum,dp);
//        return dp[ind][sum]= include || exclude;
//    }

//     bool canPartition(vector<int>& nums) {
//         long long sum=0;
//         for(int num:nums)sum+=num;
//         if(sum%2==1)return false;
//         sum=sum/2;
//         int n=nums.size();
//         vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
//         return solve(nums,0,sum,dp);
//     }
// };