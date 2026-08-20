class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>arr1,arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int index=2;
        int n=nums.size();
        while(index<n){
            if(arr1.back()>arr2.back())arr1.push_back(nums[index++]);
            else arr2.push_back(nums[index++]);
        }
        int i=0;
        // vector<int>res=arr1+arr2;
        while(i<arr2.size())arr1.push_back(arr2[i++]);
        return arr1;
    }
};