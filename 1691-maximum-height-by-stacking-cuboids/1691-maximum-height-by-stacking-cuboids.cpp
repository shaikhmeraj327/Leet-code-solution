class Solution {
public:
    bool check(vector<int>&newBox,vector<int>&oldBox){
         if(newBox[0]>=oldBox[0] && newBox[1]>=oldBox[1] && newBox[2]>=oldBox[2])return true;
         return false;
    }
    int LIS(vector<vector<int>>&cuboids,int index,int prev,int n,vector<vector<int>>&dp){
        if(index==n)return 0;
        if(dp[index][prev+1]!=-1)return dp[index][prev+1];
        int include=0;
        if(prev==-1 || check(cuboids[index],cuboids[prev])){
            include=cuboids[index][2]+LIS(cuboids,index+1,index,n,dp);
        }
        int exclude=0+LIS(cuboids,index+1,prev,n,dp);
        return dp[index][prev+1]=max(include,exclude);
    }
    
    int maxHeight(vector<vector<int>>& cuboids) {
        int n=cuboids.size();
        for(auto &cub:cuboids)sort(cub.begin(),cub.end());
        sort(cuboids.begin(),cuboids.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int index=0;
        int prev=-1;
        return LIS(cuboids,index,prev,n,dp);
    }
};