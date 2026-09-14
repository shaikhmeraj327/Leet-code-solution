class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n=slices.size();
        int k=n/3;
        vector<vector<int>>dp1(n+2,vector<int>(k+1,0));
        vector<vector<int>>dp2(n+2,vector<int>(k+1,0));
        for(int ind=n-2;ind>=0;ind--){
            for(int j=1;j<=k;j++){
                int take=slices[ind]+dp1[ind+2][j-1];
                int notTake=0+dp1[ind+1][j];
                dp1[ind][j]=max(take,notTake);
            }
        }
        int ans1=dp1[0][k];
        for(int ind=n-1;ind>=1;ind--){
            for(int j=1;j<=k;j++){
               int take=slices[ind]+dp2[ind+2][j-1];
               int notTake=0+dp2[ind+1][j]; 
               dp2[ind][j]=max(take,notTake);
            }
        }

        int ans2=dp2[1][k];
        return max(ans1,ans2);
    }

};







// class Solution {
// public:
//    int solve(vector<int>&slices,int ind,int k,int n,vector<vector<int>>&dp){
//        if(k==0 || ind>=n)return 0;
//        if(dp[ind][k]!=-1)return dp[ind][k];
//        int include=slices[ind]+solve(slices,ind+2,k-1,n,dp);
//        int exclude=0+solve(slices,ind+1,k,n,dp);
//        return dp[ind][k]= max(include,exclude);


//    }
//     int maxSizeSlices(vector<int>& slices) {
//         int n=slices.size();
//         int k=n/3;
//         vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
//         vector<vector<int>>dp2(n+1,vector<int>(k+1,-1));
//         return max(solve(slices,0,k,n-1,dp),solve(slices,1,k,n,dp2));

//     }
// };