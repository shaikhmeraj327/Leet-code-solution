class Solution {
public:
    int m=1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        vector<long long >power(n,1);
        for(int i=1;i<n;i++){
            power[i]=(power[i-1]*2)%m;
        }
        int left=0;
        int right=n-1;
        int ans=0;
        sort(nums.begin(),nums.end());
        while(left<=right){
            if(nums[left]+nums[right]<=target){
                ans=(ans+power[right-left])%m;
                left++;
            }
            else right--;
        }
        return ans%m;
    }
};