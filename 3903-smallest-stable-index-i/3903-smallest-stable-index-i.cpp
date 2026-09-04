class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>suffixMin(n);
        int mini=nums[n-1];
        suffixMin[n-1]=mini;
        for(int i=n-2;i>=0;i--){
            mini=min(mini,nums[i]);
            suffixMin[i]=mini;
        }
        int maxi=nums[0];
        for(int i=0;i<n;i++){
            maxi=max(nums[i],maxi);
            int mini=suffixMin[i];
            if(maxi-mini<=k)return i;
        }
        return -1;
    }
};