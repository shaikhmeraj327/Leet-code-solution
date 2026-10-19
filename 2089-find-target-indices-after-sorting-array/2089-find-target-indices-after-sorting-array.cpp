class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        int n=nums.size();
        int first=-1;
        int last=-1;
        int s=0;
        int e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                first=mid;
                e=mid-1;
            }
            else if(nums[mid]>target)e=mid-1;
            else s=mid+1;
        }
        s=0;
        e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                last=mid;
                s=mid+1;
            }
            else if(nums[mid]>target)e=mid-1;
            else s=mid+1;
        }
        if(first==-1 || last==-1)return {};
        for(int i=first;i<=last;i++)ans.push_back(i);
        return ans;
    }
};