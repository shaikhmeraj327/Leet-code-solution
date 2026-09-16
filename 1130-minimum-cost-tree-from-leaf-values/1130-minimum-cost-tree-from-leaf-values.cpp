class Solution {
public:
   unordered_map<int,int>maxEle;
   int solve(vector<int>&arr,int start,int n,vector<vector<int>>&dp){
    if(start>=n)return 0;
    if(dp[start][n]!=-1)return dp[start][n];
    int ans=1e9;
    for(int i=start;i<n;i++){
        int max1=*max_element(arr.begin()+start,arr.begin()+i+1);
        int max2=*max_element(arr.begin()+i+1,arr.begin()+n+1);
        ans=min(ans,(max1*max2)+solve(arr,start,i,dp)+solve(arr,i+1,n,dp));
    }
    return dp[start][n]=ans;
   }

    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        int maxi=arr[0];
       
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(arr,0,n-1,dp);

    }
};