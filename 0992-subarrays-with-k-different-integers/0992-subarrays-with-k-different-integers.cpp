class Solution {
public:
    int solve(vector<int>& nums, int k){
        if(k==0)return 0;
        unordered_map<int,int>freq;
        int left=0;
        int count=0;
        int n=nums.size();
        for(int right=0;right<n;right++){
            freq[nums[right]]++;
            while(left<right && freq.size()>k){
                freq[nums[left]]--;
                if(freq[nums[left]]==0)freq.erase(nums[left]);
                left++;
            }
            count+=right-left+1;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};