class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                ans.push_back(nums[i]);
            }
        }
        nums=ans;
        return ans.size();
    }
};


// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int index=1;
//         int n=nums.size();
//         for(int i=1;i<n;i++){
//             if(nums[i]!=nums[i-1]){
//                 nums[index++]=nums[i];
//             }
//         }
//         return index;
//     }
// };