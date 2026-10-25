class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod=1;
        int n=nums.size();
        vector<int>lp(n,1);
        vector<int>rp(n,1);
        for(int i=1;i<n;i++){
            prod*=nums[i-1];
            lp[i]=prod;
        }
        prod=1;
        for(int i=n-2;i>=0;i--){
            prod*=nums[i+1];
            rp[i]=prod;
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=lp[i]*rp[i];
        }
        return ans;
    }
};