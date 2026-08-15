class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int s=0,e=n-1;
        while(s<e){
            int mid=s+(e-s)/2;
            if(mid%2!=0)mid--;
            if(nums[mid]==nums[mid+1])s=mid+2;
            else e=mid;
        }
        return nums[s];
    }
};



// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//         int ans=nums[0];
//         int i=1;
//         while(i<nums.size()){
//             ans=ans^nums[i];
//             i++;
//         }
//         return ans;
//     }
// };