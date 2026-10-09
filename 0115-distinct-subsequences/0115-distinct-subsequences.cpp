class Solution {
public:
    // int solve(string s,string t,int i,int j,vector<vector<int>>&dp){
    //     if(j>=t.size())return 1;
    //     if(i>=s.size())return 0;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     int match=0;
    //     int notMatch=0;
    //     if(s[i]==t[j])match=solve(s,t,i+1,j+1,dp)+solve(s,t,i+1,j,dp);
    //     else notMatch=solve(s,t,i+1,j,dp);
    //     return dp[i][j]= match+notMatch;
    // }

    int numDistinct(string s, string t) {
    //    int m=s.size();
    //    int n=t.size();
    //    vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    //     return solve(s,t,0,0,dp);

           unsigned long long m=s.size();
           unsigned long long n=t.size();
           vector<vector<unsigned long long>>dp(m+1,vector<unsigned long long>(n+1,0));
           for(int i=0;i<=m;i++)dp[i][n]=1;
           for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                unsigned long long match=0;
                unsigned long long notMatch=0;
                if(s[i]==t[j])match=dp[i+1][j+1]+dp[i+1][j];
                else notMatch=dp[i+1][j];
                dp[i][j]=match+notMatch;
            }
           }
           return dp[0][0];

    }
};