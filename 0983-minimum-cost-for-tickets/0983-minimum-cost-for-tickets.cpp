class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size(); 
        vector<int>dp(n+1,INT_MAX);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            int op1=costs[0]+dp[i+1];
            int j;
            for(j=i;j<n && days[j]<days[i]+7;j++);
            int op2=costs[1]+dp[j];
            for(j=1;j<n && days[j]<days[i]+30;j++);
            int op3=costs[2]+dp[j];
            dp[i]=min({op1,op2,op3});
        }
        return dp[0];
    }
};

// class Solution {
// public:
//     int solve(vector<int>& days,vector<int>& costs,int ind,vector<int>&dp){
//         if(ind>=days.size())return 0;
//         if(dp[ind]!=-1)return dp[ind];
//         int option1=costs[0]+solve(days,costs,ind+1,dp);
//         int i=ind;
//         for(;i<days.size() && days[i]<days[ind]+7;i++);
//         int option2=costs[1]+solve(days,costs,i,dp);
//         int j=ind;
//         for(;j<days.size() && days[j]<days[ind]+30;j++);
//         int option3=costs[2]+solve(days,costs,j,dp);
//         return dp[ind]= min({option1,option2,option3});
//     }

//     int mincostTickets(vector<int>& days, vector<int>& costs) {
//         int n=days.size();
//         vector<int>dp(n+1,-1);
//         return solve(days,costs,0,dp);
//     }
// };