class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        
        int n=word2.size();
        if(m==0)return n;
        if(n==0)return m;
        int k=max(m,n);
        vector<int>next(k+1,0);
        vector<int>curr(k+1,0);
        for(int j=0;j<n;j++){
            next[j]=n-j;
        }
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                curr[n]=m-i;
                int match=1e9;
                int notMatch=1e9;
                if(word1[i]==word2[j]){
                    match=next[j+1];
                }
                else{
                    int insert=1+curr[j+1];
                    int deleteEle=1+next[j];
                    int replace=1+next[j+1];
                    notMatch=min({insert,deleteEle,replace});
                }
                curr[j]=min(match,notMatch);
            }
            next=curr;
        }
        return curr[0];
    }
};


// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         int m=word1.size();
//         int n=word2.size();
//         vector<vector<int>>dp(m+1,vector<int>(n+1,0));
//         for(int j=0;j<n;j++){
//             dp[m][j]=n-j;
//         }
//         for(int i=0;i<m;i++){
//             dp[i][n]=m-i;
//         }
//         for(int i=m-1;i>=0;i--){
//             for(int j=n-1;j>=0;j--){
//                 int match=1e9;
//                 int notMatch=1e9;
//                 if(word1[i]==word2[j])match=dp[i+1][j+1];
//                 else{
//                     int insert=1+dp[i][j+1];
//                     int deleteEle=1+dp[i+1][j];
//                     int replace=1+dp[i+1][j+1];
//                     match=min({insert,deleteEle,replace});
//                 }
//                 dp[i][j]=min(match,notMatch);
//             }
//         }
//         return dp[0][0];

//     }
// };




// class Solution {
// public:
//    int solve(string &word1,string &word2,int i,int j,vector<vector<int>>&dp){
//        if(i>=word1.size())return word2.size()-j;
//        if(j>=word2.size())return word1.size()-i;
//        if(dp[i][j]!=-1)return dp[i][j];
//        int notMatch=1e9;
//        int match=1e9;
//        if(word1[i]==word2[j])match=solve(word1,word2,i+1,j+1,dp);
//        else{
//             int insert=1+solve(word1,word2,i,j+1,dp);
//             int deleteEle=1+solve(word1,word2,i+1,j,dp);
//             int replace=1+solve(word1,word2,i+1,j+1,dp);
//             notMatch=min({insert,deleteEle,replace});
//        }
//        return dp[i][j]=min(notMatch,match);
//    }

//     int minDistance(string word1, string word2) {
//         int m=word1.size();
//         int n=word2.size();
//         vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
//         return solve(word1,word2,0,0,dp);
//     }
// };