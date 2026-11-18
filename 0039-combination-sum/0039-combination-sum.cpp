class Solution {
public:
    void solve(vector<int>&candidates,int ind,int target,vector<int>&output,vector<vector<int>>&ans){
        if(ind>=candidates.size()){
            if(target==0)ans.push_back(output);
            return;
        }
        if(target-candidates[ind]>=0){
            output.push_back(candidates[ind]);
            solve(candidates,ind,target-candidates[ind],output,ans);
            output.pop_back();
        }
        solve(candidates,ind+1,target,output,ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int ind=0;
        vector<vector<int>>ans;
        vector<int>output;
        solve(candidates,ind,target,output,ans);
        return ans;
    }
};