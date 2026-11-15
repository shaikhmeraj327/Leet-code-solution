class Solution {
public:
   bool isPalindrome(string &s,int i,int j,vector<vector<int>>&dp){
       if(i>=j)return true;
       if(dp[i][j]!=-1)return dp[i][j];
       if(s[i]!=s[j])return dp[i][j]=false;
       return dp[i][j]=isPalindrome(s,i+1,j-1,dp);
   }

    string longestPalindrome(string s) {
        int n=s.size();
        int maxLen=0;
        int pos=0;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(maxLen<j-i+1 && isPalindrome(s,i,j,dp)){
                    maxLen=j-i+1;
                    pos=i;
                }
            }
        }
        return s.substr(pos,maxLen);
    }
};