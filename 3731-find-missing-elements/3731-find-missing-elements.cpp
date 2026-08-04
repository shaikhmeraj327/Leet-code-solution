class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        int ele=nums[0];
        vector<int>ans;
        int i=0;
        while(i<n){
             if(ele==nums[i]){
                ele++;
                i++;
                continue;
             }
             else{
                ans.push_back(ele);
                ele++;
             }
        }
        return ans;
    }
};