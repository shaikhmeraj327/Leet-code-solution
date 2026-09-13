class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>>dp(n+1,vector<int>(n+2,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int time=n;time>=1;time--){
                int include=time*satisfaction[ind]+dp[ind+1][time+1];
                int exclude=0+dp[ind+1][time];
                dp[ind][time]=max(include,exclude);
            }
        }
        return dp[0][1];
    }
};






// class Solution {
// public:
//     int solve(vector<int>&satisfaction,int ind,int time,vector<vector<int>>&dp){
//         int n=satisfaction.size();
//         if(ind>=n)return 0;
//         if(dp[time][ind]!=-1)return dp[time][ind];
//         int include=time*satisfaction[ind]+solve(satisfaction,ind+1,time+1,dp);
//         int exclude=0+solve(satisfaction,ind+1,time,dp);
//         return dp[time][ind]= max(include,exclude);
//     }
    
//     int maxSatisfaction(vector<int>& satisfaction) {
//         sort(satisfaction.begin(),satisfaction.end());
//         int time=1;
//         int n=satisfaction.size();
//         vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
//         return solve(satisfaction,0,time,dp);
//     }
// };