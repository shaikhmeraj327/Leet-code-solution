class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int limit=1;limit<=k;limit++){
                    int profit=0;
                    if(buy){
                        profit=max((-prices[ind]+dp[ind+1][0][limit]),(0+dp[ind+1][1][limit]));
                    }

                    else{
                        profit=max((+prices[ind]+dp[ind+1][1][limit-1]),(0+dp[ind+1][0][limit]));
                    }
                    dp[ind][buy][limit]=profit;
                }
            }
        }
        return dp[0][1][k];

    }
};