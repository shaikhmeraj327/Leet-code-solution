class Solution {
public:
    bool isPalindrome(string &s,int i,int j,vector<vector<int>>&dp){
      if(i>=j)return true;
      if(dp[i][j]!=-1)return dp[i][j];
      if(s[i]==s[j])dp[i][j]=isPalindrome(s,i+1,j-1,dp);
      else dp[i][j]=false;
      return dp[i][j];
    }

    string longestPalindrome(string s) {
        int n=s.size();
        int maxLen=INT_MIN;
        int pos=0;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if((maxLen<j-i+1) && isPalindrome(s,i,j,dp)){
                    maxLen=j-i+1;
                    pos=i;
                }
            }
        }
        if(maxLen==INT_MIN)return "";
        return s.substr(pos,maxLen);
    }
};