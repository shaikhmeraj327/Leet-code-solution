class Solution {
public:
    void solve(vector<int>&candidates,vector<int>&output,vector<vector<int>>&ans,int target,int index,int n){
        if(target<0)return;
        if(target==0){
            ans.push_back(output);
            return;
        }
        // include
        for(int i=index;i<n;i++){
            if(i>index && candidates[i]==candidates[i-1])continue;
            output.push_back(candidates[i]);
            solve(candidates,output,ans,target-candidates[i],i+1,n);
            output.pop_back();
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int index=0;
        vector<int>output;
        vector<vector<int>>ans;
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        solve(candidates,output,ans,target,index,n);
        return ans;
    }
};