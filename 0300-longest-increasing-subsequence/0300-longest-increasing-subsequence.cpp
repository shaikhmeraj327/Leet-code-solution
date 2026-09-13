class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(ans.empty() || nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                int ind=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[ind]=nums[i];
            }
        }
        return ans.size();
    }
};



// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<int>currRow(n+1,0);
//         vector<int>prevRow(n+1,0);
//         for(int curr=n-1;curr>=0;curr--){
//             for(int prev=curr;prev>=-1;prev--){
//                 int include=0;
//                 if(prev==-1 || nums[curr]>nums[prev]){
//                     include=1+currRow[curr+1];
//                 } 
//                 int exclude=0+currRow[prev+1];
//                 prevRow[prev+1]=max(include,exclude);
//             }
//             currRow=prevRow;
//         }
//         return currRow[0];
//     }
// };


        


// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<vector<int>>dp(n+1,vector<int>(n+1,0));
//         for(int curr=n-1;curr>=0;curr--){
//             for(int prev=curr-1;prev>=-1;prev--){
//                 int include=0;
//                 if(prev==-1 || nums[curr]>nums[prev]){
//                     include=1+dp[curr+1][curr+1];
//                 }
//                 int exclude=0+dp[curr+1][prev+1];
//                 dp[curr][prev+1]=max(include,exclude);
//             }
//         }
//         return dp[0][0];
//     }
// };






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