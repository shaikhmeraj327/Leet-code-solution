class Solution {
public:
   bool isPossible(vector<int>&nums,int mid,int k){
       int sum=0;
       int n=nums.size();
       for(int i=0;i<n;i++){
           int a=nums[i]/mid;
           int b=nums[i]%mid;
           sum+=a;
           if(b>0)sum++;
           if(sum>k)return false;
       }
       return true;
   }
   

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(nums,mid,threshold)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};