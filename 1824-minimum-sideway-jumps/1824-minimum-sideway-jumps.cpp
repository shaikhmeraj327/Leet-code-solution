class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n=obstacles.size()-1;
       vector<vector<int>>dp(4,vector<int>(n+1,INT_MAX));
       dp[0][n]=0;
       dp[1][n]=0;
       dp[2][n]=0;
       dp[3][n]=0;
       for(int i=n-1;i>=0;i--){
           for(int lane=1;lane<=3;lane++){
               if(obstacles[i+1]!=lane){
                  dp[lane][i]=dp[lane][i+1];
               }
               else{
                   int ans=1e9;
                   for(int j=1;j<=3;j++){
                      if(j!=lane && obstacles[i]!=j){
                        ans=min(ans,1+dp[j][i+1]);
                      }
                   }
                   dp[lane][i]=ans;
               }
           }
       }
       return dp[2][0];

    }
};



// class Solution {
// public:
//     int solve(vector<int>& obstacles,int ind,int currLane,vector<vector<int>>&dp){
//         int n=obstacles.size();
        
//         if(ind>=n-1)return 0;
//         if(dp[currLane][ind]!=-1)return dp[currLane][ind];
//         int ans=INT_MAX;
//         if(  obstacles[ind+1]!=currLane )return solve(obstacles,ind+1,currLane,dp);
//         else{
            
//             for(int i=1;i<=3;i++){
//                 if(i!=currLane && obstacles[ind]!=i){
//                     ans=min(ans,1+solve(obstacles,ind+1,i,dp));
//                 }
//             }
//         }
//         return dp[currLane][ind]=ans;
//     }


//     int minSideJumps(vector<int>& obstacles) {
//         int n=obstacles.size();
//         vector<vector<int>>dp(4,vector<int>(n+1,-1));
//         return solve(obstacles,0,2,dp);
//     }
// };


// class Solution {
// public:
//     int solve(vector<int>&obstacles,int currLane,int pos,int n,vector<vector<int>>&dp){
//         if(pos>=n)return 0;
//         if(dp[currLane][pos]!=-1)return dp[currLane][pos];
//         if(obstacles[pos+1]!=currLane)return solve(obstacles,currLane,pos+1,n,dp);
//         else{
//             int ans=INT_MAX;
//             for(int i=1;i<=3;i++){
//                 if(currLane!=i && obstacles[pos]!=i){
//                     ans=min(ans,1+solve(obstacles,i,pos,n,dp));
//                 }
//             }
//             dp[currLane][pos]=ans;
//             return dp[currLane][pos];
//         }
//     }

//     int minSideJumps(vector<int>& obstacles) {
//         int n=obstacles.size();
//         vector<vector<int>>dp(4,vector<int>(n+1,-1));
//         return solve(obstacles,2,0,n-1,dp);
//     }
// };