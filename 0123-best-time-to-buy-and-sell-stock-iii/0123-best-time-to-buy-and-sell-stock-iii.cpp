class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int limit=1;limit<=2;limit++){
                    int profit=0;
                    if(buy){
                        // if(ind+1<=n)
                          profit=max((-prices[ind]+dp[ind+1][0][limit]),(0+dp[ind+1][1][limit]));
                    }
                    else{
                        // if(ind+1<=n && limit+1<=2)
                        profit=max((+prices[ind]+dp[ind+1][1][limit-1]),(0+dp[ind+1][0][limit]));
                    }
                    dp[ind][buy][limit]=profit;
                }
            }
        }
        return dp[0][1][2];
    }
};



// class Solution {
// public:
//    int solve(vector<int>&prices,int ind,bool buy,int limit,vector<vector<vector<int>>>&dp){
//        if(ind>=prices.size())return 0;
//        if(limit==0)return 0;
//        if(dp[ind][buy][limit]!=-1)return dp[ind][buy][limit];
//        int profit=0;
//        if(buy){
//           profit=max((-prices[ind]+solve(prices,ind+1,0,limit,dp)),(0+solve(prices,ind+1,1,limit,dp)));
//        }
//        else{
//            profit=max((+prices[ind]+solve(prices,ind+1,1,limit-1,dp)),(0+solve(prices,ind+1,0,limit,dp)));
//        }
//        return dp[ind][buy][limit]=profit;
    
//    }

//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         int limit=2;
//         vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(limit+1,-1)));
//         bool buy=1;
//         return solve(prices,0,buy,limit,dp);
//     }
// };