class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos;
        vector<int>neg;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>=0)pos.push_back(nums[i]);
            else neg.push_back(nums[i]);
        }
        int i=0,j=0;
        n=pos.size();
        int m=neg.size();
        int k=0;
        while(i<n && j<m){
            nums[k++]=pos[i++];
            nums[k++]=neg[j++];
        }
        return nums;
    }
};