class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>suffixMin(n);
        suffixMin[n-1]=nums[n-1];
        int mini=nums[n-1];
        for(int i=n-2;i>=0;i--){
            mini=min(nums[i],mini);
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