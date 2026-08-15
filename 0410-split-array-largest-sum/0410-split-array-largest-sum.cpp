class Solution {
public:
    bool isPossible(vector<int>nums,long long mid,int k){
        int count=1;
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            if(nums[i]+sum<=mid)sum+=nums[i];
            else{
                count++;
                if(count>k)return false;
                sum=nums[i];
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        long long low=*max_element(nums.begin(),nums.end());
        long long high=0;
        for(int num:nums)high+=num;
        long long ans=-1;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(isPossible(nums,mid,k)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};