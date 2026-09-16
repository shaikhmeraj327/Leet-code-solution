class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int profit=0;
        for(int i=1;i<n;i++){
            if(prices[i]>prices[i-1])profit+=prices[i]-prices[i-1];
        }
        return profit;
    }
};



// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         vector<vector<int>>dp(n+1,vector<int>(2,0));
//         for(int ind=n-1;ind>=0;ind--){
//             for(int buy=0;buy<=1;buy++){
//                 int profit=0;
//                 if(buy){
//                     if(ind+1<=n)
//                        profit=max((-prices[ind]+dp[ind+1][0]),(0+dp[ind+1][1]));
//                 }
//                 else{
//                     if(ind+1<=n)
//                        profit=max((prices[ind]+dp[ind+1][1]),(0+dp[ind+1][0]));
//                 }
//                 dp[ind][buy]=profit;
//             }
            
//         }
//         return dp[0][1];
//     }
// };





// class Solution {
// public:
//     int solve(vector<int>&prices,int ind,bool buy,vector<vector<int>>&dp){
//         if(ind>=prices.size())return 0;
//         if(dp[ind][buy]!=-1)return dp[ind][buy];
//         int profit=0;
//         if(buy){
//             profit=max((-prices[ind]+solve(prices,ind+1,0,dp)),(0+solve(prices,ind+1,1,dp)));
//         }
//         else{
//             profit=max((prices[ind]+solve(prices,ind+1,1,dp)),(0+solve(prices,ind+1,0,dp)));
//         }
//         return dp[ind][buy]= profit;
//     }

//     int maxProfit(vector<int>& prices) {
//         bool buy=1;
//         int n=prices.size();
//         vector<vector<int>>dp(n+1,vector<int>(2,-1));
//         return solve(prices,0,buy,dp);
//     }
// };


// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int mini=prices[0];
//         int profit=0;
//         int n=prices.size();
//         for(int i=1;i<n;i++){
//             if(prices[i]>=prices[i-1] && i!=n-1)continue;
//             if(prices[i]>=prices[i-1] && i==n-1){
//                 profit+=prices[i]-mini;
//                 break;
//             }
//             else{
//                 profit+=prices[i-1]-mini;
//                 mini=prices[i];
//             }
//         }
//         return profit;
//     }
// };

// class Solution {
// public:
//    int  solve(vector<int>&prices,bool buy,int index,int n,vector<vector<int>>&dp){
//     if(index==n)return 0;
//     int profit=0;
//     if(dp[index][buy]!=-1)return dp[index][buy];

//     if(buy){
//         profit=max(-prices[index]+solve(prices,0,index+1,n,dp),(0+solve(prices,1,index+1,n,dp)));
//     }
//     else{
//         profit=max((prices[index]+solve(prices,1,index+1,n,dp)),(0+solve(prices,0,index+1,n,dp)));
//     }
//   return dp[index][buy]= profit;
//    }
 
//     int maxProfit(vector<int>& prices) {
//         bool buy=1;
//         int n=prices.size();
//         int index=0;
//         vector<vector<int>>dp(n+1,vector<int>(2,-1));
//         return solve(prices,buy,index,n,dp);
//     }
// };