class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        vector<unordered_map<int,int>>dp(n);
        if(n<=2)return n;
        int maxLen=2;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int diff=nums[i]-nums[j];
                int count=1;
                if(dp[j].count(diff)){
                    count=dp[j][diff]+1;
                }
                else count=2;
                dp[i][diff]=count;
                maxLen=max(maxLen,dp[i][diff]);
            }
        }
        return maxLen;
    }
};