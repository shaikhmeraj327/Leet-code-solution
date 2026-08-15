class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int temp=nums[0];
        int maxLen=1;
        int n=nums.size();
        int zero=1;
        for(int i=1;i<n;i++){
            temp^=nums[i];
            if(nums[i]==0)zero++;
        }
        if(temp!=0)return n;
        // for(int i=0;i<n;i++){
        //     if(nums[i]==0)maxLen--;
        // }
        if(zero==n)return 0;
        return n-1;
    }
};