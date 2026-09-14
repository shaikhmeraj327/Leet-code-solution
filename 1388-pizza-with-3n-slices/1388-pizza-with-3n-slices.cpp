class Solution {
public:
   int solve(vector<int>&slices,int ind,int k,int n,vector<vector<int>>&dp){
       if(k==0 || ind>=n)return 0;
       if(dp[ind][k]!=-1)return dp[ind][k];
       int include=slices[ind]+solve(slices,ind+2,k-1,n,dp);
       int exclude=0+solve(slices,ind+1,k,n,dp);
       return dp[ind][k]= max(include,exclude);


   }
    int maxSizeSlices(vector<int>& slices) {
        int n=slices.size();
        int k=n/3;
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        vector<vector<int>>dp2(n+1,vector<int>(k+1,-1));
        return max(solve(slices,0,k,n-1,dp),solve(slices,1,k,n,dp2));

    }
};


// class Solution {
// public:
//    int solve(vector<int>&arr,int n,int index,int k,vector<vector<int>>&dp){
//     if(k==0 || index>=n)return 0;
//     if(dp[index][k]!=-1)return dp[index][k];
//     int include=arr[index]+solve(arr,n,index+2,k-1,dp);
//     int exclude=0+solve(arr,n,index+1,k,dp);
//     return dp[index][k]=max(include,exclude);

//    }

//     int maxSizeSlices(vector<int>& slices) {
//         int n=slices.size();
//         vector<int>first,second;
//         int k=n/3;
//         vector<vector<int>>dp1(n+1,vector<int>(k+1,-1));
//         vector<vector<int>>dp2(n+1,vector<int>(k+1,-1));
//         for(int i=0;i<n;i++){
//             if(i!=0)first.push_back(slices[i]);
//             if(i!=n-1)second.push_back(slices[i]);
//         }
//         int ans1=solve(first,n-1,0,k,dp1);
//         int ans2=solve(second,n-1,0,k,dp2);
//         return max(ans1,ans2);

//     }
// };