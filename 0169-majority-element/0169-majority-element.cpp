class Solution {
public:
    int majorityElement(vector<int>& nums) {
               // unordered_map<int,int>map;
        // for(int i=0;i<nums.size();i++){
        //     map[nums[i]]++;
        // }
        // for(auto num : map){
        //   if(num.second>nums.size()/2){
        //     return num.first;
        //   }
        // } 
        // return -1 ;
        // time complexity o(n);
        //space complexity o(n)

        //Another method.
        //More's voting method for mojority;
        int n=nums.size();
        int count=0;
        int ele=-1;
        for(int i=0;i<n;i++){
            if(count==0){
                ele=nums[i];
                count=1;
            }
            else if(ele==nums[i])count++;
            else count--;
        }
        count=0;
        for(int num:nums){
            if(num==ele)count++;
        }
        if(count>n/2)return ele;
        return -1;
    }
};