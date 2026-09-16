class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=max(text1.size(),text2.size());
        vector<int>curr(m+1,0);
        vector<int>next(m+1,0);
        for(int i=text1.size()-1;i>=0;i--){
            for(int j=text2.size()-1;j>=0;j--){
                int ans=0;
                if(text1[i]==text2[j]){
                    ans=1+next[j+1];
                }
                else{
                    ans=max(next[j],curr[j+1]);
                }
                curr[j]=ans;
            }
            next=curr;
        }
        return next[0];
    }
};


// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int n1=text1.size();
//         int n2=text2.size();
//         vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
//         for(int ind1=n1-1;ind1>=0;ind1--){
//             for(int ind2=n2-1;ind2>=0;ind2--){
//                 int ans=0;
//                 if(text1[ind1]==text2[ind2]){
//                     ans=1+dp[ind1+1][ind2+1];
//                 }
//                 else{
//                     ans=max(dp[ind1+1][ind2],dp[ind1][ind2+1]);
//                 }
//                 dp[ind1][ind2]=ans;
//             }
//         }
//         return dp[0][0];
//     }
// };




// class Solution {
// public:
//    int solve(string &text1,string &text2,int ind1,int ind2,vector<vector<int>>&dp){
//        if(ind1>=text1.size() || ind2>=text2.size())return 0;
//        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
//        int ans=0;
//        if(text1[ind1]==text2[ind2])ans=1+solve(text1,text2,ind1+1,ind2+1,dp);
//        else ans=max((solve(text1,text2,ind1,ind2+1,dp)),(solve(text1,text2,ind1+1,ind2,dp)));
//        return dp[ind1][ind2]= ans;
//    }

//     int longestCommonSubsequence(string text1, string text2) {
//         int ind1=0;
//         int ind2=0;
//         int n1=text1.size();
//         int n2=text2.size();
//         vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
//         return solve(text1,text2,ind1,ind2,dp);
//     }
// };