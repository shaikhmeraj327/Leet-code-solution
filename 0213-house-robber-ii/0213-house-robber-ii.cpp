class Solution {
public:
    // int solve(int ind,int n,vector<int>&nums,vector<int>&dp){
    //     if(ind>=n)return 0;
    //     if(dp[ind]!=-1)return dp[ind];
    //     int inc=nums[ind]+solve(ind+2,n,nums,dp);
    //     int exc=0+solve(ind+1,n,nums,dp);
    //     return dp[ind]=max(inc,exc);
    // }

    int rob(vector<int>& nums) {
        // int n=nums.size();
        // if(n==1)return nums[0];
        // vector<int>dp1(n+1,-1);
        // vector<int>dp2(n+1,-1);
        // int ans1=solve(0,n-1,nums,dp1);
        // int ans2=solve(1,n,nums,dp2);
        // return max(ans1,ans2);
        

        int n=nums.size();
        if(n==1)return nums[0];
        vector<int>dp1(n+1,-1e9);
        vector<int>dp2(n+2,-1e9);
        dp1[n-1]=0;
        dp1[n]=0;
        for(int ind=n-2;ind>=0;ind--){
            int inc=nums[ind]+dp1[ind+2];
            int exc=0+dp1[ind+1];
            int ans=max(inc,exc);
            dp1[ind]=ans;
        }
        dp2[n+1]=0;
        dp2[n]=0;
        for(int ind=n-1;ind>=1;ind--){
            int inc=nums[ind]+dp2[ind+2];
            int exc=0+dp2[ind+1];
            int ans=max(inc,exc);
            dp2[ind]=ans;
        }
        return max(dp1[0],dp2[1]);
    }
};