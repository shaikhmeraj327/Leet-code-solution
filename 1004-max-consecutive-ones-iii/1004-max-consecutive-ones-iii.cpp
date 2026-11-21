class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0;
        int maxi=0;
        for(int right=0;right<n;right++){
            if(nums[right]==0)k--;
            while(left<=right && k<0){
                if(nums[left]==0)k++;
                left++;
            }
            maxi=max(maxi,right-left+1);
        }
        return maxi;
    }
};