class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>freq;
        int count=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==k)count++;
            int rem=sum-k;
            if(freq.find(rem)!=freq.end()){
                count+=freq[rem];
            }
            freq[sum]++;
        }
        return count;
    }
};