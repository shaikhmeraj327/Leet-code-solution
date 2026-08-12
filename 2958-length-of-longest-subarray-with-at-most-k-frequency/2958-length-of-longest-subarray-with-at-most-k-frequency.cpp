class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        int left=0;
        int maxLen=0;
        int n=nums.size();
        for(int right=0;right<n;right++){
            freq[nums[right]]++;
            while(left<=right && freq[nums[right]]>k){
                freq[nums[left]]--;
                left++;
            }
            maxLen=max(maxLen,right-left+1);
        }
        return maxLen;
    }
};