class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n=arr.size();
        unordered_map<int,int>dp;
        int maxLen=1;
        for(int i=0;i<n;i++){
            int rem=arr[i]-difference;
            int count=0;
            if(dp.count(rem)){
                count=dp[rem];
            }
            dp[arr[i]]=count+1;
            maxLen=max(maxLen,dp[arr[i]]);
        }
        return maxLen;
    }
};