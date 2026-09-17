class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        dp[m][n]=1;
        for(int i=0;i<s.size();i++){
            dp[i][n]=0;
        }
        for (int j = n - 1; j >= 0; j--) {
            if (p[j] == '*') {
                dp[m][j] = dp[m][j + 1];
            } else {
                dp[m][j] = 0;
            }
        }
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                bool matchOrNot=false;
                if(s[i]==p[j] || p[j]=='?')matchOrNot=dp[i+1][j+1];
                else if(p[j]=='*')matchOrNot=dp[i+1][j] || dp[i][j+1];
                else matchOrNot=false;
                dp[i][j]=matchOrNot;
            }
        }
        return dp[0][0];
    }
};



// class Solution {
// public:
//     bool solve(string &s,string &p,int i,int j,vector<vector<int>>&dp){
//         if(i>=s.size() && j>=p.size())return true;
//         if(i<s.size() && j>=p.size())return false;
//         if(i>=s.size() && j<p.size()){
//             for(int k=j;k<p.size();k++){
//                 if(p[k]!='*')return false;
//             }
//             return true;
//         }
//         if(dp[i][j]!=-1)return dp[i][j];
//         bool matchOrNot=false;
//         if(s[i]==p[j] || p[j]=='?'){
//            matchOrNot= solve(s,p,i+1,j+1,dp);
//         }
//         else if(p[j]=='*'){
//             matchOrNot=solve(s,p,i,j+1,dp) || solve(s,p,i+1,j,dp);
//         }
//         else  return false;
//         return dp[i][j]= matchOrNot;
//     }

//     bool isMatch(string s, string p) {
//         int m=s.size();int n=p.size();
//         vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
//         return solve(s,p,0,0,dp);
//     }
// };