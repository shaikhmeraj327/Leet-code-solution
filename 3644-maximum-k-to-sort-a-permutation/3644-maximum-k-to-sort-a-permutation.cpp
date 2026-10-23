class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n=nums.size();
        int res=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]==i)continue;
            res&=nums[i];
        }
        if(res==INT_MAX)return 0;
        return res;
    }
};