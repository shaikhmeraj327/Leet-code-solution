class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int s=0,e=n-1;
        while(s<e){
            int mid=s+(e-s)/2;
            if(nums[mid+1]>nums[mid])s=mid+1;
            else e=mid;
        }
        return s;
    }
};




// Another method

// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
//         int n=nums.size();
//         if(n==1)return 0;
//         if(n>1 )if(nums[0]>nums[1])return 0;
//         for(int i=1;i<n;i++){
//             if(i<n-1 && nums[i]>nums[i-1] && nums[i]>nums[i+1])return i;
//             if(i==n-1 && nums[i]>nums[i-1])return i;
//         }
//         return n;
       
//     }
// };