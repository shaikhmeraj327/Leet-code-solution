class Solution {
public:
    void solve(vector<int>&arr,int target,vector<int>&output,vector<vector<int>>&ans,int index,int n){
          if(index>=n){
            if(target==0)ans.push_back(output);
            return;
          }
          // include;
          if(target-arr[index]>=0){
            output.push_back(arr[index]);
            solve(arr,target-arr[index],output,ans,index,n);
            output.pop_back();
          }
          //exclude
          solve(arr,target,output,ans,index+1,n);


    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>output;
        vector<vector<int>>ans;
        int n=candidates.size();
        solve(candidates,target,output,ans,0,n);
        return ans;
    }
};