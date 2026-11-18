class Solution {
public:
   bool solve(string &s,unordered_set<string>&set,int ind,vector<int>&dp){
        if(ind>=s.size())return true;
        if(dp[ind]!=-1)return dp[ind];
        for(int len=1;len<=s.size();len++){
            string temp=s.substr(ind,len);
            if(set.find(temp)!=set.end() && solve(s,set,ind+len,dp))return true;
        }
        return dp[ind]= false;
   }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        unordered_set<string>set(wordDict.begin(),wordDict.end());
        vector<int>dp(n+1,-1);
        return solve(s,set,0,dp);
        
    }
};