class Solution {
public:
    bool solve(string &s,string &p,int i,int j,vector<vector<int>>&dp){
        if(i>=s.size() && j>=p.size())return true;
        if(i<s.size() && j>=p.size())return false;
        if(i>=s.size() && j<p.size()){
            for(int k=j;k<p.size();k++){
                if(p[k]!='*')return false;
            }
            return true;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        bool matchOrNot=false;
        if(s[i]==p[j] || p[j]=='?'){
           matchOrNot= solve(s,p,i+1,j+1,dp);
        }
        else if(p[j]=='*'){
            matchOrNot=solve(s,p,i,j+1,dp) || solve(s,p,i+1,j,dp);
        }
        else  return false;
        return dp[i][j]= matchOrNot;
    }

    bool isMatch(string s, string p) {
        int m=s.size();int n=p.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(s,p,0,0,dp);
    }
};