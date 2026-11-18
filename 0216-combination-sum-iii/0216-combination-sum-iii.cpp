class Solution {
public:
    void solve(int ind,int k,int n,vector<int>&output,vector<vector<int>>&ans){
        if(n<0)return;
        if(output.size()==k && n==0){
            ans.push_back(output);
            return;
        }
        for(int i=ind;i<=9;i++){
            if(i>n)break;
            output.push_back(i);
            solve(i+1,k,n-i,output,ans);
            output.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
         vector<vector<int>>ans;
         vector<int>output;
         solve(1,k,n,output,ans);
         return ans;
    }
};