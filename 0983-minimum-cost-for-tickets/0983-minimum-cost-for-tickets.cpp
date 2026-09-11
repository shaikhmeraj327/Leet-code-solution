class Solution {
public:
    int solve(vector<int>& days,vector<int>& costs,int ind,vector<int>&dp){
        if(ind>=days.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        int option1=costs[0]+solve(days,costs,ind+1,dp);
        int i=ind;
        for(;i<days.size() && days[i]<days[ind]+7;i++);
        int option2=costs[1]+solve(days,costs,i,dp);
        int j=ind;
        for(;j<days.size() && days[j]<days[ind]+30;j++);
        int option3=costs[2]+solve(days,costs,j,dp);
        return dp[ind]= min({option1,option2,option3});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(n+1,-1);
        return solve(days,costs,0,dp);
    }
};