class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        vector<vector<int>>maxVal(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            maxVal[i][i]=arr[i];
            for(int j=i+1;j<n;j++){
                maxVal[i][j]=max(maxVal[i][j-1],arr[j]);
            }
        }
        for(int start=n-1;start>=0;start--){
            for(int end=start+1;end<=n-1;end++){
                int ans=1e9;
                for(int i=start;i<end;i++){
                    
                        int max1=maxVal[start][i];
                        int max2=maxVal[i+1][end];
                        ans=min(ans,(max1*max2)+dp[start][i]+dp[i+1][end]);
                    
                }
                dp[start][end]=ans;
            }
        }
        return dp[0][n-1];
    }
};




// class Solution {
// public:
//    int solve(vector<int>&arr,int start,int n,vector<vector<int>>&dp,vector<vector<int>>&maxVal){
//     if(start>=n)return 0;
//     if(dp[start][n]!=-1)return dp[start][n];
//     int ans=1e9;
//     for(int i=start;i<n;i++){
//         int max1=maxVal[start][i];
//         int max2=maxVal[i+1][n];
//         ans=min(ans,(max1*max2)+solve(arr,start,i,dp,maxVal)+solve(arr,i+1,n,dp,maxVal));
//     }
//     return dp[start][n]=ans;
//    }

//     int mctFromLeafValues(vector<int>& arr) {
//         int n=arr.size();
//         vector<vector<int>>maxVal(n+1,vector<int>(n+1,0));
//         for(int i=0;i<n;i++){
//             maxVal[i][i]=arr[i];
//             for(int j=i+1;j<n;j++){
//                 maxVal[i][j]=max(maxVal[i][j-1],arr[j]);
//             }
//         }
       
//         vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
//         return solve(arr,0,n-1,dp,maxVal);

//     }
// };



// class Solution {
// public:
//    int solve(vector<int>&arr,int start,int n,vector<vector<int>>&dp){
//     if(start>=n)return 0;
//     if(dp[start][n]!=-1)return dp[start][n];
//     int ans=1e9;
//     for(int i=start;i<n;i++){
//         int max1=*max_element(arr.begin()+start,arr.begin()+i+1);
//         int max2=*max_element(arr.begin()+i+1,arr.begin()+n+1);
//         ans=min(ans,(max1*max2)+solve(arr,start,i,dp)+solve(arr,i+1,n,dp));
//     }
//     return dp[start][n]=ans;
//    }

//     int mctFromLeafValues(vector<int>& arr) {
//         int n=arr.size();
        
       
//         vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
//         return solve(arr,0,n-1,dp);

//     }
// };